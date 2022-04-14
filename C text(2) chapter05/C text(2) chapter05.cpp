#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define _0508b


#ifdef _0500a
#define LEVEL_MIN 2
#define LEVEL_MAX 5
#define MAX_RECORD 10
int sleep(unsigned long x) {
	clock_t c1 = clock(), c2 = 0;

	do {
		if ((c2 = clock()) == (clock_t)-1)
			return 0;
	} while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);

	return 1;
}

int main(void) {
	int i = 0, j = 0, stage = 0, stage2 = 0;
	int level = 0;
	int success = 0;
	int point[MAX_RECORD] = { 0 };
	int retry = 0;
	clock_t start = 0, end = 0;

	srand((unsigned)time(NULL));

	printf("数値を記憶して1を加えた値を入力しましょう。\n");
	do {
		printf("挑戦するレベル (%d～%d) : ", LEVEL_MIN, LEVEL_MAX);
		scanf_s("%d", &level);
	} while (!(level >= LEVEL_MIN && level <= LEVEL_MAX));

	start = clock();
	do {
		int no[LEVEL_MAX];
		int x[LEVEL_MAX];
		int seikai = 0;

		printf("\n第%dステージ開始!!\n", stage + 1);
		sleep(1000);
		
		for (i = 0; i < level; i++) {
			no[i] = rand() % 90 + 10;
			printf("%d ", no[i]);
		}
		fflush(stdout);
		sleep(300 * level);
		printf("\r%*s\r", 4 * level, "");
		fflush(stdout);

		for (i = 0; i < level; i++) {
			printf("%d番目の数 : ", i + 1);
			scanf_s("%d", &x[i]);
		}

		for (i = 0; i < level; i++) {
			if (x[i] != no[i] + 1) {
				printf("× ");
			}
			else {
				printf("○ ");
				seikai++;
			}
		}
		putchar('\n');

		for (i = 0; i < level; i++) {
			printf("%2d ", no[i]);
		}

		printf(" … %d個正解です。\n", seikai);

		point[stage++ % MAX_RECORD] = seikai;
		success += seikai;

		printf("続けますか？ (Yes…1/No…0) : ");
		scanf_s("%d", &retry);
	} while (retry == 1);
	end = clock();

	printf("\n■□ 成績 □■\n");

	stage2 = stage - MAX_RECORD;
	if (stage2 < 0) {
		stage2 = 0;
	}

	for (i = level; i >= 1; i--) {
		for (j = stage2; j < stage; j++) {
			if (point[j % MAX_RECORD] >= i) {
				printf(" ★ ");
			}
			else {
				printf(" 　 ");
			}
		}
		putchar('\n');
	}
	for (i = 0; i < stage; i++) {
		printf("----");
	}
	putchar('\n')

	for (j = stage2; j < stage; j++) {
		printf(" %02d ", j + 1);
	}
	putchar('\n');

	printf("%d個中%d個正解しました。\n", level * stage, success);
	printf("%.1f秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}
#endif

#ifdef _0500b
#define LEVEL_MIN 2
#define LEVEL_MAX 6

int sleep(unsigned long x) {
	clock_t c1 = clock(), c2 = 0;

	do {
		if ((c2 = clock()) == (clock_t)-1) {
			return 0;
		}
	} while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
	return 1;
}
int main(void) {
	int i = 0, stage = 0;
	int max_stage = 0;
	int level = 0; 
	int success = 0;
	int* score;
	clock_t start = 0, end = 0;

	srand((unsigned)time(NULL));

	puts("プラスワントレーニング開始!!");
	puts("2桁の数値を記憶します。");
	puts("1を加えた値を入力してください。");

	do {
		printf("挑戦するレベル (%d～%d) : ", LEVEL_MIN, LEVEL_MAX);
		scanf_s("%d", &level);
	} while (!(level >= LEVEL_MIN && level <= LEVEL_MAX));

	do {
		printf("トレーニング回数 : ");
		scanf_s("%d", &max_stage);
	} while (max_stage <= 0);

	score = (int*)calloc(max_stage, sizeof(int));

	start = clock();
	for (stage = 0; stage < max_stage; stage++) {
		int no[LEVEL_MAX];
		int x[LEVEL_MAX];
		int seikai = 0;

		printf("\n第%dステージ開始!!\n", stage + 1);
		sleep(1000);

		for (i = 0; i < level; i++) {
			no[i] = rand() % 90 + 10;
			printf("%d ", no[i]);
		}
		fflush(stdout);
		sleep(300 * level);
		printf("\r%*s\r", 4 * level, "");
		fflush(stdout);

		for (i = 0; i < level; i++) {
			printf("%d番目の数 : ", i + 1);
			scanf_s("%d", &x[i]);
		}
		for (i = 0; i < level; i++) {
			if (x[i] != no[i] + 1) {
				printf("× ");
			}
			else {
				printf("○ ");
				seikai++;
			}
		}
		putchar('\n');

		for (i = 0; i < level; i++) {
			printf("%2d ", no[i]);
		}

		printf(" … %d個正解です。\n", seikai);
		score[stage] = seikai;
		success += seikai;
	}
	end = clock();

	printf("%d個中%d個正解しました。\n", level * max_stage, success);

	for (stage = 0; stage < max_stage; stage++) {
		printf("第%2dステージ : %d\n", stage + 1, score[stage]);
	}

	printf("%.1f秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);

	free(score);

	return 0;
}
#endif

#ifdef _0501a
#define MAX_STAGE 10
int sleep(unsigned long x) {
	clock_t c1 = clock(), c2 = 0;

	do {
		if ((c2 = clock()) == (clock_t)-1) {
			return 0;
		}
	} while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
	return 1;
}

int makeAns(int n) {
	int reverse = 0;
	while (n > 0) {
		reverse = reverse * 10 + n % 10;
		n /= 10;
	}
	return reverse;
}

int main(void) {
	int stage = 0;
	int success = 0;
	clock_t start = 0, end = 0;

	srand((unsigned)time(NULL));

	puts("4桁の数値を記憶しましょう。");
	puts("各桁を逆順にして答えてください。");

	start = clock();
	for (stage = 0; stage < MAX_STAGE; stage++) {
		int x = 0;
		int no = rand() % 9000 + 1000;

		sleep(500);

		printf("%d", no);
		fflush(stdout);
		sleep(750);

		printf("\r入力せよ : ");
		fflush(stdout);
		scanf_s("%d", &x);

		if (x != makeAns(no)) {
			printf("\a間違いです。\n");
		}
		else {
			printf("正解です。\n");
			success++;
		}
	}
	end = clock();

	printf("%d回中%d回正解しました。\n", MAX_STAGE, success);
	printf("%.1f秒かかりました\n", (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}
#endif

#ifdef _0501b
#define MAX_STAGE 10
int sleep(unsigned long x) {
	clock_t c1 = clock(), c2 = 0;

	do {
		if ((c2 = clock()) == (clock_t)-1) {
			return 0;
		}
	} while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
	return 1;
}

void makeAns(char* n) {
	int size = (int)strlen(n);
	int i, j;
	char tmp = { 0 };

	for (i = 0, j = size - 1; i < size / 2; i++, j--) {
		tmp = n[i];
		n[i] = n[j];
		n[j] = tmp;
	}
}

int main(void) {
	int stage = 0;
	int success = 0;
	clock_t start = 0, end = 0;

	srand((unsigned)time(NULL));

	puts("4桁の数値を記憶しましょう。");
	puts("各桁を逆順にして答えてください。");


	start = clock();
	for (stage = 0; stage < MAX_STAGE; stage++) {
		char no[5] = { 0 };
		char x[10] = { 0 };

		no[0] = '1' + rand() % 9;
		for (int i = 1; i < 4; i++) {
			no[i] = '0' + rand() % 10;
		}
		no[4] = '\0';

		sleep(500);

		printf("%s", no);
		fflush(stdout);
		sleep(750);

		printf("\r%*s\r入力せよ : ", 4, "");
		fflush(stdout);
		scanf_s("%s", &x, 10);

		makeAns(no);

		if (strcmp(no, x) != 0) {
			printf("\a間違いです。\n");
		}
		else {
			printf("正解です。\n");
			success++;
		}
	}
	end = clock();

	printf("%d回中%d回正解しました。\n", MAX_STAGE, success);
	printf("%.1f秒かかりました\n", (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}
#endif

#ifdef _0502a
#define MAX_STAGE 10
int sleep(unsigned long x) {
	clock_t c1 = clock(), c2 = 0;

	do {
		if ((c2 = clock()) == (clock_t)-1) {
			return 0;
		}
	} while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
	return 1;
}

int makeAns(int n, int d) {
	switch (d) {
	case 1: 
		n /= 1000; 
		return n;
	case 2:
		n -= n / 1000 * 1000;
		n /= 100;
		return n;
	case 3: 
		n -= n / 100 * 100;
		n /= 10;
		return n;
	case 4:
		n -= n / 10 * 10;
		return n;
	default: return -1;
	}
}

int main(void) {
	int stage = 0;
	int success = 0;
	clock_t start = 0, end = 0;

	srand((unsigned)time(NULL));

	puts("4桁の数値を記憶しましょう。");

	start = clock();
	for (stage = 0; stage < MAX_STAGE; stage++) {
		int x = 0;
		int no = rand() % 9000 + 1000;
		int digit = rand() % 4 + 1;

		sleep(500);

		printf("%d", no);
		fflush(stdout);
		sleep(750);

		printf("\r先頭から%d桁目の数は : ", digit);
		fflush(stdout);
		scanf_s("%d", &x);

		if (x != makeAns(no, digit)) {
			printf("\a間違いです。\n");
		}
		else {
			printf("正解です。\n");
			success++;
		}
	}
	end = clock();

	printf("%d回中%d回正解しました。\n", MAX_STAGE, success);
	printf("%.1f秒かかりました\n", (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}
#endif

#ifdef _0502b
#define MAX_STAGE 10
int sleep(unsigned long x) {
	clock_t c1 = clock(), c2 = 0;

	do {
		if ((c2 = clock()) == (clock_t)-1) {
			return 0;
		}
	} while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
	return 1;
}

void makeAns(char* n, int d) {
	n[0] = n[d - 1];
	n[1] = '\0';
}

int main(void) {
	int stage = 0;
	int success = 0;
	clock_t start = 0, end = 0;

	srand((unsigned)time(NULL));

	puts("4桁の数値を記憶しましょう。");

	start = clock();
	for (stage = 0; stage < MAX_STAGE; stage++) {
		char no[5] = { 0 };
		char x[10] = { 0 };
		int digit = rand() % 4 + 1;

		no[0] = '1' + rand() % 9;
		for (int i = 1; i < 4; i++) {
			no[i] = '0' + rand() % 10;
		}
		no[4] = '\0';

		sleep(500);

		printf("%s", no);
		fflush(stdout);
		sleep(750);

		printf("\r%*s\r先頭から%d桁目の数は : ", 4, "", digit);
		fflush(stdout);
		scanf_s("%s", &x, 10);

		makeAns(no, digit);

		if (strcmp(no, x) != 0) {
			printf("\a間違いです。\n");
		}
		else {
			printf("正解です。\n");
			success++;
		}
	}
	end = clock();

	printf("%d回中%d回正解しました。\n", MAX_STAGE, success);
	printf("%.1f秒かかりました\n", (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}
#endif

#ifdef _0503
#define MAX_STAGE 10
#define LEVEL_MIN 3
#define LEVEL_MAX 20

int sleep(unsigned long x) {
	clock_t c1 = clock(), c2 = 0;

	do {
		if ((c2 = clock()) == (clock_t)-1) {
			return 0;
		}
	} while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
	return 1;
}

void makeAns(char* n) {
	int size = (int)strlen(n);
	int i, j;
	char tmp = { 0 };

	for (i = 0, j = size - 1; i < size / 2; i++, j--) {
		tmp = n[i];
		n[i] = n[j];
		n[j] = tmp;
	}
}

int main(void) {
	int i = 0, stage = 0;
	int level = 0;
	int success = 0;
	clock_t start = 0, end = 0;
	const char str[] = "abcdefghijklmnopqrstuvwxyz";

	srand((unsigned)time(NULL));

	puts("英字記憶トレーニング");
	puts("逆順で回答してください。");

	do {
		printf("挑戦するレベル (%d～%d) : ", LEVEL_MIN, LEVEL_MAX);
		scanf_s("%d", &level);
	} while (!(level >= LEVEL_MIN && level <= LEVEL_MAX));

	printf("%d個の英字を記憶しましょう。\n", level);

	start = clock();
	for (stage = 0; stage < MAX_STAGE; stage++) {
		char mstr[LEVEL_MAX + 1];
		char x[LEVEL_MAX * 2];

		for (i = 0; i < level; i++) {
			mstr[i] = str[rand() % strlen(str)];
		}
		mstr[level] = '\0';

		sleep(500);

		printf("%s", mstr);
		fflush(stdout);
		sleep(200 * level);

		printf("\r%*s\r入力せよ : ", level, "");
		fflush(stdout);
		scanf_s("%s", x, 40);

		makeAns(mstr);

		if (strcmp(x, mstr) != 0) {
			printf("\a間違いです。\n");
		}
		else {
			printf("正解です。\n");
			success++;
		}
	}
	end = clock();

	printf("%d回中%d回正解しました。\n", MAX_STAGE, success);
	printf("%.1f秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}
#endif

#ifdef _0504
#define MAX_STAGE 10
#define LEVEL_MIN 3
#define LEVEL_MAX 20

int sleep(unsigned long x) {
	clock_t c1 = clock(), c2 = 0;

	do {
		if ((c2 = clock()) == (clock_t)-1) {
			return 0;
		}
	} while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
	return 1;
}

void makeAns(char* str, int l) {
	str[0] = str[l - 1];
	str[1] = '\0';
}

int main(void) {
	int i = 0, stage = 0;
	int level = 0;
	int success = 0;
	clock_t start = 0, end = 0;
	const char str[] = "abcdefghijklmnopqrstuvwxyz";

	srand((unsigned)time(NULL));

	puts("英字記憶トレーニング");
	puts("逆順で回答してください。");

	do {
		printf("挑戦するレベル (%d～%d) : ", LEVEL_MIN, LEVEL_MAX);
		scanf_s("%d", &level);
	} while (!(level >= LEVEL_MIN && level <= LEVEL_MAX));

	printf("%d個の英字を記憶しましょう。\n", level);

	start = clock();
	for (stage = 0; stage < MAX_STAGE; stage++) {
		char mstr[LEVEL_MAX + 1];
		char x[8];
		int letter = rand() % level + 1;

		for (i = 0; i < level; i++) {
			mstr[i] = str[rand() % strlen(str)];
		}
		mstr[level] = '\0';

		sleep(500);

		printf("%s", mstr);
		fflush(stdout);
		sleep(200 * level);

		printf("\r%*s\r%d番目の文字は : ", level, "", letter);
		fflush(stdout);
		scanf_s("%s", x, 8);

		makeAns(mstr, letter);

		if (strcmp(x, mstr) != 0) {
			printf("\a間違いです。\n");
		}
		else {
			printf("正解です。\n");
			success++;
		}
	}
	end = clock();

	printf("%d回中%d回正解しました。\n", MAX_STAGE, success);
	printf("%.1f秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}
#endif

#ifdef _0505
#define MAX_STAGE 10
#define LEVEL_MIN 3
#define LEVEL_MAX 20

int sleep(unsigned long x) {
	clock_t c1 = clock(), c2 = 0;

	do {
		if ((c2 = clock()) == (clock_t)-1) {
			return 0;
		}
	} while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
	return 1;
}

int main(void) {
	int i = 0, j = 0, stage = 0;
	char tmp = 0;
	int level = 0;
	int success = 0;
	clock_t start = 0, end = 0;
	const char str[] = "abcdefghijklmnopqrstuvwxyz";

	srand((unsigned)time(NULL));

	puts("英字記憶トレーニング");

	do {
		printf("挑戦するレベル (%d～%d) : ", LEVEL_MIN, LEVEL_MAX);
		scanf_s("%d", &level);
	} while (!(level >= LEVEL_MIN && level <= LEVEL_MAX));

	printf("%d個の英字を記憶しましょう。\n", level);

	start = clock();
	for (stage = 0; stage < MAX_STAGE; stage++) {
		char mstr[LEVEL_MAX + 1];
		int x = 0;
		int letter = rand() % level + 1;

		for (i = 0; i < level; i++) {
			do {
				tmp = str[rand() % strlen(str)];
				for (j = 0; j < i; j++) {
					if (tmp == mstr[j]) {
						break;
					}
				}
			} while (j < i);
			mstr[i] = tmp;
		}
		mstr[level] = '\0';

		sleep(500);

		printf("%s", mstr);
		fflush(stdout);
		sleep(200 * level);

		printf("\r%*s\r%cは何文字目ですか : ", level, "", mstr[letter - 1]);
		fflush(stdout);
		scanf_s("%d", &x);

		

		if (x != letter) {
			printf("\a間違いです。\n");
		}
		else {
			printf("正解です。\n");
			success++;
		}
	}
	end = clock();

	printf("%d回中%d回正解しました。\n", MAX_STAGE, success);
	printf("%.1f秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}
#endif

#ifdef _0506
#define LEVEL_MIN 2
#define LEVEL_MAX 6

int sleep(unsigned long x) {
	clock_t c1 = clock(), c2 = 0;

	do {
		if ((c2 = clock()) == (clock_t)-1) {
			return 0;
		}
	} while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
	return 1;
}
int main(void) {
	int i = 0, stage = 0;
	int max_stage = 0;
	int level = 0;
	int success = 0;
	int* score;
	clock_t start = 0, end = 0;

	srand((unsigned)time(NULL));

	puts("プラスワントレーニング開始!!");
	puts("2桁の数値を記憶します。");
	puts("1を加えた値を入力してください。");

	do {
		printf("挑戦するレベル (%d～%d) : ", LEVEL_MIN, LEVEL_MAX);
		scanf_s("%d", &level);
	} while (!(level >= LEVEL_MIN && level <= LEVEL_MAX));

	do {
		printf("トレーニング回数 : ");
		scanf_s("%d", &max_stage);
	} while (max_stage <= 0);

	score = (int*)calloc(max_stage, sizeof(int));

	start = clock();
	for (stage = 0; stage < max_stage; stage++) {
		int no[LEVEL_MAX];
		int x[LEVEL_MAX];
		int seikai = 0;

		printf("\n第%dステージ開始!!\n", stage + 1);
		sleep(1000);

		for (i = 0; i < level; i++) {
			no[i] = rand() % 90 + 10;
			printf("%d ", no[i]);
		}
		fflush(stdout);
		sleep(300 * level);
		printf("\r%*s\r", 4 * level, "");
		fflush(stdout);

		for (i = 0; i < level; i++) {
			printf("%d番目の数 : ", i + 1);
			scanf_s("%d", &x[i]);
			if (x[i] == -1 && i != 0) i -= 2;
		}


		for (i = 0; i < level; i++) {
			if (x[i] != no[i] + 1) {
				printf("× ");
			}
			else {
				printf("○ ");
				seikai++;
			}
		}
		putchar('\n');

		for (i = 0; i < level; i++) {
			printf("%2d ", no[i]);
		}

		printf(" … %d個正解です。\n", seikai);
		score[stage] = seikai;
		success += seikai;
	}
	end = clock();

	printf("%d個中%d個正解しました。\n", level * max_stage, success);

	for (stage = 0; stage < max_stage; stage++) {
		printf("第%2dステージ : %d\n", stage + 1, score[stage]);
	}

	printf("%.1f秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);

	free(score);

	return 0;
}
#endif

#ifdef _0507
#define LEVEL_MIN 2
#define LEVEL_MAX 6

int sleep(unsigned long x) {
	clock_t c1 = clock(), c2 = 0;

	do {
		if ((c2 = clock()) == (clock_t)-1) {
			return 0;
		}
	} while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
	return 1;
}
int main(void) {
	int i = 0, stage = 0;
	int max_stage = 0;
	int level = 0;
	int success = 0;
	int* score;
	clock_t start = 0, end = 0;

	srand((unsigned)time(NULL));

	puts("マイナスワントレーニング開始!!");
	puts("2桁の数値を記憶します。");
	puts("1を引いた値を入力してください。");

	do {
		printf("挑戦するレベル (%d～%d) : ", LEVEL_MIN, LEVEL_MAX);
		scanf_s("%d", &level);
	} while (!(level >= LEVEL_MIN && level <= LEVEL_MAX));

	do {
		printf("トレーニング回数 : ");
		scanf_s("%d", &max_stage);
	} while (max_stage <= 0);

	score = (int*)calloc(max_stage, sizeof(int));

	start = clock();
	for (stage = 0; stage < max_stage; stage++) {
		int no[LEVEL_MAX];
		int x[LEVEL_MAX];
		int seikai = 0;

		printf("\n第%dステージ開始!!\n", stage + 1);
		sleep(1000);

		for (i = 0; i < level; i++) {
			no[i] = rand() % 90 + 10;
			printf("%d ", no[i]);
		}
		fflush(stdout);
		sleep(300 * level);
		printf("\r%*s\r", 4 * level, "");
		fflush(stdout);

		for (i = 0; i < level; i++) {
			printf("%d番目の数 : ", i + 1);
			scanf_s("%d", &x[i]);
			if (x[i] == -1 && i != 0) i -= 2;
		}


		for (i = 0; i < level; i++) {
			if (x[i] != no[i] - 1) {
				printf("× ");
			}
			else {
				printf("○ ");
				seikai++;
			}
		}
		putchar('\n');

		for (i = 0; i < level; i++) {
			printf("%2d ", no[i]);
		}

		printf(" … %d個正解です。\n", seikai);
		score[stage] = seikai;
		success += seikai;
	}
	end = clock();

	printf("%d個中%d個正解しました。\n", level * max_stage, success);

	for (stage = 0; stage < max_stage; stage++) {
		printf("第%2dステージ : %d\n", stage + 1, score[stage]);
	}

	printf("%.1f秒でした。\n", (double)(end - start) / CLOCKS_PER_SEC);

	free(score);

	return 0;
}
#endif

#ifdef _0508a
int human = 0;
int comp = 0;
int win_no = 0;
int lose_no = 0;
int draw_no = 0;

const char* hd[] = { "グー", "チョキ", "パー" };
const char* record[] = { "引き分け", "負け", "勝ち" };

void initalize(void) {
	win_no = 0;
	lose_no = 0;
	draw_no = 0;

	srand((unsigned)time(NULL));

	puts("じゃんけんゲーム開始!!");
}

void janken(void) {
	comp = rand() % 3;

	do {
		printf("\n\aじゃんけんぽん … ");
		for (int i = 0; i < 3; i++) {
			printf(" (%d)%s", i, hd[i]);
		}
		printf(" : ");
		scanf_s("%d", &human);
	} while (!(human >= 0 && human <= 2));
}

void count_no(int result) {
	switch (result) {
	case 0: draw_no++; break;
	case 1: lose_no++; break;
	case 2: win_no++; break;
	}
}

void disp_result(int result) {
	switch (result) {
	case 0: puts("引き分けです。"); break;
	case 1: puts("あなたの負けです。"); break;
	case 2: puts("あなたの勝ちです。"); break;
	}
}

int confirm_retry(void) {
	int x;

	printf("もう一度しますか…(0)いいえ (1)はい : ");
	scanf_s("%d", &x);

	return x;
}

int main(void) {
	short x[10] = { 0 };
	int no = 0;
	int judge = 0;
	int retry = 0;

	initalize();

	do {
		janken();

		printf("私は%sで、あなたは%sです。\n", hd[comp], hd[human]);

		judge = (human - comp + 3) % 3;

		x[no++ % 10] = judge;
		count_no(judge);
		disp_result(judge);

		retry = confirm_retry();
	} while (retry == 1);

	int i = no - 10;
	if (i < 0) i = 0;

	printf("%d勝%d敗%d分けでした。\n", win_no, lose_no, draw_no);
	puts(" --- --- 内訳 --- ---");
	for (i; i < no; i++) {
		printf("%2d : %s\n", i + 1, record[x[i % 10]]);
	}

	return 0;
}
#endif

#ifdef _0508b
int human = 0;
int comp = 0;
int win_no = 0;
int lose_no = 0;
int draw_no = 0;

const char* hd[] = { "グー", "チョキ", "パー" };
const char* record[] = { "引き分け", "負け", "勝ち" };

void initalize(void) {
	win_no = 0;
	lose_no = 0;
	draw_no = 0;

	srand((unsigned)time(NULL));

	puts("じゃんけんゲーム開始!!");
}

void janken(void) {
	comp = rand() % 3;

	do {
		printf("\n\aじゃんけんぽん … ");
		for (int i = 0; i < 3; i++) {
			printf(" (%d)%s", i, hd[i]);
		}
		printf(" : ");
		scanf_s("%d", &human);
	} while (!(human >= 0 && human <= 2));
}

void count_no(int result) {
	switch (result) {
	case 0: draw_no++; break;
	case 1: lose_no++; break;
	case 2: win_no++; break;
	}
}

void disp_result(int result) {
	switch (result) {
	case 0: puts("引き分けです。"); break;
	case 1: puts("あなたの負けです。"); break;
	case 2: puts("あなたの勝ちです。"); break;
	}
}

int main(void) {
	int num = 0;
	int remain = 0;
	int judge = 0;

	initalize();

	printf("何回しますか : ");
	scanf_s("%d", &num);

	short* no = (short*)calloc(num, sizeof(short));

	while (remain < num) {
		janken();

		printf("私は%sで、あなたは%sです。\n", hd[comp], hd[human]);

		judge = (human - comp + 3) % 3;

		no[remain++] = judge;

		count_no(judge);
		disp_result(judge);
	}

	printf("%d勝%d敗%d分けでした。\n", win_no, lose_no, draw_no);
	puts(" --- --- 内訳 --- ---");
	for (int i = 0; i < num; i++) {
		printf("%2d : %s\n", i + 1, record[no[i]]);
	}

	free(no);
	
	return 0;
}
#endif