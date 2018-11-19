#pragma once
#pragma once
#ifndef NODOPILA_H
#define NODOPILA_H
template <class T> class Lista;

template <class T>

class NodoPila
{
	friend class Lista<T>;

private:
	T Info;
	NodoPila<T>* Siguiente;
	NodoPila<T>* Anterior;
public:
	//constructor
	NodoPila(const T&); // Recibe un tipo y el nodo al que va a quedar apuntando
	virtual ~NodoPila();
	T getInfo()const; // retorna un puntero q pose el nodo
	NodoPila(T&, NodoPila<T>, NodoPila<T>);
	void setSig(NodoPila<T>*);
	void setAnt(NodoPila<T>*);
	NodoPila<T>* getAnt();
	NodoPila<T>* getSig();
};

//--------------------------------------------------------------------------------------------------
template <class T>
NodoPila<T>::NodoPila(const T& newInfo) : Info(newInfo), Siguiente(0), Anterior(0)
{
}

template <class T>
void NodoPila<T>::setSig(NodoPila<T>* n)
{
	Siguiente = n;
}
template <class T>
void NodoPila<T>::setAnt(NodoPila<T>* A)
{
	Anterior = A;
}
template <class T>
NodoPila<T>* NodoPila<T>::getAnt() { return Anterior; }
template <class T>
NodoPila<T>* NodoPila<T>::getSig() { return Siguiente; }

template <class T>
NodoPila<T>::~NodoPila() {}

//----------------------------------------------------------------------------------------------------------
template<class T>
T NodoPila<T>::getInfo() const
{
	return Info;
}

#endif
