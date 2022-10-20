/*********************************************************
* @brief	スタックの詳細定義
* @date		2022/10/20
********************************************************/
#include "Stack.h"

template<class DataType>
inline const int Stack<DataType>::Count() const
{
	return list.Count();
}

template<class DataType>
inline bool Stack<DataType>::Push(DataType data)
{
	auto iter = list.End();
	return list.Insert(iter, data);
}

template<class DataType>
inline bool Stack<DataType>::Pop(DataType* pOptData)
{
	//空である場合に失敗
	if (Count() == 0)
	{
		return false;
	}

	//先頭要素を取り出す
	auto iter = list.End();
	iter--;
	if (pOptData != nullptr)
	{
		*pOptData = *iter;
	}
	list.Remove(iter);
	return true;
}
