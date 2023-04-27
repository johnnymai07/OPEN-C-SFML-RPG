#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "GameState.h"
#include "Button.h"

// Declaring the MainMenuState class, which inherits from the State class.
class MainMenuState :
    public State
{
private:
    // Variables:

    // A RectangleShape object for the background of the main menu.
    sf::RectangleShape background;

    // A Font object to store the font used in the main menu.
    sf::Font font;

    // Functions:

    // A function to initialize the font used in the main menu.
    void initializeFonts();

    // A function to initialize keybinds used in the main menu state.
    void initializeKeybinds();

public:
    // Constructor for the MainMenuState class, taking a pointer to the window object and a pointer to the map of supported keys.
    MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);

    // Virtual destructor for the MainMenuState class.
    virtual ~MainMenuState();

    // Functions:

    // A function to end the MainMenuState.
    void endState();

    // A function to update input handling, taking delta time as a parameter.
    void updateInput(const float& dt);

    // A function to update the MainMenuState, taking delta time as a parameter.
    void update(const float& dt);

    // A function to render the MainMenuState, with an optional render target parameter.
    void render(sf::RenderTarget* target = NULL);

};
#endif

