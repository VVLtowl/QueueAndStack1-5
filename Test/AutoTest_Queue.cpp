/*********************************************************
* @brief		キューの単体テスト
* @date			2022/10/19
********************************************************/
#include "gtest/gtest.h"
#include "../QueueAndStack/Queue.h"
#include "../QueueAndStack/ScoreData.h"
#include "TestTool.h"


//キューの単体テスト実行
#define GT_AUTO_TEST_QUEUE

namespace ex01_Queue
{
#if defined GT_AUTO_TEST_QUEUE

#pragma region ========== データ数の取得 ==========

	/*********************************************************
	* @brief		リストが空である場合の戻り値
	* @details		ID:1-0
	* 				リストが空である場合の戻り値は0であるかをチェック。
	********************************************************/
	TEST(QueueCountTest, WhenEmptyList)
	{
		Queue<int> queue;
		EXPECT_EQ(0, queue.Count());
	}

	/*********************************************************
	* @brief		要素をプッシュした後の戻り値
	* @details		ID:1-1
	* 				要素をプッシュした後の戻り値は1であるかをチェック。
	********************************************************/
	TEST(QueueCountTest, WhenPushSucceed)
	{
		Queue<int> queue;
		queue.Push(1);
		EXPECT_EQ(1, queue.Count());
	}

	/*********************************************************
	* @brief		要素をポップした後の戻り値
	* @details		ID:1-2
	* 				要素をポップした後の戻り値は0であるかをチェック。
	********************************************************/
	TEST(QueueCountTest, WhenPopSucceed)
	{
		Queue<int> queue;
		queue.Push(1);
		queue.Pop();
		EXPECT_EQ(0, queue.Count());
	}

	/*********************************************************
	* @brief		要素のプッシュに失敗した後の戻り値
	* @details		ID:1-3
	* 				要素のプッシュに失敗した後の戻り値は0であるかをチェック。
	********************************************************/
	TEST(QueueCountTest, WhenPushFailed)
	{
#if 1
		Queue<int> queue;
		int* data = nullptr;
		
		//test
		//std::cout << data << ":" << &data <<std::endl;
		
		EXPECT_FALSE(queue.Push(*data));
		EXPECT_EQ(0, queue.Count());
#else
		SUCCEED();
#endif
	}

	/*********************************************************
	* @brief		プッシュを2回行った後の戻り値
	* @details		ID:1-4
	* 				プッシュを2回行った後の戻り値は2であるかをチェック。
	********************************************************/
	TEST(QueueCountTest, TwoPush)
	{
		Queue<int> queue;
		EXPECT_TRUE(queue.Push(0));
		EXPECT_TRUE(queue.Push(1));
		EXPECT_EQ(2, queue.Count());
	}

	/*********************************************************
	* @brief		プッシュを2回行った後、１回ポップした後の戻り値
	* @details		ID:1-5
	* 				プッシュを2回行った後、１回ポップした後の戻り値は1であるかをチェック。
	********************************************************/
	TEST(QueueCountTest, TwoPushAndOnePop)
	{
		Queue<int> queue;
		EXPECT_TRUE(queue.Push(0));
		EXPECT_TRUE(queue.Push(1));
		EXPECT_TRUE(queue.Pop());
		EXPECT_EQ(1, queue.Count());
	}

	/*********************************************************
	* @brief		リストが空である場合に、ポップを行った後の戻り値
	* @details		ID:1-6
	* 				リストが空である場合に、ポップを行った後の戻り値は0であるかをチェック。
	********************************************************/
	TEST(QueueCountTest, WhenEmptyList_Pop)
	{
		Queue<int> queue;
		EXPECT_FALSE(queue.Pop());
		EXPECT_EQ(0, queue.Count());
	}
#pragma endregion

#pragma region ========== プッシュ ==========

	/*********************************************************
	* @brief		リストが空である場合に、プッシュした際の挙動
	* @details		ID:1-8
	* 				リストが空である場合に、プッシュした際、
	*				リストの末尾に要素が追加されるかを確認。
	*				戻り値はtrueであるかをチェック。
	********************************************************/
	TEST(QueuePushTest, WhenEmptyList)
	{
		Queue<int> queue;
		EXPECT_TRUE(queue.Push(1));
		EXPECT_TRUE(queue.Push(2));

		//末尾要素を取り出して、プッシュした要素と比較
		int tail;
		queue.Pop();//pop 1
		queue.Pop(&tail);//pop 2
		EXPECT_EQ(2, tail);
	}

	/*********************************************************
	* @brief		リストに複数の要素がある場合に、プッシュした際の挙動
	* @details		ID:1-9
	* 				リストに複数の要素がある場合に、プッシュした際、
	*				リストの末尾に要素が追加されるかを確認。
	*				戻り値はtrueであるかをチェック。
	********************************************************/
	TEST(QueuePushTest, WhenManyElements)
	{
		Queue<int> queue;
		queue.Push(1);
		queue.Push(2);

		EXPECT_TRUE(queue.Push(3));

		//末尾要素を取り出して、プッシュした要素と比較
		int tail;
		queue.Pop();//pop 1
		queue.Pop();//pop 2
		queue.Pop(&tail);//pop 3
		EXPECT_EQ(3, tail);
	}

#pragma endregion

#pragma region ========== ポップ ==========

	/*********************************************************
	* @brief		リストが空である場合に、ポップした際の挙動
	* @details		ID:1-11
	* 				リストが空である場合に、ポップした際、
	*				何も起こらないかを確認。
	*				戻り値はfalseであるかをチェック。
	********************************************************/
	TEST(QueuePopTest, WhenEmptyList)
	{
		Queue<int> queue;

		EXPECT_EQ(0, queue.Count());
		EXPECT_FALSE(queue.Pop());
		EXPECT_EQ(0, queue.Count());
	}

	/*********************************************************
	* @brief		リストに複数の要素がある場合に、ポップした際の挙動
	* @details		ID:1-12
	* 				リストに複数の要素がある場合に、ポップした際、
	*				先頭要素が引数経由で渡され、その要素がリストから削除されるかを確認。
	*				戻り値はtrueであるかをチェック。
	********************************************************/
	TEST(QueuePopTest, WhenManyElements)
	{
		Queue<int> queue;
		queue.Push(0);//head
		queue.Push(1);
		queue.Push(2);
		queue.Push(3);

		EXPECT_EQ(4, queue.Count());

		int popData;
		EXPECT_TRUE(queue.Pop(&popData));
		EXPECT_EQ(0, popData);

		EXPECT_EQ(3, queue.Count());
	}

	/*********************************************************
	* @brief		リストに複数の要素がある場合に、複数回ポップした際の挙動
	* @details		ID:1-13
	* 				最初に追加した要素から順に引数経由で渡されるかを確認。
	*				戻り値はtrueであるかをチェック。
	********************************************************/
	TEST(QueuePopTest, PopOrder)
	{
		Queue<ScoreData> queue;
		queue.Push({ 0,"A" });
		queue.Push({ 1,"B" });
		queue.Push({ 2,"C" });
		queue.Push({ 3,"D" });

		//popで取り出した要素を順番にlistに入れる
		//listを介して、popで出した要素の順番を確認
		DoubleLinkedList<ScoreData> list;
		while (queue.Count() > 0)
		{
			ScoreData popData;
			EXPECT_TRUE(queue.Pop(&popData));

			//list内では、後で出した要素を末尾へ追加
			auto end = list.End();
			list.Insert(end, popData);
		}
		//期待される順番（最初に追加した要素から順）
		ScoreData datas[] = {
			{0,"A"},
			{1,"B"},
			{2,"C"},
			{3,"D"},
		};
		CheckListValueAndCount(datas, 4, list);
	}
#pragma endregion

#endif
}