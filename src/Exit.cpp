#include "Exit.h"
#include <SFML/Graphics.hpp>

Exit::Exit(ResourceManager& manager){
  fast_exit = false;
  jump_exit = false;

  sf::Vector2i coords = manager.getSpriteCoords(ResourceManager::Sprites::EXIT);
  spriteCoords.x = coords.x;
  spriteCoords.y = coords.y;
  spriteSheet = &manager.getSpriteSheet();
}



void Exit::draw(sf::RenderWindow& window){
  sf::Vector2i size(40, 40);
  sf::IntRect spritePos(spriteCoords, size);
  sf::Sprite e(*spriteSheet, spritePos);
  e.setPosition(pos);
  window.draw(e);
}


void Exit::setPos(sf::Vector2f& pos){
  this->pos.x = pos.x;
  this->pos.y = pos.y;
}



sf::Vector2f Exit::getPos(){
  return pos;
}

bool Exit::levelEnd(){
  if(fast_exit && jump_exit){
    return true;
  }
  else{
    return false;
  }
}

void Exit::Reset(){
  fast_exit = false;
  jump_exit = false;
}


void Exit::PlayerContact(PlayerChar &player,int id){
  if(player.getType() == true){
    fast_exit = true;
  }
  if(player.getType() == false){
    jump_exit = true;
  }
}
