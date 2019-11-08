#include <Door.h>
#include <SFML/Graphics.hpp>

Door::Door(){
  this->open = false;
  door.setSize(sf::Vector2f(40,30));
  door.setFillColor(sf::Color::Green);
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
void Door::Open(){
  sf::Vector2f moveDown = sf::Vector2f(pos.x, pos.y);
  sf::Vector2f moveUp = sf::Vector2f(pos.x + 30, pos.y);
  this->open = !open;
  if(open==false){
    this->setPos(moveUp);
  }
  else{
    this->setPos(moveDown);
  }
}

void Door::PlayerContact(PlayerChar &player, int id){
  if(this->open==false){
    sf::Vector2f vel=player.getVelocity();
    vel.x=0;
    player.setVelocity(vel);
  }
}
