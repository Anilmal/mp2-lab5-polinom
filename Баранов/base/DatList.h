#pragma once
#include "Monom.h"
using namespace std;

template <class T>
class DatList
{
private:
	struct DatValue
	{
		T elem;
		DatValue* pNext;
		DatValue* pPrev;
		DatValue(T elem_= {})
		{
			pNext = nullptr;
			pPrev = nullptr;
			elem = elem_;
		}
		DatValue(const DatValue &d)
		{
			elem = d.elem;
			pNext = d.pNext;
			pPrev = d.pPrev;
		}
		DatValue& operator=(const DatValue &d)
		{
			elem = d.elem;
			pNext = d.pNext;
			pPrev = d.pPrev;
		}
		
	};
	DatValue* pFirst;
	DatValue* pLast;
	int size = 0;

public:
	DatList() :pFirst(nullptr),pLast(nullptr) {}
	~DatList()
	{
		while (pFirst != nullptr)
		{
			DatValue *tmp = pFirst->pNext;
			delete pFirst;
			pFirst = tmp;
		}
	}
	void Pop(int pos)
	{
		if (IsEmpty())
			throw("IsEmpty");
		if (pos >= size || pos < 0)
			throw("Index Error");
		DatValue *tmp = pFirst;
		if (pos == 0)
		{
			if (pFirst->pNext == nullptr)
			{
				delete pFirst;
				pFirst = nullptr;
			}
			else
			{
				pFirst = pFirst->pNext;
				delete pFirst->pPrev;
				pFirst->pPrev = nullptr;
			}
			size--;
			return;
		}
		if (pos == size - 1)
		{
			tmp = pLast;
			tmp->pPrev->pNext = nullptr;
			pLast = pLast->pPrev;
			delete tmp;
			size--;
			return;
		}
		for (int i = 0; i < pos; i++)
			tmp = tmp->pNext;
		tmp->pNext->pPrev = tmp->pPrev;
		tmp->pPrev->pNext = tmp->pNext;
		delete tmp;
		size--;
	}
	bool IsEmpty()
	{
		return pFirst == nullptr;
	}
	void Push(T elem_)
	{
		if (IsEmpty())
		{
			pFirst = new DatValue;
			pFirst->elem = elem_;
			pLast = pFirst;
			size++;
		}
		else
		{
			DatValue *tmp = new DatValue;
			tmp->elem = elem_;
			tmp->pPrev = pLast;
			pLast->pNext = tmp;
			pLast = pLast->pNext;
			size++;
		}
	}
	T& Get()
	{
		DatValue *tmp = pLast;
		return tmp->elem;
	}
	int GetSize()
	{
		return size;
	}
};
