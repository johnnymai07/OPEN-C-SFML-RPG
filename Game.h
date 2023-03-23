#ifndef GAME_H
#define GAME_H

#include "MainMenuState.h"

class Game
{
private:
	//Variables
	sf::RenderWindow *window;
	sf::Event sfEvent;

	//Delta Time keeps track how the long does it take for the game to do one Update call and one Render Call.
	sf::Clock dtClock;
	float dt;

	std::stack<State*> states; //pop and push method 

	std::map<std::string, int> supportedKeys;

	//Initializers
	void initializeWindow();
	void initializeKeys();
	void initializeStates();
	

public:
	//Constructors
	Game();
	virtual ~Game(); //Deconstructor

	//Functions

	//Regular Functions

	void endApplication();

	//Update
	void updateDt();
	void updateSFMLEvents();
	void update();

	//Render
	void render();

	//Core
	void run();

};
#endif // !GAME_H;
