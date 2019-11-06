#ifndef PLAYER_CHAR_H
#define PLAYER_CHAR_H

#include <SFML/Graphics.hpp>
#include <GameElements.h>

class PlayerChar : public GameElements {
public:

  //default constructor
  PlayerChar(){};
  //Character contructor
  PlayerChar(bool player);

  sf::RectangleShape jump_man; //to be replaced with sprites
  sf::RectangleShape fast_man;
  //sf::Sprite ;

  //void useItem();

  //draws the characters fast_man and jump_man
  void draw(sf::RenderWindow& window);

  //return the position of the character
  sf::Vector2f getPos();

  //methods to set a position for the characters
  void setPos(sf::Vector2f& pos);

  // method to set a velocity for the characters
  void setVelocity(sf::Vector2f& vel);

  // method returns the velocity of the character as a vector
  sf::Vector2f getVelocity();

  void respawn();

  void setSpawnPt(sf::Vector2f& pos);

  // returns the player character
  bool getType();

  //returns the initial height and width of the characters
  int getHeight();
  int getWidth();

  //determines if character is currently in the air
  bool isInAir();
  void setInAir(bool in_air);

  void printPlayerChar();

  void interact();

  bool interacted();

private:
   sf::Vector2f pos;
   sf::Vector2f vel;
   sf::Vector2f spawn;
   //defines which character
   bool player;
   int height;
   int width;
   bool in_air;
   bool interaction;



};


#endif //PLAYER_CHAR_H
