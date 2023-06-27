#pragma once
#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>
#include<SFML\System.hpp>
#include<iostream>
using namespace sf;
using namespace std;

#define vec2 Vector2f

class grid{
public:
    grid(int chunkX,int chunkY,int gridNum);
    vec2 getPos();

private:
    vec2 windowSize;
    bool hasY = NULL;
    int chunkX = 0;
    int chunkY = 0;
    vec2 pos;
};