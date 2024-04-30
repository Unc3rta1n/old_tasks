#include <iostream>

template < typename T >
void my_swap_with_xor(T& first, T& second)
{
	first ^= second ^= first ^= second;
	
}

template < typename T >
void my_swap_with_temp(T& first, T& second)
{ 
	T temp=first;
	first = second;
	second = temp;
}

class Person 
{
public:
	int age;
	int age1;
};
template <typename T, size_t size>
class SafeArray 
{
private:
	T array[size];
public:
	T operator[](int index)
	{
		try
		{

			if (index < 0 && index >= size)
				throw " incorrect index of array, return value=-1";

			return array[index];
		}
		catch (const char* msg)
		{
			std::cout << "error:" << msg << std::endl;
		}
		return -1;
	}
	void set_array()
	{
		
		for (size_t i=0; i<size; i++)
	    {
			array[i] = i;
		}
	}
	
};

int main(void)
{
	int a = 5;
	int b = 10;
	std::cout << "before swap with xor: " << a << " " << b << std::endl;
	my_swap_with_xor<int>(a, b);
	std::cout << "after swap with xor: " << a << " " << b << std::endl;
	Person man;
	man.age = 15;
	man.age1 = 200;
	std::cout << "before swap with temp: " << man.age << " " << man.age1 << std::endl;
	my_swap_with_temp<int>(man.age, man.age1);
	std::cout << "after swap with temp: " << man.age << " " << man.age1 << std::endl;
	system("pause");
	system("cls");
	SafeArray<int, 10> arr;
	arr.set_array();
	int index = -1;
	std::cout << "SafeArray<int>[" << index << "]==" << arr[index] << std::endl;
	SafeArray<char, 10> arr1;
	arr1.set_array();
	int index1 = 6;
	std::cout << "SafeArray<char>[" << index1 << "]==" << arr1[index1] << std::endl;
	return 0;
}