#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>

template<typename T>
class Node
{
public:
	Node() :
		m_pNext(nullptr), m_pPrev(nullptr)
	{
	}
	Node(T Data) :
		m_pNext(nullptr), m_pPrev(nullptr)
	{
		m_Data = Data;
	}
	virtual ~Node()
	{ }
	T m_Data;
	Node* m_pPrev;
	Node* m_pNext;
};


template<typename T>
class List
{
public:

	//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
	//Constructor and Destructor start !!!!!!!!!!!!!
	//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\

	List() :
		m_pStart(nullptr)
	{
		m_pStart = new Node<T>;
		m_pEnd = new Node<T>;
		m_pStart->m_pNext = m_pEnd;
		m_pStart->m_pPrev = m_pStart;
		m_pEnd->m_pPrev = m_pStart;
		m_pEnd->m_pNext = m_pEnd;
	}

	virtual ~List()
	{
		for (Node<T>* pBuffer = m_pStart->m_pNext; pBuffer->m_pNext != pBuffer; pBuffer = pBuffer->m_pNext)
		{
			delete pBuffer->m_pPrev;
		}
		delete m_pEnd;
	}


	//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
	//Constructor and Destructor end !!!!!!!!!!!!!!!
	//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\








	//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
	//Methods start !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\

	int Length() const
	{
		return m_iSize;
	}

	void begin()
	{
		m_iPosition = 0;
		m_pPosition = m_pStart->m_pNext;
	}
	
	void append(T Data)
	{
		Node<T>* pBuffer = m_pEnd->m_pPrev;
		m_pEnd->m_pPrev = new Node<T>(Data);
		m_pEnd->m_pPrev->m_pNext = m_pEnd;
		m_pEnd->m_pPrev->m_pPrev = pBuffer;
		pBuffer->m_pNext = m_pEnd->m_pPrev;
		m_iSize++;

	}

	void insert(int iIndex, T Data)
	{
		if (iIndex == m_iSize)
		{
			append(Data);
			m_iSize++;
			return;
		}

		int i = 0;
		Node<T>* pBuffer = m_pStart->m_pNext;
		for (; pBuffer->m_pNext != pBuffer; pBuffer = pBuffer->m_pNext, i++)
		{
			if (i == iIndex)
			{
				Node<T>* pBuffer2 = pBuffer->m_pPrev;
				pBuffer2->m_pNext = new Node<T>(Data);
				pBuffer2->m_pNext->m_pNext = pBuffer;
				pBuffer->m_pPrev = pBuffer2->m_pNext;
				pBuffer2->m_pNext->m_pPrev = pBuffer2;
				m_iSize++;
				return;
			}
		}
		std::cout << "Index out of Range." << std::endl;
	}

	void remove(int iIndex)
	{
		int i = 0;
		Node<T>* pBuffer = m_pStart->m_pNext;
		for (; pBuffer->m_pNext != pBuffer; pBuffer = pBuffer->m_pNext, i++)
		{
			if (i == iIndex)
			{
				if (pBuffer == m_pPosition)
				{
					m_pPosition = m_pPosition->m_pNext;
				}
				pBuffer->m_pPrev->m_pNext = pBuffer->m_pNext;
				pBuffer->m_pNext->m_pPrev = pBuffer->m_pPrev;
				delete pBuffer;
				pBuffer = nullptr;
				m_iSize--;
				return;
			}
		}
		std::cout << "Index out of Range." << std::endl;
	}

	void remove(T& ElementToRemove)
	{
		Node<T>* pBuffer = m_pStart->m_pNext;
		while (&(pBuffer->m_Data) != ElementToRemove)
		{
			pBuffer++;
		}
		if (pBuffer == m_pPosition)
		{
			m_pPosition = m_pPosition->m_pNext;
		}
		m_iSize--;
		pBuffer->m_pPrev->m_pNext = pBuffer->m_pNext;
		pBuffer->m_pNext->m_pPrev = pBuffer->m_pPrev;
		delete pBuffer;
		pBuffer = nullptr;
	}

	T& currentElement()
	{
		return m_pPosition->m_Data;
	}

	//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
	//Methods end !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\









	//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
	//Operators start !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\

	T& operator++(int)
	{
		m_pPosition = m_pPosition->m_pNext;
		m_iPosition++;
		return m_pPosition->m_pPrev->m_Data;
	}

	T& operator--(int)
	{
		m_pPosition = m_pPosition->m_pPrev;
		m_iPosition--;
		return m_pPosition->m_pNext->m_Data;
	}

	bool operator<=(const int &iIndex) const
	{
		return (m_iPosition <= iIndex && m_pPosition != m_pEnd && m_pPosition != m_pStart);
	}

	bool operator<(const int &iIndex) const
	{
		return (m_iPosition < iIndex && m_pPosition != m_pEnd && m_pPosition != m_pStart);
	}

	bool operator>(const int &iIndex) const
	{
		return (m_iPosition > iIndex && m_pPosition != m_pStart && m_pPosition != m_pEnd);
	}

	bool operator>=(const int &iIndex) const
	{
		return (m_iPosition >= iIndex && m_pPosition != m_pStart && m_pPosition != m_pEnd);
	}

	void operator=(int iPosition)
	{
		int i = 0;
		for (Node<T>* pBuffer = m_pStart->m_pNext; pBuffer->m_pNext != pBuffer; pBuffer = pBuffer->m_pNext, i++)
		{
			if (i == iPosition && pBuffer != m_pEnd)
			{
				m_pPosition = pBuffer;
				m_iPosition = i;
				return;
			}
		}
		std::cout << "Position not found";
	}

	//Zugriff per Index
	T& operator[](int iIndex)
	{
		Node<T>* pBuffer = m_pStart;
		if (iIndex < m_iSize)
		{
			if (iIndex < m_iSize*0.5)
			{
				int i = 0;
				pBuffer = m_pStart->m_pNext;
				for (; pBuffer->m_pNext != pBuffer; pBuffer = pBuffer->m_pNext, i++)
				{
					if (i == iIndex && pBuffer != m_pEnd)
					{
						return pBuffer->m_Data;
					}
				}
			}
			else
			{
				int i = m_iSize - 1;
				pBuffer = m_pEnd->m_pPrev;
				for (; pBuffer->m_pPrev != pBuffer; pBuffer = pBuffer->m_pPrev, i--)
				{
					if (i == iIndex && pBuffer != m_pStart)
					{
						return pBuffer->m_Data;
					}
				}
			}
		}
		std::cout << "Index out of Range." << std::endl;
		return pBuffer->m_Data;
	}

	void operator+=(T Data)
	{
		append(Data);
	}

	//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
	//Operators end !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\

private:
	Node<T>* m_pStart;
	Node<T>* m_pEnd;
	int m_iSize=0;
	int m_iPosition;
	Node<T>* m_pPosition;
};


#endif // !LIST_H