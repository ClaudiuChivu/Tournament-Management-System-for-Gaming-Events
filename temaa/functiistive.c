#include "functii.h"
void push(Node**top, echipa* v){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->val=v;
    newNode->next=*top;
    *top=newNode;   
}
echipa*pop(Node **top){
    if(isEmptyStack(*top)) return NULL;
    Node *temp=*top;
    echipa*aux=temp->val;
    *top=(*top)->next;
    free(temp);
    return aux;
}
echipa* top(Node *top){
    if(isEmptyStack(top)) return NULL;
    return top->val;
}
int isEmptyStack(Node* top){
    return top==NULL;
}
void deleteStack(Node** top){
    Node *temp;
    while((*top)!=NULL){
        temp=*top;
        *top=(*top)->next;
        free(temp);
    }
}