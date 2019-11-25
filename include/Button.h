#ifndef BUTTON_H_
#define BUTTON_H_

#include <SFML/Graphics.hpp>
#include <Interactables.h>
#include <ResourceManager.h>

class Button : public Interactables{
public:
  //defalt constructor
  Button() {};

  Button(ResourceManager& manager);

  const sf::Texture* spriteSheet;

  sf::Vector2i unpressedButton;

  sf::Vector2i pressedButton;


  void draw(sf::RenderWindow& window);


  //methods to set a position for the button
  void setPos(sf::Vector2f& pos);


  //returns the position of the button
  sf::Vector2f getPos();

  void Toggle();

  void PlayerContact(PlayerChar &player,int id);

  void Reset();

  void setToggleable(Interactables* interactable);

private:
  sf::Vector2f pos;
  bool pressed;

  Interactables* interactable;


};


#endif //!BUTTON_H_
