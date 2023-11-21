#include "func.h"

using namespace std;

int main()
{

    /*uint32_t polynomial = 0x04c11db7;
    uint32_t reversedPolynomial = reverseBits(polynomial);

    cout << std::hex << "Base: 0x" << setw(8) << setfill('0') << polynomial << endl;
    cout << "Reverse: 0x" << setw(8) << setfill('0') << reversedPolynomial << endl;*/

    char chr;
    bool bMenu = true;
    string userInput;

    cout << "Enter text\n";
    getline(cin, userInput);

    size_t length16 = userInput.length();

    uint16_t crc16Result = calculateCRC16(reinterpret_cast<const uint8_t*>(userInput.c_str()), length16);

    init_crc32_table();

    size_t length32 = userInput.length();

    uint32_t crc32Result = calculateCRC32(reinterpret_cast<const uint8_t*>(userInput.c_str()), length32);

    while (bMenu)
    {
        cout << "***Choose***\n";
        cout << "1 - CRC16\n";
        cout << "2 - CRC32\n";

        cout << (chr = _getch()) << endl;
        switch (chr)
        {
        case '1':

            cout << "CRC-16-CCITT: 0x" << hex << crc16Result << dec << endl;

            break;
        case '2':
            cout << "CRC-32-IEEE 802.3: 0x" << hex << crc32Result << dec << endl;
           break;
        
        default:
            cout << "\nUnsupported key is pressed\n";
            break;
        }
        cout << "\nPress 0 to continue\n";
        cout << "Any other to exit\n";
        cout << (chr = _getch()) << endl;
        if (chr != '0')
            bMenu = false;
        system("cls");
    }
}