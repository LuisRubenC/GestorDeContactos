#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nombre[50];
    char telefono[15];
    char correo[50];
} Contacto;

Contacto contactos[100];
int totalContactos = 0;

void guardarContactos();
void cargarContactos();
void agregarContacto();
void mostrarContactos();
void buscarContacto();
void eliminarContacto();

int main() {
    int opcion;
    cargarContactos();  // Cargar contactos al inicio automáticamente

    do {
        printf("\n--- Agenda de Contactos ---\n");
        printf("1. Agregar Contacto\n");
        printf("2. Mostrar Contactos\n");
        printf("3. Buscar Contacto\n");
        printf("4. Eliminar Contacto\n");
        printf("5. Guardar Contactos y Salir\n");
        printf("6. Cargar Contactos desde Archivo\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        getchar();  // Limpiar buffer de entrada

        switch(opcion) {
            case 1: agregarContacto();    
                break;
            case 2: mostrarContactos(); 
                break;
            case 3: buscarContacto(); 
                break;
            case 4: eliminarContacto(); 
                break;
            case 5: guardarContactos(); printf("Contactos guardados. Saliendo...\n"); 
                break;
            case 6: cargarContactos(); printf("Contactos cargados desde el archivo.\n"); 
                break;
            default: printf("Opcion no valida.\n");
        }
    } while (opcion != 5);

    return 0;
}
//Miranda
void agregarContacto() {
    if (totalContactos >= 100) {
        printf("No se pueden agregar más contactos.\n");
        return;
    }

    printf("Nombre: ");
    fgets(contactos[totalContactos].nombre, 50, stdin);
    contactos[totalContactos].nombre[strcspn(contactos[totalContactos].nombre, "\n")] = 0;

    printf("Telefono: ");
    fgets(contactos[totalContactos].telefono, 15, stdin);
    contactos[totalContactos].telefono[strcspn(contactos[totalContactos].telefono, "\n")] = 0;

    printf("Correo: ");
    fgets(contactos[totalContactos].correo, 50, stdin);
    contactos[totalContactos].correo[strcspn(contactos[totalContactos].correo, "\n")] = 0;

    totalContactos++;
    printf("Contacto agregado correctamente.\n");
}
//Angel
void mostrarContactos() {
    if (totalContactos == 0) {
        printf("No hay contactos para mostrar.\n");
        return;
    }

    printf("\nLista de contactos:\n");
    for (int i = 0; i < totalContactos; i++) {
        printf("%d. %s - %s - %s\n", i + 1, contactos[i].nombre, contactos[i].telefono, contactos[i].correo);
    }
}
//Diego
void buscarContacto() {
    char nombreBusqueda[50];
    printf("Ingrese el nombre a buscar: ");
    fgets(nombreBusqueda, 50, stdin);
    nombreBusqueda[strcspn(nombreBusqueda, "\n")] = 0;

    for (int i = 0; i < totalContactos; i++) {
        if (strcmp(contactos[i].nombre, nombreBusqueda) == 0) {
            printf("Contacto encontrado: %s - %s - %s\n", contactos[i].nombre, contactos[i].telefono, contactos[i].correo);
            return;
        }
    }

    printf("Contacto no encontrado.\n");
}
//Ruben
void eliminarContacto() {
    char nombreEliminar[50];
    printf("Ingrese el nombre del contacto a eliminar: ");
    fgets(nombreEliminar, 50, stdin);
    nombreEliminar[strcspn(nombreEliminar, "\n")] = 0;

    for (int i = 0; i < totalContactos; i++) {
        if (strcmp(contactos[i].nombre, nombreEliminar) == 0) {
            for (int j = i; j < totalContactos - 1; j++) {
                contactos[j] = contactos[j + 1];
            }
            totalContactos--;
            printf("Contacto eliminado correctamente.\n");
            return;
        }
    }

    printf("Contacto no encontrado.\n");
}
//Xcaret
void guardarContactos() {
    FILE *archivo = fopen("contactos.txt", "w");
    if (!archivo) {
        printf("Error al guardar los contactos.\n");
        return;
    }

    for (int i = 0; i < totalContactos; i++) {
        fprintf(archivo, "%s - %s - %s\n", contactos[i].nombre, contactos[i].telefono, contactos[i].correo);
    }

    fclose(archivo);
}

void cargarContactos() {
    FILE *archivo = fopen("contactos.txt", "r");
    if (!archivo) {
        printf("No se encontró un archivo de contactos.\n");
        return;
    }

    totalContactos = 0;  // Reiniciar la lista antes de cargar
    while (fscanf(archivo, "%[^\n] ; %[^\n] ; %[^\n]\n", contactos[totalContactos].nombre, contactos[totalContactos].telefono, contactos[totalContactos].correo) != EOF) {
        totalContactos++;
        if (totalContactos >= 100) break;
    }

    fclose(archivo);
    printf("Contactos cargados correctamente.\n");
}