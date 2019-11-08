#ifndef DOOR_H_
#define DOOR_H_

#include <SFML/Graphics.hpp>
#include <Interactables.h>

class Door : public Interactables{
public:
  //defalt constructor
  Door();

  sf::RectangleShape door;


  void draw(sf::RenderWindow& window);


  //methods to set a position for the door
  void setPos(sf::Vector2f& pos);


  //returns the position of the door
  sf::Vector2f getPos();

  void Open();

  void PlayerContact(PlayerChar &player,int id);

private:
  sf::Vector2f pos;
  bool open;


};


#endif //!DOOR_H_