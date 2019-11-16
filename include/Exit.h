#ifndef EXIT_H_
#define EXIT_H_

#include <SFML/Graphics.hpp>
#include <Interactables.h>

class Exit : public Interactables{
public:

  //defalt constructor
  Exit();

  sf::Texture exit;

  void draw(sf::RenderWindow& window);

  //sets the exit's position
  void setPos(sf::Vector2f& pos);

  //returns the position of the exit
  sf::Vector2f getPos();

  bool levelEnd();

  void PlayerContact(PlayerChar &player,int id);

private:
  sf::Vector2f pos;
  bool fast_exit;
  bool jump_exit;

};

#endif // !ENEMIES_H_
