#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
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
  Font font;
  font.loadFromFile("fonts/KOMIKAP_.ttf");
 

  
  // Prepare the sound
	SoundBuffer carBuffer;
	carBuffer.loadFromFile("sound/car.wav");
	Sound carsound;
	carsound.setBuffer(carBuffer);
  carsound.setVolume(10);
  // carsound.setLoop(true);
  
  // carsound.play();
  Text title;
  title.setString("Monofya CarSim");
  title.setCharacterSize(75);
  title.setFont(font);
  title.setPosition(350, 330);

  Text carPos;
  
  carPos.setCharacterSize(20);
  carPos.setFont(font);
  carPos.setPosition(0, 680);
  
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
    } 
    if(Keyboard::isKeyPressed(Keyboard::BackSpace)){
      carX = 560;
      carY = 517;
      spriteCar.setPosition(carX, carY);
      spriteCar.setRotation(0);
    }
    if(Keyboard::isKeyPressed(Keyboard::W)) {
    std::cout << "Moving Forward " << std::endl;
    Time dt = clock.restart();
    carX += carSpeed * cos((spriteCar.getRotation()*M_PI)/180) ;
    carY += carSpeed * sin((spriteCar.getRotation()*M_PI)/180) ;
    if(carX>1280){
        carX = 0;
    }
    // carsound.setPosition(carX, carY, 0);
    spriteCar.setPosition(carX, carY);
    if(carsound.getStatus()!=carsound.Playing){
      carsound.play();
    }
    
    
  }
    if(Keyboard::isKeyPressed(Keyboard::S)){
    carX -= carSpeed * cos((spriteCar.getRotation()*M_PI)/180) ;
    carY -= carSpeed * sin((spriteCar.getRotation()*M_PI)/180) ;
    if(carX<0){
        carX = 1280;
    }
    spriteCar.setPosition(carX, carY);
  }
  if(Keyboard::isKeyPressed(Keyboard::Q)){

  spriteCar.rotate(-0.05);
  }
    if(Keyboard::isKeyPressed(Keyboard::E)){
  spriteCar.rotate(+0.05);
  }
  
  if(Keyboard::isKeyPressed(Keyboard::Up)){
  carSpeed += 0.001;
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
    std::stringstream ss;
    ss << "Car Position:  X= " << carX << "  Y= " << carY;
    carPos.setString(ss.str());
    window.clear();
    window.draw(sprtieBg);
    window.draw(title);
    window.draw(carPos);
    window.draw(spriteCar);
    
    window.display();
    carsound.pause();
    // renderTheScene(window, gameSprites);
  }

  return 0;
}
