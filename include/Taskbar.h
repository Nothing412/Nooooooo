/* date = May 26th 2023 0:00 */
#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\System.hpp>
#include <SFML\Audio.hpp>
#include <iostream>
using namespace sf;
using namespace std;
#define vec2 Vector2f
#define rect IntRect
//128
//16


class Taskbar{
    public:
    Taskbar();
    void Draw(RenderTarget& window);
    void Update();
    
    private:
    Sprite taskbar;
    Texture taskbarTexture;
    rect taskbarRect{0,0,128,16};
};


Taskbar::Taskbar(){
    if(!taskbarTexture.loadFromFile("../Sprout Lands - Sprites - Basic pack/Objects/ItemsBar.png")){
        cout << "Failed to load: Sprout Lands - Sprites - Basic pack/Objects/ItemsBar.png";
    }
    taskbar.setTexture(taskbarTexture);
    taskbar.setScale(vec2(7,7));
    taskbar.setTextureRect(taskbarRect);
}

void Taskbar::Draw(RenderTarget& window){
    taskbar.setPosition(vec2(550,900));
    window.draw(taskbar);
}


void Taskbar::Update(){
    taskbar.setTextureRect(taskbarRect);
    
    if(Keyboard::isKeyPressed(Keyboard::Num1)){
        taskbarRect.left = 0;
    }
    
    if(Keyboard::isKeyPressed(Keyboard::Num2)){
        taskbarRect.left = 128;
    }
    
    if(Keyboard::isKeyPressed(Keyboard::Num3)){
        taskbarRect.left = 256;
    }
    
    if(Keyboard::isKeyPressed(Keyboard::Num4)){
        taskbarRect.left = 384;
    }
    
    if(Keyboard::isKeyPressed(Keyboard::Num5)){
        taskbarRect.left = 512;
    }
    
    if(Keyboard::isKeyPressed(Keyboard::Num6)){
        taskbarRect.left = 640;
    }
    
    if(Keyboard::isKeyPressed(Keyboard::Num7)){
        taskbarRect.left = 768;
    }
    
    if(Keyboard::isKeyPressed(Keyboard::Num8)){
        taskbarRect.left = 896;
    }
    
}