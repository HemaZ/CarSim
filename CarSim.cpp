#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
using namespace sf;

void renderTheScene(RenderWindow &window, std::vector<Sprite> sprites) {
  window.clear(); // Clear the window
  for (auto it = sprites.begin(); it != sprites.end(); ++it) {
    window.draw(*it);
  }
  window.display(); // Update The Game Scene
}

int main() {
  RenderWindow window(VideoMode(1280, 720), "CarSim!");
  View view(FloatRect(0, 0, 1280, 720));
  window.setView(view);

  // Add The Game Background
  Texture textureBg;
  textureBg.loadFromFile("graphics/bg.png");
  Sprite sprtieBg;
  sprtieBg.setTexture(textureBg);
  sprtieBg.setPosition(0, 0);

  // Add A Car
  Texture textCar;
  textCar.loadFromFile("graphics/mercedess.png");
  Sprite spriteCar;
  spriteCar.setTexture(textCar);
  float carX, carY;
  carX = 560;
  carY = 517;
  spriteCar.setPosition(carX, carY);
  float carSpeed = 0.11;
  std::vector<Sprite> gameSprites = {sprtieBg, spriteCar};

  Clock clock;

  while (window.isOpen()) {

    /*
    ****************************
    Handle Player Inputs
    ****************************
    */
    if (Keyboard::isKeyPressed(Keyboard::Escape)) {
      window.close(); // close the game if the player pressed ESC
    } else if (Keyboard::isKeyPressed(Keyboard::W)) {
      std::cout << "Moving Forward " << std::endl;
      Time dt = clock.restart();
      carX += carSpeed;
      if(carX>1280){
          carX = 0;
      }
      spriteCar.setPosition(carX, carY);
    }else if(Keyboard::isKeyPressed(Keyboard::S)){
      carX -= carSpeed;
      if(carX<0){
          carX = 1280;
      }
      spriteCar.setPosition(carX, carY);
    }else if(Keyboard::isKeyPressed(Keyboard::Q)){

    spriteCar.rotate(-0.1);
    }else if(Keyboard::isKeyPressed(Keyboard::E)){
    spriteCar.rotate(+0.1);
    }
    /*
    ****************************
    Update the scene
    ****************************
    */
   
    std::cout << carX << std::endl;
    /*
    ****************************
    Draw the scene
    ****************************
    */
    window.clear();
    window.draw(sprtieBg);
    window.draw(spriteCar);
    window.display();
    // renderTheScene(window, gameSprites);
  }

  return 0;
}
