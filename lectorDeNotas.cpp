#include <iostream>
#include <fstream>
using namespace std;

int seleccionarOpcion() {
    int opcionUsuario = 0;
    char esLaOpcionCorrecta = 'N';
    while (esLaOpcionCorrecta == 'N') {
        cout << "###################" << endl;
        cout << "# LECTOR DE NOTAS #" << endl;
        cout << "###################" << endl;
        cout << "" << endl;
        cout << "Que quieres hacer?" << endl;
        cout << "   1)  Consultar nota." << endl;
        cout << "   2)  Añadir nota." << endl;
        cout << "   3)  Eliminar nota." << endl;
        cout << "" << endl;
        cout << "Teclea su respuesta: ";
        cin >> opcionUsuario;
        switch (opcionUsuario)
        {
            case 1:
                cout << "Has seleccionado \"Consultar nota\". Es correcto? [ S/N ]? ";
                break;
            case 2:
                cout << "Has seleccionado \"Añadir nota\". Es correcto? [ S/N ]? ";
                break;
            case 3:
                cout << "Has seleccionado \"Eliminar nota\". Es correcto? [ S/N ]? ";
                break;
        }
        cin >> esLaOpcionCorrecta;
    }
    
    return opcionUsuario;
}

void consultarFichero(string rutaFichero) {
    string nombreAlumno = "";
    char esLaOpcionCorrecta = 'N';
    while (esLaOpcionCorrecta == 'N') {
        cout << "Introduce el nombre del alumno cuya nota quieres consultar: ";
        cin >> nombreAlumno;

        cout << "Su nombre es \"" << nombreAlumno << "\". Es correcto? [ S/N ]? ";
        cin >> esLaOpcionCorrecta;
    }

    ifstream fichero(rutaFichero);

    string lineaFichero;
    while (getline(fichero,lineaFichero)) {
        if (lineaFichero.substr(0,lineaFichero.find(":")) == nombreAlumno) {
            cout << "Nombre: " << lineaFichero.substr(0,lineaFichero.find(":")) << "\t" << "Nota: " << lineaFichero.substr((lineaFichero.find(":")+1),(lineaFichero.length()-1)) << endl;
        }
    }
}

void anadirNota(string rutaFichero) {
    string nombreAlumno = "";
    string notaAlumno = "";

    char esLaOpcionCorrecta = 'N';
    while (esLaOpcionCorrecta == 'N') {
        cout << "Introduce el nombre del alumno que quieres insertar: ";
        cin >> nombreAlumno;

        cout << "Introduce la nota del alumno que quieres insertar: ";
        cin >> notaAlumno;

        cout << "El nombre es \"" << nombreAlumno << "\" y la nota es " << notaAlumno << ". Es correcto? [ S/N ]? ";
        cin >> esLaOpcionCorrecta;
    }

    ifstream ficheroLeer(rutaFichero);
    
    string contenidoFichero = "";
    string lineaFichero = "";

    while (getline(ficheroLeer,lineaFichero)) {
        contenidoFichero.append(lineaFichero);
        contenidoFichero.append("\n");
    }

    contenidoFichero.append(nombreAlumno);
    contenidoFichero.append(":");
    contenidoFichero.append(notaAlumno);

    ofstream ficheroEscribir(rutaFichero);

    ficheroEscribir << contenidoFichero;
}

void eliminarNota(string rutaFichero) {
    string nombreAlumno = "";

    char esLaOpcionCorrecta = 'N';
    while (esLaOpcionCorrecta == 'N') {
        cout << "Introduce el nombre del alumno que quieres eliminar: ";
        cin >> nombreAlumno;

        cout << "El nombre es \"" << nombreAlumno << ". Es correcto? [ S/N ]? ";
        cin >> esLaOpcionCorrecta;
    }

    ifstream ficheroLeer(rutaFichero);
    
    string contenidoFichero = "";
    string lineaFichero = "";

    while (getline(ficheroLeer,lineaFichero)) {
        if (lineaFichero.substr(0,lineaFichero.find(":")) != nombreAlumno) {
            contenidoFichero.append(lineaFichero);
            contenidoFichero.append("\n"); 
        }
    }

    ofstream ficheroEscribir(rutaFichero);

    ficheroEscribir << contenidoFichero;
}

int main() {
    int opcion = seleccionarOpcion();
    string rutaFichero = "./archivo.txt";
    switch (opcion) {
        case 1:
            consultarFichero(rutaFichero);
            break;
        case 2:
            anadirNota(rutaFichero);
            break;
        case 3:
            eliminarNota(rutaFichero);
            break;
    }
    return 0;
}