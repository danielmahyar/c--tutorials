#include <iostream>

#include <string>



using namespace std;

double fahrenheit_to_kelvin(double);
double fahrenheit_to_celsius(double);


int main() {

    string str;

    cout << "Enter a string: ";

    getline(cin, str);

   

    size_t count = str.length()-1;

    for(size_t i{0}; i < str.length(); i++) //Loop through each row

    {

        for(size_t l{0}; l < count; l++) //Print the appropriate number of spaces

            cout << " ";

        for(size_t j{0}; j < i+1; j++) //Print the first half of the string

            cout << str.at(j);

        for(size_t k{i}; k > 0; k--) //Print the second half of the string in reverse order

            cout << str.at(k-1);

        for(size_t l{0}; l < count; l++) //Print the appropriate number of spaces again

            cout << " ";

        cout << endl;

        count--;

    }

   

    return 0;

}