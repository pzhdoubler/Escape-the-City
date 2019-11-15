#include <Button.h>
#include <SFML/Graphics.hpp>

Button::Button(){
  this->pressed = false;
  button.loadFromFile("..\\resources\\Button.png");
  pressedButton.loadFromFile("..\\resources\\ButtonPressed.png");
}

void Button::draw(sf::RenderWindow &window){
  if(pressed == true){
    sf::Sprite b;
    b.setTexture(button);
    b.setPosition(pos);
    window.draw(b);
}
  else{
    sf::Sprite p;
    p.setTexture(pressedButton);
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

void Button::setToggleable(Interactables* interactable){
  this->interactable = interactable;
}

void Button::PlayerContact(PlayerChar &player,int id){
  if(player.interacted()==true){
  this->Toggle();
  interactable->Toggle();
}

}
