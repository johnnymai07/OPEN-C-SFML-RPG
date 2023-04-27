#include "State.h"

// State class constructor, taking a pointer to the window object and a pointer to the map of supported keys.
State::State(sf::RenderWindow* window,std::map<std::string, int>* supportedKeys)
{
    // Assigning the window object to the class member.
    this-> window = window;

    // Assigning the map of supported keys to the class member.
    this-> supportedKeys = supportedKeys;

    // Initializing the quit flag to false.
    this-> quit = false;
}

// State class destructor.
State::~State()
{
    // No resources to release.
}

// Function to return the quit flag value.
const bool& State::getQuit() const
{
    return this->quit;
}

// Function to check for the quit condition.
void State::checkForQuit()
{
    // Checking if the "CLOSE" key is pressed.
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))))
    {
        // If the "CLOSE" key is pressed, set the quit flag to true.
        this->quit = true;
    }
}

// Function to update the mouse positions.
void State::updateMousePosititons()
{
    // Updating the mouse position in screen coordinates.
    this->mousePosScreen = sf::Mouse::getPosition();

    // Updating the mouse position in window coordinates.
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);

    // Updating the mouse position in view coordinates, converting from window coordinates.
    this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}
