#include <SFML/Graphics.hpp>



PlayerChar::PlayerChar(bool player){
  if (player){
    tall.setSize(25, 25);
    tall.setFillColor(sf::Color::Red);
    tall.setOrigin(10, 20);
    tall.setPos(10, 20);

  }
  else{
    fast.setSize(25, 25);
    fast.setFillColor(sf::Color::Blue);
    fast.setOrigin(50, 20);
    fast.setPos(50, 20);
  }
}

void PlayerChar::draw(sf::RenderWindow &window){
    setPos(pos);
    window.draw(tall);
    window.draw(fast);

}

void PlayerChar::getPos(){
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
