/* date = May 28th 2023 2:29 */
//16x16
#pragma once 
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\System.hpp>
#include <SFML\Audio.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class AxeItem{
    public:
    AxeItem();
    void DrawOnHotbar(RenderWindow& window);
    void Draw(RenderWindow& window);
    void Update(FloatRect playerHitbox);
    
    private:
    Sprite axeSprite;
    Texture axeTexture;
    rect axeRect{16,32,16,16};
    vec2 position{0,0};
    bool can_draw = false;
};

/*
 Two Func draw hotbarBar;
draw
*/

//
AxeItem::AxeItem(){
    
    if(axeTexture.loadFromFile("../Sprout Lands - Sprites - Basic pack/Characters/Tools.png")){
        cout << "Failed to load: Sprout Lands - Sprites - Basic pack/Characters/Tools.png";
    }
    axeSprite.setTexture(axeTexture);
    axeSprite.setTextureRect(axeRect);
    axeSprite.setPosition(position);
    axeSprite.setScale(vec2(5,5));
}

void AxeItem::Draw(RenderWindow& window){
    window.draw(axeSprite);
}

void AxeItem::DrawOnHotbar(RenderWindow& window){
    if(can_draw){
        //setposition on hot bar
        window.draw(axeSprite);
    }
}