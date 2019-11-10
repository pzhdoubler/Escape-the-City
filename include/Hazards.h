#ifndef HAZARDS_H
#define HAZARDS_H

#include <SFML/Graphics.hpp>
#include <Interactables.h>

class Hazards : public Interactables {
public:

  Hazards();

  //sf::Texture hazard;
  sf::RectangleShape hazard;

  void draw(sf::RenderWindow& window);

  void setPos(sf::Vector2f& pos);


  //returns the position of the hazard
  sf::Vector2f getPos();

  void PlayerContact(PlayerChar &player,int id);

  void Toggle();

  void setSize(int size);

  void setOrientation(bool orient);


private:
  sf::Vector2f pos;
  bool toggled;
  int size;
  bool orient;



};

#endif // !HAZARDS_H_
