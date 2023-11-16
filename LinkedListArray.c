#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int val;
    struct node *next;
}node;


typedef struct Stack
{
    node* top;
}stack;

stack* new_stack(){
    stack* st = (stack*)malloc(sizeof(stack));
    st->top = NULL;
    return st;
}

bool isEmpty(stack* st){
    return (st->top == NULL);
}
int stackTop(stack* st){
    return st->top->val;
}

void push(stack* st, int num){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->val = num;
    newnode->next = st->top;
    st->top = newnode;
}

int pop(stack* st){
    node* deleteNode = st->top;
    if(isEmpty(st)){
        printf("Thie stack is Empty.\n");
        return -1;
    }
    int x = st->top->val;
    st->top = st->top->next;
    free(deleteNode);
    return x;
}

int main(){
    int size, pushNum, popNum;
    printf("Please input your stack size.\n");
    scanf("%d", &size);
    stack *st = new_stack(size); // 建立一個stack

    for(int i = 0; i < size; i++){
        printf("Please enter number %d element:\n", i+1);
        scanf("%d", &pushNum);
        push(st, pushNum);
    }
    printf("%d\n", stackTop(st));

    // 這邊做pop
    char onemoretimes = ' '; 
    do
    {
        printf("Please enter you  want to pop times:\n");
        scanf("%d", &popNum);
        for (int i = 0; i < popNum; i++)
        {
            int x = pop(st);
            printf("you pop %d\n", x);

        }
        printf("Do you want to pop any element y/n or Y/N:\n");
        scanf("%c");
        scanf("%c", &onemoretimes);
    } while (onemoretimes == 'Y' || onemoretimes == 'y');
    
}