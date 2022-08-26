//
// Created by jeffr on 25/8/2022.
//

#ifndef LISTADOBLEGENERICA_LISTA_H
#define LISTADOBLEGENERICA_LISTA_H

#include "Nodo.h"

template<class T>
class Lista {
private:
    Nodo<T> *inicio;
    Nodo<T> *cola;
public:
    Lista();

    bool vacia();

    T *valorInicio();

    T *valorFinal();

    void agregar(Nodo<T> *referencia, T *valor);

    void agregarInicio(T *valor);

    void agregarFinal(T *valor);

    void borrar(Nodo<T> *referencia);

    void borrarInicio();

    void borrarFinal();

    string toString();
};

template<class tipo>
Lista<tipo>::Lista() {
    this->inicio = new Nodo<tipo>;
    this->cola = new Nodo<tipo>;
    inicio->setSiguiente(cola);
    cola->setAnterior(inicio);
}

template<class tipo>
bool Lista<tipo>::vacia() {
    return (inicio->getSiguiente() == cola);
}

template<class tipo>
tipo *Lista<tipo>::valorInicio() {
    Nodo<tipo> temp = inicio->getSiguiente();
    if (temp == nullptr) {
        return nullptr;
    }
    return temp->getDato();
}

template<class T>
T *Lista<T>::valorFinal(){
    Nodo<T> *temp = cola->getSiguiente();
    if(temp == nullptr){
        return nullptr;
    }
    return temp->getDato();
}

template<class T>
void Lista<T>::agregar(Nodo<T> *referencia, T *valor) {
    Nodo<T> *nuevo = new Nodo<T>();
    nuevo->setDato(valor);
    nuevo->setSiguiente(referencia);
    nuevo->setAnterior(referencia->getAnterior());
    referencia->getAnterior()->setSiguiente(nuevo);
    referencia->setAnterior(nuevo);
}

template<class T>
void Lista<T>::agregarInicio(T *valor){
    agregar(inicio->getSiguiente(),valor);
}

template<class T>
void Lista<T>::agregarFinal(T *valor){
    agregar(cola,valor);
}

template<class T>
void Lista<T>::borrar(Nodo<T> *referencia){
    Nodo<T> *ant = referencia->getAnterior();
    Nodo<T> *sig = referencia->getSiguiente();
    ant->getSiguiente(sig);
    sig->setAnterior(ant);
    delete referencia;
}

template<class T>
void Lista<T>::borrarInicio(){
    borrar(inicio->getSiguiente());
}

template<class T>
void Lista<T>::borrarFinal() {
    borrar(cola->getAnterior());
}

template<class T>
string Lista<T>::toString(){
    stringstream ss;
    Nodo<T> *temp = inicio->getSiguiente();
    if(temp == cola){
        ss << "Vacia " << endl;
    }else{
        ss<<"NULL<->";
        while(temp != cola){
            ss << *temp->getDato() << "<->";
            temp = temp->getSiguiente();
        }
        ss << "NULL" << endl;
    }
    return ss.str();
}
#endif //LISTADOBLEGENERICA_LISTA_H
