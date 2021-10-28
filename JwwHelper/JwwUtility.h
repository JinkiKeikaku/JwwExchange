#pragma once
#include "CData.h"
#include "JwwData.h"

#ifndef _countof
#define _countof(array) (sizeof(array)/sizeof(array[0]))
#endif

using namespace System::Collections::Generic;


namespace JwwHelper {
	JwwData^ ConvertToJwwData(CData*);
	void ConvertToCString(CString& dst, String^ src);



	template<typename T, size_t size>
	[StructLayout(LayoutKind::Sequential, Size = sizeof(T) * size)]
	public value struct native_array
	{
		T elem;
		property T default[int]
		{
			T get(int index)
			{
				pin_ptr<T> p = &this->elem;
				return p[index];
			}
			void set(int index, T value)
			{
				pin_ptr<T> p = &this->elem;
				p[index] = value;
			}
		}
	};


}

