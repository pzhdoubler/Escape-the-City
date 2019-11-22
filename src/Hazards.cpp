#include <Hazards.h>
#include <SFML/Graphics.hpp>


Hazards::Hazards(ResourceManager& manager){
  this->toggled = false;
  this->orient = true;
  this->size = 1;

  sf::Vector2u coords = manager.getSpriteCoords(ResourceManager::Sprites::HAZARDS);
  spriteCoords.x = coords.x;
  spriteCoords.y = coords.y;
  spriteSheet = &manager.getSpriteSheet();
  //hazard.loadFromFile("..\\resources\\Spikes.png");
}

void Hazards::draw(sf::RenderWindow& window){
  sf::Vector2f position= pos;
  sf::IntRect spritePos(spriteCoords.x, spriteCoords.y, spriteCoords.x + 20, spriteCoords.y + 20);
  if(toggled== false){
    //horizontal surface
    if(orient == true){
      for(int i = 0; i< this->size; i++){
        sf::Sprite h(*spriteSheet, spritePos);
        //h.setTexture(hazard);
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
		sf::Sprite h(*spriteSheet, spritePos);
		//h.setTexture(hazard);
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

}

void Hazards::Reset(){
  this->toggled= false;

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
