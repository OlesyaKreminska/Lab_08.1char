#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_08.1char/Lab_08.1char.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest81it
{
	TEST_CLASS(UnitTest81it)
	{
	public:

		TEST_METHOD(TestCount)
		{
			char str1[] = "n o";                 
			char str2[] = "hello n o world";      
			char str4[] = "n o n o n o";          

			Assert::AreEqual(1, Count(str1), L"Expected 1 match in 'n o'");
			Assert::AreEqual(1, Count(str2), L"Expected 1 match in 'hello n o world'");
			Assert::AreEqual(3, Count(str4), L"Expected 3 matches in 'n o n o n o'");
		}

		
	};
}
