#include <Hazards.h>
#include <SFML/Graphics.hpp>


Hazards::Hazards(){
  this->toggled= 0;
  
}

void draw(sf::RenderWindow& window){
  window.draw(this);
}

void setPos(sf::Vector2f& pos){
  this->pos.x = pos.x;
  this->pos.y = pos.y;
}


//returns the position of the hazard
sf::Vector2f getPos(){
  return pos;
}



void Toggle(){
  this->toggled= !toggled;

}
