#ifndef _RESOURCEMANAGER_H_
#define _RESOURCEMANAGER_H_

#include <SFML/Graphics.hpp>

class ResourceManager{
public:
	ResourceManager();

	const sf::Texture& getTexture(int tileID);

	const sf::Texture& getSpriteSheet();

	enum Sprites
	{
		BARRIER,
		JUMP_MAN,
		FAST_MAN,
		BUTTON_ON,
		BUTTON_OFF,
		DOOR,
		HAZARDS,
		HAZARDS_OFF,
		PLATFORM_ON,
		PLATFORM_OFF,
		JUMP_ITEM,
		SPEED_ITEM,
		EXIT
	};

	sf::Vector2i& getSpriteCoords(Sprites object);

private:
	sf::Texture spriteSheet;
	sf::Texture texture;

	int tileID; //used to reference which rectangle from the full sprite sheet to build the texture from

	sf::Vector2i spriteCoords;
	int rectX;
	int rectY;
};

#endif //_RESOURCEMANAGER_H_