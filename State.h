#ifndef STATE_H
#define STATE_H

#include "Entity.h"


class State
{
private:


// A pointer to the window object, which is used for rendering.
    sf::RenderWindow* window;

    // A pointer to a map that stores supported keys and their integer values.
    std::map<std::string, int>* supportedKeys;

    // A map that stores keybinds and their corresponding integer values.
    std::map<std::string, int> keybinds;

    // A boolean flag to indicate whether the state should quit.
    bool quit;

    // A vector storing the mouse position in screen coordinates.
    sf::Vector2i mousePosScreen;

    // A vector storing the mouse position in window coordinates.
    sf::Vector2i mousePosWindow;

    // A vector storing the mouse position in view coordinates.
    sf::Vector2f mousePosView;

    // A vector storing resources, specifically textures.
    std::vector<sf::Texture> textures;

    // A pure virtual function for initializing keybinds.
    virtual void initializeKeybinds() = 0;

public:
    // Constructor for the State class, taking a pointer to the window object and a pointer to the map of supported keys.
    State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);

    // Virtual destructor for the State class.
    virtual ~State();

    // A function to return the quit flag value.
    const bool& getQuit() const;

    // Pure virtual functions for managing the state:
    
    // A function to check for the quit condition.
    virtual void checkForQuit();

    // A function to end the state.
    virtual void endState() = 0;

    // A function to update the mouse positions.
    virtual void updateMousePosititons();

    // A function to update input handling, taking delta time as a parameter.
    virtual void updateInput(const float& dt) = 0;

    // A function to update the state, taking delta time as a parameter.
    virtual void update(const float& dt) = 0;

    // A function to render the state, with an optional render target parameter.
    virtual void render(sf::RenderTarget* target = NULL) = 0;


};
#endif
