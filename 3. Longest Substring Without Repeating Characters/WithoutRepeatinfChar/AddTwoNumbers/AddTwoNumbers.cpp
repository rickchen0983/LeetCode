#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned int ch; // 字元碼點
    int pos;         // 最後出現的位置
} CharPos;

// 在 map 中找字元 ch 的索引，如果不存在返回 -1
int find(CharPos* map, int size, unsigned int ch) {
    for (int i = 0; i < size; i++) {
        if (map[i].ch == ch) return i;
    }
    return -1;
}

int lengthOfLongestSubstring(const char* s) {
    int maxLen = 0;
    int start = 0; // 窗口起點

    int mapCapacity = 16; // 動態陣列初始容量
    int mapSize = 0;
    CharPos* map = (CharPos*)malloc(mapCapacity * sizeof(CharPos));

    for (int i = 0; s[i] != '\0'; i++) {
        unsigned char c = s[i];
        int idx = find(map, mapSize, c);

        if (idx != -1 && map[idx].pos >= start) {
            start = map[idx].pos + 1; // 更新窗口起點
        }

        // 更新 map
        if (idx != -1) {
            map[idx].pos = i;
        }
        else {
            // 動態擴容
            if (mapSize >= mapCapacity) {
                mapCapacity *= 2;
                map = (CharPos*)realloc(map, mapCapacity * sizeof(CharPos));
            }
            map[mapSize].ch = c;
            map[mapSize].pos = i;
            mapSize++;
        }

        int len = i - start + 1;
        if (len > maxLen) maxLen = len;
    }

    free(map);
    return maxLen;
}

int main() {
    char s[] = "abcabcbb";
    int result = lengthOfLongestSubstring(s);
    printf("Longest substring length: %d\n", result); // 3

    // 可以再測試其他字串
    char s2[] = "bbbbb";
    printf("Longest substring length: %d\n", lengthOfLongestSubstring(s2)); // 1

    char s3[] = "pwwkew";
    printf("Longest substring length: %d\n", lengthOfLongestSubstring(s3)); // 3

    return 0;
}
