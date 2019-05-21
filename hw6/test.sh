if [ -f css ]; then
    rm css
fi
g++ -std=c++11 *.cpp -o css
if [ ! -f css ]; then
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
./css "input=input1.txt;output=output1.txt" 1>1.stdcout 2>1.stderr
diff -iEBwu ans1.txt output1.txt > 1.diff

if [ $? -ne 0 ]; then
    echo -e "Test case 1 (#1 from Website testcases) \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 1 (#1 from Website testcases) \033[1;92mPASSED.\033[0m"
    rm -f 1.diff
fi

# For test case 2
./css "input=input2.txt;output=output2.txt" 1>1.stdcout 2>1.stderr
diff -iEBwu ans2.txt output2.txt > 2.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 2 (#2 from Website testcases) \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 2 (#2 from Website testcases) \033[1;92mPASSED.\033[0m"
    rm -f 2.diff
fi

# For test case 3
./css "input=input3.txt;output=output3.txt" 1>1.stdcout 2>1.stderr
diff -iEBwu ans3.txt output3.txt > 2.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 3 (#3 from Website testcases) \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 3 (#3 from Website testcases) \033[1;92mPASSED.\033[0m"
    rm -f 2.diff
fi

# For test case 4
./css "input=input4.txt;output=output4.txt" 1>1.stdcout 2>1.stderr
diff -iEBwu ans4.txt output4.txt > 2.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 4 \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 4 \033[1;92mPASSED.\033[0m"
    rm -f 2.diff
fi

# For test case 5
./css "input=input5.txt;output=output5.txt" 1>1.stdcout 2>1.stderr
diff -iEBwu ans5.txt output5.txt > 2.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 5 \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 5 \033[1;92mPASSED.\033[0m"
    rm -f 2.diff
fi

# For test case 6
./css "input=input6.txt;output=output6.txt" 1>1.stdcout 2>1.stderr
diff -iEBwu ans6.txt output6.txt > 2.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 6 \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 6 \033[1;92mPASSED.\033[0m"
    rm -f 2.diff
fi
# For test case 7
./css "input=input7.txt;output=output7.txt" 1>1.stdcout 2>1.stderr
diff -iEBwu ans7.txt output7.txt > 2.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 7 \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 7 \033[1;92mPASSED.\033[0m"
    rm -f 2.diff
fi

# For test case 8
./css "input=input8.txt;output=output8.txt" 1>1.stdcout 2>1.stderr
diff -iEBwu ans8.txt output8.txt > 2.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 8 \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 8 \033[1;92mPASSED.\033[0m"
    rm -f 2.diff
fi

echo -e "\033[1;92m9 and 10 are empty incase you want to make your own test cases.\033[0m"

#For test case 9
./css "input=input9.txt;output=output9.txt" 1>1.stdcout 2>1.stderr
diff -iEBwu ans9.txt output9.txt > 2.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 9 *Empty* \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 9 *Empty* \033[1;92mPASSED.\033[0m"
    rm -f 2.diff
fi

# For test case 10
./css "input=input10.txt;output=output10.txt" 1>1.stdcout 2>1.stderr
diff -iEBwu ans10.txt output10.txt > 2.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 10 *Empty* \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 10 *Empty* \033[1;92mPASSED.\033[0m"
    rm -f 2.diff
fi