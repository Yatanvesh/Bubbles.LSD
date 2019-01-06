#include "View.h"
#include <math.h>

View::View(sf::FloatRect rect,sf::Sprite *Target,sf::RenderWindow *window):sf::View(rect){
  this->Target = Target;
  this->window = window;
}

float COS,SIN;

void View::focus(){
  rotation=Target->getRotation();
  setCenter(Target->getPosition().x + posCoef*sin(rotation*PI/180) ,Target->getPosition().y -posCoef*cos(rotation*PI/180)  );
  setRotation(rotation);

  COS=shockCoef*cos(rotation*PI/180);
  SIN=shockCoef*sin(rotation*PI/180);

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    move(COS,SIN);
  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    move(-COS,-SIN);
  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    move(SIN,-COS);
  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    move(-SIN,COS);

  window->setView(*this);
}
