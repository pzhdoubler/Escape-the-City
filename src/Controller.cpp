#include <Controller.h>

#include <SFML/Graphics.hpp>
#include <string>
#include <GameLogic.h>
#include "tinyxml2.h"

bool Controller::init(GameLogic &logic)
{

	this->logic = &logic;

	bindings[PAUSE] = sf::Keyboard::P; //P key

	//read in values from file, currently correspond to default keys in design doc
	tinyxml2::XMLDocument config;
	tinyxml2::XMLError result = config.LoadFile("..\\config\\controls.xml");
	if (result != tinyxml2::XML_SUCCESS)
		return false;

	tinyxml2::XMLElement* fast = config.FirstChildElement("fastman");
	tinyxml2::XMLElement* jump = config.FirstChildElement("jumpman");

	int cur_binding = 1;

	for (tinyxml2::XMLElement* key = fast->FirstChildElement(); key != NULL; key = key->NextSiblingElement()) {
		std::string binding = key->GetText();
		bindings[cur_binding] = std::stoi(binding);
		cur_binding++;
	}

	for (tinyxml2::XMLElement* key = jump->FirstChildElement(); key != NULL; key = key->NextSiblingElement()) {
		std::string binding = key->GetText();
		bindings[cur_binding] = std::stoi(binding);
		cur_binding++;
	}

	//Default Bindings:
	//bindings[FAST_LEFT] = sf::Keyboard::Left;
	//bindings[FAST_RIGHT] = sf::Keyboard::Right;
	//bindings[FAST_JUMP] = sf::Keyboard::Up;
	//bindings[FAST_DOWN] = sf::Keyboard::Down;
	//bindings[FAST_USE] = sf::Keyboard::RShift;
	//bindings[FAST_RESPAWN] = sf::Keyboard::Comma;

	//bindings[JUMP_LEFT] = sf::Keyboard::A;
	//bindings[JUMP_RIGHT] = sf::Keyboard::D;
	//bindings[JUMP_JUMP] = sf::Keyboard::W;
	//bindings[JUMP_DOWN] = sf::Keyboard::S;
	//bindings[JUMP_USE] = sf::Keyboards::LShift;
	//bindings[JUMP_RESPAWN] = sf::Keyboard::R;

	for (int i = 0; i < CONTROLS_LEN; i++) {
		key_pressed[i] = false;
	}

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
			//button release
			if (success && !key_pressed[i]) {
				key_pressed[i] = true;
			}
		}
		//button release
		if (key_pressed[i] && !pressed) {
			key_pressed[i] = false;
			logic->buttonPress(Controls(i+CONTROLS_LEN+1), deltaMs);
		}
	}

	return false;
}
