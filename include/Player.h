#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\System.hpp>
#include <SFML\Audio.hpp>
#include <iostream>
using namespace sf;
using namespace std;

//47
//47

class Player{
public:
    Player();
    void Update(Clock p_clock);
    void draw(RenderTarget& window);
private:
    Texture playerTexture;
    Sprite playerSp;  
    float frameTime = 0.2f;
    float elapsedTime = 0.0f;
    Clock clock;
    Clock clock2;
    float dt;
    IntRect frameRect = IntRect(0, 0, 47.5, 47);
};

Player::Player(){
    
    if (!playerTexture.loadFromFile("../Sprout Lands - Sprites - Basic pack/Characters/Basic Charakter Actions-export2.png")) {
       cout << "Cannot load: res/1 Woodcutter/Woodcutter_walk.png" << endl;
    }

    playerSp.setTexture(playerTexture);
    playerSp.setTextureRect(frameRect);
    playerSp.setScale(Vector2f(10,10));
}

void Player::Update(Clock p_clock){
    dt = clock2.restart().asSeconds();
    if(Keyboard::isKeyPressed(Keyboard::S)){
        clock = p_clock;
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
        playerSp.move(0,600*dt);
    }

    else{
        frameRect = IntRect(0,0,47,47);
        playerSp.setTextureRect(frameRect);
    }
}

void Player::draw(RenderTarget& window){
    window.draw(playerSp);
}