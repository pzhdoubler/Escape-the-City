#include <Door.h>
#include <SFML/Graphics.hpp>

Door::Door(){
  this->open = false;
  door.setSize(sf::Vector2f(40,30));
  door.setFillColor(sf::Color::Green);
}

void Door::draw(sf::RenderWindow &window){

  if(open == false){
  if(orient== true){
    door.setRotation(90);
    door.setPosition(pos);
    window.draw(door);
  }
  else{
    door.setRotation(0);
    door.setPosition(pos);
    window.draw(door);
  }
}
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

void Door::setOrientation(bool orient){
  this->orient = orient;
}

void Door::setSize(int size){
  this->size = size;
}

void Door::PlayerContact(PlayerChar &player, int id){
  if(this->open==false){
    sf::Vector2f vel = player.getVelocity();
    sf::Vector2f position = getPos();
    vel.x = 0;
    position.x = position.x-20;
    player.setVelocity(vel);
    player.setPos(position);
  }
}
