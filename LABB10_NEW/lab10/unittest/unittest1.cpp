#include "stdafx.h"
#include <ctime>
#include <iterator>
#include <random>
#include "CppUnitTest.h"
#include "D://кчахлши смхбеп/4 йспя 1 яелюй/яро/STPyo/Lab1/ProjectX/tFrac.h"
#include "../lab10/TSet.h"
#include "../lab10/TSetInher.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Clear)
		{
			TSet<TFrac> t;
			t.insert(TFrac(0, 1));
			t.clear();
			Assert::AreEqual(t.size(),0);
		}

		TEST_METHOD(IsEmpty)
		{
			TSet<TFrac> t;
			t.insert(TFrac(0, 1));
			Assert::IsFalse(t.is_empty());
		}

		TEST_METHOD(Find)
		{
			TSet<TFrac> t;
			t.insert(TFrac(0, 1));
			Assert::IsTrue(t.find(TFrac(0, 1)));
		}

		TEST_METHOD(Unite)
		{
			TSet<TFrac> t;
			t.insert(TFrac(0, 1));
			TSet<TFrac> s;
			s.insert(TFrac(1, 2));
			s.insert(TFrac(0, 1));
			TSet<TFrac> r = t.unite(s);
			Assert::AreEqual(r.size(), 2);
		}
		
		TEST_METHOD(Sub)
		{
			TSet<TFrac> t;
			TSet<TFrac> s;
			t.insert(TFrac(0, 1));
			s.insert(TFrac(1, 2));
			TSet<TFrac> r = t.sub(s);
			Assert::AreEqual(r.size(), 1);

			
		}

		TEST_METHOD(SubInher)
		{
			TSetInher<TFrac> t1;
			TSetInher<TFrac> t2;
			TSetInher<TFrac> res;
			t1.insert(TFrac(0, 1));
			t2.insert(TFrac(0, 1));
			res = t1.sub(t2);
			Assert::AreEqual(res.size(), static_cast<size_t>(0));


		}

		TEST_METHOD(UniteInher)
		{
			TSetInher<TFrac> t1;
			t1.insert(TFrac(0, 1));
			TSetInher<TFrac> t2;
			t2.insert(TFrac(1, 2));
			TSetInher<TFrac> res = t1.unite(t2);
			Assert::AreEqual(res.size(), static_cast<size_t>(2));
		}

		
	};
}