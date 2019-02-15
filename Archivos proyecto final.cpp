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
       
struct comentarios{
    float puntuacion;
    char ciudadd[15];
    char hotell[30];
    string comentario;
    }comentario;

int main(){
	
	int op;
	
	do{
	cout<<"1. Para agregar hotel.\n";
	cout<<"2. Para ver hoteles.\n";
	cout<<"3. Para agregar comentarios.\n";
	cout<<"4. Para ver comentarios.\n";
	cin>>op;
	
	switch (op){
        
	case 1:
	system ("cls");
	
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
    
    cout<<"datos insertados"<<endl;
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
	
	case 3:
    system("cls");    
        
    fflush(stdin);
    cout<<"Digite la ciudad: "; cin.getline(comentario.ciudadd,15,'\n');
    fflush(stdin);
    
    cout<<"Digite el nombre del hotel: "; cin.getline(comentario.hotell,30,'\n');
    fflush(stdin);
    
    cout<<"Digite la puntuacion: "; cin>>comentario.puntuacion;
    fflush(stdin);
    
    cout<<"Digite el comentario: "; cin>>comentario.comentario;
    fflush(stdin);
    cout<<endl;
    
	archdisco = fopen("Comentarios.txt","at+");
    fwrite(&comentario,sizeof(comentario),1,archdisco);
    fclose(archdisco);
    
    cout<<"datos insertados"<<endl;
    break;
    
    case 4:
    system ("cls");
    archdisco = fopen("Comentarios.txt","at+");
    
    while (fread(&comentario,sizeof(comentario),1,archdisco)==1){
        
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
	   
    fclose(archdisco); 
    break;
    }
    
	} while (op!=0);
    
    system("pause");
    return 0;
}
