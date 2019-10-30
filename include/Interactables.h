#ifndef INTERACTABLES_H
#define INTERACTABLES_H

#include <SFML/Graphics.hpp>
#include <GameElements.h>

class Interactables : public GameElements {
public:
  //defalt constructor
  Interactables(){};

  virtual void draw(sf::RenderWindow& window)= 0;



private:



};

#endif //INTERACTABLES_H
