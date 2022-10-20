/*********************************************************
* @brief		�C�e���[�^�P�̃e�X�g�̃e�X�g
* @date			2022/10/11
********************************************************/
#include "gtest/gtest.h"
#include "../QueueAndStack/DoubleLinkedList.h"
#include "../QueueAndStack/ScoreData.h"
#include "TestTool.h"

//�C�e���[�^�̒P�̃e�X�g
#define GT_AUTO_TEST_ITERATOR

namespace ex02_ConstIterator
{
#if defined GT_AUTO_TEST_ITERATOR

#pragma region ========== �C�e���[�^�̎w���v�f���擾 ==========

	using IteratorGetDataTest_F = ListFixture;

	/*********************************************************
	* @brief		���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋���
	* @details		ID:1-0
	* 				���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂɁA
	*				assert�������邩���m�F���܂��B
	********************************************************/
	TEST(IteratorGetDataTest, WhenNoReference)
	{
#ifdef _DEBUG
		//Iterator
		{
			DoubleLinkedList<ScoreData>::Iterator iter;//���X�g�̎Q�Ƃ��Ȃ��C�e���[�^���쐬
			EXPECT_DEATH((*iter), "iterator: no reference");
		}

		//ConstIterator
		{
			DoubleLinkedList<ScoreData>::ConstIterator constIter;//���X�g�̎Q�Ƃ��Ȃ��C�e���[�^���쐬
			EXPECT_DEATH((*constIter), "constIterator: no reference");
		}
#else
		SUCCEED();
#endif
	}

	/*********************************************************
	* @brief		Iterator����擾�����v�f�ɑ΂��āA�l�̑�����s���邩���`�F�b�N
	* @details		ID:1-1
	*				Iterator����擾�����v�f�ɑ΂��āA
	*				�l�̑�����s���邩���`�F�b�N���܂��B
	********************************************************/
	TEST_F(IteratorGetDataTest_F, AfterAssignData)
	{
		InputOneData();

		//�����l���擾
		int initScore = (*headIter).score;
		std::string initName = (*headIter).name;

		//�ύX�O�͏����l�Ɠ���
		EXPECT_EQ(10, (*headIter).score);
		EXPECT_EQ("head", (*headIter).name);

		//Iterator����擾�����v�f�ɑ΂��āA�l����
		auto iter = list.Begin();
		(*iter).score = initScore + 10;
		(*iter).name = initName + "Change";

		//�ύX��͏����l�ƈقȂ�
		EXPECT_NE(10, (*headIter).score);
		EXPECT_NE("head", (*headIter).name);
		EXPECT_EQ(20, (*headIter).score);
		EXPECT_EQ("headChange", (*headIter).name);

		//���҂����l�����X�g�ɓ����������m�F
		ScoreData datas[] =
		{
			{20,"headChange"},
		};
		CheckListValueAndCount(datas, 1, list);
	}



	/*********************************************************
	* @brief		���X�g����̍ۂ́A�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
	* @details		ID:1-3
	*				���X�g����̍ۂ́A�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂɁA
	* 				assert�������邩���m�F���܂��B
	********************************************************/
	TEST(IteratorGetDataTest, ByConstIterator)
	{
#ifdef _DEBUG
		DoubleLinkedList<ScoreData> list;
		EXPECT_EQ(0, list.Count());//���X�g����ł��邩���`�F�b�N

		//Iterator
		{
			DoubleLinkedList<ScoreData>::Iterator iter = list.Begin();
			EXPECT_DEATH((*iter), "iterator: is dummy");
		}

		//ConstIterator
		{
			DoubleLinkedList<ScoreData>::ConstIterator constIter = list.CBegin();
			EXPECT_DEATH((*constIter), "constIterator: is dummy");
		}
#else
		SUCCEED();
#endif // _DEBUG
	}

	/*********************************************************
	* @brief		�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
	* @details		ID:1-4
	*				�����C�e���[�^�ɑ΂��ČĂяo�����ۂɁA
	* 				assert�������邩���m�F���܂��B
	********************************************************/
	TEST(IteratorGetDataTest, GetFromEnd)
	{
#ifdef _DEBUG
		DoubleLinkedList<ScoreData> list;

		//Iterator
		{
			DoubleLinkedList<ScoreData>::Iterator iter = list.End();
			EXPECT_DEATH((*iter), "iterator: is dummy");
		}

		//ConstIterator
		{
			DoubleLinkedList<ScoreData>::ConstIterator constIter = list.CEnd();
			EXPECT_DEATH((*constIter), "constIterator: is dummy");
		}
#else
		SUCCEED();
#endif // _DEBUG
	}
#pragma endregion

#pragma region ========== �C�e���[�^�����X�g�̖����Ɍ������Ĉ�i�߂� ==========

	using IteratorIncrementTest_F = ListFixture;

	/*********************************************************
	* @brief		���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋���
	* @details		ID:1-5
	* 				���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂɁA
	*				assert�������邩���m�F���܂��B
	********************************************************/
	TEST(IteratorIncrementTest, WhenNoReference)
	{
#ifdef _DEBUG

		//Iterator
		{
			DoubleLinkedList<ScoreData>::Iterator iter;
			EXPECT_DEATH((++iter), "pre increment: no reference");
		}

		//ConstIterator
		{
			DoubleLinkedList<ScoreData>::ConstIterator constIter;
			EXPECT_DEATH((++constIter), "pre increment: no reference");
		}

#else
		SUCCEED();
#endif // _DEBUG
	}

	/*********************************************************
	* @brief		���X�g����̍ۂ́A�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
	* @details		ID:1-6
	* 				���X�g����̍ۂ́A�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂɁA
	*				assert�������邩���m�F���܂��B
	********************************************************/
	TEST(IteratorIncrementTest, WhenEmptyList_IncrementBegin)
	{
#ifdef _DEBUG
		DoubleLinkedList<ScoreData> list;//�󃊃X�g���쐬

		//Iterator
		{
			auto iter = list.Begin();
			EXPECT_DEATH((++iter), "pre increment: dummy cant increment");
		}

		//ConstIterator
		{
			auto constIter = list.CBegin();
			EXPECT_DEATH((++constIter), "pre increment: dummy cant increment");
		}
#else
		SUCCEED();
#endif // DEBUG
	}

	/*********************************************************
	* @brief		�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
	* @details		ID:1-7
	* 				�����C�e���[�^�ɑ΂��ČĂяo�����ۂɁA
	*				assert�������邩���m�F���܂��B
	********************************************************/
	TEST(IteratorIncrementTest, IncrementEnd)
	{
#ifdef _DEBUG
		DoubleLinkedList<ScoreData> list;

		//Iterator
		{
			auto iter = list.End();
			EXPECT_DEATH((++iter), "pre increment: dummy cant increment");
		}

		//ConstIterator
		{
			auto constIter = list.CEnd();
			EXPECT_DEATH((++constIter), "pre increment: dummy cant increment");
		}
#else
		SUCCEED();
#endif // DEBUG
	}

	/*********************************************************
	* @brief		���X�g�ɓ�ȏ�̗v�f������ꍇ�ɌĂяo�����ۂ̋���
	* @details		ID:1-8
	* 				���X�g�ɓ�ȏ�̗v�f������ꍇ�ɌĂяo�����ۂɁA
	*				���̗v�f���w���̂����m�F���܂��B
	********************************************************/
	TEST_F(IteratorIncrementTest_F, WhenManyElements)
	{
		//Iterator
		{
			//��ȏ�̗v�f�����郊�X�g���쐬
			InputThreeData();//list: {10,"head"} {11,"middle"} {12,"tail"}

			//���X�g�̐擪���疖���܂ŌĂяo�����s���A
			//���҂���Ă���v�f���i�[����Ă��邩���m�F
			auto iter = list.Begin();
			EXPECT_EQ(10, (*iter).score);
			EXPECT_EQ("head", (*iter).name);
			++iter;
			EXPECT_EQ(11, (*iter).score);
			EXPECT_EQ("middle", (*iter).name);
			++iter;
			EXPECT_EQ(12, (*iter).score);
			EXPECT_EQ("tail", (*iter).name);
		}

		//ConstIterator
		{
			//��ȏ�̗v�f�����郊�X�g���쐬
			InputThreeData();//list: {10,"head"} {11,"middle"} {12,"tail"}

			//���X�g�̐擪���疖���܂ŌĂяo�����s���A
			//���҂���Ă���v�f���i�[����Ă��邩���m�F
			auto iter = list.CBegin();
			EXPECT_EQ(10, (*iter).score);
			EXPECT_EQ("head", (*iter).name);
			++iter;
			EXPECT_EQ(11, (*iter).score);
			EXPECT_EQ("middle", (*iter).name);
			++iter;
			EXPECT_EQ(12, (*iter).score);
			EXPECT_EQ("tail", (*iter).name);
		}
	}

	/*********************************************************
	* @brief		�O�u�C���N�������g���s�����ۂ̋���
	* @details		ID:1-9
	* 				�O�u�C���N�������g���s�����ۂɁA
	*				���̗v�f���w���̂����m�F���܂��B
	********************************************************/
	TEST_F(IteratorIncrementTest_F, PreIncrement)
	{
		//��ȏ�̗v�f�����郊�X�g���쐬
		InputThreeData();//list: {10,"head"} {11,"middle"} {12,"tail"}

		//Iterator
		{
			auto iter = list.Begin();

			//�w���Ă���v�f��head�A����middle�̂͂�
			EXPECT_EQ(10, (*iter).score);
			EXPECT_EQ("head", (*iter).name);

			//�O�u�C���N�������g�̌�
			EXPECT_EQ(11, (*(++iter)).score);
			EXPECT_EQ("tail", (*++iter).name);
		}

		//ConstIterator
		{
			auto iter = list.CBegin();

			//�w���Ă���v�f��head�A����middle�̂͂�
			EXPECT_EQ(10, (*iter).score);
			EXPECT_EQ("head", (*iter).name);

			//�O�u�C���N�������g�̌�
			EXPECT_EQ(11, (*(++iter)).score);
			EXPECT_EQ("tail", (*++iter).name);
		}
	}

	/*********************************************************
	* @brief		��u�C���N�������g���s�����ۂ̋���
	* @details		ID:1-10
	* 				��u�C���N�������g���s�����ۂɁA
	*				���̗v�f���w���̂����m�F���܂��B
	********************************************************/
	TEST_F(IteratorIncrementTest_F, PostIncrement)
	{
		//��ȏ�̗v�f�����郊�X�g���쐬
		InputThreeData();//list: {10,"head"} {11,"middle"} {12,"tail"}

		//Iterator
		{
			auto iter = list.Begin();

			//�w���Ă���v�f��head�A����middle�̂͂�
			EXPECT_EQ(10, (*iter).score);
			EXPECT_EQ("head", (*iter).name);

			//��u�C���N�������g�̌�
			EXPECT_EQ(10, (*(iter++)).score);
			EXPECT_EQ("middle", (*(iter++)).name);
		}

		//ConstIterator
		{
			auto iter = list.CBegin();

			//�w���Ă���v�f��head�A����middle�̂͂�
			EXPECT_EQ(10, (*iter).score);
			EXPECT_EQ("head", (*iter).name);

			//��u�C���N�������g�̌�
			EXPECT_EQ(10, (*(iter++)).score);
			EXPECT_EQ("middle", (*(iter++)).name);
		}
	}
#pragma endregion

#pragma region ========== �C�e���[�^�����X�g�̐擪�Ɍ������Ĉ�i�߂� ==========

	using IteratorDecrementTest_F = ListFixture;

	/*********************************************************
	* @brief		���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋���
	* @details		ID:1-11
	* 				���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂɁA
	*				assert�������邩���m�F���܂��B
	********************************************************/
	TEST(IteratorDecrementTest, WhenNoReference)
	{
#ifdef _DEBUG
		//Iterator
		{
			DoubleLinkedList<ScoreData>::Iterator iter;
			EXPECT_DEATH((--iter), "pre decrement: no reference");
		}

		//ConstIterator
		{
			DoubleLinkedList<ScoreData>::ConstIterator iter;
			EXPECT_DEATH((--iter), "pre decrement: no reference");
		}
#else
		SUCCEED();
#endif // DEBUG
	}

	/*********************************************************
	* @brief		���X�g����̍ۂ́A�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
	* @details		ID:1-12
	* 				���X�g����̍ۂ́A�����C�e���[�^�ɑ΂��ČĂяo�����ۂɁA
	*				assert�������邩���m�F���܂��B
	********************************************************/
	TEST(IteratorDecrementTest, WhenEmptyList_DecrementEnd)
	{
#ifdef _DEBUG
		DoubleLinkedList<ScoreData> list;//��ł��郊�X�g���쐬

		//Iterator
		{
			auto iter = list.End();
			EXPECT_DEATH((--iter), "pre decrement: list is empty");
		}

		//ConstIterator
		{
			auto iter = list.CEnd();
			EXPECT_DEATH((--iter), "pre decrement: list is empty");
		}
#else
		SUCCEED();
#endif // DEBUG
	}

	/*********************************************************
	* @brief		�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
	* @details		ID:1-13
	* 				�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂɁA
	*				assert�������邩���m�F���܂��B
	********************************************************/
	TEST_F(IteratorDecrementTest_F, DecrementBegin)
	{
#ifdef _DEBUG
		//�v�f�̂��郊�X�g���쐬
		InputOneData();

		//Iterator
		{
			//�_�~�[�ł͂Ȃ��擪�C�e���[�^���擾
			auto iter = list.Begin();

			EXPECT_DEATH((--iter), "pre decrement: begin cant decrement");
		}

		//ConstIterator
		{
			//�_�~�[�ł͂Ȃ��擪�C�e���[�^���擾
			auto iter = list.CBegin();

			EXPECT_DEATH((--iter), "pre decrement: begin cant decrement");
		}

#else
		SUCCEED();
#endif // DEBUG
	}

	/*********************************************************
	* @brief		���X�g�ɓ�ȏ�̗v�f������ꍇ�ɌĂяo�����ۂ̋���
	* @details		ID:1-14
	* 				���X�g�ɓ�ȏ�̗v�f������ꍇ�ɌĂяo�����ۂɁA
	*				�O�̗v�f���w���̂����m�F���܂��B
	********************************************************/
	TEST_F(IteratorDecrementTest_F, WhenManyElements)
	{
		//Iterator
		{
			//��ȏ�̗v�f�����郊�X�g���쐬
			InputThreeData();//list: {10,"head"} {11,"middle"} {12,"tail"}

			//���X�g�̖�������擪�܂ŌĂяo�����s���A
			//���҂���Ă���v�f���i�[����Ă��邩���m�F
			auto iter = list.End();
			--iter;//�Ō�̗v�f����
			EXPECT_EQ(12, (*iter).score);
			EXPECT_EQ("tail", (*iter).name);
			--iter;
			EXPECT_EQ(11, (*iter).score);
			EXPECT_EQ("middle", (*iter).name);
			--iter;
			EXPECT_EQ(10, (*iter).score);
			EXPECT_EQ("head", (*iter).name);
		}

		//ConstIterator
		{
			//��ȏ�̗v�f�����郊�X�g���쐬
			InputThreeData();//list: {10,"head"} {11,"middle"} {12,"tail"}

			//���X�g�̖�������擪�܂ŌĂяo�����s���A
			//���҂���Ă���v�f���i�[����Ă��邩���m�F
			auto iter = list.CEnd();
			--iter;//�Ō�̗v�f����
			EXPECT_EQ(12, (*iter).score);
			EXPECT_EQ("tail", (*iter).name);
			--iter;
			EXPECT_EQ(11, (*iter).score);
			EXPECT_EQ("middle", (*iter).name);
			--iter;
			EXPECT_EQ(10, (*iter).score);
			EXPECT_EQ("head", (*iter).name);
		}
	}

	/*********************************************************
	* @brief		�O�u�f�N�������g���s�����ۂ̋���
	* @details		ID:1-15
	* 				�O�u�f�N�������g���s�����ۂɁA
	*				�O�̗v�f���w���̂����m�F���܂��B
	********************************************************/
	TEST_F(IteratorDecrementTest_F, PreDecrement)
	{
		//Iterator
		{
			//��ȏ�̗v�f�����郊�X�g���쐬
			InputThreeData();//list: {10,"head"} {11,"middle"} {12,"tail"}
			auto iter = list.End();
			--iter;//�Ō�̗v�f����

			//�w���Ă���v�f��tail�A�O��middle�̂͂�
			EXPECT_EQ(12, (*iter).score);
			EXPECT_EQ("tail", (*iter).name);

			//�O�u�f�N�������g�̌�
			EXPECT_EQ(11, (*(--iter)).score);
			EXPECT_EQ("head", (*(--iter)).name);
		}

		//ConstIterator
		{
			//��ȏ�̗v�f�����郊�X�g���쐬
			InputThreeData();//list: {10,"head"} {11,"middle"} {12,"tail"}
			auto iter = list.CEnd();
			--iter;//�Ō�̗v�f����

			//�w���Ă���v�f��tail�A�O��middle�̂͂�
			EXPECT_EQ(12, (*iter).score);
			EXPECT_EQ("tail", (*iter).name);

			//�O�u�f�N�������g�̌�
			EXPECT_EQ(11, (*(--iter)).score);
			EXPECT_EQ("head", (*(--iter)).name);
		}
	}

	/*********************************************************
	* @brief		��u�f�N�������g���s�����ۂ̋���
	* @details		ID:1-15
	* 				��u�f�N�������g���s�����ۂɁA
	*				�O�̗v�f���w���̂����m�F���܂��B
	********************************************************/
	TEST_F(IteratorDecrementTest_F, PostDecrement)
	{
		//Iterator
		{
			//��ȏ�̗v�f�����郊�X�g���쐬
			InputThreeData();//list: {10,"head"} {11,"middle"} {12,"tail"}
			auto iter = list.End();
			iter--;//�Ō�̗v�f����

			//�w���Ă���v�f��tail�A�O��middle�̂͂�
			EXPECT_EQ(12, (*iter).score);
			EXPECT_EQ("tail", (*iter).name);

			//��u�f�N�������g�̌�
			EXPECT_EQ(12, (*(iter--)).score);
			EXPECT_EQ("middle", (*(iter--)).name);
		}

		//ConstIterator
		{
			//��ȏ�̗v�f�����郊�X�g���쐬
			InputThreeData();//list: {10,"head"} {11,"middle"} {12,"tail"}
			auto iter = list.CEnd();
			iter--;//�Ō�̗v�f����

			//�w���Ă���v�f��tail�A�O��middle�̂͂�
			EXPECT_EQ(12, (*iter).score);
			EXPECT_EQ("tail", (*iter).name);

			//��u�f�N�������g�̌�
			EXPECT_EQ(12, (*(iter--)).score);
			EXPECT_EQ("middle", (*(iter--)).name);
		}
	}
#pragma endregion

#pragma region ========== �C�e���[�^�̃R�s�[���s�� ==========

	using IteratorCopyTest_F = ListFixture;

	/*********************************************************
	* @brief		�R�s�[�R���X�g���N�g��̒l���R�s�[���Ɠ��������Ƃ��`�F�b�N
	* @details		ID:1-18
	* 				�R�s�[�R���X�g���N�g��̒l���R�s�[���Ɠ��������Ƃ��`�F�b�N���܂��B
	********************************************************/
	TEST_F(IteratorCopyTest_F, AfterCopy_CheckDataEqual)
	{
		InputOneData();//list: {10,"head"}

		//Iterator
		{
			//�R�s�[�R���X�g���N�g
			auto iter(list.Begin());

			//�R�s�[�ƃR�s�[���̒l���r
			EXPECT_EQ(
				(*list.Begin()).score,
				(*iter).score);
			EXPECT_EQ(
				(*list.Begin()).name,
				(*iter).name);
		}

		//ConstIterator
		{
			//�R�s�[�R���X�g���N�g
			auto iter(list.CBegin());

			//�R�s�[�ƃR�s�[���̒l���r
			EXPECT_EQ(
				(*list.CBegin()).score,
				(*iter).score);
			EXPECT_EQ(
				(*list.CBegin()).name,
				(*iter).name);
		}
	}
#pragma endregion

#pragma region ========== �C�e���[�^�̑�����s���e�X�g ==========

	using IteratorAssignTest_F = ListFixture;

	/*********************************************************
	* @brief		�����̒l���R�s�[���Ɠ��������Ƃ��`�F�b�N
	* @details		ID:1-20
	* 				�����̒l���R�s�[���Ɠ��������Ƃ��`�F�b�N���܂��B
	********************************************************/
	TEST_F(IteratorAssignTest_F, AfterAssign_CheckDataEqual)
	{
		InputOneData();//list: {10,"head"}

		//Iterator
		{
			//���
			DoubleLinkedList<ScoreData>::Iterator iter;
			iter = list.Begin();

			//�����̒l�ƃR�s�[���̒l���r
			EXPECT_EQ(
				(*list.Begin()).score,
				(*iter).score);
			EXPECT_EQ(
				(*list.Begin()).name,
				(*iter).name);
		}

		//ConstIterator
		{
			//���
			DoubleLinkedList<ScoreData>::ConstIterator iter;
			iter = list.CBegin();

			//�����̒l�ƃR�s�[���̒l���r
			EXPECT_EQ(
				(*list.CBegin()).score,
				(*iter).score);
			EXPECT_EQ(
				(*list.CBegin()).name,
				(*iter).name);
		}
	}
#pragma endregion

#pragma region ========== ������̂̃C�e���[�^�ł��邩�̔�r ==========

	using IteratorEqualTest_F = ListFixture;

	/*********************************************************
	* @brief		���X�g����̏�Ԃł̐擪�C�e���[�^�Ɩ����C�e���[�^���r�����ۂ̋������`�F�b�N
	* @details		ID:1-21
	* 				���X�g����̏�Ԃł̐擪�C�e���[�^�Ɩ����C�e���[�^���r�����ۂɁA
	*				true���Ԃ�ꍇ�����ł��B
	********************************************************/
	TEST(IteratorEqualTest, WhenEmptyList_CheckBeginAndEnd)
	{
		DoubleLinkedList<ScoreData> list;

		//Iterator
		{
			//���X�g����̏�ԂŁA�擪���������_�~�[�ł���
			auto begin = list.Begin();
			auto end = list.End();

			EXPECT_TRUE(begin == end);
		}

		//ConstIterator
		{
			//���X�g����̏�ԂŁA�擪���������_�~�[�ł���
			auto begin = list.CBegin();
			auto end = list.CEnd();

			EXPECT_TRUE(begin == end);
		}
	}

	/*********************************************************
	* @brief		����̃C�e���[�^���r�����ۂ̋���
	* @details		ID:1-22
	* 				����̃C�e���[�^���r�����ۂɁA
	*				true���Ԃ�ꍇ�����ł��B
	********************************************************/
	TEST_F(IteratorEqualTest_F, WhenEmptyList_CheckSame)
	{
		InputOneData();

		//Iterator
		{
			//�����v�f���w����̃C�e���[�^���쐬
			auto iter1 = list.Begin();
			auto iter2 = list.Begin();

			EXPECT_TRUE(iter1 == iter2);
		}

		//ConstIterator
		{
			//�����v�f���w����̃C�e���[�^���쐬
			auto iter1 = list.CBegin();
			auto iter2 = list.CBegin();

			EXPECT_TRUE(iter1 == iter2);
		}
	}

	/*********************************************************
	* @brief		�قȂ�C�e���[�^���r�����ۂ̋���
	* @details		ID:1-23
	* 				�قȂ�C�e���[�^���r�����ۂɁA
	*				false���Ԃ�ꍇ�����ł��B
	********************************************************/
	TEST_F(IteratorEqualTest_F, WhenEmptyList_CheckDifferent)
	{
		InputTwoData();

		//Iterator
		{
			//�قȂ�v�f���w����̃C�e���[�^���쐬
			auto iter1 = headIter;
			auto iter2 = middleIter;

			EXPECT_FALSE(iter1 == iter2);
		}

		//ConstIterator
		{
			//�قȂ�v�f���w����̃C�e���[�^���쐬
			auto iter1 = list.CBegin();
			auto iter2 = list.CEnd();

			EXPECT_FALSE(iter1 == iter2);
		}
	}
#pragma endregion

#pragma region ========== �قȂ�C�e���[�^�ł��邩�̔�r ==========

	using IteratorNotEqualTest_F = ListFixture;

	/*********************************************************
	* @brief		���X�g����̏�Ԃł̐擪�C�e���[�^�Ɩ����C�e���[�^���r�����ۂ̋������`�F�b�N
	* @details		ID:1-24
	* 				���X�g����̏�Ԃł̐擪�C�e���[�^�Ɩ����C�e���[�^���r�����ۂɁA
	*				true���Ԃ�ꍇ�����ł��B
	********************************************************/
	TEST(IteratorNotEqualTest, WhenEmptyList_CheckBeginAndEnd)
	{
		DoubleLinkedList<ScoreData> list;

		//Iterator
		{
			//���X�g����̏�ԂŁA�擪���������_�~�[�ł���
			auto begin = list.Begin();
			auto end = list.End();

			EXPECT_FALSE(begin != end);
		}

		//ConstIterator
		{
			//���X�g����̏�ԂŁA�擪���������_�~�[�ł���
			auto begin = list.CBegin();
			auto end = list.CEnd();

			EXPECT_FALSE(begin != end);
		}
	}

	/*********************************************************
	* @brief		����̃C�e���[�^���r�����ۂ̋���
	* @details		ID:1-25
	* 				����̃C�e���[�^���r�����ۂɁA
	*				true���Ԃ�ꍇ�����ł��B
	********************************************************/
	TEST_F(IteratorNotEqualTest_F, WhenEmptyList_CheckSame)
	{
		InputOneData();

		//Iterator
		{
			//�����v�f���w����̃C�e���[�^���쐬
			auto iter1 = headIter;
			auto iter2 = headIter;

			EXPECT_FALSE(iter1 != iter2);
		}

		//ConstIterator
		{
			//�����v�f���w����̃C�e���[�^���쐬
			auto iter1 = list.CBegin();
			auto iter2 = list.CBegin();

			EXPECT_FALSE(iter1 != iter2);
		}
	}

	/*********************************************************
	* @brief		�قȂ�C�e���[�^���r�����ۂ̋���
	* @details		ID:1-26
	* 				�قȂ�C�e���[�^���r�����ۂɁA
	*				false���Ԃ�ꍇ�����ł��B
	********************************************************/
	TEST_F(IteratorNotEqualTest_F, WhenEmptyList_CheckDifferent)
	{
		InputTwoData();

		//Iterator
		{
			//�قȂ�v�f���w����̃C�e���[�^���쐬
			auto iter1 = headIter;
			auto iter2 = middleIter;

			EXPECT_TRUE(iter1 != iter2);
		}

		//ConstIterator
		{
			//�قȂ�v�f���w����̃C�e���[�^���쐬
			auto iter1 = list.CBegin();
			auto iter2 = list.CEnd();

			EXPECT_TRUE(iter1 != iter2);
		}
	}
#pragma endregion

#endif
}