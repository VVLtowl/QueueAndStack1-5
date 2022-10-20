/*********************************************************
* @brief		�X�^�b�N�̃e�X�g(�蓮�e�X�g)
* @date			2022/10/19
********************************************************/
#include "gtest/gtest.h"
#include "../QueueAndStack/Stack.h"
#include "../QueueAndStack/ScoreData.h"
#include "ManualTest_Stack.h"

//�N�C�b�N�\�[�g�̎蓮�e�X�g���s
#define GT_MANUAL_TEST_STACK

namespace ex01_Stack
{
#ifdef  GT_MANUAL_TEST_STACK

#pragma region ========== Stack ==========

#ifdef MANUAL_TEST_STACK_COUNT_IS_CONST
	/*********************************************************
	* @brief		const�̃��\�b�h�ł��邩
	* @details		ID:0-7
	*				const�̃��X�g����Ăяo���āA
	*				�R���p�C���G���[�ƂȂ�Ȃ������`�F�b�N�B�����e�X�g�����Ȃ��Ă悢�B
	********************************************************/
	TEST(StackCountTest, IsConst)
	{
		const Stack<int> stack;
		stack.Count();
	}
#endif

#ifdef MANUAL_TEST_STACK_PUSH_NOT_CONST
	/*********************************************************
	* @brief		��const�̃��\�b�h�ł��邩
	* @details		ID:0-10
	*				const�̃��X�g����Ăяo���āA
	*				�R���p�C���G���[�ƂȂ邩���`�F�b�N�B�����e�X�g�����Ȃ��Ă悢�B
	********************************************************/
	TEST(StackPushTest, NotConst)
	{
		const Stack<int> stack;
		stack.Push(0);
	}
#endif

#ifdef MANUAL_TEST_STACK_POP_NOT_CONST
	/*********************************************************
	* @brief		��const�̃��\�b�h�ł��邩
	* @details		ID:0-14
	*				const�̃��X�g����Ăяo���āA
	*				�R���p�C���G���[�ƂȂ邩���`�F�b�N�B�����e�X�g�����Ȃ��Ă悢�B
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





