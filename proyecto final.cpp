#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <cstring>
#include <stdio.h>
#include <conio.h>
#include <cctype>
#include <windows.h>

using namespace std;

//Estructuras.

struct ciudades{
	char ciudad[15];
    char hotel[30];
    float puntuacion;
    int estrellas;
    bool piscina;
    bool parqueadero;
    bool restaurante;
    unsigned long long precio;
    }ciudad;

struct llegada_{
	int dia;
	int mes;
	int anio;
	int hora;
};

struct dat_hotel{
	string ciudad;
	float puntuacion;
	int estrellas;
};

struct filtros_{
	bool piscina;
	bool parqueadero;
	bool restaurante;
};

struct salida_{
	int dia;
	int mes;
	int anio;
	int hora;
};

struct reserva_{
	int entradas;
	unsigned long long precio;
	llegada_ llegada;
	salida_ salida;
	dat_hotel hotel;
	filtros_ filtros;
};

struct cuenta_{
	unsigned long long cedula;
	string nombre;
	string usuario;
	unsigned long long clave;
};

//Firmas
void llenardatos(reserva_ &reserva);
void mostrarhoteles(ciudades &ciudad, reserva_ &reserva, string &nombre_hotel);

//main
int main() {
	int op;
	string nombre_hotel;
	reserva_ reserva;
	cuenta_ cuenta;
	
	//Llamado funciones
	do{
	    do{
		    cout<<"1. si desea ingresar los datos."<<endl;
	    	cout<<"2. si desea ver los hoteles disponibles."<<endl;
	    	cout<<"3. si desea ver los comentarios del hotel. "<<endl;
		    cout<<"Que opcion desea?: ";
		    cin>>op;
	} while ((op<0) || (op>3));
		
			
			switch (op){
				
				case 1:
					system ("cls");
					llenardatos(reserva);
					break;
				
				case 2:
					
					system("cls");
					mostrarhoteles(ciudad, reserva, nombre_hotel);
					break;
				
				case 3:
					
					system ("cls");
					cout<<"Escogio el hotel: "<<nombre_hotel<<endl;
					break;
			}
			
		} while(op!=0);
		
	system ("pause");
	return 0;
}

//Funciones.
void llenardatos(reserva_ &reserva){
	
	cout<<"Ingrese el numero de personas: ";
	cin>>reserva.entradas;
	
	fflush(stdin);
	cout<<"\nIngrese el precio maximo de la habitacion por noche: ";
	cin>>reserva.precio;
	
	fflush(stdin);
	cout<<"\nIngrese la fecha de llegada.\n";
	cout<<"Dia: "; cin>>reserva.llegada.dia;
	cout<<"Mes: "; cin>>reserva.llegada.mes;
	cout<<"Año: "; cin>>reserva.llegada.anio;
	cout<<"Hora: "; cin>>reserva.llegada.hora;
	
	fflush(stdin);
	cout<<"\nIngrese la fecha de salida.\n";
	cout<<"Dia: "; cin>>reserva.salida.dia;
	cout<<"Mes: "; cin>>reserva.salida.mes;
	cout<<"Año: "; cin>>reserva.salida.anio;
	cout<<"Hora: "; cin>>reserva.salida.hora;
	
	fflush(stdin);
	cout<<"\nIngrese la ciudad en la que estara. "<<endl;
	cout<<"Las ciudades pueden ser: "<<endl;
    cout<<"Medellin."<<endl;
    cout<<"Cartagena."<<endl;
    cout<<"Cali."<<endl;
    cout<<"Bogota."<<endl;
    cout<<"Pereira."<<endl;
	cin>>reserva.hotel.ciudad;
	
	fflush(stdin);
	cout<<"\nIngrese la puntuacion minima del hotel: ";
	cin>>reserva.hotel.puntuacion;
	
	fflush(stdin);
	cout<<"\nIngrese el minimo de estrellas: ";
	cin>>reserva.hotel.estrellas;
	
	fflush(stdin);
	cout<<"\nA continuacion tendremos algunos filtros, ingrese 1 si desea agregarlos o 0 si no los requiere.\n";
	cout<<"Piscina: "; cin>>reserva.filtros.piscina;
	cout<<"Parqueadero: "; cin>>reserva.filtros.parqueadero;
	cout<<"Restaurante: "; cin>>reserva.filtros.restaurante;
}



void mostrarhoteles(ciudades &ciudad, reserva_ &reserva, string &nombre_hotel){
	
	system ("cls");
    
    getchar();
    FILE *archdisco;
    archdisco = fopen("Hoteles.txt","at+");
	
    while(fread(&ciudad,sizeof(ciudad),1,archdisco)==1){
    	
        if ((reserva.hotel.ciudad == ciudad.ciudad) && (reserva.hotel.estrellas <= ciudad.estrellas) &&
		    (reserva.hotel.puntuacion <= ciudad.puntuacion) && (reserva.filtros.piscina <= ciudad.piscina) &&
			(reserva.filtros.parqueadero <= ciudad.parqueadero) && (reserva.filtros.restaurante <= ciudad.restaurante) &&
			(reserva.precio>=ciudad.precio)){
				
            cout<<"Ciudad: "<<ciudad.ciudad<<endl;
            fflush(stdin);

            cout<<"Nombre del hotel: "<<ciudad.hotel<<endl;
            fflush(stdin);

            cout<<"Puntuacion: "<<ciudad.puntuacion<<endl;
            fflush(stdin);

            cout<<"Estrellas: "<<ciudad.estrellas<<endl;
            fflush(stdin);

            cout<<"Piscina?: "<<ciudad.piscina<<endl;
            fflush(stdin);

            cout<<"Parqueadero?: "<<ciudad.parqueadero<<endl;
            fflush(stdin);

            cout<<"Restaurante?: "<<ciudad.restaurante<<endl;
            fflush(stdin);

            cout<<"Precio por noche: "<<ciudad.precio<<endl;
            cout<<"\n";
        }
    }
           fclose(archdisco);
           cout<<"Ingrese el nombre del hotel que desea escoger:";
           cin>>nombre_hotel;
}
