#include "interleaving_string.h"

bool isInterleave(char *s1, char *s2, char *s3) {
	int lenS1 = strlen(s1);
	int lenS2 = strlen(s2);
	int lenS3 = strlen(s3);

	if (lenS1 + lenS2 != lenS3) {
		return false;
	}

	if (0 == lenS1 && 0 == lenS2 && 0 == lenS3) {
		return true;
	}

	bool matrix[1024][1024];

	memset(matrix, false, 1024 * 1024 * sizeof(bool));
	matrix[0][0] = true;
	int i, j, k;

	for (i = 1; i <= lenS1; i++) {
		if (s1[i - 1] == s3[i - 1]) {
			matrix[i][0] = true;
		} else {
			break;
		}
	}

	for (i = 1; i <= lenS2; i++) {
		if (s2[i - 1] == s3[i - 1]) {
			matrix[0][i] = true;
		} else {
			break;
		}
	}

	for (i = 1; i <= lenS1; i++) {
		for (j = 1; j <= lenS2; j++) {
			k = i + j;

			matrix[i][j] = (matrix[i - 1][j] && s1[i - 1] == s3[k - 1])
					|| (matrix[i][j - 1] && s2[j - 1] == s3[k - 1]);
		}
	}

	return matrix[lenS1][lenS2];
}

static void _run() {
	if (isInterleave("aabcc", "dbbca", "aadbbcbcac")) {
		printf("Is Interleaving String\n");
	} else {
		printf("Is not Interleaving String\n");
	}
}

void interleaving_string() {
	_run();
}
