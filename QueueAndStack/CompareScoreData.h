/*********************************************************
* @brief		�\�[�g�̃��[���̃w�b�_�[
* @date			2022/10/17
********************************************************/
#pragma once
#include "ScoreData.h"

/*********************************************************
* @brief	�X�R�A��r�̃t�@���N�^(����)
********************************************************/
class ScoreGreater
{
public:
	inline bool operator()(const ScoreData& left, const ScoreData& right) {
		return left.score > right.score;
	}
};

/*********************************************************
* @brief	�X�R�A��r�̃t�@���N�^(�~��)
********************************************************/
class ScoreLess
{
public:
	inline bool operator()(const ScoreData& left, const ScoreData& right) {
		return left.score < right.score;
	}
};

/*********************************************************
* @brief	���O��r�̃t�@���N�^(����)
********************************************************/
class NameGreater
{
public:
	inline bool operator()(const ScoreData& left, const ScoreData& right) {
		return left.name > right.name;
	}
};

/*********************************************************
* @brief	���O��r�̃t�@���N�^(�~��)
********************************************************/
class NameLess
{
public:
	inline bool operator()(const ScoreData& left, const ScoreData& right) {
		return left.name < right.name;
	}
};
