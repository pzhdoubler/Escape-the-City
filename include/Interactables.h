#ifndef INTERACTABLES_H
#define INTERACTABLES_H

#include <SFML/Graphics.hpp>
#include <GameElements.h>
#include <PlayerChar.h>

class Interactables : public GameElements {
public:
  //defalt constructor
  Interactables(){};

  virtual void draw(sf::RenderWindow& window)= 0;

  virtual void setPos(sf::Vector2f& pos) = 0;

  virtual sf::Vector2f getPos() = 0;

  virtual void Toggle() = 0;

  virtual void PlayerContact(PlayerChar &player, int id) = 0;

  enum Color {Red, Blue, Green, Purple, Yellow, Orange };

private:



};

#endif //INTERACTABLES_H
