/*********************************************************
* @brief		キューのテスト(手動テスト)
* @date			2022/10/19
********************************************************/
#include "gtest/gtest.h"
#include "../QueueAndStack/Queue.h"
#include "ManualTest_Queue.h"

//キューの手動テスト実行
#define GT_MANUAL_TEST_QUEUE

namespace ex01_Queue
{
#ifdef  GT_MANUAL_TEST_QUEUE

#pragma region ========== Queue ==========

	/*********************************************************
	* @brief		constのメソッドであるか
	* @details		ID:0-7
	*				constのリストから呼び出して、
	*				コンパイルエラーとならないかをチェック。自動テスト化しなくてよい。
	********************************************************/
	TEST(StackCountTest, IsConst)
	{
#ifdef MANUAL_TEST_QUEUE_COUNT_IS_CONST
		const Queue<int> queue;
		queue.Count();
#endif
		SUCCEED();
	}

	/*********************************************************
	* @brief		非constのメソッドであるか
	* @details		ID:0-10
	*				constのリストから呼び出して、
	*				コンパイルエラーとなるかをチェック。自動テスト化しなくてよい。
	********************************************************/
	TEST(StackPushTest, NotConst)
	{
#ifdef MANUAL_TEST_QUEUE_PUSH_NOT_CONST
		const Queue<int> queue;
		queue.Push(0);
#endif
		SUCCEED();
	}

	/*********************************************************
	* @brief		非constのメソッドであるか
	* @details		ID:0-14
	*				constのリストから呼び出して、
	*				コンパイルエラーとなるかをチェック。自動テスト化しなくてよい。
	********************************************************/
	TEST(StackPopTest, NotConst)
	{
#ifdef MANUAL_TEST_QUEUE_POP_NOT_CONST
		const Queue<int> queue;
		queue.Pop();
#endif
		SUCCEED();
	}

#pragma endregion



#endif 
}





