/*********************************************************
* @brief	キューの詳細定義
* @date		2022/10/20
********************************************************/
#include "Queue.h"

template<class DataType>
inline const int Queue<DataType>::Count() const
{
	return 0;
}

template<class DataType>
inline bool Queue<DataType>::Push(DataType data)
{
	return false;
}

template<class DataType>
inline DataType& Queue<DataType>::Pop()
{
	// TODO: 在此处插入 return 语句
}
