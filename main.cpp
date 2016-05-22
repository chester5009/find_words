/*
 * main.cpp
 *
 *  Created on: 21 мая 2016 г.
 *      Author: chester
 */
#include <iostream>
#include <stdio.h>

using namespace std;

int getWordsCountMore5(char *buffer, int size) {
	int count = 0;
	int countChars = 0;
	for (int i = 0; i < size; i++) {
		if (buffer[i] == ' ') {
			if (countChars > 5) {
				count++;

			}
			countChars = 0;

		} else if (buffer[i] == NULL) {
			if (countChars > 5) {
				count++;

				return count;
			}
			countChars = 0;

		} else if (buffer[i] != ' ' && buffer[i] != NULL) {
			countChars++;

		}
	}
	return count;
}

int getWordsCount(char *buffer, int size) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (buffer[i] == ' ') {
			count++;
		} else if (buffer[i] == NULL) {
			count++;
			return count;
		}
	}
	return count;
}

void getBufferFromFile(char *path, char *buffer, int size) {
	int totalWords = 0;
	int wordsMore5 = 0;
	FILE *file;
	buffer = new char[size];
	file = fopen(path, "r");
	if (!file) {
		printf("Ошибка открытия файла\n");

	} else if (file) {
		while (fgets(buffer, size, file) != NULL) {

			//printf("words: %d\n", getWordsCount(buffer, 1024));
			//printf("words5: %d\n", getWordsCountMore5(buffer, 1024));
			totalWords += getWordsCount(buffer, 1024);
			wordsMore5 += getWordsCountMore5(buffer, 1024);
		}
		fclose(file);
	}
	printf("Всего слов: %d \n",totalWords);
	printf("Слов с количеством букв больше 5: %d \n",wordsMore5);
}

int main(int argc, char **argv) {
	setlocale(LC_ALL,"Russian");
	char buffer;
	char * path="data.txt";


	getBufferFromFile(path, &buffer, 1024);

}
