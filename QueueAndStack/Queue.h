/*********************************************************
* @brief	�L���[�̃w�b�_�[�t�@�C��
* @date		2022/10/20
********************************************************/
#pragma once
#include "DoubleLinkedList.h"

/*********************************************************
* @brief		�L���[
* @details		�L���[�̃e���v���[�g
* @tparam		DataType: �f�[�^�̌^
********************************************************/
template <class DataType>
class Queue
{
private:
	// @brief		�o�������X�g
	DoubleLinkedList<DataType> m_List;

public:

	//const ���\�b�h

	/*********************************************************
	* @brief	�v�f�����擾����
	* @return	�v�f����Ԃ�
	********************************************************/
	const int Count() const;

	/*********************************************************
	* @brief	�v�b�V��
	* @details	�擪�ɗv�f��ǉ�����B
	* @param	data: �ǉ��������v�f
	* @retval	true: �v�b�V�������̏ꍇ	
	* @retval	false: �v�b�V�����s�̏ꍇ
	********************************************************/
	bool Push(const DataType& data);

	/*********************************************************
	* @brief		�|�b�v
	* @details		�擪�v�f�������o�R�œn����A���̗v�f�����X�g����폜�����B
	*				��ł���ꍇ�Ɏ��s�B
	* @param[out]	pOptData: ���o���v�f���i�[���߂̈���
	* @retval		true: �|�b�v�����̏ꍇ
	* @retval		false: �|�b�v���s�̏ꍇ
	********************************************************/
	bool Pop(DataType* pOptData = nullptr);
};

#include "Queue.inl"
