#ifndef SPARKLES_H
#define SPARKLES_H
#include "Entity.h"

class Sparkles : public Entity{

public:
  Sparkles();
  void draw(sf::RenderWindow &window);
  void tick();

  int r(){return rand()%255;};
  int d(){return rand()%360;};
  sf::CircleShape circle;
  float angle;
  float velocity;
  int type=1;
  float radius=1;

  bool isVisible();
};

#endif
