#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
}Node;

Node *current, *first, *previous;

void insertNode(Node* node, int item){  // 插入新的節點
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->val = item;
    newnode->next = node->next;
    node->next = newnode;
}

void printList(Node* first){ //印出串列
    Node* node = first;
    if(first == NULL){
        printf("這個List是空的");
    }
    else{
        while(node != NULL){
            printf("%d ", node->val);
            node = node->next;
        }
        printf("\n");
    }
}

Node* searchNode(Node* first, int item){ //搜尋節點
    Node* node=first;
    while(node->next != NULL){
        if(node->val == item){
            return node;
        }
        else{
            node = node->next;
        }
    }
    return NULL;
}

void push_front(int a){ //插入新的節點在開頭
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->val = a;
    newnode->next = first;
    first = newnode;
}
void push_back(int a){//插入新的節點在尾巴
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->val = a;
    newnode->next = NULL;
    if(first == 0){
        first = newnode;
    }
    else{
        Node* current = first;
        while (current->next != NULL)
        {
            current = current->next; //會一直往下走直到走完為止
        }
        current->next = newnode;
    }
}

void freeList(Node* first){ //釋放空間
    Node *current, *tmp;
    current = first;
    while(current != NULL){
        tmp = current;
        current = current->next;
        free(tmp);
    }
}

Node* deleteNode(Node* first, Node* node){ //刪除節點
    Node* ptr = first;
    if(first == NULL){
        printf("沒有甚麼東西可以刪除了!!!");
        return NULL;
    }
    if(node == first){
        first = first->next;
        free(node);
        return first;
    }
    else{
        while(ptr->next != node){
            ptr = ptr->next;  //走訪整個串列
        }
        ptr->next = node->next;
        free(node);
        return first;
    }
}

void reverse(){
    if(first == NULL || first->next == NULL){
        return;
    }
    Node *previous, *current, *preceding;
    previous = NULL;
    current = first;
    preceding = first->next;
    while(preceding != NULL){
        current->next = previous;
        previous = current;
        current = preceding;
        preceding = preceding->next;
    }
    current->next = previous;
    first = current;
}

int main(){
    //int num[5] = {12, 4, 8, 90, 23};
    int total;
    printf("Number of nodes:\n");
    scanf("%d", &total);
    
    for(int i = 0; i < total; i ++){
        current = (Node*)malloc(sizeof(Node));
        printf("Data for node %d: ", i+1);
        scanf("%d", &(current->val));

        if(i == 0){             // 如果這是第一個節點的話
            first = current;    // 將 first 指標指向目前的節點
            previous = current;  // 將 previous 指標指向目前的節點
        }
        else
        // 不斷的往下一個節點去做處理
        {
            previous->next = current; // 將前一個節點的下一個 指向目前的節點
            current->next = NULL;     // 將目前的下一個指向NULLL
            previous = current;       // 將前一個節點設為現在的節點
        }
    }
    current = first;
    printList(first);

    push_front(30);
    push_back(62);
    printf("After push_front() and push_back(): \n");
    printList(first);

    reverse();
    printf("After reverse(): \n");
    printList(first);

    Node* node2=searchNode(first, 8);
    deleteNode(first, node2);
    printf("搜尋並刪除該節點之後:\n");
    printList(first);

    freeList(first);
    return 0;
}