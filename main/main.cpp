#include <time.h>
#include <stdio.h>
#include <SFML/Window.hpp>
#include "BubbleFactory.h"
#include <iostream>

void globalInit();

int main(int argc, char* argv[]){
  srand (time(NULL));
  globalInit();

  if (argc>1){
      int resolution;
      sscanf(argv[1], "%d", &resolution);
      printf("%d",resolution);
      SCREEN_DIMS.x= SCREEN_DIMS.y = resolution;
      SCREEN_CENTRE.x = SCREEN_DIMS.x/2;
      SCREEN_CENTRE.y = SCREEN_DIMS.y/2;
  }

  sf::RenderWindow window(sf::VideoMode(SCREEN_DIMS.x,SCREEN_DIMS.y), "Bubbles on LSD");
  window.setVerticalSyncEnabled(true);

  BubbleFactory BubbleFactory;

  while(window.isOpen()){
    sf::Event event;
    while(window.pollEvent(event)){
      if(event.type == sf::Event::Closed)
        window.close();
    }

    BubbleFactory.tick();

    window.clear();
    BubbleFactory.draw(window);
    window.display();
  }
  return 0;
}

void globalInit(){
  SCREEN_DIMS.x= 1080;
  SCREEN_DIMS.y=1080;
  SCREEN_CENTRE.x = SCREEN_DIMS.x/2;
  SCREEN_CENTRE.y = SCREEN_DIMS.y/2;
}
