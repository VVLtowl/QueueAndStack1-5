/*********************************************************
* @brief		�o�������X�g�̃\�[�g�̃e�X�g
* @date			2022/10/18
********************************************************/
#include "gtest/gtest.h"
#include "../QueueAndStack/DoubleLinkedList.h"
#include "../QueueAndStack/ScoreData.h"
#include "../QueueAndStack/CompareScoreData.h"
#include "TestTool.h"

//�o�������X�g�̃\�[�g�̃e�X�g���s
#define GT_AUTO_TEST_LIST_SORT


/*********************************************************
* @brief		�^�t���e�X�g�p
********************************************************/
template<typename T>
class QuickSortTestFixture : public ListFixture
{
};

typedef ::testing::Types<ScoreGreater,ScoreLess,NameGreater,NameLess> Comparator;
TYPED_TEST_CASE(QuickSortTestFixture, Comparator);





namespace ex03_ListSort
{
#ifdef GT_AUTO_TEST_LIST_SORT

/*********************************************************
* @brief		�N�C�b�N�\�[�g�̃e�X�g
* @details		�\�[�g�����s�����e�X�g�S�ĂŁA�S�ẴL�[�E�~��������ԗ����Ď��s������
********************************************************/
#pragma region ========== �N�C�b�N�\�[�g ==========
	/*********************************************************
	* @brief		�v�f�������Ȃ����X�g�Ƀ\�[�g�����s�������̋���
	* @details		ID:0-0
	*				�v�f�������Ȃ����X�g�Ƀ\�[�g�����s�������A
	*				�����N����Ȃ������m�F�B
	********************************************************/
	TYPED_TEST(QuickSortTestFixture, WhenEmptyList)
	{
		//���s�O�ナ�X�g���ω����������m�F
		//m_pDummy��m_Count�Ŋm�F
		EXPECT_TRUE(list.CBegin()==list.CEnd());
		EXPECT_EQ(0, list.Count());

		TypeParam cmp;
		list.Sort(cmp);

		EXPECT_TRUE(list.CBegin() == list.CEnd());
		EXPECT_EQ(0, list.Count());
	}

	/*********************************************************
	* @brief		�v�f��1���������X�g�Ƀ\�[�g�����s�������̋���
	* @details		ID:0-1
	*				�v�f��1���������X�g�Ƀ\�[�g�����s�������A
	*				�����N����Ȃ������m�F�B
	********************************************************/
	TYPED_TEST(QuickSortTestFixture, WhenOneElement)
	{
		InputOneData();

		//���s�O�ナ�X�g���ω����������m�F
		//�l�Ŕ�r
		ScoreData datas[] = {
			{10,"head"},
		};
		CheckListValueAndCount(datas, 1, list);

		TypeParam cmp;
		list.Sort(cmp);

		CheckListValueAndCount(datas, 1, list);
	}

	/*********************************************************
	* @brief		2�ȏ�v�f�������X�g�Ƀ\�[�g�����s�������̋���
	* @details		ID:0-�Q
	*				2�ȏ�v�f�������X�g�Ƀ\�[�g�����s�������A
	*				�v�f���w�肵���L�[�ɏ����Ďw�肵�����ɕ��Ԃ����m�F�B
	*				�擪���珇�ɃC�e���[�^�Ŋm�F���A
	*				�m�[�h�̍����ւ�������ɍs���Ă��邩�`�F�b�N�B
	********************************************************/
	TYPED_TEST(QuickSortTestFixture, WhenManyElement)
	{
		ScoreData datas[] = {
			{8,"B"},
			{4,"Z"},
			{3,"C"},
			{7,"A"},
			{6,"Y"},
			{5,"X"},
			{2,"W"},
			{1,"D"},
		};
		InputDatasToList(datas, 8, list);

		//���s�O���X�g�v�f�̏��Ԃ��m�F
		CheckListValueAndCount(datas, 8, list);

		//���s�ナ�X�g�v�f�̏��Ԃ��m�F
		TypeParam cmp;
		list.Sort(cmp);
		SortDatas(datas, 8, cmp);//�����̏��̔z���p��
		CheckListValueAndCount(datas, 8, list);
	}

	/*********************************************************
	* @brief		�����L�[�����v�f�����郊�X�g�ŁA���̃L�[���w�肵�\�[�g�����s�������̋���
	* @details		ID:0-3
	*				�����L�[�����v�f�����郊�X�g�ŁA���̃L�[���w�肵�\�[�g�����s�������A
	*				�v�f���\�[�g����ĕ��Ԃ��A�����v�f�̏����͕ۏ؂���Ȃ��B
	********************************************************/
	TYPED_TEST(QuickSortTestFixture, ElementsHaveSameKey)
	{
		DoubleLinkedList<ScoreData> list1, list2;
		
		//���ׂĂ̗v�f�����������A�����L�[������ꍇ�A
		//�ŏ��̏��Ԃ͈Ⴄ�ƁA�\�[�g�̌��ʂɉe������
		const int count = 4;
		ScoreData datas1[count] = {
			{5,"B"},
			{3,"A"},
			{4,"A"},
			{4,"C"},
		};
		InputDatasToList(datas1, count, list1);
		ScoreData datas2[count] = {
			{4,"C"},
			{4,"A"},
			{3,"A"},
			{5,"B"},
		};
		InputDatasToList(datas2, count, list2);

		//�\�[�g���s��
		TypeParam cmp;
		list1.Sort(cmp);
		list2.Sort(cmp);

		//�v�f�͑S�����������A���񌋉ʂ��Ⴄ�\��������
		EXPECT_FALSE(IsSameOrder(list1, list2));

		//test ���X�g�o��
		PrintList(list1);
		PrintList(list2);
	}

	/*********************************************************
	* @brief		����ς݃��X�g�Ƀ\�[�g�����s�������̋���
	* @details		ID:0-4
	*				����ς݃��X�g�Ƀ\�[�g�����s�������A
	*				�����L�[�̗v�f�̊ԈȊO�̏��Ԃ��ϓ����Ȃ������`�F�b�N�B
	*				�d���v�f�Ȃ��̐���ς݃��X�g���g���B
	********************************************************/
	TYPED_TEST(QuickSortTestFixture, AfterSort)
	{
		DoubleLinkedList<ScoreData> list1, list2;
		TypeParam cmp;

		//����ς݃��X�g��2�p��
		const int count = 4;
		ScoreData datas[count] = {
			{5,"B"},
			{3,"A"},
			{2,"D"},
			{4,"C"},
		};
		InputDatasToList(datas, count, list1);
		InputDatasToList(datas, count, list2);
		list1.Sort(cmp);
		list2.Sort(cmp);
		//����̌�\�[�g����ĕ��Ԃ����`�F�b�N
		SortDatas(datas, count, cmp);
		CheckListValueAndCount(datas, count, list1);
		//����̌ナ�X�g�̏��Ԃ����������`�F�b�N
		EXPECT_TRUE(IsSameOrder(list1, list2));

		//�\�[�g�ς݂�list1�Ƀ\�[�g���s��
		list1.Sort(cmp);

		//list2�ŁAlist1�̏��Ԃ��ϓ����Ȃ������`�F�b�N
		EXPECT_TRUE(IsSameOrder(list1, list2));
	}

	/*********************************************************
	* @brief		��x���񂵂����X�g�̊e���ɑ}�����A�ēx�\�[�g�����s�������̋���
	* @details		ID:0-5
	*				��x���񂵂����X�g�̊e���ɑ}�����A�ēx�\�[�g�����s�������A
	*				�v�f���\�[�g����ĕ��Ԃ����`�F�b�N�B
	*				�d���v�f�Ȃ��̐���ς݃��X�g���g���B
	********************************************************/
	TYPED_TEST(QuickSortTestFixture, AfterSortAndInsert)
	{
		TypeParam cmp;

		//��x���񂵂����X�g��p��
		const int count = 4;
		ScoreData datas[count] = {
			{5,"B"},
			{3,"A"},
			{1,"E"},
			{4,"C"},
		};
		InputDatasToList(datas, count, list);
		list.Sort(cmp);
		//����̌�\�[�g����ĕ��Ԃ����`�F�b�N
		SortDatas(datas, count, cmp);
		CheckListValueAndCount(datas, count, list);

		//�}�����s��
		UpdateIterator();
		list.Insert(middleIter, { 2,"D" });

		//�Ăу\�[�g���s��
		list.Sort(cmp);

		//�Đ���̌�\�[�g����ĕ��Ԃ����`�F�b�N
		const int count2 = list.Count();
		ScoreData datas2[] = {
			{ 5,"B" },
			{ 3,"A" },
			{ 1,"E" },
			{ 4,"C" },
			{ 2,"D" },
		};
		SortDatas(datas2, count2, cmp);
		CheckListValueAndCount(datas2, count2, list);
	}

	/*********************************************************
	* @brief		�L�[�w������Ȃ�����(nullptr��n����)���̋���
	* @details		ID:0-6
	*				�L�[�w������Ȃ�����(nullptr��n����)���A
	*				�G���[�܂߂āA�����N����Ȃ������`�F�b�N�B
	********************************************************/
	TEST(QuickSortTest, WithoutComparator)
	{
		DoubleLinkedList<ScoreData> list;

		const int count = 5;
		ScoreData datas[count] = {
			{ 5,"B" },
			{ 3,"A" },
			{ 1,"E" },
			{ 4,"C" },
			{ 2,"D" },
		};
		InputDatasToList(datas, count, list);

		//�L�[�w������Ȃ��āA�\�[�g���s��
		list.Sort([](const ScoreData& left, const ScoreData& right)
			{return false; });
		
		//test
		//list.Sort([](const ScoreData& left, const ScoreData& right)
		//	{return true; });

		CheckListValueAndCount(datas, count, list);
	}

#pragma endregion

#endif
}
