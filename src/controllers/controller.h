#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>
#include "../models/pet.h"
#include "../models/owner.h"

using namespace std;

class Controller {
public:
    // Pets
    bool createPet(int id, string nombre, string animal);
    bool getAllPets(string &output);
    bool updatePet(int id, int newId, string newNombre, string newAnimal);
    bool deletePet(int id);
    // Owners
    bool createOwner(int id, string nombre, string telefono);
    bool getAllOwners(string &output);
    bool updateOwner(int id, int newId, string newNombre, string newTelefono);
    bool deleteOwner(int id);
};

#endif