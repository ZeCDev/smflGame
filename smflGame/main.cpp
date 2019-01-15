
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "ResourcePath.hpp"
#include "Player.hpp"
#include "Menu.hpp"

#define WINDOW_NAME "smflGame"

int main(int, char const**)
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1024, 768), WINDOW_NAME);

    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // Load a music to play
    sf::Music music;
    if (!music.openFromFile(resourcePath() + "nice_music.ogg")) {
        return EXIT_FAILURE;
    }

    // Play the music
    music.play();

    SMFLGame::Player p1;
    //Create the menu
    SMFLGame::Menu menu(&window, &p1);
    
    // Start the game loop
    while (window.isOpen())
    {
        menu.getPlayer();
        menu.run();
    }

    return EXIT_SUCCESS;
}
