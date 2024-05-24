#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to encrypt the text
void encrypt(char text[], int key) {
    char ch;
    for (int i = 0; text[i] != '\0'; ++i) {
        ch = text[i];
        if (isalpha(ch)) {
            if (islower(ch)) {
                ch = (ch - 'a' + key) % 26 + 'a';
            }
            if (isupper(ch)) {
                ch = (ch - 'A' + key) % 26 + 'A';
            }
        }
        text[i] = ch;
    }
}

// Function to decrypt the text
void decrypt(char text[], int key) {
    char ch;
    for (int i = 0; text[i] != '\0'; ++i) {
        ch = text[i];
        if (isalpha(ch)) {
            if (islower(ch)) {
                ch = (ch - 'a' - key + 26) % 26 + 'a';
            }
            if (isupper(ch)) {
                ch = (ch - 'A' - key + 26) % 26 + 'A';
            }
        }
        text[i] = ch;
    }
}

int main() {
    char text[500];
    int key, choice;

    // Taking user input
    printf("Enter a message: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter the key: ");
    scanf("%d", &key);

    printf("Enter 1 to Encrypt or 2 to Decrypt: ");
    scanf("%d", &choice);

    if (choice == 1) {
        encrypt(text, key);
        printf("Encrypted message: %s\n", text);
    } else if (choice == 2) {
        decrypt(text, key);
        printf("Decrypted message: %s\n", text);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
