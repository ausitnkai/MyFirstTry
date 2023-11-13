#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

void resertBoard(); //重製整個九宮格
void printBoard(); //顯示現在整個九宮格的內容
int checkFreeSpace(); // 檢查九宮格內是否還有格子可以放
void playerMove(); // 使用者進行要畫哪格
void computMove(); //電腦決定要下哪格
char checkWinner(); //查看誰是勝利者
void printWinner(char); //印出誰是最後的勝者

char board[10000][10000];
const char player = 'X';
const char compute = 'O';

int main()
{
    char winner = ' ';
    char response = ' '; // 是否要再來一次

    do
    {
        winner = ' ';
        response = ' ';
        resertBoard();
        while(winner == ' ' && checkFreeSpace() != 0){
            printBoard();
            playerMove();
            winner = checkWinner();
            if(winner != ' ' || checkFreeSpace() == 0){
                break;
            }

            computMove();
            winner = checkWinner();
            if(winner != ' ' || checkFreeSpace() == 0){
                break;
            }
        }

        printBoard();
        printWinner(winner);

        printf("\n Would you like to play again?(Y/N): ");
        scanf("%c");
        scanf("%c", &response);
        response = toupper(response);
    } while (response == 'Y');
    
    printf("Thanks for playing");
    return 0;
}

void resertBoard(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            board[i][j] = ' ';
        }
    }
}
void printBoard(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf(" %c | ", board[i][j]);
        }
        printf("\n---|----|----|\n");
    }
}
int checkFreeSpace(){
    int freeSpace = 9;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] != ' '){
                freeSpace--;
            }
        }
    }
    return freeSpace;
}

void playerMove(){
    int x, y;
    do
    {
        printf("Enter Row #(1-3): ");
        scanf("%d", &x);
        x--;
        printf("Enter Column #(1-3): ");
        scanf("%d", &y);
        y--;

        if(board[x][y] != ' '){
            printf("This block has been used!!!\n");
        }
        else{
            board[x][y] = player;
            break; //如果有填到位置就直接結束
        }
    } while (board[x][y] != ' ');
    
} 
void computMove(){
    srand(time(0));
    int x, y;
    if (checkFreeSpace()>0)
    {
        do
        {
            x = rand()%3;
            y = rand()%3;
        } while (board[x][y] != ' ');
        board[x][y] = compute;
    }
    else
    {
        printWinner(' ');
    }
}
char checkWinner(){
    //check Row
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }
    //check Column
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[0][i] && board[0][i] == board[0][i])
        {
            return board[0][i];
        }
    }
    //check Diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][2])
    {
        return board[0][2];
    }
    return ' ';
}
void printWinner(char winner)
{
    if(winner == player){
        printf("YOU WIN!");
    }
    else if (winner == compute){
        printf("YOU LOSS");
    }
    else{
        printf("II'S A TIE");
    }
}   