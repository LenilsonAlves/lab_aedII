#include <stdio.h>
#include <stdlib.h>

int isPerfect(int n){
    int soma = 0, i;
    for (i = 1; i < n; i++){
        if( n % i == 0){
            soma+= i;
        }
    }

    if(soma == n){
        return soma;
    }
}

int main(){
int n, r;

printf("\nInsira um n�mero: ");
scanf("%i", &n);

r = isPerfect(n);

if(r == n){
    printf("\n%i � um n�mero perfeito", n);
} else {
     printf("\n%i n�o � um n�mero perfeito", n);
}


}
