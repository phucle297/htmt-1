//
// Created by PerMees on 7/22/2024.
//

#include "iostream"
#include "algorithm"

using namespace std;

string decToBin(unsigned int dec) {
    if (dec == 0) return "0";
    string binary;
    while (dec) {
        binary += to_string(dec % 2);
        dec /= 2;
    }
    reverse(binary.begin(), binary.end());
    return binary;
};

string decToHex(unsigned int dec) {
    if (dec == 0) return "0";

    string hexChars = "0123456789ABCDEF";
    string hex;

    while (dec) {
        hex += hexChars[dec % 16];
        dec /= 16;
    }
    reverse(hex.begin(), hex.end());

    return hex;
}

unsigned int hexToDec(const string &hex) {
    unsigned int decimal = 0;
    unsigned int base = 1; //16^0
    string upperHex = hex;
    transform(upperHex.begin(), upperHex.end(), upperHex.begin(), ::toupper);

    for (auto it = upperHex.rbegin(); it != upperHex.rend(); ++it) {
        char digit = *it;
        unsigned int value;

        if (digit >= '0' && digit <= '9') {
            value = digit - '0';
        } else if (digit >= 'A' && digit <= 'F') {
            value = digit - 'A' + 10;
        } else {
            throw invalid_argument("Invalid hex character");
        }
        decimal += value * base;
        base *= 16;
    }

    return decimal;
}

unsigned int binToDec(const string &binary) {
    unsigned int decimal = 0;
    unsigned int base = 1; //2^0

    for (auto it = binary.rbegin(); it != binary.rend(); ++it) {
        char digit = *it;

        if (digit != '0') {
            if (digit == '1') {
                decimal += base;
            } else {
                throw invalid_argument("Invalid binary character");
            }
        }
        base *= 2;
    }

    return decimal;
}

string binToHex(const string &binary) {
    unsigned int decimal = binToDec(binary);
    return decToHex(decimal);
}

string hexToBin(const string &hex) {
    unsigned int decimal = hexToDec(hex);
    return decToBin(decimal);
}

int main() {
    cout << "Dec to Bin: " << decToBin(123) << endl;
    cout << "Dec to Hex: " << decToHex(123) << endl;
    cout << "Hex to Dec: " << hexToDec("7B") << endl;
    cout << "Bin to Dec: " << binToDec("1111011") << endl;
    cout << "Bin to Hex: " << binToHex("1111011") << endl;
    cout << "Hex to Bin: " << hexToBin("7B") << endl;
    return 0;
}