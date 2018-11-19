#include "stdafx.h"
#include "CppUnitTest.h"
#include "../lab4/tMemory.h"

#include "../../Lab1/ProjectX/tFrac.h"
#include "../../lab2/lab2/tComplex.h"
#include "../../lab3/lab3/TPNumber.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test
{		
	TEST_CLASS(UnitTest)
	{
	public:
		TMemory<TFrac> a;
		TFrac b;
		
		TEST_METHOD(Get) {
			Assert::AreEqual(b.getDrobString(),(string) "0/1");
			Assert::AreEqual(a.GetFState(), (string)"_Off");
		}

		TEST_METHOD(Take) {
			b = a.Take();
			Assert::AreEqual(b.getDrobString(), (string)"0/1");
			Assert::AreEqual(a.GetFState(), (string)"_On");
		}

		TEST_METHOD(Add) {
			a.Add(TFrac(1, 1));
			Assert::AreEqual(a.GetFNumber().getDrobString(), (string)"1/1");
			Assert::AreEqual(a.GetFState(), (string)"_On");
		}
		
		TEST_METHOD(Write) {
			a.Write(TFrac(3, 5));
			Assert::AreEqual(a.GetFNumber().getDrobString(),(string) "3/5");
			Assert::AreEqual(a.GetFState(), (string)"_On");
		}


		TEST_METHOD(Clear) {
			
			//Assert::AreEqual(b.getDrobString(),(string) "0/1");
			a.Clear();
			Assert::AreNotEqual(a.GetFState(), (string)"_On");
		}
	};
}