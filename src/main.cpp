#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>
#include<SFML\System.hpp>
#include<iostream>
#include<Grid.h>
using namespace sf;
using namespace std;

int main(){
    RenderWindow window(VideoMode(1920,1080),"Test");
    RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(1920, 1080));
    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
            if(event.type == Event::Closed){
                window.close();
            }
        }   
        window.clear();
        window.draw(rectangle);
        window.display();
    }
}