#ifndef _RESOURCEMANAGER_H_
#define _RESOURCEMANAGER_H_

#include <SFML/Graphics.hpp>

class ResourceManager{
public:
	ResourceManager();

	const sf::Texture& getTexture(int tileID);

private:
	sf::Texture spriteSheet;
	sf::Texture texture;

	int tileID; //used to reference which rectangle from the full sprite sheet to build the texture from

	int rectX;
	int rectY;
};

#endif //_RESOURCEMANAGER_H_