def cubo(n):
    if n > 0:
        print(n**3)
        cubo(n-1)

cubo(5)