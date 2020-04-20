#include "game.h"
Game::Game(int height, int width) : _height(height), _width(width) {

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
    rnd.Render(_car);
    sf::Time elapsed1 = clock.getElapsedTime();
    // std::cout << "Sleeping for " << 33 - elapsed1.asMilliseconds() <<
    // std::endl;
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