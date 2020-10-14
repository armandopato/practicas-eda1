def funcion3(L,n):
    if n == 1:
        return L[0]
    else:
        return L[0] + funcion3(L[1:], n-1)

lista1 = [1, 2, 3, 4, 5, 6, 7, 8]
# Parametro corregido: se agregó n (longitud de arreglo)
lista2 = funcion3(lista1, len(lista1))
print(lista2)