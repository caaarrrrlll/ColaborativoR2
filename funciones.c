#include <stdio.h>
#include <string.h>
#include "funciones.h"

// Variables globales
char nombres[MAX_PRODUCTOS][MAX_NOMBRE];
float precios[MAX_PRODUCTOS];
int cantidades[MAX_PRODUCTOS];
int numProductos = 0;

char cedulas[MAX_CLIENTES][MAX_CEDULA];
char nombresClientes[MAX_CLIENTES][MAX_NOMBRE];
int numClientes = 0;

char fechas[MAX_FACTURAS][MAX_FECHA];
char cedulasFacturas[MAX_FACTURAS][MAX_CEDULA];
char nombresClientesFacturas[MAX_FACTURAS][MAX_NOMBRE];
float valoresPagados[MAX_FACTURAS];
int cantidadesProductos[MAX_FACTURAS];
int numFacturas = 0;

void mostrarMenu(){
    printf("==== Menu ====\n");
    printf("1. Mostrar productos\n");
    printf("2. Agregar producto\n");
    printf("3. Editar producto\n");
    printf("4. Eliminar producto\n");
    printf("5. Vender producto\n");
    printf("6. Guardar en archivo\n");
    printf("7. Ingresar Cliente\n");
    printf("8. Modificar Cliente\n");
    printf("9. Eliminar Cliente\n");
    printf("10. Listar Clientes\n");
    printf("11. Facturar\n");
    printf("12. Buscar Factura\n");
    printf("13. Listar Factura\n");
    printf("14. Salir del Programa\n");
    printf("Ingrese su opcion: ");
}

void mostrarProductos(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], float precios[MAX_PRODUCTOS], int cantidades[MAX_PRODUCTOS], int numProductos){
    printf("\n*** Lista de productos ***\n");
    if (numProductos == 0) {
        printf("No hay productos en el inventario.\n");
        return;
    }

    for (int i = 0; i < numProductos; i++) {
        printf("%d. %s - Precio: %.2f - Cantidad: %d\n", i + 1, nombres[i], precios[i], cantidades[i]);
    }
}

void guardarEnArchivo(const char nombres[MAX_PRODUCTOS][MAX_NOMBRE], const float precios[MAX_PRODUCTOS], const int cantidades[MAX_PRODUCTOS], int *numProductos){
    FILE *archivo = fopen("Inventario.txt", "w");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo para escritura.\n");
        return;
    }

    for (int i = 0; i < *numProductos; i++) {
        fprintf(archivo, "%s %.2f %d\n", nombres[i], precios[i], cantidades[i]);
    }

    fclose(archivo);
}

void agregarProducto(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], float precios[MAX_PRODUCTOS], int cantidades[MAX_PRODUCTOS], int *numProductos){
    if (*numProductos < MAX_PRODUCTOS) {
        printf("Ingrese el nombre del producto: ");
        scanf("%s", nombres[*numProductos]);
        printf("Ingrese el precio del producto: ");
        scanf("%f", &precios[*numProductos]);
        printf("Ingrese la cantidad en inventario: ");
        scanf("%d", &cantidades[*numProductos]);

        (*numProductos)++;
        printf("Producto agregado con exito.\n");
    } else {
        printf("El inventario está lleno. No se puede agregar mas productos.\n");
    }
}

void editarProductos(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], float precios[MAX_PRODUCTOS], int cantidades[MAX_PRODUCTOS], int *numProductos){
    printf("\n*** Editar producto ***\n");
    if (*numProductos == 0) {
        printf("No hay productos en el inventario.\n");
        return;
    }
    mostrarProductos(nombres, precios, cantidades, *numProductos);

    int seleccion;
    printf("Seleccione el número del producto que desea editar: ");
    scanf("%d", &seleccion);

    if (seleccion >= 1 && seleccion <= *numProductos) {
        printf("Ingrese el nuevo nombre del producto: ");
        scanf("%s", nombres[seleccion - 1]);
        printf("Ingrese el nuevo precio del producto: ");
        scanf("%f", &precios[seleccion - 1]);
        printf("Ingrese la nueva cantidad en inventario: ");
        scanf("%d", &cantidades[seleccion - 1]);
        printf("Producto editado con éxito.\n");
    } else {
        printf("Número de producto no válido.\n");
    }
}

void eliminarProductos(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], float precios[MAX_PRODUCTOS], int cantidades[MAX_PRODUCTOS], int *numProductos){
    printf("\n*** Eliminar producto ***\n");
    if (*numProductos == 0) {
        printf("No hay productos en el inventario.\n");
        return;
    }
    mostrarProductos(nombres, precios, cantidades, *numProductos);

    int seleccion;
    printf("Seleccione el número del producto que desea eliminar: ");
    scanf("%d", &seleccion);

    if (seleccion >= 1 && seleccion <= *numProductos) {
        for (int i = seleccion - 1; i < *numProductos - 1; i++) {
            strcpy(nombres[i], nombres[i + 1]);
            precios[i] = precios[i + 1];
            cantidades[i] = cantidades[i + 1];
        }
        (*numProductos)--;

        printf("Producto eliminado con éxito.\n");
    } else {
        printf("Número de producto no válido.\n");
    }
}

void venderProductos(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], float precios[MAX_PRODUCTOS], int cantidades[MAX_PRODUCTOS], int *numProductos){
    printf("\n*** Vender productos ***\n");
    if (*numProductos == 0) {
        printf("No hay productos en el inventario.\n");
        return;
    }

    mostrarProductos(nombres, precios, cantidades, *numProductos);

    int seleccion;
    printf("Seleccione el número del producto que desea vender: ");
    scanf("%d", &seleccion);

    if (seleccion >= 1 && seleccion <= *numProductos) {
        int cantidadVender;
        printf("Ingrese la cantidad que desea vender: ");
        scanf("%d", &cantidadVender);

        if (cantidadVender > 0 && cantidadVender <= cantidades[seleccion - 1]) {
            cantidades[seleccion - 1] -= cantidadVender;
            printf("Venta realizada con éxito. Total a pagar: %.2f\n", precios[seleccion - 1] * cantidadVender);
        } else {
            printf("Cantidad no válida o insuficiente en inventario.\n");
        }
    } else {
        printf("Número de producto no válido.\n");
    }
}

void ingresarCliente(char cedulas[MAX_CLIENTES][MAX_CEDULA], char nombresClientes[MAX_CLIENTES][MAX_NOMBRE], int *numClientes){
    if (*numClientes < MAX_CLIENTES) {
        char nuevaCedula[MAX_CEDULA];
        printf("Ingrese la cédula del cliente: ");
        scanf("%s", nuevaCedula);
        // Validar que la cédula sea válida (simplemente verifica la longitud aquí)
        if (strlen(nuevaCedula) != 10) {
            printf("La cédula no es válida. Debe tener 10 dígitos.\n");
            return;
        }
        // Verificar si la cédula ya existe
        for (int i = 0; i < *numClientes; i++) {
            if (strcmp(cedulas[i], nuevaCedula) == 0) {
                printf("Ya existe un cliente con esa cédula. Inténtelo de nuevo.\n");
                return;
            }
        }

        printf("Ingrese el nombre del cliente: ");
        scanf("%s", nombresClientes[*numClientes]);

        strcpy(cedulas[*numClientes], nuevaCedula);

        (*numClientes)++;
        printf("Cliente ingresado con éxito.\n");
    } else {
        printf("Límite de clientes alcanzado. No se puede ingresar más clientes.\n");
    }
}


void modificarCliente(char cedulas[MAX_CLIENTES][MAX_CEDULA], char nombresClientes[MAX_CLIENTES][MAX_NOMBRE], int *numClientes){
    char cedulaModificar[MAX_CEDULA];
    printf("Ingrese la cédula del cliente que desea modificar: ");
    scanf("%s", cedulaModificar);

    // Buscar la cédula en el listado de clientes
    int indiceCliente = -1;
    for (int i = 0; i < *numClientes; i++) {
        if (strcmp(cedulas[i], cedulaModificar) == 0) {
            indiceCliente = i;
            break;
        }
    }

    if (indiceCliente != -1) {
        printf("Ingrese el nuevo nombre del cliente: ");
        scanf("%s", nombresClientes[indiceCliente]);
        printf("Cliente modificado con éxito.\n");
    } else {
        printf("No se encontró ningún cliente con la cédula ingresada.\n");
    }
}

void eliminarCliente(char cedulas[MAX_CLIENTES][MAX_CEDULA], char nombresClientes[MAX_CLIENTES][MAX_NOMBRE], int *numClientes){
    char cedulaEliminar[MAX_CEDULA];
    printf("Ingrese la cédula del cliente que desea eliminar: ");
    scanf("%s", cedulaEliminar);

    int indiceEliminar = -1;
    for (int i = 0; i < *numClientes; i++) {
        if (strcmp(cedulas[i], cedulaEliminar) == 0) {
            indiceEliminar = i;
            break;
        }
    }

    if (indiceEliminar != -1) {
        // Eliminar cliente moviendo los elementos restantes del array
        for (int i = indiceEliminar; i < *numClientes - 1; i++) {
            strcpy(cedulas[i], cedulas[i + 1]);
            strcpy(nombresClientes[i], nombresClientes[i + 1]);
        }

        (*numClientes)--;
        printf("Cliente eliminado con éxito.\n");
    } else {
        printf("No se encontró ningún cliente con la cédula ingresada.\n");
    }
}

void listarClientes(char cedulas[MAX_CLIENTES][MAX_CEDULA], char nombresClientes[MAX_CLIENTES][MAX_NOMBRE], int numClientes){
    printf("\n*** Listado de Clientes ***\n");
    if (numClientes == 0) {
        printf("No hay clientes registrados.\n");
        return;
    }

    for (int i = 0; i < numClientes; i++) {
        printf("Cédula: %s - Nombre: %s\n", cedulas[i], nombresClientes[i]);
    }
}


void facturar(char fechas[MAX_FACTURAS][MAX_FECHA], char cedulas[MAX_FACTURAS][MAX_CEDULA], char nombresClientes[MAX_FACTURAS][MAX_NOMBRE], float valoresPagados[MAX_FACTURAS], int cantidadesProductos[MAX_FACTURAS], int *numFacturas){
    if (*numFacturas < MAX_FACTURAS) {
        FILE *clientesFile = fopen("clientes.txt", "r"); // Abre el archivo de clientes en modo lectura

        if (clientesFile == NULL) {
            printf("Error al abrir el archivo de clientes.\n");
            return;
        }

        char cedulaCliente[MAX_CEDULA];
        printf("Ingrese la cédula del cliente: ");
        scanf("%s", cedulaCliente);

        // Validar la existencia del cliente con la cédula ingresada
        int clienteEncontrado = 0;
        char linea[MAX_CEDULA + MAX_NOMBRE];
        while (fgets(linea, sizeof(linea), clientesFile) != NULL) {
            char cedulaArchivo[MAX_CEDULA];
            sscanf(linea, "%s", cedulaArchivo);

            if (strcmp(cedulaArchivo, cedulaCliente) == 0) {
                clienteEncontrado = 1;
                break;
            }
        }

        fclose(clientesFile);

        if (!clienteEncontrado) {
            printf("No se encontró ningún cliente con la cédula ingresada. Factura no generada.\n");
            return;
        }

        // Resto de la lógica de facturación permanece igual, solo la validación de la cédula cambió

        printf("Ingrese el nombre del cliente: ");
        scanf("%s", nombresClientes[*numFacturas]);

        printf("Ingrese el valor pagado: ");
        scanf("%f", &valoresPagados[*numFacturas]);

        printf("Ingrese la cantidad de productos comprados: ");
        scanf("%d", &cantidadesProductos[*numFacturas]);

        (*numFacturas)++;
        printf("Factura generada con éxito.\n");
    } else {
        printf("Límite de facturas alcanzado. No se puede generar más facturas.\n");
    }
}


void buscarFactura(char fechas[MAX_FACTURAS][MAX_FECHA]){
    printf("\n*** Buscar Factura ***\n");

    if (numFacturas == 0) {
        printf("No hay facturas registradas.\n");
        return;
    }

    char fechaBusqueda[MAX_FECHA];
    printf("Ingrese la fecha de la factura que desea buscar (Formato: DD/MM/AAAA): ");
    scanf("%s", fechaBusqueda);

    int facturaEncontrada = 0;
    for (int i = 0; i < numFacturas; i++) {
        if (strcmp(fechas[i], fechaBusqueda) == 0) {
            printf("Fecha: %s - Cédula: %s - Nombre: %s - Valor Pagado: %.2f - Cantidad Productos: %d\n",
                   fechas[i], cedulas[i], nombresClientes[i], valoresPagados[i], cantidadesProductos[i]);
            facturaEncontrada = 1;
            break;
        }
    }

    if (!facturaEncontrada) {
        printf("No se encontró ninguna factura con la fecha ingresada.\n");
    }
}

void listarFacturas(char fechas[MAX_FACTURAS][MAX_FECHA], char cedulas[MAX_FACTURAS][MAX_CEDULA], float valoresPagados[MAX_FACTURAS], int cantidadesProductos[MAX_FACTURAS], int numFacturas){
    printf("\n*** Listado de Facturas ***\n");
    if (numFacturas == 0) {
        printf("No hay facturas registradas.\n");
        return;
    }

    for (int i = 0; i < numFacturas; i++) {
        printf("Fecha: %s - Cédula: %s - Nombre: %s - Valor Pagado: %.2f - Cantidad Productos: %d\n",
               fechas[i], cedulas[i], nombresClientes[i], valoresPagados[i], cantidadesProductos[i]);
    }
}
