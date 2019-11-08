#include <Plates.h>
#include <SFML/Graphics.hpp>

Plates::Plates(){
  this->open = false;
}

void Plates::draw(sf::RenderWindow &window){
  sf::Sprite p;
  p.setTexture(plates);
  window.draw(p);
}

void Plates::setPos(sf::Vector2f& pos){
  this->pos.x = pos.x;
  this->pos.y = pos.y;
}

sf::Vector2f Plates::getPos(){
  return pos;
}

//tells if the Plates has been pressed
void Plates::Toggle(){
  this->open = true;
}

void Button::PlayerContact(PlayerChar &player, int id){
  this->Toggle();


}
