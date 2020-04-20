#ifndef GAME_H
#define GAME_H
#include "car.h"
#include "renderer.h"
#include <chrono>
#include <thread>
class Game {

public:
  Game(int height, int width);

private:
  int _height;
  int _width;
  bool _play;
  Car _car;
  void Run(Renderer &rnd);
  void LimitWorld();
};

#endif