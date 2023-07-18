/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjackows <cjackows@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:58:46 by cjackows          #+#    #+#             */
/*   Updated: 2023/07/17 13:17:25 by cjackows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreation", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreation", 145, 137),  _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm(src.getName(), src.getGradeRequiedToSign(), src.getGradeRequiedToExec()), _target(src._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src) {
	_target = src._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::action() const {
	std::ofstream file;
	file.open (_target + "_shrubbery");
	file
		<< "              _{\\ _{\\{\\/}/}/}__\n"
		<< "             {/{/\\}{/{/\\}(\\}{/\\} _\n"
		<< "            {/{/\\}{/{/\\}(_)\\}{/{/\\}  _\n"
		<< "         {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}\n"
		<< "        {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}\n"
		<< "       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}\n"
		<< "      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}\n"
		<< "      _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}\n"
		<< "     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}\n"
		<< "      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}\n"
		<< "       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)\n"
		<< "      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}\n"
		<< "       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}\n"
		<< "         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}\n"
		<< "          (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)\n"
		<< "            {/{/{\\{\\/}{/{\\{\\{\\(_)/}\n"
		<< "             {/{\\{\\{\\/}/}{\\{\\\\}/}\n"
		<< "              {){/ {\\/}{\\/} \\}\\}\n"
		<< "              (_)  \\.-'.-/\n"
		<< "          __...--- |'-.-'| --...__\n"
		<< "   _...--    .-'   |'-.-'|  ' -.  --..__\n"
		<< " -    ' .  . '     |.'-._| '  . .  '   \n"
		<< " .  '-  '    .--'  | '-.'|    .  '  . '\n"
		<< "          ' ..     |'-_.-|\n"
		<< "  .  '  .       _.-|-._ -|-._  .  '  .\n"
		<< "              .'   |'- .-|   '.\n"
		<< "  ..-'   ' .  '.   `-._.-`   .'  '  - .\n"
		<< "   .-' '        '-._______.-'     '  .;\n";
	file.close();
}

std::string ShrubberyCreationForm::getTarget() const { return _target; }
