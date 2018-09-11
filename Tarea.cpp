
/*
	Diego René Melendez Alvarado 				00174118
	Christian Alexander Contreras Bolaños		00149618
	Pedro Enrique Menjivar Hernández  			00056118


*/


#include <iostream>
using namespace std;



void Menu();

struct Nodo
{
	int dato;
	Nodo*sig;
};

class Lista
{
private:
	Nodo*lsinicio;
public:
	Lista(); // constructor
	void Insertarls(int); // Insertar valores
	void mostrar_lista(void); // Mostrar lista
	void Sumaelementos(void);//Funcion iterativa de cantidad de elementos 	
	int SumaelementosRec(Nodo*/*,int*/); //Funcion recursiva de cantidad de elementos
	void ingresodatos();
	void inicSumaRec();


};

Lista::Lista(void){
	lsinicio=NULL;
}

void Lista::mostrar_lista(void){
	Nodo*s;
	s=lsinicio;

	while(s!=NULL){
		
		cout<<s->dato<<endl;
		s=s->sig;
	}
}

void Lista::Insertarls(int dato){
	Nodo*nuevo= new Nodo;
	nuevo->dato=dato;
	nuevo->sig=lsinicio;
	lsinicio=nuevo;
}
void Lista::Sumaelementos(){
	int Numero=0;
	Nodo*s;
	s=lsinicio;

	while(s!=NULL){
		Numero++;
		//cout<<s<<endl;
		s=s->sig; 
	}
	cout<<endl<<endl<<"Actualmente en la lista hay "<<Numero<<" elementos contados de manera iterativa."<<endl;
	cout<<endl;
}

int Lista::SumaelementosRec(Nodo*list/*,int number*/){

	//cout<<number<<list->dato<<endl;
	if (list!=NULL){
		//number++;
		//cout<<number<<endl;
		return 1+SumaelementosRec(list->sig/*,number*/);
	}
	else {
		//cout<<number++<<endl;
		//cout<<"else"<<endl;
		return 0;
	}
}

void Lista::ingresodatos(){

	int dato;
	string x;

		//cout<<"Ingrese datos númericos a la lista: ";
	while (x!="s"){
		cout<<"Digite el dato (uno por uno):"<<endl;
		cin >>dato;
		cout<<"Para parar presione s, para continuar presione c; "<<endl;
		cin >>x;
		Insertarls(dato);
		//mostrar_lista();
		cout<<endl;
	}

}
void Lista::inicSumaRec(){
	cout<<endl;
	cout<<endl<<endl<<"Actualmente en la lista hay "<<SumaelementosRec(lsinicio/*,0*/)<<" elementos contados de manera recursiva."<<endl;
	cout<<endl;
}



int main()
{
	//int dato;
	Menu();

	return 0;
}

void Menu(){
	int opcion=0;
	Lista objLista;

for (int i=0; i<100;i++){
		//cout<<opcion<<endl;
		opcion=0;
		cout <<"<:MENU:>"<<endl;
		cout <<"1. Insertar valores. "<<endl;
		cout <<"2. Mostrar elementos de la lista. "<<endl;
		cout <<"3. Sumar los elementos iterativamente. "<<endl;
		cout <<"4. Sumar los elementos recursivamente. "<<endl;
		cout <<"5. Salir."<<endl;
		cin >>opcion;

		if(opcion==5){
			break;
		}
			//cin >>opcion;
			switch (opcion) {
				case 1: cout<<"Digite los elementos"<<endl;
								objLista.ingresodatos();
								//opcion=0;
								break;
				case 2: cout<<"Los elementos de la lista son: "<<endl;
			 					objLista.mostrar_lista();
			 					//opcion=0;
								break;
				case 3: cout<<"El resultado de forma iterativa es: ";
			    	    		objLista.Sumaelementos();
			    	    		//opcion=0;
								break;
				case 4: cout<<"El resultado de forma recursiva es: ";
			  					objLista.inicSumaRec();
			  					//opcion=0;
								break;
				default: cout<<"Opcion no valida"<<endl; 

		}
	}
}