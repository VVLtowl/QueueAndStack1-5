/*********************************************************
* @brief		�C�e���[�^�P�̃e�X�g(�蓮�e�X�g)
* @date			2022/10/14
********************************************************/
#include "gtest/gtest.h"
#include "../QueueAndStack/DoubleLinkedList.h"
#include "ManualTest_ConstIterator.h"

//�o�������X�g�̎蓮�e�X�g���s
#define GT_MANUAL_TEST_ITERATOR

namespace ex02_ConstIterator
{
#ifdef GT_MANUAL_TEST_ITERATOR



	/*********************************************************
	* @brief		ConstIterator����擾�����v�f�ɑ΂��āA�l�̑�����s���Ȃ������`�F�b�N
	* @details		ID:1-2
	*				ConstIterator����擾�����v�f�ɑ΂��āA
	*				�l�̑�����s���Ȃ������`�F�b�N���܂��B
	*				�R���p�C���G���[�ɂȂ邱�Ƃ��`�F�b�N���܂��B(�蓮�e�X�g)
	********************************************************/
	TEST(IteratorGetDataTest, WhenEmptyList_GetFromBegin)
	{
#ifdef MANUAL_TEST_ITERATOR_CANT_ASSIGN_CONSTITERATOR
		DoubleLinkedList<int> list;

		//Iterator����擾�����v�f�ɒl����
		auto iter = list.Begin();
		(*iter) = 10;

		//ConstIterator����擾�����v�f�ɒl����
		auto constIter = list.CBegin();
		(*constIter) = 10;
#else
		SUCCEED();
#endif // GT_MANUAL_TEST_ITERATOR
	}

	/*********************************************************
	* @brief		ConstIterator����AIterator�̃R�s�[���쐬����Ȃ������`�F�b�N
	* @details		ID:1-17
	* 				ConstIterator����AIterator�̃R�s�[���쐬����Ȃ������`�F�b�N���܂��B
	*				�R���p�C���G���[�ɂȂ邱�Ƃ��m�F���܂��B(�蓮�e�X�g)
	********************************************************/
	TEST(IteratorCopyTest, ConstIteratorCopyIterator)
	{
#ifdef MANUAL_TEST_ITERATOR_CONSTITERATOR_CANT_COPY_ITERATOR
		DoubleLinkedList<int>::Iterator iter;
		DoubleLinkedList<int>::ConstIterator constIter;
		DoubleLinkedList<int>::ConstIterator constIter1(iter);//Iterator����AConstIterator�̃R�s�[���쐬
		DoubleLinkedList<int>::Iterator iter1(constIter);//ConstIterator����AIterator�̃R�s�[���쐬
#else
		SUCCEED();
#endif //
	}

	/*********************************************************
	* @brief		Iterator��ConstIterator�����ł��Ȃ������`�F�b�N
	* @details		ID:1-19
	* 				Iterator��ConstIterator�����ł��Ȃ������`�F�b�N���܂��B
	*				�R���p�C���G���[�ɂȂ邱�Ƃ��m�F���܂��B(�蓮�e�X�g)
	********************************************************/
	TEST(IteratorAssignTest, AssginConstIteratorToIterator)
	{
#ifdef MANUAL_TEST_ITERATOR_CANT_ASSIGN_CONSTITERATOR_TO_ITERATOR
		DoubleLinkedList<int>::ConstIterator constIter;
		DoubleLinkedList<int>::Iterator iter;
		constIter = iter;//ConstIterator��Iterator����
		iter = constIter;//Iterator��ConstIterator����
#else
		SUCCEED();
#endif
	}


#endif // GT_MANUAL_TEST_ITERATOR

}