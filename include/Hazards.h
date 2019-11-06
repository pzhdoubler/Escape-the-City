#ifndef HAZARDS_H
#define HAZARDS_H

#include <SFML/Graphics.hpp>
#include <Interactables.h>

class Hazards : public Interactables {
public:

  Hazards();

  //sf::Sprite hazard;
  sf::RectangleShape hazard;

  void draw(sf::RenderWindow& window);

  void setPos(sf::Vector2f& pos);


  //returns the position of the hazard
  sf::Vector2f getPos();


  void Toggle();



private:
  sf::Vector2f pos;
  bool toggled;

};

#endif // !HAZARDS_H_
