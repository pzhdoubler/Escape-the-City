#include <Hazards.h>
#include <SFML/Graphics.hpp>


Hazards::Hazards(){
  this->toggled= 0;

}

void Hazards::draw(sf::RenderWindow& window){
  window.draw(hazard);
}

void Hazards::setPos(sf::Vector2f& pos){
  this->pos.x = pos.x;
  this->pos.y = pos.y;
}


//returns the position of the hazard
sf::Vector2f Hazards::getPos(){
  return pos;
}



void Hazards::Toggle(){
  this->toggled= !toggled;

}
