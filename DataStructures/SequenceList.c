
#include "SequenceList.h"
#include <corecrt_malloc.h>

/// <summary>
/// ��ʼ��˳���
/// </summary>
/// <param name="sequenceList"></param>
/// <param name="maxSize"></param>
/// <returns></returns>
int SequenceList_Init(SequenceList* sequenceList, int maxSize)
{
	if (maxSize < 0)
	{
		return 0;
	}

	(*sequenceList).Data = (SequenceListElementType*)malloc(maxSize * sizeof(SequenceListElementType));
	if (!(*sequenceList).Data)
		return 0;

	(*sequenceList).Length = 0;
	(*sequenceList).MaxSize = maxSize;

	return 1;
}

/// <summary>
/// ����Ԫ��
/// </summary>
/// <param name="position">��1��ʼ��</param>
/// <param name="element"></param>
int SequenceList_Insert(SequenceList* sequenceList, int position, SequenceListElementType element)
{
	if (position < 1)
	{
		return 0;
	}

	//���洢�ռ��������迪���¿ռ� 
	SequenceListElementType* newbase;
	if (position > (*sequenceList).MaxSize)
	{
		newbase = (SequenceListElementType*)realloc((*sequenceList).Data, ((*sequenceList).MaxSize + position + LISTINCREMENT) * sizeof(SequenceListElementType));
		if (!newbase)
			return 0;

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
	return 1;
}

/// <summary>
/// ��ȡԪ��
/// </summary>
/// <param name="sequenceList"></param>
/// <param name="position"></param>
/// <returns></returns>
int SequenceList_Get(SequenceList* sequenceList, int position, SequenceListElementType* element)
{
	if (position < 1 || position >(*sequenceList).Length)
	{
		return 0;
	}

	*element = (*sequenceList).Data[position - 1];
}

/// <summary>
/// ��ȡ�±�
/// </summary>
/// <param name="sequenceList"></param>
/// <param name="position"></param>
/// <returns></returns>
int SequenceList_Index(SequenceList* sequenceList, SequenceListElementType element)
{
	int index = 0;

	for (int i = 0; i < (*sequenceList).Length; i++)
	{
		if (*((*sequenceList).Data + i) == element)
		{
			return i + 1;
		}
	}

	return index;
}

/// <summary>
/// ɾ��Ԫ��
/// </summary>
/// <param name="sequenceList"></param>
/// <param name="position"></param>
/// <returns></returns>
int SequenceList_Delete(SequenceList* sequenceList, int position)
{
	if (position < 1 || position >(*sequenceList).Length)
	{
		return 0;
	}

	SequenceListElementType* start, * end;
	end = &(*sequenceList).Data[(*sequenceList).Length - 1];
	for (start = (*sequenceList).Data + (position - 1); end >= start; start++)
	{
		*start = *(start + 1);
	}

	(*sequenceList).Length--;

	return 1;
}