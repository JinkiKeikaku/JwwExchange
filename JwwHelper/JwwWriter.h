#pragma once
#include "CJwwWriter.h"
#include "JwwHeader.h"
#include "JwwData.h"
#include "JwwSen.h"
#include "JwwMoji.h"
#include "JwwTen.h"
#include "JwwEnko.h"
#include "JwwSunpou.h"
#include "JwwSolid.h"
#include "JwwBlock.h"
#include "JwwDataList.h"
using namespace System;
namespace JwwHelper {

	public ref class JwwWriter
	{
	public:
		property JwwHeader^ Header {
			JwwHeader^ get() {
				return _Header;
			}
		}
	public:
		JwwWriter();
		/// <summary>
		/// �w�b�_�[�͐ݒ荀�ڂ������̂�jww�t�@�C���ɂ�菉�������܂��B
		/// �w�b�_�[���������O�͂ł���߂Ȓl�������Ă��܂��B�K�����������Ă��������B
		/// ����������t�@�C����ver7.02�ȍ~�ɂ��Ă�������(JW_DATA_VERSION=700)�B
		/// ��������Ɋ�]����w�b�_�[�̃v���p�e�B�[��ݒ肵�Ă��������B
		/// </summary>
		/// <param name="templatePath">�e���v���[�g�t�@�C���̃p�X</param>
		void InitHeader(String^ templatePath);
		void Write(String^ path);
		void AddData(JwwData^ data);
		void AddDataList(JwwDataList^ dataList);
	public:
		~JwwWriter();
		!JwwWriter();

	private:
		CJwwWriter* m_pWriter;
		JwwHeader^ _Header;
	};
}
