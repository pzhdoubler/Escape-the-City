#include <Button.h>
#include <SFML/Graphics.hpp>

Button::Button(){
  this->pressed = 0;
}

void Button::draw(sf::RenderWindow &window){
  window.draw(button);
}

void Button::setPos(sf::Vector2f& pos){
  this->pos.x = pos.x;
  this->pos.y = pos.y;
}

void Toggle(){
  this->pressed = !pressed;
}
