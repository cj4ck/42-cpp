#!/bin/sh
BASE_T="\033[38;5;"
BASE_B="\033[48;5;"
SYS_MSG_DES=" \033[38;5;242m❯ \033[3m\033[38;5;242m\033[38;5;124m"
SYS_MSG_CON=" \033[38;5;242m❯ \033[3m\033[38;5;242m\033[38;5;28m"
SYS_MSG="\033[38;5;242m❯ \033[3m\033[38;5;242m"
SYS_MSG_B="\033[48;5;242m❯ \033[3m\033[38;5;242m "
G="\033[38;5;242m"
SYS="\033[38;5;242m\033[4m\033[38;5;33m"
EX="\033[48;5;160m[ EXCEPTION ]\033[0m \033[38;5;196m"
KO="\033[48;5;160m[ FAIL ]\033[0m \033[38;5;196m"
P_DEBUG="\033[48;5;202m              [ DEBUGGING ]            \033[0m"
INFO="\033[48;5;39m[ INFORMATION ]\033[0m \033[38;5;123m"
T_DEBUG="\033[38;5;202m"
BLUE="\033[38;5;123m"
DARKBLUE="\033[38;5;33m"
BLUE_B="\033[48;5;39m"
GREEN="\033[1;32m"
BOLD="\033[1m"
ITALIC="\033[3m"
UNDERLINE="\033[4m"
STRIKETHROUGH="\033[9m"
RED="\033[38;5;160m"
R="\033[0m"
E="\033[0m\n"
F="\r\033[K"
A="\033[0A"

clear
printf "${BASE_T}231m .                                                      -=━━━┓\n"
printf "${BASE_T}231m |    ▁▁▁▁▁ ▁▁▁▁▁▁▁▁          ▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁◹ ┃\n"   
printf "${BASE_T}195m ┃   ╱  │  │╲▁▁▁▁▁  ╲         ╲▁   ▁▁▁ ╲▁▁▁▁▁▁   ╲▁▁▁▁▁▁   ╲ |\n"
printf "${BASE_T}195m ┃  ╱   │  │▁╱  ▁▁▁▁╱  ▁▁▁▁▁▁ ╱    ╲  ╲╱│     ▁▁▁╱│     ▁▁▁╱ '\n"   
printf "${BASE_T}195m ┃ ╱    ^   ╱       ╲ ╱▁▁▁▁▁╱ ╲     ╲▁▁▁│    │    │    │     \n"   
printf "${BASE_T}195m ┃ ╲▁▁▁▁   │╲▁▁▁▁▁▁▁ ╲         ╲▁▁▁▁▁▁  ╱▁▁▁▁│    │▁▁▁▁│     \n"   
printf "${BASE_T}159m ┃ ◺    │▁▁│        ╲╱                ╲╱                     \n"
printf "${BASE_T}159m ┗━━━━━━━━━━━━━━━━━━━━[${ITALIC}Tester Made with ♥  by @cjackows${R}${BASE_T}159m]${R}" ; echo ;

TEST_INDEX="NO ARGUMENTS TEST"
printf "${BLUE}━━━=[ Test 00 ]=━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━=-${E}"
printf "${BASE_B}${BLUE}${BOLD} ${TEST_INDEX}\n${E}"

TEST=$(./btc 2>&1)
if [ "$TEST" != "" ]; then
    printf "${GREEN} ${TEST_INDEX} PASSED${E}"
else
    printf "${KO} ${TEST_INDEX} ${E}"
fi

TEST_INDEX="EMPTY FILE TEST "
printf "${E}${BLUE}━━━=[ Test 01 ]=━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━=-${E}"
printf "${BASE_B}${BLUE}${BOLD} ${TEST_INDEX}\n${E}"

touch empty.txt
TEST=$(./btc empty.txt 2>&1)

if [ "$TEST" != "" ]; then
    printf "${GREEN} ${TEST_INDEX} PASSED${E}"
else
    printf "${KO} ${TEST_INDEX} ${E}"
fi
rm -f empty.txt

TEST_INDEX="INVALID INPUT NEGATIVE NUMBER TEST"
printf "${E}${BLUE}━━━=[ Test 02 ]=━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━=-${E}"
printf "${BASE_B}${BLUE}${BOLD} ${TEST_INDEX}\n${E}"

TEST=$(./btc test/negative-num.txt 2>&1)

if [ "$TEST" != "" ]; then
    printf "${GREEN} ${TEST_INDEX} PASSED${E}"
else
    printf "${KO} ${TEST_INDEX} ${E}"
fi


TEST_INDEX="INVALID INPUT NUMBER RANGE"
printf "${E}${BLUE}━━━=[ Test 03 ]=━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━=-${E}"
printf "${BASE_B}${BLUE}${BOLD} ${TEST_INDEX}\n${E}"
touch toolarge.txt
echo "date | value
2017-02-19 | 1050.87
2017-02-22 | 1130.01
2017-02-25 | 1150.37
2017-02-28 | 1190.89" > toolarge.txt
./btc toolarge.txt
rm -f toolarge.txt

TEST_INDEX="INVALID INPUT DATE"
printf "${E}${BLUE}━━━=[ Test 04 ]=━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━=-${E}"
printf "${BASE_B}${BLUE}${BOLD} ${TEST_INDEX}\n${E}"
touch invalid_date.txt
echo "date | value
2017-13-19 | 50.87
2017-02-29 | 130.01
2017-06-31 | 150.37
2017-55-55 | 190.89" > invalid_date.txt
./btc invalid_date.txt
rm -f invalid_date.txt


TEST_INDEX="TESTS FROM SUBJECT PDF"
printf "${E}${BLUE}━━━=[ Test 05 ]=━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━=-${E}"
printf "${BASE_B}${BLUE}${BOLD} ${TEST_INDEX}\n${E}"

PROGRAM_COMMAND="./btc test/pdf-input.txt"
COMPARE_FILE="./test/pdf-output.txt"

printf "${INFO} Should output 3 errors ${E}"
${PROGRAM_COMMAND} > tmp_output.txt

DIFF=$(diff --color=always -p tmp_output.txt ${COMPARE_FILE})

if [ "$DIFF" != "" ]; then
	printf "${KO} ${TEST_INDEX} ${E}"
	printf "${SYS_MSG} Differences found: ${E}"
    printf "$DIFF"
else
    printf "${GREEN} ${TEST_INDEX} PASSED${E}"
fi

rm tmp_output.txt

TEST_INDEX="LARGER INPUT TEST"
printf "${E}${BLUE}━━━=[ Test 06 ]=━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━=-${E}"
printf "${BASE_B}${BLUE}${BOLD} ${TEST_INDEX}\n${E}"

touch input.txt
echo "date | value
2011-01-03 | 3
2011-01-03 | 2
2011-01-03 | 1
2011-01-03 | 1.2
2011-01-09 | 1
2012-01-11 | -1
2001-42-42
2012-01-11 | 1
2012-01-11 | 2147483648
2012-03-01 | 2
2013-03-01 | 2
12312312 || 12312412
| 2010-05-01 2
|||||||||||||||||
|
1
5555555555555555555555555555555555555555555555555555555
55555555555555555555555555 | 55555555555555555555555555555
55555555555555555555555555 | j
2010-05-01 | d
2011-01-32 | 42
2012-02-29 | 42
2013-02-29 | 42
2011-01-09 |42
2011-01-09| 42
2-011-01-09 | 42
2-01101-09 | 42
2011-1.3-09 | 42
2011-12-0t | 42
2011-12-00 | 42
2011-00-05 | 42
0000-12-05 | 42
2012-20-05 | 42
2040-12-05 | 42
0010-12-05 | 42
0001-01-01 | 42
2012-12-05 | 1000.0
2012-12-05 | 1001
2012-12-05 | 1000.1
2012-12-05 | 10.00.1" > input.txt
./btc input.txt
rm -f input.txt
