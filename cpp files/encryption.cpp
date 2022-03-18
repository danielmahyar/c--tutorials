#include <iostream>
#include <string>
using namespace std;

int main(){
	const string albet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVMXYZ"};
	const string key {"lmnopqrZABCDEFGHIJKLMNstudefgvwxyzabchijkXYOPQRSTUVM"};
	string inputMessage {};

	cout << "Write your message that will be encrypted: ";
	getline(cin, inputMessage);
	string encryptedMessage {inputMessage};

	cout << "\nEncrypting message..." << endl;
	
	for(size_t i = 0; i < encryptedMessage.size(); ++i)
		encryptedMessage[i] = (isalpha(encryptedMessage[i])) ? key[albet.find(encryptedMessage[i])] : encryptedMessage[i];

	cout << "The encrypted message is: " << encryptedMessage << endl;

	cout << "Decrypting message..." << endl;

	string decryptedMessage {encryptedMessage};

	for(size_t i = 0; i < decryptedMessage.size(); ++i)
		decryptedMessage[i] = (isalpha(decryptedMessage[i])) ? albet[key.find(decryptedMessage[i])] : decryptedMessage[i];


	cout << "The decrypted message is: " << decryptedMessage << endl;
	cout << "The original and decryptedMessage was: " << (inputMessage == decryptedMessage) << endl;

	return 0;
}