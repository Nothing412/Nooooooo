#pragma once
#include<SFML\Graphics.hpp>
#include<iostream>
using namespace sf;
using namespace std;

#define vec2 Vector2f

class grid{
public:
    grid(int chunkX,int chunkY,int gridNum,int gridNumY);
    vec2 getPos();

private:
    vec2 windowSize;
    vec2 gridSize;
    
    int chunkX = 0;
    int chunkY = 0;
    int gridX = 0;
    int gridY = 0;
    bool hasX = NULL;
    bool hasY = NULL;
    bool hasGridX = NULL;
    bool hasGridY = NULL;
    vec2 pos;
    vec2 acpos;
};