#include "pet.h"
#include <sstream> // para usar istringstream

using namespace std;

const string Pet::petFile = "bin/pets.csv";

Pet::Pet(int id, string nombre, string animal)
    : id(id), nombre(nombre), animal(animal) {}

int Pet::getId() {
    return id;
}

void Pet::setId(int id) {
    this->id = id;
}

string Pet::getNombre() {
    return nombre;
}

void Pet::setNombre(string nombre) {
    this->nombre = nombre;
}

string Pet::getAnimal() {
    return animal;
}

void Pet::setAnimal(string animal) {
    this->animal = animal;
}

// Crear mascota
bool Pet::createPet(Pet &pet) {
    ofstream file(petFile, ios::app);
    if (file.is_open()) {
        file << pet.getId() << "," << pet.getNombre() << "," << pet.getAnimal() << "\n";
        file.close();
        return true;
    }
    return false;
}

// Leer mascotas
bool Pet::readAllPets(string &output) {
    ifstream file(petFile);
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

// Actualizar mascota por id
bool Pet::updatePet(int id, Pet &newPet) {
    ifstream file(petFile);
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
            string idStr, nombre, animal;

            if (getline(stream, idStr, ',') && getline(stream, nombre, ',') && getline(stream, animal)) {
                int currentId = stoi(idStr); // stoi convierte texto a entero
                if (currentId == id) {
                    tempFile << newPet.getId() << "," << newPet.getNombre() << "," << newPet.getAnimal() << "\n";
                    updated = true;
                } else {
                    tempFile << line << "\n";
                }
            }
        }
        file.close();
        tempFile.close();

        remove(petFile.c_str()); // c_str para reconvertir el string y asi poder eliminar y renombrar el archivo
        rename("temp.csv", petFile.c_str());
    }

    return updated;
}

// Eliminar mascota por ID
bool Pet::deletePet(int id) {
    ifstream file(petFile);
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
            string idStr, nombre, animal;

            if (getline(stream, idStr, ',') && getline(stream, nombre, ',') && getline(stream, animal)) {
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

        remove(petFile.c_str()); // c_str para reconvertir el string y asi poder eliminar y renombrar el archivo
        rename("temp.csv", petFile.c_str());
    }

    return deleted;
}
