#ifndef PLATFORMS_H_
#define PLATFORMS_H_

#include <SFML/Graphics.hpp>
#include <Interactables.h>
#include <ResourceManager.h>

class Platforms : public Interactables{
public:
  //defalt constructor
  Platforms() {};

  Platforms(ResourceManager& manager);

  const sf::Texture* spriteSheet;

  sf::Vector2i platOnCoords;

  sf::Vector2i platOffCoords;

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

  void setOrientation(bool orient);

private:
  sf::Vector2f pos;
  float time;
  float time2;
  sf::Vector2f curPos;
  bool direction;
  int size;
  bool toggled;
  bool orientation;
  int velocity = 100;
  Interactables* interactable;


};




#endif
