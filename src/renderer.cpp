#include "renderer.h"

Renderer::Renderer(int h, int w) : _height(h), _width(w) {

  _window =
      std::make_unique<RenderWindow>(VideoMode(_width, _height), "CarSim!");
  View view(FloatRect(0, 0, _width, _height));
  _window->setView(view);

  _font.loadFromFile("fonts/KOMIKAP_.ttf");

  _title.setString("Hema's CarSim");
  _title.setCharacterSize(75);
  _title.setFont(_font);
  _title.setPosition(350, 330);

  _carPos.setCharacterSize(20);
  _carPos.setFont(_font);
  _carPos.setPosition(0, 680);

  // Add The Game Background
  _textureBg.loadFromFile("graphics/bg.png");
  _sprtieBg.setTexture(_textureBg);
  _sprtieBg.setPosition(0, 0);
}

void Renderer::Render(Car &car) {
  _window->clear();
  _window->draw(_sprtieBg);
  _window->draw(_title);
  _window->draw(_carPos);
  _window->draw(car._sprite);

  _window->display();
}