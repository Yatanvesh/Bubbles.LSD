#ifndef Bubble_H
#define Bubble_H

#include "globals.h"
class Bubble{
public:
  Bubble();
  void draw(sf::RenderWindow &window);
  void tick();
  bool isAlive();
private:
  int r(){return rand()%255;};
  int d(){return rand()%360;};
  sf::CircleShape circle;
  float angle;
  float velocity;
  int type=1;
  float radius=1;
  float lifeTime;
  sf::Clock clock;
};

#endif
