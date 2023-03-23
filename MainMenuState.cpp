#include "MainMenuState.h"

void MainMenuState::initializeFonts()
{
	if (this->font.loadFromFile("Fonts/KingsmanDemo.tttf"))
	{
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT"); //Exit the program and prints the text
	}
}

void MainMenuState::initializeKeybinds()
{

	std::ifstream ifs("Config/gamestate_keybinds.ini");

	if (ifs.is_open())
	{
		std::string key = "";
		std::string key2 = "";

		while (ifs >> key >> key2)
		{
			this->keybinds[key] = this->supportedKeys->at(key2);
		}
	}

	ifs.close();

}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys)
	: State(window, supportedKeys)
{
	this->initializeFonts();
	this->initializeKeybinds();

	this->background.setSize(sf::Vector2f(window->getSize().x,window->getSize().y));
	this->background.setFillColor(sf::Color::Blue);
}

MainMenuState::~MainMenuState()
{

}

void MainMenuState::endState()
{
	std::cout << "Ending Game" << "\n";
}

void MainMenuState::updateInput(const float& dt)
{
	this->checkForQuit();

}

void MainMenuState::update(const float& dt)
{
	this->updateMousePosititons();
	this->updateInput(dt);

}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)

		target = this->window;
	
	target->draw(this->background);
}

