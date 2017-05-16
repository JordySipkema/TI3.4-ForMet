#include <iostream>
#include "Automata.h"
#include "Transition.h"

static Automata<std::string> getExampleSlide8Lesson2() {
	std::vector<char> alphabet = { 'a', 'b' };
	Automata<std::string>* m = new Automata<std::string>(alphabet);

	m->addTransition(Transition<std::string>("q0", 'a', "q1"));
	m->addTransition(Transition<std::string>("q0", 'b', "q4"));

	m->addTransition(Transition<std::string>("q1", 'a', "q4"));
	m->addTransition(Transition<std::string>("q1", 'b', "q2"));

	m->addTransition(Transition<std::string>("q2", 'a', "q3"));
	m->addTransition(Transition<std::string>("q2", 'b', "q4"));

	m->addTransition(Transition<std::string>("q3", 'a', "q1"));
	m->addTransition(Transition<std::string>("q3", 'b', "q2"));

	// The error states
	m->addTransition(Transition<std::string>("q4", 'a'));
	m->addTransition(Transition<std::string>("q4", 'b'));

	// Start state
	m->defineAsStartState(std::string("q0"));

	// Final states
	m->defineAsFinalState(std::string("q2"));
	m->defineAsFinalState(std::string("q3"));

	m->printTransitions();

	return *m;
}

int main() {
	std::cout << "Formele Methoden - Sander & Jordy\n" << std::endl;

	getExampleSlide8Lesson2();

	getchar();
	return 0;
}
