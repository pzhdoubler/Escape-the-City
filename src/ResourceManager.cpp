#include <ResourceManager.h>

ResourceManager::ResourceManager(){
	this->spriteSheet.loadFromFile("..\\resources\\sprite_sheet.png");
	//this->texture.create(20, 20);
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

const sf::Texture& ResourceManager::getSpriteSheet()
{
	return spriteSheet;
}


sf::Vector2i& ResourceManager::getSpriteCoords(Sprites object)
{
	switch (object) {
		case BARRIER:
			spriteCoords.x = 0;
			spriteCoords.y = 0;
			break;
		case JUMP_MAN:
			spriteCoords.x = 100;
			spriteCoords.y = 100;
			break;
		case FAST_MAN:
			spriteCoords.x = 80;
			spriteCoords.y = 100;
			break;
		case BUTTON_ON:
			spriteCoords.x = 100;
			spriteCoords.y = 0;
			break;
		case BUTTON_OFF:
			spriteCoords.x = 80;
			spriteCoords.y = 0;
			break;
		case DOOR:
			spriteCoords.x = 20;
			spriteCoords.y = 20;
			break;
		case HAZARDS:
			spriteCoords.x = 0;
			spriteCoords.y = 20;
			break;
		case PLATFORM_ON:
			spriteCoords.x = 0;
			spriteCoords.y = 60;
			break;
		case PLATFORM_OFF:
			spriteCoords.x = 0;
			spriteCoords.y = 40;
			break;
		case JUMP_ITEM:
			spriteCoords.x = 40;
			spriteCoords.y = 20;
			break;
		case SPEED_ITEM:
			spriteCoords.x = 60;
			spriteCoords.y = 20;
			break;
		case EXIT:
			spriteCoords.x = 80;
			spriteCoords.y = 20;
			break;
		default:
			spriteCoords.x = 0;
			spriteCoords.y = 0;
			break;
	}

	return spriteCoords;
}