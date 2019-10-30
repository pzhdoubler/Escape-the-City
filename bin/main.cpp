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
        while(!appLayer.isPaused) {
            //essentially trying to do a while loop for appLayer.update

            appLayer.screenTransitionTest(App);
            //still freezes if clicked more than once, look up how to implement multiple screens
            //but at least the blocks seem to load without error
        }

		LevelReader loader; //to be done inside app layer once fully implemented
		loader.loadMap("level_prototype.txt");

		//recieve level and initialize Views
		LevelState level = loader.createLevelState();

        //decided to put appLayer above, before initalizing logic and screenview so it loads after the blue screen
        //is removed

		GameLogic logic;
		logic.init(level);

		ScreenView screen;
		screen.init(level);

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


			logic.update(deltaMs);

			screen.update(App, logic);

			//update controller

			App.display();
		}
	}

	return 0;
}