#include <Button.h>
#include <SFML/Graphics.hpp>

Button::Button(){
  this->pressed = false;
}

void Button::draw(sf::RenderWindow &window){
  sf::Sprite b;
  b.setTexture(button);
  window.draw(b);
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

void Button::PlayerContact(PlayerChar &player,int id){
  if(player.interacted()==1){
  this->Toggle();
}

}
