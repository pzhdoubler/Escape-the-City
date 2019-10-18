#include <SFML/Graphics.hpp>



PlayerChar::PlayerChar(bool player){
  if (player){
    fast_man.setSize(20, 20);
    fast_man.setFillColor(sf::Color::Blue);
    fast_man.setPos(50, 20);


  }
  else{
    jump_man.setSize(20, 20);
    jump_man.setFillColor(sf::Color::Red);
    jump_man.setPos(10, 20);
  }
}

void PlayerChar::draw(sf::RenderWindow &window){
    jump_man.setPos(pos);
    window.draw(jump_man);
    fast_man.setPos(pos);
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

void PlayerChar::UseItem(){

}
