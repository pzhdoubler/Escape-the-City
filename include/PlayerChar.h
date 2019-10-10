#ifndef PLAYER_CHAR_H
#define PLAYER_CHAR_H

#include <SFML/Graphics.hpp>

class PlayerChar{
public:
  //Character contructor
  Char(player);
  //sf::Vector2f pos;
  //sf::Sprite ;


  void useItem();

  void getPos();

  float setPos(x, y);

  float setVelocity(i, j);

  void getVelocity()

  //defines which character
  bool player;

private:
   float x, y, i, j;


};


#endif //PLAYER_CHAR_H
