#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\System.hpp>
#include <SFML\Audio.hpp>
#include <iostream>
#include "Player.h"
#include "Taskbar.h"
#include "Axe.h"
using namespace sf;
using namespace std;

int main() {
    RenderWindow window(sf::VideoMode(800, 800), "Cat Woodcutter", sf::Style::Fullscreen);
    window.setFramerateLimit(60);
    
    Player player;
    Taskbar taskbar;
    View view(player.getPositionForView(),Vector2f(window.getSize().x,window.getSize().y));
    AxeItem axe;
    Clock clock;
    
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }
        
        player.Update(clock);
        taskbar.Update();
        
        clock.restart();
        
        window.clear();
        
        window.setView(view);
        view.setCenter(Vector2f(player.getPositionForView().x,player.getPositionForView().y));
        
        axe.Draw(window);
        
        player.draw(window);
        
        window.setView(window.getDefaultView());
        
        taskbar.Draw(window);
        
        window.display();
    }
    
    return 0;
}