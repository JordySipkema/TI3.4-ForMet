#pragma once
#include <vector>
#include <iterator>
#include "Transition.h"

template <class T>
class Automata
{
	std::vector<Transition<T>> transitions;

	std::vector<T> states;
	std::vector<T> startStates;
	std::vector<T> finalStates;
	std::vector<char> symbols;

	void init(std::vector<char>& symbols) {
		transitions = std::vector<Transition<T>>();
		states = std::vector<T>();
		startStates = std::vector<T>();
		finalStates = std::vector<T>();
		this->setAlphabet(symbols);
	}

public:
	Automata() {
		init(new std::vector<char>());
	}

	Automata(std::vector<char>& symbols) {
		init(symbols);
	}

	Automata(char* s) {
		std::vector<char> vect(s, s + sizeof s / sizeof s[0]);
		init(vect);
	}

	void setAlphabet(char* s) {
		this->setAlphabet(&std::vector<char>(s, s + sizeof s / sizeof s[0]));
	}

	void setAlphabet(std::vector<char>& symbols) {
		this->symbols = symbols;
	}

	std::vector<char> getAlphabet() {
		return this->symbols;
	}

	void addTransition(Transition<T>& t) {
		transitions.push_back(t);
		states.push_back(t.getFromState());
		states.push_back(t.getToState());
	}

	void defineAsStartState(T& t) {
		states.push_back(t);
		startStates.push_back(t);
	}

	void defineAsFinalState(T& t) {
		states.push_back(t);
		finalStates.push_back(t);
	}

	void printTransitions() {
		for (auto t : transitions) {
			std::cout << t << "\n";
		}
	}

	bool isDFA() {

	}


	~Automata() {

	}
};

