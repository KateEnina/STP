#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\lab6\TFracEditor.h"
#include "..\..\Lab1\ProjectX\tFrac.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(isZero)
		{
			TFracEditor frac;
			Assert::AreEqual(frac.isZero(), true);
			frac.AddNumber(7);
			Assert::AreEqual(frac.isZero(), false);
		}

		TEST_METHOD(AddNumber)
		{
			TFracEditor frac;
			frac.AddNumber(7);
			Assert::AreEqual(frac.GetNumber(), (string)"7/1");
		}
		
		TEST_METHOD(AddSign)
		{
			TFracEditor frac;
			frac.AddNumber(9); 
			Assert::AreEqual(frac.AddSign(), (string)"-9");
		}
		
		TEST_METHOD(AddZero)
		{
			TFracEditor frac;
			frac.AddNumber(3);
			frac.AddZero();
			Assert::AreEqual(frac.GetNumber(), (string)"30/1");
		}
		
		TEST_METHOD(BackSpace)
		{
			TFracEditor frac;
			frac.AddNumber(5);
			Assert::AreEqual(frac.BackSpace(), (string)"0");
		}

		TEST_METHOD(Clear)
		{
			TFracEditor frac;
			Assert::AreEqual(frac.AddNumber(8), (string)"8");
			Assert::AreEqual(frac.Clear(), (string)"0");
		}

		TEST_METHOD(GetNumber)
		{
			TFracEditor frac;
			frac.AddNumber(2);
			frac.AddNumber(7);
			Assert::AreEqual(frac.GetNumber(), (string)"27/1");
		}
		
		TEST_METHOD(SetNumber)
		{
			try {
				TFracEditor frac;
				string number = "3//1";
				frac.SetNumber(number);
				//Assert::AreEqual(frac.GetNumber(), (string)"3/1");
				Assert::Fail();
			}
			catch(...){
				Assert::IsTrue(true);
			}
			}

		TEST_METHOD(AddSplit)
		{
			TFracEditor frac;
			frac.AddNumber(8);
			frac.AddSplit();
			frac.AddNumber(3);
			Assert::AreEqual(frac.GetNumber(), (string)"8/3");
		}
	};
}