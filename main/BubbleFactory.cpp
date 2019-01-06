#include "BubbleFactory.h"

BubbleFactory::BubbleFactory(){
  for (size_t i = 0; i < NO_BUBBLE; i++) {
    Bubble *s = new Bubble();
    m_Bubble.push_back(s);
  }
}

void BubbleFactory::tick(){
  for (auto s : m_Bubble){
    s->tick();
    if(!s->isAlive()){
      delete s;
      s = new Bubble;
    }
  }
}

void BubbleFactory::draw(sf::RenderWindow &window){
  for (auto s : m_Bubble)
    s->draw(window);

}
