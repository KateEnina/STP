#include "stdafx.h"
#include "CppUnitTest.h"
#include <string>
#include "../lab9/TMono.h"
#include "../lab9/TPoly.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(MonoConstructor)
		{
			TMono m;
			Assert::AreEqual(m.get_coeff(),0);
			Assert::AreEqual(m.get_degree(),0);
		}


		TEST_METHOD(Poly)
		{
			TMono m(0, 2);
			Assert::AreEqual(m.get_string(), (string)"2*x^0");

		}
		
		TEST_METHOD(MonoLess)
		{
			TMono m;
			TMono l(3, 5);
			Assert::IsTrue(m < l);
		}
		
		
		TEST_METHOD(MonoDiff)
		{
			TMono m(5, 10);
			m= m.diff();
			Assert::AreEqual(m.get_coeff(),50);
			Assert::AreEqual(m.get_degree(),4);
		}
		
		TEST_METHOD(MonoString)
		{
			TMono m(2, -10);
			Assert::AreEqual(m.get_string(),(string)"-10*x^2");
		}


		TEST_METHOD(PolyConstructor)
		{
			TPoly p(2, -3);
			p = p + TPoly(5, 7);
			Assert::AreEqual(p.get_str(),(string)"-3*x^2+7*x^5");
		}


		TEST_METHOD(PolyGetCoeff)
		{
			TPoly p(2, -3);
			p = p + TPoly(5, 7);
			Assert::AreEqual(p.get_coeff(2), -3);
		}


		TEST_METHOD(PolySumm)
		{
			TPoly p(2, -3);
			p = p + TPoly(2, 3);
			Assert::AreEqual(p.get_str(), (string)"0*x^0");
		}

		TEST_METHOD(PolyMulty)
		{
			TPoly p(2, -3);
			p = p + TPoly(5, 7);
			p = p * TPoly(2, 1);
			Assert::AreEqual(p.get_str(), (string)"-3*x^4+7*x^7");
		}

		TEST_METHOD(PolyDiff)
		{
			TPoly p(2, -3);
			p = p.diff();
			Assert::AreEqual(p.get_str(),(string)"-6*x^1");
		}

		TEST_METHOD(PolyGetMono)
		{
			TPoly p(2, -3);
			p = p + TPoly(5, 7);
			p = p * TPoly(2, 1);
			TMono m = p.get_mono(1);
			Assert::AreEqual(m.get_string(), (string)"7*x^7");
		}

		TEST_METHOD(Sl)
		{
			TPoly p(2, 1);
			p = p + TPoly(0, 1)+p;
			Assert::AreEqual(p.get_str(), (string)"1*x^0+2*x^2");
		}
	};
}