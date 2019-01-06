#ifndef VIEW_H
#define VIEW_H


#include <SFML/Graphics.hpp>
#include "globals.h"

class View : public sf::View{
public:
  View(sf::FloatRect rect,sf::Sprite *Target,sf::RenderWindow *window);
  void focus();
private:
  sf::Sprite *Target;
  sf::RenderWindow *window;
  double rotation;
  int posCoef=300;
  int shockCoef= 5;
};

#endif
