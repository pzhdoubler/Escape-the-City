#ifndef PLATES_H_
#define PLATES_H_

#include <SFML/Graphics.hpp>
#include <Interactables.h>

class Plates : public Interactables{
public:
  //defalt constructor
  Plates();

  sf::Texture plates;


  void draw(sf::RenderWindow& window);


  //methods to set a position for the Plates
  void setPos(sf::Vector2f& pos);


  //returns the position of the Plates
  sf::Vector2f getPos();

  void Toggle();

  void PlayerContact(PlayerChar &player, int id);



private:
  sf::Vector2f pos;
  bool open;


};


#endif //!Plates_H_
