#include "Ship.h"
#include <math.h>

Ship::Ship(){
    if(!texture.loadFromFile("./main/assets/img/ship.png") )
      cout<< "File not found error";
  sprite.setTexture(texture);
  sprite.scale(0.1,0.1);
  sprite.setOrigin(sprite.getLocalBounds().width/2, sprite.getLocalBounds().height/2);
}

Ship::~Ship(){
}

float gradX;
float gradY;
float rotation;
float posX;
float posY;

void Ship::tick(){
  getInput();
  setConstraints();
  //SpriteRotation
  gradX = this->sprite.getPosition().x - SCREEN_CENTRE.x;
  gradY = this->sprite.getPosition().y - SCREEN_CENTRE.y;
  rotation = 90 + atan(gradY/gradX) *180/PI;
  if (this->sprite.getPosition().x >= SCREEN_CENTRE.x)
    rotation+=180;
  this->sprite.setRotation(rotation);

  //Set position
  angle +=angularVelocity;
  posX = SCREEN_CENTRE.x + radius * cos(angle)*180/PI;
  posY = SCREEN_CENTRE.y + radius * sin(angle)*180/PI;
  this->sprite.setPosition(posX,posY);

  //update global player setPosition
  playerPosition = sprite.getPosition();
}

void Ship::draw(sf::RenderWindow &window){
  window.draw(sprite);
}

void Ship::getInput(){
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    angularVelocity-=ANGULAR_ACCELERATION;
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    angularVelocity+=ANGULAR_ACCELERATION;
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    radius-=VERTICAL_VELOCITY;
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    radius+=VERTICAL_VELOCITY;
}

void Ship::setConstraints(){
  //radius and angularVelocity constraints
  if (angularVelocity > MAX_ANGULAR_VELOCITY)
    angularVelocity = MAX_ANGULAR_VELOCITY;
  else if (angularVelocity < -MAX_ANGULAR_VELOCITY)
    angularVelocity = -MAX_ANGULAR_VELOCITY;

  if(radius>6)
    radius=6;
  else if (radius<1)
    radius=1;
}
