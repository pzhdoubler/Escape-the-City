#include <ResourceManager.h>

ResourceManager::ResourceManager(){
	//this->spriteSheet.loadFromFile("SPRITESHEET.PNG");
	this->texture.create(20, 20);
}

const sf::Texture& ResourceManager::getTexture(int tileID){
	this->tileID = tileID;
	//if statements checking the tile id and the corresponding location
	//on the sprite sheet (specified by rectX and rectY)
	/*if(tileID == 0){
		this->texture.update(spriteSheet, rectX, rectY);
	}*/
	return texture;
}