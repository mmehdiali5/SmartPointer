#ifndef UNIQUE_SMART_POINTER
#define UNIQUE_SMART_POINTER

template<typename T>
class UniqueSmartPointer
{
protected:
	T*pData;
public:
	UniqueSmartPointer(T*ptr = nullptr)
	{
		pData = ptr;
	}
	const T*get()const
	{
		return pData;
	}
	T& operator*()
	{
		return *pData;
	}
	T* operator->()
	{
		return pData;
	}
	T* release()
	{
		T*temp = pData;
		pData = nullptr;
		return temp;
	}
	void reset(T*p = nullptr)
	{
		this->~UniqueSmartPointer();
		pData = p;
	}
	operator bool()
	{
		if (!pData)
		{
			return false;
		}
		return true;
	}

	void swap(UniqueSmartPointer&x)
	{
		T*temp = this->operator->();
		this->release();
		this->reset(x.operator->());
		x.release();
		x.reset(temp);
	}

	T&operator[](int i)
	{
		return pData[i];
	}

	~UniqueSmartPointer()
	{
		if (pData)
		{
			delete pData;
		}
		pData = nullptr;
	}
	UniqueSmartPointer&operator=(UniqueSmartPointer& ref)
	{
		if (this == &ref)
		{
			return *this;
		}
		this->reset(ref.operator->());
		ref.release();
		return *this;
	}

	UniqueSmartPointer(UniqueSmartPointer&ref)
	{
		pData = nullptr;
		this->reset(ref.operator->());
		ref.release();
	}

	UniqueSmartPointer(UniqueSmartPointer&&ref)
	{
		pData = nullptr;
		this->reset(ref.operator->());
		ref.release();
	}

	UniqueSmartPointer&operator=(UniqueSmartPointer&& ref)
	{
		if (this == &ref)
		{
			return *this;
		}
		this->reset(ref.operator->());
		ref.release();
		return *this;
	}
};



template<typename T>
class UniqueSmartPointer<T[]>:public UniqueSmartPointer<T>
{
public:
	
	UniqueSmartPointer(T*ptr = nullptr)
	{
		UniqueSmartPointer<T>::pData = ptr;
	}
	
	~UniqueSmartPointer()
	{
		if (UniqueSmartPointer<T>::pData)
		{
			delete [] UniqueSmartPointer<T>::pData;
		}
		UniqueSmartPointer<T>::pData = nullptr;
	}
};

template<typename T>
class UniqueSmartPointer<T*> :public UniqueSmartPointer<T>
{
public:

	UniqueSmartPointer(T*ptr = nullptr)
	{
		UniqueSmartPointer<T>::pData = ptr;
	}

	~UniqueSmartPointer()
	{
		if (UniqueSmartPointer<T>::pData)
		{
			delete[] UniqueSmartPointer<T>::pData;
		}
		UniqueSmartPointer<T>::pData = nullptr;
	}
};

#endif