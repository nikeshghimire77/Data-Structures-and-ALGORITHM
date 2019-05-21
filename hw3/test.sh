if [ -f database ]; then
    rm database
fi
g++ -std=c++11 *.cpp -o database
if [ ! -f database ]; then
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
./database "input=input11.txt;output=output11.txt;command=command11.txt" 1>1.stdcout 2>1.stderr
diff -iEBwu ans11.txt output11.txt > 1.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 1 - Sort ID \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 1 - Sort ID \033[1;92mPASSED.\033[0m"
    rm -f 1.diff
fi
# For test case 2
./database "input=input12.txt;output=output12.txt;command=command12.txt" 1>1.stdcout 2>1.stderr
diff -iEBwu ans12.txt output12.txt > 1.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 2 - Sort first name \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 2 - Sort first name \033[1;92mPASSED.\033[0m"
    rm -f 1.diff
fi
# For test case 3
./database "input=input13.txt;output=output13.txt;command=command13.txt" 1>1.stdcout 2>1.stderr
diff -iEBwu ans13.txt output13.txt > 1.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 3 - Sort last name \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 3 - Sort last name \033[1;92mPASSED.\033[0m"
    rm -f 1.diff
fi
# For test case 4
./database "input=input14.txt;output=output14.txt;command=command14.txt" 1>1.stdcout 2>1.stderr
diff -iEBwu ans14.txt output14.txt > 1.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 4 - Sort DOB \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 4 - Sort DOB \033[1;92mPASSED.\033[0m"
    rm -f 1.diff
fi
# For test case 5
./database "input=input15.txt;output=output15.txt;command=command15.txt" 1>1.stdcout 2>1.stderr
diff -iEBwu ans15.txt output15.txt > 1.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 5 - Sort years worked \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 5 - Sort years worked \033[1;92mPASSED.\033[0m"
    rm -f 1.diff
fi
# For test case 6
./database "input=input16.txt;output=output16.txt;command=command16.txt" 1>1.stdcout 2>1.stderr
diff -iEBwu ans16.txt output16.txt > 1.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 6 - Sort salary \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 6 - Sort salary \033[1;92mPASSED.\033[0m"
    rm -f 1.diff
fi
# For test case 7
./database "input=input17.txt;output=output17.txt;command=command17.txt" 1>1.stdcout 2>1.stderr
diff -iEBwu ans17.txt output17.txt > 1.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 7 - Sort position \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 7 - Sort position \033[1;92mPASSED.\033[0m"
    rm -f 1.diff
fi
# For test case 8
./database "input=input18.txt;output=output18.txt;command=command18.txt" 1>1.stdcout 2>1.stderr
diff -iEBwu ans18.txt output18.txt > 1.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 8 - Add at beginning \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 8 - Add at beginning \033[1;92mPASSED.\033[0m"
    rm -f 1.diff
fi
# For test case 9
./database "input=input19.txt;output=output19.txt;command=command19.txt" 1>1.stdcout 2>1.stderr
diff -iEBwu ans19.txt output19.txt > 1.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 9 - Add at End \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 9 - Add at End \033[1;92mPASSED.\033[0m"
    rm -f 1.diff
fi
# For test case 10
./database "input=input20.txt;output=output20.txt;command=command20.txt" 1>1.stdcout 2>1.stderr
diff -iEBwu ans20.txt output20.txt > 1.diff
if [ $? -ne 0 ]; then
      echo -e "Test case 10 - Add after \033[1;91mFAILED.\033[0m"
else
      echo -e "Test case 10 - Add after \033[1;92mPASSED.\033[0m"
    rm -f 1.diff
fi
# For test case 11
./database "input=input21.txt;output=output21.txt;command=command21.txt" 1>1.stdcout 2>1.stderr
diff -iEBwu ans21.txt output21.txt > 1.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 11 - Add before \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 11 - Add before \033[1;92mPASSED.\033[0m"
    rm -f 1.diff
fi
# For test case 12
./database "input=input22.txt;output=output22.txt;command=command22.txt" 1>1.stdcout 2>1.stderr
diff -iEBwu ans22.txt output22.txt > 1.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 12 - Delete id \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 12 - Delete id \033[1;92mPASSED.\033[0m"
    rm -f 1.diff
fi
# For test case 13
./database "input=input23.txt;output=output23.txt;command=command23.txt" 1>1.stdcout 2>1.stderr
diff -iEBwu ans23.txt output23.txt > 1.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 13 - Delete index to index \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 13 - Delete index to index \033[1;92mPASSED.\033[0m"
    rm -f 1.diff
fi
# For test case 14
./database "input=input24.txt;output=output24.txt;command=command24.txt" 1>1.stdcout 2>1.stderr
diff -iEBwu ans24.txt output24.txt > 1.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 14 - Delete at beginning \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 14 - Delete at beginning \033[1;92mPASSED.\033[0m"
    rm -f 1.diff
fi
# For test case 15
./database "input=input25.txt;output=output25.txt;command=command25.txt" 1>1.stdcout 2>1.stderr
diff -iEBwu ans25.txt output25.txt > 1.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 15 - Delete Delete at end \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 15 - Delete Delete at end \033[1;92mPASSED.\033[0m"
    rm -f 1.diff
fi
# For test case 16
./database "input=input26.txt;output=output26.txt;command=command26.txt" 1>1.stdcout 2>1.stderr
diff -iEBwu ans26.txt output26.txt > 1.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 16 test 1 from rizk's website \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 16 test 1 from rizk's website \033[1;92mPASSED.\033[0m"
    rm -f 1.diff
fi
# For test case 17
./database "input=input27.txt;output=output27.txt;command=command27.txt" 1>1.stdcout 2>1.stderr
diff -iEBwu ans27.txt output27.txt > 1.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 17 test 2 from rizk's website \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 17 test 2 from rizk's website \033[1;92mPASSED.\033[0m"
    rm -f 1.diff
fi
# For test case 18
./database "input=input28.txt;output=output28.txt;command=command28.txt" 1>1.stdcout 2>1.stderr
diff -iEBwu ans28.txt output28.txt > 1.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 18 test 3 from rizk's website \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 18 test 3 from rizk's website \033[1;92mPASSED.\033[0m"
    rm -f 1.diff
fi
# For test case 19
./database "input=input29.txt;output=output29.txt;command=command29.txt" 1>1.stdcout 2>1.stderr
diff -iEBwu ans29.txt output29.txt > 1.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 19 EVERYTHING ALL AT ONCE \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 19 EVERYTHING ALL AT ONCE \033[1;92mPASSED.\033[0m"
    rm -f 1.diff
fi
# For test case 20
./database "input=input30.txt;output=output30.txt;command=command30.txt" 1>1.stdcout 2>1.stderr
diff -iEBwu ans30.txt output30.txt > 1.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 20 Test Case 1 from HW3 PDF \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 20 Test Case 1 from HW3 PDF \033[1;92mPASSED.\033[0m"
    rm -f 1.diff
fi
# For test case 21
./database "input=input31.txt;output=output31.txt;command=command31.txt" 1>1.stdcout 2>1.stderr
diff -iEBwu ans31.txt output31.txt > 1.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 21 Test Case 2 from HW3 PDF \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 21 Test Case 2 from HW3 PDF \033[1;92mPASSED.\033[0m"
    rm -f 1.diff
fi
# For test case 22
./database "input=input32.txt;output=output32.txt;command=command32.txt" 1>1.stdcout 2>1.stderr
diff -iEBwu ans32.txt output32.txt > 1.diff
if [ $? -ne 0 ]; then
    echo -e "Test case 22 Test Case 3 from HW3 PDF \033[1;91mFAILED.\033[0m"
else
    echo -e "Test case 22 Test Case 3 from HW3 PDF \033[1;92mPASSED.\033[0m"
    rm -f 1.diff
fi