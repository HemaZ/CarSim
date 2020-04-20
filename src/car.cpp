#include "car.h"

Car::Car() {
  _textCar.loadFromFile("graphics/mercedess.png");
  _sprite.setTexture(_textCar);
  _x = 560;
  _y = 517;
  _speed = 1.5;
  _sprite.setPosition(_x, _y);
}

void Car::Reset() {
  _x = 560;
  _y = 517;
  _speed = 1.5;
  _sprite.setPosition(_x, _y);
  _sprite.setRotation(0);
}

void Car::MoveFW() {
  // std::cout << "Moving Forward ";
  _x += _speed * cos((_sprite.getRotation() * M_PI) / 180);
  _y += _speed * sin((_sprite.getRotation() * M_PI) / 180);
  if (_x > 1280) {
    _x = 0;
  }
  _sprite.setPosition(_x, _y);
  // std::cout << " X: " << _x << "  Y: " << _y << std::endl;
}

void Car::MoveBW() {
  _x -= _speed * cos((_sprite.getRotation() * M_PI) / 180);
  _y -= _speed * sin((_sprite.getRotation() * M_PI) / 180);
  if (_x < 0) {
    _x = 1280;
  }
  _sprite.setPosition(_x, _y);
}

void Car::Rotate(float angle) { _sprite.rotate(angle); }

void Car::Accelerate() { _speed += 0.1; }