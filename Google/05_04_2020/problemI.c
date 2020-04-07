typedef struct linkedlist{
    int value;
    struct linkedlist* next;
} * LInt;

void reverse(LInt *l) {
    LInt prev = NULL;
    LInt following = NULL;
    LInt cur = (*l);
    while(cur){
        following = cur->next;
        cur->prox = prev;
        prev = cur;
        cur = following;
    }
    (*l) = prev;
}
