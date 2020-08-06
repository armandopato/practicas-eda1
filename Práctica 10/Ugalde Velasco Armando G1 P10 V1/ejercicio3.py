# -*- coding: utf-8 -*-
"""
Editor de Spyder

Este es un archivo temporal.
"""

def promedio(lista):
    return sum(lista) / len(lista)

def toStr(num):
    return str(round(num, 2))

tareas = []
examenes = []
practicas = []

for i in range(5):
    tareas.append( float(input("Introduzca la calificación de la tarea " + str(i+1) + ": ")) )
    
for i in range(4):
    examenes.append( float(input("Introduzca la calificación del examen " + str(i+1) + ": ")) )
    
for i in range(5):
    practicas.append( float(input("Introduzca la calificación de la practica " + str(i+1) + ": ")) )
    
promedioTareas = promedio(tareas)
promedioExamenes = promedio(examenes)
promedioPracticas = promedio(practicas)
califInicial = promedioExamenes*0.6 + promedioPracticas*0.4
califFinal = califInicial

if promedioTareas > 8.5:
    califFinal += 0.5
    
elif promedioTareas <= 7:
    califFinal -= 0.5
    
print("\nTu promedio de exámenes fue de " + toStr(promedioExamenes))
print("Tu promedio de laboratorio fue de " + toStr(promedioPracticas))
print("Tu calificación inicial es de " + toStr(califInicial))
print("Tu calificación de tareas es de " + toStr(promedioTareas) + ", por lo tanto tu calificación final es de " + toStr(califFinal))

