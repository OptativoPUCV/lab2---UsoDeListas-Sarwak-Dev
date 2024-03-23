#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

//#include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) {
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

/* 
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List* crea_lista() {
   List* L = create_list();

  for (int i = 0; i < 10; i++) {
    int* dato = (int*)malloc(sizeof(int));
    *dato = i + 1;
    pushBack(L, dato);
  }
   return L;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *L) {

  int suma = 0;  
  int size = get_size(L);

  int* dato = (int*)first(L);
  
  for (int i = 0; i < size; i++) {
    suma += *dato;
    dato = (int*)next(L);
  }
  
   return suma;
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List *L, int elem) {
    int size = get_size(L);
    int i = 0;
    int *dato = (int*)first(L);

    while (i < size) {
        if (*dato == elem) {
            popCurrent(L);
            
            if (i < size - 1) 
                dato = (int*)next(L);
            size--; 
        } 
          
        else {
          dato = (int*)next(L);
          i++; 
        }
    }
}




/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2) {

  Stack* P3 = create_stack();
  void* dato;
  while ((dato = pop(P1)) != NULL) {
    push(P3, dato);
  }
  while ((dato = top(P3)) != NULL) {
    push(P1, dato);
    push(P2, dato);
    pop(P3);
  }
}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena) {
    int count = 0;
    Stack* P = create_stack();
    char dato;

    while (cadena[count] != '\0') {
        if (cadena[count] == '(' || cadena[count] == '[' || cadena[count] == '{') {
            // Si encontramos un paréntesis de apertura, lo apilamos en la pila
            dato = cadena[count];
            push(P, &dato);
        } else if (cadena[count] == ')' || cadena[count] == ']' || cadena[count] == '}') {
            // Si encontramos un paréntesis de cierre, verificamos si coincide con el tope de la pila
            if (P == NULL) {
                // Si la pila está vacía y encontramos un paréntesis de cierre, la cadena no está balanceada
                return 0;
            }
            char top_char = *(char*)top(P);
            if ((cadena[count] == ')' && top_char != '(') ||
                (cadena[count] == ']' && top_char != '[') ||
                (cadena[count] == '}' && top_char != '{')) {
                // Si el paréntesis de cierre no coincide con el tope de la pila, la cadena no está balanceada
                return 0;
            }
            // Si coincide, desapilamos el paréntesis de apertura correspondiente
            pop(P);
        }
        count++;
    }

    // Al final, si la pila está vacía, significa que todos los paréntesis están balanceados
    if (P == NULL) {
        return 1;
    } else {
        return 0;
    }
}
