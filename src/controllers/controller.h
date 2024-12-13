#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>
#include "../models/pet.h"

using namespace std;

class Controller {
public:
    bool createPet(int id, string nombre, string animal);
    bool getAllPets(string &output);
    bool updatePet(int id, int newId, string newNombre, string newAnimal);
    bool deletePet(int id);
};

#endif
