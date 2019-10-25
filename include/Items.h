#ifndef ITEMS_H_
#define ITEMS_H_

#include <SFML/Graphics.hpp>
#include <Interactables.h>

class Items : public Interactables {
public:

  Items();

  sf::Sprite item;

  void draw(sf::RenderWindow& window);

  void setPos(sf::Vector2f& pos);


  //returns the position of the hazard
  sf::Vector2f getPos();


  void Pickup();



private:
  sf::Vector2f pos;
  bool pickup;

};

#endif // !ITEMS_H_
