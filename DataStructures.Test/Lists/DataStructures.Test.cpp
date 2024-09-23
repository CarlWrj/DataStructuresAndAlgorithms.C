#include "CppUnitTest.h"
#include "..\..\DataStructures\SequenceList.h"
#include "..\..\DataStructures\SequenceList.c"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DataStructuresTest_Lists
{
	TEST_CLASS(DataStructuresTest_Lists)
	{
	public:

		TEST_METHOD(TestMethod)
		{
			//初始化
			SequenceList sequenceList;
			Assert::IsTrue(SequenceList_Init(&sequenceList, 10));

			//插入
			for (int i = 1; i <= 15; i++)
			{
				Assert::IsTrue(SequenceList_Insert(&sequenceList, i, i));
			}

			//查找
			for (int i = 1; i <= 15; i++)
			{
				SequenceListElementType element;
				Assert::IsTrue(SequenceList_Get(&sequenceList, i, &element));
				Assert::AreEqual(i, element);

				int index = SequenceList_Index(&sequenceList, element);
				Assert::AreEqual(i, index);
			}

			//删除
			for (int i = 1; i <= 15; i++)
			{
				Assert::IsTrue(SequenceList_Delete(&sequenceList, 1));
			}
			Assert::AreEqual(0, sequenceList.Length);
		}
	};
}
