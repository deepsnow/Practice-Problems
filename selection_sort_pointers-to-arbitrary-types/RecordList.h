#pragma once

template<typename T>
class RecordList
{
private:
	int size;
	T **pRefList;

public:

	//The implementation of a template class must be in the header file for some compilers.
		//http://www.comeaucomputing.com/techtalk/templates/#whylinkerror
		//http://www.parashift.com/c++-faq-lite/templates.html#faq-35.12

	RecordList(T buffer[], int buffer_len) 
	{
		size = buffer_len;
		pRefList = new T*[buffer_len]; //I should do deep copy here in case caller's data goes out of scope
		for(int i=0; i<size; i++)
		{
			pRefList[i] = &buffer[i];
		}
	}

	~RecordList(void) {delete [] pRefList;}

	void printList()
	{
		for(int i=0; i<size; i++)
		{
			cout << *pRefList[i] << (i==size-1 ? "" : ", ");
		}
		cout << endl;
	}

	void sortList()
	{
		for(int i=0; i<size; i++)
		{
			int index_to_smallest = i;
			for(int j=i+1; j<size; j++)
			{
				if(*pRefList[j] < *pRefList[index_to_smallest])
				{
					index_to_smallest = j;
				}
			}
			if(*pRefList[index_to_smallest] < *pRefList[i])
			{
				//swap pointers
				T* pTemp = pRefList[i];
				pRefList[i] = pRefList[index_to_smallest];
				pRefList[index_to_smallest] = pTemp;
			}
		}
	}

};
