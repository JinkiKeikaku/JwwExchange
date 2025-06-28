#include "pch.h"
#include "JwwReader.h"
#include "JwwData.h"
#include "JwwSen.h"
#include "JwwMoji.h"
#include "JwwEnko.h"
#include "JwwTen.h"
#include "JwwSolid.h"
#include "JwwSunpou.h"
#include "JwwBlock.h"
#include "JwwUtility.h"
#include "JwwImage.h"

namespace JwwHelper {
	void JwwReader::Read(String^ path, CompletedCallback^ completed) {
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		pin_ptr<const WCHAR> str = PtrToStringChars(path);
		//CW2A astr(str);

		m_pReader->Read(str);// astr);
		ConvertToManaged();
		if (completed != nullptr) {
			completed(this);
		}
	}

	void JwwReader::Read(array<byte>^ buffer, CompletedCallback^ completed)
	{
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		pin_ptr<byte> pinned = &buffer[0];
		m_pReader->Read((byte*)pinned, buffer->Length);
		ConvertToManaged();
		if (completed != nullptr) {
			completed(this);
		}
	}

	void JwwReader::ConvertToManaged() {
		mHeader = gcnew JwwHeader(m_pReader->m_pHeader->Clone());
		mDataList->Clear();
		POSITION pos = m_pReader->m_DataList.GetHeadPosition();
		while (pos != NULL) {
			CData* data = m_pReader->m_DataList.GetNext(pos);
			JwwData^ jd = ConvertToJwwData(data);
			if (jd != nullptr) mDataList->Add(jd);
		}
		pos = m_pReader->m_DataListList.GetHeadPosition();
		while (pos != NULL) {
			CDataList* data = m_pReader->m_DataListList.GetNext(pos);
			mDataListList->Add(gcnew JwwDataList((CDataList*)data->Clone()));
		}

		mImages = gcnew array<JwwImage^>(m_pReader->m_Images.size());
		for (size_t i = 0; i < m_pReader->m_Images.size(); i++) {
			mImages[i] = gcnew JwwImage(m_pReader->m_Images[i]);
		}
		//�摜�f�[�^�͑傫���̂ŃN���[���͍��Ȃ��B�������Ƃ̃f�[�^��Managed�ŊǗ�����B
		//���̂��߂����ŃN���A�B
		m_pReader->m_Images.clear();
	}
}