git@vogsphere.42wolfsburg.de:vogsphere/intra-uuid-70f7ad01-8b0e-4571-abe7-f37354826072-4977972-cjackows/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:45:57 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/20 11:55:06 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "../inc/Colors.hpp"

template <typename T>
class Array {
    public:
        Array() : _size(1), _array(new T[1], _array[0](0)) { std::cout << SYS_MSG_CON << "Def Constructor " << G << "called for: " << BLUE << "Array<T>" << E;}

        Array(unsigned int n) : _array(new T[n]), _size(n) { std::cout << SYS_MSG_CON << "Constructor " << G << "called for: " << BLUE << "Array<T>" << E; }

        Array(Array const & src) : _array(new T[src._size]), _size(src._size) { std::cout << SYS_MSG_CON << "Copy Constructor " << G << "called for: " << BLUE << "Array<T>" << E;
            for (unsigned int i = 0; i < _size; i++)
                _array[i] = src._array[i];
        }

        ~Array(void) { std::cout << SYS_MSG_DES << "Destructor " << G << "called for: " << BLUE << "Array<T>" << E;
            delete [] _array;
        }

        Array & operator=(Array const & src) { std::cout << SYS_MSG << BLUE << "Copy assignment operator " << G << "called for: " << BLUE << "Array<T>" << E;
            if (*this != src) {				
				delete [] _array;
				_size = src._size;
				_array = new T[_size];
				for (unsigned int i = 0; i < _size; i++)
					_array[i] = src._array[i];
			}
			return *this;
        }

        T & operator[](unsigned int n) {
            if (n >= _size)
                throw std::exception();
            else
                return _array[n];
        }

        unsigned int size(void) const {
            return _size;
        }

    private:
        T * _array;
        unsigned int _size;
};