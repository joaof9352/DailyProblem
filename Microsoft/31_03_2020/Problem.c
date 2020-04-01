#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct slist *LInt;
typedef struct slist {
    int value;
    LInt next;
} Node;

LInt snoc (LInt l, int x){
    LInt ant,p;
    for(p = l; p != NULL; p = p->next) ant = p;

    p = malloc(sizeof(Node));
    p->value = x;
    p->next = NULL;

    if(l == NULL) l = p;
    else ant->next = p;

    return l;
}

int countDigits(int a){
    int ans = 0;
    if(a == 0) return 1;
    while(a != 0){
        ans++;
        a = a / 10;
    }
    return ans;
}

int* splitInt(int a){
    int num = countDigits(a);
    int i = 0;
    int* ans = malloc(num* sizeof(int));
    while (a>0) {
        ans[i++] = a % 10;
        a /= 10;
    }
    return ans;
}

LInt piecesTogether(int* a, int N){
    LInt ans = malloc(sizeof(Node));
    for(int i = 0; i < N; i++){
        snoc(ans,a[i]);
    }
    return ans;
}

int main() {
    int test[] = {1,2,3,4};
    LInt ans = piecesTogether(splitInt(1684),4);
    for(int i = 0; ans != NULL; ans = ans->next) printf("%d", ans->value);
}