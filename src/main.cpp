#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\System.hpp>
#include <SFML\Audio.hpp>
#include <iostream>
#include "Player.h"
using namespace sf;
using namespace std;

int main() {
    RenderWindow window(sf::VideoMode(800, 800), "SFML Animation", sf::Style::Fullscreen);
    window.setFramerateLimit(60);

    Player player;

    Clock clock;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        player.Update(clock);

        clock.restart();

        window.clear();
        player.draw(window);
        window.display();
    }

    return 0;
}