#pragma once
using namespace System;
using namespace System::Collections::Generic;
#include "JwsHeader.h"
#include "JwwData.h"
#include "JwwDataList.h"
#include "CJwsReader.h"
#include "JwwImage.h"

namespace JwwHelper {
	public ref class JwsReader
	{
	public:
		delegate void CompletedCallback(JwsReader^);
	public:
		JwsReader() {
			m_pReader = new CJwsReader();
		}
		~JwsReader() { this->!JwsReader(); }
		!JwsReader() { delete m_pReader; }
	public:
		/// <summary>
		/// jws�t�@�C���̃w�b�_�[
		/// </summary>
		property JwsHeader^ Header {
			JwsHeader^ get() { return mHeader; }
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


	public:
		void Read(String^ path, CompletedCallback^ completed);
		int GetBlockSize() {
			return mDataListList->Count;
		}

	protected:
		JwsHeader^ mHeader = gcnew JwsHeader();
		List<JwwData^>^ mDataList = gcnew List<JwwData^>();
		List<JwwDataList^>^ mDataListList = gcnew List<JwwDataList^>();

	protected:
		CJwsReader* m_pReader;
		void ConvertToManaged();

	};
}

