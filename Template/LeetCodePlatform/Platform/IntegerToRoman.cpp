#include "IntegerToRoman.h"

static char* intToRoman(int num);

void IntegerToRoman_Main(void)
{
    char* result = intToRoman(1994);
}

static char* intToRoman(int num) {
    static char result[20];
    const char romanTable[7] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
    int element = 0;
    int index = 0;

    if (num == 0) return result;

    int count = 0;
    if (num < 0) num = -num;

    while (num > 0) {
        element = num % 10;

        if (element < 4)
        {
            for (index = index; index < element; index++)
            {
                result[index] = romanTable[count];
            }
        }
        else if (element == 4)
        {
            for (index = index; index < 2; index++)
            {
                result[index] = romanTable[index];
            }
        }
        else if (element == 5)
        {
            result[index] = romanTable[count+1];
			index++;
        }
        else if (element < 9)
        {
            result[index] = romanTable[count + 1];
            for (index = 1; index < element - 4 + 1; index++)
            {
                result[index] = romanTable[count];
            }
        }
		else if (element == 9)
		{
			result[index] = romanTable[count];
			result[index + 1] = romanTable[count + 2];
            index += 2;
		}
        num /= 10;
        count++;
    }
	return result;
}