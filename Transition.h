#pragma once
#include <string>
#include <stdio.h>

template <class T>
class Transition
{
	T fromState;
	char symbol;
	T toState;

	void init(T from, char s, T to) {
		this->fromState = from;
		this->symbol = s;
		this->toState = to;
	}


public:
	const static char EPSILON = '$';

	Transition(T from, char s, T to) {
		init(from, s, to);
	}

	Transition(T fromOrTo, char s) {
		init(fromOrTo, s, fromOrTo);
	}

	Transition(T from, T to) {
		init(from, EPSILON, to);
	}

	T getFromState() const { return fromState; }
	T getToState() const { return toState; }
	char getSymbol() const { return symbol; }

	char* toString() const {
		char* s = new char[100];
        sprintf(s, "(%s, %c) --> %s",
			(this->getFromState()).c_str(), this->getSymbol(), (this->getToState()).c_str()
		);
		return s;
	}

	friend std::ostream& operator<<(std::ostream &Str, const Transition &obj){
		Str << obj.toString();
		return Str;
	}
    
    bool operator==(const Transition<T>& rhs) const {
        return (fromState == rhs.getFromState()
                && toState == rhs.getToState()
                && symbol == rhs.getSymbol());
    }
    
    bool operator!=(const Transition<T>& rhs) const {
        return !(this==rhs);
    }

    bool operator<(const Transition<T>& rhs) const {
        // TODO: find out if this function can be improved/simplified
        if (fromState < rhs.getFromState()) return true;
        if (symbol < rhs.getSymbol() && fromState == rhs.getFromState()) return true;
        if (toState < rhs.getToState() && symbol == rhs.getSymbol() && fromState == rhs.getFromState()) return true;
        return false;
    }
    bool operator>(const Transition<T>& rhs) const {
        return rhs < this;
    }
    bool operator<=(const Transition<T>& rhs) const {
        return !(this > rhs);
    }
    bool operator>=(const Transition<T>& rhs) const {
        return !(this < rhs);
    }
    
	~Transition() {

	}
};

