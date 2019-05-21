#Compile the code
# if the file densemult exits then remove it
if [ -f sort ]; then
    rm sort
fi
g++ -std=c++11 *.cpp -o sort
# if the file densemult does not exit then exit the test
if [ ! -f sort ]; then
    echo -e "\033[1;91mCompile FAILED.\033[0m"
    exit
fi
# clean
if [ -f *.out ]; then
    rm *.out
fi
if [ -f *.stderr ]; then
    rm *.stderr
fi
if [ -f *.stdcout ]; then
    rm *.stdcout
fi
#rm *.out *.stderr *.stdcout
# For test case 1
# input 1.txt and output 1.out
./sort "input=input21.txt;output=output1.txt;sort=sort21.txt" 1>1.stdcout 2>1.stderr
diff -iEBwu ans21.txt output1.txt > 1.diff
if [ $? -ne 0 ]; then
    # display "test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case 1    \033[1;91mFAILED.\033[0m"
else
    # display "test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e "Test case 1    \033[1;92mPASSED.\033[0m"
    # remove the file 1.diff
    rm -f 1.diff
fi
# For test case 2
./sort "input=input22.txt;output=output2.txt;sort=sort22.txt" 1>1.stdcout 2>1.stderr
diff -iEBwu ans22.txt output2.txt > 2.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 2    \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 2    \033[1;92mPASSED.\033[0m"
    rm -f 1.diff
fi
# For test case 3
./sort "input=input23.txt;output=output3.txt;sort=sort23.txt" 1>1.stdcout 2>1.stderr
diff -iEBwu ans23.txt output3.txt > 1.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 3    \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 3    \033[1;92mPASSED.\033[0m"
    rm -f 1.diff
fi

# For test case 4
./sort "input=input24.txt;output=output4.txt;sort=sort24.txt" 1>1.stdcout 2>1.stderr
diff -iEBwu ans24.txt output4.txt > 1.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 4    \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 4    \033[1;92mPASSED.\033[0m"
    rm -f 1.diff
fi

# For test case 5
./sort "input=input25.txt;output=output5.txt;sort=sort25.txt" 1>1.stdcout 2>1.stderr
diff -iEBwu ans25.txt output5.txt > 1.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 5    \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 5    \033[1;92mPASSED.\033[0m"
    rm -f 1.diff
fi

# For test case 6
./sort "input=input26.txt;output=output6.txt;sort=sort26.txt" 1>1.stdcout 2>1.stderr
diff -iEBwu ans26.txt output6.txt > 1.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 6    \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 6    \033[1;92mPASSED.\033[0m"
    rm -f 1.diff
fi


# For test case 7
./sort "input=input27.txt;output=output7.txt;sort=sort27.txt" 1>1.stdcout 2>1.stderr
diff -iEBwu ans27.txt output7.txt > 1.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 7    \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 7    \033[1;92mPASSED.\033[0m"
    rm -f 1.diff
fi


# For test case 8
./sort "input=input28.txt;output=output8.txt;sort=sort28.txt" 1>1.stdcout 2>1.stderr
diff -iEBwu ans28.txt output8.txt > 1.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 8    \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 8    \033[1;92mPASSED.\033[0m"
    rm -f 1.diff
fi


# For test case 9
./sort "input=input29.txt;output=output9.txt;sort=sort29.txt" 1>1.stdcout 2>1.stderr
diff -iEBwu ans29.txt output9.txt > 1.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 9    \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 9    \033[1;92mPASSED.\033[0m"
    rm -f 1.diff
fi







