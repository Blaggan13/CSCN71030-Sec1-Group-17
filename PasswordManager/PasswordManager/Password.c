#define _CRT_SECURE_NO_WARNINGS

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "Password.h"

pPassword createPassword() {
	pPassword pass = (pPassword)malloc(sizeof(pPassword));
	if (!pass) {
		fprintf(stderr, "Error allocating memory");
		exit(-1);
	}

	pass->password = (char*)calloc(PASSWORD_LENGTH, sizeof(char));

	return pass;
}

// Function to randomly generate the password
// of length 
pPassword randomPasswordGeneration() {
	pPassword password = createPassword();

	srand(time(NULL));

	int length = rand() % 10 + 10;

	for (int i = 0; i < length; i++) {
		*(password->password + i) = rand() % 90 + 35;
	}

	return password;
	//
	//// Initialize counter
	//int i = 0;

	//int randomizer = 0;

	// Seed the random-number generator
	// with current time so that the
	// numbers will be different every time
	

	//// Array of numbers
	//char numbers[] = "0123456789";

	//// Array of small alphabets
	//char letter[] = "abcdefghijklmnoqprstuvwyzx";

	//// Array of capital alphabets
	//char LETTER[] = "ABCDEFGHIJKLMNOQPRSTUYWVZX";

	//// Array of all the special symbols
	//char symbols[] = "!@#$^&*?";

	// Stores the random password
	//char password[length];
	//password1.password[length];


	// To select the randomizer
	//// inside the loop
	//randomizer = rand() % 4;

	//// Iterate over the range [0, N]
	//for (i = 0; i < length; i++) {

	//	if (randomizer == 1) {
	//		password1.password[i] = numbers[rand() % 10];
	//		randomizer = rand() % 4;
	//		printf_s("%c", password1.password[i]);
	//	}
	//	else if (randomizer == 2) {
	//		password1.password[i] = symbols[rand() % 8];
	//		randomizer = rand() % 4;
	//		printf_s("%c", password1.password[i]);
	//	}
	//	else if (randomizer == 3) {
	//		password1.password[i] = LETTER[rand() % 26];
	//		randomizer = rand() % 4;
	//		printf_s("%c", password1.password[i]);
	//	}
	//	else {
	//		password1.password[i] = letter[rand() % 26];
	//		randomizer = rand() % 4;
	//		printf_s("%c", password1.password[i]);
	//	}
	//}

	

	//char *pass = password1.password;
	//passwordStrengthChecker(*pass);

	//return password1.password;
}


int passwordStrengthChecker(pPassword pass) {
	/**(pass->password + i)*/
		int i, uppercase, lowercase, digit, specialcase;
		i = uppercase = lowercase = digit = specialcase = 0;

		int length = strlen(pass->password);

		for (i = 0; i < length; i++)
		{
			if (*(pass->password + i) >= 65 && *(pass->password + i) <= 90)   // check [A-Z] character present or not(UPPERCASE)
				uppercase++;
			else
				if (*(pass->password + i) >= 97 && *(pass->password + i) <= 122) //check [a-z] character present of not(lowercase)
					lowercase++;
				else
					if (*(pass->password + i) >= 48 && *(pass->password + i) <= 57) //check[0-9] digit present or not
						digit++;	
					else
						specialcase++;
		}

		int strength = 0;

		printf_s("your pass is:");
		if (uppercase > 0 && lowercase > 0 && digit > 0 && specialcase > 0) {
			printf_s("Very strong");
			strength = 4;
		}
		else {
			if (lowercase > 0 && uppercase > 0 && (digit > 0 || specialcase > 0)) {
				printf_s("strong..");
				strength = 3;
			}
				
			else {
				if (lowercase > 0 && (uppercase > 0 || digit > 0 || specialcase > 0)) {
					printf_s("Medium..");
					strength = 2;
				}
				else
					if (lowercase > 0 && uppercase == 0 && digit == 0 && specialcase == 0) {
						printf_s("weak..");
						strength = 1;
					}
			}
		}

		return strength;
}

void changePassword(pPassword pass, char* newPassword) {
	pPassword newPass = createPassword();

	strncpy(pass->password, newPassword, PASSWORD_LENGTH);
}