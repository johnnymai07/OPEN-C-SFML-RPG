#include "GameState.h"

// Function to initialize keybinds used in the game state.
void GameState::initializeKeybinds()
{
    // Opening a file stream to read keybinds from a configuration file.
    std::ifstream ifs("Config/gamestate_keybinds.ini");

    // If the file is open and accessible.
    if (ifs.is_open())
    {
        std::string key = "";
        std::string key2 = "";

        // Read the keybinds from the file.
        while (ifs >> key >> key2)
        {
            // Store the keybinds in the class member map.
            this->keybinds[key] = this->supportedKeys->at(key2);
        }
    }

    // Close the file stream.
    ifs.close();
}

// Constructor for the GameState class.
GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys)
    : State(window, supportedKeys) // Initializing the State class with the given arguments.
{
    // Initialize the keybinds.
    this->initializeKeybinds();
}

// Destructor for the GameState class.
GameState::~GameState()
{
    
}

// Function to end the GameState.
void GameState::endState()
{
    std::cout << "Ending Game" << "\n";
}

// Function to update input handling, taking delta time as a parameter.
void GameState::updateInput(const float& dt)
{
    // Check if the quit condition is met.
    this->checkForQuit();

    // Update player input.
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
        this->player.move(dt, -1.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
        this->player.move(dt, 1.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))))
        this->player.move(dt, 0.f, -1.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
        this->player.move(dt, 0.f, 1.f);
}

// Function to update the GameState, taking delta time as a parameter.
void GameState::update(const float& dt)
{
    // Update the mouse positions.
    this->updateMousePosititons();

    // Update input handling.
    this->updateInput(dt);

    // Update the player entity.
    this->player.update(dt);
}

// Function to render the GameState, with an optional render target parameter.
void GameState::render(sf::RenderTarget* target)
{
    // If the target is not specified, use the window object as the render target.
    if (!target)
    {
        target = this->window;
    }

    // Render the player entity on the render target.
    this->player.render(target);
}

