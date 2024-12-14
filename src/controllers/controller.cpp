#include "controller.h"
#include "../models/pet.h"
#include "../models/owner.h"

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

bool Controller::createOwner(int id, string nombre, string telefono) {
    Owner owner(id, nombre, telefono);
    return Owner::createOwner(owner);
}

bool Controller::getAllOwners(string &output) {
    return Owner::readAllOwners(output);
}

bool Controller::updateOwner(int id, int newId, string newNombre, string newTelefono) {
    Owner newOwner(newId, newNombre, newTelefono);
    return Owner::updateOwner(id, newOwner);
}

bool Controller::deleteOwner(int id) {
    return Owner::deleteOwner(id);
}
