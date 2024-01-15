#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAX_PRODUCTOS 100
#define MAX_NOMBRE 50
#define MAX_CLIENTES 100
#define MAX_FACTURAS 100
#define MAX_FECHA 11  // "DD/MM/AAAA" (incluyendo el carácter nulo)
#define MAX_CEDULA 12 // una cédula tiene 11 dígitos 

#define MAX_OPCION 2 //Maximo de opciones 

void mostrarMenu();

void mostrarProductos(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], float precios[MAX_PRODUCTOS], int cantidades[MAX_PRODUCTOS], int numProductos);
void agregarProducto(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], float precios[MAX_PRODUCTOS], int cantidades[MAX_PRODUCTOS], int *numProductos);
void editarProductos(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], float precios[MAX_PRODUCTOS], int cantidades[MAX_PRODUCTOS], int *numProductos);
void eliminarProductos(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], float precios[MAX_PRODUCTOS], int cantidades[MAX_PRODUCTOS], int *numProductos);
void venderProductos(char nombres[MAX_PRODUCTOS][MAX_NOMBRE], float precios[MAX_PRODUCTOS], int cantidades[MAX_PRODUCTOS], int *numProductos);
void guardarEnArchivo(const char nombres[MAX_PRODUCTOS][MAX_NOMBRE], const float precios[MAX_PRODUCTOS], const int cantidades[MAX_PRODUCTOS], int *numProductos);
void ingresarCliente(char cedulas[MAX_CLIENTES][MAX_CEDULA], char nombresClientes[MAX_CLIENTES][MAX_NOMBRE], int *numClientes);
void modificarCliente(char cedulas[MAX_CLIENTES][MAX_CEDULA], char nombresClientes[MAX_CLIENTES][MAX_NOMBRE], int *numClientes);
void eliminarCliente(char cedulas[MAX_CLIENTES][MAX_CEDULA], char nombresClientes[MAX_CLIENTES][MAX_NOMBRE], int *numClientes);
void listarClientes(char cedulas[MAX_CLIENTES][MAX_CEDULA], char nombresClientes[MAX_CLIENTES][MAX_NOMBRE], int numClientes);
void facturar(char fechas[MAX_FACTURAS][MAX_FECHA], char cedulas[MAX_FACTURAS][MAX_CEDULA], char nombresClientes[MAX_FACTURAS][MAX_NOMBRE], float valoresPagados[MAX_FACTURAS], int cantidadesProductos[MAX_FACTURAS], int *numFacturas);
void buscarFactura(char fechas[MAX_FACTURAS][MAX_FECHA]);
void listarFacturas(char fechas[MAX_FACTURAS][MAX_FECHA], char cedulas[MAX_FACTURAS][MAX_CEDULA], float valoresPagados[MAX_FACTURAS], int cantidadesProductos[MAX_FACTURAS], int numFacturas)


#endif // FUNCIONES_H