#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_06_01recursive/Lab_06_01recursive.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest5
{
	TEST_CLASS(UnitTest5)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int k = 0;
			int a[6] = { -8, -3, -1, 0, 6, 7 };
			int count = 0;
			k = Count(a, count, 0, 6);
			Assert::AreEqual(1, k);
		}
		TEST_METHOD(TestMethod2)
		{
			int k = 0;
			int a[6] = { -8, -3, -1, 0, 6, 7 };
			int sum = 0;
			k = Sum(a, sum, 0, 6);
			Assert::AreEqual(7, k);
		}
	};
}
