#include <Enemies.h>
#include <SFML/Graphics.hpp>



void Enemies::draw(sf::RenderWindow& window){
  sf::Sprite e;
  e.setTexture(enemy);
  e.setPosition(pos);
  window.draw(e);
}


void Enemies::setPos(sf::Vector2f& pos){
  this->pos.x = pos.x;
  this->pos.y = pos.y;
}



sf::Vector2f Enemies::getPos(){
  return pos;
}


//
