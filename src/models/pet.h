#ifndef PET_H
#define PET_H

#include <string>
#include <fstream>

using namespace std;

class Pet {
private:
    int id;
    string nombre;
    string animal;
    static const string petFile;
public:
    Pet(int id, string nombre, string animal);

    int getId();
    void setId(int id);
    string getNombre();
    void setNombre(string nombre);
    string getAnimal();
    void setAnimal(string animal);

    // crud
    static bool createPet(Pet &pet);
    static bool readAllPets(string &output);
    static bool updatePet(int id, Pet &newPet);
    static bool deletePet(int id);
};

#endif
