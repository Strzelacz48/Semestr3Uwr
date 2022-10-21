#include<iostream>
#include <cmath>
using namespace std;
float silnia(float x){
    if(x==0) return 1;
    return x*silnia(x-1);
}
double funkcja1(double x)
{
    return 12132*(x-sin(x))/pow(x,3);
}
//12132 (1/3!-x^2/5!+x^4/7!-...)
double funkcja2(double x,int dokladnosc)
{
    double suma=0;
    for(int i=0;i<dokladnosc;i++)
    {
        suma+=(pow(x,i*2)/silnia(2+((i+1)*2)))*pow(-1,i);
    }
    return suma;
}
int main()
{
    for(int i=11;i<21;i++)
    {// poprawić zeby dostawał małe liczy program
    cout<<"Wynik z podejścia bez namysłu dla "<<i<<" : "<<funkcja1(pow(1,-i))<<"\n";
    cout<<"Wynik z podejścia po namyśle dla "<<i<<" : "<<funkcja2(0.001,20)<<"\n";
    }
    return 0;
}
//oblicz de hospitala

/*
#include<stdio.h>
#include<math.h>

float silnia(float x){
    if(x==0) return 1;
    return x*silnia(x-1);
}

float f1(float x){
    return 4042*(1-cos(x))/pow(x, 2);
}

float f2(float x, int wyrazy){
    float suma = 0;
    for(int i=0; i<wyrazy; i++){
        suma += pow(-1, i)*pow(pow(x, 2), i)/silnia(i*2+2);
    }
    return 4042*suma;
}
int main(){
    for(int i=11; i<=20; i++){
        printf("i = %d ---> %f\n", i, f1(pow(10, -i)));
    }
    printf("\n\n");
    for(int i=11; i<=20; i++){
        printf("i = %d ---> %f\n", i, f2(pow(10, -i), 1));
    }
    return 0;
}
*/
