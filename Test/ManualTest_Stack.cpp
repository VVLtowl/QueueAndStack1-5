/*********************************************************
* @brief		�X�^�b�N�̃e�X�g(�蓮�e�X�g)
* @date			2022/10/19
********************************************************/
#include "gtest/gtest.h"
#include "../QueueAndStack/Stack.h"
#include "ManualTest_Stack.h"

//�X�^�b�N�̎蓮�e�X�g���s
#define GT_MANUAL_TEST_STACK

namespace ex01_Stack
{
#ifdef  GT_MANUAL_TEST_STACK

#pragma region ========== Stack ==========

	/*********************************************************
	* @brief		const�̃��\�b�h�ł��邩
	* @details		ID:0-7
	*				const�̃��X�g����Ăяo���āA
	*				�R���p�C���G���[�ƂȂ�Ȃ������`�F�b�N�B�����e�X�g�����Ȃ��Ă悢�B
	********************************************************/
	TEST(StackCountTest, IsConst)
	{
#ifdef MANUAL_TEST_STACK_COUNT_IS_CONST
		const Stack<int> stack;
		stack.Count();
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
#ifdef MANUAL_TEST_STACK_PUSH_NOT_CONST
		const Stack<int> stack;
		stack.Push(0);
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
#ifdef MANUAL_TEST_STACK_POP_NOT_CONST
		const Stack<int> stack;
		stack.Pop();
#endif
		SUCCEED();
	}

#pragma endregion



#endif //  GT_MANUAL_TEST_SORT
}





