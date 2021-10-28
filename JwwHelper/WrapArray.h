#pragma once
using namespace System;
using namespace System::Collections::Generic;
namespace JwwHelper {

	template<typename  T>
	public ref class WrapArray : public IEnumerable<T>
	{
	private:
		T* _elems;
		int _size;
	public:
		WrapArray(T* elems, int size) {
			_elems = elems;
			_size = size;
		}
		property T default[int]
		{
			T get(int index)
			{
				if (index < 0 || index >= _size) throw gcnew System::IndexOutOfRangeException();
				return _elems[index];
			}
			void set(int index, T value)
			{
				if (index < 0 || index >= _size) throw gcnew System::IndexOutOfRangeException();
				_elems[index] = value;
			}
		};
		property int Length {
			int get() {
				return _size;
			}
		};

		virtual IEnumerator<T>^ GetEnumerator()
		{
			return gcnew enumerator(this);
		}
		virtual System::Collections::IEnumerator^ GetEnumerator2() = System::Collections::IEnumerable::GetEnumerator
		{
			return gcnew enumerator(this);
		}

	private:
		ref struct enumerator : IEnumerator<T>
		{
			enumerator(WrapArray<T>^ myArr)
			{
				colInst = myArr;
				currentIndex = -1;
			}

			virtual bool MoveNext() = IEnumerator<T>::MoveNext
			{
				if (currentIndex < colInst->Length - 1)
				{
					currentIndex++;
					return true;
				}
				return false;
			}

				property T Current
			{
				virtual T get() = IEnumerator<T>::Current::get
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
			virtual void Reset() = IEnumerator<T>::Reset{}
				~enumerator() {}

			WrapArray<T>^ colInst;
			int currentIndex;
		};
	};
}
