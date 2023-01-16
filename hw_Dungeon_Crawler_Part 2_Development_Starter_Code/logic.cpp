#include <iostream>
#include <fstream>
#include <string>
#include "logic.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::string;

/**
 * TODO: Student implement this function
 * Load representation of the dungeon level from file into the 2D map.
 * Calls createMap to allocate the 2D array.
 * @param   fileName    File name of dungeon level.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object by reference to set starting position.
 * @return  pointer to 2D dynamic array representation of dungeon map with player's location., or nullptr if loading fails for any reason
 * @updates  maxRow, maxCol, player
 */
char** loadLevel(const string& fileName, int& maxRow, int& maxCol, Player& player) {

    ifstream file;
    file.open(fileName);
    if (!file.is_open()){
        return nullptr;
    }

    file>>maxRow;
    if (file.fail()){
        return nullptr;
    }
    if (maxRow<=0){
        return nullptr;
    }

    file>>maxCol;
    if (file.fail()){
        return nullptr;
    }
    if (maxCol<=0){
        return nullptr;
    }

    file>>player.row;
    if (file.fail()){
        return nullptr;
    }
    if (player.row<0){
        return nullptr;
    }
    
    file>>player.col;
    if (file.fail()){
        return nullptr;
    }
    if(player.col<0){
        return nullptr;
    }

    if(maxCol>INT32_MAX/maxRow){
      return nullptr;
    }
    if (player.row>=maxRow){
        return nullptr;
    }
    if (player.col>=maxCol){
        return nullptr;
    }
   
   char** gamemap=createMap(maxRow,maxCol);
   bool exit=false;
   string line;
   getline(file, line);
    for (int i=0;i<maxRow;++i){
        getline(file, line);

        if (file.fail()){
        return nullptr;
        }
        int index = 0;
        unsigned int num=(maxCol*2)-1;
        if (num!=line.size()){
            return nullptr;
        }
        for(int j=0;j<maxCol;++j){
        gamemap[i][j] = line.at(index);
        
        if (file.fail()){
        return nullptr;
        } 
        if (gamemap[i][j]!= '-' && gamemap[i][j]!='o' && gamemap[i][j]!='$' && gamemap[i][j]!='@' && gamemap[i][j]!='M' && gamemap[i][j]!='+' && gamemap[i][j]!='?' && gamemap[i][j]!='!'){
            return nullptr;
        }
        if (gamemap[i][j]=='?' || gamemap[i][j]=='!'){
            exit=true;
        }
        index+=2;
        }
    }
    getline(file,line);

    if (!file.fail()){
        return nullptr;
    }
    file.close();
    gamemap[player.row][player.col] = TILE_PLAYER;

    if (exit==false){
        return nullptr;
    }
    return gamemap;
    
}

/**
 * TODO: Student implement this function
 * Translate the character direction input by the user into row or column change.
 * That is, updates the nextRow or nextCol according to the player's movement direction.
 * @param   input       Character input by the user which translates to a direction.
 * @param   nextRow     Player's next row on the dungeon map (up/down).
 * @param   nextCol     Player's next column on dungeon map (left/right).
 * @updates  nextRow, nextCol
 */
void getDirection(char input, int& nextRow, int& nextCol) {
    if (input==MOVE_UP){
        nextRow-=1;
    }
    else if (input==MOVE_DOWN){
        nextRow+=1;
    }
    else if (input==MOVE_RIGHT){
        nextCol+=1;
    }   
    else if (input==MOVE_LEFT){
        nextCol-=1;
    }

}

/**
 * TODO: [suggested] Student implement this function
 * Allocate the 2D map array.
 * Initialize each cell to TILE_OPEN.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @return  2D map array for the dungeon level, holds char type.
 */
char** createMap(int maxRow, int maxCol) {
    
    char** createMap=new char* [maxRow];

    for(int i=0;i<maxRow;++i){
       createMap[i]=new char [maxCol];
    }

    for (int i=0;i<maxRow;++i){
        for(int j=0;j<maxCol;++j){
               createMap[i][j]=TILE_OPEN; 
        }
    }

    return createMap;
}

/**
 * TODO: Student implement this function
 * Deallocates the 2D map array.
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @return None
 * @update map, maxRow
 */
void deleteMap(char**& map, int& maxRow) {
    
    if (map) {
        for (int i = 0; i < maxRow; ++i) {
            delete[] map[i];  
        }
        delete[] map;
    }
    else{
        delete[] map;
    }
    map=nullptr;
    maxRow=0;
}
    

/**
 * TODO: Student implement this function
 * Resize the 2D map by doubling both dimensions.
 * Copy the current map contents to the right, diagonal down, and below.
 * Do not duplicate the player, and remember to avoid memory leaks!
 * You can use the STATUS constants defined in logic.h to help!
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height), to be doubled.
 * @param   maxCol      Number of columns in the dungeon table (aka width), to be doubled.
 * @return  pointer to a dynamically-allocated 2D array (map) that has twice as many columns and rows in size.
 * @update maxRow, maxCol
 */
char** resizeMap(char** map, int& maxRow, int& maxCol) {

    if (maxRow<1 || maxCol<1){
        return nullptr;
    }
    
    if (map==nullptr){
        return nullptr;
    }

    int newRow=0;
    int newCol=0;
    int col=0;
    int row=0;
    newRow=maxRow*2;
    newCol=maxCol*2;

    char** newcreateMap = createMap(newRow,newCol);
        /////////////////////////////////////A
    for (int i=0;i<maxRow;++i){
            for(int j=0;j<maxCol;++j){
               newcreateMap[i][j]=map[i][j]; 

            }
        }
        /////////////////////////////////////B
    for (int i=0;i<maxRow;++i){
            col=0;
            for(int j=maxCol;j<newCol;++j){
               newcreateMap[i][j]=map[i][col]; 
               if (TILE_PLAYER==newcreateMap[i][j]){
                newcreateMap[i][j]=TILE_OPEN;
               }
               ++col;
            }
        }
        /////////////////////////////////////C
    for (int i=maxRow;i<newRow;++i){
            for(int j=0;j<maxCol;++j){
               newcreateMap[i][j]=map[row][j];  
               if (TILE_PLAYER==newcreateMap[i][j]){
                newcreateMap[i][j]=TILE_OPEN;
               } 
            }
            ++row;
        }
        /////////////////////////////////////D
    row=0;
    for (int i=maxRow;i<newRow;++i){
            col=0;
            for(int j=maxCol;j<newCol;++j){
               newcreateMap[i][j]=map[row][col];
               if (TILE_PLAYER==newcreateMap[i][j]){
                newcreateMap[i][j]=TILE_OPEN;
               }
            ++col; 
            }
        ++row;
        }
    
        deleteMap(map,maxRow);
        maxRow=newRow;
        maxCol=newCol;
    return newcreateMap;

}
/**
 * TODO: Student implement this function
 * Checks if the player can move in the specified direction and performs the move if so.
 * Cannot move out of bounds or onto TILE_PILLAR or TILE_MONSTER.
 * Cannot move onto TILE_EXIT without at least one treasure. 
 * If TILE_TREASURE, increment treasure by 1.
 * Remember to update the map tile that the player moves onto and return the appropriate status.
 * You can use the STATUS constants defined in logic.h to help!
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object to by reference to see current location.
 * @param   nextRow     Player's next row on the dungeon map (up/down).
 * @param   nextCol     Player's next column on dungeon map (left/right).
 * @return  Player's movement status after updating player's position.
 * @update map contents, player
 */
int doPlayerMove(char** map, int maxRow, int maxCol, Player& player, int nextRow, int nextCol) {
    //////Player row greater than both
    if(player.row>=maxRow || player.col>=maxCol){
        nextRow=player.row;
        nextCol=player.col;

        return STATUS_STAY; 
    }
    //////column and row at 0
    if (player.row==0 && nextRow<0){
        nextRow=player.row;
        nextCol=player.col;

        return STATUS_STAY;     
    }

    if (player.col==0 && nextCol<0){
        nextRow=player.row;
        nextCol=player.col;

        return STATUS_STAY; 
    }
    
    
    //////Bounds
    if (nextRow>=maxRow || nextCol>=maxCol || map[nextRow][nextCol]==TILE_PILLAR || map[nextRow][nextCol]==TILE_MONSTER || (map[nextRow][nextCol]==TILE_EXIT && player.treasure==0)) {
        nextRow=player.row;
        nextCol=player.col;

        return STATUS_STAY;
    }
    ////Open Space
    if(map[nextRow][nextCol]==TILE_OPEN){
       map[player.row][player.col]=TILE_OPEN; 
       player.row=nextRow;
       player.col=nextCol;
       map[nextRow][nextCol]=TILE_PLAYER;
       return STATUS_MOVE;
    }
    //////Treasure
    if(map[nextRow][nextCol]==TILE_TREASURE){
        map[player.row][player.col]=TILE_OPEN;
        player.row=nextRow;
        player.col=nextCol;
        player.treasure +=1;
        map[nextRow][nextCol]=TILE_PLAYER;
        return STATUS_TREASURE;

    }
    //////Amulet
    if(map[nextRow][nextCol]==TILE_AMULET){
        map[player.row][player.col]=TILE_OPEN;
        player.row=nextRow;
        player.col=nextCol;
        map[nextRow][nextCol]=TILE_PLAYER;
        return STATUS_AMULET;     
    }
    //////Door
    if(map[nextRow][nextCol]==TILE_DOOR){
        map[player.row][player.col]=TILE_OPEN;
        player.row=nextRow;
        player.col=nextCol;
        map[nextRow][nextCol]=TILE_PLAYER;
        return STATUS_LEAVE;

    }
    //////Exit
    if(map[nextRow][nextCol]==TILE_EXIT && player.treasure>=1){
        map[player.row][player.col]=TILE_OPEN;
        player.row=nextRow;
        player.col=nextCol;
        map[nextRow][nextCol]=TILE_PLAYER;
        return STATUS_ESCAPE;
    }

    return 0;
}

/**
 * TODO: Student implement this function
 * Update monster locations:
 * We check up, down, left, right from the current player position.
 * If we see an obstacle, there is no line of sight in that direction, and the monster does not move.
 * If we see a monster before an obstacle, the monster moves one tile toward the player.
 * We should update the map as the monster moves.
 * At the end, we check if a monster has moved onto the player's tile.
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object by reference for current location.
 * @return  Boolean value indicating player status: true if monster reaches the player, false if not.
 * @update map contents
 */
bool doMonsterAttack(char** map, int maxRow, int maxCol, const Player& player) {
    
    ////Going Up
    for(int i=player.row-1;i>=0;--i){
        
        if (map[i][player.col]==TILE_MONSTER){
            map[i][player.col]=TILE_OPEN;
            map[i+1][player.col]=TILE_MONSTER;
        }
        else if(map[i][player.col]==TILE_PILLAR){
            break;
        }
        
    }
    ////going down
    for(int i=player.row+1;i<maxRow;++i){
        if (map[i][player.col]==TILE_MONSTER){
            map[i][player.col]=TILE_OPEN;
            map[i-1][player.col]=TILE_MONSTER;
        }
        else if(map[i][player.col]==TILE_PILLAR){
            break;
        }
    }
    ////going left 
    for(int i=player.col-1;i>=0;--i){
        if (map[player.row][i]==TILE_MONSTER){
            map[player.row][i]=TILE_OPEN;
            map[player.row][i+1]=TILE_MONSTER;
        }
        else if(map[player.row][i]==TILE_PILLAR){
            break;
        }
        
    }
    ////going right
    for(int i=player.col+1;i<maxCol;++i){
        if (map[player.row][i]==TILE_MONSTER){
            map[player.row][i]=TILE_OPEN;
            map[player.row][i-1]=TILE_MONSTER;
        }
        else if(map[player.row][i]==TILE_PILLAR){
            break;
        }
    }


    ////Monster attacking

    if (map[player.row][player.col]==TILE_MONSTER){
        return true;
    }
    else {
    return false;
    }
}