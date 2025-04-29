#ifndef INVENTARIO_H
#define INVENTARIO_H
#define MAX_PRODUCTS 100
#define CODIGO 10
#define ALPHA 18
#include <stdio.h>
#include <string.h>

enum IDENTIFICADOR {
    CODIGO_BARRAS = 1,
    NUMERO_DE_SERIE,
    ALFANUMERICO
};


// Parte I
// Crea, implementa y utiliza tu propia librería que te permita llevar a cabo control de
// inventario de una tienda. Define y utiliza estructuras y uniones para definir los
// productos y sus características de la siguiente manera:

typedef union {
    // Falta especificación para implementación
    char codigoBarras[CODIGO];
    char numeroSerie[CODIGO];
    char alfanumerico[ALPHA];
} Identificador;

typedef struct {
    char fabricante[50];
    char categoria[30];
} InfoAdicional;

typedef struct {
    unsigned int tipodeidentificador;
    Identificador id;
    char nombre[50];
    float precio;
    unsigned int cantidad;
    InfoAdicional infoAdicional;
} Producto;


// Funciones De Apoyo

int validarCodigoDeBarras(char codigo[CODIGO]);
int validarNumeroSerie(char codigo[CODIGO]);
int validarAlfanumerico(char codigo[CODIGO]);


// Las funciones deberán definirse y recibir e implementar lo siguiente
// - addProduct: recibe un arreglo de productos y el numero actual de productos.
// Revisa que el numero actual de productos sea menor que el número máximo de
// productos y en caso de ser así, crea un nuevo producto y procede a preguntar al
// usuario por la información correspondiente a cada campo. Una vez llenados los
// datos, agregar el producto a la lista de productos existentes en la posición
// correspondiente. Al final regresa el numero actualizado de productos (es decir, el
// numero de productos que recibió +1).

int addProduct( Producto productos[MAX_PRODUCTS], int cantidadActual);

// - deleteProduct: recibe un arreglo de productos y el numero actual de productos.
// Solicita al usuario el ID del producto a eliminar y busca en el arreglo hasta
// encontrar el id correspondiente; en caso de ser encontrado, eliminar el producto
// moviendo los productos posteriores una posición hacia adelante y actualizar la
// cuenta de productos totales. En caso de no encontrar el producto, mostrar un
// mensaje indicándolo. Retornar el número de productos actual.

int deleteProduct( Producto productos[MAX_PRODUCTS], int cantidadActual);


// - searchProduct: recibe un arreglo de productos y el numero actual de
// productos. Solicita al usuario el id a buscar y revisa todos los productos
// existentes. En caso de encontrar un match, despliega en pantalla toda la
// información del producto. En caso contrario, informa que no se encontró el
// producto. La función no regresa nada.
void searchProduct( Producto productos[MAX_PRODUCTS], int cantidadActual);



// - listProducts: recibe la lista de productos y el numero total de productos
// actuales. Itera sobre cada producto y despliega toda la información de cada
// producto separando cada producto con “--------------------------------“ al final. No
// devuelve nada.
void listProducts( Producto productos[MAX_PRODUCTS], int cantidadActual);



// - generateReport: recibe la lista y numero actual de productos. Itera a través de
// todos los productos y obtiene el valor total del inventario a partir del costo por
// unidad de cada producto y la cantidad existente de cada uno. Al final despliega en
// pantalla el valor total y el producto mas caro junto con su valor. La función no
// devuelve nada.

void generateReport( Producto productos[MAX_PRODUCTS], int cantidadActual);




#endif