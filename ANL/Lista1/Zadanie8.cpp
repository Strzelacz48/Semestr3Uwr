#include<stdio.h>
#include<math.h>

double f1_s(double x, double h){
    return (pow(x+h, 2)-pow(x, 2))/h;
}

double f2_s(double x, double h){
    return (sqrt(x+h)-sqrt(x))/h;
}

double f3_s(double x, double h){
    return (sin(x+h)-sin(x))/h;
}

double f1_d(double x, double h){
    return (pow(x+h, 2)-pow(x-h, 2))/(2*h);
}

double f2_d(double x, double h){
    return (sqrt(x+h)-sqrt(x-h))/(2*h);
}

double f3_d(double x, double h){
    return (sin(x+h)-sin(x-h))/(2*h);
}
int main(){
    double x = pow(10, -16);
    printf("SLABE\nf1\t\tf2\t\tf3\n");

    for(double i=1; i>x; i/=10){
        printf("%lf\t%lf\t%lf\n", f1_s(2, i), f2_s(4, i), f3_s(0, i));
    }

    printf("\n\nDOBRE\nf1\t\tf2\t\tf3\n");

    for(double i=1; i>x; i/=10){
        printf("%lf\t%lf\t%lf\n", f1_d(2, i), f2_d(4, i), f3_d(0, i));
    }
    return 0;
}
