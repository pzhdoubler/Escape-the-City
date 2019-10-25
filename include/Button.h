#ifndef BUTTON_H_
#define BUTTON_H_

#include <SFML/Graphics.hpp>
#include <Interactables.h>

class Button : public Interactables{
public:
  //defalt constructor
  Button();

  sf::Sprite button;


  void draw(sf::RenderWindow& window);


  //methods to set a position for the button
  void setPos(sf::Vector2f& pos);


  //returns the position of the button
  sf::Vector2f getPos();

  void Toggle();



private:
  sf::Vector2f pos;
  bool pressed;


};


#endif //!BUTTON_H_
