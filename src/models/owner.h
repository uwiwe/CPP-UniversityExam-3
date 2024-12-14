#ifndef OWNER_H
#define OWNER_H

#include <string>
#include <fstream>

using namespace std;

class Owner {
private:
    int id;
    string nombre;
    string telefono;
    static const string ownerFile;
public:
    Owner(int id, string nombre, string telefono);

    int getId();
    void setId(int id);
    string getNombre();
    void setNombre(string nombre);
    string getTelefono();
    void setTelefono(string telefono);

    // crud
    static bool createOwner(Owner &owner);
    static bool readAllOwners(string &output);
    static bool updateOwner(int id, Owner &newOwner);
    static bool deleteOwner(int id);
};

#endif