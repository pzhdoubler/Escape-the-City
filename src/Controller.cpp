#include <Controller.h>

#include <SFML/Graphics.hpp>

bool Controller::init(GameLogic &logic)
{

	this->logic = &logic;

	bindings[PAUSE] = 15; //P key

	//read in values from file, currently correspond to default keys in design doc

	bindings[FAST_LEFT] = 72;
	bindings[FAST_RIGHT] = 73;
	bindings[FAST_JUMP] = 74;
	bindings[FAST_DOWN] = 75;
	bindings[FAST_USE] = 42;

	bindings[JUMP_LEFT] = 0;
	bindings[JUMP_RIGHT] = 3;
	bindings[JUMP_JUMP] = 22;
	bindings[JUMP_DOWN] = 18;
	bindings[JUMP_USE] = 38;

	return true;

}


//check for case of same keys
bool Controller::editKey(Controls key, int new_binding)
{

	switch (key)
	{
		case PAUSE:
			bindings[PAUSE] = new_binding;
			return true;
		case FAST_LEFT:
			bindings[FAST_LEFT] = new_binding;
			return true;
		case FAST_RIGHT:
			bindings[FAST_RIGHT] = new_binding;
			return true;
		case FAST_JUMP:
			bindings[FAST_JUMP] = new_binding;
			return true;
		case FAST_DOWN:
			bindings[FAST_DOWN] = new_binding;
			return true;
		case FAST_USE:
			bindings[FAST_USE] = new_binding;
			return true;
		case JUMP_LEFT:
			bindings[JUMP_LEFT] = new_binding;
			return true;
		case JUMP_RIGHT:
			bindings[JUMP_RIGHT] = new_binding;
			return true;
		case JUMP_JUMP:
			bindings[JUMP_JUMP] = new_binding;
			return true;
		case JUMP_DOWN:
			bindings[JUMP_DOWN] = new_binding;
			return true;
		case JUMP_USE:
			bindings[JUMP_USE] = new_binding;
			return true;
		default:
			return false;
	}
}


bool Controller::update(float deltaMs)
{
	//check to pause game
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(bindings[PAUSE])))
		return true;

	for(int i = 1; i < CONTROLS_LEN; i++) 
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(bindings[i])))
			break;//key update logic method
	}

	return false;
}