/*********************************************************
* @brief		�L���[�̃e�X�g(�蓮�e�X�g)
* @date			2022/10/19
********************************************************/
#include "gtest/gtest.h"
#include "../QueueAndStack/Queue.h"
#include "ManualTest_Queue.h"

//�L���[�̎蓮�e�X�g���s
#define GT_MANUAL_TEST_QUEUE

namespace ex01_Queue
{
#ifdef  GT_MANUAL_TEST_QUEUE

#pragma region ========== Queue ==========

	/*********************************************************
	* @brief		const�̃��\�b�h�ł��邩
	* @details		ID:0-7
	*				const�̃��X�g����Ăяo���āA
	*				�R���p�C���G���[�ƂȂ�Ȃ������`�F�b�N�B�����e�X�g�����Ȃ��Ă悢�B
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
	* @brief		��const�̃��\�b�h�ł��邩
	* @details		ID:0-10
	*				const�̃��X�g����Ăяo���āA
	*				�R���p�C���G���[�ƂȂ邩���`�F�b�N�B�����e�X�g�����Ȃ��Ă悢�B
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
	* @brief		��const�̃��\�b�h�ł��邩
	* @details		ID:0-14
	*				const�̃��X�g����Ăяo���āA
	*				�R���p�C���G���[�ƂȂ邩���`�F�b�N�B�����e�X�g�����Ȃ��Ă悢�B
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





