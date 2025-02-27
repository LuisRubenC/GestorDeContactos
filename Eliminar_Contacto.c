//Funcion eliminar contacto

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
