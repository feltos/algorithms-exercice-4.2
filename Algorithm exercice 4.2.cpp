#include <iostream>
#include <list>




void show_list(std::list<int>& intList)
{
	std::cout << "The list contains: \n";
	for (int elem : intList)
	{
		std::cout << elem << "\n";
	}
}


void bubble_sort(std::list<int>& intList)
{
	bool is_sorted = false;
	while (!is_sorted)
	{
		is_sorted = true;
		for (auto j = intList.begin(); j != intList.end(); ++j)
		{
			if (std::next(j, 1) == intList.end())
				break;

			if (*std::next(j, 1) < *(j))
			{
				int tmp = *std::next(j, 1);
				*std::next(j, 1) = *(j);
				*(j) = tmp;
				is_sorted = false;
			}
		}
	}
}


void insertion_sort(std::list<int>& intList)
{

	for (auto i = intList.begin(); i != intList.end(); ++i)
	{
		while (*(i) > 0 && *std::next(i,1) > *(i))
		{
			auto temp = *(i);
			*(i) = *std::next(i,1);
			*std::next(i, 1) = temp;
			
		}

		*(i) = *std::next(i,1);
	}
}

void quick_sort(std::list<int>& intList)
{

	auto i = intList.begin();
	auto j = intList.end();
	


	while (*(i) < *(j))
	{
		
		while (*(i) < *(j))
		{
			i++;
		}
		while (*(j) < *(i))
		{
			j--;
		}
		if (*(i) <= *(j))
		{
			auto temp = *(i);
			*(i) = *(j);
			*(j) = temp;
		}
		else 
		{
			quick_sort(intList);
		}

		
			
	}
}




void sort_list(std::list<int>& intList)
{
	//bubble_sort(intList); WORK
	//insertion_sort(intList);// DIDN'T WORK =,(
	//quick_sort(intList); DIDN'T WORK =,(
}


int main()
{

	std::list<int> intList =
	{
		4,
		2,
		3,
		6,
		5,
		1
	};
	std::cout << "Before the sort: \n";
	show_list(intList);

	sort_list(intList);

	std::cout << "After the sort: \n";
	show_list(intList);

	system("pause");
	return 0;
}
