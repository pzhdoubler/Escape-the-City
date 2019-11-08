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
                    appLayer.isPlaying = true;
                    paused = true;
                    App.close();
                }
            }

            appLayer.mainMenu(App, paused);
        }


        if (paused) {
            return 0;
        }

		logic.init(appLayer.level);

        //gets here and then dies
		screen.init(appLayer.level);

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

			//with all this, if you pause in the air, sometimes the character won't get redrawn so look into that
			//it actually only makes the character not get redrawn if you pause the screen while the character is
			//falling. If you pause as your character starts jumping, it works alright
			//because of the while loop it pauses screen updates and you can see this when you pause as the character
			//starts a jump. It will start to fall when you unpause
			if (controller.update(deltaMs)) {
			    printf("paused\n");
			    appLayer.pauseMenuOpen = true;
			    while (appLayer.pauseMenuOpen) {
                    sf::Event event;
                    while (App.pollEvent(event)) {
                        if (event.type == sf::Event::Closed) {
                            appLayer.pauseMenuOpen = false;
                            //isPlaying = true;
                            paused = true;
                            App.close();
                        }
                    }
                    appLayer.pauseMenu(App);
			    }
			    clock.restart();
			}

			//work on getting it to read one time
            while (App.pollEvent(event)) {
                if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Enter) {
                        printf("enter pressed");
                    }
                }
            }


			//update controller

			App.display();
		}
	}

	return 0;
}