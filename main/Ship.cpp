#include "Ship.h"
#include <math.h>
#define PI 3.14159265
Ship::Ship(){
  if(!texture.loadFromFile("./main/assets/img/ship.png") )
    cout<<"TODO: raise exception ";

  sprite.setTexture(texture);
  sprite.scale(0.1,0.1);
  sprite.setOrigin(sprite.getLocalBounds().width/2, sprite.getLocalBounds().height/2);
  sprite.setPosition(100,100);
}

Ship::~Ship(){

}
float gradX;
float gradY;
float rotation;
float posX;
float posY;
void Ship::fly(){
  gradX = this->sprite.getPosition().x - screenCentre.first;
  gradY = this->sprite.getPosition().y - screenCentre.second;
  rotation = 90+atan(gradY/gradX)  *180/PI;


  if (this->sprite.getPosition().x >= screenCentre.first)
    rotation+=180;
  this->sprite.setRotation(rotation);

  posX = screenCentre.first + radius * cos(angle)*180/PI;
  posY = screenCentre.second + radius * sin(angle)*180/PI;
  this->sprite.setPosition(posX,posY );
  if(radius>6)
    radius=6;
  else if (radius<1)
    radius=1;
  cout<<posX<<"   "<<posY<<"  "<<radius<<endl;
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    angle+=0.02;
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    angle-=0.02;
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    radius-=0.04;
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    radius+=0.04;
}
