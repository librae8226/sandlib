#include "ciphers.h"
#include <iostream>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;

void printArray(const char arr[], int size)
{
	for (int i = 0; i < size; i++) {
		cout << arr[i];
	}
	cout << endl;
}

void copyArray(const string source, char destination[], int &size)
{
	size = source.size();
	for (int i = 0; i <= size; i++) {
		destination[i] = source[i];
	}
}

void erase(char arr[], int &size, int position, int count)
{
	int x = size;
	int i = 0;
	for (i = position; i + count < x; i++) {
		arr[i] = arr[i + count];
	}
	for (; i < x; i++) {
		arr[i] = '\n';
		size = size - 1;
	}
}

void removeNonAlphas(char arr[], int &size, bool space)
{
	int i = 0;
	if (space) {
		for (i = 0; i < size; i++) {
			if (!
			    (arr[i] >= 'a' && arr[i] <= 'z' || arr[i] >= 'A'
			     && arr[i] <= 'Z')) {
				erase(arr, size, i, 1);
				i = i - 1;
			}
		}
	}
	else {
		for (i = 0; i < size; i++) {
			if (!
			    (arr[i] >= 'a' && arr[i] <= 'z' || arr[i] >= 'A'
			     && arr[i] <= 'Z' || arr[i] == ' ')) {
				erase(arr, size, i, 1);
				i = i - 1;
			}
		}
	}
}

char putCharacterIntoRange(int val)
{
	char x;
	if (val < 65) {
		int i = 0;
		i = val;
		while (i < 65) {
			i = i + ALPHABET_SIZE;
		}
		val = i;
	}
	else if (val > 90) {
		int i = 0;
		i = val;
		while (i > 90) {
			i = i - ALPHABET_SIZE;
		}
		val = i;
	}
	x = static_cast < char >(val);
	return x;
}

void toUpper(char arr[], int size)
{
	for (int i = 0; i < size; i++) {
		int x = 0;
		x = static_cast < int >(arr[i]);
		if (x >= 97 && x <= 122) {
			x = x - 32;
			arr[i] = static_cast < char >(x);
		}
	}
}

void caesarCipher(char message[], int &size, int key)
{
	removeNonAlphas(message, size, false);
	toUpper(message, size);
	for (int i = 0; i < size; i++) {
		if (message[i] != ' ') {
			int val = 0;
			val = (int)message[i] + key;
			message[i] = putCharacterIntoRange(val);
		}
	}
}

void copyArray(const string source, int destination[], int &size)
{
	int i;
	for (i = 0; i < source.length(); i++)
		destination[i] = source[i];
	size = source.length();
}

void printArrayAsCharacters(const int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << (char)arr[i];
	cout << endl;
}

void printArray(const int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i];
		if (i != size - 1)
			cout << ' ';
	}
	cout << endl;
}

void caesarCipher(int arr[], int size, int key)
{
	while (key < -25) {
		key = key + ALPHABET_SIZE;
	}
	while (key > 25) {
		key = key - ALPHABET_SIZE;
	}
	int i = 0;
	while (i < size) {
		arr[i] = arr[i] + key;
		i = i + 1;
	}
}

void upperCaseAndStrip(string str, char arr[], int &size, bool spaces)
{
	copyArray(str, arr, size);
	toUpper(arr, size);
	removeNonAlphas(arr, size, spaces);
}

void copyArray(char arr[], string & message, int size)
{
	int i;
	message.clear();
	for (i = 0; i < size; i++)
		message.push_back(arr[i]);
}

void vigenereCipher(string & message, string key, char code)
{
	char arr1[SIZE];
	char arr2[SIZE];
	int x = message.length();
	int y = key.length();
	upperCaseAndStrip(message, arr1, x, false);
	upperCaseAndStrip(key, arr2, y, true);
	int i = 0;
	int z = 0;

	if (code == 'e' || code == 'E') {
		for (i = 0; i < x; i++, z++) {
			if (arr1[i] != ' ') {
				arr1[i] =
				    putCharacterIntoRange(arr1[i] +
							  arr2[z % y] - 'A');
			}
			else {
				z--;
			}
		}
	}
	else {
		for (i = 0; i < x; i++, z++) {
			if (arr1[i] != ' ') {
				arr1[i] =
				    putCharacterIntoRange(arr1[i] -
							  arr2[z % y] - 'A');
			}
			else {
				z--;
			}
		}
	}
	copyArray(arr1, message, x);
}

void adjustAndCleanKey(string origKey, char key[], int &size, bool spaces)
{
	copyArray(origKey, key, size);
	removeNonAlphas(key, size, spaces);
	toUpper(key, size);
	removeDuplicates(key, size);
	for (char a = 'Z'; a >= 'A'; a--)
	{
		key[size++] = a;
	}
	key[size] = ' ';
	removeDuplicates(key, size);
}

void removeDuplicates(char arr[], int &size)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < size; i++) {
		j = find(arr, size, arr[i], i + 1);
		while (j != size) {
			erase(arr, size, j, 1);
			j = find(arr, size, arr[i], i + 1);
		}
	}
}

int find(const char arr[], int size, char target, int position)
{
	for (int i = position; i < size; i++)
		if (arr[i] == target)
			return i;
	return size;
}

void monoAlphabetCipher(string & origMessage, string origKey, char code)
{
	char arr[SIZE];
	char arr1[SIZE];
	int size = origKey.length();
	int size1 = origMessage.length();
	int num = 0;
	int i;
	adjustAndCleanKey(origKey, arr, size, false);
	upperCaseAndStrip(origMessage, arr1, size1, false);
	if (code == 'e' || code == 'E') {
		for (i = 0; i < size1; i++) {
			if (arr1[i] != ' ') {
				num = (int)arr1[i] - 65;
				arr1[i] = arr[num];
			}
			else {
				arr1[i] = arr[ALPHABET_SIZE];
			}
		}
		origMessage.clear();
		for (i = 0; i < size1; i++) {
			origMessage.push_back(arr1[i]);
		}
	}
	else {
		for (int i = 0; i < size1; i++) {
			num = find(arr, size, arr1[i], 0);
			if (num != ALPHABET_SIZE) {
				arr1[i] = static_cast < char >(num + 65);
			}
			else {
				arr1[i] = ' ';
			}
		}
		for (int i = 0; i < origMessage.length(); i++) {
			if (i < size1) {
				origMessage[i] = arr1[i];
			}
			else {
				origMessage.pop_back();
			}
		}
	}
}

int main(int argc, char *argv[])
{
	string key1 = "ACORN";
	string msg1 = "HELLO FROM EECS STAFF";
	string msg3 = "HGZCB FTCD REEG JGAHT";

	string key2 = "FEATHR WHISPCZYXVUQONMLKJGDB";
	string msg2 = "Hello from EECS 183 Staff";
	string msg4 = "WHCCXBRQXZBHHAOBBONFRR";

	cout << msg1 << ": Encrypt =>\n";
	vigenereCipher(msg1, key1, 'e');
	cout << msg1 << "\n";

	cout << msg2 << ": Encrypt =>\n";
	monoAlphabetCipher(msg2, key2, 'e');
	cout << msg2 << "\n";

	cout << msg3 << ": Decrypt =>\n";
	vigenereCipher(msg3, key1, 'd');
	cout << msg3 << "\n";

	cout << msg4 << ": Decrypt =>\n";
	monoAlphabetCipher(msg4, key2, 'd');
	cout << msg4 << "\n";

	return 0;
}
