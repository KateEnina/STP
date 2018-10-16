#include "stdafx.h"
#include "CppUnitTest.h"
#include <assert.h>
#include "..\lab2\tComplex.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

//string s = "7-i*1";
//tComplex c(s);
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
			Assert::AreEqual(f.GetIm(), d.GetIm());
		}

		TEST_METHOD(summ)
		{
			tComplex f(0, 0);
			f = d.Summ(e);
			Assert::AreEqual(f.GetIm(), (d.GetIm() + e.GetIm()));
		}

		TEST_METHOD(umnoj)
		{
			tComplex f(0, 0);
			f = d.Multiply(e);
			Assert::AreEqual(f.GetIm(), (d.GetRe()*e.GetIm() + e.GetRe()*d.GetIm()));
		}

		TEST_METHOD(kvadrat)
		{
			tComplex f(0, 0);
			f = d.Square();
			Assert::AreEqual(f.GetIm(), d.GetRe()*d.GetIm() + d.GetIm()*d.GetRe());
		}

		TEST_METHOD(obratnoe)
		{
			tComplex f(0, 0);
			f = d.Obratnoe();
			Assert::AreEqual(f.GetRe(), (d.GetRe() / (d.GetRe()*d.GetRe() + d.GetIm() + d.GetIm())));
		}

		TEST_METHOD(vichest)
		{
			tComplex f(0, 0);
			f = d.Vichest(e);
			Assert::AreEqual(f.GetRe(), d.GetRe() - e.GetRe());
		}

		TEST_METHOD(delenie)
		{
			tComplex f(0, 0);
			f = d.Del(e);
			Assert::AreEqual(f.GetRe(), (d.GetRe()*e.GetRe() + d.GetIm()*e.GetIm()) / (e.GetRe()*e.GetRe() + e.GetIm()*e.GetIm()));
		}

		TEST_METHOD(minus)
		{
			tComplex f(0, 0);
			f = d.Minus();
			Assert::AreEqual(f.GetRe(), 0 - d.GetRe());
			Assert::AreEqual(f.GetIm(), 0 - d.GetIm());
		}

		TEST_METHOD(modul)
		{

			float f = d.Module();
			Assert::AreEqual(f, sqrt(d.GetRe()*d.GetRe() + d.GetIm()*d.GetIm()));
		}

		TEST_METHOD(ugol_rad)
		{
			float f = d.AngleRad();
			Assert::AreEqual(f, atan2(d.GetIm(), d.GetRe()));
		}

	};
}
