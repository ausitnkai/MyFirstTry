#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack
{
    int top;
    int capacity;
    int *data;
}stack;

stack* new_stack(int size){
    stack* st = (stack*)malloc(sizeof(stack)+size*sizeof(int));
    st->top = -1;
    st->capacity = size-1; // 設定stack最多能容納多少資料
}

bool isEmpty(stack* st){
    return (st->top == -1);
}
bool isFull(stack* st){
    return (st->top == st->capacity);
}

void push(stack* st, int num){
    if(isFull(st)){
        printf("This stack is full.\n");
    }
    else{
        st->data[++st->top] = num;
    }
}

int pop(stack* st){
    if(isEmpty(st)){
        printf("This stack is empty.\n");
    }
    else{
        return (st->data[st->top--]);
    }
    return 0;
}

int main(){
    int size, pushNum, popNum;
    printf("Please input your stack size.\n");
    scanf("%d", &size);
    stack *myst = new_stack(size); // 建立一個stack

    for(int i = 0; i < size; i++){
        printf("Please enter number %d element:\n", i+1);
        scanf("%d", &pushNum);
        push(myst, pushNum);
    }
    push(myst, 100);
    
    // 這邊做push
    char onemoretimes = ' '; 
    do
    {
        printf("Please enter you  want to pop times:\n");
        scanf("%d", &popNum);
        for (int i = 0; i < popNum; i++)
        {
            int x = pop(myst);
            printf("you pop %d\n", x);

        }
        printf("Do you want to pop any element y/n or Y/N:\n");
        scanf("%c");
        scanf("%c", &onemoretimes);
    } while (onemoretimes == 'Y' || onemoretimes == 'y');
    
}