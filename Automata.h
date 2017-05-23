#pragma once
#include <set>
#include <vector>
#include <iterator>
#include "Transition.h"

template <class T>
class Automata
{
	std::set<Transition<T>> transitions;

	std::set<T> states;
	//std::set<T> startStates;
    T startState;
	std::set<T> finalStates;
	std::set<char> symbols;

	void init(std::set<char>& symbols) {
        transitions = std::set<Transition<T>>();
		states = std::set<T>();
		//startStates = std::set<T>();
		finalStates = std::set<T>();
		this->setAlphabet(symbols);
	}

public:
	Automata() {
        std::set<char> set = std::set<char>();
        init(set);
	}

	Automata(std::set<char>& symbols) {
		init(symbols);
	}

	Automata(char* s) {
		std::set<char> vect(s, s + sizeof s / sizeof s[0]);
		init(vect);
	}

	void setAlphabet(char* s) {
		this->setAlphabet(std::set<char>(s, s + sizeof s / sizeof s[0]));
	}

	void setAlphabet(std::set<char>& symbols) {
		this->symbols = symbols;
	}

	std::vector<char> getAlphabet() {
		return this->symbols;
	}

	void addTransition(const Transition<T>& t) {
		transitions.insert(t);
		states.insert(t.getFromState());
		states.insert(t.getToState());
	}

	void defineAsStartState(const T& t) {
		states.insert(t);
		//startStates.insert(t);
        startState = t;
	}

	void defineAsFinalState(const T& t) {
		states.insert(t);
		finalStates.insert(t);
	}

	void printTransitions() {
		for (auto t : transitions) {
			std::cout << t << "\n";
		}
	}
    
    bool accept(const std::string input){
        T state = startState;
        for (auto it = input.begin(); it < input.end(); ++it){
            // find transition:
            for (auto transition : transitions){
                if (transition.getFromState() == state && transition.getSymbol() == *it){
                    state = transition.getToState();
                    break;
                }
            }
        }
        
        // End state?
        return finalStates.find(state) != finalStates.end();
    }

	bool isDFA() {
	}


	~Automata() {

	}
};

