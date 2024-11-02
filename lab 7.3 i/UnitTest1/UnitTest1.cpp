#include "pch.h"
#include "CppUnitTest.h"
#include "../lab 7.3 i/lab 7.3 i.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            const int rowCount = 3;
            const int colCount = 3;
            int* a[rowCount];

            int row0[] = { 1, 2, 3 };
            int row1[] = { 0, 1, 2 };
            int row2[] = { 4, 5, 6 };
            a[0] = row0;
            a[1] = row1;
            a[2] = row2;

            double threshold = 2.5;
            int expectedCount = 2; // тільки рядок [0, 1, 2] має середнє арифметичне менше 2.5
            int actualCount = CountRowsWithAvgLessThan(a, rowCount, colCount, threshold);

            Assert::AreEqual(expectedCount, actualCount);
        }

        TEST_METHOD(TestMethod2)
        {
            const int rowCount = 3;
            const int colCount = 3;
            int* a[rowCount];

            int row0[] = { 10, 20, 30 };
            int row1[] = { 5, 10, 15 };
            int row2[] = { 3, 6, 9 };
            a[0] = row0;
            a[1] = row1;
            a[2] = row2;

            double threshold = 10.0;
            int expectedCount = 1; // рядки [5, 10, 15] і [3, 6, 9] мають середнє арифметичне менше 10
            int actualCount = CountRowsWithAvgLessThan(a, rowCount, colCount, threshold);

            Assert::AreEqual(expectedCount, actualCount);
        }
    };
}
