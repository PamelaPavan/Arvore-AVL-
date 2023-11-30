
#include <stdlib.h>
#include<stdio.h>

typedef struct avlno AVL;

typedef struct
{
	int value;
}Info;

struct avlno
{
	Info *info;
	int balance;
	struct avlno *left, *right;
};

/* funcao: AVL *createAVL()
   *  acao:        funcao que cria uma AVL
   *  entrada:     void
   *  saida:       ponteiro para uma AVL
   *  suposicoes:  nenhuma
*/
AVL *createAVL(void);

/* funcao: Node *createNode()
   *  acao:        funcao que cria um novo no o qual devera ser inserido na arvore
   *  entrada:     elemento de informacao do novo no
   *  saida:       ponteiro para um no
   *  suposicoes:  nenhuma
*/
struct avlno *createNodeAVL(Info *inf);


/* funcao: Info *createInfo(int i)
   *  acao:        funcao que aloca espaco para um elemento de informacao
   *  entrada:     inteiro representando o novo elemento de informacao
   *  saida:       ponteiro para a area de memoria do elemento de informacao
   *  suposicoes:  nenhuma
*/
Info *createInfo(int i);

/* funcao: int isEmptyAVL(AVL *avl)
   *  acao:        verifica se uma árvore avl esta vazia ou nula
   *  entrada:     ponteiro para a árvore avl (avl)
   *  saida:       1, se a arvore avl é vazia ou nula
				   0, caso contrario
   *  suposicoes:  árvore avl
*/
int isEmptyAVL(AVL *avl);

/* funcao: AVL * leftAVL(AVL *avl)
   *  acao:        retorna a subárvore esquerda de uma árvore avl
   *  entrada:     ponteiro para a árvore avl (avl)
   *  saida:       ponteiro para a subárvore esquerda de avl
   *  suposicoes:  árvore avl
*/
AVL *leftAVL(AVL *avl);

/* funcao: AVL * rightAVL(AVL *avl)
   *  acao:        retorna a subárvore direita de uma árvore avl
   *  entrada:     ponteiro para a árvore avl (avl)
   *  saida:       ponteiro para a subárvore direita de avl
   *  suposicoes:  árvore avl
*/
AVL *rightAVL(AVL *avl);

/* funcao: Info * rootAVL(AVL *avl)
   *  acao:        retorna o elemento de informacao da raiz de uma árvore avl
   *  entrada:     ponteiro para a árvore avl (avl)
   *  saida:       ponteiro para o elemento de informacao da raiz da árvore avl
   *  suposicoes:  árvore avl
*/
Info *rootAVL(AVL *avl);


/* funcao: AVL searchAVL(AVL *avl,Info *inf)
   *  acao:        busca por um elemento de informacao na arvore avl
   *  entrada:     ponteiro para a árvore avl (avl) e um ponteiro para o elemento de informação (inf)
   *  saida:       pontiro para o no da arvore que contem o elemento de informacao buscado
				   NULL, caso contrario
   *  suposicoes:  árvore avl
*/
AVL *searchAVL(AVL *avl,Info *inf);


/* funcao: int heightAVL(AVL *avl)
   *  acao:        calcula a altura de uma arvore avl
   *  entrada:     ponteiro para a árvore avl (avl)
   *  saida:       inteiro representando a altura da arvore
   *  suposicoes:  árvore avl
*/
int heightAVL(AVL *avl);

/* funcao: int isAVL(AVL *avl)
   *  acao:        verifica se eh arvore avl
   *  entrada:     endereço de um ponteiro para a árvore avl (avl)
   *  saida:		1, se a diferenca de altura entre as subarvores esquerda e direita eh <=1
   					0, caso contrario
   *  suposicoes:  árvore avl
*/
int isAVL(AVL *avl);

/* funcao: void LL_RotationAVL(AVL** avl)
   *  acao:        realiza rotacao LL em uma arvore avl
   *  entrada:     ponteiro para a árvore avl (avl) apontando para o no critico
   *  saida:       void
   *  suposicoes:  árvore avl
*/
void LL_RotationAVL(AVL** avl);

/* funcao: void RR_RotationAVL(AVL** avl)
   *  acao:        realiza rotacao RR em uma arvore avl
   *  entrada:     ponteiro para a árvore avl (avl) apontando para o no critico
   *  saida:       void
   *  suposicoes:  árvore avl
*/
void RR_RotationAVL(AVL** avl);

/* funcao: void LR_RotationAVL(AVL** avl)
   *  acao:        realiza rotacao LR em uma arvore avl
   *  entrada:     ponteiro para a árvore avl (avl) apontando para o no critico
   *  saida:       void
   *  suposicoes:  árvore avl
*/
void LR_RotationAVL(AVL** avl);

/* funcao: void RL_RotationAVL(AVL** avl)
   *  acao:        realiza rotacao RL em uma arvore avl
   *  entrada:     ponteiro para a árvore avl (avl) apontando para o no critico
   *  saida:       void
   *  suposicoes:  árvore avl
*/
void RL_RotationAVL(AVL** avl);

/* funcao: int auxInsertAVL(AVL** avl, Info *inf, int *growup)
   *  acao:        aux insere um elemento de informacao na arvore avl
   *  entrada:     endereço de um ponteiro para a árvore avl (avl) e um ponteiro para o elemento de informação a ser inserido (inf)
   *  saida:		1, caso a inserção ocorra com sucesso
   					0, caso contrario
   *  suposicoes:  árvore avl
*/
int auxInsertAVL(AVL** avl, Info *inf, int *growup);

/* funcao: int insertAVL(AVL **avl,Info *inf)
   *  acao:        insere um elemento de informacao na arvore avl
   *  entrada:     endereço de um ponteiro para a árvore avl (avl) e um ponteiro para o elemento de informação a ser inserido (inf)
   *  saida:		1, caso a inserção ocorra com sucesso
   					0, caso contrario
   *  suposicoes:  árvore avl
*/
int insertAVL(AVL **avl,Info *inf);

/* funcao: AVL * findSmallestElementAVL(AVL *avl)
   *  acao:        Busca o menor elemento da arvore posicionado mais a esquerda de uma arvore avl
   *  entrada:     ponteiro para a árvore binaria avl
   *  saida:       ponteiro para a arvore binaria avl
   *  suposicoes:  árvore avl
*/
AVL *findSmallestElementAVL(AVL *avl);

/* funcao: AVL * treeToAVL(AVL *avl)
   *  acao:        função auxiliar da deleteAVL que transforma uma árvore desbalanceada em balanceada
   *  entrada:     ponteiro para a árvore binaria desbalanceada
   *  saida:       ponteiro para a arvore balanceada
   *  suposicoes:  árvore avl
*/
AVL *treeToAVL(AVL *avl);

/* funcao: AVL * deleteAVL(AVL *avl,Info *inf)
   *  acao:        eliminar um elemento de informação da arvore, e mantem a arvore avl
   *  entrada:     ponteiro para a árvore binaria avl e ponteiro para o elemento de informação a ser deletado inf
   *  saida:       ponteiro para a arvore com o elemento de informcao deletado
   *  suposicoes:  árvore avl
*/
AVL *deleteAVL(AVL *avl,Info *inf);


/* funcao: void auxprintAVL(AVL *avl)
   *  acao:        imprime os elementos de informação considerando o caminho em profundidade da arvore
   *  entrada:     ponteiro para a árvore binaria avl
   *  saida:       void
   *  suposicoes:  árvore avl
*/
void auxprintAVL(AVL *avl);

/* funcao: void printAVL(AVL *avl)
   *  acao:        imprime os elementos de informação considerando o caminho em profundidade da arvore
   *  entrada:     ponteiro para a árvore binaria avl
   *  saida:       void
   *  suposicoes:  árvore avl
*/
void printAVL(AVL *avl);


/* funcao: void printPreOrderAVL(AVL *avl)
   *  acao:        imprime os elementos de informação considerando o caminho em PreOrdem da arvore
   *  entrada:     ponteiro para a árvore binaria avl
   *  saida:       void
   *  suposicoes:  árvore avl
*/
void printPreOrderAVL(AVL *avl);





