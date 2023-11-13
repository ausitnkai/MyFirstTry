#include <stdio.h>
#include <string.h>
/*
    STRUCT 結構
    在一個結構中你可以去建構任何你想放的參數，不論它的型態是甚麼
    而那些參數都會存放在你所 "命名的結構的記憶體" 當中

    typedef 可以幫你宣告的 "對象型別" 命名一個自訂的名稱
*/

typedef struct
{
    int score;
    char nmae[12];
}player;



int main(){
    
    player player1;
    player player2;
    player player3 = {92, "Jully"}; //struct 可以直接宣告他們的參數

    //或者一個一個宣告
    strcpy(player1.nmae, "Bob");
    player1.score = 75;

    strcpy(player2.nmae, "Alan");
    player2.score = 89;
    
    printf("%s score is %d\n", player1.nmae, player1.score);
    printf("%s score is %d\n", player2.nmae, player2.score);
    printf("%s score is %d", player3.nmae, player3.score);

    return 0;
}