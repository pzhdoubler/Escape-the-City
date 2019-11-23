#include <SFML/Graphics.hpp>
#include <PlayerChar.h>


PlayerChar::PlayerChar(bool player, ResourceManager& manager){
  this->player = player;
  this->height = 18;
  this->width = 15;
  this->in_air = true;
  this->interaction = false;
  this->powerUp = 0;
  spriteSheet = &manager.getSpriteSheet();
  if (player){
	  sf::Vector2i coords = manager.getSpriteCoords(ResourceManager::Sprites::FAST_MAN);
	  spriteCoords.x = coords.x;
	  spriteCoords.y = coords.y;
  }
  else{
	  sf::Vector2i coords = manager.getSpriteCoords(ResourceManager::Sprites::JUMP_MAN);
	  spriteCoords.x = coords.x;
	  spriteCoords.y = coords.y;
  }
}

void PlayerChar::draw(sf::RenderWindow &window){
	sf::Vector2i size(20, 20);
	sf::IntRect spritePos(spriteCoords, size);
	sf::Sprite p(*spriteSheet, spritePos);
	p.setPosition(pos);
    window.draw(p);

}

sf::Vector2f PlayerChar::getPos(){
  return pos;
}

void PlayerChar::setPos(sf::Vector2f& pos){
  this->pos.x = pos.x;
  this->pos.y = pos.y;
}

void PlayerChar::setVelocity(sf::Vector2f& vel){
  this->vel.x = vel.x;
  this->vel.y = vel.y;
}

sf::Vector2f PlayerChar::getVelocity(){
  return vel;
}

int PlayerChar::getHeight(){
  return height;
}

int PlayerChar::getWidth(){
  return width;
}

bool PlayerChar::getType(){
  return player;
}

bool PlayerChar::isInAir() {
  return in_air;
}

void PlayerChar::setInAir(bool in_air) {
  this->in_air = in_air;
}

void PlayerChar::printPlayerChar() {
	if (player)
		printf("Type: Fast\n");
	else
		printf("Type: Jump\n");

	printf("Position: { %f, %f }\n", pos.x, pos.y);
	printf("Velocity: { %f, %f }\n", vel.x, vel.y);
	printf("Height: %d\n", height);
	printf("Width: %d\n", width);

	printf("\n");
}

void PlayerChar::setSpawnPt(sf::Vector2f& pos){
  this->spawn.x = pos.x;
  this->spawn.y = pos.y;
}

void PlayerChar::respawn(){
  this->vel = sf::Vector2f(0, 0);
  if(powerUp != 0){
  //this->item->Toggle();
}
  this->powerUp = 0;
  setPos(spawn);

}

void PlayerChar::interact(bool interact){
  this->interaction = interact;
}

bool PlayerChar::interacted(){
  return interaction;
}

void PlayerChar::setItem(int id, GameElements* interactable){
  this->item = interactable;
  if(id == 1){
    this->powerUp = 1;
  }
}

void PlayerChar::useItem(){
  printf("%d", powerUp );
  if(player && this->powerUp == 1){
    this->vel.y = -300;
    this->powerUp = 0;
  }
  if(player == false && this->powerUp == 1){
  this->vel.y = -500;
  this->powerUp = 0;
}
}

int PlayerChar::getPowerUp(){
  return this->powerUp;
}
