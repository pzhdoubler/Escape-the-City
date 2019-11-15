#include <Hazards.h>
#include <SFML/Graphics.hpp>


Hazards::Hazards(){
  this->toggled = false;
  this->orient = true;
  this->size = 1;

  hazard.loadFromFile("..\\resources\\Spikes.png");


}

void Hazards::draw(sf::RenderWindow& window){
  sf::Vector2f position= pos;
  if(toggled== false){
    //horizontal surface
    if(orient == true){
      for(int i = 0; i< this->size; i++){
        sf::Sprite h;
        h.setTexture(hazard);
        h.setRotation(0);
       h.setPosition(position);
      window.draw(h);
      position.x=position.x+20;
    }
  }
  //vertical surface
    else{
      position.x=position.x+20;
      for(int i = 0; i< this->size; i++){      
        sf::Sprite h;
        h.setTexture(hazard);
        h.setRotation(90);
       h.setPosition(position);
      window.draw(h);
      position.y=position.y+20;
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
