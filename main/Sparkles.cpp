#include "Sparkles.h"
#include <math.h>
Sparkles::Sparkles(){
  circle.setRadius(5 + rand() % 30);
  circle.setFillColor(sf::Color(r(),r(),r(),r()));

  circle.setOutlineThickness(1 +rand()%6);
  circle.setOutlineColor(sf::Color(r(),r(),r(),r()));
  circle.setPosition(100+rand()%600,100+rand()%600);
  angle= d();
  velocity = 1+ 0.1* (100 - rand()%200);
}

void Sparkles::draw(sf::RenderWindow &window){
  window.draw(circle);
}
int ranone()
{
  if(rand()%100 >50)
    return 2;
  return -2;
}
sf::Color transform(sf::Color color){
  return sf::Color(color.r + ranone(), color.g+ ranone(), color.b +ranone(),color.a);
}
void Sparkles::tick(){
  switch (3) {
    case 1:circle.move(velocity*cos(angle),velocity*sin(angle));
            break;
    case 2:circle.move(0.6*velocity+5,velocity*sin(circle.getPosition().x));
            break;
    case 3:circle.setPosition(SCREEN_CENTRE.x + radius * cos(angle)*180/PI,SCREEN_CENTRE.y + radius * sin(angle)*180/PI);
            angle+= velocity*0.02;
            radius+= abs(velocity)*0.01;
            break;
    case 4:
      break;
  }
  circle.setFillColor(transform(circle.getFillColor())  );
  circle.setOutlineColor(transform(circle.getOutlineColor()));

}

int x,y;
bool Sparkles::isVisible(){
  x=circle.getPosition().x;
  y=circle.getPosition().y;
  if(  x> SCREEN_DIMS.x || x <0 ||
       y> SCREEN_DIMS.y || y<0 )
       return false;
  else return true;
}
