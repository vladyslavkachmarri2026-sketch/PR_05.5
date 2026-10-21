#include "pch.h"
#include "CppUnitTest.h"
#include "../PR_05.5.cpp" // підключив свій проект (змініть шлях/назву на свої)

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest12
{
    TEST_CLASS(UnitTest12)
    {
    public:

        // 1. Тест кореня на відрізку [0, 2]: очікуємо pi/4
        TEST_METHOD(TestMethod_RootOnZeroTwo)
        {
            double pi = 3.14159265358979323846;
            int depth = 0;
            double actual = bisect(0, 2, 1e-6, 1, depth);

            Assert::AreEqual(pi / 4, actual, 1e-6);
        }

        // 2. Тест кореня на відрізку [3, 5]: очікуємо 5*pi/4 (знаки змінюються в інший бік)
        TEST_METHOD(TestMethod_RootOnThreeFive)
        {
            double pi = 3.14159265358979323846;
            int depth = 0;
            double actual = bisect(3, 5, 1e-6, 1, depth);

            Assert::AreEqual(5 * pi / 4, actual, 1e-6);
        }

        // 3. Значення функції в знайденому корені має бути майже нулем
        TEST_METHOD(TestMethod_FunctionValueAtRoot)
        {
            int depth = 0;
            double root = bisect(0, 2, 1e-6, 1, depth);

            Assert::AreEqual(0.0, f(root), 1e-5);
        }

        // 4. Глибина рекурсії для [0, 2], eps = 0.001 дорівнює 12
        TEST_METHOD(TestMethod_DepthValue)
        {
            int depth = 0;
            bisect(0, 2, 0.001, 1, depth);

            Assert::AreEqual(12, depth);
        }

        // 5. Менша eps дає більшу глибину рекурсії
        TEST_METHOD(TestMethod_SmallerEpsBiggerDepth)
        {
            int depthBig = 0, depthSmall = 0;
            bisect(0, 2, 1e-2, 1, depthBig);
            bisect(0, 2, 1e-8, 1, depthSmall);

            Assert::IsTrue(depthSmall > depthBig);
        }

        // 6. Якщо відрізок уже менший за eps - лише один виклик (глибина 1)
        TEST_METHOD(TestMethod_IntervalSmallerThanEps)
        {
            int depth = 0;
            bisect(0.7, 0.8, 1.0, 1, depth);

            Assert::AreEqual(1, depth);
        }

        // 7. depth зберігає максимум (перевірка умови level > depth)
        TEST_METHOD(TestMethod_DepthKeepsMaximum)
        {
            int depth = 100;
            bisect(0, 2, 0.001, 1, depth);

            Assert::AreEqual(100, depth);
        }

        // 8. Тест функції f: f(0) = -1
        TEST_METHOD(TestMethod_FunctionAtZero)
        {
            Assert::AreEqual(-1.0, f(0.0), 1e-7);
        }

        // 9. Тест функції f: f(pi/4) = 0
        TEST_METHOD(TestMethod_FunctionAtPiOverFour)
        {
            double pi = 3.14159265358979323846;

            Assert::AreEqual(0.0, f(pi / 4), 1e-7);
        }
    };
}