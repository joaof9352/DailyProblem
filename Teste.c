#include <stdlib.h>

typedef struct slist { 
    int valor; 
    struct slist *prox;
} *LInt;

//1

int verifica(int s[], int N){
    if(N <= 1) return 1;
    int razao = s[1] - s[0];
    for(int i = 2; i < N; i++){
        if((s[i] - s[i-1]) != razao)
            return 0;
    }
    return 1;
}

//2
void gera(LInt *l, int N){
    int i = 0;
    while(i < N){
        add(l,fib(i++));
    }
}

void add(LInt *l,int x){
    LInt new = malloc(sizeof(struct slist));
    new->valor = x;
    new->prox = NULL;

    while(*l && (*l)->prox) l = &((*l)->prox);

    if(!(*l)) (*l) = new;
    else (*l)->prox = new;

}

int fib(int N){
    if(N == 0) return 1;
    else if(N == 1) return 1;
    else return fib(N-1) + fib(N-2);
}


//3
int tamanho(LInt l){
    if(!l) return 0;
    LInt temp = l;
    int count = 0;
    while(l->prox != temp){
        l = l->prox;
        count++;
    }
    return count+1;
}

typedef struct dlist { 
    int valor; 
    struct dlist *ant, *prox;
} NodoD;

typedef struct {
    NodoD *front, *last
} DLint;

//4
void reverse(DLint *l){
    DLint *a = l;
    struct dlist *temp = NULL;
    while((*a).front != (*a).last){
        temp = (*a).front->prox;
        (*a).front->prox = (*a).front->ant;
        (*a).front->ant = temp;
        a = &((*a).front->prox);
    }
    temp = (*a).last->prox;
    (*a).last->prox = (*a).last->ant;
    (*a).last->ant = temp;
}


//5
typedef struct sbin{
    int valor;
    struct sbin *esq, *dir;
} *ABin;

//Dá errado!!!
void imprime(ABin t){
    if(!t) return;
    if(t->esq) printf("<");
    imprime(t->esq);
    if(t->dir) printf(">");
    imprime(t->dir);
    printf("%d\n",t->valor);
}

//6
#include <string.h>

void pad (char *texto, int p, int N){
    int i = 0;
    int countPalavras = 0;
    while(texto[i] && countPalavras < p){
        while(texto[i] != ' ')
            i++;
        addEspacos(texto,N,i);
        while(texto[i] == ' ') 
            i++;
        countPalavras++;
    }
}

void addEspacos(char *texto,int numEspacos, int i){
    int len = strlen(texto);
    memmove(&texto[i+numEspacos+1],&texto[i],texto - i);
    while(numEspacos){
        texto[i+numEspacos] = ' ';
        numEspacos--;
    }
}

typedef struct nodo { char *raiz; int quantos; struct nodo *esq, *dir; } *Palavras;

//7

//O significado é o número de nodos que a árvore tem
int calculaQuantos (Palavras p){
    if(!p) return NULL;
    p->esq->quantos = calculaQuantos(p->esq);
    p->dir->quantos = calculaQuantos(p->dir);
    p->quantos = 1 + (p->esq ? p->esq->quantos : 0) + (p->dir ? p->dir->quantos : 0);
    return p->quantos;
}

//8
int acrescenta (Palavras *e, char *p){
    Palavras *prev = NULL;
    while((*e) || strcmp(p,(*e)->raiz) != 0){
        prev = e;
        if(strcmp(p,(*e)->raiz) < 0)
            e = &((*e)->esq);
        else 
            e = &((*e)->dir);
    }
    //Significa que chegou ao fim da árvore e não econtrou a palavra
    if(!(*e)){
        Palavras a;
        if((a = malloc(sizeof(struct nodo)))){
            a->raiz = strdup(p);
            a->dir = NULL;
            a->esq = NULL;
            a->quantos = 0;
            if(strcmp(p, (*prev)->raiz) < 0)
                (*prev)->esq = a;
            else 
                (*prev)->dir = a;

            
        }
        else return 1;
    }
    else return 1;
}

//9
char *atRank (Palavras p, int k){
    if(p->quantos < k) return NULL;
    else if(p->quantos == k) return p->raiz;
    
    if(p->esq->quantos > k) return atRank(p->esq,k);
    else return atRank(p->dir,k);
}

int main() {
  struct sbin teste = {5, NULL, NULL};
  struct sbin a = {10, &teste, NULL};
  struct sbin c = {10, &teste, NULL};
  struct sbin b = {20, &a, &c};
  imprime(&b);
  return 0;
}
