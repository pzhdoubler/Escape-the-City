#include <Hazards.h>
#include <SFML/Graphics.hpp>


Hazards::Hazards(){
  this->toggled= false;
  this->size = 1;
  hazard.setSize(sf::Vector2f(40,30));
  hazard.setFillColor(sf::Color::Red);


}

void Hazards::draw(sf::RenderWindow& window){
  sf::Vector2f position= pos;
  if(toggled== false){
    if(orient == true){
      hazard.setRotation(90);
      for(int i; i< size; i++){
      hazard.setPosition(position);
      window.draw(hazard);
      position.y=position.y-15;
    }
  }
    else{
      hazard.setRotation(0);
      for(int i; i< size; i++){
      hazard.setPosition(position);
      window.draw(hazard);
      position.x=position.x+20;
    }
    }
}
}



//set hazard's position only used at creation of a hazard
void Hazards::setPos(sf::Vector2f& pos){
  this->pos.x = pos.x;
  this->pos.y = pos.y;
}


//returns the position of the hazard
sf::Vector2f Hazards::getPos(){
  return pos;
}


//
void Hazards::Toggle(){
  this->toggled= !toggled;
  this->pos.y = this->pos.y;

}

void Hazards::setSize(int size){
  this->size = size;
}

void Hazards::setOrientation(bool orient){
  this->orient = orient;
}

void Hazards::PlayerContact(PlayerChar &player, int id){
  if(toggled==false){
  player.respawn();
}

}
