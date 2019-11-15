#include <Door.h>
#include <SFML/Graphics.hpp>

Door::Door(){
  this->open = false;
  this->size = 2;
  door.loadFromFile("..\\resources\\Door_Texture.png");
}

void Door::draw(sf::RenderWindow &window){
  sf::Vector2f position = pos;
  if(open == false){
  if(orient== true){
    for(int i = 0; i< this->size; i++){
    position.x=position.x+20;
    sf::Sprite d;
    d.setTexture(door);
    d.setRotation(90);
    d.setPosition(position);
    window.draw(d);

  }

  }
  else{
    for(int i = 0; i< this->size; i++){
    sf::Sprite d;
    d.setTexture(door);
    d.setRotation(0);
    d.setPosition(position);
    window.draw(d);
    position.y=position.y+20;
  }
  }
}
}

void Door::setPos(sf::Vector2f& pos){
  this->pos.x = pos.x;
  this->pos.y = pos.y;
}

sf::Vector2f Door::getPos(){
  return pos;
}

//tells if the Door has been pressed
void Door::Toggle(){
  //sf::Vector2f moveDown = sf::Vector2f(pos.x, pos.y);
  //sf::Vector2f moveUp = sf::Vector2f(pos.x + 30, pos.y);
  this->open = !open;
  //if(open==false){
  //  this->setPos(moveUp);
//  }
//  else{
//  }
}

void Door::setOrientation(bool orient){
  this->orient = orient;
}

void Door::setSize(int size){
  this->size = size;
}

void Door::PlayerContact(PlayerChar &player, int id){
  sf::Vector2f vel = player.getVelocity();
  sf::Vector2f position = player.getPos();
  if(this->open==false){
    if(this->orient == false){
    vel.x = 0;
    if(position.x>pos.x){

      position.x = pos.x+20;
      player.setVelocity(vel);
      player.setPos(position);
  }
    else{
      position.x = pos.x-16;
      player.setVelocity(vel);
      player.setPos(position);
  }
  }
  else{

    vel.y = 0;
    if(position.y>pos.y){
      position.y = pos.y+20;
      player.setVelocity(vel);
      player.setPos(position);
  }
    else{
      player.setInAir(false);
      position.y = pos.y-19;
      player.setVelocity(vel);
      player.setPos(position);
  }
}
}
}
