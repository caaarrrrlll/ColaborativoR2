#include <stdio.h>
#include "funciones.h"

int main() {
    char nombres[MAX_PRODUCTOS][MAX_NOMBRE];
    float precios[MAX_PRODUCTOS];
    int cantidades[MAX_PRODUCTOS];
    int numProductos = 0;

    char cedulas[MAX_CLIENTES][MAX_CEDULA];
    char nombresClientes[MAX_CLIENTES][MAX_NOMBRE];
    int numClientes = 0;

    char fechas[MAX_FACTURAS][MAX_FECHA];
    float valoresPagados[MAX_FACTURAS];
    int cantidadesProductos[MAX_FACTURAS];
    int numFacturas = 0;

    char opcion_str[MAX_OPCION];
    char opcion;

    do {
        mostrarMenu();
        printf("Ingrese su opcion: ");
        if (scanf(" %c", &opcion) != 1) {
            printf("Error al leer la opcion. Inténtelo de nuevo.\n");
            while (getchar() != '\n'); // Limpiar el búfer de entrada
            continue;
        }

        opcion_str[0] = opcion;

        switch (opcion) {
            case '1':
                mostrarProductos(nombres, precios, cantidades, numProductos);
                break;
            case '2':
                agregarProducto(nombres, precios, cantidades, &numProductos);
                break;
            case '3':
                editarProductos(nombres, precios, cantidades, &numProductos);
                break;
            case '4':
                eliminarProductos(nombres, precios, cantidades, &numProductos);
                break;
            case '5':
                venderProductos(nombres, precios, cantidades, &numProductos);
                break;
            case '6':
                guardarEnArchivo(nombres, precios, cantidades, &numProductos);
                break;
            case '7':
                ingresarCliente(cedulas, nombresClientes, &numClientes);
                break;
            case '8':
                modificarCliente(cedulas, nombresClientes, &numClientes);
                break;
            case '9':
                eliminarCliente(cedulas, nombresClientes, &numClientes);
                break;
            case 10:
                listarClientes(cedulas, nombresClientes, numClientes);
                break;
            case 11:
                facturar(fechas, cedulas, nombresClientes, valoresPagados, cantidadesProductos, &numFacturas);
                break;
            case 12:
                buscarFactura(fechas);
                break;
            case 13:
                listarFacturas(fechas, cedulas, valoresPagados, cantidadesProductos, &numFacturas);
                break;
            case 14:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida. Intentelo de nuevo.\n");
        }

    } while (opcion != 14);

    return 0;
}

