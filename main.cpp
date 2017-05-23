#include <iostream>
#include "Automata.h"
#include "Transition.h"
#include "DFA.h"

static Automata<std::string> getExampleSlide8Lesson2() {
	std::set<char> alphabet = { 'a', 'b' };
	Automata<std::string> m = Automata<std::string>(alphabet);

    m.addTransition(Transition<std::string>(std::string("q0"), 'a', std::string("q1")));
    m.addTransition(Transition<std::string>(std::string("q0"), 'b', std::string("q4")));
    
    m.addTransition(Transition<std::string>(std::string("q1"), 'a', std::string("q4")));
    m.addTransition(Transition<std::string>(std::string("q1"), 'b', std::string("q2")));
    
    m.addTransition(Transition<std::string>(std::string("q2"), 'a', std::string("q3")));
    m.addTransition(Transition<std::string>(std::string("q2"), 'b', std::string("q4")));
    
    m.addTransition(Transition<std::string>(std::string("q3"), 'a', std::string("q1")));
    m.addTransition(Transition<std::string>(std::string("q3"), 'b', std::string("q2")));

	// The error states
    m.addTransition(Transition<std::string>(std::string("q4"), 'a'));
    m.addTransition(Transition<std::string>(std::string("q4"), 'b'));

	// Start state
	m.defineAsStartState(std::string("q0"));

	// Final states
	m.defineAsFinalState(std::string("q2"));
	m.defineAsFinalState(std::string("q3"));

    m.printTransitions();

	return m;
//    return Automata<std::string>();
}

void testAccept(){
    std::string input = std::string("ab");
    Automata<std::string> m = getExampleSlide8Lesson2();
    bool result = m.accept(input);
    std::cout << "The given string '" << input << "' is " << (result ? "accepted" : "rejected");
}

int main() {
	std::cout << "Formele Methoden - Sander & Jordy\n" << std::endl;

	//getExampleSlide8Lesson2();
    testAccept();

	getchar();
	return 0;
}
