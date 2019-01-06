#ifndef BUBBLE_FACTORY_H
#define BUBBLE_FACTORY_H

#include "Bubble.h"
#include <vector>

class BubbleFactory{
public:
  vector<Bubble*> m_Bubble;
  BubbleFactory();
  const int NO_BUBBLE=4000;
  void tick();
  void draw(sf::RenderWindow &window);
};

#endif
