#pragma once

#define WIN32_LEAN_AND_MEAN             // 从 Windows 头文件中排除极少使用的内容

#define LISTINCREMENT  10				//顺序表存储空间的分配增量

/// <summary>
/// 顺序表类型
/// </summary>
typedef int SequenceListElementType;

typedef struct
{
	/// <summary>
	/// 数据
	/// </summary>
	SequenceListElementType* Data;

	/// <summary>
	/// 最大容量
	/// </summary>
	int MaxSize;

	/// <summary>
	/// 长度
	/// </summary>
	int Length;

}SequenceList;


