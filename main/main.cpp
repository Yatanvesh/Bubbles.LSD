#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <utility>
#include "Ship.h"
#include "globals.h"
using namespace std;

int main(){
  screenDims.first= 800;
  screenDims.second=800;
  screenCentre.first = screenDims.first/2;
  screenCentre.second = screenDims.second/2;

  cout<<"Running"<<endl;
  sf::RenderWindow window(sf::VideoMode(screenDims.first,screenDims.second), "Galactic Junkies");

  Ship ship;
  while(window.isOpen()){
    sf::Event event;
    while(window.pollEvent(event)){
      if(event.type == sf::Event::Closed)
        window.close();
    }
    ship.fly();


    window.clear();
    window.draw(ship.sprite);
    window.display();
  }
  return 0;
}
