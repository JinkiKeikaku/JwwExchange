#pragma once
#include"CJwwImage.h"
using namespace System::Runtime::InteropServices;

namespace JwwHelper {
	/// <summary>
	/// �����摜�̎��́B�I�u�W�F�N�g�쐬�̓R���X�g���N�^�ł͂Ȃ��AJwwImage.Create()���g���܂��B
	/// </summary>
	public ref class JwwImage
	{
	public:
		/// <summary>
		/// <para>�I�u�W�F�N�g�쐬�B�C���[�W�͈��k�����B[imageName]�̊g���q�͈��k����̂���".gz"��t����B</para>
		/// <para>�摜�f�[�^�͂����炭Windows��Bitmap�����g���Ȃ��B</para>
		/// <para>�摜�̐}�`�f�[�^�͕ʂ�JwwMoji���g���B</para>
		/// </summary>
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
		/// �t�@�C����
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

		/// <summary>
		/// �C���[�W�o�b�t�@�[�̃T�C�Y
		/// </summary>
		property int Size {
			int get() {
				return m_pImage->m_Size;
			}
		}
		/// <summary>
		/// �C���[�W�o�b�t�@�[
		/// </summary>
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
