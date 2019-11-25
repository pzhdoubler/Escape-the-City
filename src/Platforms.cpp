#include <Platforms.h>
#include <SFML/Graphics.hpp>

Platforms::Platforms(){
  this->size = 2;
  this->direction = true;
  this->time = 0;
  this->toggled = false;
  platform.loadFromFile("..\\resources\\Door_Texture.png");
}

void Platforms::draw(sf::RenderWindow &window){
  sf::Vector2f position = this->curPos;
  if(this->direction){

  for(int i = 0; i< 2; i++){

  sf::Sprite p;
  p.setTexture(platform);
  p.setPosition(position);

  window.draw(p);
  position.x=position.x+20;
}

if(time>.02){
  if(this->toggled == false){
  this->curPos.x = curPos.x + 1;}
  time= time-.02;
}
}
if(direction == false){
  for(int i = 0; i< 2; i++){

  sf::Sprite p;
  p.setTexture(platform);
  p.setPosition(position);

  window.draw(p);
position.x=position.x+20;}
  if(time>.02){
    if(this->toggled == false){
    this->curPos.x = curPos.x - 1;}
    time= time-.02;
  }

}
if(curPos.x<=pos.x){
  direction = true;

}
if(curPos.x>=pos.x+(this->size*20 )-40){
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

void Platforms::setTime(float deltaMs){
 this->time = this->time + deltaMs;
}

void Platforms::setSize(int size){
  this->size = size;
}

void Platforms::PlayerContact(PlayerChar &player, int id){
  sf::Vector2f vel = player.getVelocity();
  sf::Vector2f position = player.getPos();



  /*if(position.y>curPos.y && position.x<curPos.x+40 && position.x>curPos.x-11){
    vel.y = 0;
    position.y = pos.y+20;
    player.setVelocity(vel);
    player.setPos(position);
}*/
  if(position.y<curPos.y-8 && (position.x<curPos.x+40 && position.x>curPos.x-11)&& position.y>curPos.y-10 ){
    vel.y = 0;
    if(this->direction){
    if(time>.02){
      position.x= position.x + 1;
    }
  }
    if(this->direction == false){
      if(time>.02){
        position.x= position.x - 1;
      }
    }
    player.setInAir(false);
    //position.y = pos.y-18;
    player.setVelocity(vel);
    player.setPos(position);
}
 /*else if (position.x>curPos.x-15 && position.x<curPos.x+41){
   printf("1" );
  if(position.x>curPos.x+40 ){
    printf("2" );
  position.x = curPos.x+41;}
  else if(position.x<curPos.x){
    printf("3" );
    //vel.x=0;
  position.x = curPos.x-15;}
  player.setVelocity(vel);
  player.setPos(position);
}*/



}
