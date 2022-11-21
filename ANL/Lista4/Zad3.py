def bisection(F, a, b, it):
    if F(a) * F(b) >= 0:
        print("Bisection method fails.")
        return None
    a_n = a
    b_n = b
    for i in range(1,it):
        m_n = (a_n + b_n) / 2.0
        if F(m_n) == 0:
            return m_n
        if F(a_n) * F(m_n) < 0:
            a_n = a_n
            b_n = m_n
        else:
            a_n = m_n
            b_n = b_n
        print("Iteration", i, " m_n :", m_n, "Wynik funkcji : ", F(m_n))
    return (a_n + b_n) / 2.0

def f(x):
    return x-0.49
iterations = 27
wynik=bisection(f, 0, 1, iterations)
print("Wynik bisekcji po ",iterations," krokach m_n : ",wynik, "f(m_n) : ", f(wynik))
