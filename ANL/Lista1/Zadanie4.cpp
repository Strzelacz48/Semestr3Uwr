#include <stdio.h>
#include <math.h>

double integral(int n){
    if(n==0) return log(2023.0/2022.0);
    return (1.0/n)-(2022*integral(n-1));
}

int main(){
    for(int i=1; i<=20; i++){
        printf("%d - %lf\n", i, integral(i));
    }
    return 0;
}
