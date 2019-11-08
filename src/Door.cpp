#include <Door.h>
#include <SFML/Graphics.hpp>

Door::Door(){
  this->open = false;
}

void Door::draw(sf::RenderWindow &window){
  window.draw(door);
}

void Door::setPos(sf::Vector2f& pos){
  this->pos.x = pos.x;
  this->pos.y = pos.y;
}

sf::Vector2f Door::getPos(){
  return pos;
}

//tells if the Door has been pressed
void Door::Toggle(){
  this->open = !open;
  if(open==false){
    this->setPos(sf::Vector2f(pos.x - 30, pos.y));
  }
  else{
    this->setPos(sf::Vector2f(pos.x + 30, pos.y));
  }
}

void Door::PlayerContact(PlayerChar &player, int id){
  if(this->open==false){
    vel=player.getVelocity();
    vel.x=0;
    player.setVelocity(sf::Vector2f(vel));
  }
}
