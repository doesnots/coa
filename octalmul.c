#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num1, num2;
    cout << "Enter two number to get binary and octal addition and multiplication :-\n";
    cin >> num1 >> num2;
    int temp1 = num1, temp2 = num2;
    int binary_bits = ((int)(log2(num1) + 1) >= (int)(log2(num2) + 1) ? (int)(log2(num1) + 1) : (int)(log2(num2) + 1));
    int bin1[binary_bits + 2], bin2[binary_bits + 2];
    // Storing binary value of two numbers in array
    for (int i = binary_bits + 1; i >= 0; i--)
    {
        bin1[i] = temp1 % 2;
        bin2[i] = temp2 % 2;
        temp1 /= 2;
        temp2 /= 2;
    }
    int add[binary_bits + 2], carry = 0;
    // Adding and storing in array
    for (int i = binary_bits + 1; i >= 0; i--)
    {
        add[i] = bin1[i] + bin2[i] + carry;
        if (add[i] >= 2)
        {
            carry = add[i] / 2;
            add[i] = add[i] % 2;
        }
        else
        {
            carry = 0;
        }
    }
    // Displaying value of addition
    cout << "Binary addition of no. " << num1 << " and " << num2 << " is :-\n";
    for (int i = 0; i <= binary_bits + 1; i++)
    {
        cout << add[i] << " ";
    }
    cout << endl;
    int mul[binary_bits + 2];
    // Multiplying bin1 num2 times and storing in mul array
    for (int j = 1; j <= num2; j++)
    {
        if (j == 1)
        {
            for (int i = 0; i <= binary_bits + 1; i++)
            {
                mul[i] = bin1[i];
            }
        }
        else
        {
            carry = 0;
            for (int i = binary_bits + 1; i >= 0; i--)
            {
                mul[i] += bin1[i];
                mul[i] += carry;
                if (mul[i] >= 2)
                {
                    carry = mul[i] / 2;
                    mul[i] = mul[i] % 2;
                }
                else
                {
                    carry = 0;
                }
            }
        }
    }
    // Displaying mul array
    for (int i = 0; i <= binary_bits + 1; i++)
    {
        cout << mul[i] << " ";
    }
    cout << endl;
    return 0;
}
