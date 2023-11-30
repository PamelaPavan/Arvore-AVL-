
#include "avl.h"

/* funcao: AVL *createAVL()
   *  acao:        funcao que cria uma AVL
   *  entrada:     void
   *  saida:       ponteiro para uma AVL
   *  suposicoes:  nenhuma
*/
AVL *createAVL(void)
{
    return NULL;
}

/* funcao: Node *createNode()
   *  acao:        funcao que cria um novo no o qual devera
   					ser inserido na arvore
   *  entrada:     elemento de informacao do novo no
   *  saida:       ponteiro para um no
   *  suposicoes:  nenhuma
*/
struct avlno *createNodeAVL(Info *inf)
{
    struct avlno *ptr;
    if((ptr=(struct avlno *)malloc(sizeof(struct avlno)))){
        ptr->info=inf;
        ptr->balance=0;
        ptr->left=NULL;
        ptr->right=NULL;
        return ptr;
    }
    return NULL;
}

/* funcao: Info *createInfo(int i)
   *  acao:        funcao que aloca espaco para um elemento de informacao
   *  entrada:     inteiro representando o novo elemento de informacao
   *  saida:       ponteiro para a area de memoria do elemento de informacao
   *  suposicoes:  nenhuma
*/
Info *createInfo(int i)
{
    Info *ptr;
    if((ptr=(Info *)malloc(sizeof(Info)))){
        ptr->value=i;
        return ptr;
    }
    return NULL;
}

/* funcao: int isEmptyAVL(AVL *avl)
   *  acao:        verifica se uma árvore avl esta vazia ou nula
   *  entrada:     ponteiro para a árvore avl (avl)
   *  saida:       1, se a arvore avl é vazia ou nula
				   0, caso contrario
   *  suposicoes:  árvore avl
*/
int isEmptyAVL(AVL *avl)
{
    if(!avl)return 1;
    return 0;
}

/* funcao: AVL * leftAVL(AVL *avl)
   *  acao:        retorna a subárvore esquerda de uma árvore avl
   *  entrada:     ponteiro para a árvore avl (avl)
   *  saida:       ponteiro para a subárvore esquerda de avl
   *  suposicoes:  árvore avl
*/
AVL *leftAVL(AVL *avl)
{
    if(isEmptyAVL(avl))return NULL;
    return avl->left;
}

/* funcao: AVL * rightAVL(AVL *avl)
   *  acao:        retorna a subárvore direita de uma árvore avl
   *  entrada:     ponteiro para a árvore avl (avl)
   *  saida:       ponteiro para a subárvore direita de avl
   *  suposicoes:  árvore avl
*/

AVL *rightAVL(AVL *avl)
{
    if(isEmptyAVL(avl))return NULL;
    return avl->right;
}

/* funcao: Info * rootAVL(AVL *avl)
   *  acao:        retorna o elemento de informacao da raiz de uma árvore avl
   *  entrada:     ponteiro para a árvore avl (avl)
   *  saida:       ponteiro para o elemento de informacao da raiz da árvore avl
   *  suposicoes:  árvore avl
*/
Info *rootAVL(AVL *avl)
{
    if(isEmptyAVL(avl))return NULL;
    return avl->info;
}


/* funcao: AVL searchAVL(AVL *avl,Info *inf)
   *  acao:        busca por um elemento de informacao na arvore avl
   *  entrada:     ponteiro para a árvore avl (avl) e um ponteiro
   					para o elemento de informação (inf)
   *  saida:       pontiro para o no da arvore que contem o elemento
   					 de informacao buscado
				   NULL, caso contrario
   *  suposicoes:  árvore avl
*/
AVL *searchAVL(AVL *avl,Info *inf)
{
    if(!inf || !avl ) return NULL;
    if(avl->info->value==inf->value) return avl;
    else if((rootAVL(avl))->value>inf->value)return searchAVL(leftAVL(avl),inf);
    else return searchAVL(rightAVL(avl),inf);
}

/* funcao: int heightAVL(AVL *avl)
   *  acao:        calcula a altura de uma arvore avl
   *  entrada:     ponteiro para a árvore avl (avl)
   *  saida:       inteiro representando a altura da arvore
   *  suposicoes:  árvore avl
*/
int heightAVL(AVL *avl)
{
    int l,r;
    if(!avl)return 0;
    l=1+heightAVL(leftAVL(avl));
    r=1+heightAVL(rightAVL(avl));
    if(r>l)return r;
    else return l;
}

/* funcao: int isAVL(AVL *avl)
   *  acao:        verifica se eh arvore avl
   *  entrada:     endereço de um ponteiro para a árvore avl (avl)
   *  saida:		1, se a diferenca de altura entre as subarvores esquerda e direita eh <=1
   					0, caso contrario
   *  suposicoes:  árvore avl
*/
int isAVL(AVL *avl) {
  if (avl == NULL) return 1;
  return (abs(heightAVL(leftAVL(avl)) - heightAVL(rightAVL(avl))))<=1;
}

void LL_RotationAVL(AVL** avl)
{
	printf("\nLL_RotationAVL:1");
	AVL* b = *avl;
	AVL* a = b->left;
	b->left = a->right;
	a->right = b;
	a->balance = 0;
	b->balance = 0;
	*avl = a;
}

void RR_RotationAVL(AVL** avl)
{
	printf("\nRR_RotationAVL:1");
	AVL* a = *avl;
	AVL* b = a->right;
	a->right = b->left;
	b->left = a;
	a->balance = 0;
	b->balance = 0;
	*avl = b;
}

void LR_RotationAVL(AVL** avl)
{
	printf("\nLR_RotationAVL:1");
	AVL *c = *avl;
	AVL *a = c->left;
	AVL *b = a->right;

	c->left = b->right;
	a->right = b->left;
	b->left = a;
	b->right = c;
	switch(b->balance)
	{
	  case -1:
		a->balance = 0;
		c->balance = 1;
		break;
	  case 0:
		a->balance = 0;
		c->balance = 0;
		break;
	  case +1:
		a->balance = -1;
		c->balance = 0;
		break;
	}
	b->balance = 0;
	*avl = b;
}

void RL_RotationAVL(AVL** avl)
{
	printf("\nLR_RotationAVL:1");
	AVL *a = *avl;
	AVL *c = a->right;
	AVL *b = c->left;

	c->left = b->right;
	a->right = b->left;
	b->left = a;
	b->right = c;
	switch(b->balance)
	{
		case -1:
		a->balance = 0;
		c->balance = 1;
		break;
		case 0:
		a->balance = 0;
		c->balance = 0;
		break;
		case +1:
		a->balance = -1;
		c->balance = 0;
		break;
	}
	b->balance = 0;
	*avl = b;
}


/* funcao: int auxInsertAVL(AVL** avl, Info *inf, int *growup)
   *  acao:        aux insere um elemento de informacao na arvore avl
   *  entrada:     endereço de um ponteiro para a árvore avl (avl) e um ponteiro para o elemento de informação a ser inserido (inf)
   *  saida:		1, caso a inserção ocorra com sucesso
   					0, caso contrario
   *  suposicoes:  árvore avl
*/
//growup indica que apos a insercao a avl cresceu
int auxInsertAVL(AVL** avl, Info *inf, int *growup)
{
	if (*avl==NULL)
	{
		printf("\nauxInsertAVL:1");
    	*avl=createNodeAVL(inf);
    	*growup=1;
		return 1;
	}
	//se o nó já existe, o mesmo não será inserido
    if (inf->value==(*avl)->info->value) return 0;

	// insercao na sub-arvore esquerda
	if (inf->value<(*avl)->info->value)
	{
		printf("\nauxInsertAVL:2");
    	if (auxInsertAVL(&(*avl)->left,inf,growup))
		{
		    if (*growup)
			{
				switch ((*avl)->balance)
				{
					case 1:
						if ((leftAVL(*avl))->balance == 1)
					    	LL_RotationAVL(avl);
					 	else
							LR_RotationAVL(avl);
						*growup = 0;
						break;
					case 0:
						(*avl)->balance=1;
						*growup = 1;
						break;
					case -1:
						(*avl)->balance = 0;
						*growup= 0;
						break;
				}
			}
			return 1;
		}
		else return 0;
	}

	// insercao na sub-arvore direita
  	if(inf->value>(*avl)->info->value)
	{
		if(	auxInsertAVL(&(*avl)->right,inf,growup))
		{
			printf("\nauxInsertAVL:3");
			if(*growup)
			{
				switch ((*avl)->balance)
				{
					case -1:
						if ((rightAVL(*avl))->balance == -1)
							RR_RotationAVL(avl);
						else
							RL_RotationAVL(avl);
						*growup = 0;
						break;
					case 1:
						(*avl)->balance = 0;
						*growup = 0;
						break;
					case 0:
						(*avl)->balance = -1;
						*growup = 1;
						break;
				}
			}
			return 1;
		}
		else return 0;
	}
	return 0;
}

/* funcao: int insertAVL(AVL **avl,Info *inf)
   *  acao:        insere um elemento de informacao na arvore avl
   *  entrada:     endereço de um ponteiro para a árvore avl (avl)
   			 e um ponteiro para o elemento de informação a ser inserido (inf)
   *  saida:		1, caso a inserção ocorra com sucesso
   					0, caso contrario
   *  suposicoes:  árvore avl
*/
int insertAVL(AVL **avl,Info *inf)
{
	int growup=0;
	return auxInsertAVL(avl,inf,&growup);
}



/*******************************IMPLEMENTADO***************************************/


/* funcao: AVL * findSmallestElementAVL(AVL *avl)
   *  acao:        Busca o menor elemento da arvore posicionado mais a esquerda de uma arvore avl
   *  entrada:     ponteiro para a árvore binaria avl
   *  saida:       ponteiro para a arvore binaria avl
   *  suposicoes:  árvore avl
*/
AVL *findSmallestElementAVL(AVL *avl){
    if(isEmptyAVL(avl) || isEmptyAVL(leftAVL(avl))) return avl;
    else return findSmallestElementAVL(leftAVL(avl));
}

/* funcao: AVL * treeToAVL(AVL *avl)
   *  acao:        função auxiliar da deleteAVL que transforma uma árvore desbalanceada em balanceada
   *  entrada:     ponteiro para a árvore binaria desbalanceada
   *  saida:       ponteiro para a arvore balanceada
   *  suposicoes:  árvore avl
*/
AVL *treeToAVL(AVL *avl){

    // analizar qual método de rotação utilizar
    // rebalancear a arvore

    AVL *auxLeft = leftAVL(avl); // Subarvore esquerda da raiz
    AVL *auxRight = rightAVL(avl); // Subarvore direita da raiz

    // se a arvore estiver desbalanceada pela esquerda
    // LL_Rotation ou LR_Rotation
    if ( ( heightAVL(leftAVL(avl))) - heightAVL(rightAVL(avl) ) > 1){

        // Se subarvore esquerda é a mais funda, utiliza a LL_rotation
        if( (heightAVL(leftAVL(auxLeft)) - heightAVL(rightAVL(auxLeft))) > 0 ){
            LL_RotationAVL(*avl);
        }

        // Se a subarvore direita é a mais funda, utiliza a LR_Rotation
        else if((heightAVL(leftAVL(auxLeft)) - heightAVL(rightAVL(auxLeft))) < 0){
            LR_RotationAVL(*avl);
        }
    }

    // se a arvore estiver desbalanceada pela direita
    // RR_Rotation ou RL_Rotation
    else if( ( heightAVL(leftAVL(avl)) - heightAVL(rightAVL(avl) ) < (-1) ) {

        // Se subarvore esquerda é a mais funda, utiliza a RR_rotation
        if( (heightAVL(leftAVL(auxRight)) - heightAVL(rightAVL(auxRight))) > 0 ){
            RR_RotationAVL(*avl);
        }

        // Se a subarvore direita é a mais funda, utiliza a RL_Rotation
        else if((heightAVL(leftAVL(auxRight)) - heightAVL(rightAVL(auxRight))) < 0){
            RL_RotationAVL(*avl);
        }
    }

    return avl;
}


/* funcao: AVL * deleteAVL(AVL *avl,Info *inf)
   *  acao:        eliminar um elemento de informação da arvore, e mantem a arvore avl
   *  entrada:     ponteiro para a árvore binaria avl e ponteiro para o elemento de informação a ser deletado inf
   *  saida:       ponteiro para a arvore com o elemento de informcao deletado
   *  suposicoes:  árvore avl
*/
AVL *deleteAVL(AVL *avl,Info *inf)
{
    // Caso trivial
    if(avl==NULL) return avl;
    if(inf->value < (rootAVL(avl))->value)
        avl->left=deleteAVL(leftAVL(avl), inf);
    else if(inf->value > (rootAVL(avl))->value)
        avl->right=deleteAVL(rightAVL(avl), inf);
    else{
        // nó com somente um filho ou nenhum filho
        if(leftAVL(avl)==NULL){
            struct avlno *temp = rightAVL(avl);
            free(avl->info);
            free(avl);

        }
        else if(rightAVL(avl)==NULL){
            struct avlno *temp = leftAVL(avl);
            free(avl->info);
            free(avl);

        }
        // nó com dois filhos: deleta o nó substituindo-o pelo seu sucessor
        // "em-ordem" (menor elemento da subarvore direita)
        struct avlno *temp = findSmallestElementAVL(rightAVL(avl));
        // Copia o conteudo do menor elemento da subarvore direita para o nó
        avl->info=temp->info;
        // Deleta o sucessor "em-ordem"
        avl->right = deleteAVL(rightAVL(avl), temp->info);
    }
    // Verifica se a arvore está balanceada, caso nao esteja, chama a função para balancear
	if(!isAVL(avl)){
        avl=treeToAVL(avl);
	}
    return avl;
}

/*********************************************************************************************/

/* funcao: void auxprintAVL(AVL *avl)
   *  acao:        imprime os elementos de informação considerando o caminho em profundidade da arvore
   *  entrada:     ponteiro para a árvore binaria avl
   *  saida:       void
   *  suposicoes:  árvore avl
*/
void auxprintAVL(AVL *avl)
{
	if(isEmptyAVL(avl))return;

    auxprintAVL(leftAVL(avl));
    printf(" %d", (rootAVL(avl))->value);
    auxprintAVL(rightAVL(avl));
}


/* funcao: void printAVL(AVL *avl)
   *  acao:        imprime os elementos de informação considerando o caminho em profundidade da arvore
   *  entrada:     ponteiro para a árvore binaria avl
   *  saida:       void
   *  suposicoes:  árvore avl
*/
void printAVL(AVL *avl)
{

	if(isEmptyAVL(avl))return;
	auxprintAVL(leftAVL(avl));
    printf(" %d", (rootAVL(avl))->value);
    auxprintAVL(rightAVL(avl));

}

/* funcao: void printPreOrderAVL(AVL *avl)
   *  acao:        imprime os elementos de informação considerando o caminho em PreOrdem da arvore
   *  entrada:     ponteiro para a árvore binaria avl
   *  saida:       void
   *  suposicoes:  árvore avl
*/
void printPreOrderAVL(AVL *avl)
{

	if(isEmptyAVL(avl))return;
	printf(" %d", (rootAVL(avl))->value);
	printPreOrderAVL(leftAVL(avl));
    printPreOrderAVL(rightAVL(avl));

}


