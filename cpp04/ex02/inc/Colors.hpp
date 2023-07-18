/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Colors.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:21:41 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/15 13:18:29 by cjackows         ###   ########.fr       */
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

#define BASE_T "\033[38;5;"
#define BASE_B "\033[48;5;"

#define	SYS_MSG_DES " \033[38;5;242m❯ \033[3m\033[38;5;242m\033[38;5;124m"
#define	SYS_MSG_CON " \033[38;5;242m❯ \033[3m\033[38;5;242m\033[38;5;28m"
#define	SYS_MSG "\033[38;5;242m❯ \033[3m\033[38;5;242m"
#define	SYS_MSG_B "\033[48;5;242m❯ \033[3m\033[38;5;242m "
#define G "\033[38;5;242m"
#define SYS "\033[38;5;242m\033[4m\033[38;5;33m"

#define ERROR "\033[48;5;160m[ ERROR ]\033[0m \033[38;5;196m"
#define P_DEBUG "\033[48;5;202m              [ DEBUGGING ]            \033[0m"
#define INFO "\033[48;5;39m[ INFORMATION ]\033[0m \033[38;5;123m"
#define T_DEBUG "\033[38;5;202m"
#define BLUE "\033[38;5;123m"
#define DARKBLUE "\033[38;5;33m"
#define BLUE_B "\033[48;5;39m"
#define GREEN "\033[1;32m"
#define BOLD "\033[1m"
#define ITALIC "\033[3m"
#define UNDERLINE "\033[4m"
#define STRIKETHROUGH "\033[9m"
#define RED "\033[38;5;160m"
#define R "\033[0m"
#define E "\033[0m\n"
#define F "\r\033[K"
#define A "\033[0A"
