# -*- coding: utf-8 -*-
"""
Created on Wed Apr  1 12:55:31 2020

@author: armau
"""

numIntentos = 5
password = input("Introduzca la contraseña (" + str(numIntentos) + " intentos restantes): ")
numIntentos -= 1

while password != "edauno" and numIntentos > 0:
    password = input("Contraseña incorrecta. Introdúzcala de nuevo. (" + str(numIntentos) + " intentos restantes)\n")
    numIntentos -= 1
        
if numIntentos > 0:
    print("Has logrado ingresar")

else:
    print("Se ha agotado el número de intentos")