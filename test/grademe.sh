#!/bin/bash

RESET="\033[0m"
BLACK="\033[30m"
RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
BLUE="\033[34m"
MAGENTA="\033[35m"
CYAN="\033[36m"
WHITE="\033[37m"
BOLDBLACK="\033[1m\033[30m"
BOLDRED="\033[1m\033[31m"
BOLDGREEN="\033[1m\033[32m"
BOLDYELLOW="\033[1m\033[33m"
BOLDBLUE="\033[1m\033[34m"
BOLDMAGENTA="\033[1m\033[35m"
BOLDCYAN="\033[1m\033[36m"
BOLDWHITE="\033[1m\033[37m"

printf "$BOLDYELLOW TEST RESULT $RESET \n"

cd ..
touch minish_error.txt minish_result.txt bash_error.txt bash_result.txt
./minishell < test/testcase.sh 2> minish_error.txt > minish_result.txt
bash < test/testcase.sh 2> bassh_error.txt > bash_result.txt
diff minish_result.txt bash_result.txt
diff minish_error.txt bash_error.txt
rm *.txt
