//
// Created by jeffr on 25/8/2022.
//

#ifndef LISTADOBLEGENERICA_NODO_H
#define LISTADOBLEGENERICA_NODO_H

#include <sstream>

using namespace std;

template<class T>
class Nodo {
private:
    T *dato;
    Nodo *siguiente;
    Nodo *anterior;
public:
    Nodo();
    virtual ~Nodo();
    T *getDato() const;
    void setDato(T *dato);
    Nodo *getSiguiente() const;
    void setSiguiente(Nodo *siguiente);
    Nodo *getAnterior() const;
    void setAnterior(Nodo *anterior);
};

template<class T>
Nodo<T>::Nodo() {}

template<class T>
Nodo<T>::~Nodo() {

}

template<class T>
T *Nodo<T>::getDato() const {
    return dato;
}

template<class T>
void Nodo<T>::setDato(T *dato) {
    Nodo::dato = dato;
}

template<class T>
Nodo<T> *Nodo<T>::getSiguiente() const {
    return siguiente;
}

template<class T>
void Nodo<T>::setSiguiente(Nodo *siguiente) {
    Nodo::siguiente = siguiente;
}

template<class T>
Nodo<T> *Nodo<T>::getAnterior() const {
    return anterior;
}

template<class T>
void Nodo<T>::setAnterior(Nodo *anterior) {
    Nodo::anterior = anterior;
}

#endif //LISTADOBLEGENERICA_NODO_H