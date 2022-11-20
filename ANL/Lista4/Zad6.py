def f(x_0, a, iteracje):
    wynik = x_0
    for i in range(iteracje):
        wynik = (wynik*(3-(a*(wynik**2))))/2
    return wynik


print("Kolejne iteracje dla x_0 = 0.2; a = 4")
for i in range(1, 10):
    print(i, " - ", f(0.2, 4, i))

print("\nKolejne iteracje dla x_0 = 0.2; a = 9")
for i in range(1, 10):
    print(i, " - ", f(0.2, 9, i))

print("\nKolejne iteracje dla x_0 = 0.2; a = 16")
for i in range(1, 10):
    print(i, " - ", f(0.2, 16, i))

print("\nKolejne iteracje dla x_0 = 0.1; a = 36")
for i in range(1, 10):
    print(i, " - ", f(0.1, 36, i))