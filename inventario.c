#include "inventario.h"


int validarCodigoDeBarras(char codigo[CODIGO]) {

    if( strlen(codigo) != CODIGO ) {
        return 0;
    }

    for( int i = 0 ; i < CODIGO ; i ++){
        if(codigo[i] != 48 && codigo[i] != 49){
            return 0;
        }
    }

    return 1;
}


int validarNumeroSerie(char codigo[CODIGO]) {
    if( strlen(codigo) != CODIGO ) {
        return 0;
    }

    for( int i = 0 ; i < CODIGO ; i ++){
        if ( codigo[i] < 48 || codigo[i] > 57 ) {
            return 0;
        }
    }

    return 1;
}

int validarAlfanumerico(char codigo[ALPHA]){
    if( strlen(codigo) != ALPHA ) {
        return 0;
    }

    for( int i = 0 ; i < ALPHA ; i ++){
        if ( !( (codigo[i] >= 48 && codigo[i] <= 57) ||
            (codigo[i] >= 65 && codigo[i] <= 90) ||
            (codigo[i] >= 97 && codigo[i] <= 122)) ) {
            return 0;
        }
    }

    return 1;
}




// Las funciones deberán definirse y recibir e implementar lo siguiente
// - addProduct: recibe un arreglo de productos y el numero actual de productos.
// Revisa que el numero actual de productos sea menor que el número máximo de
// productos y en caso de ser así, crea un nuevo producto y procede a preguntar al
// usuario por la información correspondiente a cada campo. Una vez llenados los
// datos, agregar el producto a la lista de productos existentes en la posición
// correspondiente. Al final regresa el numero actualizado de productos (es decir, el
// numero de productos que recibió +1).

int addProduct( Producto productos[MAX_PRODUCTS], int cantidadActual) {

    if( cantidadActual >= MAX_PRODUCTS) {
        printf("No se pueden agregar más productos\n");
        return cantidadActual;
    }


    // DATOS DEL PRODUCTO
    Producto productoNuevo;

    // ASIGNACIÓN DE TIPO DE IDENTIFICADOR A PRODUCTO
    do {
        printf("Opciones para tipo de Identificador: \n");
        printf("  1- Codigo de Barras.\n");
        printf("  2- Numero de serie.\n");
        printf("  3- Alfanumerico.\n");
        scanf("%i", &productoNuevo.tipodeidentificador);
    } while( productoNuevo.tipodeidentificador < 1 || productoNuevo.tipodeidentificador > 3 );


    // CAPTURA DE ID SEGUN TIPO DE IDENTIFICADOR
    switch (productoNuevo.tipodeidentificador)
    {
    case 1:
        // Validar Codigo de Barras
        do{
            printf("Ingresa el Codigo de Barras del Producto ( DEBE SER DE 10 CARACTERES ): ");
            scanf("%s", productoNuevo.id.codigoBarras);
        }while(!validarCodigoDeBarras(productoNuevo.id.codigoBarras));

        break;
    case 2:
        // Validar Numero de Serie
        do{
            printf("Ingresa el numero de serie del producto ( DEBE SER DE 10 CARACTERES ): ");
            scanf("%s", productoNuevo.id.numeroSerie);
        }while(!validarNumeroSerie(productoNuevo.id.numeroSerie));
        break;
    case 3:
        // Validar Alfanumerico
        do{
            printf("Ingresa el codigo alfanumerico ( DEBE SER DE 18 CARACTERES ): ");
            scanf("%s", productoNuevo.id.alfanumerico);
        }while(!validarAlfanumerico(productoNuevo.id.alfanumerico));
        break;
    default:
        break;
    }


    // CAPTURA DE CANTIDAD
    do {
        printf("Cantidad del Producto: ");
        scanf("%i\n", &productoNuevo.cantidad);
    }while(productoNuevo.cantidad <= 0);


    // CAPTURA DE NOMBRE
    printf("Nombre del Producto: ");
    scanf("%s\n", productoNuevo.nombre);

    // CAPTURA DE PRECIO
    do {
        printf("Precio del Producto: ");
        scanf("%f\n", &productoNuevo.precio);
    }while(productoNuevo.precio <= 0);


    // DATOS DE INFO ADICIONAL
    InfoAdicional infoProductoNuevo;


    // CAPTURA EL NOMBRE DE FABRICANTE DEL PRODUCTO
    printf("Fabricante del Producto: ");
    scanf("%s\n", infoProductoNuevo.fabricante);

    // CAPTURA LA CATEGORIA  DEL PRODUCTO
    printf("Categoria del Producto: ");
    scanf("%s\n", infoProductoNuevo.categoria);


    // ASIGNACIÓN DE INFO ADICIONAL A PRODUCTO NUEVO
    productoNuevo.infoAdicional = infoProductoNuevo;

    // ASIGNACIÓN DE PRODUCTO NUEVO A ARREGLO DE PRODUCTOS
    productos[cantidadActual] = productoNuevo;
    // AUMENTO DE CANTIDAD ACTUAL
    cantidadActual++;
    printf("Producto agregado correctamente\n");
    printf("Cantidad actual de productos: %i\n", cantidadActual);
    printf("--------------------------------------------------\n");
    return cantidadActual;

};

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


