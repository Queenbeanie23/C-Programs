#include "pch.h"
using namespace std;


string rverseStr(string& strr)

{
    int n = strr.length();

    for (int i = 0; i < n / 2; i++)


        swap(strr[i], strr[n - i - 1]);

    return strr;

}

TEST(StringTest, rverseStr)
{
    string input = "Hello";
    string output = "olleH";
    rverseStr(input);
    EXPECT_EQ(input, output);

    string input1 = "";
    string output1 = "";
    rverseStr(input1);
    EXPECT_EQ(input1, output1);

    string input3 = "cat";
    string output3 = "tac";
    rverseStr(input3);
    EXPECT_EQ(input3, output3);

    string input2 = "Sabine";
    string output2 = "enibaS";
    rverseStr(input2);
    EXPECT_EQ(input2, output2);



}
void delete_shift(int arr[], int ARRAY_SIZE, int elem) {



    for (int j = elem; j < (ARRAY_SIZE - 1); j++){
    
        arr[j] = arr[j + 1];
    }


}

TEST(DELETE_SHIFT, delete_shift) {



    int foo[5] = { 16, 2, 77, 40, 12071 };
    int foo1[5] = { 16,2,40,12071,};

    delete_shift(foo, 6, 2);

    EXPECT_EQ(  foo[5], foo1[5]);



}
int main() {

    int index;

    int meow[10] = {1,2,3,4,5,6,7,8,9,10};
  

    for (int i = 0; i < 10; ++i) {
        cout << meow[i] << "  ";
    }
    cout << " type a index you want you delete from an array:  ";
    cin >> index;

    delete_shift(meow, 10, index);

    for (int i = 0; i < 10; ++i) {
        cout << meow[i] << "  ";
    }
    return 0;



}