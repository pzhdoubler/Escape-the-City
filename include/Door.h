#ifndef DOOR_H_
#define DOOR_H_

#include <SFML/Graphics.hpp>
#include <Interactables.h>
#include <ResourceManager.h>

class Door : public Interactables{
public:

  Door() {};

  //defalt constructor
  Door(ResourceManager& manager);

  const sf::Texture* spriteSheet;

  sf::Vector2i spriteCoords;

  void draw(sf::RenderWindow& window);


  //methods to set a position for the door
  void setPos(sf::Vector2f& pos);


  //returns the position of the door
  sf::Vector2f getPos();

  void Toggle();

  void setSize(int size);

  void setOrientation(bool orient);

  void Reset();

  void PlayerContact(PlayerChar &player,int id);

private:
  sf::Vector2f pos;
  bool open;
  int size;
  bool orient;

};


#endif //!DOOR_H_
