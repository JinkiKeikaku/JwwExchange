#pragma once
#include"CJwwImage.h"
namespace JwwHelper {
	public ref class JwwImage
	{
		CJwwImage* m_pImage;
	internal:
		JwwImage(CJwwImage* pImage) {
			m_pImage = pImage;
		}
	public:
		~JwwImage() { this->!JwwImage(); }
		!JwwImage() { delete m_pImage; }
	public:
		/// <summary>
		/// ƒtƒ@ƒCƒ‹–¼
		/// </summary>
		property String^ ImageName {
			String^ get() {
				return gcnew String(CA2W(m_pImage->m_ImageName.GetString()));
			}
			void set(String^ value) {
				pin_ptr<const WCHAR> str = PtrToStringChars(value);
				CW2A astr(str);
				m_pImage->m_ImageName = astr;
			}
		};
		property int Size {
			int get() {
				return m_pImage->m_Size;
			}
		}
		property byte* Buffer {
			byte* get() {
				return m_pImage->m_pBuffer;
			}
		}




	};
}
