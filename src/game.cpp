#include "game.h"
Game::Game(int height, int width) {

  Renderer rnd(height, width);
  _play = true;
  Run(rnd);
}

void Game::Run(Renderer &rnd) {
  while (_play) {
    auto timstart = std::chrono::system_clock::now();

    /*
    ****************************
    Handle Player Inputs
    ****************************
    */
    if (Keyboard::isKeyPressed(Keyboard::Escape)) {
      _play = false;
    }
    if (Keyboard::isKeyPressed(Keyboard::BackSpace)) {
      _car.Reset();
    }
    if (Keyboard::isKeyPressed(Keyboard::Q)) {

      _car.Rotate(-0.1);
      _car.MoveFW();
    }
    if (Keyboard::isKeyPressed(Keyboard::E)) {
      _car.Rotate(+0.05);
      _car.MoveFW();
    }

    if (Keyboard::isKeyPressed(Keyboard::Up)) {
      _car.Accelerate();
    }
    if (Keyboard::isKeyPressed(Keyboard::W)) {
      _car.MoveFW();
    }
    if (Keyboard::isKeyPressed(Keyboard::S)) {
      _car.MoveBW();
    }

    rnd.Render(_car);
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - timstart;

    if (elapsed.count() < (1000 / 30)) {
      int sleepfor = (1000 / 30) - elapsed.count();
      std::this_thread::sleep_for(std::chrono::milliseconds(sleepfor));
    }
  }
}