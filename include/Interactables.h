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

  void PlayerContact(PlayerChar &player, int id);

private:



};

#endif //INTERACTABLES_H
