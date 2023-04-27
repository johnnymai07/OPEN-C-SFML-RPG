#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"

// Declaring the GameState class, which inherits from the State class.
class GameState :
    public State
{
private:
    // An Entity object representing the player.
    Entity player;

    // Functions:

    // A function to initialize keybinds used in the game state.
    void initializeKeybinds();

public:
    // Constructor for the GameState class, taking a pointer to the window object and a pointer to the map of supported keys.
    GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);

    // Virtual destructor for the GameState class.
    virtual ~GameState();

    // Functions:

    // A function to end the GameState.
    void endState();

    // A function to update input handling, taking delta time as a parameter.
    void updateInput(const float& dt);

    // A function to update the GameState, taking delta time as a parameter.
    void update(const float& dt);

    // A function to render the GameState, with an optional render target parameter.
    void render(sf::RenderTarget* target = NULL);

};
#endif


