import numpy as np
import matplotlib.pyplot as plt

def s(tab1, tab2, k, n, x):
    h = tab1[k] - tab1[k-1] #h_k
    a = 1/6 * M(tab1,tab2,k-1,n) * (tab1[k] - x)**3
    b = 1/6 * M(tab1,tab2,k,n) * (x - tab1[k-1])**3
    c = (tab2[k-1] - 1/6 * M(tab1,tab2,k-1,n) * (h)**2) * (tab1[k] - x)
    d = (tab2[k] - 1/6 * M(tab1,tab2,k,n) * (h)**2) * (x - tab1[k-1])
    
    return h**(-1) *(a + b + c + d)

def M(tab1,tab2, k, n):
    if (k == n - 1):
        return u(tab1,tab2,k,n)
    elif (k >= 1 and k <= n - 2):
        return u(tab1,tab2,k,n) + (q(tab1,tab2,k,n)*M(tab1,tab2,k+1,n))

def u(tab1,tab2, k, n):
    if(k==0):
        return 0
    elif (k <= n - 1 and k >= 1):
        return (d(tab1,tab2,k,n) - u(tab1,tab2,k-1,n)*lbda(tab1,tab2,k,n))/p(tab1,tab2,k,n)

def lbda(tab1,tab2, k, n):
    if(k >= 1 and k <= n - 1):
        return (tab1[k] - tab1[k-1])/(tab1[k+1] - tab1[k-1])# tab1[k] sie skracaja
    else:
        print("poza zakresem lbda k: ", k)
        return 0

def p(tab1,tab2, k, n):
    if(k >= 1 and k <= n - 1):
        return lbda(tab1,tab2,k,n)*q(tab1,tab2,k-1,n) + 2

def q(tab1,tab2, k, n):
    if(k==0):
        return 0
    elif(k >= 1 and k <= n - 1):
        return (lbda(tab1,tab2,k,n) - 1)/p(tab1,tab2,k,n)

def d(tab1,tab2, k, n):
    if(k >= 1 and k <= n - 1):
        return 6*(f(tab1,tab2,k,n) - f(tab1,tab2,k-1,n))/(tab1[k+1]-tab1[k-1])
    else:
        print("poza zakresem d k: ", k)
        return 0

def f(tab1,tab2, k, n):
    if(k >= 0 and k <= n - 1):
        return (tab2[k+1] - tab2[k])/(tab1[k+1] - tab1[k])
    #return (tab2[k+1] - tab2[k])/(tab1[k+1] - tab1[k])

def S(tab1, tab2, n, iks):
    k = 0
    while (k < n):
        if (tab1[k] <= iks and iks <= tab1[k+1]):
            return s(tab1,tab2,k,n,iks)
        else:
            k+=1
    return 0
#funkcja wezmie przedzial [a,b] wezmie wzor i dla x e[a,b] policzy wartosc y
def funkcja(a,b,wzor,diff):
    i=a
    wynik = np.array([], dtype=np.float64)
    while(i<b):
        wynik = np.append(wynik, wzor(i))
        i+=diff
    return wynik

x_cords = np.array([58, 46, 46.5, 48.1, 48.2, 47, 49.1, 50, 49], dtype=np.float64)
y_cords = np.array([233, 219, 200, 183, 164, 144, 125, 110, 99], dtype=np.float64)
t_cords = np.array([1, 2, 3, 4, 5, 6, 7, 8, 9], dtype=np.float64)
x_result = np.array([], dtype=np.float64)
y_result = np.array([], dtype=np.float64)
for i in range(1, len(x_cords)):
    j=t_cords[i-1]
    while(j<t_cords[i]):
        x_result = np.append(x_result, j)
        y_result = np.append(y_result, s(t_cords, x_cords, i, len(t_cords), j))
        j+=0.01
#xt_result = np.array([], dtype=np.float64)
#yt_result = np.array([], dtype=np.float64)
#t_cords = np.linspace (-10, 10,num=1000, dtype=np.float64)

for i in x_cords:
    print("i: ", i," ", S(x_cords, y_cords, len(x_cords), 1),"\n")
    #xt_result = np.append(xt_result, S(t_cords, x_cords, len(t_cords), 1))
    #yt_result = np.append(yt_result, S(t_cords, y_cords, len(t_cords), 1))

plt.plot(x_result,y_result)# (S_x(t), S_y(t))
plt.show()