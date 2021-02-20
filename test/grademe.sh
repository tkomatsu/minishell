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

cp ../minishell .
mkdir ./log
touch ./log/minish_error.txt ./log/minish_result.txt ./log/bash_error.txt ./log/bash_result.txt
./minishell < ./testcase.sh 2> ./log/minish_error.txt > ./log/minish_result.txt
bash < ./testcase.sh 2> ./log/bassh_error.txt > ./log/bash_result.txt
printf "$GREEN STDOUT $RESET\n"
diff ./log/minish_result.txt ./log/bash_result.txt
printf "$RED STDERR $RESET\n"
diff ./log/minish_error.txt ./log/bash_error.txt
rm -r ./log ./minishell
