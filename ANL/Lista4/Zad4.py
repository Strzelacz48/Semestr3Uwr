from math import sqrt
from math import sin
def F(x):
    return (x**4)-6*(sin(3*x-1))

def f_1(x_0, x_1):
    wynik = (x_0+x_1)/2
    it=27
    while(F(wynik)!=0 and it>0):
        if(F(wynik)>0):
            x_1=wynik
        else:
            x_0=wynik
        wynik=(x_0+x_1)/2
        it-=1
    return wynik
#for i in range(iteracje):
        #wynik = wynik - (((wynik-1)**2)*((wynik-2)**2)) / \
            #((2*(wynik**3)) - (9*(wynik**2)) + (13*wynik) - 6)

print("Kolejne iteracje f_1 dla x_0 e [-2,-1],x_1 e [-1,0],x_2 e [0,1],x_3 e [1,2]")
#for i in range(1, 10):
print("x_0 - ", f_1(-2, -1))
print("x_1 - ", f_1(-1, 0))
print("x_2 - ", f_1(0, 1))
print("x_3 - ", f_1(1, 2))