#include <AppLayer.h>

bool AppLayer::display(sf::RenderWindow& mainWindow, int screen_pref)
{
	level_name = "level_prototype.txt";
	return true;
}


LevelState AppLayer::loadLevel()
{
	loader.loadMap(level_name);
	return loader.createLevelState();
}