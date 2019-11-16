#include "Exit.h"
#include <SFML/Graphics.hpp>

Exit::Exit(){
  fast_exit = false;
  jump_exit = false;

  exit.loadFromFile("..\\resources\\Exit.png");
}



void Exit::draw(sf::RenderWindow& window){
  sf::Sprite e;
  e.setTexture(exit);
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


void Exit::PlayerContact(PlayerChar &player,int id){
  if(player.getType() == true){
    fast_exit = true;
  }
  if(player.getType() == false){
    jump_exit = true;
  }
}
