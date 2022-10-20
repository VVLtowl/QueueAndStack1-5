/*********************************************************
* @brief	�X�^�b�N�̃w�b�_�[�t�@�C��
* @date		2022/10/20
********************************************************/
#pragma once
#include "DoubleLinkedList.h"

/*********************************************************
* @brief		�X�^�b�N
* @details		�X�^�b�N�̃e���v���[�g
* @tparam		DataType: �f�[�^�̌^
********************************************************/
template <class DataType>
class Stack
{
private:
	// @brief		�o�������X�g
	DoubleLinkedList<DataType> list;

public:

	//const ���\�b�h

	/*********************************************************
	* @brief	�v�f�����擾����
	* @return	�v�f����Ԃ�
	********************************************************/
	const int Count() const;

	/*********************************************************
	* @brief	�v�b�V��
	* @details	�����ɗv�f��ǉ�����B
	* @param	data: �ǉ��������v�f
	* @retval	true: �v�b�V�������̏ꍇ	
	* @retval	false: �v�b�V�����s�̏ꍇ
	********************************************************/
	bool Push(DataType data);

	/*********************************************************
	* @brief		�|�b�v
	* @details		�����v�f�������o�R�œn����A���̗v�f�����X�g����폜�����B
	*				��ł���ꍇ�Ɏ��s�B
	* @param[out]	pOptData: ���o���v�f���i�[���߂̈���
	* @retval		true: �|�b�v�����̏ꍇ
	* @retval		false: �|�b�v���s�̏ꍇ
	********************************************************/
	bool Pop(DataType* pOptData=nullptr);
};

#include "Stack.inl"
