#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>
#include<SFML\System.hpp>
#include<iostream>
#include<Grid.h>
using namespace sf;
using namespace std;

int main(){
    RenderWindow window(VideoMode(1920,1080),"Test");
    grid test(2,2,0,0);
    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
            if(event.type == Event::Closed){
                window.close();
            }
        }   
        window.clear();
        cout << test.getPos().x << " , " << test.getPos().y <<  "\n";
        window.display();
    }
}