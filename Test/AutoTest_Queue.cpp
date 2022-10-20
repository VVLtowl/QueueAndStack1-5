/*********************************************************
* @brief		�L���[�̒P�̃e�X�g
* @date			2022/10/19
********************************************************/
#include "gtest/gtest.h"
#include "../QueueAndStack/Queue.h"
#include "../QueueAndStack/ScoreData.h"
#include "TestTool.h"


//�L���[�̒P�̃e�X�g���s
#define GT_AUTO_TEST_QUEUE

namespace ex01_Queue
{
#if defined GT_AUTO_TEST_QUEUE

#pragma region ========== �f�[�^���̎擾 ==========

	/*********************************************************
	* @brief		���X�g����ł���ꍇ�̖߂�l
	* @details		ID:1-0
	* 				���X�g����ł���ꍇ�̖߂�l��0�ł��邩���`�F�b�N�B
	********************************************************/
	TEST(QueueCountTest, WhenEmptyList)
	{
		Queue<int> queue;
		EXPECT_EQ(0, queue.Count());
	}

	/*********************************************************
	* @brief		�v�f���v�b�V��������̖߂�l
	* @details		ID:1-1
	* 				�v�f���v�b�V��������̖߂�l��1�ł��邩���`�F�b�N�B
	********************************************************/
	TEST(QueueCountTest, WhenPushSucceed)
	{
		Queue<int> queue;
		queue.Push(1);
		EXPECT_EQ(1, queue.Count());
	}

	/*********************************************************
	* @brief		�v�f���|�b�v������̖߂�l
	* @details		ID:1-2
	* 				�v�f���|�b�v������̖߂�l��0�ł��邩���`�F�b�N�B
	********************************************************/
	TEST(QueueCountTest, WhenPopSucceed)
	{
		Queue<int> queue;
		queue.Push(1);
		queue.Pop();
		EXPECT_EQ(0, queue.Count());
	}

	/*********************************************************
	* @brief		�v�f�̃v�b�V���Ɏ��s������̖߂�l
	* @details		ID:1-3
	* 				�v�f�̃v�b�V���Ɏ��s������̖߂�l��0�ł��邩���`�F�b�N�B
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
	* @brief		�v�b�V����2��s������̖߂�l
	* @details		ID:1-4
	* 				�v�b�V����2��s������̖߂�l��2�ł��邩���`�F�b�N�B
	********************************************************/
	TEST(QueueCountTest, TwoPush)
	{
		Queue<int> queue;
		EXPECT_TRUE(queue.Push(0));
		EXPECT_TRUE(queue.Push(1));
		EXPECT_EQ(2, queue.Count());
	}

	/*********************************************************
	* @brief		�v�b�V����2��s������A�P��|�b�v������̖߂�l
	* @details		ID:1-5
	* 				�v�b�V����2��s������A�P��|�b�v������̖߂�l��1�ł��邩���`�F�b�N�B
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
	* @brief		���X�g����ł���ꍇ�ɁA�|�b�v���s������̖߂�l
	* @details		ID:1-6
	* 				���X�g����ł���ꍇ�ɁA�|�b�v���s������̖߂�l��0�ł��邩���`�F�b�N�B
	********************************************************/
	TEST(QueueCountTest, WhenEmptyList_Pop)
	{
		Queue<int> queue;
		EXPECT_FALSE(queue.Pop());
		EXPECT_EQ(0, queue.Count());
	}
#pragma endregion

#pragma region ========== �v�b�V�� ==========

	/*********************************************************
	* @brief		���X�g����ł���ꍇ�ɁA�v�b�V�������ۂ̋���
	* @details		ID:1-8
	* 				���X�g����ł���ꍇ�ɁA�v�b�V�������ہA
	*				���X�g�̖����ɗv�f���ǉ�����邩���m�F�B
	*				�߂�l��true�ł��邩���`�F�b�N�B
	********************************************************/
	TEST(QueuePushTest, WhenEmptyList)
	{
		Queue<int> queue;
		EXPECT_TRUE(queue.Push(1));
		EXPECT_TRUE(queue.Push(2));

		//�����v�f�����o���āA�v�b�V�������v�f�Ɣ�r
		int tail;
		queue.Pop();//pop 1
		queue.Pop(&tail);//pop 2
		EXPECT_EQ(2, tail);
	}

	/*********************************************************
	* @brief		���X�g�ɕ����̗v�f������ꍇ�ɁA�v�b�V�������ۂ̋���
	* @details		ID:1-9
	* 				���X�g�ɕ����̗v�f������ꍇ�ɁA�v�b�V�������ہA
	*				���X�g�̖����ɗv�f���ǉ�����邩���m�F�B
	*				�߂�l��true�ł��邩���`�F�b�N�B
	********************************************************/
	TEST(QueuePushTest, WhenManyElements)
	{
		Queue<int> queue;
		queue.Push(1);
		queue.Push(2);

		EXPECT_TRUE(queue.Push(3));

		//�����v�f�����o���āA�v�b�V�������v�f�Ɣ�r
		int tail;
		queue.Pop();//pop 1
		queue.Pop();//pop 2
		queue.Pop(&tail);//pop 3
		EXPECT_EQ(3, tail);
	}

#pragma endregion

#pragma region ========== �|�b�v ==========

	/*********************************************************
	* @brief		���X�g����ł���ꍇ�ɁA�|�b�v�����ۂ̋���
	* @details		ID:1-11
	* 				���X�g����ł���ꍇ�ɁA�|�b�v�����ہA
	*				�����N����Ȃ������m�F�B
	*				�߂�l��false�ł��邩���`�F�b�N�B
	********************************************************/
	TEST(QueuePopTest, WhenEmptyList)
	{
		Queue<int> queue;

		EXPECT_EQ(0, queue.Count());
		EXPECT_FALSE(queue.Pop());
		EXPECT_EQ(0, queue.Count());
	}

	/*********************************************************
	* @brief		���X�g�ɕ����̗v�f������ꍇ�ɁA�|�b�v�����ۂ̋���
	* @details		ID:1-12
	* 				���X�g�ɕ����̗v�f������ꍇ�ɁA�|�b�v�����ہA
	*				�擪�v�f�������o�R�œn����A���̗v�f�����X�g����폜����邩���m�F�B
	*				�߂�l��true�ł��邩���`�F�b�N�B
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
	* @brief		���X�g�ɕ����̗v�f������ꍇ�ɁA������|�b�v�����ۂ̋���
	* @details		ID:1-13
	* 				�ŏ��ɒǉ������v�f���珇�Ɉ����o�R�œn����邩���m�F�B
	*				�߂�l��true�ł��邩���`�F�b�N�B
	********************************************************/
	TEST(QueuePopTest, PopOrder)
	{
		Queue<ScoreData> queue;
		queue.Push({ 0,"A" });
		queue.Push({ 1,"B" });
		queue.Push({ 2,"C" });
		queue.Push({ 3,"D" });

		//pop�Ŏ��o�����v�f�����Ԃ�list�ɓ����
		//list����āApop�ŏo�����v�f�̏��Ԃ��m�F
		DoubleLinkedList<ScoreData> list;
		while (queue.Count() > 0)
		{
			ScoreData popData;
			EXPECT_TRUE(queue.Pop(&popData));

			//list���ł́A��ŏo�����v�f�𖖔��֒ǉ�
			auto end = list.End();
			list.Insert(end, popData);
		}
		//���҂���鏇�ԁi�ŏ��ɒǉ������v�f���珇�j
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