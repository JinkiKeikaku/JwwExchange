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
#include "JwwImage.h"
using namespace System;
namespace JwwHelper {
	/// <summary>
	/// jww�t�@�C���ۑ��N���X�B
	/// </summary>
	public ref class JwwWriter
	{
	public:
		/// <summary>
		/// �w�b�_�[
		/// </summary>
		property JwwHeader^ Header {
			JwwHeader^ get() {
				return _Header;
			}
		}
	public:
		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		JwwWriter();
		/// <summary>
		/// �w�b�_�[�͐ݒ荀�ڂ������̂�jww�t�@�C���ɂ�菉�������܂��B
		/// �w�b�_�[���������O�͂ł���߂Ȓl�������Ă��܂��B�K�����������Ă��������B
		/// ����������t�@�C����ver7.02�ȍ~�ɂ��Ă�������(JW_DATA_VERSION=700)�B
		/// ��������Ɋ�]����w�b�_�[�̃v���p�e�B�[��ݒ肵�Ă��������B
		/// </summary>
		/// <param name="templatePath">�e���v���[�g�t�@�C���̃p�X</param>
		void InitHeader(String^ templatePath);

		/// <summary>
		/// �t�@�C�������o��
		/// </summary>
		/// <param name="path"></param>
		void Write(String^ path);
		/// <summary>
		/// �������ސ}�`��ǉ����܂��B
		/// </summary>
		/// <param name="data"></param>
		void AddData(JwwData^ data);
		/// <summary>
		/// �u���b�N�}�`�̎��̂�ǉ����܂��B
		/// </summary>
		void AddDataList(JwwDataList^ dataList);
		/// <summary>
		/// �����摜��ǉ����܂��B�摜
		/// </summary>
		void AddImage(JwwImage^ image);
	public:
		~JwwWriter();
		!JwwWriter();

	private:
		CJwwWriter* m_pWriter;
		JwwHeader^ _Header;
		//array<JwwImage^>^ mImages = gcnew array<JwwImage^>(0);
	};
}
