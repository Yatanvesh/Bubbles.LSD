#include <SFML/Graphics.hpp>
#include <iostream>
#include "globals.h"
using namespace std;
class Ship{
public:
  double rotation;
  double angle=0;
  double speed=3;
  double radius = 5;
  sf::Texture texture;
  sf::Sprite sprite;

  Ship();
  ~Ship();

  void fly();


};
