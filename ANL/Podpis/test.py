import numpy as np
import matplotlib.pyplot as plt
print('test')
def f(tab1):
    return tab1**2

def funkcja(a,b,wzor):
    i=a
    wynik = np.array([], dtype=np.float64)
    while(i<b):
        wynik = np.append(wynik, wzor(i))
        i+=0.02
    return wynik

x_cords = np.linspace (-10, 10,num=1010, dtype=np.float64)
print(len(x_cords))
#y_cords = np.array([233, 219, 200, 183, 164, 144, 125, 110, 99], dtype=np.float64)
t_cords = np.array([0, 1, 2, 3, 4, 5, 6, 7, 8], dtype=np.float64)
#result = np.array( [None] * len(x_cords), dtype=np.float64)
y_list = np.array(f(x_cords), dtype=np.float64)
#y_list2 = np.array([], dtype=np.float64)
y_list2 = funkcja(-10, 10, f)
y_list2 = np.append(y_list2, t_cords)
#################################
#iter = -10
#while(iter<10):
#    y_list2 = np.append(y_list2, f(iter))
#    iter+=0.02
#################################
print(len(y_list2))
print(y_list2)
plt.plot(x_cords, y_list2)# (S_x(t), S_y(t))
plt.show()
"""
import numpy as np
import matplotlib.pyplot as plt

def x(k):
    if (k>= len(x_cords)):
        print("poza tablica x_cords k :",k)
        return 0
    print("x_cords[k]: ", x_cords[k], "\n")
    return x_cords[k]

def y(k):
    if (k>= len(y_cords)):
        print("poza tablica y_cords k :",k)
        return 0
    print("y_cords[k]: ", y_cords[k], "\n")
    return y_cords[k]
#######################################################################
def lbda(k):
    if(k >= 1 and k <= N):
        return h(k)/(h(k)+h(k+1))
    else:
        print("poza zakresem lbda k: ", k)
        return 0
def h(k):
    if(k >= 1 and k <= N):
        return x(k)-x(k-1)
    else:
        print("poza zakresem h k: ", k)
        return 0

def f(a,b): # iloraz roznicowy
    print("a: ", a, ", b: ", b, "\n")
    if(a < 0 or b > N):
        print("poza zakresem f a: ", a, ", b: ", b, "\n")
        return 0
    else:
        return (y(b) - y(a))/(x(b)-x(a))

def d(k):
    if(k<1 or k>=N):
        print("poza zakresem d k: ", k)
        return 0
    else:
        return 6*(f(k, k+1) - f(k-1, k))/(x(k+1)-x(k-1))

def q(k):
    if(k==0):
        return 0
    elif(k < 1 or k >= N):
        return (lbda(k) - 1)/p(k)
    else:
        print("poza zakresem q k: ", k)
        return 0

def p(k):
    if(k < 1 or k >= N):
        return lbda(k)*q(k-1)+2
    else:
        print("poza zakresem p k: ", k)
        return 0

def u(k):
    if(k==0):
        return 0
    elif(k < 1 or k >= N):
        return (d(k)-lbda(k)*u(k-1))/p(k)
    else:
        print("poza zakresem u k: ", k)
        return 0 

def M(k):
    if (k==0 or k==N):
        print("poza zakresem M k: ", k)
        return 0
    if(k==N-1):
        return u(N-1)
    else:
        return u(k)+q(k)*M(k+1)


def s(k, iks):
    print("k: ", k, ", n: ", N, ", x: ", iks, "\n")
    a = 1/6 * M(k-1)* (x(k) - iks)**3
    b = 1/6 * M(k) * (iks - x(k-1))**3
    c = (y(k-1) - 1/6 * M(k-1) * h(k)**2) * (x(k) - iks)
    d = (y(k) - 1/6 * M(k) * h(k)**2) * (iks - x(k-1))
    return h(k)**(-1) * (a + b + c + d)

def Sx(iks):
    print("x: ", iks, "n: ", N, "\n")
    for k in range(1, N):
        if(x(k-1) <= iks and iks <= x(k)):
            return s(k, iks)
      
def Sy(iks):
    print("y: ", iks, "n: ", N, "\n")
    for k in range(1, N):
        if(y(k-1) <= iks and iks <= y(k)):
            return s(k, iks)
#def S_x(t):
#    return S(t, len(x_cords))
#def S_y(t):
#    return S(t, len(y_cords))
x_cords = np.array ([58, 46, 46.5, 48.1, 48.2, 47, 49.1, 50, 49], dtype=np.float64)
y_cords = np.array([233, 219, 200, 183, 164, 144, 125, 110, 99], dtype=np.float64)
t_cords = np.array([0, 1, 2, 3, 4, 5, 6, 7, 8], dtype=np.float64)
resultx = np.array( [0] * len(x_cords), dtype=np.float64)
resulty = np.array( [0] * len(y_cords), dtype=np.float64)
N=len(x_cords)-1
for i in range(len(x_cords)):
    Sx(x_cords[i])
    print("resultx[i]: ", resultx[i], "\n")
    Sy(y_cords[i])
    print("resulty[i]: ", resulty[i], "\n") 

"""