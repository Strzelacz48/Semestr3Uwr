from math import sqrt


def f_1(x_0, iteracje):
    wynik = x_0
    for i in range(iteracje):
        wynik = wynik - (((wynik-1)**2)*((wynik-2)**2)) / \
            ((2*(wynik**3)) - (9*(wynik**2)) + (13*wynik) - 6)
    return wynik


def g_1(x_0, iteracje):
    wynik = x_0
    for i in range(iteracje):
        wynik = wynik - ((wynik-1)*(wynik-2)) / \
            ((2*wynik) - 3)
    return wynik


def f_2(x_0, iteracje):
    r = 2
    wynik = x_0
    for i in range(iteracje):
        wynik = wynik - (r*((wynik-1)**2)*((wynik-2)**3)) / \
            (((2-wynik)**2)*((5*(wynik**2)) - (12*wynik) + 7))
    return wynik


def g_2(x_0, iteracje):
    wynik = x_0
    for i in range(iteracje):
        wynik = wynik - ((wynik-1)*(wynik-2)*sqrt(wynik-2)) / \
            ((1/2.0)*sqrt(wynik-2)*((5*wynik)-7))
    return wynik


print("Kolejne iteracje f_1 dla x_0 = 10")
for i in range(1, 10):
    print(i, " - ", f_1(10, i))

print("\nKolejne iteracje g_1 dla x_0 = 10")
for i in range(1, 10):
    print(i, " - ", g_1(10, i))

print("\nKolejne iteracje f_2 dla x_0 = 10")
for i in range(1, 10):
    print(i, " - ", f_2(10, i))

print("\nKolejne iteracje g_2 dla x_0 = 10")
for i in range(1, 10):
    print(i, " - ", g_2(10, i))
