/*********************************************************
* @brief		スタックのテスト(手動テスト)
* @date			2022/10/19
********************************************************/
#include "gtest/gtest.h"
#include "../QueueAndStack/Stack.h"
#include "../QueueAndStack/ScoreData.h"
#include "ManualTest_Stack.h"

//クイックソートの手動テスト実行
#define GT_MANUAL_TEST_STACK

namespace ex01_Stack
{
#ifdef  GT_MANUAL_TEST_STACK

#pragma region ========== Stack ==========

#ifdef MANUAL_TEST_STACK_COUNT_IS_CONST
	/*********************************************************
	* @brief		constのメソッドであるか
	* @details		ID:0-7
	*				constのリストから呼び出して、
	*				コンパイルエラーとならないかをチェック。自動テスト化しなくてよい。
	********************************************************/
	TEST(StackCountTest, IsConst)
	{
		const Stack<int> stack;
		stack.Count();
	}
#endif

#ifdef MANUAL_TEST_STACK_PUSH_NOT_CONST
	/*********************************************************
	* @brief		非constのメソッドであるか
	* @details		ID:0-10
	*				constのリストから呼び出して、
	*				コンパイルエラーとなるかをチェック。自動テスト化しなくてよい。
	********************************************************/
	TEST(StackPushTest, NotConst)
	{
		const Stack<int> stack;
		stack.Push(0);
	}
#endif

#ifdef MANUAL_TEST_STACK_POP_NOT_CONST
	/*********************************************************
	* @brief		非constのメソッドであるか
	* @details		ID:0-14
	*				constのリストから呼び出して、
	*				コンパイルエラーとなるかをチェック。自動テスト化しなくてよい。
	********************************************************/
	TEST(StackPopTest, NotConst)
	{
		const Stack<int> stack;
		stack.Pop();
	}
#endif

#pragma endregion



#endif //  GT_MANUAL_TEST_SORT
}





