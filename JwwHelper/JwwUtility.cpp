#include "JwwUtility.h"
#include "JwwSen.h"
#include "JwwMoji.h"
#include "JwwEnko.h"
#include "JwwTen.h"
#include "JwwSolid.h"
#include "JwwSunpou.h"
#include "JwwBlock.h"

namespace JwwHelper {
	JwwData^ ConvertToJwwData(CData* data) {
		CRuntimeClass* c = data->GetRuntimeClass();
		LPCSTR name = c->m_lpszClassName;
		JwwData^ s;
		if (strcmp(name, "CDataSen") == 0) {
			s = gcnew JwwSen((CDataSen*)data->Clone());
		}
		else if (strcmp(name, "CDataMoji") == 0) {
			s = gcnew JwwMoji((CDataMoji*)data->Clone());
		}
		else if (strcmp(name, "CDataTen") == 0) {
			s = gcnew JwwTen((CDataTen*)data->Clone());
		}
		else if (strcmp(name, "CDataEnko") == 0) {
			s = gcnew JwwEnko((CDataEnko*)data->Clone());
		}
		else if (strcmp(name, "CDataSolid") == 0) {
			s = gcnew JwwSolid((CDataSolid*)data->Clone());
		}
		else if (strcmp(name, "CDataSunpou") == 0) {
			s = gcnew JwwSunpou((CDataSunpou*)data->Clone());
		}
		else if (strcmp(name, "CDataBlock") == 0) {
			s = gcnew JwwBlock((CDataBlock*)data->Clone());
		}
		return s;
	}

	void ConvertToCString(CString& dst, String^ src) {
		pin_ptr<const WCHAR> str = PtrToStringChars(src);
		CW2A astr(str);
		dst = astr;
	}

}
