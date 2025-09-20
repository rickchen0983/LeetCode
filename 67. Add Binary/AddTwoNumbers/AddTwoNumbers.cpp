#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* addBinary(char* a, char* b) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    int maxLen = lenA > lenB ? lenA : lenB;
    char* result = (char*)malloc(maxLen + 2); // +1 for possible carry, +1 for '\0'
    result[maxLen + 1] = '\0';

    int i = lenA - 1, j = lenB - 1, k = maxLen, carry = 0;

    while (k >= 0) {
        int bitA = i >= 0 ? a[i--] - '0' : 0;
        int bitB = j >= 0 ? b[j--] - '0' : 0;
        int sum = bitA + bitB + carry;
        result[k--] = (sum % 2) + '0';
        carry = sum / 2;
    }

    // 如果最高位有進位
    if (result[0] == '0') {
        memmove(result, result + 1, maxLen + 1);
    }

    return result;
}
int main() {
    char a[] = "1010";
    char b[] = "1011";
    char* sum = addBinary(a, b);
    printf("Sum: %s\n", sum);
    free(sum); // 記得釋放記憶體
    return 0;
}
