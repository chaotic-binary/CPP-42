#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include "easyfind.hpp"

int main(void)
{
	{
		std::vector<int> v(5);
		std::vector<int>::iterator found;
		for (int i = 0; i < 5; i++)
			v[i] = i;
		try {
			found = easyfind(v, 42);
		} catch (const std::exception& e) {}
		found = easyfind(v, 0);
		std::cout << "Found " << *found << " in vector\n\n";
	}

	{
		std::list<int> lst;
		std::list<int>::iterator found;
		for (int i = 0; i < 5; i++)
			lst.push_back(i);
		try {
			found = easyfind(lst, 42);
		} catch (const std::exception& e) {}
		found = easyfind(lst, 3);
		std::cout << "Found " << *found << " in list\n\n";
	}

	{
		std::deque<int> deque;
		std::deque<int>::iterator found;
		for (int i = 0; i < 5; i++)
			deque.push_back(i);
		try {
			found = easyfind(deque, 42);
		} catch (const std::exception& e) {}
		found = easyfind(deque, 3);
		std::cout << "Found " << *found << " in deque\n\n";
	}

	{
		std::set<int> set;
		std::set<int>::iterator found;
		for (int i = 0; i < 5; i++)
			set.insert(i);
		try {
			found = easyfind(set, 42);
		} catch (const std::exception& e) {}
		found = easyfind(set, 2);
		std::cout << "Found " << *found << " in set\n";
	}
	return (0);
}