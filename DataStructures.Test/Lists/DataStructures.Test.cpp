#include "CppUnitTest.h"
#include "..\..\DataStructures\SequenceList.h"
#include "..\..\DataStructures\SequenceList.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DataStructuresTest_Lists
{
	TEST_CLASS(DataStructuresTest_Lists)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			//初始化
			SequenceList sequenceList;
			bool result = SequenceList_Init(&sequenceList, 10);
			Assert::IsTrue(result);

			//插入
			for (int i = 1; i <= 15; i++)
			{
				Assert::IsTrue(SequenceList_Insert(&sequenceList, i, i));
			}

			//查找
			for (int i = 1; i <= 15; i++)
			{
				Assert::AreEqual(i, SequenceList_Get(&sequenceList, i));
			}

			//删除
			for (int i = 1; i <= 15; i++)
			{
				Assert::IsTrue(SequenceList_Delete(&sequenceList, i));
			}
			Assert::AreEqual(0, sequenceList.Length);
		}
	};
}
