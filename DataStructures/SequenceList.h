#pragma once

#define WIN32_LEAN_AND_MEAN             // �� Windows ͷ�ļ����ų�����ʹ�õ�����

#define LISTINCREMENT  10				//˳���洢�ռ�ķ�������

/// <summary>
/// ˳�������
/// </summary>
typedef int SequenceListElementType;

typedef struct
{
	/// <summary>
	/// ����
	/// </summary>
	SequenceListElementType* Data;

	/// <summary>
	/// �������
	/// </summary>
	int MaxSize;

	/// <summary>
	/// ����
	/// </summary>
	int Length;

}SequenceList;


