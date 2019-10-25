#ifndef ENEMIES_H_
#define ENEMIES_H_

#include <SFML/Graphics.hpp>
#include <Interactables.h>

class Enemies : public Interactables{
public:

  //defalt constructor
  Enemies(){};

  sf::Sprite enemy;

  void draw(sf::RenderWindow& window);

  //sets the enemy's position
  void setPos(sf::Vector2f& pos);

  //returns the position of the enemu
  sf::Vector2f getPos();

private:
  sf::Vector2f pos;

};

#endif // !ENEMIES_H_
