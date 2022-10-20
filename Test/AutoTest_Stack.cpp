/*********************************************************
* @brief		�X�^�b�N�̒P�̃e�X�g
* @date			2022/10/19
********************************************************/
#include "gtest/gtest.h"
#include "../QueueAndStack/Stack.h"
#include "../QueueAndStack/ScoreData.h"
#include "TestTool.h"


//�X�^�b�N�̒P�̃e�X�g���s
#define GT_AUTO_TEST_STACK

namespace ex01_Stack
{
#if defined GT_AUTO_TEST_STACK

#pragma region ========== �f�[�^���̎擾 ==========

	using StackCountTest_F = StackFixture;

	/*********************************************************
	* @brief		���X�g����ł���ꍇ�̖߂�l
	* @details		ID:0-0
	* 				���X�g����ł���ꍇ�̖߂�l��0�ł��邩���`�F�b�N�B
	********************************************************/
	TEST(StackCountTest, WhenEmptyList)
	{
		Stack<ScoreData> stack;
		EXPECT_EQ(0, stack.Count());
	}

	/*********************************************************
	* @brief		�v�f���v�b�V��������̖߂�l
	* @details		ID:0-1
	* 				�v�f���v�b�V��������̖߂�l��1�ł��邩���`�F�b�N�B
	********************************************************/
	TEST(StackCountTest, WhenPushSucceed)
	{
		Stack<ScoreData> stack;
		stack.Push({ 0,"A" });
		EXPECT_EQ(1, stack.Count());
	}

	/*********************************************************
	* @brief		�v�f���|�b�v������̖߂�l
	* @details		ID:0-2
	* 				�v�f���|�b�v������̖߂�l��0�ł��邩���`�F�b�N�B
	********************************************************/
	TEST(StackCountTest, WhenPopSucceed)
	{
		Stack<ScoreData> stack;
		stack.Push({ 0,"A" });
		stack.Pop();
		EXPECT_EQ(0, stack.Count());
	}

	/*********************************************************
	* @brief		�v�f�̃v�b�V���Ɏ��s������̖߂�l
	* @details		ID:0-3
	* 				�v�f�̃v�b�V���Ɏ��s������̖߂�l��0�ł��邩���`�F�b�N�B
	********************************************************/
	TEST(StackCountTest, WhenPushFailed)
	{
		//TODO
	}
#pragma endregion

#pragma region ========== �v�b�V�� ==========

	using StackPushTest_F = StackFixture;

	/*********************************************************
	* @brief		���X�g����ł���ꍇ�ɁA�v�b�V�������ۂ̋���
	* @details		ID:0-8
	* 				���X�g����ł���ꍇ�ɁA�v�b�V�������ہA
	*				���X�g�̖����ɗv�f���ǉ�����邩���m�F�B
	*				�߂�l��true�ł��邩���`�F�b�N�B
	********************************************************/
	TEST(StackPushTest, WhenEmptyList)
	{
		Stack<ScoreData> stack;
		EXPECT_TRUE(stack.Push({ 0,"A" }));

		//�����v�f�����o���āA�v�b�V�������v�f�Ɣ�r
		ScoreData tail;
		stack.Pop(&tail);
		EXPECT_EQ("A", tail.name);
		EXPECT_EQ(0, tail.score);
	}

	/*********************************************************
	* @brief		���X�g�ɕ����̗v�f������ꍇ�ɁA�v�b�V�������ۂ̋���
	* @details		ID:0-9
	* 				���X�g�ɕ����̗v�f������ꍇ�ɁA�v�b�V�������ہA
	*				���X�g�̖����ɗv�f���ǉ�����邩���m�F�B
	*				�߂�l��true�ł��邩���`�F�b�N�B
	********************************************************/
	TEST(StackPushTest, WhenManyElements)
	{
		Stack<ScoreData> stack;
		ScoreData datas[] = {
			{0,"A"},
			{1,"B"},
			{2,"C"},
			{3,"D"},
		};
		InputDatasToStack(datas, 4, stack);

		EXPECT_TRUE(stack.Push({ 4,"E" }));

		//�����v�f�����o���āA�v�b�V�������v�f�Ɣ�r
		ScoreData tail;
		stack.Pop(&tail);
		EXPECT_EQ("E", tail.name);
		EXPECT_EQ(4, tail.score);
	}

#pragma endregion

#pragma region ========== �|�b�v ==========

	using StackPopTest_F = StackFixture;

	/*********************************************************
	* @brief		���X�g����ł���ꍇ�ɁA�|�b�v�����ۂ̋���
	* @details		ID:0-11
	* 				���X�g����ł���ꍇ�ɁA�|�b�v�����ہA
	*				�����N����Ȃ������m�F�B
	*				�߂�l��false�ł��邩���`�F�b�N�B
	********************************************************/
	TEST(StackPopTest, WhenEmptyList)
	{
		Stack<ScoreData> stack;

		EXPECT_EQ(0, stack.Count());
		EXPECT_FALSE(stack.Pop());
		EXPECT_EQ(0, stack.Count());
	}

	/*********************************************************
	* @brief		���X�g�ɕ����̗v�f������ꍇ�ɁA�|�b�v�����ۂ̋���
	* @details		ID:0-12
	* 				���X�g�ɕ����̗v�f������ꍇ�ɁA�|�b�v�����ہA
	*				�����v�f�������o�R�œn����A���̗v�f�����X�g����폜����邩���m�F�B
	*				�߂�l��true�ł��邩���`�F�b�N�B
	********************************************************/
	TEST(StackPopTest, WhenManyElements)
	{
		Stack<ScoreData> stack;
		ScoreData datas[] = {
			{0,"A"},
			{1,"B"},
			{2,"C"},
			{3,"D"},//tail
		};
		InputDatasToStack(datas, 4, stack);
		
		EXPECT_EQ(4, stack.Count());

		ScoreData popData;
		EXPECT_TRUE(stack.Pop(&popData));
		EXPECT_EQ(3, popData.score);
		EXPECT_EQ("D", popData.name);

		EXPECT_EQ(3, stack.Count());
	}

	/*********************************************************
	* @brief		���X�g�ɕ����̗v�f������ꍇ�ɁA������|�b�v�����ۂ̋���
	* @details		ID:0-13
	* 				�Ō�ɒǉ������v�f���珇�Ɉ����o�R�œn����邩���m�F�B
	*				�߂�l��true�ł��邩���`�F�b�N�B
	********************************************************/
	TEST(StackPopTest, PopOrder)
	{
		Stack<ScoreData> stack;
		ScoreData datas[] = {
			{0,"A"},
			{1,"B"},
			{2,"C"},
			{3,"D"},
		};
		InputDatasToStack(datas, 4, stack);

		//pop�Ŏ��o�����v�f�����Ԃ�list�ɓ����
		//list����āApop�ŏo�����v�f�̏��Ԃ��m�F
		DoubleLinkedList<ScoreData> list;
		while (stack.Count() > 0)
		{
			ScoreData popData;
			EXPECT_TRUE(stack.Pop(&popData));
			
			//list���ł́A��ŏo�����v�f�𖖔��֒ǉ�
			auto end = list.End();
			list.Insert(end, popData);
		}
		//���҂���鏇��
		ScoreData datas2[] = {
			{3,"D"},
			{2,"C"},
			{1,"B"},
			{0,"A"},
		};
		CheckListValueAndCount(datas2,4,list);
	}
#pragma endregion

#endif
}