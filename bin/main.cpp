#include <SFML/Graphics.hpp>

#include <GameLogic.h>
#include <ScreenView.h>
#include <LevelState.h>
#include <LevelReader.h>
#include <AppLayer.h>

int main(int argc, char** argv) 
{
	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Escape the City - SFML", sf::Style::Close);

	//initialize app layer
	AppLayer appLayer;

	while (App.isOpen()) 
	{

	    //all this should now work within appLayer
//		LevelReader loader; //to be done inside app layer once fully implemented
//		loader.loadMap("level_prototype.txt");
//
//		//recieve level and initialize Views
//		LevelState level = loader.createLevelState();
//
//		GameLogic logic;
//		logic.init(level);
//
//		ScreenView screen;
//		screen.init(level);

		//initialize controller

		sf::Clock clock;
		bool paused = false; //Controller will return true or false based on pausing pref

		//main game loop
		while (!paused) 
		{
			float deltaMs = clock.getElapsedTime().asSeconds();
			clock.restart();

			sf::Event event;
			while (App.pollEvent(event))
			{
				if (event.type == sf::Event::Closed) {
					paused = true;
					App.close();
				}
			}

			//this is to test if on a spaceBar press, the AppLayer will remove a blue filled screen
			appLayer.screenTransitionTest(App);
            //with this in place, we dont start updating logic or screenview until we press the spacebar but the only
            //reason for that is is because we don't let anything else update due to the while loop we get stuck in

			appLayer.logic.update(deltaMs);

			appLayer.screen.update(App, appLayer.logic);

			appLayer.controller.update(deltaMs);

			//update controller

			App.display();
		}
	}

	return 0;
}