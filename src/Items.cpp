#include <Items.h>
#include <SFML/Graphics.hpp>


Items::Items(){
  this->pickup= 0;

}

void Items::draw(sf::RenderWindow& window){
  sf::Sprite i;
  i.setTexture(item);
  i.setPosition(pos);
  window.draw(i);
}

//set item's position only used at creation of a item
void Items::setPos(sf::Vector2f& pos){
  this->pos.x = pos.x;
  this->pos.y = pos.y;
}


//returns the position of the item
sf::Vector2f Items::getPos(){
  return pos;
}


//tells if an item has been picked up
void Items::Pickup(){
  this->pickup= !pickup;

}
