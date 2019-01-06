#ifndef SHIP_H
#define SHIP_H
#include "Entity.h"

class Ship : public Entity{
public:
  Ship();
  ~Ship();
  void tick();
  void draw(sf::RenderWindow &window);

private:
  const float MAX_ANGULAR_VELOCITY=0.1;
  const float ANGULAR_ACCELERATION=0.01;
  const float VERTICAL_VELOCITY=0.14;

  double angle = 0;
  double speed = 3;
  double radius = 5;
  double angularVelocity=0;

  void getInput();
  void setConstraints();
};

#endif
