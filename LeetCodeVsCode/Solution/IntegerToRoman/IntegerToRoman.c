#include "IntegerToRoman.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *intToRoman(int num);
void IntegerToRoman_Main(void)
{
    int number = 1994;
    char *romanNumeral = intToRoman(number);
    printf("The Roman numeral for %d is %s\n", number, romanNumeral);
}

char *intToRoman(int num)
{
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char *symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    // 使用 static，記憶體會配置在全域區，直到程式結束才釋放
    static char roman[20];
    memset(roman, 0, sizeof(roman)); // 每次呼叫前先清空內容

    int i = 0;
    int pos = 0; // 改用索引填入，效率比 strcat 高
    while (num > 0)
    {
        while (num >= values[i])
        {
            // 將符號拷貝進陣列
            char *s = symbols[i];
            while (*s)
            {
                roman[pos++] = *s++;
            }
            num -= values[i];
        }
        i++;
    }
    roman[pos] = '\0'; // 結尾補上空字元
    return roman;
}