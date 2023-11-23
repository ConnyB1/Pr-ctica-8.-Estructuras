/*
Nombre del archivo: Practica8.cpp
Autor: Cesar Alejandro Velazquez Mercado
Fecha de creación: 22 de noviembre de 2023
Descripción: Guarda los registros de una tienda  
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"

typedef struct _Producto 
{
    char nombre[50];
    int cantidad;
    float precio;
} reg;

void agregarProducto(reg inventario[], int *numProductos, int capacidad);
void retirarProducto(reg inventario[], int *numProductos);
void mostrarInventario(reg inventario[], int numProductos);
void calcularValorTotal(reg inventario[], int numProductos);
void ordenarPorNombre(reg inventario[], int numProductos);
void ordenarPorCantidad(reg inventario[], int numProductos);
void ordenarPorPrecio(reg inventario[], int numProductos);
void ordenarElementos(reg inventario[], int n, int criterio);
int estaOrdenado(reg inventario[], int n, int criterio);


int main() 
{
    int capacidad = 10, numProductos = 0, opcion;
    reg inventario[capacidad];

    do 
    {
        printf("\nMenú:\n");
        printf("1. Agregar producto\n");
        printf("2. Retirar producto\n");
        printf("3. Mostrar inventario\n");
        printf("4. Calcular valor total del inventario\n");
        printf("5. Ordenar inventario\n");
        printf("0. Salir\n");
        printf("Ingrese su opción: ");
        opcion = valinum(0,5);

        if (opcion == 1) 
        {
            agregarProducto(inventario, &numProductos, capacidad);
        }
        else
        {
            if (opcion == 2) 
            {
                retirarProducto(inventario, &numProductos);
            }
            else
            {
                if (opcion == 3) 
                {
                    mostrarInventario(inventario, numProductos);
                }
                else
                {
                    if (opcion == 4) 
                    {
                        calcularValorTotal(inventario, numProductos);
                    }
                    else
                    {
                        if (opcion == 5) 
                        {
                            printf("Que quieres hacer?\n");
                            printf("1) ordenar por nombre, 2) ordenar por cantidad, 3)ordenar por precio: ");
                            int op = valinum(1, 3);
                            ordenarElementos(inventario, numProductos, op);
                        }
                        else
                        {
                            if (opcion == 0) 
                            {
                                printf("Adios\n");
                            }
                        }
                    }
                }
            }
        }
    } while (opcion != 0);

    return 0;
}

void agregarProducto(reg inventario[], int *numProductos, int capacidad) 
{
    if (*numProductos < capacidad) 
    {
        printf("Ingrese el nombre del producto: ");
        leercadena(inventario[*numProductos].nombre, sizeof(inventario[*numProductos].nombre));
        printf("\n");
        printf("Ingrese la cantidad del producto: ");
        inventario[*numProductos].cantidad = valinum(0, 10000);
        printf("\n");
        printf("Ingrese el precio del producto: ");
        inventario[*numProductos].precio = valinum(0, 10000);
        printf("\n");
        (*numProductos)++;
        printf("Producto agregado con éxito.\n");
    } 
    else 
    {
        printf("El inventario está lleno. No se pueden agregar más productos.\n");
    }
}

void retirarProducto(reg inventario[], int *numProductos) 
{
    char nombreBuscado[50];
    printf("Ingrese el nombre del producto que desea retirar: ");
    scanf("%s", nombreBuscado);

    int i, encontrado = 0;
    for (i = 0; i < *numProductos; i++) 
    {
        if (strcmp(inventario[i].nombre, nombreBuscado) == 0) 
        {
            for (int j = i; j < (*numProductos - 1); j++) 
            {
                inventario[j] = inventario[j + 1];
            }
            (*numProductos)--;
            encontrado = 1;
            printf("Producto retirado con éxito.\n");
            break;
        }
    }

    if (!encontrado) 
    {
        printf("El producto no se encuentra en el inventario.\n");
    }
}

void mostrarInventario(reg inventario[], int numProductos) 
{
    printf("Inventario:\n");
    for (int i = 0; i < numProductos; i++) 
    {
        printf("Nombre: %s, Cantidad: %d, Precio: %.2f\n", inventario[i].nombre, inventario[i].cantidad, inventario[i].precio);
    }
}

void calcularValorTotal(reg inventario[], int numProductos) 
{
    float valorTotal = 0.0;
    for (int i = 0; i < numProductos; i++) 
    {
        valorTotal += inventario[i].cantidad * inventario[i].precio;
    }
    printf("Valor total del inventario: %.2f\n", valorTotal);
}


void ordenarElementos(reg inventario[], int n, int criterio) 
{
    switch (criterio) 
    {
        case 1:
            ordenarPorNombre(inventario, n);
            printf("El inventario ha sido ordenado por nombre.\n");
            break;
        case 2:
            ordenarPorCantidad(inventario, n);
            printf("El inventario ha sido ordenado por cantidad.\n");
            break;
        case 3:
            ordenarPorPrecio(inventario, n);
            printf("El inventario ha sido ordenado por precio.\n");
            break;

    }
}

void intercambiar(reg *a, reg *b) 
{
    reg temp = *a;
    *a = *b;
    *b = temp;
}

void ordenarPorNombre(reg inventario[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (strcmp(inventario[j].nombre, inventario[j + 1].nombre) > 0) 
            {
                intercambiar(&inventario[j], &inventario[j + 1]);
            }
        }
    }
}

void ordenarPorCantidad(reg inventario[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (inventario[j].cantidad > inventario[j + 1].cantidad) 
            {
                intercambiar(&inventario[j], &inventario[j + 1]);
            }
        }
    }
}

void ordenarPorPrecio(reg inventario[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (inventario[j].precio > inventario[j + 1].precio) 
            {
                intercambiar(&inventario[j], &inventario[j + 1]);
            }
        }
    }
}