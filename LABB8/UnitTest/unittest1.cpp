#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\..\lab3\lab3\TPNumber.h"
#include "..\lab8\TPNumberEditor.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(isZero)
		{
			TPNumberEditor pnum;
			Assert::AreEqual(pnum.isZero(), true);
			pnum.AddNumber(5);
			Assert::AreEqual(pnum.isZero(), false);
		}

		TEST_METHOD(AddNumber)
		{
			TPNumberEditor pnum;
			pnum.AddNumber(7);
			Assert::AreEqual(pnum.GetNumber(), to_string(7.0f));
		}

		TEST_METHOD(AddSign)
		{
			TPNumberEditor pnum;
			pnum.AddNumber(9);
			Assert::AreEqual(pnum.AddSign(), (string)"-9");
		}

		TEST_METHOD(AddZero)
		{
			TPNumberEditor pnum;
			pnum.AddNumber(3);
			pnum.AddZero();
			Assert::AreEqual(pnum.GetNumber(), to_string(30.0f));
		}

		TEST_METHOD(BackSpace)
		{
			TPNumberEditor pnum;
			pnum.AddNumber(5);
			Assert::AreEqual(pnum.BackSpace(), (string)"0");
		}

		TEST_METHOD(Clear)
		{
			TPNumberEditor pnum;
			Assert::AreEqual(pnum.AddNumber(8), (string)"8");
			Assert::AreEqual(pnum.Clear(), (string)"0");
		}

		TEST_METHOD(GetNumber)
		{
			TPNumberEditor pnum;
			pnum.AddNumber(2);
			Assert::AreEqual(pnum.GetNumber(), to_string(2.0f));
		}

		TEST_METHOD(SetNumber)
		{
			TPNumberEditor pnum;
			/*string number = "3F";
			pnum.SetNumber(number);
			Assert::AreEqual(pnum.GetNumber(), to_string(0.0f));*/
			
			pnum.AddNumber(17);
			Assert::AreEqual(pnum.GetNumber(), to_string(0.0f));

		}

	};
}