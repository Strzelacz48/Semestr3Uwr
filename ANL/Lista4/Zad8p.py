def f(x,r):
    return (x-3)**r
def g(x,f,r,iteracje):
    wynik=x
    for i in range(iteracje):
        wynik = wynik - (r * (f(wynik,r) )**(1/r)) / ((f(wynik,r)**(1/r-1))*r*f(wynik,r-1))
    return wynik
print("Kolejne iteracje g dla x_0 = 10")
for i in range(1, 10):
    print(i, " - ", g(10,f,5, i))