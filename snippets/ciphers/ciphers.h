#ifndef __ciphers_h
#define __ciphers_h

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

const int SIZE = 200;		// max size of all messages
const int SIZE_183CIPHER = 5;	// size of arrays in 183Cipher
const int ALPHABET_SIZE = 26;

/**
 Note: All of the "printArray" functions will be very similar. Don't worry
       much about duplicated code in these functions. We expect it.
 */
/**
 Requires: The size of array arr is size && size > 0 && size <= SIZE.
 Modifies: Nothing.
 Effects:  Prints the elements of the array with no spaces between.
           Prints an endl at the end.
 Example:  If array arr contains {'A', 'B', 'C', 'D'} then the following code:
           printArray(arr, 4);
           cout << "Hello";
           will print
           ABCD
           Hello
 Note: there must be no space after the 'D' in the above example.
 */
void printArray(const char arr[], int size);

/**
 Requires: destination is large enough to hold all characters in source.
 Modifies: destination and size.
 Effects:  Copies all elements from source to destination[] and updates
           size to be the length of the string source.
 */
void copyArray(const string source, char destination[], int &size);

/**
 Requires: The size of array arr is size && size > 0 && size <= SIZE.
           position >= 0 and count >= 0.
 Modifies: arr and size.
 Effects:  Starting with the element at position, erase removes
           count elements from arr.
 Example:  If array arr contains {'A', 'B', 'C', 'D'} then the code:
           int size = 4;
           erase(arr, size, 2, 1);
           printArray(arr, size);
           will print: ABD
           erase removed 1 element at index 2.
           If arr contains {'A','B','C','D','E','F'} with size being 6
           erase(arr, size, 3, 4);
           printArray(arr, size);
           will print: ABC
 Note:     Trying to erase more elements than are possible is not an error
           as in the above example.
 */
void erase(char arr[], int &size, int position, int count);

/**
 Requires: The size of array arr is size && size > 0 && size <= SIZE.
 Modifies: arr, size.
 Effects:  Removes all non-alpha characters from arr.
           If space is true, it also removes spaces from arr.
           If space is false, it leaves spaces in arr.
 Example:  char arr1[] = "Hello from 183 Staff";
           removeNonAlphas(arr1, size, true);
           printArray(arr1, size);
           // will print: HellofromStaff
 Example:  char arr2[] = "Hello from 183 Staff";
           removeNonAlphas(arr2, size, false);
           printArray(arr2, size);
           // will print: Hello from  Staff
 Calls:    copyArray
           erase
 */
void removeNonAlphas(char arr[], int &size, bool space);

/**
 Requires: Nothing.
 Modifies: Nothing.
 Effects:  If val is outside of the range 65 through 90 inclusive, val will be
           shifted by ALPHABET_SIZE until it is in the range of 65 through 90.
           Returns the corresponding character in range of 'A' through 'Z'.
 Example:  cout << putCharacterIntoRange(68);  // will print 'D'
           cout << putCharacterIntoRange(42);  // will print 'D'
           cout << putCharacterIntoRange(16);  // will print 'D'
           cout << putCharacterIntoRange(94);  // will print 'D'
           cout << putCharacterIntoRange(120); // will print 'D'
           cout << putCharacterIntoRange('D'); // will print 'D'
 */
char putCharacterIntoRange(int val);

/**
 Requires: The size of array arr is size && size > 0 && size <= SIZE.
 Modifies: arr.
 Effects:  Will uppercase all letters within arr.
           It will not alter any non-alpha characters.
 */
void toUpper(char arr[], int size);

/**
 Requires: The size of array arr is size && size > 0 && size <= SIZE.
 Modifies: message, size.
 Effects:  Encrypts and decrypts arr using the key
           For more details on Caesar cipher see the spec
 Note:     You will want to cast the char to an int BEFORE you add the key.
           int val = (int) message[i] + key;
           Make sure you store it back into an int
           If you don't, you may easily overflow max char
           message[i] = (int) message[i] + key; // could cause major issues
                                                // don't do this
 Calls:    removeNonAlphas
           toUpper
           putCharInRange
 */
void caesarCipher(char message[], int &size, int key);

/**
 Requires: Nothing.
 Modifies: destination and size.
 Effects:  Takes characters in source and stores their ASCII equivalent
           in array destination in the corresponding locations.
           It also updates size accordingly to the length of source.
 Hint:     Useful in testing the next caesarCipher function.
 Example:  The following code:
           int arr[SIZE];
           int size = 0;
           copyArray("Enjoy!", arr, size);
           printArray(arr, size);
           cout << "Size is: " << size << endl;
           will print:
           69 110 106 111 121 33
           Size is: 6
 Note: This function will make testing some of the following functions easier.
 */
void copyArray(const string source, int destination[], int &size);

/**
 Requires: The size of array arr is size && size > 0 && size <= SIZE.
           All values within arr must be >= 32 and < 127.
 Modifies: Nothing.
 Effects:  Prints the elements of the array as the ASCII character they
           represent. Prints an endl at the end.
 Hint:     Useful in testing the next caesarCipher function.
 Example:  If array arr contains {65, 66, 67, 68} then the following code:
           printArray_as_characters(arr, 4);
           cout << "Hello";
           will print
           ABCD
           Hello
 Note:     There must be no space after the D in the above example.
           int arr[] = {120, 121, 122, 123};
           putCharacterIntoRange(arr, 4);
           prints: xyz{
 */
void printArrayAsCharacters(const int arr[], int size);

/**
 Requires: The size of array arr is size && size > 0 && size <= SIZE.
 Effects:  Prints the elements of the array with one space between.
           Prints an endl at the end.
 Hint:     Useful in testing the next caesarCipher function.
 Example:  If array arr contains {1,2,3,4} then the following code:
           printArray(arr, 4);
           cout << "Hello";
           will print
           1 2 3 4
           Hello
 Note:     There must be no space after the 4 in the above example.
 */
void printArray(const int arr[], int size);

/**
 Requires: The size of array arr is size && size > 0 && size <= SIZE.
 Modifies: arr.
 Effects:  Encrypts and decrypts arr using the key.
           For more details on Caesar cipher, see the specification.
 */
void caesarCipher(int arr[], int size, int key);

/**
 Requires: size is the size of arr.
 Modifies: arr and size.
 Effects:  Copies str into arr and then uppercases all characters
           and strips out all non-alpha characters including spaces
           if spaces == true, otherwise leaves spaces.
 Calls:    copyArray
           toUpper
           removeNonAlphas
 */
void upperCaseAndStrip(string str, char arr[], int &size, bool spaces);

/**
 Requires: The size of array arr is size && size > 0 && size <= SIZE.
 Modifies: message.
 Effects:  Creates message by appending all from arr into it.
 */
void copyArray(char arr[], string & message, int size);

/**
 Requires: If code is 'E' or 'e', it will encrypt. Otherwise, it will decrypt.
 Modifies: message.
 Effects:  Encrypts and decrypts message using the key.
           Make sure the encrypted/decrypted message is indeed
           back into "message" before you return from here.
           For more details on Vinenere cipher see project specification.
 Calls:    upperCaseAndStrip
           putCharacterIntoRange
           copyArray
 */
void vigenereCipher(string & message, string key, char code);

/**
 Requires: spaces to be true/false depending on if you want spaces kept.
 Modifies: key, size.
 Effects:  Puts the key into the format required for monoAlphabetCipher.
 */
void adjustAndCleanKey(string origKey, char key[], int &size, bool spaces);

/**
 Requires: The size of array arr is size && size > 0 && size <= SIZE.
 Modifies: arr and size.
 Effects:  Removes all duplicates within arr.
 Example:  char arr[] = {'A','B','C','B','D','E','C'};
           int size = 7;
           removeDuplicates(arr, size);
           printArray(arr, size); // will print: ABCDE
           cout << "Size is: " << size << endl; // prints: Size is: 5
 Calls:    find
           erase
 */
void removeDuplicates(char arr[], int &size);

/**
 Requires: The size of array arr is size && size > 0 && size <= SIZE.
 Modifies: Nothing.
 Effects:  Tries to find target in the array arr starting at index position.
           If target is found, returns the index it was found at.
           Otherwise, returns size.
 */
int find(const char arr[], int size, char target, int position);

/**
 Requires: If code is 'E' or 'e', it will encrypt, otherwise it will decrypt.
 Modifies: origMessage.
 Effects:  Encrypts or decrypts message and reassigns back into message
           Make sure the encrypted/decrypted message is indeed
           back into "message" before you return from here.
           For details on Mono-aplphabet cipher, see project specification.
 Calls:    upperCaseAndStrip
           adjustAndCleanKey
           find
           copyArray
 */
void monoAlphabetCipher(string & origMessage, string origKey, char code);

#endif
