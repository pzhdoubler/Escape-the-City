#include <Button.h>
#include <SFML/Graphics.hpp>

Button::Button(ResourceManager& manager){
  this->pressed = false;

  sf::Vector2i unpressed = manager.getSpriteCoords(ResourceManager::Sprites::BUTTON_OFF);
  unpressedButton.x = unpressed.x;
  unpressedButton.y = unpressed.y;
  sf::Vector2i pressed = manager.getSpriteCoords(ResourceManager::Sprites::BUTTON_ON);
  pressedButton.x = pressed.x;
  pressedButton.y = pressed.y;
  spriteSheet = &manager.getSpriteSheet();
  //button.loadFromFile("..\\resources\\Button.png");
  //pressedButton.loadFromFile("..\\resources\\ButtonPressed.png");
}

void Button::draw(sf::RenderWindow &window){
  sf::Vector2i size(20, 20);
  if(pressed == true){
	sf::IntRect pressedSpritePos(pressedButton, size);
    sf::Sprite b(*spriteSheet, pressedSpritePos);
    //b.setTexture(button);
    b.setPosition(pos);
    window.draw(b);
}
  else{
	sf::IntRect unpressedSpritePos(unpressedButton, size);
	sf::Sprite p(*spriteSheet, unpressedSpritePos);
    //p.setTexture(pressedButton);
    p.setPosition(pos);
    window.draw(p);
  }

}

void Button::setPos(sf::Vector2f& pos){
  this->pos.x = pos.x;
  this->pos.y = pos.y;
}


sf::Vector2f Button::getPos(){
  return pos;
}

//tells if the button has been pressed
void Button::Toggle(){
  this->pressed = !pressed;

}

void Button::Reset(){
  this->pressed = false;
  interactable->Reset();
}

void Button::setToggleable(Interactables* interactable){
  this->interactable = interactable;
}

void Button::PlayerContact(PlayerChar &player,int id){
  if(player.interacted()==true){
  this->Toggle();
  interactable->Toggle();
}

}
