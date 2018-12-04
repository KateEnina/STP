#include "stdafx.h"
#include "CppUnitTest.h"
#include <string>
#include "../../lab2/lab2/tComplex.h"
#include "../../lab3/lab3/TPNumber.h"

#include "../lab5/TProc.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Add)
		{
			TProc<int> a;
			a.SetLop_Res(int(100));
			a.SetRop(int(25));
			a.SetOprtn(TOprtn::Add);
			a.RunOperation();
			Assert::AreEqual(a.GetLop_Res(), 125);
		}

		TEST_METHOD(Sub)
		{
			TProc<int> a;
			a.SetLop_Res(int(100));
			a.SetRop(int(25));
			a.SetOprtn(TOprtn::Sub);
			a.RunOperation();
			Assert::AreEqual(a.GetLop_Res(), 75);
		}
		
		TEST_METHOD(Multiply)
		{
			TProc<int> a;
			a.SetLop_Res(int(100));
			a.SetRop(int(25));
			a.SetOprtn(TOprtn::Mul);
			a.RunOperation();
			Assert::AreEqual(a.GetLop_Res(), 2500);
		}

		TEST_METHOD(Sqr)
		{
			TProc<TComplex> a;
			TComplex test(3.0, 4.0);
			//a.SetLop_Res(int(100));
			a.SetRop(test);
			a.RunFunc(TFunc::Sqr);
			Assert::AreEqual(a.GetRop().GetRe(),(float)-7);
			Assert::AreEqual(a.GetRop().GetIm(),(float)24);

		}

		
		TEST_METHOD(AddSl)
		{

			TProc<TPNumber> c;
			TPNumber a("11", 10, 3), b("11", 2, 3);
			c.SetLop_Res((TPNumber)a);
			c.SetRop((TPNumber)b);
			c.SetOprtn(TOprtn::Add);
			c.RunOperation();
			TPNumber d("14", 10, 3);
			d = d - c.GetLop_Res();
			Assert::AreEqual(d.GetFloatPNumber(), 0.0f);
		}
		
	};
}