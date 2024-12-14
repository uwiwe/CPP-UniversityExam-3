#include <iostream>
#include <string>
#include "../controllers/controller.h"

using namespace std;

int main() {
    Controller controller;
    int opcion;

    do {
        cout << "Mascotas y Propietarios:" << endl;
        cout << "1. Anadir mascota" << endl;
        cout << "2. Ver lista de mascotas" << endl;
        cout << "3. Actualizar mascota" << endl;
        cout << "4. Eliminar mascota" << endl;
        cout << "5. Anadir propietario" << endl;
        cout << "6. Ver lista de propietarios" << endl;
        cout << "7. Actualizar propietario" << endl;
        cout << "8. Eliminar propietario" << endl;
        cout << "9. Salir" << endl;
        cout << "Seleccione: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int id;
                string nombre, animal;
                cout << "Ingrese id: ";
                cin >> id;
                cout << "Ingrese nombre: ";
                cin.ignore();
                getline(cin, nombre);
                cout << "Ingrese tipo de animal: ";
                getline(cin, animal);

                if (controller.createPet(id, nombre, animal)) {
                    cout << "Mascota creada." << endl;
                } else {
                    cout << "Error al crear la mascota." << endl;
                }
                break;
            }

            case 2: {
                string output;
                if (controller.getAllPets(output)) {
                    cout << "Lista de mascotas:" << endl;
                    cout << output;
                } else {
                    cout << "Error al leer las mascotas." << endl;
                }
                break;
            }

            case 3: {
                int id, nuevoId;
                string nuevoNombre, nuevoAnimal;
                cout << "Ingrese id de la mascota a actualizar: ";
                cin >> id;
                cout << "Ingrese nuevo id: ";
                cin >> nuevoId;
                cout << "Ingrese nuevo nombre: ";
                cin.ignore();
                getline(cin, nuevoNombre);
                cout << "Ingrese nuevo tipo de animal: ";
                getline(cin, nuevoAnimal);

                if (controller.updatePet(id, nuevoId, nuevoNombre, nuevoAnimal)) {
                    cout << "Mascota actualizada." << endl;
                } else {
                    cout << "Error al actualizar la mascota." << endl;
                }
                break;
            }

            case 4: {
                int id;
                cout << "Ingrese id de la mascota a eliminar: ";
                cin >> id;

                if (controller.deletePet(id)) {
                    cout << "Mascota eliminada exitosamente." << endl;
                } else {
                    cout << "Error al eliminar la mascota." << endl;
                }
                break;
            }

            case 5: {
                int id;
                string nombre, telefono;
                cout << "Ingrese id: ";
                cin >> id;
                cout << "Ingrese nombre: ";
                cin.ignore();
                getline(cin, nombre);
                cout << "Ingrese telefono: ";
                getline(cin, telefono);

                if (controller.createOwner(id, nombre, telefono)) {
                    cout << "Propietario creado." << endl;
                } else {
                    cout << "Error al crear el propietario." << endl;
                }
                break;
            }

            case 6: {
                string output;
                if (controller.getAllOwners(output)) {
                    cout << "Lista de propietarios:" << endl;
                    cout << output;
                } else {
                    cout << "Error al leer los propietarios." << endl;
                }
                break;
            }

            case 7: {
                int id, nuevoId;
                string nuevoNombre, nuevoTelefono;
                cout << "Ingrese id del propietario a actualizar: ";
                cin >> id;
                cout << "Ingrese nuevo id: ";
                cin >> nuevoId;
                cout << "Ingrese nuevo nombre: ";
                cin.ignore();
                getline(cin, nuevoNombre);
                cout << "Ingrese nuevo telefono: ";
                getline(cin, nuevoTelefono);

                if (controller.updateOwner(id, nuevoId, nuevoNombre, nuevoTelefono)) {
                    cout << "Propietario actualizado." << endl;
                } else {
                    cout << "Error al actualizar el propietario." << endl;
                }
                break;
            }

            case 8: {
                int id;
                cout << "Ingrese id del propietario a eliminar: ";
                cin >> id;

                if (controller.deleteOwner(id)) {
                    cout << "Propietario eliminado exitosamente." << endl;
                } else {
                    cout << "Error al eliminar el propietario." << endl;
                }
                break;
            }

            case 9:
                cout << "Ha salido del programa." << endl;
                break;

            default:
                cout << "Opcion no valida. Intente nuevamente." << endl;
        }
    } while (opcion != 9);

    return 0;
}