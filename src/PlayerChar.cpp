#include <SFML/Graphics.hpp>
#include <PlayerChar.h>


PlayerChar::PlayerChar(bool player){
  this->player = player;
  this->height = 18;
  this->width = 15;
  if (player){
    fast_man.setSize(sf::Vector2f(width, height));
    fast_man.setFillColor(sf::Color::Blue);
    fast_man.setPosition(sf::Vector2f(0, 0));


  }
  else{
    jump_man.setSize(sf::Vector2f(width, height));
    jump_man.setFillColor(sf::Color::Red);
    jump_man.setPosition(sf::Vector2f(10, 0));
  }
}

void PlayerChar::draw(sf::RenderWindow &window){
    jump_man.setPosition(pos);
    window.draw(jump_man);
    fast_man.setPosition(pos);
    window.draw(fast_man);

}

sf::Vector2f PlayerChar::getPos(){
  return pos;
}

void PlayerChar::setPos(sf::Vector2f pos){
  if (player){
    this->pos=pos;
  }
  else{
    this->pos=pos;
  }
}

void PlayerChar::setVelocity(sf::Vector2f vel){
  if (player){
    this->vel=vel;
  }
  else{
    this->vel=vel;
  }
}

sf::Vector2f PlayerChar::getVelocity(){
  return vel;
}

int PlayerChar::getHeight(){
  return height;
}

int PlayerChar::getWidth(){
  return width;
}

bool PlayerChar::getType(){
  return player;
}

/*void PlayerChar::UseItem(){

}
*/