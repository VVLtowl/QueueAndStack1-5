/*********************************************************
* @brief	スタックのヘッダーファイル
* @date		2022/10/20
********************************************************/
#pragma once
#include "DoubleLinkedList.h"

/*********************************************************
* @brief		スタック
* @details		スタックのテンプレート
* @tparam		DataType: データの型
********************************************************/
template <class DataType>
class Stack
{
private:
	// @brief		双方向リスト
	DoubleLinkedList<DataType> list;

public:

	//const メソッド

	/*********************************************************
	* @brief	要素数を取得する
	* @return	要素数を返す
	********************************************************/
	const int Count() const;

	/*********************************************************
	* @brief	プッシュ
	* @details	末尾に要素を追加する。
	* @param	data: 追加したい要素
	* @retval	true: プッシュ成功の場合	
	* @retval	false: プッシュ失敗の場合
	********************************************************/
	bool Push(DataType data);

	/*********************************************************
	* @brief		ポップ
	* @details		末尾要素が引数経由で渡され、その要素がリストから削除される。
	*				空である場合に失敗。
	* @param[out]	pOptData: 取り出す要素を格納ための引数
	* @retval		true: ポップ成功の場合
	* @retval		false: ポップ失敗の場合
	********************************************************/
	bool Pop(DataType* pOptData=nullptr);
};

#include "Stack.inl"
