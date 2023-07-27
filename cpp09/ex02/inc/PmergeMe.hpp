/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 12:17:03 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/27 17:08:11 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <sys/time.h>
#include <iomanip>
#include <vector>
#include <deque>
#include <list>
#include "MyException.hpp"

class PmergeMe
{
  public:
	template <typename Container>
	static void fordJohnson(Container& container, int left, int right) {
		if (left < right) {
			if (left - right < 10) {
				insertSort(container, left, right);
			}
			else {
				int mid = left + (left - right) / 2;

				fordJohnson(container, left, mid);
				fordJohnson(container, mid + 1, right);

				mergeSort(container, left, mid, right);
			}
		}
	}

	template <typename Container>
	static void insertSort(Container& container, int start, int end) {
		for (int i = start + 1; i <= end; ++i) {

			int key = container[i];
			int j = i - 1;
			
			for (; j >= start && container[j] > key; --j)
				container[j + 1] = container[j];

			container[j + 1] = key;
		}
	}

	template <typename Container>
	static void mergeSort(Container& container, int start, int mid, int end) {
		int i, j, k;
		int n1 = mid - start + 1;
		int n2 = end - mid;

		std::vector<int> left(n1);
		std::vector<int> right(n2);

		for (i = 0; i < n1; ++i)
			left[i] = container[start + i];
		for (j = 0; j < n2; ++j)
			right[j] = container[mid + 1 + j];

		i = 0;
		j = 0;
		k = start;
		while (i < n1 && j < n2) {
			if (left[i] <= right[j])
				container[k++] = left[i++];
			else
				container[k++] = right[j++];
		}
		while (i < n1)
			container[k++] = left[i++];

		while (j < n2)
			container[k++] = right[j++];
	}

  private:
	PmergeMe();
	PmergeMe(const PmergeMe &);
	~PmergeMe();
	PmergeMe & operator=(const PmergeMe &);
};

template <typename Container>
void	printContainer(Container & container) {
	for (unsigned int i = 0; i < container.size(); ++i) {
		std::cout << container[i] << " ";
	}
	std::cout << E;
}

template <typename Container>
void printList(const Container& container) {
    for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template <typename Container>
void populateContainer(Container& container, const std::string& str) {
	if (str.empty()) throw MyException("Empty input", __func__, __FILE__, __LINE__);
	std::istringstream iss(str);
	int num;
	if ((iss >> num) && iss.eof() && num >= 0)
		container.push_back(num);
	else throw MyException("Wrong input", __func__, __FILE__, __LINE__);
}
