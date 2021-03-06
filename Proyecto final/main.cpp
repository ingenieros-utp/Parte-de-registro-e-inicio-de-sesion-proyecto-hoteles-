#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <ctime>
#include <fstream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;


int n_clien=0, n_hot,clien=0, cli=2;
bool sesion, admin ,client = 0;

void registrar();
void inic_sesion();
void menu_admin();
void menu_clien();
void llenar_struct_usu();

struct Usuario {
	char nombre[40];
	char contrasena[10];
	char usuario[20];
	char cedula[10];
}usuarios[100];

struct habitacion {
	int id_hab;
	char clasificacion[30];
	bool libre;
};

struct Hoteles{
	int codigo;
	char nombre[40];
	int valoracion;
	int n_habt;
	char ciudad;
	struct habitacion habitac;
	bool piscina;
	bool parquer;
	bool restuar;
}hotel[100];

int main() {
	int opc;
	llenar_struct_usu();
	
	cout<<"\tBienvenido"<<endl;
	Sleep(1000);
	system("cls");
	//mostramos el menu principal
	do{
		system("cls");
		cout<<"1. Registrar"<<endl;
		cout<<"2. Iniciar Sesion"<<endl;
		cout<<"3. Salir"<<endl;
		cout<<"Opcion: "; cin>>opc;
		fflush(stdin);
		
		switch(opc){
			case 1:
				registrar();
				break;
			case 2:
				inic_sesion();
				//system("pause");
				break;	
		}
	}while(opc<3);
	
	return 0;
}

//funcion para registrar el usuario, sea un cliente o un administrador
void registrar(){
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
void inic_sesion(){
	system("cls");
	cli=4;
	char cade[]="admin";
	string usua,clave;
	bool band;
	//pedimos al cliente o al administrador su usuario y contraseņa
	cout<<"Usuario: "; getline(cin,usua,'\n'); fflush(stdin);
	cout<<"Contrasena: "; getline(cin,clave,'\n'); fflush(stdin);
	system("cls");
	//buscamos en la estructura el usuario y la contraseņa de quien inicia sesion
	for(int i = 0; i < cli;i++){
		//comparamos en la estructura
		if((strcmp(usua.c_str(),usuarios[i].usuario)==0) && (strcmp(clave.c_str(),usuarios[i].contrasena)==0)){
			band = true;//bandera verdarera si la encuentra
			break;
		}else{
			band = false;//bandera falsa si no existe
		}
	}
	if(band == false){//si el usuario o la contraseņa no existen 
			cout<<"Contrasena o usuario incorrectos. O usuario no registrado "<<endl;//se muestra el mensaje
			system("pause");
		}else{//si el usuario existe comparamos si inicio un admin o un cliente
		if(strcmp(usua.c_str(),cade)==0){
				menu_admin();//si inicia un admin
				sesion = true;//booleano verdadero para saber que hay sesion activa
			}else{
				menu_clien();//si inicia un cliente
				sesion = true;//booleano de sesion activa
			}
		}
}

//funcion menu del administrador
void menu_admin(){
	int opc;
	//system("pause");
	Hoteles hotel;
	system("cls");
	//mostramos el menu para el admin
		do{
		cout<<"1. Registrar Hotel"<<endl;
		cout<<"2. Ver historial de reservas"<<endl;
		cout<<"3. Cerrar sesion"<<endl;
		cout<<"opcion: "; cin>>opc; fflush(stdin);
		//switch(opc){
		//	case 1
		
	}while(opc < 3);
	sesion = false;//booleano falso para finalizar sesion
	system("pause");
}

//funcion menu del cliente
void menu_clien(){
	int opc;
	system("cls");
	do{
	cout<<"1. Cerrar sesion"<<endl;
	cout<<"opcion: "; cin>>opc; fflush(stdin); 
	}while(opc<1);
	sesion= false;//booleano falso para finalizar sesion
	system("pause");
}
//funcion para llenar la estructura desde los archivos
void llenar_struct_usu(){
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
	
	while(getline(nombre,nom)){//mientras se obtengan nombres del archivo
		//guardamos en la estructura los datos 
		getline(nombre,nom);
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
