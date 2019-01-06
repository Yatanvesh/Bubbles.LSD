#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include "globals.h"

class Entity{
public:
  sf::Sprite sprite;
  int drawHeight=0;

  virtual void tick()=0;
  virtual void draw(sf::RenderWindow &window)=0;
protected:
  sf::Texture texture;

};

#endif
