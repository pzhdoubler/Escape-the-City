#ifndef PLATFORMS_H_
#define PLATFORMS_H_

#include <SFML/Graphics.hpp>
#include <Interactables.h>

class Platforms : public Interactables{
public:
  //defalt constructor
  Platforms();

  sf::Texture platform;


  void draw(sf::RenderWindow& window);


  //methods to set a position for the Platforms
  void setPos(sf::Vector2f& pos);

  //returns the position of the Platforms
  sf::Vector2f getPos();

  void setSize(int size);

  void Toggle();

  void Reset();

  void PlayerContact(PlayerChar &player, int id);

 void setTime(float deltaMs);


private:
  sf::Vector2f pos;
  float time;
  sf::Vector2f curPos;
  bool direction;
  int size;
  bool toggled;
  Interactables* interactable;


};




#endif
