#include "Array.h"

int main()
{
	CArray<int> IntArray;
	//const CArray<int>	IntArray1;

//IntArray1.push_back(10);
//IntArray1.size();
	

	for (int i = 0; i < 10; i++)
	{
		IntArray.push_back(i);
	}
	IntArray.pop_back();

	IntArray.Remove(4);

	std::cout << "Capacity : " << IntArray.capacity() << std::endl;
	std::cout << "Count : " << IntArray.size() << std::endl;

	for (int i = 0; i < IntArray.size(); ++i)
	{
		//std::cout << IntArray.Get(i) << std::endl;
		std::cout << IntArray[i] << std::endl;
	}

	//CArray<int>*	IntArray1 = new CArray<int>;

	//delete IntArray1;

	return 0;
}