#ifndef CAR_H
#define CAR_H
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
using namespace sf;
class Car {
public:
  Car();
  void MoveFW();
  void MoveBW();
  void Rotate(float angle);
  void Accelerate();
  void Reset();
  float _speed = 0.1;
  float _x;
  float _y;
  Texture _textCar;
  Sprite _sprite;
};

#endif