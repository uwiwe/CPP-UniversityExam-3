# CRUD de Pets y Owners

Este es un proyecto CRUD para gestionar información de mascotas (pets) y propietarios (owners).

## Compilación y ejecución

Desde la carpeta raíz del proyecto, genere el ejecutable con el siguiente comando:
```bash
g++ -std=c++11 -o bin/main.exe src/views/main.cpp src/controllers/controller.cpp src/models/*.cpp -I./src/models -I./src/views -I./src/controllers
```

Luego, para ejecutar el programa, inserte:
```bash
bin\main.exe
```
