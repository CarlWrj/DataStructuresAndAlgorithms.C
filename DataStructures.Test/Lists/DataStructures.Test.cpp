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
			//��ʼ��
			SequenceList sequenceList;
			bool result = SequenceList_Init(&sequenceList, 10);
			Assert::IsTrue(result);

			//����
			for (int i = 1; i <= 15; i++)
			{
				Assert::IsTrue(SequenceList_Insert(&sequenceList, i, i));
			}

			//����
			for (int i = 1; i <= 15; i++)
			{
				Assert::AreEqual(i, SequenceList_Get(&sequenceList, i));
			}

			//ɾ��
			for (int i = 1; i <= 15; i++)
			{
				Assert::IsTrue(SequenceList_Delete(&sequenceList, i));
			}
			Assert::AreEqual(0, sequenceList.Length);
		}
	};
}
