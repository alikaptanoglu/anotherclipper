#include <windows.h>

int containsarray(char* text, char* letters) {
	if (strlen(text) != strcspn(text, letters)) return 1;
	return 0;
}

int startswith(char* text, char* pattern) {
	if (strncmp(text, pattern, strlen(pattern)) == 0) return 1;
	return 0;
}

int isbtc(char* adr) {
	char* forbidden = "O0lI!\"#$ % &'()*+,-./:;<=>?@[\\]^_`{|}~";
	size_t adrlen = strlen(adr);
	if (startswith(adr, "1") && adrlen >= 26 && adrlen <= 34 && !containsarray(adr, forbidden)) return 1;
	return 0;
}

int iseth(char* adr) {
	char* forbidden = "ghijklmnopqrstuvwyzGHIJKLMNOPQRSTUVWXYZ\"#$ % &'()*+,-./:;<=>?@[\\]^_`{|}~";
	size_t adrlen = strlen(adr);
	if (startswith(adr, "0x") && adrlen == 42 && !containsarray(adr, forbidden)) return 1;
	return 0;
}