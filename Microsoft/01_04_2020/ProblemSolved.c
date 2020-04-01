int auxAscii(char str[], int start){
    int ascii[255] = {0};
    int i;
    for(i = start; !ascii[str[i]] && str[i]; i++){
        ascii[str[i]] = 1;
    }
    return i-start;
}

int lengthOfLongestSubstring(char str[]){
    int i,max = 0,temp;
    for(i = 0; str[i]; i+=temp){
        temp = auxAscii(str,i);
        if(temp > max) max = temp;
    }
    return max;
}

int main() {
    char str[] = "Universidade do Minho";
    int a = lengthOfLongestSubstring(str);
    printf("%d", a);
}