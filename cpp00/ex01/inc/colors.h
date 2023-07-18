/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:21:41 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/04 18:15:27 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifdef __linux__
    #define OS_LINUX
    #define PROGRESS_DONE_CHAR '#'
    #define PROGRESS_TODO_CHAR '-'
#else
    #define OS_MAC
    #define PROGRESS_DONE_CHAR "🟩"
    #define PROGRESS_TODO_CHAR "⬜️"
#endif

#define BASE_T "\e[38;5;"
#define BASE_B "\e[48;5;"
#define ERROR "\e[48;5;160m[ ERROR ]\e[0m \e[38;5;196m"
#define P_DEBUG "\e[48;5;202m              [ DEBUGGING ]            \e[0m"
#define INFO "\e[48;5;39m[ INFORMATION ]\e[0m \e[38;5;123m"
#define T_DEBUG "\e[38;5;202m"
#define BLUE "\e[38;5;123m"
#define DARKBLUE "\e[38;5;33m"
#define BLUE_B "\e[48;5;39m"
#define GREEN "\033[1;32m"
#define R "\033[0m"
#define BOLD "\e[1m"
#define ITALIC "\e[3m"
#define UNDERLINE "\e[4m"
#define STRIKETHROUGH "\e[9m"
#define RED "\e[38;5;160m"
#define F "\r\033[K"
