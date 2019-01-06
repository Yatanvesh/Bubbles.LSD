#include "Bubble.h"
#include <math.h>

Bubble::Bubble(){
  circle.setRadius(5 + rand() % 30);
  circle.setFillColor(sf::Color(r(),r(),r(),r()));
  circle.setOutlineThickness(1 +rand()%6);
  circle.setOutlineColor(sf::Color(r(),r(),r(),r()));
  circle.setPosition(SCREEN_DIMS.x*0.3+rand()%int(SCREEN_DIMS.x*0.4),SCREEN_DIMS.y*0.3+rand()%int(SCREEN_DIMS.y*0.4));
  circle.setOrigin(circle.getRadius(),circle.getRadius());
  angle= d();
  velocity = 1+ 0.1* ( rand()%100);
  velocity*=0.7;
  lifeTime = 20 + 0.1*(rand()%100);
}

void Bubble::draw(sf::RenderWindow &window){
  window.draw(circle);
}

int randTwo()
{
  if(rand()%100 >50)
    return 2;
  return -2;
}

sf::Color transform(sf::Color color){
  return sf::Color(color.r + randTwo(), color.g+ randTwo(), color.b +randTwo(),color.a);
}

void Bubble::tick(){
  circle.setPosition(SCREEN_CENTRE.x + radius * cos(angle)*180/PI,SCREEN_CENTRE.y + radius * sin(angle)*180/PI);
  angle+= velocity*0.02;
  radius+= abs(velocity)*0.01;

  circle.setFillColor(transform(circle.getFillColor()));
  circle.setOutlineColor(transform(circle.getOutlineColor()));
}

bool Bubble::isAlive(){
  if (clock.getElapsedTime().asSeconds() <lifeTime)
    return true;
  else return false;
}
