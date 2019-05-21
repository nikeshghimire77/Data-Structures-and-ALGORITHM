#Compile the code
# if the file densemult exits then remove it
if [ -f evalexpr ]; then
    rm evalexpr
fi
g++ -std=c++11 *.cpp -o evalexpr
# if the file densemult does not exit then exit the test
if [ ! -f evalexpr ]; then
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
# For test case 1
./evalexpr "input=input51.txt;output=output51.txt" 1>1.stdcout 2>1.stderr
diff -iEBwu ans51.txt output51.txt > 1.diff
if [ $? -ne 0 ]; then
     echo -e "Test case 1 Answer should be Yes \033[1;91mFAILED.\033[0m"
else
     echo -e "Test case 1 Answer should be Yes \033[1;92mPASSED.\033[0m"
     rm -f 1.diff
fi
# For test case 2
./evalexpr "input=input52.txt;output=output52.txt" 1>2.stdcout 2>2.stderr
diff -iEBwu ans52.txt output52.txt > 2.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 2 Answer should be No \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 2 Answer should be No \033[1;92mPASSED.\033[0m"
    rm -f 2.diff
fi
# For test case 3
./evalexpr "input=input53.txt;output=output53.txt" 1>3.stdcout 2>3.stderr
diff -iEBwu ans53.txt output53.txt > 1.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 3 Answer should be error \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 3 Answer should be error \033[1;92mPASSED.\033[0m"
    rm -f 3.diff
fi
# For test case 4
./evalexpr "input=input54.txt;output=output54.txt" 1>4.stdcout 2>4.stderr
diff -iEBwu ans54.txt output54.txt > 1.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 4 Answer should be Yes \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 4 Answer should be Yes \033[1;92mPASSED.\033[0m"
    rm -f 4.diff
fi
# For test case 5
./evalexpr "input=input55.txt;output=output55.txt" 1>5.stdcout 2>5.stderr
diff -iEBwu ans55.txt output55.txt > 1.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 5 Answer should be No \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 5 Answer should be No \033[1;92mPASSED.\033[0m"
    rm -f 5.diff
fi
# For test case 6
./evalexpr "input=input56.txt;output=output56.txt" 1>6.stdcout 2>6.stderr
diff -iEBwu ans56.txt output56.txt > 1.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 6 Answer should be No \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 6 Answer should be No \033[1;92mPASSED.\033[0m"
    rm -f 6.diff
fi
# For test case 7
./evalexpr "input=input57.txt;output=output57.txt" 1>7.stdcout 2>7.stderr
diff -iEBwu ans57.txt output57.txt > 1.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 7 Answer should be Yes \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 7 Answer should be Yes \033[1;92mPASSED.\033[0m"
    rm -f 7.diff
fi
# For test case 8
./evalexpr "input=input58.txt;output=output58.txt" 1>8.stdcout 2>8.stderr
diff -iEBwu ans58.txt output58.txt > 1.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 8 Answer should be Yes \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 8 Answer should be Yes \033[1;92mPASSED.\033[0m"
    rm -f 8.diff
fi
# For test case 9
./evalexpr "input=input59.txt;output=output59.txt" 1>9.stdcout 2>.stderr
diff -iEBwu ans59.txt output59.txt > 1.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 9 Answer should be Error at 2 \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 9 Answer should be Error at 2 \033[1;92mPASSED.\033[0m"
    rm -f 9.diff
fi