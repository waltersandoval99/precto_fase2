#include <iostream>
#include <fstream>
#include <windows.h>


using namespace std;
	
int menu(){
	int x;
	system("cls");
	cout<<"========BIENBENIDO======="<<endl<<endl;
	cout<<"1. Agregar Palbra"<<endl;
	cout<<"2. Ver Palbras"<<endl;
	cout<<"3. Traductor"<<endl;
	cout<<"4. modificar palabra"<<endl;
	cout<<"5. Eliminar palabra"<<endl;
	cout<<"6. Salir"<<endl;
	cout<<"========================="<<endl;
	cout<<"Opcion: ";
	cin>>x;
	return x;
		
}

bool verifica(string Ingles){
 ifstream leer ("registro.txt", ios::in);
 string ingles;
 string des;
 string Esp;
 leer>>ingles;
 while(!leer.eof()){
  leer>>Esp;
  leer>>des;
  if(ingles == Ingles){
   cout<<"\n\n\tError: Registro duplicado.\n\n";
   system("pause");
   leer.close();
   return false;
  }
  leer>>ingles;
 }
   leer.close();
   return true; 
}
void agregar(ofstream &es) {
	system("cls");
	string ingles;
	string Esp;
	string des;
	es.open("registro.txt", ios::out| ios::app);
	cout<<"ingles:  ";
	cin>>ingles;
	cout<<"Español:  ";
	cin>>Esp;
	cout<<"Descripcion:  ";
	cin>>des;
	if(verifica(ingles))
		es<<ingles<<" "<<Esp<<" "<<des<<"\n";
	es.close();
	}

void verRegistros(ifstream &Lec){
	system("cls");
	string ingles;
 	string des;
 	string Esp;
 	Lec.open("registro.txt", ios::in);
 	if(Lec.is_open()){
	 	cout<<"-------Palabras guardadas-------"<<endl<<endl;
	 	Lec>>ingles;
	 	while(!Lec.eof()){
			Lec>>Esp;
			Lec>>des;
			cout<<"==Ingles=======: "<<ingles<<endl;
			cout<<"==español======: "<<Esp<<endl;
			cout<<"==Descripcion==: "<<des<<endl;
			cout<<"----------------------"<<endl;
			Lec>>ingles;
		 }
		 Lec.close();
	}else
		cout<<"Error"<<endl;
	 system("pause");
}



void buscarpalabra(ifstream &Lec){
	system("cls");
	Lec.open("registro.txt", ios::in);
	string ingles, Esp, des, inglesaux;
	bool encontrado = false;
	cout<<"Digite su palabra en Ingles: ";
	cin>>inglesaux;
	Lec>>des;
	while(! Lec.eof() && !encontrado){	
		Lec>>Esp;
		Lec>>des;
	
		if(ingles == inglesaux){
			cout<<"==Ingles=======: "<<ingles<<endl;
			cout<<"==español======: "<<Esp<<endl;
			cout<<"==Descripcion==: "<<des<<endl;
			cout<<"----------------------"<<endl;
			encontrado = true;
		}	
		Lec>>ingles;
	}
	Lec.close();
	
	if(!encontrado)
		cout<<"DATO NO ENCONTRADO"<<endl<<endl;
	system("pause");
}

void modificar(ifstream &Lec){
	system("cls");
 	string Esp;
 	string ingles;
	string des;
	string inglesaux;
	string Espaux;
	string desaux;
	Lec.open("registro.txt", ios::in);
	ofstream aux("auxiliar.txt", ios::out);
	if(Lec.is_open()){
		cout<<"--------------Palabras a modificar--------------------"<<endl;
		cout<<"Ingles dato:  ";
		cin>>inglesaux;
		Lec>>ingles;
		while(!Lec.eof()){
		  	Lec>>Esp;
			Lec>>des;
			
			if(ingles == inglesaux){
				cout<<"--------------------------------------"<<endl;
				cout<<"Ingr. palabra en espanol:  ";
				cin>>Espaux;
				cout<<"--------------------------------------"<<endl;
				cout<<"Ingrese el descripcion:    ";
				cin>>desaux;
				aux<<ingles<<" "<<Espaux<<" "<<desaux<<"\n";
				cout<<"--------------------------------------"<<endl;
			}else{
				aux<<ingles<<" "<<Esp<<" "<<des<<"\n";
			}
			
			Lec>>ingles;
			Lec>>des;
		}
		Lec.close();
		aux.close();
	}else 
		cout<<"Error"<<endl;
	remove ("registro.txt");
	rename("auxiliar.txt", "registro.txt");
}

void eliminar(ifstream &Lec){
	system("cls");
 	string Esp;
 	string ingles;
	string des;
	string inglesaux;
	string Espaux;
	string desaux;
	Lec.open("registro.txt", ios::in);
	ofstream aux("auxiliar.txt", ios::out);
	if(Lec.is_open()){
		cout<<"--------------Palabras a modificar--------------------"<<endl;
		cout<<"Ingles dato:  ";
		cin>>inglesaux;
		Lec>>ingles;
		while(!Lec.eof()){
		  	Lec>>Esp;
			Lec>>des;
			
			if(ingles == inglesaux){
				cout<<"--------------------------------------"<<endl;
				cout<<"------Fue eliminada existosamente-----"<<endl;
				Sleep(1500);
				cout<<"--------------------------------------"<<endl;
			}else{
				aux<<ingles<<" "<<Esp<<" "<<des<<"\n";
				
			}
			
			Lec>>ingles;
			Lec>>des;
		}
		Lec.close();
		aux.close();
	}else 
		cout<<"Error"<<endl;
	remove ("registro.txt");
	rename("auxiliar.txt", "registro.txt");	
	
}

int main(){
	ofstream Esc;
	ifstream Lec;
	int op;
	do{
		
		system("cls");
		op = menu();
		switch(op){
			case 1:
				agregar(Esc);
			break;
			case 2:
				verRegistros(Lec);
			break;
			case 3:
				buscarpalabra(Lec);
			break;
			case 4:
				modificar(Lec);
			break;
			case 5:
				eliminar(Lec);
			break;	
		}	
	}while(op != 6);
	return 0;
}
