#include "game.h"
Game::Game(int height, int width, ros::NodeHandle &nh)
    : _height(height), _width(width) {

  _sub = nh.subscribe("/CarSim/steer", 10, &Game::_clbk, this);
  _pub = nh.advertise<sensor_msgs::Image>("/CarSim/image", 30);
  Renderer rnd(height, width);
  _play = true;
  Run(rnd);
}

void Game::Run(Renderer &rnd) {
  Clock clock;
  while (rnd._window->isOpen()) {
    clock.restart();
    _car.MoveFW();
    Event event;
    while (rnd._window->pollEvent(event)) {

      if (event.type == sf::Event::Closed ||
          Keyboard::isKeyPressed(Keyboard::Escape)) {
        rnd._window->close();
        break;
      }

      if (Keyboard::isKeyPressed(Keyboard::BackSpace)) {
        _car.Reset();
      }
      if (Keyboard::isKeyPressed(Keyboard::Q)) {
        _car.Rotate(-0.1);
      }
      if (Keyboard::isKeyPressed(Keyboard::E)) {
        _car.Rotate(+0.1);
      }

      if (Keyboard::isKeyPressed(Keyboard::Up)) {
        _car.Accelerate();
      }
      if (Keyboard::isKeyPressed(Keyboard::S)) {
        _car.MoveBW();
      }
    }
    LimitWorld();
    ros::spinOnce();
    rnd.Render(_car);
    Image screen = rnd._window->capture();
    _pub.publish(*windowToROS(screen));
    sf::Time elapsed1 = clock.getElapsedTime();
    std::this_thread::sleep_for(
        std::chrono::milliseconds(33 - elapsed1.asMilliseconds()));
  }
}

void Game::LimitWorld() {
  if (_car._x > _width) {
    _car._x = 0;
  }
  if (_car._x < 0) {
    _car._x = _width;
  }
  if (_car._y > _height) {
    _car._y = 0;
  }
  if (_car._y < 0) {
    _car._y = _height;
  }
}

void Game::_clbk(const std_msgs::Float32::ConstPtr &msg) {
  _car.Rotate(msg->data);
}