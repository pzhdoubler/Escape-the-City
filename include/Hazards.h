#ifndef HAZARDS_H
#define HAZARDS_H

#include <SFML/Graphics.hpp>
#include <Interactables.h>
#include <ResourceManager.h>

class Hazards : public Interactables {
public:

  Hazards() {};

  Hazards(ResourceManager& manager);

  const sf::Texture* spriteSheet;

  sf::Vector2i spriteCoords;

  void draw(sf::RenderWindow& window);

  void setPos(sf::Vector2f& pos);


  //returns the position of the hazard
  sf::Vector2f getPos();

  void PlayerContact(PlayerChar &player,int id);

  void Toggle();

  void setSize(int size);

  void Reset();

  void setOrientation(bool orient);


private:
  sf::Vector2f pos;
  bool toggled;
  int size;
  bool orient;



};

#endif // !HAZARDS_H_
