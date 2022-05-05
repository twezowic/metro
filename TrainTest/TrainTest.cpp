#include "CppUnitTest.h"
#include "../TrainLib/Train.h"
#include"../WagonLib/Wagon.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TrainTest
{
	TEST_CLASS(TrainTest)
	{
	public:
		
		TEST_METHOD(Constructor)
		{
			std::vector<Station_ptr> v;
			Train a = Train(1, 10, v);
		}
	};
	TEST_CLASS(WagonTest)
	{
	public:

		TEST_METHOD(Constructor)
		{
			Wagon wag = Wagon(15, 10);
			Assert::AreEqual(15, wag.getID(), 0.05);
		}
	};

}
