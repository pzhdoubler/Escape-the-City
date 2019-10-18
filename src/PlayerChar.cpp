#include <SFML/Graphics.hpp>



PlayerChar::PlayerChar(bool player){
  if (player){
    jumpman.setSize(20, 20);
    jumpman.setFillColor(sf::Color::Red);
    jumpman.setOrigin(10, 20);
    jumpman.setPos(10, 20);

  }
  else{
    fastman.setSize(20, 20);
    fastman.setFillColor(sf::Color::Blue);
    fastman.setOrigin(50, 20);
    fastman.setPos(50, 20);
  }
}

void PlayerChar::draw(sf::RenderWindow &window){
    jumpman.setPos(pos);
    window.draw(tall);
    fastman.setPos(pos);
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
