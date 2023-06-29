#include<Grid.h>

grid::grid(int chunkX,int chunkY,int gridNumX,int gridNumY){
    windowSize = vec2(1920,1080);
    gridSize = vec2(15,8.4375);

    if(chunkY == 0){
        hasY = false;
    }

    if(hasY = false){
        pos.y = 0;
    }

    else{
        pos.y = chunkY * windowSize.y;
    }

    if(chunkX == 0){
        hasX = false;
    }

    if(hasX = false){
        pos.x = 0;
    }

    else{
        pos.x = chunkX * windowSize.x;
    }

    //other
    if(gridNumX == 0){
        hasX = false;
    }

    if(hasGridX = false){
        acpos.x = 0;
    }

    else{
        acpos.x = gridNumX * windowSize.x;
    }    
    
}

vec2 grid::getPos(){
    return acpos;
}