
#include "SequenceList.h"
#include <corecrt_malloc.h>

/// <summary>
/// 初始化顺序表
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
/// 插入元素
/// </summary>
/// <param name="position">从1开始算</param>
/// <param name="element"></param>
bool SequenceList_Insert(SequenceList* sequenceList, int position, SequenceListElementType element)
{
	if (position < 1)
	{
		return false;
	}

	//若存储空间已满，需开辟新空间 
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
	//q为插入位置
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
/// 获取元素
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
/// 删除元素
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