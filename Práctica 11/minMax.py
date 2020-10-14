def funcion1(L):
    if L == []:
        return 1
    elif len(L) == 1:
        return L[0]
    else:
        return L[0] * funcion1(L[1:])
    
lista1 = [1, 2, 3, 4, 5, 6, 7, 8]
lista2 = funcion1(lista1)
print(lista2)