/*********************************************************
* @brief	双方向リストのヘッダーファイル
* @date		2022/10/11
********************************************************/
#pragma once

/*********************************************************
* @brief		双方向リスト
* @details		双方向リストのテンプレート
* @tparam		DataType: データの型
********************************************************/
template <class DataType>
class DoubleLinkedList
{
private:
	/*********************************************************
	* @brief	ノードの構造体
	********************************************************/
	struct Node
	{
		// @brief	前のノードへのポインタ
		Node* pPrev = nullptr;

		// @brief	次のノードへのポインタ
		Node* pNext = nullptr;

		// @brief	データ
		DataType data;
	};

public:
	/*********************************************************
	* @brief	コンストイテレータ
	********************************************************/
	class ConstIterator
	{
	protected:
		// @brief	ノードへのポインタ
		Node* m_pNode;

		// @brief	リストへのポインタ
		const DoubleLinkedList* m_pList;

	protected:
		/*********************************************************
		* @brief	有効なイテレータであるか
		* @details	リストの参照がある、
		*			同じリストであることを確認する。
		* @param	list: 同じリストであるかの判断用リストへのポインタ
		* @return	全条件足した場合trueを返す、ほかの場合falseを返す
		********************************************************/
		bool IsVaild(const DoubleLinkedList* const list);

	public:
		/*********************************************************
		* @brief	コンストラクタ　
		********************************************************/
		ConstIterator() :
			m_pNode(nullptr),
			m_pList(nullptr) {};

		/*********************************************************
		* @brief	リストの先頭に向かって一つ進める（前置デクリメント）
		* @details	リストの参照がない場合失敗になる。
		*			リストが空である場合失敗になる。
		*			直前ノードは先頭ノードの場合失敗になる。
		* @return	演算された後のイテレータを返す
		********************************************************/
		ConstIterator& operator--();

		/*********************************************************
		* @brief	リストの末尾に向かって一つ進める（前置インクリメント）
		* @details	リストの参照がない場合失敗になる。
		*			ノードはダミーの場合失敗になる。
		* @return	演算された後のイテレータを返す
		********************************************************/
		ConstIterator& operator++();

		/*********************************************************
		* @brief	リストの末尾に向かって一つ進める（後置デクリメント）
		* @details	リストの参照がない場合失敗になる。
		*			リストが空である場合失敗になる。
		*			ノードは先頭ノードの場合失敗になる。
		* @return	演算された後のイテレータを返す
		********************************************************/
		ConstIterator operator--(int i);

		/*********************************************************
		* @brief	リストの末尾に向かって一つ進める（後置インクリメント）
		* @details	リストの参照がない場合失敗になる。
		*			直後ノードはダミーの場合失敗になる。
		* @return	演算された後のイテレータを返す
		********************************************************/
		ConstIterator operator++(int i);

		/*********************************************************
		* @brief	コピーを行う（コピーコンストラクタ）
		* @details	宣言時、引数、戻り値の3つの動作でコピーがとられた時に実行される。
		********************************************************/
		ConstIterator(const ConstIterator& constIter);

		/*********************************************************
		* @brief	代入を行う
		* @return	代入を行ったのイテレータを返す
		********************************************************/
		ConstIterator& operator=(const ConstIterator& constIter);


		//constメソッド

		/*********************************************************
		* @brief	イテレータの指す要素を取得する(const版)
		* @details	リストの参照がない場合失敗になる。
		* 			ノードはダミーの場合失敗になる。
		* @return	指した要素を返す
		********************************************************/
		const DataType& operator*()const;

		/*********************************************************
		* @brief	同一か比較する
		* @return	同一の場合trueを返す、異なる場合falseを返す
		********************************************************/
		bool operator==(const ConstIterator& constIter)const;

		/*********************************************************
		* @brief	異なるか比較する
		* @return	異なる場合trueを返す、同一の場合falseを返す
		********************************************************/
		bool operator!=(const ConstIterator& constIter)const;

		//DoubleLinkedListの関数内で、有効イテレータ確認するため
		friend DoubleLinkedList;
	};

	/*********************************************************
	* @brief	イテレータ
	********************************************************/
	class Iterator :public ConstIterator
	{
	private:
		using ConstIterator::m_pNode;
		using ConstIterator::m_pList;
	public:
		/*********************************************************
		* @brief	イテレータの指す要素を取得する(非const版)
		* @details	リストの参照がない場合失敗になる。
		* 			ノードはダミーの場合失敗になる。
		* @return	指した要素を返す
		********************************************************/
		DataType& operator*();

		friend DoubleLinkedList;
	};

private:
	/*********************************************************
	* @brief	ダミーノードへのポインタ　先頭と末尾の判断用
	* @details	dummy.pPrevは最後の要素を指す、dummy.pNextは先頭要素を指す
	********************************************************/
	Node m_Dummy;

	/*********************************************************
	* @brief	要素数
	* @details	挿入、削除のときカウントする
	********************************************************/
	int m_Count;

private:
	/*********************************************************
	* @brief	クイックソート
	* @details	先頭の要素を標準値にするクイックソート
	* @link		参考: https://ja.wikipedia.org/wiki/%E3%82%AF%E3%82%A4%E3%83%83%E3%82%AF%E3%82%BD%E3%83%BC%E3%83%88
	* @param	head: 先頭の要素を指すイテレータ
	* @param	tail: 最後の要素を指すイテレータ
	* @param	greater: 要素の比較ルール
	********************************************************/
	template <typename Comparator>
	void QuickSort(Iterator head, Iterator tail, Comparator& greater);

	/*********************************************************
	* @brief		二つのデータを交換する
	* @details		イテレータが指した要素のノードを位置交換
	* @param[out]	l: 左要素を指すイテレータ
	* @param[out]	r: 右要素を指すイテレータ
	********************************************************/
	void Swap(Iterator& l, Iterator& r);

public:
	/*********************************************************
	* @brief	デストラクタ
	* @details	動的作成したノードを全部解放
	********************************************************/
	virtual ~DoubleLinkedList();

	/*********************************************************
	* @brief	コンストラクタ
	* @details	ダミーノードを作成
	********************************************************/
	DoubleLinkedList();

	/*********************************************************
	* @brief	データの挿入
	* @details	イテレータが有効であるかを確認、
	*			有効ではないかを確認。
	* @param	position: 挿入位置を指すイテレータ
	* @tparam	data: 挿入したいデータ
	* @return	挿入成功の場合trueを返す
	*			挿入失敗の場合falseを返す
	********************************************************/
	bool Insert(ConstIterator& position, const DataType& data);

	/*********************************************************
	* @brief	データの削除
	* @details	リストが空ではないかの確認、
	*			空ではない場合イテレータが有効であるかの確認、
	*			有効の場合ダミーではないかの確認。
	* @param	position: 削除ノードを指すイテレータ
	* @return	削除成功の場合trueを返す
	*			削除失敗の場合falseを返す
	********************************************************/
	bool Remove(ConstIterator& position);

	/*********************************************************
	* @brief	ソート
	* @details	ソートの種類はクイックソート、
	*			関数の引数にて、ソートの条件を変更できる。
	*			返り値がbool型のラムダ式、又はファンクタを入れてください。 
	* 			メソッドの引数がデータの型で、leftとrightを二つ用意し、
	*			trueが返されると要素の交換を行う：
	*			・left>rightがtrueの場合交換を行い、左から右へ大きくなる昇順で整列できる
	*			・left<rightがtrueの場合交換を行い、左から右へ小さくなる降順で整列できる。
	* @tparam	compare: ソートに使うキー
	********************************************************/
	template <typename Comparator>
	void Sort(Comparator compare);

	/*********************************************************
	* @brief	先頭イテレータ取得する
	* @details	リストが空である場合、ダミーノードを指すイテレータを返す、
	*			空ではない場合、先頭ノードを指すイテレータを返す。
	* @return	先頭イテレータを返す
	********************************************************/
	Iterator Begin();

	/*********************************************************
	* @brief	末尾イテレータ取得する
	* @details	ダミーノードを指すイテレータを返す。
	* @return	末尾イテレータを返す
	********************************************************/
	Iterator End();


	//constメソッド

	/*********************************************************
	* @brief	データ数を取得する
	* @return	データ数を返す
	********************************************************/
	int Count()const;

	/*********************************************************
	* @brief	先頭コンストイテレータ取得する
	* @details	リストが空である場合、ダミーノードを指すコンストイテレータを返す
	*			空ではない場合、先頭ノードを指すコンストイテレータを返す。
	* @return	先頭コンストイテレータを返す
	********************************************************/
	ConstIterator CBegin()const;

	/*********************************************************
	* @brief	末尾イテレータ取得する
	* @details	ダミーノードを指すコンストイテレータを返す。
	* @return	末尾コンストイテレータを返す
	********************************************************/
	ConstIterator CEnd()const;
};

#include "DoubleLinkedList.inl"