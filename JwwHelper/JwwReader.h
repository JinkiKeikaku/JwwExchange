#pragma once
using namespace System;
using namespace System::Collections::Generic;
#include "JwwHeader.h"
#include "JwwData.h"
#include "JwwDataList.h"
#include "JwwImage.h"
#include "CJwwReader.h"

namespace JwwHelper {
	/// <summary>
	/// jww�t�@�C���ǂݍ��݃N���X
	/// </summary>
	public ref class JwwReader
	{
	public:
		/// <summary>
		/// �t�@�C���ǂݍ��݊������ɌĂ΂��R�[���o�b�N
		/// </summary>
		delegate void CompletedCallback(JwwReader^);
	public:
		/// <summary>
		/// �R���X�g���N�^�B
		/// </summary>
		JwwReader() {
//			m_Completed = completed;
			m_pReader = new CJwwReader();
		}
		~JwwReader() { this->!JwwReader(); }
		!JwwReader() { delete m_pReader; }
	public:
		/// <summary>
		/// jww�t�@�C���̃w�b�_�[
		/// </summary>
		property JwwHeader^ Header {
			JwwHeader^ get() { return mHeader; }
		};
		/// <summary>
		/// �}�`�̃��X�g
		/// </summary>
		property List<JwwData^>^ DataList {
			List<JwwData^>^ get() { return mDataList; }
		};
		/// <summary>
		/// �u���b�N�}�`���̂̃��X�g
		/// </summary>
		property List<JwwDataList^>^ DataListList {
			List<JwwDataList^>^ get() { return mDataListList; }
		};

		/// <summary>
		/// �摜�����̃f�[�^�z��B�摜�͈��k����Ă���B�ڍׂ͖{�Ƃ̃h�L�������g�����Ă��������B
		/// </summary>
		property array<JwwImage^>^ Images {
			array<JwwImage^>^ get() {
				return mImages;
			}
		}


	public:
		/// <summary>
		/// �t�@�C���ǂݍ��݁B�ǂݍ��݊������͓n�����R�[���o�b�N���Ă΂��B
		/// </summary>
		/// <param name="path"></param>
		void Read(String^ path, CompletedCallback^ completed);

		void Read(array<byte>^ buffer, CompletedCallback^ completed);

		/// <summary>
		/// �u���b�N�}�`���B
		/// </summary>
		int GetBlockSize() {
			return mDataListList->Count;
		}

	protected:
		JwwHeader^ mHeader = gcnew JwwHeader();
		List<JwwData^>^ mDataList = gcnew List<JwwData^>();
		List<JwwDataList^>^ mDataListList = gcnew List<JwwDataList^>();
		array<JwwImage^>^ mImages = gcnew array<JwwImage^>(0);
		CJwwReader* m_pReader;
//		CompletedCallback^ m_Completed;

		void ConvertToManaged();
	};

}

