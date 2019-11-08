#include <Controller.h>

#include <SFML/Graphics.hpp>
#include <GameLogic.h>

bool Controller::init(GameLogic &logic)
{

	this->logic = &logic;

	bindings[PAUSE] = sf::Keyboard::P; //P key

	//read in values from file, currently correspond to default keys in design doc

	bindings[FAST_LEFT] = sf::Keyboard::Left;
	bindings[FAST_RIGHT] = sf::Keyboard::Right;
	bindings[FAST_JUMP] = sf::Keyboard::Up;
	bindings[FAST_DOWN] = sf::Keyboard::Down;
	bindings[FAST_USE] = sf::Keyboard::RShift;
	bindings[FAST_RESPAWN] = sf::Keyboard::Comma;

	bindings[JUMP_LEFT] = sf::Keyboard::A;
	bindings[JUMP_RIGHT] = sf::Keyboard::D;
	bindings[JUMP_JUMP] = sf::Keyboard::W;
	bindings[JUMP_DOWN] = sf::Keyboard::S;
	bindings[JUMP_USE] = sf::Keyboard::LShift;
	bindings[JUMP_RESPAWN] = sf::Keyboard::R;

	fast_jumped = false;
	jump_jumped = false;

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
		case FAST_RESPAWN:
			bindings[FAST_RESPAWN] = new_binding;
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
		case JUMP_RESPAWN:
			bindings[JUMP_RESPAWN] = new_binding;
			return true;

		default:
			return false;
	}
}


bool Controller::update(float deltaMs)
{
	//check to pause game
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(bindings[PAUSE]))) {
		return true;
	}


	for(int i = 1; i < CONTROLS_LEN; i++)
	{
		bool pressed = false;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(bindings[i]))) {
			pressed = true;
			bool success = logic->buttonPress(Controls(i), deltaMs);
			if (i == FAST_JUMP && success && !fast_jumped) {
				fast_jumped = true;
			}
			if (i == JUMP_JUMP && success && !jump_jumped) {
				jump_jumped = true;
			}
		}
		if (i == FAST_JUMP && fast_jumped && !pressed) {
			fast_jumped = false;
			logic->buttonPress(FAST_JUMP_RELEASE, deltaMs);
		}
		if (i == JUMP_JUMP && jump_jumped && !pressed) {
			jump_jumped = false;
			logic->buttonPress(JUMP_JUMP_RELEASE, deltaMs);
		}
	}

	return false;
}
