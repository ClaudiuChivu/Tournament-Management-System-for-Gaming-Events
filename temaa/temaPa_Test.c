#include "functii.h"
int main(int argc,char **argv) {
    FILE *fisier0 = fopen(argv[1],"r");
    if(fisier0 == NULL) {
        printf("Fisierul nu poate fi deschis");
        exit(1);
    }
    FILE *fisier1 = fopen(argv[2],"r");
    if(fisier1 == NULL) {
        printf("Fisierul nu poate fi deschis");
        exit(1);
    }
    FILE *fisier2 = fopen(argv[3],"w");
    if(fisier2 == NULL) {
        printf("Fisierul nu poate fi deschis");
         exit(1);
     }
    Node *listaechipe = NULL;
    char* teamName = (char*)malloc(50* sizeof(char));
    int nrrPlayers,totalTeams;

    fscanf(fisier1, "%d",  &totalTeams);
    for(int teamIndex=0;teamIndex<totalTeams;teamIndex++) {
        fscanf(fisier1,"%d ",&nrrPlayers);
        fgets(teamName,50,fisier1);
int length = strlen(teamName);
while (length > 0 && (teamName[length - 1] == ' ' || teamName[length - 1] == '\n' || teamName[length - 1] == '\r')) {
    teamName[length - 1] = '\0';
    length--;
}

        echipa* newTeam = (echipa*)malloc(sizeof(echipa));
         newTeam->nrPlayers = nrrPlayers;
        newTeam->teamName = (char*)malloc((strlen(teamName) ) * sizeof(char)); 
        strcpy(newTeam->teamName, teamName);
        newTeam->players = (jucator**)malloc(nrrPlayers * sizeof(jucator*));
        for (int i = 0; i < nrrPlayers; i++) {
            jucator* newPlayer = (jucator*)malloc(sizeof(jucator));
            newPlayer->firstName = (char*)malloc(30 * sizeof(char));
            newPlayer->secondName = (char*)malloc(30 * sizeof(char));
            fscanf(fisier1, "%s %s %d", newPlayer->firstName, newPlayer->secondName, &newPlayer->points);
            newTeam->players[i] = newPlayer;}
 
        if(listaechipe == NULL) {
            addAtBeginning(&listaechipe, newTeam);
        } else {
            addAtBeginning(&listaechipe, newTeam);
        }     
    }
       Node* listcastigatori=NULL;
    int nrtask;
    int task[5];
    for(int k=0;k<5;k++)
    {fscanf(fisier0,"%d",&task[k]);
   
    }
        if(task[0]==1)
        {
            displayToFile(listaechipe,fisier2);   
        fclose(fisier2);
        }
       if(task[1]==1)
         { FILE *fisier2 = fopen(argv[3],"w");
     
         newTeamslist(&listaechipe,totalTeams);
            displayToFile(listaechipe, fisier2);
        fclose(fisier2);
        
        }
        if(task[2]==1)
        {FILE *fisier2 = fopen(argv[3],"a");
       
          runda(totalTeams,listaechipe,fisier2,&listcastigatori);
        fclose(fisier2);
        }
         if(task[3]==1)
        {FILE *fisier2 = fopen(argv[3],"a");
        nodBT* bstRoot = NULL; 
Node* nodCurent = listcastigatori;
while (nodCurent != NULL) {
    bstRoot = insert(bstRoot, nodCurent->val);
    nodCurent = nodCurent->next;
}
fprintf(fisier2,"\nTOP 8 TEAMS:\n");
 inordine(bstRoot,fisier2);
 fclose(fisier2);
        }
     if(task[4]==1)
        {FILE *fisier2 = fopen(argv[3],"a");
            nodAVL* avlRoot = NULL;
  nodBT* bsttemp = NULL;
Node* current = listcastigatori;
 Node* stivaptinversare=NULL;
while (current != NULL) {
   bsttemp = insert(bsttemp, current->val);
  
    current = current->next;
}

for(int k=0;k<8;k++)
{
    inordineAVL(bsttemp,fisier2,&stivaptinversare);
}
while(!isEmptyStack(stivaptinversare))
{
    avlRoot = insertAVL(avlRoot,pop(&stivaptinversare));
}
/*while (current != NULL) {
   // avlRoot = insertAVL(avlRoot, current->val);
  push(&stivaptinversare,current->val);
  // bsttemp = insert(bsttemp, current->val);
  
    current = current->next;
}
while(!isEmptyStack(stivaptinversare))
{
    avlRoot = insertAVL(avlRoot,pop(&stivaptinversare));
}*/
fprintf(fisier2,"\nTHE LEVEL 2 TEAMS ARE:\n");
printLevel(avlRoot,3,fisier2);
fclose(fisier2);

        }
        
  
     fclose(fisier0);
     fclose(fisier1); 

    return 0;
}
    