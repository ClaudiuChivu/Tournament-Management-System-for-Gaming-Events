#include "functii.h"
Queue* createQueue(){
    Queue *q;
 q=(Queue*)malloc(sizeof(Queue));
 if(q==NULL) return NULL;
 q->front=q->rear=NULL;
 return q;
}
void enQueue(Queue*q,echipa* v){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->val=v;
    newNode->next=NULL;
    //nodurile noi se adauga la finalul cozii
    if(q->rear==NULL) q->rear=newNode;
    else{
        (q->rear)->next=newNode;
        (q->rear)=newNode;
    }
    //daca exista un singur element in coada
    if(q->front==NULL) q->front=q->rear;

}
int isEmptyQueue(Queue *q){
    return (q->front==NULL);
}
echipa* deQueue(Queue*q){
    Node* aux; echipa* d;
    if(isEmptyQueue(q)) return NULL;
    aux=q->front;
    d=aux->val;
    q->front=(q->front)->next;
    free(aux);
    return d;
}
void deleteQueue(Queue*q){
    Node* aux;
    while(!isEmptyQueue(q)){
        aux=q->front;
        q->front=q->front->next;
        free(aux);
    }
    free(q);
}