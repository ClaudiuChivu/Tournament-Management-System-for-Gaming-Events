Tema: Lan Party

Descriere:
-Am folosit o lista simplu inlantuita pentru a retine echipele  si un vector de pointeri
pentru a retine jucatorii din fiecare echipa, o structura pentru coada, arbore BST si arbore AVL.


-Pentru cerinta 1 am citit datele din fisierul d.in , prima data numarul de echipa,numele echipei si am adaugat jucatorii in vector, inclusiv datele despre acestia, apoi am folosit
functia  displayToFile(Node *head, FILE *f); pentru a parcurge lista de echipe si a o afisa


-Pentru cerinta 2  am folosit functiile deleteTeam(Node** headRef, echipa* key) (care sterge o echipa (nod) din lista simplu inlantuita ), teamPoints(echipa* team)( care calculeaza scorul de echipa). Pe acestea le-am apelat in  functia newTeamslist(Node **head, int nrEchipe) pentru a sterge echipele cu cel mai mic teamScore pana am ajuns la un nr(cel mai mare ) de echipe putere a lui 2.


-Pentru cerinta 3 am folosit  functiile : echipacastigatoare(echipa* wTeam, echipa* lTeam, Node** wStack, Node** lStack) (care  incrementeaza TeamScore-ul echipei castigatoare cu 1 si care pune in functie de teamScore in WStack sau LStack), dupa functia egalitate pentru cazul echipelor cu acelasi scor, pe acestea le am apelat in functia procesareechipe(echipa* team1, echipa* team2, Node** wStack, Node** lStack) pentru toate cele 3 cazuri (>,<,=)
Am folosit si functia addTeamsToQueue(Node* head, Queue* queue) pentru a adauga echipele din lista in coada de meciuri. Am luat un contor care atunci cand ajunge la  8, adauga  top 8 echipe din stiva pentru castigatori intr o noua lista.

-Pentru cerinta 4 am folosit urmatoarele functii:
  ~ nodBT* newNode(echipa* data) (care creeaza un nod nou in arbore )
  ~ nodBT* insert(nodBT* node, echipa* key) (care insereaza nodul in arbore, incat acesta sa fie BST)
  ~ void inordine(nodBT* node, FILE* f) ( care afiseaza arbore intr o inordine inversa, adica dreapta, radacina, stanga)


  -Pentru cerinta 5 am folosit:
   ~ int nodeHeight(nodAVL* root) - pentru a calcula inaltimea unui nod
   ~ int maxim(int a, int b) - pentru a returna maximul
   ~ nodAVL *RightRotation(nodAVL *z) pentru rotatia la dreapta
   ~ nodAVL *LeftRotation(nodAVL *z) pentru rotatia la stanga 
   ~ nodAVL* LRRotation(nodAVL*z); si nodAVL* RLRotation(nodAVL*z); pentru rotatii duble 
   ~ nodAVL* insertAVL(nodAVL* node, echipa* key)  pentru a insera arborele AVL  care respecta toate cazurile de comparare 
   ~ void printLevel(nodAVL* root, int level,FILE* f) pentru a afisa echipele de pe un anumit nivel
   

