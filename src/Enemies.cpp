#include <Enemies.h>
#include <SFML/Graphics.hpp>



void Enemies::draw(sf::RenderWindow& window){
  window.draw(enemy);
}


void Enemies::setPos(sf::Vector2f& pos){
  this->pos.x = pos.x;
  this->pos.y = pos.y;
}



sf::Vector2f Enemies::getPos(){
  return pos;
}


//
