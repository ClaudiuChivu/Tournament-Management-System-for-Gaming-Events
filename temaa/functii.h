
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
struct Player {
    char* firstName;
    char* secondName;
    int points;
};
typedef struct Player jucator;
struct Elem {
    struct Team* val;
    struct Elem* next;
};
typedef struct Elem Node;
struct Team {
    int nrPlayers; 
    char* teamName;
    jucator ** players;
    float teamScore;
    int teampoints;
};
typedef struct Team echipa;
struct Q{
    Node *front;
    Node *rear;
};
typedef struct Q Queue;
struct N{
    struct Team* val;
    struct N *left,*right;
};
typedef struct N nodBT;
struct nodAVL {
    echipa* val;
    struct nodAVL* left;
    struct nodAVL* right;
    int height;

};
typedef struct nodAVL nodAVL;

void addAtBeginning(Node **head, echipa* v);
void addAtEnd(Node **head, echipa* v);
void deleteTeam(Node** headRef, echipa* key);
float teamPoints(echipa* team);
void newTeamslist(Node **head, int nrEchipe);
void displayToFile(Node *head, FILE *f);
void push(Node**top, echipa* v);
 echipa*pop(Node **top);
 echipa* top(Node *top);
int isEmptyStack(Node* top);
void deleteStack(Node** top);
Queue* createQueue();
void enQueue(Queue*q,echipa* v);
int isEmptyQueue(Queue *q);
echipa* deQueue(Queue*q);
void deleteQueue(Queue*q);
void runda(int nrEchipe, Node* head,FILE*f,Node** listaCastigatori);
nodBT* newNode(echipa* data);
nodBT* insert(nodBT* node, echipa* key);
void inordine(nodBT* node, FILE* f);
//nodAVL* insertAVL(nodAVL* node, echipa* key);
//void printLevel2(nodAVL* root,FILE* f);
int maxim(int a, int b);
int nodeHeight(nodAVL* node);
nodAVL *RightRotation(nodAVL *z);
nodAVL *LeftRotation(nodAVL *z);
nodAVL* LRRotation(nodAVL*z);
nodAVL* RLRotation(nodAVL*z);
nodAVL* insertAVL(nodAVL* node, echipa* key);
void printLevel(nodAVL* root, int level,FILE* f);
void levelOrderTraversal(nodAVL* root,FILE *f);
void inordineAVL(nodBT* node, FILE* f,Node** stiva);
