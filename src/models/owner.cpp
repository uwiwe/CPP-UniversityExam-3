#include "owner.h"
#include <sstream> // para usar istringstream

using namespace std;

const string Owner::ownerFile = "bin/owners.csv";

Owner::Owner(int id, string nombre, string telefono)
    : id(id), nombre(nombre), telefono(telefono) {}

int Owner::getId() {
    return id;
}

void Owner::setId(int id) {
    this->id = id;
}

string Owner::getNombre() {
    return nombre;
}

void Owner::setNombre(string nombre) {
    this->nombre = nombre;
}

string Owner::getTelefono() {
    return telefono;
}

void Owner::setTelefono(string telefono) {
    this->telefono = telefono;
}

// Crear propietario
bool Owner::createOwner(Owner &owner) {
    ofstream file(ownerFile, ios::app);
    if (file.is_open()) {
        file << owner.getId() << "," << owner.getNombre() << "," << owner.getTelefono() << "\n";
        file.close();
        return true;
    }
    return false;
}

// Leer propietarios
bool Owner::readAllOwners(string &output) {
    ifstream file(ownerFile);
    if (file.is_open()) {
        string line;
        output = "";
        while (getline(file, line)) {
            output += line + "\n";
        }
        file.close();
        return true;
    }
    return false;
}

// Actualizar propietario por id
bool Owner::updateOwner(int id, Owner &newOwner) {
    ifstream file(ownerFile);
    ofstream tempFile("temp.csv");
    bool updated = false;

    if (file.is_open() && tempFile.is_open()) {
        string line;

        // Ignorar encabezado
        if (getline(file, line)) {
            tempFile << line << "\n";
        }

        while (getline(file, line)) {
            istringstream stream(line);
            string idStr, nombre, telefono;

            if (getline(stream, idStr, ',') && getline(stream, nombre, ',') && getline(stream, telefono)) {
                int currentId = stoi(idStr); // stoi convierte texto a entero
                if (currentId == id) {
                    tempFile << newOwner.getId() << "," << newOwner.getNombre() << "," << newOwner.getTelefono() << "\n";
                    updated = true;
                } else {
                    tempFile << line << "\n";
                }
            }
        }
        file.close();
        tempFile.close();

        remove(ownerFile.c_str()); // c_str para reconvertir el string y asi poder eliminar y renombrar el archivo
        rename("temp.csv", ownerFile.c_str());
    }

    return updated;
}

// Eliminar propietario por ID
bool Owner::deleteOwner(int id) {
    ifstream file(ownerFile);
    ofstream tempFile("temp.csv");
    bool deleted = false;

    if (file.is_open() && tempFile.is_open()) {
        string line;

        // Ignorar encabezado
        if (getline(file, line)) {
            tempFile << line << "\n";
        }
        
        while (getline(file, line)) {
            istringstream stream(line);
            string idStr, nombre, telefono;

            if (getline(stream, idStr, ',') && getline(stream, nombre, ',') && getline(stream, telefono)) {
                int currentId = stoi(idStr); // stoi convierte texto a entero
                if (currentId == id) {
                    deleted = true;
                } else {
                    tempFile << line << "\n";
                }
            }
        }
        file.close();
        tempFile.close();

        remove(ownerFile.c_str()); // c_str para reconvertir el string y asi poder eliminar y renombrar el archivo
        rename("temp.csv", ownerFile.c_str());
    }

    return deleted;
}