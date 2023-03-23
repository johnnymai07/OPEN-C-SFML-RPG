#include "Game.h"

//Static Functions -------------------------------------------------------------------------------------------

//Initializer Functions --------------------------------------------------------------------------------------

void Game::initializeWindow()
{
    //Create a sf window using options from window.ini.file

    std::ifstream ifs("Config/Window.ini");

    std::string title = "None";
    sf::VideoMode window_bounds(800, 600);
    unsigned framerate_limit = 120;
    bool vertical_sync_enabled = false;


    if (ifs.is_open())
    {
        std::getline(ifs, title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> framerate_limit;
        ifs >> vertical_sync_enabled;
    }   

    ifs.close();

	this->window = new sf::RenderWindow(window_bounds, title);
    this->window->setFramerateLimit(framerate_limit);
    this->window->setVerticalSyncEnabled(vertical_sync_enabled);
}

void Game::initializeKeys()

{

    std::ifstream ifs("Config/supported_keys.ini");

    if (ifs.is_open())
    {
        std::string key = "";
        int key_value = 0;

        while (ifs >> key >> key_value)
        {
            this->supportedKeys[key] = key_value;
        }
    }

    ifs.close();

    for (auto i : this->supportedKeys)
    {
        std::cout << i.first << " " << i.second << "\n";
    }
}
    


void Game::initializeStates()
{
    this->states.push(new MainMenuState(this->window, &this->supportedKeys));
    this->states.push(new GameState(this->window, &this->supportedKeys));
}

//Constructors & Deconstructors ------------------------------------------------------------------------------------
Game::Game()
{

    this->initializeWindow();
    this->initializeKeys();
    this->initializeStates();

}

Game::~Game()
{
	delete this->window;

    while (!this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    }
}


//Functions --------------------------------------------------------------------------------------------------
void Game::updateDt()
{
    //Update the dT value with the time it takes to update and render one frame.
    this->dt = this->dtClock.restart().asSeconds();

    system("cls");
    std::cout << this->dt << "\n";
}


void Game::updateSFMLEvents()
{
    while (this->window->pollEvent(this->sfEvent))
    {
        if (this->sfEvent.type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::endApplication()
{
    std::cout << "Ending Application" << "\n";
}

void Game::update()
{
    this->updateSFMLEvents();

    if (!this->states.empty())
    {
        this->states.top()->update(this->dt);

        if (this->states.top()->getQuit())
        {
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }
    //Application end
    else
    {
        this->endApplication();
        this->window->close();
    }
}

void Game::render()
{
    this->window->clear();

    //Render and Display items
    if (!this->states.empty())
        this->states.top()->render(this->window);

    this->window->display();
}

void Game::run()
{
    while (this->window->isOpen())
    {
        //Reset the clock,update,render,save the dT.
        this->updateDt();
        this->update();
        this->render();
    }
}

