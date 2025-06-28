#pragma once
#include "CData.h"
#include "JwwUtility.h"

using namespace System;
using namespace System::Collections::Generic;

namespace JwwHelper {
	public ref class CStringArray : public IEnumerable<String^>
	{
	private:
		CString* _elems;
		int _size;
	public:
		CStringArray(CString* elems, int size) {
			_elems = elems;
			_size = size;
		}
		property String^ default[int]
		{
			String ^ get(int index)
			{
				if (index < 0 || index >= _size) throw gcnew System::IndexOutOfRangeException();
				return gcnew String(_elems[index]);
			}
			void set(int index, String ^ value)
			{
				if (index < 0 || index >= _size) throw gcnew System::IndexOutOfRangeException();
				ConvertToCString(_elems[index], value);
			}
		};
		property int Length {
			int get() {
				return _size;
			}
		};
		virtual IEnumerator<String^>^ GetEnumerator()
		{
			return gcnew enumerator(this);
		}
		virtual System::Collections::IEnumerator^ GetEnumerator2() = System::Collections::IEnumerable::GetEnumerator
		{
			return gcnew enumerator(this);
		}

	private:
		ref struct enumerator : IEnumerator<String^>
		{
			enumerator(CStringArray^ myArr)
			{
				colInst = myArr;
				currentIndex = -1;
			}

			virtual bool MoveNext() = IEnumerator<String^>::MoveNext
			{
				if (currentIndex < colInst->Length - 1)
				{
					currentIndex++;
					return true;
				}
				return false;
			}

				property String^ Current
			{
				virtual String^ get() = IEnumerator<String^>::Current::get
				{
					return colInst[currentIndex];
				}
			};
			property Object^ Current2
			{
				virtual Object^ get() = System::Collections::IEnumerator::Current::get
				{
					return colInst[currentIndex];
				}
			};
			virtual void Reset() = IEnumerator<String^>::Reset{}
				~enumerator() {}

			CStringArray^ colInst;
			int currentIndex;
		};
	};
}

