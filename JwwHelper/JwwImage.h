#pragma once
#include"CJwwImage.h"
using namespace System::Runtime::InteropServices;

namespace JwwHelper {
	public ref class JwwImage
	{
	public:
		static JwwImage^ Create(String^ imageName, array<byte>^ buffer) {
			BYTE* buf = new BYTE[buffer->Length];
			Marshal::Copy(buffer, 0, (IntPtr)buf, buffer->Length);
			pin_ptr<const WCHAR> str = PtrToStringChars(imageName);
			CW2A astr(str);
			CJwwImage* image = new CJwwImage(CString(astr), buf, buffer->Length);
			return gcnew JwwImage(image);
		}

	internal:
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
		property array<byte>^ Buffer {
			array<byte>^ get(){
				array<byte>^ buf = gcnew array<byte>(m_pImage->m_Size);
				Marshal::Copy((IntPtr)m_pImage->m_pBuffer, buf, 0, m_pImage->m_Size);
				return buf;
			}
			void set(array<byte>^ value) {
				delete[]m_pImage->m_pBuffer;
				m_pImage->m_pBuffer = new BYTE[value->Length];
				m_pImage->m_Size = value->Length;
				Marshal::Copy(value, 0, (IntPtr)m_pImage->m_pBuffer, value->Length);
			}
		}
	};
}
