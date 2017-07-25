#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>



char *compliment(char *str){
    int len = strlen(str);
    char *compliment = (char *)malloc(len*sizeof(char));
    for(int i=0;i<len;i++){
        if(str[i]=='0')
            compliment[i] = '1';
        else
            compliment[i] = '0';
    }
    return compliment;

}


char *expand(char *str){
    if(strlen(str)>1000)
        return str;
    else{
        char *expstr = strcat(str, compliment(str));
        expand(expstr);
    }
}




char *duplication(int x){
    char *zero = malloc(sizeof(char));
    strcat(zero,"0");
    char *rev = expand(zero);
    char *result = malloc(sizeof(char));
    if(rev[x]=='0')
        strcat(result, "0");
    else
        strcat(result,"1");
    return result;
}



int main() {
    int q; 
    scanf("%d", &q);
    for(int a0 = 0; a0 < q; a0++){
        int x; 
        scanf("%d", &x);
        int result_size;
        char* result = duplication(x);
        printf("%s\n", result);
    }
    return 0;
}
OP+KO