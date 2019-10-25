#include <Button.h>
#include <SFML/Graphics.hpp>

Button::Button(){
  this->pressed = false;
}

void Button::draw(sf::RenderWindow &window){
  window.draw(button);
}

void Button::setPos(sf::Vector2f& pos){
  this->pos.x = pos.x;
  this->pos.y = pos.y;
}

sf::Vector2f Button::getPos(){
  return pos;
}

//tells if the button has been pressed
void Button::Toggle(){
  this->pressed = !pressed;
}
