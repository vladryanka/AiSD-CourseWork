#include "pch.h"
#include "CppUnitTest.h"
#include "..\kursovaya.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestKursovaya
{
	TEST_CLASS(UnitTestKursovaya)
	{
	public:

		TEST_METHOD(TestCorrect)
		{
			string String = "()";
			int position = 0;
			try
			{
				correct(String, position);
			}
			catch (const invalid_argument error)
			{
				cout << error.what() << endl;
				position++;
			}
			Assert::IsTrue(position != 0);
			String.erase();
			String = "(2+6*)";
			position = 0;
			try
			{
				correct(String, position);
			}
			catch (const invalid_argument error)
			{
				cout << error.what() << endl;
				position++;
			}
			String.erase();
			Assert::IsTrue(position != 0);
			String = "ln~e";
			position = 0;
			try
			{
				correct(String, position);
			}
			catch (const invalid_argument error)
			{
				cout << error.what() << endl;
				position++;	
			}
			Assert::IsTrue(position != 0);
		}
		
		TEST_METHOD(TestFilling)
		{
			string stroka = "1+2*3-4^2";
			arrayoper = (char*)malloc(poststring.size() * sizeof(char));
			arraynumber = (double*)malloc(poststring.size() * sizeof(double));
			poststring = filling(stroka, poststring);
			Assert::IsTrue(poststring == "1 2 3  * +4 2 ^-");
		}
		TEST_METHOD(TestProsessing)
		{
			string stroka = "1+2*3-4^2";
			arrayoper = (char*)malloc(poststring.size() * sizeof(char));
			arraynumber = (double*)malloc(poststring.size() * sizeof(double));
			poststring = filling(stroka, poststring);
			double result = processing(poststring);
			Assert::IsTrue(result == -9);
			poststring.clear();
			stroka.clear();
			stroka = "cos1-pi+lne-ctg3+20^lg10";
			delete(arrayoper);
			delete(arraynumber);
			arrayoper = (char*)malloc(poststring.size() * sizeof(char));
			arraynumber = (double*)malloc(poststring.size() * sizeof(double));
			poststring = filling(stroka, poststring);
			result = processing(poststring);
			Assert::IsTrue(result == 25.413962203712881);
			poststring.clear();
			stroka.clear();
			stroka = "sin1+~log8-tgpi+sqrt81";
			delete(arrayoper);
			delete(arraynumber);
			arrayoper = (char*)malloc(poststring.size() * sizeof(char));
			arraynumber = (double*)malloc(poststring.size() * sizeof(double));
			poststring = filling(stroka, poststring);
			result = processing(poststring);
			Assert::IsTrue(result == 6.8414709848078967);

		}
		TEST_METHOD(TestNotation)
		{
			string stroka = "sin1+~log8-tgpi+sqrt81";
			arrayoper = (char*)malloc(poststring.size() * sizeof(char));
			arraynumber = (double*)malloc(poststring.size() * sizeof(double));
			poststring = filling(stroka, poststring);
			poststring = notation(poststring);
			Assert::IsTrue(poststring == "1 sin 8 log ~ + pi tg - 81 sqrt + ");
			poststring.clear();
			stroka.clear();
			delete(arrayoper);
			delete(arraynumber);
			arrayoper = (char*)malloc(poststring.size() * sizeof(char));
			arraynumber = (double*)malloc(poststring.size() * sizeof(double));
			stroka = "cos1-pi+lne-ctg3+20^lg10";
			poststring = filling(stroka, poststring);
			poststring = notation(poststring);
			Assert::IsTrue(poststring == "1 cos pi - e ln + 3 ctg - 20 10 lg ^ + ");
			delete(arrayoper);
			delete(arraynumber);
			arrayoper = (char*)malloc(poststring.size() * sizeof(char));
			arraynumber = (double*)malloc(poststring.size() * sizeof(double));
			poststring.clear();
			stroka.clear();
			stroka = "1+2*3-4^2";
			poststring = filling(stroka, poststring);
			poststring = notation(poststring);
			Assert::IsTrue(poststring == "1 2 3 * + 4 2 ^ - ");
		}
	};
}
