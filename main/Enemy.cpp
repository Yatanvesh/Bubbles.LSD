#include "Enemy.h"

Enemy::Enemy(){
  if(!texture.loadFromFile("./main/assets/img/enemy.png") )
    cout<< "File not found error";

    sprite.setTexture(texture);
    sprite.scale(0.3,0.3);
    sprite.setOrigin(sprite.getLocalBounds().width/2, sprite.getLocalBounds().height/2);
    sprite.setPosition(SCREEN_CENTRE);
}

void Enemy::tick(){

}

void Enemy::draw(sf::RenderWindow &window){
  window.draw(sprite);
}
