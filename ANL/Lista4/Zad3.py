def bisection(F, a, b, eps):
    if F(a) * F(b) >= 0:
        print("Bisection method fails.")
        return None
    a_n = a
    b_n = b
    n = 0
    while (b_n - a_n) / 2.0 > eps:
        m_n = (a_n + b_n) / 2.0
        if F(m_n) == 0:
            return m_n
        if F(a_n) * F(m_n) < 0:
            a_n = a_n
            b_n = m_n
        else:
            a_n = m_n
            b_n = b_n
        n += 1
    return (a_n + b_n) / 2.0
print()