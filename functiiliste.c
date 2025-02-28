#include "functii.h"
void addAtBeginning(Node **head, echipa* v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = v;
    newNode->next = *head;
    *head = newNode;
}


void addAtEnd(Node **head, echipa* v) {
    Node *aux = *head;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = v;
    if (*head == NULL) {
        *head = newNode;
        newNode->next = NULL;
    } else {
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = newNode;
        newNode->next = NULL;
    }
}

void deleteTeam(Node** headRef, echipa* key)
{Node* temp=*headRef;
Node* prev=NULL;
if(temp != NULL && temp->val == key)
{
    *headRef= temp->next;
    free(temp);
    return;
}
while (temp != NULL && temp->val != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    prev->next = temp->next;
    free(temp);
}




float teamPoints(echipa* team){
    float sum=0;
    for(int i=0;i<team->nrPlayers;i++){
        sum+=team->players[i]->points;
    }
    return sum/team->nrPlayers;
}

void newTeamslist(Node **head, int nrEchipe) {
    if (*head == NULL) {
        return;
    }
    int putere2 = 1;
    while (putere2 < nrEchipe) {
        putere2 *= 2;
    }
   if (nrEchipe == putere2) {
    return;}
    Node *nodCurent = *head;
    float puncteminime = 10000;
    while (nodCurent != NULL) {
        echipa *echipaCurenta = nodCurent->val;
        if (echipaCurenta->nrPlayers > 0) {
            float puncteTotale = teamPoints(echipaCurenta);
            if (puncteTotale < puncteminime) {
                puncteminime = puncteTotale;
            }
      }
        nodCurent = nodCurent->next;
    }
    nodCurent = *head;
    while (nodCurent != NULL && nrEchipe > putere2/2){
        echipa *echipaCurenta=nodCurent->val;
        if(echipaCurenta->nrPlayers>0){
            float puncteTotale=teamPoints(echipaCurenta);
            if(puncteTotale==puncteminime){
                deleteTeam(head,echipaCurenta);
               nrEchipe--;
              break;
                 }}
    nodCurent=nodCurent->next;
}
if (nrEchipe > putere2/2) {  
    newTeamslist(head, nrEchipe);
}
}

void displayToFile(Node* head, FILE* f) {
    while (head != NULL) {
        fprintf(f, "%s\n", head->val->teamName);
        head = head->next;
    }
}
void echipacastigatoare(echipa* wTeam, echipa* lTeam, Node** wStack, Node** lStack) {
    wTeam->teamScore++;
    push(wStack, wTeam);
    push(lStack, lTeam);
}

void egalitate(echipa* team1, echipa* team2, Node** wStack, Node** lStack) {
    team2->teamScore++;
    push(wStack, team2);
    push(lStack, team1);
}

void procesareechipe(echipa* team1, echipa* team2, Node** wStack, Node** lStack) {
    if (team1->teamScore > team2->teamScore) {
        echipacastigatoare(team1, team2, wStack, lStack);
    } else if (team1->teamScore < team2->teamScore) {
        echipacastigatoare(team2, team1, wStack, lStack);
    } else {
        egalitate(team1, team2, wStack, lStack);
    }
}
void addTeamsToQueue(Node* head, Queue* queue) {
    while (head != NULL) {
        head->val->teamScore = teamPoints(head->val);
        enQueue(queue, head->val);
        head = head->next;
    }
}

void runda(int nrEchipe, Node* head, FILE* f,Node** listaCastigatori)
{   Queue* meciuri = createQueue();
    Node* StivaInvinsi = NULL;
   Node* StivaCastigatori = NULL;
   Node* auxstiva=NULL;
    Node* nodCurent = head;
    addTeamsToQueue(head,meciuri);
    int nrRunda = 1;
    while (nrEchipe > 1) {
        int count=0;
       Queue* meciuritemp=createQueue();
        fprintf(f, "\n--- ROUND NO:%d\n", nrRunda);    
        while (!isEmptyQueue(meciuri)) {
            echipa* echipa1 = deQueue(meciuri);
            echipa* echipa2 = deQueue(meciuri);
            fprintf(f, "%-32s - %32s\n", echipa1->teamName, echipa2->teamName);
            procesareechipe(echipa1, echipa2, &StivaCastigatori, &StivaInvinsi);
            count++;
        }
        while (!isEmptyStack(StivaCastigatori) && count==8) {
    echipa* echipaCastigatoare = pop(&StivaCastigatori);
    echipa* copieEchipaCastigatoare = (echipa*)malloc(sizeof(echipa));
memcpy(copieEchipaCastigatoare, echipaCastigatoare, sizeof(echipa));
 push(&auxstiva, echipaCastigatoare);
addAtBeginning(&*listaCastigatori, copieEchipaCastigatoare);
}
while (!isEmptyStack(auxstiva)) {
    push(&StivaCastigatori, pop(&auxstiva));
}
         fprintf(f, "\nWINNERS OF ROUND NO:%d\n", nrRunda);    
        while (!isEmptyStack(StivaCastigatori)) {
            enQueue(meciuri, pop(&StivaCastigatori));//pun iar castigatorii in coada pentru urmatoarea runda
         }
        nrEchipe /= 2;
        nrRunda++;
    while (!isEmptyQueue(meciuri)) {
        echipa* echipawin = deQueue(meciuri);
        fprintf(f, "%-33s -  %.2f\n", echipawin->teamName, echipawin->teamScore);
        enQueue(meciuritemp, echipawin); }   
 meciuri=meciuritemp;
     deleteStack(&StivaInvinsi);
     deleteStack(&StivaCastigatori); }  }

