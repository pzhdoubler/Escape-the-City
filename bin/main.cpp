#include <SFML/Graphics.hpp>

#include <GameLogic.h>
#include <ScreenView.h>
#include <LevelState.h>
#include <LevelReader.h>
#include <ResourceManager.h>
#include <AppLayer.h>
#include <Controller.h>

int main(int argc, char** argv) 
{
	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Escape the City - SFML", sf::Style::Close);
	App.setFramerateLimit(120);

	//initialize app layer
	AppLayer appLayer;
	ResourceManager resourceManager;
	GameLogic logic(resourceManager);
	ScreenView screen;
	Controller controller;

	while (App.isOpen()) 
	{
        bool paused = false; //Controller will return true or false based on pausing pref
        //while you're not playing at the main menus
        while(!appLayer.isPlaying) {
            sf::Event event;
            while (App.pollEvent(event))
            {
                //if you close out of the window
                if (event.type == sf::Event::Closed) {
                    //break out of mainMenu loop
                    appLayer.isPlaying = true;
                    //set game loop condition to true so we don't go there
                    paused = true;
                    //close out of application
                    App.close();
                }
            }
            appLayer.mainMenu(App, paused, controller, logic);
        }

        //check and see if we exited mainMenu without starting game, if so, return
        if (paused) {
            return 0;
        }



        //initialization
		logic.init(appLayer.level);
		screen.init(appLayer.level, resourceManager);
		controller.init(logic);

		sf::Clock clock;

		//main game loop
		while (!paused) 
		{
		    //start clock
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

			//updates

			//if logic.update is true, then we need to return to the main menu
			if (logic.update(deltaMs)) {
			    appLayer.returnToMain = true;
			    if (appLayer.returnToMain) {
			        paused = true;
			        printf("should send to main\n");
			        appLayer.isPlaying = false;
			        appLayer.returnToMain = false;
			        break;
			    }
			}
			screen.update(App, logic);
			//controller update and check to see if game is paused
			if (controller.update(deltaMs)) {
			    printf("paused\n");
			    appLayer.pauseMenuOpen = true;
			    while (appLayer.pauseMenuOpen) {
                    sf::Event event;
                    while (App.pollEvent(event)) {
                        //if you close out of window
                        if (event.type == sf::Event::Closed) {
                            //breaks out of appLayer while loop
                            appLayer.pauseMenuOpen = false;
                            //breaks out of game loop
                            paused = true;
                            //close out of application
                            App.close();
                        }
                    }
                    appLayer.pauseMenu(App, paused);

			    }
			    //if we pressed the mainMenu button in pause Menu
                if (appLayer.returnToMain) {
                    printf("should send to main\n");
                    //initialize condition to restart the beginning mainMenu while loop
                    appLayer.isPlaying = false;
                    //if we restart the level, we need to turn returnToMain back off or else it restarts the game
                    //after every unpause
                    appLayer.returnToMain = false;
                    //break out of game loop but keep entire application loop running
                    break;
                }
			    clock.restart();
			}

			App.display();
		}
	}

	return 0;
}