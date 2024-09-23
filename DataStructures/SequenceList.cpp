
#include "SequenceList.h"
#include <corecrt_malloc.h>

/// <summary>
/// ��ʼ��˳���
/// </summary>
/// <param name="sequenceList"></param>
/// <param name="maxSize"></param>
/// <returns></returns>
bool SequenceList_Init(SequenceList* sequenceList, int maxSize)
{
	if (maxSize < 0)
	{
		return false;
	}

	(*sequenceList).Data = (SequenceListElementType*)malloc(maxSize * sizeof(SequenceListElementType));
	if (!(*sequenceList).Data)
		return false;

	(*sequenceList).Length = 0;
	(*sequenceList).MaxSize = maxSize;

	return true;
}

/// <summary>
/// ����Ԫ��
/// </summary>
/// <param name="position">��1��ʼ��</param>
/// <param name="element"></param>
bool SequenceList_Insert(SequenceList* sequenceList, int position, SequenceListElementType element)
{
	if (position < 1)
	{
		return false;
	}

	//���洢�ռ��������迪���¿ռ� 
	SequenceListElementType* newbase;
	if (position > (*sequenceList).MaxSize)
	{
		newbase = (SequenceListElementType*)realloc((*sequenceList).Data, ((*sequenceList).MaxSize + position + LISTINCREMENT) * sizeof(SequenceListElementType));
		if (!newbase)
			return false;

		(*sequenceList).Data = newbase;
		(*sequenceList).MaxSize += LISTINCREMENT;
	}

	SequenceListElementType* p, * q;
	//qΪ����λ��
	q = &(*sequenceList).Data[position - 1];
	for (p = &(*sequenceList).Data[(*sequenceList).Length - 1]; p >= q; p--)
	{
		*(p + 1) = *p;
	}

	*q = element;
	(*sequenceList).Length++;
	return true;
}

/// <summary>
/// ��ȡԪ��
/// </summary>
/// <param name="sequenceList"></param>
/// <param name="position"></param>
/// <returns></returns>
SequenceListElementType SequenceList_Get(SequenceList* sequenceList, int position)
{
	if (position < 1 || position >(*sequenceList).MaxSize)
	{
		return false;
	}

	return (*sequenceList).Data[position - 1];
}

/// <summary>
/// ɾ��Ԫ��
/// </summary>
/// <param name="sequenceList"></param>
/// <param name="position"></param>
/// <returns></returns>
bool SequenceList_Delete(SequenceList* sequenceList, int position)
{
	if (position < 1 || position >(*sequenceList).MaxSize)
	{
		return false;
	}

	SequenceListElementType* startP, * endP;
	endP = &(*sequenceList).Data[(*sequenceList).Length - 1];
	for (startP = (*sequenceList).Data + (position - 1); endP >= startP; startP++)
	{
		*startP = *(startP + 1);
	}

	(*sequenceList).Length--;

	return true;
}