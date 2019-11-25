#include <Items.h>
#include <SFML/Graphics.hpp>


Items::Items(){
  this->pickup= false;
  item.loadFromFile("..\\resources\\Button.png");

}

void Items::draw(sf::RenderWindow& window){
  if(pickup == false){
  sf::Sprite i;
  i.setTexture(item);
  i.setPosition(pos);
  window.draw(i);
}

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
void Items::Toggle(){
  this->pickup= !pickup;
}

void Items::Reset(){
  this->pickup = false;
}



void Items::PlayerContact(PlayerChar &player, int id){
  if(pickup == false && player.powerUp == 0){
    pickup = true;
    int i = id-35;
    player.setItem(i);
  }
}
