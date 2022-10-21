#include<stdio.h>
#include<math.h>
double pi(int x){
    double suma = 0;
    for(int i=0; i<x; i++){
        suma += pow(-1, i)/(2*i+1);
    }
    return 4.0*suma;
}

// PI = 3,141592

int main(){
    int dokladnosc = 866860;
    //2mln wyraz ciągu jest mniejszy niż
    printf("Wartosc dla %d wyrazow ---> %lf\n", dokladnosc, pi(dokladnosc));
    return 0;
}
