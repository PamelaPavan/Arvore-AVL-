#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct tavl{
    struct tavl *right, *left;
    int value, balance;
}AVL;

AVL *createAVL(int inf){
    AVL *ptr;
    if(ptr=(AVL*)malloc(sizeof(AVL))){
        ptr->right=NULL;
        ptr->left=NULL;
        ptr->value=inf;
        ptr->balance=0;
        return ptr;
    }
    return NULL;
}
AVL *leftAVL(AVL *avl){
    if(!avl) return NULL;
    else return avl->left;
}
AVL *rightAVL(AVL *avl){
    if(!avl) return NULL;
    else return avl->right;
}
int rootAVL(AVL *avl){
    if(!avl) return NULL;
    return avl->value;
}
int heightAVL(AVL *avl){
    if(!avl) return NULL;
    int r,l;
    r=1+heightAVL(rightAVL(avl));
    l=1+heightAVL(leftAVL(avl));
    if(r > l) return r;
    else return l;
}
int isAVL(AVL *avl){
    if(!avl) return 1;
    if ( abs(heightAVL(leftAVL(avl)) - heightAVL(rightAVL(avl))) > 1)  return NULL;
    else return (isAVL(leftAVL(avl)) && isAVL(rightAVL(avl)));
}
int isEmptyAVL(AVL *avl){
    if(!avl) return 1;
    return NULL;
}
AVL *searchAVL(AVL *avl, int inf){
    AVL *ptr;
    if(!avl) return NULL;
    ptr=avl;
    if(inf == ptr->value) return ptr;
    else if(inf > ptr->value) return searchAVL(rightAVL(avl),inf);
    else return searchAVL(leftAVL(avl), inf);
}
void RR_Rotation(AVL **avl){
    AVL *a, *b;
    a=avl;
    b=a->right;
    a->right=b->left;
    b->left=a;
    a->balance=0;
    b->balance=0;
    *avl=b;
}







