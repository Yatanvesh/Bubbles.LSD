#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"

class Enemy: public Entity{
public:
  Enemy();
  void draw(sf::RenderWindow &window);
  void tick();


};

#endif
