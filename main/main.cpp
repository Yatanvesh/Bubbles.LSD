#include <iostream>
#include <time.h>
#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>
#include "Ship.h"
#include "Enemy.h"
#include "View.h"
#include "Sparkles.h"

void globalInit();

int main(){
  srand (time(NULL));
  globalInit();

  sf::RenderWindow window(sf::VideoMode(SCREEN_DIMS.x,SCREEN_DIMS.y), "Galactic Junkies");
  window.setVerticalSyncEnabled(true);
  Ship playerShip;
  Enemy enemy;
  Sparkles s[1000];

  sf::Texture bT;
  bT.loadFromFile("./main/assets/img/bb.png");
  sf::Sprite b(bT);

  View view(sf::FloatRect(800,800,800,800),&playerShip.sprite,&window);

  while(window.isOpen()){
    sf::Event event;
    while(window.pollEvent(event)){
      if(event.type == sf::Event::Closed)
        window.close();
    }

    playerShip.tick();
    for (size_t i = 0; i < 1000; i++) {
      s[i].tick();
    }



    //view.focus();
    window.clear();
    window.draw(b);
    playerShip.draw(window);
    enemy.draw(window);
    for (size_t i = 0; i < 1000; i++) {
      s[i].draw(window);
    }

    window.display();
  }
  return 0;
}

void globalInit(){
  SCREEN_DIMS.x= 800;
  SCREEN_DIMS.y=800;
  SCREEN_CENTRE.x = SCREEN_DIMS.x/2;
  SCREEN_CENTRE.y = SCREEN_DIMS.y/2;
}
