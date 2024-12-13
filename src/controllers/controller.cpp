#include "controller.h"
#include "../models/pet.h"

using namespace std;

// Implementaciones
bool Controller::createPet(int id, string nombre, string animal) {
    Pet pet(id, nombre, animal);
    return Pet::createPet(pet);
}

bool Controller::getAllPets(string &output) {
    return Pet::readAllPets(output);
}

bool Controller::updatePet(int id, int newId, string newNombre, string newAnimal) {
    Pet newPet(newId, newNombre, newAnimal);
    return Pet::updatePet(id, newPet);
}

bool Controller::deletePet(int id) {
    return Pet::deletePet(id);
}
