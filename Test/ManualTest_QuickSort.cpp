/*********************************************************
* @brief		�N�C�b�N�\�[�g�̃e�X�g(�蓮�e�X�g)
* @date			2022/10/19
********************************************************/
#include "gtest/gtest.h"
#include "../QueueAndStack/DoubleLinkedList.h"
#include "../QueueAndStack/ScoreData.h"
#include "ManualTest_QuickSort.h"

//�N�C�b�N�\�[�g�̎蓮�e�X�g���s
#define GT_MANUAL_TEST_SORT

namespace ex03_ListSort
{
#ifdef  GT_MANUAL_TEST_SORT
#pragma region ========== �N�C�b�N�\�[�g ==========


	/*********************************************************
	* @brief		�^�Ȃǂ��s�K�؂ȃL�[�w�肪�����œn���ꂽ���̋���
	* @details		ID:0-7
	*				�^�Ȃǂ��s�K�؂ȃL�[�w�肪�����œn���ꂽ���A
	*				�R���p�C���G���[���`�F�b�N�B�����e�X�g�����Ȃ��B
	********************************************************/
	TEST(QuickSortTest, WithoutComparator)
	{

#ifdef MANUAL_TEST_SORT_WITH_WRONG_COMPARATOR
		DoubleLinkedList<ScoreData> list;

		//�L�[�w������Ȃ��āA�\�[�g���s��
		list.Sort([]() {return true; });
#endif
		SUCCEED();
	}

	/*********************************************************
	* @brief		��const�̃��\�b�h�ł��邩
	* @details		ID:0-8
	*				��const�̃��\�b�h�ł��邩���m�F�B
	*				const�̃��X�g����Ăяo���āA�R���p�C���G���[�ƂȂ邩���`�F�b�N�B�����e�X�g�����Ȃ��Ă悢�B
	********************************************************/
	TEST(QuickSortTest, NotConst)
	{
#ifdef MANUAL_TEST_SORT_NOT_CONST
		const DoubleLinkedList<ScoreData> list;
		list.Sort([]() {return true; });
#endif
		SUCCEED();
	}


#pragma endregion



#endif //  GT_MANUAL_TEST_SORT
}





