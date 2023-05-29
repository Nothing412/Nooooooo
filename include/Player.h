#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\System.hpp>
#include <SFML\Audio.hpp>
#include <iostream>
using namespace sf;
using namespace std;


class Player{
    public:
    Player();
    void Update(Clock p_clock);
    void draw(RenderTarget& window);
    FloatRect hitbox = playerSp.getGlobalBounds();
    Vector2f getPositionForView();
    
    private:
    Texture playerTexture;
    Sprite playerSp;  
    float frameTime = 0.2f;
    float elapsedTime = 0.0f;
    Clock clock;
    Clock clock2;
    float dt;
    IntRect frameRect = IntRect(0, 0, 47.5, 47);
    Texture playerTextureTools;
    bool down = false,up = false;
    
};

Player::Player(){
    if(!playerTexture.loadFromFile("../Sprout Lands - Sprites - Basic pack/Characters/Basic Charakter Actions-export2.png")){
        cout << "Could Not load: Sprout Lands - Sprites - Basic pack/Characters/Basic Charakter Actions-export2.png\n";
    }
    
    if(!playerTextureTools.loadFromFile("../Sprout Lands - Sprites - Basic pack/Characters/Basic Charakter Actions.png")){
        cout << "Could Not load: Basic Charakter Actions.png\n";
    }
    
    playerSp.setTexture(playerTexture);
    playerSp.setScale(Vector2f(10,10));
    playerSp.setTextureRect(frameRect);
}

void Player::Update(Clock p_clock){
    dt = clock2.restart().asSeconds();
    
    if(Keyboard::isKeyPressed(Keyboard::W)){
        frameRect.top = 47;
        clock = p_clock;
        up = true;
        elapsedTime += clock.getElapsedTime().asSeconds();
        if (elapsedTime >= frameTime) {
            // Move to the next frame
            frameRect.left += frameRect.width;
            if (frameRect.left >= playerTexture.getSize().x - frameRect.width) {
                frameRect.left = 0;
            }
            playerSp.setTextureRect(frameRect);
            elapsedTime = 0.0f;
        }
        
        
        playerSp.move(0,-600*dt);
    } 
    
    else if(Keyboard::isKeyPressed(Keyboard::S)){
        clock = p_clock;
        elapsedTime += clock.getElapsedTime().asSeconds();
        down= true;
        if (elapsedTime >= frameTime) {
            // Move to the next frame
            frameRect.left += frameRect.width;
            if (frameRect.left >= playerTexture.getSize().x - frameRect.width) {
                frameRect.left = 0;
            }
            
            playerSp.setTextureRect(frameRect);
            elapsedTime = 0.0f;
        }
        playerSp.move(0,600*dt);
    }
    
    else if(Keyboard::isKeyPressed(Keyboard::A)){
        frameRect.top = 95;
        clock = p_clock;
        elapsedTime += clock.getElapsedTime().asSeconds();
        if(elapsedTime>=frameTime){
            frameRect.left += frameRect.width;
            if(frameRect.left >= playerTexture.getSize().x - frameRect.width){
                frameRect.left = 0;
            }
            
            playerSp.setTextureRect(frameRect);
            elapsedTime = 0.0f;
        }
        playerSp.move(-600*dt,0);
    }
    
    else if(Keyboard::isKeyPressed(Keyboard::D)){
        frameRect.top = 144;
        clock = p_clock;
        elapsedTime += clock.getElapsedTime().asSeconds();
        if(elapsedTime>=frameTime){
            
            frameRect.left += frameRect.width;
            
            if(frameRect.left >= playerTexture.getSize().x - frameRect.width){
                frameRect.left = 0;
            }
            playerSp.setTextureRect(frameRect);
            elapsedTime = 0.0f;
            
        }
        playerSp.move(600*dt,0);
    }
    
    //axes
    
    else if(Mouse::isButtonPressed(Mouse::Left)){
        playerSp.setTexture(playerTextureTools);
        frameRect.top = 205;
        playerSp.setTextureRect(frameRect);
    }
    
    else if(Mouse::isButtonPressed(Mouse::Right)){
        playerSp.setTexture(playerTextureTools);
        frameRect.top = 7;
        playerSp.setTextureRect(frameRect);
    }
    
    else{
        frameRect = IntRect(0,0,47,47);
        playerSp.setTextureRect(frameRect);
        playerSp.setTexture(playerTexture);
    }
}

void Player::draw(RenderTarget& window){
    window.draw(playerSp);
}

Vector2f Player::getPositionForView(){
    return Vector2f(playerSp.getPosition().x+playerSp.getScale().x,playerSp.getPosition().y+playerSp.getScale().y);
}