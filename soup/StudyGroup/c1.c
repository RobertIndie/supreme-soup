//电子学习小组考核题答案
#include <stdio.h>
const int IS_STARTED = 1 << 0;
const int START_WITH_CHINESE = 1 << 1;
const int END_WITH_NUMBER = 1 << 2;
const int HAS_NUMBER = 1 << 3;
const int HAS_ENGLISH = 1 << 4;
int main()
{
	char buffer[200];
	scanf("%s", buffer);
	int i = 0, state = 0, start_i = -1;
	while (1) {
		char p = buffer[i];
		if (p == ';' || p=='\0') {
			if (buffer[i - 1] >= 48 && buffer[i - 1] < 58) state |= END_WITH_NUMBER;
#define JUDGE(flag) ((state & flag) != 0)
#define PRINT(str) {printf(str);for(int j = start_i;j<i;j++)putchar(buffer[j]);putchar('\n');}
#define NEXT {i++;continue;}
			if (JUDGE(START_WITH_CHINESE) && !JUDGE(END_WITH_NUMBER) && !JUDGE(HAS_NUMBER) && !JUDGE(HAS_ENGLISH)) PRINT("NAME:")
			if (JUDGE(START_WITH_CHINESE) && JUDGE(END_WITH_NUMBER) && !JUDGE(HAS_ENGLISH)) PRINT("GRADE:")
			if (!JUDGE(START_WITH_CHINESE) && !JUDGE(HAS_ENGLISH) && JUDGE(HAS_NUMBER) && (i - start_i) == 11) PRINT("PHONE:")
			if (!JUDGE(START_WITH_CHINESE) && !JUDGE(HAS_ENGLISH) && JUDGE(HAS_NUMBER) && (i - start_i) < 11) PRINT("QQ:")
			if (JUDGE(HAS_ENGLISH)) PRINT("WECHAT:")
			if (p == '\0')break;
			state = 0;
			start_i = -1;
			NEXT
		}
		if (p == ' ') NEXT
		if (start_i==-1)start_i = i;
		if ((state&IS_STARTED) == 0 && p < 0) (state |= IS_STARTED) && (state |= START_WITH_CHINESE);
		if (p >= 48 && p < 58) state |= HAS_NUMBER;
		if ((p >= 65 && p < 91) || (p >= 97 && p < 123)) state |= HAS_ENGLISH;
		NEXT
	}
}