#include <iostream>
#include "logic.h"

using std::cout;
using std::endl;

// TODO(student): Write unit tests for the functions in logic.h
//                You should end up with at least 500 lines of test code
int main() {

Player player;
int maxRow=5;
int maxCol=3;
char ** my_map;
int nextRow=0;
int nextCol=0;
char move_around=0;
int player_move;
bool monster;
////////////////////////////////////////////////////////////load level cases

my_map=loadLevel("no_map.txt", maxRow, maxCol, player);
deleteMap(my_map,maxRow);

my_map=loadLevel("no_map1.txt", maxRow, maxCol, player);
deleteMap(my_map,maxRow);

my_map=loadLevel("bad_row.txt", maxRow, maxCol, player);
deleteMap(my_map,maxRow);

my_map=loadLevel("bad_col.txt", maxRow, maxCol, player);
deleteMap(my_map,maxRow);

my_map=loadLevel("exceeding_row.txt", maxRow, maxCol, player);
deleteMap(my_map,maxRow);

my_map=loadLevel("exceeding_col.txt", maxRow, maxCol, player);
deleteMap(my_map,maxRow);

my_map=loadLevel("no_exit.txt", maxRow, maxCol, player);
deleteMap(my_map,maxRow);

my_map=loadLevel("start_wall.txt", maxRow, maxCol, player);
deleteMap(my_map,maxRow);

my_map=loadLevel("extra_value_col.txt", maxRow, maxCol, player);
deleteMap(my_map,maxRow);

my_map=loadLevel("extra_value_row.txt", maxRow, maxCol, player);
deleteMap(my_map,maxRow);

my_map=loadLevel("char1.txt", maxRow, maxCol, player);
deleteMap(my_map,maxRow);

my_map=loadLevel("char2.txt", maxRow, maxCol, player);
deleteMap(my_map,maxRow);

my_map=loadLevel("char3.txt", maxRow, maxCol, player);
deleteMap(my_map,maxRow);

my_map=loadLevel("char4.txt", maxRow, maxCol, player);
deleteMap(my_map,maxRow);

my_map=loadLevel("invalid_file.txt", maxRow, maxCol, player);
deleteMap(my_map,maxRow);

my_map=loadLevel("string", maxRow, maxCol, player);
deleteMap(my_map,maxRow);

my_map=loadLevel("neg1.txt", maxRow, maxCol, player);
deleteMap(my_map,maxRow);

my_map=loadLevel("neg2.txt", maxRow, maxCol, player);
deleteMap(my_map,maxRow);

my_map=loadLevel("neg3.txt", maxRow, maxCol, player);
deleteMap(my_map,maxRow);

my_map=loadLevel("neg4.txt", maxRow, maxCol, player);
deleteMap(my_map,maxRow);

my_map=loadLevel("int32max1.txt", maxRow, maxCol, player);
deleteMap(my_map,maxRow);

my_map=loadLevel("int32max2.txt", maxRow, maxCol, player);
deleteMap(my_map,maxRow);

my_map=loadLevel("int32max3.txt", maxRow, maxCol, player);
deleteMap(my_map,maxRow);

my_map=loadLevel("int32max4.txt", maxRow, maxCol, player);
deleteMap(my_map,maxRow);

my_map=loadLevel("not_valid_symbol.txt", maxRow, maxCol, player);
deleteMap(my_map,maxRow);

my_map=loadLevel("not_enought_tiles.txt", maxRow, maxCol, player);
deleteMap(my_map,maxRow);

my_map=loadLevel("extra_col.txt", maxRow, maxCol, player);
deleteMap(my_map,maxRow);

my_map=loadLevel("extra_row.txt", maxRow, maxCol, player);
deleteMap(my_map,maxRow);

////////////////////////////////////////////////////////////resize map

my_map=loadLevel("good_map.txt", maxRow, maxCol, player);
my_map=resizeMap(my_map, maxRow, maxCol);
deleteMap(my_map,maxRow);
////////////////////////////////////////////////////////////monster,doplayer,direction
       
my_map=loadLevel("good_map.txt", maxRow, maxCol, player);

move_around='q';
getDirection(move_around, nextRow, nextCol);
player_move=doPlayerMove(my_map, maxRow, maxCol, player, nextRow, nextCol);
monster=doMonsterAttack(my_map, maxRow, maxCol, player);

move_around='e';
getDirection(move_around, nextRow, nextCol);
player_move=doPlayerMove(my_map, maxRow, maxCol, player, nextRow, nextCol);
monster=doMonsterAttack(my_map, maxRow, maxCol, player);

move_around='d';
nextRow=3;
nextCol=1;
getDirection(move_around, nextRow, nextCol);
player_move=doPlayerMove(my_map, maxRow, maxCol, player, nextRow, nextCol);
monster=doMonsterAttack(my_map, maxRow, maxCol, player);

move_around='s';
nextRow=4;
nextCol=1;
getDirection(move_around, nextRow, nextCol);
player_move=doPlayerMove(my_map, maxRow, maxCol, player, nextRow, nextCol);
monster=doMonsterAttack(my_map, maxRow, maxCol, player);


move_around='w';
nextRow=3;
nextCol=1;
getDirection(move_around, nextRow, nextCol);
doPlayerMove(my_map, maxRow, maxCol, player, nextRow, nextCol);
monster=doMonsterAttack(my_map, maxRow, maxCol, player);

move_around='a';
nextRow=3;
nextCol=0;
getDirection(move_around, nextRow, nextCol);
doPlayerMove(my_map, maxRow, maxCol, player, nextRow, nextCol);
monster=doMonsterAttack(my_map, maxRow, maxCol, player);

deleteMap(my_map,maxRow); 
////////////////////////////////////////////////////////////monster,doplayer,direction


my_map=loadLevel("map1.txt", maxRow, maxCol, player);//left out of bounds
nextRow=3;
nextCol=-1;
doPlayerMove(my_map, maxRow, maxCol, player, nextRow, nextCol);
deleteMap(my_map,maxRow); 

my_map=loadLevel("map2.txt", maxRow, maxCol, player);//right out of bounds
nextRow=3;
nextCol=3;
doPlayerMove(my_map, maxRow, maxCol, player, nextRow, nextCol);
deleteMap(my_map,maxRow); 

my_map=loadLevel("map3.txt", maxRow, maxCol, player);//up out of bounds
nextRow=-1;
nextCol=2;
doPlayerMove(my_map, maxRow, maxCol, player, nextRow, nextCol);
deleteMap(my_map,maxRow);  

my_map=loadLevel("map4.txt", maxRow, maxCol, player);//down out of bounds
nextRow=5;
nextCol=1;
doPlayerMove(my_map, maxRow, maxCol, player, nextRow, nextCol);
deleteMap(my_map,maxRow);  

my_map=loadLevel("map5.txt", maxRow, maxCol, player);//wall 
nextRow=2;
nextCol=1;
doPlayerMove(my_map, maxRow, maxCol, player, nextRow, nextCol);
deleteMap(my_map,maxRow); 



my_map=loadLevel("monster_case1.txt", maxRow, maxCol, player);

monster=doMonsterAttack(my_map, maxRow, maxCol, player);
deleteMap(my_map,maxRow);

my_map=loadLevel("monster_case2.txt", maxRow, maxCol, player);
my_map=resizeMap(my_map, maxRow, maxCol);
deleteMap(my_map,maxRow);

my_map=loadLevel("monster_case2.txt", maxRow, maxCol, player);

monster=doMonsterAttack(my_map, maxRow, maxCol, player);
deleteMap(my_map,maxRow);

/*
my_map=loadLevel("monster_case3.txt", maxRow, maxCol, player);

monster=doMonsterAttack(my_map, maxRow, maxCol, player);
deleteMap(my_map,maxRow);

*/
return 0;


}
