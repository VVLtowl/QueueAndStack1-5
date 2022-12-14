/*********************************************************
* @brief		スタックの単体テスト
* @date			2022/10/19
********************************************************/
#include "gtest/gtest.h"
#include "../QueueAndStack/Stack.h"
#include "../QueueAndStack/ScoreData.h"
#include "TestTool.h"


//スタックの単体テスト実行
#define GT_AUTO_TEST_STACK

namespace ex01_Stack
{
#if defined GT_AUTO_TEST_STACK

#pragma region ========== データ数の取得 ==========

	using StackCountTest_F = StackFixture;

	/*********************************************************
	* @brief		リストが空である場合の戻り値
	* @details		ID:0-0
	* 				リストが空である場合の戻り値は0であるかをチェック。
	********************************************************/
	TEST(StackCountTest, WhenEmptyList)
	{
		Stack<int> stack;
		EXPECT_EQ(0, stack.Count());
	}

	/*********************************************************
	* @brief		要素をプッシュした後の戻り値
	* @details		ID:0-1
	* 				要素をプッシュした後の戻り値は1であるかをチェック。
	********************************************************/
	TEST(StackCountTest, WhenPushSucceed)
	{
		Stack<int> stack;
		stack.Push(1);
		EXPECT_EQ(1, stack.Count());
	}

	/*********************************************************
	* @brief		要素をポップした後の戻り値
	* @details		ID:0-2
	* 				要素をポップした後の戻り値は0であるかをチェック。
	********************************************************/
	TEST(StackCountTest, WhenPopSucceed)
	{
		Stack<int> stack;
		stack.Push(1);
		stack.Pop();
		EXPECT_EQ(0, stack.Count());
	}

	/*********************************************************
	* @brief		要素のプッシュに失敗した後の戻り値
	* @details		ID:0-3
	* 				要素のプッシュに失敗した後の戻り値は0であるかをチェック。
	********************************************************/
	TEST(StackCountTest, WhenPushFailed)
	{
#if 1
		Stack<int> stack;
		int* data = nullptr;
		EXPECT_FALSE(stack.Push(*data));
		EXPECT_EQ(0, stack.Count());
#else
		SUCCEED();
#endif
	}

	/*********************************************************
	* @brief		プッシュを2回行った後の戻り値
	* @details		ID:0-4
	* 				プッシュを2回行った後の戻り値は2であるかをチェック。
	********************************************************/
	TEST(StackCountTest, TwoPush)
	{
		Stack<int> stack;
		EXPECT_TRUE(stack.Push(0));
		EXPECT_TRUE(stack.Push(1));
		EXPECT_EQ(2, stack.Count());
	}

	/*********************************************************
	* @brief		プッシュを2回行った後、１回ポップした後の戻り値
	* @details		ID:0-5
	* 				プッシュを2回行った後、１回ポップした後の戻り値は1であるかをチェック。
	********************************************************/
	TEST(StackCountTest, TwoPushAndOnePop)
	{
		Stack<int> stack;
		EXPECT_TRUE(stack.Push(0));
		EXPECT_TRUE(stack.Push(1));
		EXPECT_TRUE(stack.Pop());
		EXPECT_EQ(1, stack.Count());
	}

	/*********************************************************
	* @brief		リストが空である場合に、ポップを行った後の戻り値
	* @details		ID:0-6
	* 				リストが空である場合に、ポップを行った後の戻り値は0であるかをチェック。
	********************************************************/
	TEST(StackCountTest, WhenEmptyList_Pop)
	{
		Stack<int> stack;
		EXPECT_FALSE(stack.Pop());
		EXPECT_EQ(0, stack.Count());
	}
#pragma endregion

#pragma region ========== プッシュ ==========

	using StackPushTest_F = StackFixture;

	/*********************************************************
	* @brief		リストが空である場合に、プッシュした際の挙動
	* @details		ID:0-8
	* 				リストが空である場合に、プッシュした際、
	*				リストの末尾に要素が追加されるかを確認。
	*				戻り値はtrueであるかをチェック。
	********************************************************/
	TEST(StackPushTest, WhenEmptyList)
	{
		Stack<int> stack;
		EXPECT_TRUE(stack.Push(5));

		//末尾要素を取り出して、プッシュした要素と比較
		int tail;
		stack.Pop(&tail);
		EXPECT_EQ(5, tail);
	}

	/*********************************************************
	* @brief		リストに複数の要素がある場合に、プッシュした際の挙動
	* @details		ID:0-9
	* 				リストに複数の要素がある場合に、プッシュした際、
	*				リストの末尾に要素が追加されるかを確認。
	*				戻り値はtrueであるかをチェック。
	********************************************************/
	TEST(StackPushTest, WhenManyElements)
	{
		Stack<int> stack;
		stack.Push(0);
		stack.Push(1);
		stack.Push(2);
		stack.Push(3);

		EXPECT_TRUE(stack.Push(4));

		//末尾要素を取り出して、プッシュした要素と比較
		int tail;
		stack.Pop(&tail);
		EXPECT_EQ(4, tail);
	}

#pragma endregion

#pragma region ========== ポップ ==========

	using StackPopTest_F = StackFixture;

	/*********************************************************
	* @brief		リストが空である場合に、ポップした際の挙動
	* @details		ID:0-11
	* 				リストが空である場合に、ポップした際、
	*				何も起こらないかを確認。
	*				戻り値はfalseであるかをチェック。
	********************************************************/
	TEST(StackPopTest, WhenEmptyList)
	{
		Stack<int> stack;

		EXPECT_EQ(0, stack.Count());
		EXPECT_FALSE(stack.Pop());
		EXPECT_EQ(0, stack.Count());
	}

	/*********************************************************
	* @brief		リストに複数の要素がある場合に、ポップした際の挙動
	* @details		ID:0-12
	* 				リストに複数の要素がある場合に、ポップした際、
	*				末尾要素が引数経由で渡され、その要素がリストから削除されるかを確認。
	*				戻り値はtrueであるかをチェック。
	********************************************************/
	TEST(StackPopTest, WhenManyElements)
	{
		Stack<int> stack;
		stack.Push(0);
		stack.Push(1);
		stack.Push(2);
		stack.Push(3);//tail

		EXPECT_EQ(4, stack.Count());

		int popData;
		EXPECT_TRUE(stack.Pop(&popData));
		EXPECT_EQ(3, popData);

		EXPECT_EQ(3, stack.Count());
	}

	/*********************************************************
	* @brief		リストに複数の要素がある場合に、複数回ポップした際の挙動
	* @details		ID:0-13
	* 				最後に追加した要素から順に引数経由で渡されるかを確認。
	*				戻り値はtrueであるかをチェック。
	********************************************************/
	TEST(StackPopTest, PopOrder)
	{
		Stack<ScoreData> stack;
		stack.Push({ 0,"A" });
		stack.Push({ 1,"B" });
		stack.Push({ 2,"C" });
		stack.Push({ 3,"D" });

		//popで取り出した要素を順番にlistに入れる
		//listを介して、popで出した要素の順番を確認
		DoubleLinkedList<ScoreData> list;
		while (stack.Count() > 0)
		{
			ScoreData popData;
			EXPECT_TRUE(stack.Pop(&popData));
			
			//list内では、後で出した要素を末尾へ追加
			auto end = list.End();
			list.Insert(end, popData);
		}
		//期待される順番（最後に追加した要素から順）
		ScoreData datas[] = {
			{3,"D"},
			{2,"C"},
			{1,"B"},
			{0,"A"},
		};
		CheckListValueAndCount(datas,4,list);
	}
#pragma endregion

#endif
}