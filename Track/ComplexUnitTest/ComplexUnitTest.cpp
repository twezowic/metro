#include "CppUnitTest.h"
#include "../ComplexLib/Complex.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
/*
namespace ComplexUnitTest
{
	TEST_CLASS(ComplexUnitTest)
	{
	public:
		TEST_METHOD(ConstructorParameterless)
		{
			Complex c;
			Assert::AreEqual(0.0, c.getReal(), std::numeric_limits<double>::epsilon());
			Assert::AreEqual(0.0, c.getImaginary(), std::numeric_limits<double>::epsilon());
		}
		TEST_METHOD(ConstructorWithParameter)
		{
			Complex c(12.37, -14.89);
			Assert::AreEqual(12.37, c.getReal(), 0.01);
			Assert::AreEqual(-14.89, c.getImaginary(), 0.01);
		}
		TEST_METHOD(getReal)
		{
			Complex c(-23.74, 134.89);
			Assert::AreEqual(-23.74, c.getReal(), 0.01);
		}
		TEST_METHOD(getImaginary)
		{
			Complex c(-23.74, 134.89);
			Assert::AreEqual(134.89, c.getImaginary(), 0.01);
		}
		TEST_METHOD(setReal)
		{
			Complex c(-23.74, 134.89);
			c.setReal(920.23);
			Assert::AreEqual(920.23, c.getReal(), 0.01);
		}
		TEST_METHOD(setImaginary)
		{
			Complex c(-23.74, 134.89);
			c.setImaginary(-529.23);
			Assert::AreEqual(-529.23, c.getImaginary(), 0.01);
		}
		TEST_METHOD(magnitudeZeroZero)
		{
			Complex c(0.0, 0.0);
			Assert::AreEqual(0.0, c.magnitude(), 0.01);
		}
		TEST_METHOD(magnitude0deg)
		{
			Complex c(4.0, 0.0);
			Assert::AreEqual(4.0, c.magnitude(), 0.01);
		}
		TEST_METHOD(magnitude90deg)
		{
			Complex c(0.0, 6.0);
			Assert::AreEqual(6.0, c.magnitude(), 0.01);
		}
		TEST_METHOD(magnitude180deg)
		{
			Complex c(-5.0, 0.0);
			Assert::AreEqual(5.0, c.magnitude(), 0.01);
		}
		TEST_METHOD(magnitude270deg)
		{
			Complex c(0.0, -12.0);
			Assert::AreEqual(12.0, c.magnitude(), 0.01);
		}
		TEST_METHOD(magnitudeIQuarter)
		{
			Complex c(233.74, 153.89);
			Assert::AreEqual(279.85, c.magnitude(), 0.01);
		}
		TEST_METHOD(magnitudeIIQuarter)
		{
			Complex c(-313.24, 713.48);
			Assert::AreEqual(779.21, c.magnitude(), 0.01);
		}
		TEST_METHOD(magnitudeIIIQuarter)
		{
			Complex c(-45.62, -92.17);
			Assert::AreEqual(102.84, c.magnitude(), 0.01);
		}
		TEST_METHOD(magnitudeVIQuarter)
		{
			Complex c(512.79, -821.59);
			Assert::AreEqual(968.48, c.magnitude(), 0.01);
		}
		TEST_METHOD(directionZeroZero)
		{
			Complex c(0.0, 0.0);
			Assert::AreEqual(0.0, c.direction(), 0.01);
		}
		TEST_METHOD(direction0deg)
		{
			Complex c(4.0, 0.0);
			Assert::AreEqual(0.0, c.direction(), 0.01);
		}
		TEST_METHOD(direction90deg)
		{
			Complex c(0.0, 6.0);
			Assert::AreEqual(1.57, c.direction(), 0.01);
		}
		TEST_METHOD(direction180deg)
		{
			Complex c(-5.0, 0.0);
			Assert::AreEqual(3.14, c.direction(), 0.01);
		}
		TEST_METHOD(direction270deg)
		{
			Complex c(0.0, -12.0);
			Assert::AreEqual(-1.57, c.direction(), 0.01);
		}
		TEST_METHOD(directionIQuarter)
		{
			Complex c(23.74, 3.89);
			Assert::AreEqual(0.16, c.direction(), 0.01);
		}
		TEST_METHOD(directionIIQuarter)
		{
			Complex c(-13.44, 45.41);
			Assert::AreEqual(1.86, c.direction(), 0.01);
		}
		TEST_METHOD(directionIIIQuarter)
		{
			Complex c(-71.12, -932.92);
			Assert::AreEqual(-1.65, c.direction(), 0.01);
		}
		TEST_METHOD(directionIVQuarter)
		{
			Complex c(712.81, -434.39);
			Assert::AreEqual(-0.55, c.direction(), 0.01);
		}
		TEST_METHOD(operatorPlusComplexComplex)
		{
			Complex a;
			Complex b(12.87, -44.39);
			Complex c(-2.41, 34.35);
			a = b + c;
			Assert::AreEqual(10.46, a.getReal(), 0.01);
			Assert::AreEqual(-10.04, a.getImaginary(), 0.01);
		}
		TEST_METHOD(operatorMinusComplexComplex)
		{
			Complex a;
			Complex b(-42.53, -54.19);
			Complex c(25.31, 47.74);
			a = b - c;
			Assert::AreEqual(-67.84, a.getReal(), 0.01);
			Assert::AreEqual(-101.93, a.getImaginary(), 0.01);
		}
		TEST_METHOD(operatorPlusComplexReal)
		{
			Complex a;
			Complex b(322.51, -564.19);
			a = b + 34.29;
			Assert::AreEqual(356.8, a.getReal(), 0.01);
			Assert::AreEqual(-564.19, a.getImaginary(), 0.01);
		}
		TEST_METHOD(operatorMinusComplexReal)
		{
			Complex a;
			Complex b(25.31, 47.74);
			a = b - (-34.54);
			Assert::AreEqual(59.85, a.getReal(), 0.01);
			Assert::AreEqual(47.74, a.getImaginary(), 0.01);
		}
		TEST_METHOD(operatorPlusEqualComplex)
		{
			Complex a(12.87, -44.39);
			Complex b(-2.41, 34.35);
			a += b;
			Assert::AreEqual(10.46, a.getReal(), 0.01);
			Assert::AreEqual(-10.04, a.getImaginary(), 0.01);
		}
		TEST_METHOD(operatorMinusEqualComplex)
		{
			Complex a(-42.53, -54.19);
			Complex b(25.31, 47.74);
			a -= b;
			Assert::AreEqual(-67.84, a.getReal(), 0.01);
			Assert::AreEqual(-101.93, a.getImaginary(), 0.01);
		}
		TEST_METHOD(operatorPlusEqualReal)
		{
			Complex a(322.51, -564.19);
			a += 34.29;
			Assert::AreEqual(356.8, a.getReal(), 0.01);
			Assert::AreEqual(-564.19, a.getImaginary(), 0.01);
		}
		TEST_METHOD(operatorMinusEqualReal)
		{
			Complex a(25.31, 47.74);
			a -= -34.54;
			Assert::AreEqual(59.85, a.getReal(), 0.01);
			Assert::AreEqual(47.74, a.getImaginary(), 0.01);
		}
		TEST_METHOD(operatorEqualComplexComplexEqualReAndIm)
		{
			Complex a(25.31, 47.74);
			Complex b(25.31, 47.74);
			Assert::IsTrue(a == b);
		}
		TEST_METHOD(operatorEqualComplexComplexEqualReNotEqualIm)
		{
			Complex a(25.31, 47.74);
			Complex b(25.31, 53.43);
			Assert::IsFalse(a == b);
		}
		TEST_METHOD(operatorEqualComplexComplexNotEqualReEqualIm)
		{
			Complex a(95.73, 53.43);
			Complex b(-31.21, 53.43);
			Assert::IsFalse(a == b);
		}
		TEST_METHOD(operatorEqualComplexComplexNotEqualReAndIm)
		{
			Complex a(45.53, 23.13);
			Complex b(-31.21, 57.48);
			Assert::IsFalse(a == b);
		}
		TEST_METHOD(operatorNotEqualComplexComplexEqualReAndIm)
		{
			Complex a(-534.71, -37.84);
			Complex b(-534.71, -37.84);
			Assert::IsFalse(a != b);
		}
		TEST_METHOD(operatorNotEqualComplexComplexEqualReNotEqualIm)
		{
			Complex a(-32.63, 87.74);
			Complex b(-32.63, -23.43);
			Assert::IsTrue(a != b);
		}
		TEST_METHOD(operatorNotEqualComplexComplexNotEqualReEqualIm)
		{
			Complex a(-92.73, -93.73);
			Complex b(31.51, -93.73);
			Assert::IsTrue(a != b);
		}
		TEST_METHOD(operatorNotEqualComplexComplexNotEqualReAndIm)
		{
			Complex a(31.58, 92.53);
			Complex b(-62.21, 57.48);
			Assert::IsTrue(a != b);
		}
		TEST_METHOD(operatorEqualComplexRealEqual)
		{
			Complex a(151.58, 0.0);
			Assert::IsTrue(a == 151.58);
		}
		TEST_METHOD(operatorEqualComplexRealReNotEqualImZero)
		{
			Complex a(11.27, 0.0);
			Assert::IsFalse(a == 51.58);
		}
		TEST_METHOD(operatorEqualComplexRealReNotEqualImNotZero)
		{
			Complex a(13.25, -1.73);
			Assert::IsFalse(a == 51.58);
		}
		TEST_METHOD(operatorEqualComplexRealReEqualImNotZero)
		{
			Complex a(43.25, -31.48);
			Assert::IsFalse(a == 43.25);
		}
		TEST_METHOD(operatorNotEqualComplexRealEqual)
		{
			Complex a(271.58, 0.0);
			Assert::IsFalse(a != 271.58);
		}
		TEST_METHOD(operatorNotEqualComplexRealReNotEqualImZero)
		{
			Complex a(37.17, 0.0);
			Assert::IsTrue(a != 62.71);
		}
		TEST_METHOD(operatorNotEqualComplexRealReNotEqualImNotZero)
		{
			Complex a(49.55, 5.43);
			Assert::IsTrue(a != 81.28);
		}
		TEST_METHOD(operatorNotEqualComplexRealReEqualImNotZero)
		{
			Complex a(-73.25, 26.94);
			Assert::IsTrue(a != -73.25);
		}
		TEST_METHOD(operatorPlusRealComplex)
		{
			Complex a;
			Complex b(-2.41, 14.25);
			a = 5.81 + b;
			Assert::AreEqual(3.40, a.getReal(), 0.01);
			Assert::AreEqual(14.25, a.getImaginary(), 0.01);
		}
		TEST_METHOD(operatorMinusRealComplex)
		{
			Complex a;
			Complex b(29.11, 74.65);
			a = 5.81 - b;
			Assert::AreEqual(-23.30, a.getReal(), 0.01);
			Assert::AreEqual(-74.65, a.getImaginary(), 0.01);
		}
		TEST_METHOD(operatorEqualRealComplexEqual)
		{
			Complex a(151.58, 0.0);
			Assert::IsTrue(151.58 == a);
		}
		TEST_METHOD(operatorEqualRealComplexReNotEqualImZero)
		{
			Complex a(11.27, 0.0);
			Assert::IsFalse(51.58 == a);
		}
		TEST_METHOD(operatorEqualRealComplexReNotEqualImNotZero)
		{
			Complex a(13.25, -1.73);
			Assert::IsFalse(51.58 == a);
		}
		TEST_METHOD(operatorEqualRealComplexReEqualImNotZero)
		{
			Complex a(43.25, -31.48);
			Assert::IsFalse(43.25 == a);
		}
		TEST_METHOD(operatorNotEqualRealComplexEqual)
		{
			Complex a(271.58, 0.0);
			Assert::IsFalse(271.58 != a);
		}
		TEST_METHOD(operatorNotEqualRealComplexReNotEqualImZero)
		{
			Complex a(37.17, 0.0);
			Assert::IsTrue(62.71 != a);
		}
		TEST_METHOD(operatorNotEqualRealComplexReNotEqualImNotZero)
		{
			Complex a(49.55, 5.43);
			Assert::IsTrue(81.28 != a);
		}
		TEST_METHOD(operatorNotEqualRealComplexReEqualImNotZero)
		{
			Complex a(-73.25, 26.94);
			Assert::IsTrue(-73.25 != a);
		}
	};
}*/