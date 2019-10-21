#include <SFML/Graphics.hpp>
#include <PlayerChar.h>


PlayerChar::PlayerChar(bool player){
  this->player = player;
  this->height = 18;
  this->width = 15;
  if (player){
    fast_man.setSize(sf::Vector2f(width, height));
    fast_man.setFillColor(sf::Color::Red);
    fast_man.setPosition(sf::Vector2f(0, 0));


  }
  else{
    jump_man.setSize(sf::Vector2f(width, height));
    jump_man.setFillColor(sf::Color::Blue);
    jump_man.setPosition(sf::Vector2f(10, 0));
  }
}

void PlayerChar::draw(sf::RenderWindow &window){
    jump_man.setPosition(pos);
    window.draw(jump_man);
    fast_man.setPosition(pos);
    window.draw(fast_man);

}

sf::Vector2f PlayerChar::getPos(){
  return pos;
}

void PlayerChar::setPos(sf::Vector2f pos){
	//printf("prev pos: %f, %f\n", this->pos.x, this->pos.y);
	//printf("passed pos: %f, %f\n", pos.x, pos.y);
	this->pos = pos;
	//printf("final pos: %f, %f\n\n", this->pos.x, this->pos.y);
}

void PlayerChar::setVelocity(sf::Vector2f vel){
	//printf("prev vel: %f, %f\n", this->vel.x, this->vel.y);
	//printf("passed vel: %f, %f\n", vel.x, vel.y);
	this->vel = vel;
	//printf("final vel: %f, %f\n\n", this->vel.x, this->vel.y);
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

/*void PlayerChar::UseItem(){

}
*/