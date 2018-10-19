#include "stdafx.h"
#include "CppUnitTest.h"
#include <assert.h>
#include "..\lab2\tComplex.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

tComplex d(3, 2), e(4, -5);

namespace UnitLab2Test1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(copy)
		{
			tComplex f(0, 0);
			f = d.Copy();
			Assert::AreEqual(f.GetRe(), 3,0); 
			Assert::AreEqual(f.GetIm(), 2,0);
		}

		TEST_METHOD(summ)
		{
			tComplex f(0, 0);
			f = d.Summ(e);
			Assert::AreEqual(f.GetIm(), -3,0);
			Assert::AreEqual(f.GetRe(), 7,0);
		}

		TEST_METHOD(umnoj)
		{
			tComplex f(0, 0);
			f = d.Multiply(e);
			Assert::AreEqual(f.GetIm(), -7,0);
			Assert::AreEqual(f.GetRe(), 22,0);
		}

		TEST_METHOD(kvadrat)
		{
			tComplex f(0, 0);
			f = d.Square();
			Assert::AreEqual(f.GetIm(), 12,0);
			Assert::AreEqual(f.GetRe(), 5,0);
		}

		TEST_METHOD(obratnoe)
		{
			tComplex f(0, 0);
			f = d.Obratnoe();
			Assert::AreEqual(f.GetIm(), -0,153846 );
			Assert::AreEqual(f.GetRe(), 0,230769);
		}

		TEST_METHOD(vichest)
		{
			tComplex f(0, 0);
			f = d.Vichest(e);
			Assert::AreEqual(f.GetIm(), 7,0 );
			Assert::AreEqual(f.GetRe(), -1,0 );
		}

		TEST_METHOD(delenie)
		{
			tComplex f(0, 0);
			f = d.Del(e);
			Assert::AreEqual(f.GetIm(), 0,560976);
		}

		TEST_METHOD(minus)
		{
			tComplex f(0, 0);
			f = d.Minus();
			Assert::AreEqual(f.GetRe(), -3,0);
			Assert::AreEqual(f.GetIm(), -2,0);
		}

		TEST_METHOD(modul)
		{

			float f = d.Module();
			Assert::AreEqual(f, 3,60555);
		}

		TEST_METHOD(ugol_rad)
		{
			float f = d.AngleRad();
			Assert::AreEqual(f, 0,5880026);
		}

	};
}
