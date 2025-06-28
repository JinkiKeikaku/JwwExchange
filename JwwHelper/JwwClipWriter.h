#pragma once
#include "CJwwClipWriter.h"
#include "JwwClipHeader.h"
#include "JwwData.h"
#include "JwwDataList.h"

using namespace System;
namespace JwwHelper {

	public ref class JwwClipWriter
	{
	public:
		/// <summary>
		/// �w�b�_�[
		/// </summary>
		property JwwClipHeader^ Header {
			JwwClipHeader^ get() {
				return _Header;
			}
		}
	public:
		/// <summary>
		/// �R���X�g���N�^
		/// </summary>
		JwwClipWriter();
		/// <summary>
		/// �����o��
		/// </summary>
		/// <param name="path"></param>
		IntPtr Write();
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
		~JwwClipWriter();
		!JwwClipWriter();

	private:
		CJwwClipWriter* m_pWriter;
		JwwClipHeader^ _Header;

	};
}
