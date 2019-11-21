#include <ResourceManager.h>

ResourceManager::ResourceManager(){
	this->spriteSheet.loadFromFile("..\\resources\\sprite_sheet");
	this->texture.create(20, 20);
}

const sf::Texture& ResourceManager::getTexture(int tileID){
	this->tileID = tileID;
	//if statements checking the tile id and the corresponding location
	//on the sprite sheet (specified by rectX and rectY)
	unsigned int rectX;
	unsigned int rectY;
	//Barrier tile
	/*if(tileID == 1){
		rectX = 0;
		rectY = 0;
		this->texture.update(spriteSheet, rectX, rectY);
	}
	//jump man
	else if(tileID == 2){
		rectX = 40;
		rectY = 20;
		this->texture.update(spriteSheet, rectX, rectY);
	}
	//fast man
	else if(tileID == 2){
		rectX = 60;
		rectY = 20;
		this->texture.update(spriteSheet, rectX, rectY);
	}
	//button on
	else if(tileID == 2){
		rectX = 80;
		rectY = 0;
		this->texture.update(spriteSheet, rectX, rectY);
	}
	//button off
	else if(tileID == 2){
		rectX = 100;
		rectY = 0;
		this->texture.update(spriteSheet, rectX, rectY);
	}
	//door
	else if(tileID == 2){
		rectX = 20;
		rectY = 20;
		this->texture.update(spriteSheet, rectX, rectY);
	}
	//hazard (spike)
	else if(tileID == 2){
		rectX = 0;
		rectY = 20;
		this->texture.update(spriteSheet, rectX, rectY);
	}*/
	return texture;
}