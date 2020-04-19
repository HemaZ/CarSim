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
  bool _play;
  Car _car;
  void Run(Renderer &rnd);
};

#endif