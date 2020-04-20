#ifndef RENDERER_H
#define RENDERER_H
#include "car.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
using namespace sf;

class Renderer {
public:
  Renderer(int height, int width);
  void Render(Car &car);
  std::shared_ptr<RenderWindow> _window;

private:
  Font _font;
  Texture _textureBg;
  Sprite _sprtieBg;
  Text _title;
  Text _carPos;
  int _height;
  int _width;
};

#endif