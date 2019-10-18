#ifndef PLAYER_CHAR_H
#define PLAYER_CHAR_H

#include <SFML/Graphics.hpp>

class PlayerChar{
public:
  //Character contructor
  Char(bool player);

  sf::RectangleShape jumpman; //to be replaced with sprites
  sf::RectangleShape fastman;
  //sf::Sprite ;

  void useItem();

  void draw(sf::RenderWindow&);

  sf::Vector2f getPos();

  void setPos(sf::Vector2f pos);

  void setVelocity(sf::Vector2f vel);

  sf::Vector2f getVelocity();

private:
   sf::Vector2f pos;
   sf::Vector2f vel;
   //defines which character
   bool player;

};


#endif //PLAYER_CHAR_H
