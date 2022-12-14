/*********************************************************
* @brief	キューの詳細定義
* @date		2022/10/20
********************************************************/
#include "Queue.h"

template<class DataType>
inline const int Queue<DataType>::Count() const
{
	return m_List.Count();
}

template<class DataType>
inline bool Queue<DataType>::Push(const DataType& data)
{
	auto iter = m_List.End();
	return m_List.Insert(iter, data);
}

template<class DataType>
inline bool Queue<DataType>::Pop(DataType* pOptData)
{
	//空である場合に失敗
	if (Count() == 0)
	{
		return false;
	}

	//先頭要素を取り出す
	auto iter = m_List.Begin();
	if (pOptData != nullptr)
	{
		*pOptData = *iter;
	}
	m_List.Remove(iter);
	return true;
}
