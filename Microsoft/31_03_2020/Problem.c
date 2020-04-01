#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct slist *LInt;
typedef struct slist {
    int value;
    LInt next;
} Node;

LInt first(){
    LInt a = malloc(sizeof(Node));
    a->value = 1;
    a->next = malloc(sizeof(Node));
    a->next->value = 1;
    a->next->next = malloc(sizeof(Node));
    a->next->next->value = 2;
    a->next->next->next = NULL;
    return a;
}

int transform(LInt a){
    int p = 0, ans = 0;
    for(; a != NULL; p++, a = a->next){
        ans += a->value * pow(10, p);
    }
    return ans;
}

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
    ans->value = a[0];
    ans->next = NULL;
    for(int i = 1; i < N; i++){
        snoc(ans,a[i]);
    }
    return ans;
}

int main() {
    LInt a = first();
    LInt b = first();
    int c = transform(a) + transform(b);
    LInt ans = piecesTogether(splitInt(c),3);
    for(int i = 0; ans != NULL; ans = ans->next) printf("%d", ans->value);
}