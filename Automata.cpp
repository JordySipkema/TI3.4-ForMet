#include "Automata.h"


template <class T>
Automata<T>::Automata()
{
	this(new std::Vector<char>());
}

template<class T>
Automata<T>::Automata(char * s)
{
	this(std::vector<char>(s, s + sizeof s / sizeof s[0]));
}

template<class T>
Automata<T>::Automata(Vector<char> symbols)
{
	//transitions = new std::vector<Transition<T>>();
	states = new std::vector<T>();
	startStates = new std::vector<T>();
	finalStates = new std::vector<T>();

	setAlphabet(symbols);
}

template<class T>
void Automata<T>::setAlphabet(char * s)
{
	setAlphabet(std::vector<char>(s, s + sizeof s / sizeof s[0]));
}

template<class T>
void Automata<T>::setAlphabet(Vector<char> symbols)
{
	this.symbols = symbols;
}

template<class T>
Vector<char> Automata<T>::getAlphabet()
{
	return symbols;
}

template<class T>
void Automata<T>::defineAsStartState(T t)
{
	//
}

template<class T>
void Automata<T>::defineAsFinalState(T t)
{
	//
}

template<class T>
void Automata<T>::printTransitions()
{
	//
}

template<class T>
bool Automata<T>::isDFA()
{
	return false;
}

template <class T>
Automata<T>::~Automata()
{
}
