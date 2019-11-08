#include <Hazards.h>
#include <SFML/Graphics.hpp>


Hazards::Hazards(){
  this->toggled= 0;
  hazard.setSize(sf::Vector2f(40,30));
  hazard.setFillColor(sf::Color::Red);


}

void Hazards::draw(sf::RenderWindow& window){
  hazard.setPosition(pos);
  window.draw(hazard);
}

//set hazard's position only used at creation of a hazard
void Hazards::setPos(sf::Vector2f& pos){
  this->pos.x = pos.x;
  this->pos.y = pos.y;
}


//returns the position of the hazard
sf::Vector2f Hazards::getPos(){
  return pos;
}


//
void Hazards::Toggle(){
  this->toggled= !toggled;
  this->pos.y = this->pos.y;

}

void Hazards::PlayerContact(PlayerChar &player, int id){
  player.respawn();
}
