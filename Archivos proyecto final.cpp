#include <cstdlib>
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;


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

int main(){
	
	int op;
	
	do{
	
	cin>>op;
	
	switch (op){
	case 1:
	system ("cls");
    //captura de campos.
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
    cout<<endl;
    
    FILE *archdisco;
	archdisco = fopen("Hoteles.txt","at+");
    fwrite(&ciudad,sizeof(ciudad),1,archdisco);
    fclose(archdisco);
    
    
    cout<<"datos insertados";
    break;
    
    case 2:
    system ("cls");
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
    cout<<"\n";
	}
    
    fclose(archdisco); 
    break;
	
}
    
	} while (op!=0);
    
    system("pause");
    return 0;
}
