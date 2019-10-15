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
    window.draw(tall);
    window.draw(fast);

}

float PlayerChar::getPos(x, y){
  return pos;
}

void PlayerChar::setPos(pos){
  if (player){
    pos.x=x;
    pos.y=y;
  }
  else{
    pos.x=x;
    pos.y=y;
  }
}

void PlayerChar::setVelocity(vel){
  if (player){
    vel.x=x;
    vel.y=y;
  }
  else{
    vel.x=x;
    vel.y=y;
  }
}

sf::Vector2f PlayerChar::getVelocity(){
  return vel;
}

void PlayerChar::UseItem(){

}
