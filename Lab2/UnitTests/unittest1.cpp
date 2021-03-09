#include "stdafx.h"
#include "CppUnitTest.h"
#include <iostream>
#include "../Lab2/source-h.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(Branch1)
		{
			std::string r("5");
			Assert::AreEqual(r, func1(0, 0, 0, 0, 0, 0));
		}
		TEST_METHOD(Branch2)
		{
			std::string r("2 -1.000000 1.000000");
			Assert::AreEqual(r, func1(1, 3, 2, 5, 2, 3));
		}
		TEST_METHOD(Branch3)
		{
			std::string r("4 2.500000");
			Assert::AreEqual(r, func1(0, 0, 0, 2, 0, 5));
		}
		TEST_METHOD(Branch4)
		{
			std::string r("3 5.000000");
			Assert::AreEqual(r, func1(0, 0, 8, 0, 0, 40));
		}
		TEST_METHOD(Branch5)
		{
			std::string r("0");
			Assert::AreEqual(r, func1(0, 0, 0, 0, 5, 0));
		}
		TEST_METHOD(Branch6)
		{
			std::string r("4 1.000000");
			Assert::AreEqual(r, func1(0, 2, 0, 2, 2, 2));
		}
		TEST_METHOD(Branch7)
		{
			std::string r("3 1.000000");
			Assert::AreEqual(r, func1(3, 0, 5, 0, 3, 5));
		}
		TEST_METHOD(Branch8)
		{
			std::string r("1 5.000000 7.500000");
			Assert::AreEqual(r, func1(0, 0, -10, 2, 0, 15));
		}
		TEST_METHOD(Branch9)
		{
			std::string r("1 4.500000 0.500000");
			Assert::AreEqual(r, func1(-18, 4, 0, 0, 2, 0));
		}
		TEST_METHOD(Branch10)
		{
			std::string r("1 -3.333333 0.000000");
			Assert::AreEqual(r, func1(0, 1, 3, 10, 0, 0));
		}
		TEST_METHOD(Branch11)
		{
			std::string r("1 -5.000000 0.000000");
			Assert::AreEqual(r, func1(2, 10, 0, 4, 0, 0));
		}
		TEST_METHOD(Branch12)
		{
			std::string r("1 -5.000000 0.000000");
			Assert::AreEqual(r, func1(10, 2, 50, 10, 0, 0));
		}
		TEST_METHOD(Branch13)
		{
			std::string r("Are you kidding me?");
			Assert::AreEqual(r, func1(10, 2, 100, 10, 0, 0));
		}
	};
}