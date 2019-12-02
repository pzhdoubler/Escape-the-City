#include <Items.h>
#include <SFML/Graphics.hpp>


Items::Items(ResourceManager& manager, int id) {
  this->pickup= false;

  sf::Vector2i coords;

  if (id == 3 || id == 4)
	  coords = manager.getSpriteCoords(ResourceManager::Sprites::SPEED_ITEM);
  else
	  coords = manager.getSpriteCoords(ResourceManager::Sprites::JUMP_ITEM);

  spriteCoords.x = coords.x;
  spriteCoords.y = coords.y;

  spriteSheet = &manager.getSpriteSheet();
}

void Items::draw(sf::RenderWindow& window){
  if(pickup == false){
  sf::Vector2i size(20, 20);
  sf::IntRect spritePos(spriteCoords, size);
  sf::Sprite i(*spriteSheet, spritePos);
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
