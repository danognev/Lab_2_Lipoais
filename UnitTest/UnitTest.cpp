#include "CppUnitTest.h"
#include "..\Lab_2\GameModel.cpp"
#include "..\Lab_2\FunctionsMenu.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab2Var7UnitTest
{
	TEST_CLASS(Lab2Var7UnitTest)
	{
	public:
		
		TEST_METHOD(TestVoidFieldEvolve)
		{
			const int width = 30;
			int countevolution = 1;
			bool field[width][width], newfield[width][width];
			for (size_t i = 0; i < width; i++)
				for (size_t j = 0; j < width; j++) {
					field[i][j] = false;
					newfield[i][j] = field[i][j];
				}
			bool testflag = true;
			EvolutionPlayingField(field, countevolution, false);
			for (size_t i = 0; i < width; i++)
				for (size_t j = 0; j < width; j++)
					if (field[i][j] != newfield[i][j])
						testflag = false;
			Assert::IsTrue(testflag, L"Test 1");
		}
		TEST_METHOD(TestOneEvolveLivelyFigure)
		{
			const int width = 30;
			int countevolution = 1;
			bool field[width][width], newfield[width][width];
			for (size_t i = 0; i < width; i++)
				for (size_t j = 0; j < width; j++) {
					field[i][j] = false;
					newfield[i][j] = field[i][j];
				}
			field[0][0] = true; // Фигура **
			field[0][1] = true; //        *
			field[1][0] = true;
			newfield[0][0] = true; // Итоговая **
			newfield[0][1] = true; // Фигура   **
			newfield[1][0] = true;
			newfield[1][1] = true;
			bool testflag = true;
			EvolutionPlayingField(field, countevolution, false);
			for (size_t i = 0; i < width; i++)
				for (size_t j = 0; j < width; j++)
					if (field[i][j] != newfield[i][j])
						testflag = false;
			Assert::IsTrue(testflag, L"Test 2");
		}
		TEST_METHOD(TestOneEvolveDyingFigure)
		{
			const int width = 30;
			int countevolution = 1;
			bool field[width][width], newfield[width][width];
			for (size_t i = 0; i < width; i++)
				for (size_t j = 0; j < width; j++) {
					field[i][j] = false;
					newfield[i][j] = field[i][j];
				}
			field[0][0] = true; // Фигура **
			field[0][1] = true; 
			bool testflag = true;
			EvolutionPlayingField(field, countevolution, false);
			for (size_t i = 0; i < width; i++)
				for (size_t j = 0; j < width; j++)
					if (field[i][j] != newfield[i][j])
						testflag = false;
			Assert::IsTrue(testflag, L"Test 3");
		}
		TEST_METHOD(TestOfChangesInADyingFigure)
		{
			const int width = 30;
			int countevolution = 1;
			bool field[width][width], newfield[width][width];
			for (size_t i = 0; i < width; i++)
				for (size_t j = 0; j < width; j++) {
					field[i][j] = false;
					newfield[i][j] = field[i][j];
				}
			field[0][0] = true;	   // Фигура *  *
			field[2][0] = true;    //           *
			field[2][1] = true;
			newfield[1][0] = true; // Фигура после     *
			newfield[1][1] = true; // первой эволюции  *
			bool testflag = true;  // После второй эволюции должа быть смерть колонии
			EvolutionPlayingField(field, countevolution, false); // Первая эволюция
			for (size_t i = 0; i < width; i++)
				for (size_t j = 0; j < width; j++)
					if (field[i][j] != newfield[i][j])
						testflag = false;
			Assert::IsTrue(testflag, L"Test 4.1");
			for (size_t i = 0; i < width; i++)
				for (size_t j = 0; j < width; j++)
					newfield[i][j] = false;
			testflag = true;
			EvolutionPlayingField(field, countevolution, false); // Вторая эволюция
			for (size_t i = 0; i < width; i++)
				for (size_t j = 0; j < width; j++)
					if (field[i][j] != newfield[i][j])
						testflag = false;
			Assert::IsTrue(testflag, L"Test 4.2");
		}
		TEST_METHOD(TestFiveEvolveLivelyFigure)
		{
			const int width = 30;
			int countevolution = 5;
			bool field[width][width], newfield[width][width];
			for (size_t i = 0; i < width; i++)
				for (size_t j = 0; j < width; j++) {
					field[i][j] = false;
					newfield[i][j] = field[i][j];
				}
			field[0][1] = true; // Фигура *
			field[1][1] = true; //        *
			field[2][1] = true; //        *  
			newfield[1][0] = true; // Итоговая фигура ***
			newfield[1][1] = true;
			newfield[1][2] = true;
			bool testflag = true;
			EvolutionPlayingField(field, countevolution, false);
			for (size_t i = 0; i < width; i++)
				for (size_t j = 0; j < width; j++)
					if (field[i][j] != newfield[i][j])
						testflag = false;
			Assert::IsTrue(testflag, L"Test 5");
		}

	};
}
