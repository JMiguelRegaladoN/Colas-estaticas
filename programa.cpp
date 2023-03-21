#include <iostream>
#define TAM 50
//Juan Miguel Regalado Nuño
/*
Colas Estaticas Seminario de estructura de datos I
*/
#include<iostream>
using namespace std;
class Alumno{
private:
    char Nombre[64];
    char Carrera[64];
    int Materias;
    float Promedio;
public:
    Alumno(){};
    friend ostream & operator<<(ostream &O, Alumno &x){
            O<<"\nNombre: "<<x.Nombre;
            O<<"\nCarrera: "<<x.Carrera;
            O<<"\nMaterias Aprobadas: "<<x.Materias;
            O<<"\nPromedio: "<<x.Promedio;
            return O;
    }
    friend istream & operator>>(istream &O, Alumno &x){
            cout<<"\nNombre: ";
            O>>x.Nombre;
            cout<<"Carrera: ";
            O>>x.Carrera;
            cout<<"Materias Aprobadas: ";
            O>>x.Materias;
            cout<<"Promedio: ";
            O>>x.Promedio;
            return O;
    }
};

//plantillas
template<class T>
class Cola{
private:
    T datos[TAM];
    int ult;
    bool inserta(T, int);
    bool elimina(int);
    T recupera(int)const;
    int primero()const;
    int ultimo()const;
    void imprime()const;
public:
    Cola():ult(-1){}
    bool vacia()const;
    bool llena()const;
    bool  Queue(T&);
    bool Dequeue();
    T Front()const;
};

template<class T>
T Cola<T>::Front()const{
    T x=datos[primero()];
    return x; 
}

template<class T>
bool Cola<T>::Dequeue(){
    if(vacia()){
        return false;
    }
    else{
        elimina(primero());
    }
    return true;
}

template<class T>
bool Cola<T>::Queue(T& elem){
    if(llena()){
        return false;
    }
    if(vacia()){
        inserta(elem,0);
    }
    else{
        inserta(elem, ultimo()+1);
    }
    return true;
}

template<class T>
void Cola<T>::imprime()const{
    if(!vacia()){
        for(int i=0; i<=ult; i++){
            Alumno x=datos[i];
            std::cout<<x<<std::endl;
        }
    }
}

template<class T>
bool Cola<T>::vacia()const{
    return ult==-1;
}

template<class T>
bool Cola<T>::llena()const{
    return ult==TAM-1;
}

template<class T>
bool Cola<T>::inserta(T elem, int pos){
    if(llena() || pos<0 || pos>ult+1){
        std::cout<<"\n No se pudo insertar";
        return false;
    }
    int i=ult+1;
    while(i>pos){
        datos[i]=datos[i-1];
        i--;
    }
    datos[pos]=elem;
    ult++;
    return true;
}

template<class T>
bool Cola<T>::elimina(int pos){
    if(vacia() || pos<0 || pos>ult){
        std::cout<<"\n No se pudo eliminar";
        return false;
    }
    int i=pos;
    while(i<ult){
        datos[i]=datos[i+1];
        i++;
    }
    ult--;
    return true;
}

template<class T>
T Cola<T>::recupera(int pos)const{
    if(vacia() || pos<0 || pos>ult-1){
        std::cout<<"\n Insuficiencia de datos";
        //Manejar exceptions
    }
    else{
       return datos[pos];
    }
}

template<class T>
int Cola<T>::primero()const{
    if(vacia()){
       return -1;
    }
    return 0;
}

template<class T>
int Cola<T>::ultimo()const{
    if(vacia()){
       return -1;
    }
    return ult;
}

int main()
{
    Cola<Alumno> MiCola;
    Alumno x;
    int opc;
    do{//Menu de opciones para el usuario
        cout<<"MENU\n";
        cout<<"1-Dar de Alta un alumno: \n";
        cout<<"2-Crear una constancia: \n";
        cout<<"3-Salir: \n";
        cout<<"Elige una opcion: \t";
        cin>>opc;
        switch(opc){//Manejo del menu
            case 1:
                cin>>x;
                MiCola.Queue(x);
                break;
            case 2:
            	if(MiCola.vacia()){//En caso de no haber datos se tienen que crear primero y se tiene que digitar la opcion 1
            		cout<<"No se puede generar por que no hay datos tienes que darte de alta para poder los datos y generar la constancia"<<endl;
				}
				else{
					cout<<"Primero debes de darte del alta";
                	x=MiCola.Front();
                	cout<<x<<endl;
                	MiCola.Dequeue();
				}
            	/*cout<<"Primero debes de darte del alta";
                x=MiCola.Front();
                cout<<x<<endl;
                MiCola.Dequeue();
                */
                break;
            case 3:
                break;
            default:
                cout<<"\nElige una opcion entre 1 y 3\n";
        }
    cout<<"\n\n";
    }while(opc!=3);
return 0;
}
