/*********************************************************
* @brief		�e�X�g�⏕�̃N���X�Ɗ֐�
* @date			2022/10/12
********************************************************/
#pragma once

#include "gtest/gtest.h"
#include "../QueueAndStack/DoubleLinkedList.h"
#include "../QueueAndStack/Stack.h"
#include "../QueueAndStack/ScoreData.h"
#include <string>

#pragma region ========== List ==========

/*********************************************************
* @brief		�w��v�f���̃��X�g�̃t�B�N�X�`��
********************************************************/
class ListFixture : public ::testing::Test
{
protected:
	// @brief		�e�X�g�p���X�g
	DoubleLinkedList<ScoreData> list;

	// @brief		�擪�v�f���w���C�e���[�^
	DoubleLinkedList<ScoreData>::Iterator headIter;

	// @brief		���ԗv�f���w���C�e���[�^
	DoubleLinkedList<ScoreData>::Iterator middleIter;

	// @brief		�Ō�̗v�f���w���C�e���[�^
	DoubleLinkedList<ScoreData>::Iterator tailIter;

	// @brief		�����v�f���w���C�e���[�^
	DoubleLinkedList<ScoreData>::Iterator endIter;

protected:
	virtual void SetUp(void)
	{
		//list = new DoubleLinkedList();
	}

	virtual void TearDown(void)
	{
		//delete list;
	}

	/*********************************************************
	* @brief		�v�f��1���������
	********************************************************/
	void InputOneData()
	{
		ClearList();

		ScoreData data;
		DoubleLinkedList<ScoreData>::Iterator end;

		data.score = 10;
		data.name = "head";
		end = list.End();
		list.Insert(end, data);

		//�e�X�g�p�C�e���[�^�̏���
		headIter = list.Begin();
		middleIter = list.Begin(); ++middleIter;
		tailIter = list.End(); --tailIter;
		endIter = list.End();

		UpdateIterator();
	}

	/*********************************************************
	* @brief		�v�f��2�����
	********************************************************/
	void InputTwoData()
	{
		ClearList();

		ScoreData data;
		DoubleLinkedList<ScoreData>::Iterator end;

		data.score = 10;
		data.name = "head";
		end = list.End();
		list.Insert(end, data);

		data.score = 11;
		data.name = "tail";
		end = list.End();
		list.Insert(end, data);

		//�e�X�g�p�C�e���[�^�̏���
		headIter = list.Begin();
		middleIter = list.Begin(); ++middleIter;
		tailIter = list.End(); --tailIter;
		endIter = list.End();

		UpdateIterator();
	}

	/*********************************************************
	* @brief		�v�f��3�����
	********************************************************/
	void InputThreeData()
	{
		ClearList();

		ScoreData data;
		DoubleLinkedList<ScoreData>::Iterator end;

		data.score = 10;
		data.name = "head";
		end = list.End();
		list.Insert(end, data);

		data.score = 11;
		data.name = "middle";
		end = list.End();
		list.Insert(end, data);

		data.score = 12;
		data.name = "tail";
		end = list.End();
		list.Insert(end, data);

		UpdateIterator();
	}

	/*********************************************************
	* @brief		2�ȏ�A�w��v�f���œ����
	* @param		count: �v�f��[2,5]
	********************************************************/
	void InputDatas(int count)
	{
		ClearList();

		ScoreData data;
		DoubleLinkedList<ScoreData>::Iterator end;
		int dataNum = count;

		//�쐬���𐧌�
		if (dataNum < 2)dataNum = 2;
		if (dataNum > 5)dataNum = 5;

		//�擪���쐬���A���X�g�ɓ����
		data.score = 10;
		data.name = "head";
		end = list.End();
		list.Insert(end, data);

		//���Ԃ��쐬���A���X�g�ɓ����
		for (int i = 1; i < dataNum - 1; i++)
		{
			data.score = 10 + i;
			data.name = "middle" + std::to_string(i - 1);//���O�ŋ�ʂ�����
			end = list.End();
			list.Insert(end, data);
		}

		//�Ō�̗v�f���쐬���A���X�g�ɓ����
		data.score = 10 + dataNum - 1;
		data.name = "tail";
		end = list.End();
		list.Insert(end, data);

		UpdateIterator();
	}

	/*********************************************************
	* @brief		�e�X�g�p�̐擪�A���ԁA�Ō�̗v�f�A�����C�e���[�^�̏���
	********************************************************/
	void UpdateIterator()
	{
		//���X�g����ł���ꍇ�A�ݒu���Ȃ�
		if (list.Count() == 0)
			return;

		//�e�X�g�p�C�e���[�^�̏���
		headIter = list.Begin();
		middleIter = list.Begin(); ++middleIter;//���ԗv�f���擾
		tailIter = list.End(); --tailIter;//�Ō�̗v�f���擾
		endIter = list.End();
	}

	/*********************************************************
	* @brief		���X�g���󂭂���
	********************************************************/
	void ClearList()
	{
		//��̏ꍇ�I��
		if (list.Count() == 0)
		{
			return;
		}

		//��������S���폜
		auto iter = list.End();
		iter--;
		auto del = iter;
		while (del != list.Begin())
		{
			iter--;
			list.Remove(del);
			del = iter;
		}
		list.Remove(del);//�擪���폜
	}
};

/*********************************************************
* @brief		�v�f�͊��҂����l�ł��邩�̊m�F
* @details		���҂����l�̔z���n���ă��X�g���̗v�f����v���邩�ƁA
*				�v�f���������Ă邩�𔻒肷��B
* @param		datas: ���҂����l�̔z��
* @param		count: �l�̌�
* @param		list: ��r���郊�X�g
********************************************************/
inline void CheckListValueAndCount(const ScoreData* datas, const int count, const DoubleLinkedList<ScoreData>& list)
{
	auto iter = list.CBegin();
	EXPECT_EQ(count, list.Count());

	//���҂����l�ł͂Ȃ��ꍇfalse�ŏI��
	{
		for (int i = 0; i < count; i++, iter++)
		{
			EXPECT_EQ(datas[i].name, (*iter).name);
			EXPECT_EQ(datas[i].score, (*iter).score);
		}
	}
}

/*********************************************************
* @brief		�����C�e���[�^�ł��邩���m�F
* @details		��O�̗v�f�������v�f�ł��邱�Ƃ��m�F����
* @param		iter: ���f�������C�e���[�^
* @param		tail: �����v�f�̃f�[�^
********************************************************/
inline void CheckIsEndIterator(DoubleLinkedList<ScoreData>::ConstIterator iter, const ScoreData& tail)
{
	iter--;

	EXPECT_EQ(tail.name, (*iter).name);
	EXPECT_EQ(tail.score, (*iter).score);
}

/*********************************************************
* @brief		�w�肵���v�f������
* @param		datas: �w�肵���v�f
* @param		count: �v�f��[2,10]
* @param		list: �g�����X�g
********************************************************/
inline void InputDatasToList(ScoreData* datas, int count, DoubleLinkedList<ScoreData>& list)
{
	ScoreData data;
	DoubleLinkedList<ScoreData>::Iterator end;
	int dataNum = count;

	//�쐬���𐧌�
	if (dataNum < 2)dataNum = 2;
	if (dataNum > 10)dataNum = 10;

	for (int i = 0; i < dataNum; i++)
	{
		data.score = datas[i].score;
		data.name = datas[i].name;
		end = list.End();
		list.Insert(end, data);
	}
}

/*********************************************************
* @brief		���X�g��\��
* @param		list: ���X�g
********************************************************/
inline void PrintList(const DoubleLinkedList<ScoreData>& list)
{
	std::cout << "print list:" << std::endl;
	auto iter = list.CBegin();
	auto end = list.CEnd();
	for (; iter != end; iter++)
	{
		std::cout << (*iter).name << ":" << (*iter).score << std::endl;
	}
}

/*********************************************************
* @brief		�f�[�^�z�����בւ�
* @details		�}���\�[�g�Ńf�[�^�z�����בւ�
* @param		datas: �\�[�g���������z��
* @param		count: �v�f�̌�
* @param		greater: �\�[�g�̃��[��
********************************************************/
template <typename Comparator>
inline void SortDatas(ScoreData* datas, const int count, Comparator greater)
{
	ScoreData temp;
	int finishCount, i, j;
	for (finishCount = 0; finishCount < count; finishCount++)
	{
		for (j = finishCount, i = finishCount - 1; i >= 0; i--, j--)
		{
			if (greater(datas[i], datas[j]))
			{
				temp = datas[i];
				datas[i] = datas[j];
				datas[j] = temp;
			}
			else
			{
				break;
			}
		}
	}

	//test
#if 0 
	for (i = 0; i < count; i++)
	{
		std::cout << datas[i].name << ":" << datas[i].score << std::endl;
	}
#endif // 1

}

/*********************************************************
* @brief		2���X�g�ɁA�v�f�̏��Ԃ������ł��邩�̃`�F�b�N
* @param		list1: ��r���郊�X�g1
* @param		list2: ��r���郊�X�g2
* @retval		false: ���Ԃ��S�������ł͂Ȃ��ꍇ
* @retval		true: ���Ԃ��S�������̏ꍇ
********************************************************/
inline bool IsSameOrder(const DoubleLinkedList<ScoreData>& list1, const DoubleLinkedList<ScoreData>& list2)
{
	bool isSame = true;//���ԑS�������̏ꍇtrue
	auto iter1 = list1.CBegin();
	auto iter2 = list2.CBegin();
	auto end = list1.CEnd();
	for (; iter1 != end; iter1++, iter2++)
	{
		if ((*iter1).name != (*iter2).name ||
			(*iter1).score != (*iter2).score)
		{
			isSame = false;
			break;
		}
	}
	return isSame;
}

#pragma endregion

#pragma region ========== Stack ==========
/*********************************************************
* @brief		�w��v�f���̃X�^�b�N�̃t�B�N�X�`��
********************************************************/
class StackFixture : public ::testing::Test
{
protected:
	// @brief		�e�X�g�p�X�^�b�N
	Stack<ScoreData> stack;

protected:
	virtual void SetUp(void)
	{
	}

	virtual void TearDown(void)
	{
	}

	/*********************************************************
	* @brief		�v�f��1���������
	********************************************************/
	void InputOneData()
	{
		ClearList();

	}

	/*********************************************************
	* @brief		�v�f��2�����
	********************************************************/
	void InputTwoData()
	{
		ClearList();

		ScoreData data;
	}

	/*********************************************************
	* @brief		2�ȏ�A�w��v�f���œ����
	* @param		count: �v�f��[2,5]
	********************************************************/
	void InputDatas(int count)
	{
		ClearList();

		ScoreData data;
	}

	/*********************************************************
	* @brief		���X�g���󂭂���
	********************************************************/
	void ClearList()
	{
		//��������S���폜
		while (stack.Count() > 0)
		{
			stack.Pop();
		}
	}
};

/*********************************************************
* @brief		�w�肵���v�f���X�^�b�N�ɓ����
* @param		datas: �w�肵���v�f
* @param		count: �v�f��[2,10]
* @param		list: �g�����X�g
********************************************************/
inline void InputDatasToStack(ScoreData* datas, int count, Stack<ScoreData>& stack)
{
	ScoreData data;
	int dataNum = count;

	//�쐬���𐧌�
	if (dataNum < 2)dataNum = 2;
	if (dataNum > 10)dataNum = 10;

	for (int i = 0; i < dataNum; i++)
	{
		data.score = datas[i].score;
		data.name = datas[i].name;
		stack.Push(data);
	}
}

#pragma endregion