#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Transition.h"
#include <vector>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TI34ForMetTest
{		
	TEST_CLASS(TransitionTest)
	{
	public:
		
		TEST_METHOD(TestTransitionToString)
		{
			Transition<std::string>* transition = new Transition<std::string>("q0", 'a', "q1");

			char* expected = new char[100];
			sprintf_s(expected, 100, "(q0, a) --> q1");

			Assert::IsTrue(strcmp(expected, transition->toString()) == 0);
		}

		TEST_METHOD(TestTransitionEpsilon) {
			Transition<std::string>* transition = new Transition<std::string>("q0", "q1");

			Assert::AreEqual(transition->EPSILON, transition->getSymbol());
		}

	};
}