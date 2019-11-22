#include <Platforms.h>
#include <SFML/Graphics.hpp>

Platforms::Platforms(){
  this->size = 2;
  this->direction =   true;
  platform.loadFromFile("..\\resources\\pixil-frame-0 (2).png");
}

void Platforms::draw(sf::RenderWindow &window){
  sf::Vector2f position = this->curPos;

  if(this->direction){

  for(int i = 0; i< 2; i++){
  position.x=position.x+20;
  sf::Sprite p;
  p.setTexture(platform);
  p.setPosition(position);

  window.draw(p);
}this->curPos.x = curPos.x + 1;
}
if(direction == false){
  for(int i = 0; i< 2; i++){
  position.x=position.x-20;
  sf::Sprite p;
  p.setTexture(platform);
  p.setPosition(position);

  window.draw(p);}
  this->curPos.x = curPos.x - 1;
}
if(curPos.x<=pos.x-(this->size*10)){
  direction = true;

}
if(curPos.x>=pos.x){
  direction = false;
}
}

void Platforms::setPos(sf::Vector2f& pos){
  this->pos.x = pos.x;
  this->pos.y = pos.y;
  this->curPos.x = pos.x;
  this->curPos.y = pos.y;
}

sf::Vector2f Platforms::getPos(){
  return pos;
}

//tells if the Platforms has been toggled
void Platforms::Toggle(){
  this->toggled = !toggled;
}

void Platforms::Reset(){
  this->toggled = false;
}

void Platforms::setSize(int size){
  this->size = size;
}

void Platforms::PlayerContact(PlayerChar &player, int id){
  sf::Vector2f vel = player.getVelocity();
  sf::Vector2f position = player.getPos();
  printf("1" );
  vel.y = 0;
  if(position.y>pos.y){

    position.y = pos.y+23;
    player.setVelocity(vel);
    player.setPos(position);
}
  else{
    player.setInAir(false);
    position.y = pos.y-21;
    player.setVelocity(vel);
    player.setPos(position);
}

}
