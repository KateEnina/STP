#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\lab3\TPNumber.h"
#include <stdlib.h>
#include <iostream>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
TPNumber A("-31.F123A", 16, 5);
TPNumber B(54.321, 8, 3);
TPNumber D(21.125, 8, 3);

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(GetPString)
		{
			Assert::AreEqual(B.GetPString().c_str(), "66.244");
		}
		TEST_METHOD(GetBString)
		{
			Assert::AreEqual(B.GetBString().c_str(), "8");
		}
		TEST_METHOD(GetCString)
		{
			Assert::AreEqual(B.GetCString().c_str(), "3");
		}

		TEST_METHOD(SetBString)
		{
			B.SetBString("4");
			Assert::AreEqual(B.GetBString().c_str(), "4");
			B.SetBString("8");
		}
		TEST_METHOD(SetCString)
		{
			B.SetCString("6");
			Assert::AreEqual(B.GetCString().c_str(), "6");
			B.SetCString("3");
		}

		TEST_METHOD(SetBInt)
		{
			B.SetIntB(4);
			Assert::AreEqual(B.GetIntB(), 4);
			B.SetBString("8");
		}
		TEST_METHOD(SetCSInt)
		{
			A.SetIntC(6);
			Assert::AreEqual(A.GetIntC(), 6);
			A.SetCString("3");
		}

		TEST_METHOD(Copy)
		{
			TPNumber C(0, 2, 1);
			C = B.Copy();
			Assert::AreEqual(C.GetFloatPNumber(), 54.321f, 0.001f);
			Assert::AreEqual(C.GetIntB(), 8);
			Assert::AreEqual(C.GetIntC(), 3);
		}

		TEST_METHOD(Reverse)
		{
			TPNumber C(0, 2, 1);
			C = B.Reverse();
			Assert::AreEqual(C.GetFloatPNumber(), 0.0184f, 0.0001f);
			Assert::AreEqual(C.GetIntB(), 8);
			Assert::AreEqual(C.GetIntC(), 3);
		}

		TEST_METHOD(Kvadrat)
		{
			TPNumber C(0, 2, 1);
			C = B.Sqr();
			Assert::AreEqual(C.GetFloatPNumber(), 2950.7710f, 0.0001f);
			Assert::AreEqual(C.GetIntB(), 8);
			Assert::AreEqual(C.GetIntC(), 3);
		}

		TEST_METHOD(Summa)
		{
			TPNumber C(0, 2, 1);
			C = B.Summ(D);
			Assert::AreEqual(C.GetFloatPNumber(), 75.446f, 0.0001f);
			Assert::AreEqual(C.GetIntB(), 8);
			Assert::AreEqual(C.GetIntC(), 3);
		}
	
		TEST_METHOD(Substruct)
		{
			TPNumber C(0, 2, 1);
			C = B.Substruct(D);
			Assert::AreEqual(C.GetFloatPNumber(), 33.196f, 0.001f);
			Assert::AreEqual(C.GetIntB(), 8);
			Assert::AreEqual(C.GetIntC(), 3);
		}

		TEST_METHOD(Multiply)
		{
			TPNumber C(0, 2, 1);
			C = B.Multiply(D);
			Assert::AreEqual(C.GetFloatPNumber(), 1147.531f, 0.001f);
			Assert::AreEqual(C.GetIntB(), 8);
			Assert::AreEqual(C.GetIntC(), 3);
		}

		TEST_METHOD(Devide)
		{
			TPNumber C(0, 2, 1);
			C = B.Divide(D);
			Assert::AreEqual(C.GetFloatPNumber(), 2.571f, 0.001f);
			Assert::AreEqual(C.GetIntB(), 8);
			Assert::AreEqual(C.GetIntC(), 3);
		}
	};
}