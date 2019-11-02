#include <SFML/Graphics.hpp>

#include <GameLogic.h>
#include <ScreenView.h>
#include <LevelState.h>
#include <LevelReader.h>
#include <AppLayer.h>
#include <Controller.h>

int main(int argc, char** argv) 
{
	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Escape the City - SFML", sf::Style::Close);

	//initialize app layer
	AppLayer appLayer;
	GameLogic logic;
	ScreenView screen;
	Controller controller;

	while (App.isOpen()) 
	{
        bool paused = false; //Controller will return true or false based on pausing pref

        while(!appLayer.isPlaying) {
            //essentially trying to do a while loop for appLayer.update
            sf::Event event;
            while (App.pollEvent(event))
            {
                if (event.type == sf::Event::Closed) {
                    paused = true;
                    App.close();
                }
            }

            appLayer.mainMenu(App);

        }

		LevelReader loader; //to be done inside app layer once fully implemented
		//current level options:
		//level_prototype.txt
		//level_0_tutorial.txt
		loader.loadMap("level_0_tutorial.txt");

		//recieve level and initialize Views
		LevelState level = loader.createLevelState();

        //decided to put appLayer above, before initalizing logic and screenview so it loads after the blue screen
        //is removed

		logic.init(level);

		screen.init(level);

		controller.init(logic);

		//initialize controller

		sf::Clock clock;




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

			controller.update(deltaMs);

			//update controller

			App.display();
		}
	}

	return 0;
}