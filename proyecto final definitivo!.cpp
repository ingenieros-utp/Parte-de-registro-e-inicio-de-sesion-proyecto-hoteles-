#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <string>
#include <cstring>
#include <conio.h>
#include <cctype>

using namespace std;


//Estructuras con las firmas 

//Registro
struct Usuario {
	char nombre[40];
	char contrasena[10];
	char usuario[20];
	char cedula[10];
}usuarios[100];

//Firmas
void registrar(int&,int&);
void inic_sesion(int&, int&,bool&, string&);
void menu_admin(bool &,int &, int &);
void menu_clien(bool &, string&);
void llenar_struct_usu(int &, int &);
void mostrarusuarios(int &, int&);

//--------------------------------------------------------------------------------------------------------------------------

//Hoteles y Comentarios
struct ciudades{
	   char ciudad[15];
       char hotel[30];
       float puntuacion;
       int estrellas;
       bool piscina;
       bool parqueadero;
       bool restaurante;
       unsigned long long precio;
       int personas;
       int hab_disp;
    }ciudad;
       
struct comentarios{
		char nombre[30];
   		float puntuacion;
    	char ciudadd[15];
    	char hotell[30];
    	char comentario[500];
    }comentario;

//Firmas
void agg_coment();
void ver_coment();
void agg_hot(ciudades &ciudad);
void ver_hot(ciudades &ciudad);

//--------------------------------------------------------------------------------------------------------------------------

//Reserva
struct comparacion{
	   string ciudad;
       string hotel;
       float puntuacion;
       int estrellas;
       bool piscina;
       bool parqueadero;
       bool restaurante;
       unsigned long long precio;
       int personas;
       int hab_disp;
    }vec[6], aux;

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
}reserva;

	int dias=0;
	int horas=0;

//Firmas
void llenardatos();
void mostrarhoteles(ciudades &ciudad, string &nombre_hotel);
void mostrarhoteles_precioM(ciudades &ciudad, string &nombre_hotel);
void mostrarhoteles_preciom(ciudades &ciudad, string &nombre_hotel);
void mostrarhoteles_valoracion(ciudades &ciudad, string &nombre_hotel);
void comentarios(ciudades &ciudad, string &nombre_hotel);
void precio_total(ciudades &ciudad, string &nombre_hotel);
void confirmar();
int cerrar();

//--------------------------------------------------------------------------------------------------------------------------

int main() {
	//declaramos las variables
	int opc,clien=0,n_clien=0;
	bool sesion;
	string nombre_hotel;
	//Llenamos la estructura de usuario desde el archivo
	llenar_struct_usu(clien,n_clien);
	
	//mensaje de inicio
	cout<<"\tBienvenido"<<endl;
	Sleep(1000);
	system("cls");
	//mostramos el menu principal
	do{
		do{
			system("cls");
			cout<<"0. Salir"<<endl;
			cout<<"1. Registrar"<<endl;
			cout<<"2. Iniciar Sesion"<<endl;
			cout<<"Opcion: "; cin>>opc;
			fflush(stdin);
			} while ((opc>2) || (opc<0));
		
		switch(opc){
			case 1:
				registrar(clien,n_clien);
				break;
					
			case 2:
				inic_sesion(clien,n_clien,sesion,nombre_hotel);
				break;	
		}
		
	} while(opc!=0);
	
	return 0;
}

//--------------------------------------------------------------------------------------------------------------------------

//Funciones Registro
//funcion para registrar el usuario, sea un cliente o un administrador
void registrar(int &clien, int &n_clien){
	system("cls");
	char ced[10];
	int i;
	//delcraracion de las variables para los archivos
	ofstream cedul,nombre,usuario,passw;
	//abriendo los archivos necesarios
	nombre.open("nombre.txt",ios::app);
	cedul.open("cedula.txt",ios::app);
	usuario.open("usuario.txt",ios::app);
	passw.open("passwords.txt",ios::app);
	
	string cedula1;
	string nombre1;
	string contrasena1;
	string usuario1;
	cout<<"Digite la cedula: "; getline(cin,cedula1,'\n'); fflush(stdin);
	strcpy(ced,cedula1.c_str());
	
	if(n_clien == 0){//no hay datos de usuarios en la estructuras
		//ingreso del primer usuario
		strcpy(usuarios[clien].cedula,cedula1.c_str());	
		cedul<<usuarios[clien].cedula<<endl; 
		cout<<"Digite su nombre: "; getline(cin,nombre1,'\n'); fflush(stdin);
		strcpy(usuarios[clien].nombre,nombre1.c_str());
		nombre<<usuarios[clien].nombre<<endl;
		cout<<"Digite el usuario que va a utilizar: "; getline(cin,usuario1,'\n'); fflush(stdin);
		strcpy(usuarios[clien].usuario,usuario1.c_str());
		usuario<<usuarios[clien].usuario<<endl;
		cout<<"Digite la contrasena que va a utilizar: "; getline(cin,contrasena1,'\n'); fflush(stdin);
		strcpy(usuarios[clien].contrasena,contrasena1.c_str());
		passw<<usuarios[clien].contrasena<<endl;
	
		clien++;
		n_clien++;
		system("cls");
		cout<<"== Usuario Registrado! =="<<endl;
		system("pause");
		
		//cerrando archivos	
		nombre.close();
		passw.close();
		cedul.close();
		usuario.close();
		}
		else{
			//ingreso de los demas usuarios
			for(i = 0; i < n_clien; i++){//recorremos la estrucutra para verificar existencia
				if(strcmp(cedula1.c_str(),usuarios[i].cedula)==0){//si existe el usuario
						system("cls");
						cout<<"==Usuario ya se encuentra registrado=="<<endl;
						system("pause");
						system("cls");
						break;
					}				
				}
				if( i ==  n_clien){//si no existe el usuario
					//se le pide ingresar los demas datos
					strcpy(usuarios[clien].cedula,cedula1.c_str());	
					cedul<<usuarios[clien].cedula<<endl; 
					cout<<"Digite su nombre: "; getline(cin,nombre1,'\n'); fflush(stdin);
					strcpy(usuarios[clien].nombre,nombre1.c_str());
					nombre<<usuarios[clien].nombre<<endl;
					cout<<"Digite el usuario que va a utilizar: "; getline(cin,usuario1,'\n'); fflush(stdin);
					strcpy(usuarios[clien].usuario,usuario1.c_str());
					usuario<<usuarios[clien].usuario<<endl;
					cout<<"Digite la contrasena que va a utilizar: "; getline(cin,contrasena1,'\n'); fflush(stdin);
					strcpy(usuarios[clien].contrasena,contrasena1.c_str());
					passw<<usuarios[clien].contrasena<<endl;
					clien++;
					n_clien++;
					system("cls");
					cout<<"== Usuario Registrado! =="<<endl;
					system("pause");
					
					//cerrando archivos	
					nombre.close();
					passw.close();
					cedul.close();
					usuario.close();
						
				}
			}
}
	
//funcion que permite iniciar sesion
void inic_sesion(int &clien, int &n_clien, bool &sesion, string &nombre_hotel){
	system("cls");
	char cade[]="admin";
	string usua,clave;
	bool band;
	//pedimos al cliente o al administrador su usuario y contraseña
	cout<<"Usuario: "; getline(cin,usua,'\n'); fflush(stdin);
	cout<<"Contrasena: "; getline(cin,clave,'\n'); fflush(stdin);
	system("cls");
	//buscamos en la estructura el usuario y la contraseña de quien inicia sesion
	for(int i = 0; i < n_clien;i++){
		//comparamos en la estructura
		if((strcmp(usua.c_str(),usuarios[i].usuario)==0) && (strcmp(clave.c_str(),usuarios[i].contrasena)==0)){
			band = true;//bandera verdarera si la encuentra
			break;
		}else{
			band = false;//bandera falsa si no existe
		}
	}
	if(band == false){//si el usuario o la contraseña no existen 
			cout<<"Contrasena o usuario incorrectos. O usuario no registrado "<<endl;//se muestra el mensaje
			system("pause");
		}
		else{//si el usuario existe comparamos si inició un admin o un cliente
		if(strcmp(usua.c_str(),cade)==0){	
				sesion = true;//booleano verdadero para saber que hay sesion activa
				menu_admin(sesion,clien,n_clien);//si inicia un admin
			}else{
				sesion = true;//booleano de sesion activa
				menu_clien(sesion, nombre_hotel);//si inicia un cliente
			}
		}
}

//funcion menu del administrador
void menu_admin(bool &sesion,int &clien,int &n_clien){
	int op;
	//mostramos el menu para el admin
	do{
		do{
			system("cls");
			cout<<"0. Para Cerrar sesion"<<endl;
			cout<<"1. Para ver usuarios registrados"<<endl;
			cout<<"2. Para ver hoteles.\n";
			cout<<"3. Para ver comentarios.\n";
			cout<<"4. Para agregar hoteles.\n";
			cout<<"Que opcion desea: ";
			cin>>op;
			fflush(stdin);
		} while ((op>4) || (op<0));
			
			switch(op){
				
				case 1:
					system("cls");
					mostrarusuarios(clien,n_clien);
					break;
				
				case 2:
					system("cls");
					ver_hot(ciudad);
					break;
				
				case 3:
					system("cls");
					ver_coment();
					break;
				
				case 4:
					system("cls");
					agg_hot(ciudad);
					break;
				
			}
	}while(op != 0);
	
	system("cls");
	cout<<"==Ha finalizado sesion=="<<endl;	
	sesion = false;//booleano falso para finalizar sesion
	system("pause");
}

//funcion menu del cliente
void menu_clien(bool &sesion, string &nombre_hotel){
	int op;
	int opc;
	system("cls");
	
	//mostramos el menu para el cliente
	do{
		do{
			system("cls");
			cout<<"0. Para Cerrar sesion"<<endl;
			cout<<"1. Si desea ingresar los datos."<<endl;
	    	cout<<"2. Si desea ver los hoteles disponibles y escoger uno."<<endl;
	    	cout<<"3. Si desea ver los comentarios del hotel que escogio."<<endl;
	    	cout<<"4. Si desea ingresar un comentario."<<endl;
	    	cout<<"5. Si desea ver el costo total."<<endl;
	    	cout<<"6. Si desea confirmar la reserva o volver al inicio."<<endl;
			cout<<"Que opcion desea?: ";
			cin>>op;
			fflush(stdin);
		} while ((op>6) || (op<0));
			
		switch(op){
			case 1:
				system ("cls");
				llenardatos();
				break;
			
			case 2:
				system("cls");
				
				do{
					do{
						system("cls");
						cout<<"0. Para volver al menu anterior.\n";
						cout<<"1. Para ver los hoteles por orden de valoracion.\n";
						cout<<"2. Para ver los hoteles por orden de menor a mayor precio.\n";
						cout<<"3. Para ver los hoteles por orden de mayor a menor precio.\n";
						cin>>opc;
						fflush(stdin);
					} while ((opc>3) || (opc<0));
						
					switch (opc){
						
						case 1:
							system ("cls");
							mostrarhoteles_valoracion(ciudad, nombre_hotel);
							break;
						
						case 2:
							system ("cls");
							mostrarhoteles_preciom(ciudad, nombre_hotel);
							break;
						
						case 3:
							system ("cls");
							mostrarhoteles_precioM(ciudad, nombre_hotel);
							break;	
					}
				} while(opc!=0);
			
				break;
			
			case 3:
				system ("cls");
				comentarios(ciudad, nombre_hotel);
				break;
			
			case 4:
				system("cls");
				agg_coment();
				break;
			
			case 5:
				system("cls");
				precio_total(ciudad, nombre_hotel);
				break;
			
			case 6:
				system("cls");
				
				do{
					do{
						system("cls");
						cout<<"0. Para volver al menu anterior.\n";
						cout<<"1. Para confirmar la reserva.\n";
						cout<<"2. para cancelar todo.\n";
						cin>>opc;
						fflush(stdin);
					} while ((opc>3) || (opc<0));
				
					switch (opc){
						
						case 1:
							system("cls");
							confirmar();
							break;
						
						case 2:
							system("cls");
							cerrar();
							break;
						
					}
				} while(opc!=0);
				
				break;
			
		}
			
	}while(op != 0);
	system("cls");
	cout<<"==Ha finalizado sesion=="<<endl;
	sesion= false;//booleano falso para finalizar sesion
	system("pause");
}

//funcion para llenar la estructura desde los archivos
void llenar_struct_usu(int &clien,int &n_clien){
	//declaramos las cadenas donde guardamos los datos desde los archivos
	string nom, usu, pass, cedula;
	
	//declaramos las variables de archivos
	ifstream nombre,cedul,usuario,passw;
	
	//abrimos los archivos
	nombre.open("nombre.txt",ios::in);
	cedul.open("cedula.txt",ios::in);
	usuario.open("usuario.txt",ios::in);
	passw.open("passwords.txt",ios::in);
	
	clien=0;
	n_clien=0;
	while(getline(nombre,nom)){//mientras se obtengan nombres del archivo
		//guardamos en la estructura los datos 
		strcpy(usuarios[clien].nombre,nom.c_str());
		getline(cedul,cedula);
		strcpy(usuarios[clien].cedula,cedula.c_str());
		getline(usuario,usu);
		strcpy(usuarios[clien].usuario,usu.c_str());
		getline(passw,pass);
		strcpy(usuarios[clien].contrasena,pass.c_str());
		
		clien++;
		n_clien++;
	}
	//cerramos los archivos
	nombre.close();
	cedul.close();
	usuario.close();
	passw.close();
}


//--------------------------------------------------------------------------------------------------------------------------

//Funciones Usuario.

//funcion para reservar
void llenardatos(){
	
	do{
		cout<<"Ingrese el numero de personas: ";
		cin>>reserva.entradas;
	} while((reserva.entradas>4) || (reserva.entradas<=0));
	
	fflush(stdin);
	cout<<"\nIngrese el precio maximo de la habitacion por noche: ";
	cin>>reserva.precio;
	
	fflush(stdin);
	cout<<"\nIngrese la fecha de llegada.\n";
	do{
		cout<<"Dia: "; cin>>reserva.llegada.dia;
	} while (reserva.llegada.dia > 30);
	
	do{
		cout<<"Mes: "; cin>>reserva.llegada.mes;
	} while(reserva.llegada.mes > 12);
	
	cout<<"Año: "; cin>>reserva.llegada.anio;
	
	do{
		cout<<"Hora: "; cin>>reserva.llegada.hora;
	} while(reserva.llegada.hora > 24);
	
	fflush(stdin);
	cout<<"\nIngrese la fecha de salida.\n";
	
	do{
		cout<<"Dia: "; cin>>reserva.salida.dia;
	} while (reserva.salida.dia > 30);
	
	do{
		cout<<"Mes: "; cin>>reserva.salida.mes;
	} while (reserva.salida.mes > 12);
	
	cout<<"Año: "; cin>>reserva.salida.anio;
	
	do{
		cout<<"Hora: "; cin>>reserva.salida.hora;
	} while (reserva.salida.hora > 24);
	
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

//funcion que muestra los hoteles
void mostrarhoteles(ciudades &ciudad, string &nombre_hotel){
	
	system ("cls");
    getchar();
    FILE *archdisco;
    archdisco = fopen("Hoteles.txt","at+");
	
    while(fread(&ciudad,sizeof(ciudad),1,archdisco)==1){
    	
        if ((reserva.hotel.ciudad == ciudad.ciudad) && (reserva.hotel.estrellas <= ciudad.estrellas) &&
		    (reserva.hotel.puntuacion <= ciudad.puntuacion) && (reserva.filtros.piscina <= ciudad.piscina) &&
			(reserva.filtros.parqueadero <= ciudad.parqueadero) && (reserva.filtros.restaurante <= ciudad.restaurante) &&
			(reserva.precio>=ciudad.precio) && (reserva.entradas == ciudad.personas) && (ciudad.hab_disp > 0)){
				
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
            fflush(stdin);
            
            cout<<"Personas: "<<ciudad.personas<<endl;
            fflush(stdin);
            
            cout<<"Habitaciones disponibles: "<<ciudad.hab_disp<<endl;
            cout<<"\n";
        }
        
    }
           fclose(archdisco);
           cout<<"Ingrese el nombre del hotel que desea escoger:";
           cin>>nombre_hotel;
}

//__________________________________________________________________________________________________________________________
//__________________________________________________________________________________________________________________________

//mostrar hoteles por valoracion
void mostrarhoteles_valoracion(ciudades &ciudad, string &nombre_hotel){
	
	int i=0;
	system ("cls");
    getchar();
    FILE *archdisco;
    archdisco = fopen("Hoteles.txt","at+");
	
    while(fread(&ciudad,sizeof(ciudad),1,archdisco)==1){
    	
        if ((reserva.hotel.ciudad == ciudad.ciudad) && (reserva.hotel.estrellas <= ciudad.estrellas) &&
		    (reserva.hotel.puntuacion <= ciudad.puntuacion) && (reserva.filtros.piscina <= ciudad.piscina) &&
			(reserva.filtros.parqueadero <= ciudad.parqueadero) && (reserva.filtros.restaurante <= ciudad.restaurante) &&
			(reserva.precio>=ciudad.precio) && (reserva.entradas == ciudad.personas) && (ciudad.hab_disp > 0)){
				
            vec[i].ciudad = ciudad.ciudad;
            vec[i].hotel = ciudad.hotel;
            vec[i].puntuacion = ciudad.puntuacion;
            vec[i].estrellas = ciudad.estrellas;
            vec[i].piscina = ciudad.piscina;
            vec[i].parqueadero = ciudad.parqueadero;
            vec[i].restaurante = ciudad.restaurante;
            vec[i].precio = ciudad.precio;
            vec[i].personas = ciudad.personas;
            vec[i].hab_disp = ciudad.hab_disp;
            i++;
        }
        
    }
    
    for (int j=0; j<i; j++){
    	
    	for (int n=0; n<i; n++){
    		
    		if (vec[n].puntuacion < vec[n+1].puntuacion){
    			aux.ciudad = vec[n].ciudad;
            	aux.hotel = vec[n].hotel;
            	aux.puntuacion = vec[n].puntuacion;
            	aux.estrellas = vec[n].estrellas;
            	aux.piscina = vec[n].piscina;
            	aux.parqueadero = vec[n].parqueadero;
            	aux.restaurante = vec[n].restaurante;
            	aux.precio = vec[n].precio;
            	aux.personas = vec[n].personas;
            	aux.hab_disp = vec[n].hab_disp;
            	
            	vec[n].ciudad = vec[n+1].ciudad;
	            vec[n].hotel = vec[n+1].hotel;
    	        vec[n].puntuacion = vec[n+1].puntuacion;
        	    vec[n].estrellas = vec[n+1].estrellas;
            	vec[n].piscina = vec[n+1].piscina;
	            vec[n].parqueadero = vec[n+1].parqueadero;
    	        vec[n].restaurante = vec[n+1].restaurante;
        	    vec[n].precio = vec[n+1].precio;
            	vec[n].personas = vec[n+1].personas;
            	vec[n].hab_disp = vec[n+1].hab_disp;
            	
            	vec[n+1].ciudad = aux.ciudad;
	            vec[n+1].hotel = aux.hotel;
    	        vec[n+1].puntuacion = aux.puntuacion;
        	    vec[n+1].estrellas = aux.estrellas;
            	vec[n+1].piscina = aux.piscina;
	            vec[n+1].parqueadero = aux.parqueadero;
    	        vec[n+1].restaurante = aux.restaurante;
        	    vec[n+1].precio = aux.precio;
            	vec[n+1].personas = aux.personas;
            	vec[n+1].hab_disp = aux.hab_disp;
            
			}
			
		}
			
	}
    
    for (int n=0; n<i; n++){
    	
    	cout<<"Ciudad: "<<vec[n].ciudad<<endl;
        fflush(stdin);
        
        cout<<"Nombre del hotel: "<<vec[n].hotel<<endl;
        fflush(stdin);
        
        cout<<"Puntuacion: "<<vec[n].puntuacion<<endl;
        fflush(stdin);
        
        cout<<"Estrellas: "<<vec[n].estrellas<<endl;
        fflush(stdin);
        
        cout<<"Piscina?: "<<vec[n].piscina<<endl;
        fflush(stdin);
        
        cout<<"Parqueadero?: "<<vec[n].parqueadero<<endl;
        fflush(stdin);
        
        cout<<"Restaurante?: "<<vec[n].restaurante<<endl;
        fflush(stdin);

        cout<<"Precio por noche: "<<vec[n].precio<<endl;
        fflush(stdin);
        
        cout<<"Personas: "<<vec[n].personas<<endl;
        fflush(stdin);
        
        cout<<"Habitaciones disponibles: "<<vec[n].hab_disp<<endl;
        cout<<"\n";
	}
    
    fclose(archdisco);
    
    if (i==0){
    	cout<<"Ningun hotel cumple estas caracteristicas.\n\n";
	}
	else{
		cout<<"Ingrese el nombre del hotel que desea escoger:";
    	cin>>nombre_hotel;
    	cout<<endl;
	}
	system("pause");
}

//__________________________________________________________________________________________________________________________
//mostrar hoteles por precio
void mostrarhoteles_precioM(ciudades &ciudad, string &nombre_hotel){
	
	int i=0;
	system ("cls");
    getchar();
    FILE *archdisco;
    archdisco = fopen("Hoteles.txt","at+");
	
    while(fread(&ciudad,sizeof(ciudad),1,archdisco)==1){
    	
        if ((reserva.hotel.ciudad == ciudad.ciudad) && (reserva.hotel.estrellas <= ciudad.estrellas) &&
		    (reserva.hotel.puntuacion <= ciudad.puntuacion) && (reserva.filtros.piscina <= ciudad.piscina) &&
			(reserva.filtros.parqueadero <= ciudad.parqueadero) && (reserva.filtros.restaurante <= ciudad.restaurante) &&
			(reserva.precio>=ciudad.precio) && (reserva.entradas == ciudad.personas) && (ciudad.hab_disp > 0)){
				
            vec[i].ciudad = ciudad.ciudad;
            vec[i].hotel = ciudad.hotel;
            vec[i].puntuacion = ciudad.puntuacion;
            vec[i].estrellas = ciudad.estrellas;
            vec[i].piscina = ciudad.piscina;
            vec[i].parqueadero = ciudad.parqueadero;
            vec[i].restaurante = ciudad.restaurante;
            vec[i].precio = ciudad.precio;
            vec[i].personas = ciudad.personas;
            vec[i].hab_disp = ciudad.hab_disp;
            i++;
        }
        
    }
    
    for (int j=0; j<i; j++){
    	
    	for (int n=0; n<i-1; n++){
    		
    		if (vec[n].precio < vec[n+1].precio){
    			aux.ciudad = vec[n].ciudad;
            	aux.hotel = vec[n].hotel;
            	aux.puntuacion = vec[n].puntuacion;
            	aux.estrellas = vec[n].estrellas;
            	aux.piscina = vec[n].piscina;
            	aux.parqueadero = vec[n].parqueadero;
            	aux.restaurante = vec[n].restaurante;
            	aux.precio = vec[n].precio;
            	aux.personas = vec[n].personas;
            	aux.hab_disp = vec[n].hab_disp;
            	
            	vec[n].ciudad = vec[n+1].ciudad;
	            vec[n].hotel = vec[n+1].hotel;
    	        vec[n].puntuacion = vec[n+1].puntuacion;
        	    vec[n].estrellas = vec[n+1].estrellas;
            	vec[n].piscina = vec[n+1].piscina;
	            vec[n].parqueadero = vec[n+1].parqueadero;
    	        vec[n].restaurante = vec[n+1].restaurante;
        	    vec[n].precio = vec[n+1].precio;
            	vec[n].personas = vec[n+1].personas;
            	vec[n].hab_disp = vec[n+1].hab_disp;
            	
            	vec[n+1].ciudad = aux.ciudad;
	            vec[n+1].hotel = aux.hotel;
    	        vec[n+1].puntuacion = aux.puntuacion;
        	    vec[n+1].estrellas = aux.estrellas;
            	vec[n+1].piscina = aux.piscina;
	            vec[n+1].parqueadero = aux.parqueadero;
    	        vec[n+1].restaurante = aux.restaurante;
        	    vec[n+1].precio = aux.precio;
            	vec[n+1].personas = aux.personas;
            	vec[n+1].hab_disp = aux.hab_disp;
            
			}
			
		}
			
	}
    
    for (int n=0; n<i; n++){
    	
    	cout<<"Ciudad: "<<vec[n].ciudad<<endl;
        fflush(stdin);
        
        cout<<"Nombre del hotel: "<<vec[n].hotel<<endl;
        fflush(stdin);
        
        cout<<"Puntuacion: "<<vec[n].puntuacion<<endl;
        fflush(stdin);
        
        cout<<"Estrellas: "<<vec[n].estrellas<<endl;
        fflush(stdin);
        
        cout<<"Piscina?: "<<vec[n].piscina<<endl;
        fflush(stdin);
        
        cout<<"Parqueadero?: "<<vec[n].parqueadero<<endl;
        fflush(stdin);
        
        cout<<"Restaurante?: "<<vec[n].restaurante<<endl;
        fflush(stdin);

        cout<<"Precio por noche: "<<vec[n].precio<<endl;
        fflush(stdin);
        
        cout<<"Personas: "<<vec[n].personas<<endl;
        fflush(stdin);
        
        cout<<"Habitaciones disponibles: "<<vec[n].hab_disp<<endl;
        cout<<"\n";
	}
    
    fclose(archdisco);
    
    if (i==0){
    	cout<<"Ningun hotel cumple estas caracteristicas.\n\n";
	}
	else{
		cout<<"Ingrese el nombre del hotel que desea escoger:";
    	cin>>nombre_hotel;
    	cout<<endl;
	}
	system("pause");
}

//__________________________________________________________________________________________________________________________
//mostrar hoteles por precio menor
void mostrarhoteles_preciom(ciudades &ciudad, string &nombre_hotel){
	
	int i=0;
	system ("cls");
    getchar();
    FILE *archdisco;
    archdisco = fopen("Hoteles.txt","at+");
	
    while(fread(&ciudad,sizeof(ciudad),1,archdisco)==1){
    	
        if ((reserva.hotel.ciudad == ciudad.ciudad) && (reserva.hotel.estrellas <= ciudad.estrellas) &&
		    (reserva.hotel.puntuacion <= ciudad.puntuacion) && (reserva.filtros.piscina <= ciudad.piscina) &&
			(reserva.filtros.parqueadero <= ciudad.parqueadero) && (reserva.filtros.restaurante <= ciudad.restaurante) &&
			(reserva.precio>=ciudad.precio) && (reserva.entradas == ciudad.personas) && (ciudad.hab_disp > 0)){
				
            vec[i].ciudad = ciudad.ciudad;
            vec[i].hotel = ciudad.hotel;
            vec[i].puntuacion = ciudad.puntuacion;
            vec[i].estrellas = ciudad.estrellas;
            vec[i].piscina = ciudad.piscina;
            vec[i].parqueadero = ciudad.parqueadero;
            vec[i].restaurante = ciudad.restaurante;
            vec[i].precio = ciudad.precio;
            vec[i].personas = ciudad.personas;
            vec[i].hab_disp = ciudad.hab_disp;
            i++;
        }
        
    }
    
    for (int j=0; j<i; j++){
    	
    	for (int n=0; n<i-1; n++){
    		
    		if (vec[n].precio < vec[n+1].precio){
    			aux.ciudad = vec[n].ciudad;
            	aux.hotel = vec[n].hotel;
            	aux.puntuacion = vec[n].puntuacion;
            	aux.estrellas = vec[n].estrellas;
            	aux.piscina = vec[n].piscina;
            	aux.parqueadero = vec[n].parqueadero;
            	aux.restaurante = vec[n].restaurante;
            	aux.precio = vec[n].precio;
            	aux.personas = vec[n].personas;
            	aux.hab_disp = vec[n].hab_disp;
            	
            	vec[n].ciudad = vec[n+1].ciudad;
	            vec[n].hotel = vec[n+1].hotel;
    	        vec[n].puntuacion = vec[n+1].puntuacion;
        	    vec[n].estrellas = vec[n+1].estrellas;
            	vec[n].piscina = vec[n+1].piscina;
	            vec[n].parqueadero = vec[n+1].parqueadero;
    	        vec[n].restaurante = vec[n+1].restaurante;
        	    vec[n].precio = vec[n+1].precio;
            	vec[n].personas = vec[n+1].personas;
            	vec[n].hab_disp = vec[n+1].hab_disp;
            	
            	vec[n+1].ciudad = aux.ciudad;
	            vec[n+1].hotel = aux.hotel;
    	        vec[n+1].puntuacion = aux.puntuacion;
        	    vec[n+1].estrellas = aux.estrellas;
            	vec[n+1].piscina = aux.piscina;
	            vec[n+1].parqueadero = aux.parqueadero;
    	        vec[n+1].restaurante = aux.restaurante;
        	    vec[n+1].precio = aux.precio;
            	vec[n+1].personas = aux.personas;
            	vec[n+1].hab_disp = aux.hab_disp;
            
			}
			
		}
			
	}
    
    for (int n=i-1; n>=0; n--){
    	
    	cout<<"Ciudad: "<<vec[n].ciudad<<endl;
        fflush(stdin);
        
        cout<<"Nombre del hotel: "<<vec[n].hotel<<endl;
        fflush(stdin);
        
        cout<<"Puntuacion: "<<vec[n].puntuacion<<endl;
        fflush(stdin);
        
        cout<<"Estrellas: "<<vec[n].estrellas<<endl;
        fflush(stdin);
        
        cout<<"Piscina?: "<<vec[n].piscina<<endl;
        fflush(stdin);
        
        cout<<"Parqueadero?: "<<vec[n].parqueadero<<endl;
        fflush(stdin);
        
        cout<<"Restaurante?: "<<vec[n].restaurante<<endl;
        fflush(stdin);

        cout<<"Precio por noche: "<<vec[n].precio<<endl;
        fflush(stdin);
        
        cout<<"Personas: "<<vec[n].personas<<endl;
        fflush(stdin);
        
        cout<<"Habitaciones disponibles: "<<vec[n].hab_disp<<endl;
        cout<<"\n";
	}
    
    fclose(archdisco);
    
    if (i==0){
    	cout<<"Ningun hotel cumple estas caracteristicas.\n\n";
	}
	else{
		cout<<"Ingrese el nombre del hotel que desea escoger:";
    	cin>>nombre_hotel;
    	cout<<endl;
	}
	system("pause");
}

//__________________________________________________________________________________________________________________________
//__________________________________________________________________________________________________________________________

//mostrar comentarios
void comentarios(ciudades &ciudad, string &nombre_hotel){
	
	system ("cls");
	getchar();
    FILE *archdisco;
    archdisco = fopen("Comentarios.txt","at+");
    cout<<"Escogio el hotel: "<<nombre_hotel<<endl<<endl;
    
    while (fread(&comentario,sizeof(comentario),1,archdisco)==1){
    	
    	if ((nombre_hotel == comentario.hotell)  && (reserva.hotel.ciudad == comentario.ciudadd)){
    		
    		fflush(stdin);
        	cout<<"Usuario: "<<comentario.nombre<<endl;
        	fflush(stdin);
        	
        	cout<<"Ciudad: "<<comentario.ciudadd<<endl;
        	fflush(stdin);
    		
        	cout<<"Nombre del hotel: "<<comentario.hotell<<endl;
        	fflush(stdin);
      		
        	cout<<"Puntuacion: "<<comentario.puntuacion<<endl;
        	fflush(stdin);
    		
        	cout<<"Comentario: "<<comentario.comentario<<endl;
        	fflush(stdin);
        	cout<<endl;
		}
		
    }
    
    fclose(archdisco);
}


//agregar comentario
void agg_coment(){
	
	fflush(stdin);
    cout<<"Digite su nombre: "; cin.getline(comentario.nombre,30,'\n');
    fflush(stdin);
    
    cout<<"Digite la ciudad: "; cin.getline(comentario.ciudadd,15,'\n');
    fflush(stdin);
    
    cout<<"Digite el nombre del hotel: "; cin.getline(comentario.hotell,30,'\n');
    fflush(stdin);
    
    cout<<"Digite la puntuacion: "; cin>>comentario.puntuacion;
    fflush(stdin);
    
    cout<<"Digite el comentario: "; cin.getline(comentario.comentario,500,'\n');
    fflush(stdin);
    cout<<endl;
    
    FILE *archdisco;
	archdisco = fopen("Comentarios.txt","at+");
    fwrite(&comentario,sizeof(comentario),1,archdisco);
    fclose(archdisco);
    system("pause");
    cout<<"datos insertados"<<endl;
}

//--------------------------------------------------------------------------------------------------------------------------

//Funciones Admin

//agregar hoteles
void agg_hot(ciudades &ciudad){
	
	fflush(stdin);
	cout<<"Digite la ciudad: "; cin.getline(ciudad.ciudad,15,'\n');
    fflush(stdin);
    
    cout<<"Digite el nombre del hotel: "; cin.getline(ciudad.hotel,30,'\n');
    fflush(stdin);
    
    cout<<"Digite la puntuacion: "; cin>>ciudad.puntuacion;
    fflush(stdin);
    
    cout<<"Digite las estrellas: "; cin>>ciudad.estrellas;
    fflush(stdin);
    
    cout<<"Tiene piscina?: "; cin>>ciudad.piscina;
    fflush(stdin);
    
    cout<<"Tiene parqueadero?: "; cin>>ciudad.parqueadero;
    fflush(stdin);
    
    cout<<"Tiene restaurante?: "; cin>>ciudad.restaurante;
    fflush(stdin);
    
    cout<<"Precio por noche: "; cin>>ciudad.precio;
    fflush(stdin);
    
    cout<<"Numero de personas: "; cin>>ciudad.personas;
    fflush(stdin);
    
    cout<<"Habitaciones disponibles: "; cin>>ciudad.hab_disp;
    fflush(stdin);
    cout<<endl;
    
    FILE *archdisco;
	archdisco = fopen("Hoteles.txt","at+");
    fwrite(&ciudad,sizeof(ciudad),1,archdisco);
    fclose(archdisco);
    system("pause");
    cout<<"datos insertados"<<endl;
}

//ver los hoteles agregados
void ver_hot(ciudades &ciudad){
	
	FILE *archdisco;
    archdisco = fopen("Hoteles.txt","at+");
    
	while (fread(&ciudad,sizeof(ciudad),1,archdisco)==1){
		
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
    fflush(stdin);
    
    cout<<"Personas: "<<ciudad.personas<<endl;
    fflush(stdin);
    
    cout<<"Habitaciones disponibles: "<<ciudad.hab_disp<<endl;
    cout<<"\n";
	}
    
    system("pause");
    fclose(archdisco); 
}


//ver comentarios
void ver_coment(){
	
	FILE *archdisco;
    archdisco = fopen("Comentarios.txt","at+");
    
    while (fread(&comentario,sizeof(comentario),1,archdisco)==1){
        
        fflush(stdin);
        cout<<"Usuario: "<<comentario.nombre<<endl;
        fflush(stdin);
        
        cout<<"Ciudad: "<<comentario.ciudadd<<endl;
        fflush(stdin);
    
        cout<<"Nombre del hotel: "<<comentario.hotell<<endl;
        fflush(stdin);
      
        cout<<"Puntuacion: "<<comentario.puntuacion<<endl;
        fflush(stdin);
    
        cout<<"Comentario: "<<comentario.comentario<<endl;
        fflush(stdin);
        cout<<endl;
	   }
	  
	system("pause");   
    fclose(archdisco); 
}
//funcion para mostrar usuarios
void mostrarusuarios(int &clien,int &n_clien){
	for(clien=0; clien < n_clien;clien++){
		cout<<"Usuario #"<<clien+1<<endl;
		cout<<"Nombre: "<<usuarios[clien].nombre<<endl;
		cout<<"Cedula: "<<usuarios[clien].cedula<<endl;
		cout<<"Usuario: "<<usuarios[clien].usuario<<endl;
		cout<<"Contraseña: "<<usuarios[clien].contrasena<<endl;
		cout<<endl;
	}
	system("pause");
}

void precio_total(ciudades &ciudad, string &nombre_hotel){
	
	getchar();
	int op;
	int mes1_1;
	mes1_1 = reserva.llegada.mes;
	
	if (mes1_1==12){
		mes1_1=0;
	}
	
	if (reserva.salida.anio-reserva.llegada.anio >= 2){
		cout<<"No existen reservas para tantos dias.\n";
	}
	else if (((reserva.salida.mes*30+reserva.salida.dia)-(mes1_1*30+reserva.llegada.dia) >= 15) || (mes1_1 > reserva.salida.mes)){
		cout<<"No existen reservas para tantos dias.\n";
	}
	else{
		while (reserva.llegada.hora != reserva.salida.hora){
			if (reserva.llegada.hora == 25){
				reserva.llegada.hora=1;
			}
			
			reserva.llegada.hora++;
			horas++;
		}
		
		while (reserva.llegada.dia != reserva.salida.dia){
			if (reserva.llegada.dia == 31){
				reserva.llegada.dia = 1;
			}
			reserva.llegada.dia++;
			dias++;
		}
		cout<<"Usted estara "<<dias<<" Dias y "<<horas<<" Horas."<<endl;
	}
	
	cout<<"Su costo total sera: ";
	
    FILE *archdisco;
    archdisco = fopen("Hoteles.txt","at+");
    
    while (fread(&ciudad,sizeof(ciudad),1,archdisco)==1){
    	
    	if ((nombre_hotel == ciudad.hotel) && (reserva.hotel.ciudad == ciudad.ciudad) &&
		(reserva.entradas == ciudad.personas)){
    		
    		cout<<ciudad.precio*dias + ((ciudad.precio/24)*horas);
    		cout<<endl;
    		system("pause");
		}
		
    }
    
	system("pause");
    fclose(archdisco);

}

void confirmar(){
	
	
	
	cout<<"Su reserva se ha realizado con exito."<<endl;
	system ("pause");
	cerrar();
}

int cerrar(){
	system ("cls");
	return main();
}
