#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\..\lab2\lab2\tComplex.h"
#include "..\lab7\TComplexEditor.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(isZero)
		{
			TComplexEditor pnum;
			Assert::AreEqual(pnum.isZero(), true);
		}

		TEST_METHOD(AddNumber)
		{
			TComplexEditor complx;
			complx.AddNumber(4);
			Assert::AreEqual(complx.GetNumber(), to_string(4.0) + "+i*" + to_string(0.0));
		}

		TEST_METHOD(AddSign)
		{
			TComplexEditor complx;
			complx.AddNumber(9);
			complx.AddSign();
			Assert::AreEqual(complx.GetNumber(), to_string(-9.0) + "+i*" + to_string(0.0));
		}

		TEST_METHOD(AddZero)
		{
			TComplexEditor complx;
			complx.AddNumber(3);
			complx.AddZero();
			Assert::AreEqual(complx.GetNumber(), to_string(30.0) + "+i*" + to_string(0.0));
		}

		TEST_METHOD(BackSpace)
		{
			TComplexEditor complx;
			complx.AddNumber(5);
			Assert::AreEqual(complx.BackSpace(), (string)"0");
		}

		TEST_METHOD(Clear)
		{
			TComplexEditor complx;
			Assert::AreEqual(complx.AddNumber(8), (string)"8");
			Assert::AreEqual(complx.Clear(), (string)"0");
		}

		TEST_METHOD(GetNumber)
		{
			TComplexEditor complx;
			string number = "7";
			complx.SetNumber(number);
			Assert::AreEqual(complx.GetNumber(), to_string(7.0) + "+i*" + to_string(0.0));
		}

		TEST_METHOD(SetNumber)
		{
			TComplexEditor complx;
			string number = "3";
			string test = to_string(3.0f) + "+i*" + to_string(0.0f);
			complx.SetNumber(number);
			Assert::AreEqual(complx.GetNumber(), test);
		}

		TEST_METHOD(SetNumber2)
		{
			TComplexEditor complx;
			string number = "3+i*2";
			string test = to_string(3.0f) + "+i*" + to_string(0.0f);
			complx.SetNumber(number);
			Assert::AreEqual(to_string(3.0f) + "+i*" + to_string(2.0f), complx.GetNumber());
		}

	};
}