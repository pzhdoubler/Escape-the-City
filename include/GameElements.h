#ifndef GAMEELEMENTS_H_
#define GAMEELEMENTS_H_

#include <SFML/Graphics.hpp>

class GameElements {

public:
 //virtual draws to allow ScreenView to acess drawn methods
	virtual void draw(sf::RenderWindow& window) = 0;

	//virtual void Toggle() = 0;


};

#endif // !GAMEELEMENTS_H_
