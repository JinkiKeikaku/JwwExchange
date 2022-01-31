#pragma once
#include "CJwsWriter.h"
#include "JwsHeader.h"
#include "JwwData.h"
#include "JwwDataList.h"

using namespace System;
namespace JwwHelper {

	/// <summary>
	/// jws�t�@�C���ۑ��N���X�B
	/// </summary>
	public ref class JwsWriter
	{
	public:
		/// <summary>
		/// �w�b�_�[
		/// </summary>
		property JwsHeader^ Header {
			JwsHeader^ get() {
				return _Header;
			}
		}
	public:
		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		JwsWriter();
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
	public:
		~JwsWriter();
		!JwsWriter();

	private:
		CJwsWriter* m_pWriter;
		JwsHeader^ _Header;

	};

}
