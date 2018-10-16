#include "stdafx.h"
#include "CppUnitTest.h"
#include <assert.h>
#include "../ProjectX/drob.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

Drobi a(6, 13), b(11, 12), c(3, 7), d(11331, 22264);
Drobi fromstr("5/6");
Drobi fromstr2("1/25");

namespace UnitLab1Test
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(getChislitelTest)
		{
			Assert::AreEqual(a.getChislitel(), 6);
			Assert::AreEqual(b.getChislitel(), 11);
		}

		TEST_METHOD(getZnamenatelTest)
		{
			Assert::AreEqual(c.getZnamenatel(), 7);
			Assert::AreEqual(d.getZnamenatel(), 22264);
		}
		TEST_METHOD(getStringTest)
		{
			Assert::AreEqual(fromstr.getChislitel(), 5);
			Assert::AreEqual(fromstr2.getZnamenatel(), 25);
		}
		TEST_METHOD(SummTest)
		{
			Drobi res = b.summ(a);
			Assert::AreEqual(res.getChislitel(), (215));
			res = c.summ(d);
			Assert::AreEqual(res.getZnamenatel(), 7*22264);
		}
		TEST_METHOD(ObratnoeTest)
		{
			a.obratnoe();
			Assert::AreEqual(a.getChislitel(), 13);
			Assert::AreEqual(a.getZnamenatel(), 6);
			a.obratnoe();
		}
		TEST_METHOD(DelenieTest)
		{
			Drobi res = a.delit(b);
			Assert::AreEqual(res.getChislitel(), 72);
			res = a.delit(b);
			Assert::AreEqual(res.getZnamenatel(), 143);
		}
		TEST_METHOD(UmnozhTest)
		{
			Drobi res = b.umnozh(a);
			Assert::AreEqual(res.getChislitel(), (11));
			res = b.umnozh(a);
			Assert::AreEqual(res.getZnamenatel(), (26));
			
		}
		TEST_METHOD(SquareTest)
		{
			Drobi res = a;
			res = res.kvadrat(res);
			Assert::AreEqual(res.getChislitel(), 6*6);
			Assert::AreEqual(res.getZnamenatel(), 13*13);
		}
		TEST_METHOD(DrobstringTest)
		{
			Assert::AreEqual(a.getDrobString(), std::string("6/13"));
		}

		TEST_METHOD(CopyTest)
		{
			Drobi copyrez = a.copy();
			Assert::AreEqual(copyrez.getChislitel(), 6);
		}

	};
}