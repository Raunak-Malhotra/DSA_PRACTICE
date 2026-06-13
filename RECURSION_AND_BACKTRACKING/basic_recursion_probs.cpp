#include <iostream>
#include <vector>
#include <string>
using namespace std;

// THIS FILE CONTAINS BASIC CPP QUESTIONS -
// 1. Factorial
// 2. Power Function
// 3. Generate Subsequences
// 4. Generate Permutations

int fact(int number) {

    if(number == 0 || number == 1)
        return 1;

    return number * fact(number - 1);
}



long long power(long long base, long long exponent) {

    if(exponent == 0)
        return 1;

    return base * power(base, exponent - 1);
}



void Subsequences(
        string inputString,
        string currSubsequence,
        int currentIndex)
{
    if(currentIndex == inputString.length()) {

        cout << currSubsequence << endl;
        return;
    }

    Subsequences(
        inputString,
        currSubsequence,
        currentIndex + 1);

    Subsequences(
        inputString,
        currSubsequence + inputString[currentIndex],
        currentIndex + 1);
}



void generatePermutations(
        string& inputString,
        int currentIndex)
{
    if(currentIndex == inputString.length()) {

        cout << inputString << endl;
        return;
    }

    for(int swapIndex=currentIndex;
        swapIndex<inputString.length();
        swapIndex++)
    {
        swap(
            inputString[currentIndex],
            inputString[swapIndex]);

        generatePermutations(
            inputString,
            currentIndex + 1);

        swap(
            inputString[currentIndex],
            inputString[swapIndex]);
    }
}

int main() {

    cout << fact(5) << endl;

    cout << power(2,10) << endl;

    Subsequences("abc","",0);

    string text = "abc";
    generatePermutations(text,0);

    return 0;
}