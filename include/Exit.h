#ifndef EXIT_H_
#define EXIT_H_

#include <SFML/Graphics.hpp>
#include <Interactables.h>
#include <ResourceManager.h>

class Exit : public Interactables{
public:

  //defalt constructor
  Exit() {};

  Exit(ResourceManager& manager);

  const sf::Texture* spriteSheet;

  sf::Vector2i spriteCoords;

  void draw(sf::RenderWindow& window);

  //sets the exit's position
  void setPos(sf::Vector2f& pos);

  //returns the position of the exit
  sf::Vector2f getPos();

  void Toggle() {};

  bool levelEnd();

  void Reset();

  void PlayerContact(PlayerChar &player,int id);

private:
  sf::Vector2f pos;
  bool fast_exit;
  bool jump_exit;

};

#endif // !ENEMIES_H_
