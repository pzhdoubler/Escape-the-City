#ifndef ITEMS_H_
#define ITEMS_H_

#include <SFML/Graphics.hpp>
#include <Interactables.h>
#include <ResourceManager.h>

class Items : public Interactables {
public:

  Items() {};

  Items(ResourceManager& manager, int id);

  const sf::Texture* spriteSheet;

  sf::Vector2i spriteCoords;

  void draw(sf::RenderWindow& window);

  void setPos(sf::Vector2f& pos);


  //returns the position of the hazard
  sf::Vector2f getPos();

  void PlayerContact(PlayerChar &player, int id);
  void Toggle();

  void Reset();




private:
  sf::Vector2f pos;
  bool pickup;

};

#endif // !ITEMS_H_
