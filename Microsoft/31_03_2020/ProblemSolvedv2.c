LInt sum(LInt ans, LInt b){
    int go=0;
    LInt c = ans, ant;
    for(int i = 0; c != NULL && b != NULL; c = c->next, b = b->next){
        int a1 = c->value;
        int b1 = b->value;
        if(a1+b1+go > 9){
            c->value = (a1+b1+go)%10;
            go = 1;
        }else{
            c->value = a1+b1;
            go = 0;
        }
        ant = c;
    }
    if(go = 1){
        LInt last = malloc(sizeof(Node));
        last->value = 1;
        last->next = NULL;
        ant->next = last;
    }
    return ans;
}