#include <iostream>
#include <windows.h>

using namespace std;

struct DatosRegistroVideoJuegos{
	string NombreJuego;
	string Plataforma;
	string Desarrollador;
	int Lanzamiento;
};

//Variables Globales
DatosRegistroVideoJuegos DatosRegistro[100];
int totalJuegos;

void RegistroVideoJuegos(){
	if (totalJuegos >= 100) {
        cout << "¡Límite de juegos alcanzado!" << endl;
        return;
    }
    
    cout << "\n Bienvenido a GameHub, aqui puedes registrar tu videojuego\n";
    cin.ignore();
    cout << "Ingresa el nombre de tu videojuego: ";
    getline(cin, DatosRegistro[totalJuegos].NombreJuego);
    cout << "Ingresa la plataforma en donde estara disponible: ";
    getline(cin, DatosRegistro[totalJuegos].Plataforma);
    cout << "Ingresa el nombre de tu empresa: ";
    getline(cin, DatosRegistro[totalJuegos].Desarrollador);
    cout << "Ingresa el año de lanzamiento: ";
    cin >> DatosRegistro[totalJuegos].Lanzamiento;

    cout << "\nRegistro guardado exitosamente:\n";
    cout << "Nombre: " << DatosRegistro[totalJuegos].NombreJuego << endl;
    cout << "Plataforma: " << DatosRegistro[totalJuegos].Plataforma << endl;
    cout << "Desarrollador: " << DatosRegistro[totalJuegos].Desarrollador << endl;
    cout << "Año de Lanzamiento: " << DatosRegistro[totalJuegos].Lanzamiento << endl;
    cout << "ID Generado Automaticamente: " << totalJuegos + 1 << endl;
    totalJuegos++; 
    cout<<"\nRegreseras al menu principal automaticamente en 5 segundos.";
    Sleep(5000);
    system("cls");
}

void EliminarVideoJuego(){
	int opc;
	char opcionconfirmacion;
    cout << "\n Bienvenido, aqui puedes eliminar tu videojuego\n";
    cout << "(1) Ingresar el ID\n(2) Ingresar el nombre del videojuego\n";
    cout << "Ingresa una opcion: ";
    cin >> opc;
    system("cls");

    if (totalJuegos == 0) {
        cout << "No hay videojuegos registrados aun.\n";
        return;
    }

    if (opc == 1) {
        int id;
        cout << "Ingresa el ID del videojuego a eliminar: ";
        cin >> id;
        id--;

        if (id < 0 || id >= totalJuegos) {
            cout << "ID inválido.\n";
            return;
        }
        
        cout<<"\nVideoJuego Encontrado:\n";
        cout << "Nombre: " << DatosRegistro[id].NombreJuego << endl;
    	cout << "Plataforma: " << DatosRegistro[id].Plataforma << endl;
    	cout << "Desarrollador: " << DatosRegistro[id].Desarrollador << endl;
    	cout << "Año de Lanzamiento: " << DatosRegistro[id].Lanzamiento << endl;
    	cout << "\n¿Estas seguro de que deseas eliminar el videojuego? (S/s para si, N/n para no): ";
    	cout << "\nIngrese una opccion:";
    	cin>>opcionconfirmacion;
    	
    	if(opcionconfirmacion == 'S' || opcionconfirmacion == 's'){
			for (int i = id; i < totalJuegos - 1; i++) {
				DatosRegistro[i] = DatosRegistro[i + 1];
			}
        	totalJuegos--;
        	cout << "\nVideojuego eliminado correctamente.\n";
        	cout<<"\nRegreseras al menu principal automaticamente en 5 segundos.";
    		Sleep(5000);
    		system("cls");
		}
		else if(opcionconfirmacion == 'N' || opcionconfirmacion == 'n'){
			cout<<"\nCancelaste la eliminacion del VideoJuego."<<endl;
			cout<<"\nRegreseras al menu principal automaticamente en 5 segundos.";
    		Sleep(5000);
    		system("cls");
		}
		else{
			cout << "Opcion no valida.\n";
			cout<<"\nRegreseras al menu principal en 5 segundos.";
    		Sleep(5000);
    		system("cls");
		}
    } 
	else if (opc == 2) {
    	string nombre;
	    cin.ignore();
	    cout << "Ingresa el nombre del videojuego a eliminar: ";
	    getline(cin, nombre);
	    bool encontrado = false;

	    for (int i = 0; i < totalJuegos; i++) {
	        if (DatosRegistro[i].NombreJuego == nombre) {
	            encontrado = true;
	            cout << "\nVideoJuego Encontrado:\n";
	            cout << "Nombre: " << DatosRegistro[i].NombreJuego << endl;
	            cout << "Plataforma: " << DatosRegistro[i].Plataforma << endl;
	            cout << "Desarrollador: " << DatosRegistro[i].Desarrollador << endl;
	            cout << "Año de Lanzamiento: " << DatosRegistro[i].Lanzamiento << endl;
	            cout << "\n¿Estas seguro de que deseas eliminar el videojuego? (S/s para si, N/n para no): ";
	            cin >> opcionconfirmacion;
	
	            if (opcionconfirmacion == 'S' || opcionconfirmacion == 's') {
	                for (int j = i; j < totalJuegos - 1; j++) {
	                    DatosRegistro[j] = DatosRegistro[j + 1];
	                }
	                totalJuegos--;
	                cout << "\nVideojuego eliminado correctamente.\n";
	            } else if (opcionconfirmacion == 'N' || opcionconfirmacion == 'n') {
	                cout << "\nCancelaste la eliminacion del VideoJuego." << endl;
	            } else {
	                cout << "\nOpcion no valida.\n";
	            }
	
	            cout << "\nRegresarás al menú principal automáticamente en 5 segundos.";
	            Sleep(5000);
	            system("cls");
	            break;
	        }
	    }
	
	    if (!encontrado) {
	        cout << "Videojuego no encontrado.\n";
	        cout << "\nRegresarás al menú principal automáticamente en 5 segundos.";
	        Sleep(5000);
	        system("cls");
	    }
	}
	else{
        cout << "Opción inválida.\n";
    }
}

void ModificarVideoJuego(){
    if (totalJuegos == 0) {
        cout << "No hay videojuegos registrados aun.\n";
        cout << "\nRegresaras al menu principal automaticamente en 5 segundos.";
        Sleep(5000);
        system("cls");
        return;
    }
    
    int opcionBusqueda;
    cout << "\n ¿Como deseas buscar el videojuego a modificar?\n";
    cout << "1. Por ID\n2. Por Nombre\nSelecciona una opcion: ";
    cin >> opcionBusqueda;
    system("cls");

    int id = -1;

    if (opcionBusqueda == 1) {
        cout << "Ingresa el ID del videojuego: ";
        cin >> id;
        id--;

        if (id < 0 || id >= totalJuegos) {
            cout << "ID invalido.\n";
            cout << "\nRegresaras al menu principal automaticamente en 5 segundos.";
            Sleep(5000);
            system("cls");
            return;
        }
    } 
	else if (opcionBusqueda == 2) {
        string nombre;
        cin.ignore();
        cout << "Ingresa el nombre del videojuego: ";
        getline(cin, nombre);

        bool encontrado = false;
        for (int i = 0; i < totalJuegos; i++) {
            if (DatosRegistro[i].NombreJuego == nombre) {
                id = i;
                encontrado = true;
                break;
            }
        }

        if (!encontrado) {
            cout << "Videojuego no encontrado.\n";
            cout << "\nRegresaras al menu principal automaticamente en 5 segundos.";
            Sleep(5000);
            system("cls");
            return;
        }
    } 
	else {
        cout << "Opcion invalida.\n";
        return;
    }

    cout << "\nVideojuego encontrado:\n";
    cout << "Nombre: " << DatosRegistro[id].NombreJuego << endl;
    cout << "Plataforma: " << DatosRegistro[id].Plataforma << endl;
    cout << "Desarrollador: " << DatosRegistro[id].Desarrollador << endl;
    cout << "Año de Lanzamiento: " << DatosRegistro[id].Lanzamiento << endl;

    char confirmacion;
    cout << "\n¿Quieres modificar este videojuego? (S/s para si, N/n para no): ";
    cin >> confirmacion;

    if (confirmacion == 'S' || confirmacion == 's') {
        cin.ignore();
        cout << "\nIngresa el nuevo nombre del videojuego: ";
        getline(cin, DatosRegistro[id].NombreJuego);
        cout << "Ingresa la nueva plataforma: ";
        getline(cin, DatosRegistro[id].Plataforma);
        cout << "Ingresa el nuevo desarrollador: ";
        getline(cin, DatosRegistro[id].Desarrollador);
        cout << "Ingresa el nuevo año de lanzamiento: ";
        cin >> DatosRegistro[id].Lanzamiento;

        cout << "\nVideojuego modificado correctamente.\n";
    } 
	else if (confirmacion == 'N' || confirmacion == 'n') {
        cout << "\nModificacion cancelada.\n";
    } 
	else {
        cout << "Opcion invalida.\n";
    }

    cout << "\nRegresaras al menu principal automaticamente en 5 segundos.";
    Sleep(5000);
    system("cls");
}

void MostrarVideoJuegos(){
    if (totalJuegos == 0) {
        cout << "No hay videojuegos registrados aun.\n";
    } else {
        cout << "\n----- Catalogo de Videojuegos -----\n";
        for (int i = 0; i < totalJuegos; i++) {
            cout << "ID: " << i + 1 << endl;
            cout << "Nombre: " << DatosRegistro[i].NombreJuego << endl;
            cout << "Plataforma: " << DatosRegistro[i].Plataforma << endl;
            cout << "Desarrollador: " << DatosRegistro[i].Desarrollador << endl;
            cout << "Año de Lanzamiento: " << DatosRegistro[i].Lanzamiento << endl;
            cout << "-------------------------------\n";
        }
    }
    cout << "\nPresiona una tecla para regresar al menú principal.";
    system("pause");
    system("cls");
}

void BuscarVideoJuego(){
    if (totalJuegos == 0) {
        cout << "No hay videojuegos registrados aun.\n";
        cout << "\nPresiona una tecla para regresar al menú principal.";
        system("pause");
        system("cls");
        return;
    }

    int opcionBusqueda;
    cout << "\n ¿Cómo deseas buscar el videojuego?\n";
    cout << "1. Por ID\n2. Por Nombre\nSelecciona una opción: ";
    cin >> opcionBusqueda;
    system("cls");

    if (opcionBusqueda == 1) {
        int id;
        cout << "Ingresa el ID del videojuego: ";
        cin >> id;
        id--;

        if (id < 0 || id >= totalJuegos) {
            cout << "ID inválido.\n";
        } else {
            cout << "\nVideojuego encontrado:\n";
            cout << "ID: " << id + 1 << endl;
            cout << "Nombre: " << DatosRegistro[id].NombreJuego << endl;
            cout << "Plataforma: " << DatosRegistro[id].Plataforma << endl;
            cout << "Desarrollador: " << DatosRegistro[id].Desarrollador << endl;
            cout << "Año de Lanzamiento: " << DatosRegistro[id].Lanzamiento << endl;
        }
    } 
	else if (opcionBusqueda == 2) {
        string nombre;
        cin.ignore();
        cout << "Ingresa el nombre del videojuego: ";
        getline(cin, nombre);

        bool encontrado = false;
        for (int i = 0; i < totalJuegos; i++) {
            if (DatosRegistro[i].NombreJuego == nombre) {
                encontrado = true;
                cout << "\nVideojuego encontrado:\n";
                cout << "ID: " << i + 1 << endl;
                cout << "Nombre: " << DatosRegistro[i].NombreJuego << endl;
                cout << "Plataforma: " << DatosRegistro[i].Plataforma << endl;
                cout << "Desarrollador: " << DatosRegistro[i].Desarrollador << endl;
                cout << "Año de Lanzamiento: " << DatosRegistro[i].Lanzamiento << endl;
                break;
            }
        }

        if (!encontrado) {
            cout << "Videojuego no encontrado.\n";
        }
    } 
	else {
        cout << "Opción inválida.\n";
    }

    cout << "\nPresiona una tecla para regresar al menú principal.";
    system("pause");
    system("cls");
}

int main(){
	DatosRegistroVideoJuegos DatosRegistro[100];
	int opcion;
	
    do {
    	cout<<"---------------------";
        cout << "\n1. Registrar VideoJuegos \n2. Eliminar VideoJuegos \n3. Modificar VideoJuegos \n4. Mostrar VideoJuegos \n5. Buscar VideoJuego \n6. Salir\n";
        cout<<"---------------------\n";
        cout << " Seleccione una opcion: ";
        cin >> opcion;
        
        system("cls");
        
        switch (opcion) {
            case 1:
            	RegistroVideoJuegos();
                break;
            case 2:
            	EliminarVideoJuego();
                break;
            case 3:
            	ModificarVideoJuego();
                break;
            case 4:
            	MostrarVideoJuegos();
            	break;
            case 5:
            	BuscarVideoJuego();
            	break;
            case 6: 
            	cout << "Saliendo del sistema...\n";
            	system("pause");
            	break;
            default:
                cout << "Opción no válida. Intente de nuevo.\n";
        }
    } while (opcion != 6);
	
	return 0;
}
