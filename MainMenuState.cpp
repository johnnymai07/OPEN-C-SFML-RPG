#include "MainMenuState.h"

// Function to initialize the font used in the main menu.
void MainMenuState::initializeFonts()
{
    // Attempt to load the font from the specified file.
    if (this->font.loadFromFile("Fonts/KingsmanDemo.tttf"))
    {
        // If the font fails to load, throw an error and exit the program.
        throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
    }
}

// Function to initialize keybinds used in the main menu state.
void MainMenuState::initializeKeybinds()
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

// Constructor for the MainMenuState class.
MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys)
    : State(window, supportedKeys) // Initializing the State class with the given arguments.
{
    // Initialize the font and keybinds.
    this->initializeFonts();
    this->initializeKeybinds();

    // Set the size and color of the background.
    this->background.setSize(sf::Vector2f(window->getSize().x,window->getSize().y));
    this->background.setFillColor(sf::Color::Blue);
}

// Destructor for the MainMenuState class.
MainMenuState::~MainMenuState()
{
    
}

// Function to end the MainMenuState.
void MainMenuState::endState()
{
    std::cout << "Ending Game" << "\n";
}

// Function to update input handling, taking delta time as a parameter.
void MainMenuState::updateInput(const float& dt)
{
    // Check if the quit condition is met.
    this->checkForQuit();
}

// Function to update the MainMenuState, taking delta time as a parameter.
void MainMenuState::update(const float& dt)
{
    // Update the mouse positions.
    this->updateMousePosititons();

    // Update input handling.
    this->updateInput(dt);
}

// Function to render the MainMenuState, with an optional render target parameter.
void MainMenuState::render(sf::RenderTarget* target)
{
    // If the target is not specified, use the window object as the render target.
    if (!target)
    {
        target = this->window;
    }

    // Draw the background on the render target.
    target->draw(this->background);
}
