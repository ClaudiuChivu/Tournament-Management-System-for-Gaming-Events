#include "functii.h"
nodBT* newNode(echipa* data) {
    nodBT* node = (nodBT*)malloc(sizeof(nodBT));
    node->val = data;
    node->left = node->right = NULL;
    return node;
}

nodBT* insert(nodBT* node, echipa* key) {
    if (node == NULL)
        return newNode(key);
    
    if (key->teamScore < node->val->teamScore) {
        node->left = insert(node->left, key);
    } else if (key->teamScore > node->val->teamScore) {
        node->right = insert(node->right, key);
    } else { 
        if (strcmp(key->teamName, node->val->teamName) < 0) {
            node->left = insert(node->left, key);
        } else {
            node->right = insert(node->right, key);
        }
    }
    
    return node;
}

void inordine(nodBT* node, FILE* f) {
    if (node != NULL) {
        inordine(node->right,f);
       fprintf(f,"%-33s -  %.2f\n", node->val->teamName,node->val->teamScore);
        inordine(node->left,f);
        
    }
}
void inordineAVL(nodBT* node, FILE* f, Node** stiva) {
    if (node != NULL) {
    
        
        inordineAVL(node->left, f, stiva);
       push(stiva, node->val);
      
       inordineAVL(node->right, f, stiva);
    }
}

int nodeHeight(nodAVL* root) {
    int hs, hd;
    if(root==NULL) return -1;
    hs = nodeHeight(root->left);
    hd = nodeHeight(root->right);
    return 1+((hs>hd) ? hs:hd);
}



int maxim(int a, int b) {
     return (a > b) ? a:b;
}
nodAVL *RightRotation(nodAVL *z){
    nodAVL *y = z->left;
    nodAVL *T3 = y->right;
    y->right = z;
    z->left = T3;
    z->height = maxim(nodeHeight(z->left), nodeHeight(z->right))+1;
    y->height = maxim(nodeHeight(y->left),nodeHeight(y->right))+1;
    return y;
}
nodAVL *LeftRotation(nodAVL *z){
    nodAVL *y = z->right;
    nodAVL *T2 = y->left;
    y->left = z;
    z->right = T2;
    z->height = maxim(nodeHeight(z->left), nodeHeight(z->right))+1;
    y->height = maxim(nodeHeight(y->left),nodeHeight(y->right))+1;
    return y;
}
nodAVL* LRRotation(nodAVL*Z){
    Z->left = LeftRotation(Z->left);
    return RightRotation(Z);
}
nodAVL* RLRotation(nodAVL*Z){
    Z->right = RightRotation(Z->right);
    return LeftRotation(Z);
}
nodAVL* insertAVL(nodAVL* node, echipa* key){
    if(node == NULL){
        node=(nodAVL*)malloc(sizeof(nodAVL));

        node->val=key;
        node->height=0;
        node->left=node->right=NULL;
        return node;
    }
    if(key->teamScore < node->val->teamScore){
        node->left = insertAVL(node->left, key);
    } else if(key->teamScore > node->val->teamScore){
        node->right = insertAVL(node->right, key);
    } else if(key->teamScore == node->val->teamScore){
        if(strcmp(key->teamName,node->val->teamName) > 0){
            node->left=insertAVL(node->left,key);
           
      
        } else{
            node->right=insertAVL(node->right, key);
        }
    }

    node->height= 1+maxim(nodeHeight(node->left), nodeHeight(node->right));
    int k = (nodeHeight(node->left)-nodeHeight(node->right));
    if(k > 1 && key->teamScore < node->left->val->teamScore)
      return RightRotation(node);
   
     
    if (k < -1 && key->teamScore > node->right->val->teamScore)
       return LeftRotation(node);
     
    if(k > 1 && key->teamScore > node->left->val->teamScore )
      return RLRotation(node);
      
     
    if(k < -1 && key->teamScore < node->right->val->teamScore)
   return  LRRotation(node);
   

  
    
return node;
}

void printLevel(nodAVL* root, int level,FILE* f){
    if(root == NULL) return;
    if(level == 1) {fprintf(f,"%s ", root->val->teamName);
     fprintf(f,"\n");}
    else if ( level > 1){
        printLevel(root->right, level-1,f);
        printLevel(root->left, level-1,f);
       //printLevel(root->right, level-1,f);
    }
}


void levelOrderTraversal(nodAVL* root,FILE *f){
    int h = nodeHeight(root);
    int i;
   for(i=1; i<=h; i++){
        printLevel(root, i, f);
        fprintf(f,"\n");
    }
}
/*void printLevel(nodAVL* root, int level, FILE* f) {
    if (root == NULL)
        return;

    if (level == 1) {
        fprintf(f, "%s ", root->val->teamName);
    } else if (level > 1) {
        printLevel(root->left, level - 1, f);
        printLevel(root->right, level - 1, f);
    }
}

void levelOrderTraversal(nodAVL* root, FILE* f) {
    if (root == NULL)
        return;

    int h = nodeHeight(root);
    int i;
    for (i = 1; i <= h+1; i++) {
        fprintf(f, "Level %d: ", i);
        printLevel(root, i, f);
        fprintf(f, "\n");
    }
}
*/