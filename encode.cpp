#include <iostream>
#include <bitset>

bool calculateParity(bool bit1, bool bit2, bool bit3, bool bit4) {
    return (bit1 + bit2 + bit3 + bit4) % 2;
}

std::bitset<8> encodeHammingCode(std::bitset<4> dataBits) {
    bool dataBit1 = dataBits[0], dataBit2 = dataBits[1], dataBit3 = dataBits[2], dataBit4 = dataBits[3];
    bool parityBit1, parityBit2, parityBit3, parityBit4;

    parityBit1 = calculateParity(dataBit1, dataBit3, dataBit4, 1);
    parityBit2 = calculateParity(dataBit1, dataBit2, dataBit4, 1);
    parityBit3 = calculateParity(dataBit1, dataBit2, dataBit3, 1);
    parityBit4 = (1 + parityBit1 + dataBit1 + parityBit2 + dataBit2 + parityBit3 + dataBit3 + dataBit4) % 2;

    std::bitset<8> encodedHammingCode;
    encodedHammingCode[0] = parityBit1;
    encodedHammingCode[1] = dataBit1;
    encodedHammingCode[2] = parityBit2;
    encodedHammingCode[3] = dataBit2;
    encodedHammingCode[4] = parityBit3;
    encodedHammingCode[5] = dataBit3;
    encodedHammingCode[6] = parityBit4;
    encodedHammingCode[7] = dataBit4;

    return encodedHammingCode;
}

std::bitset<16> encodeData(int data)
{
    std::bitset<8> dataBits(data);

    std::bitset<4> firstHalf(dataBits.to_string().substr(0, 4));
    std::bitset<4> secondHalf(dataBits.to_string().substr(4, 4));

    std::bitset<8> encodedFirstHalf = encodeHammingCode(firstHalf);
    std::bitset<8> encodedSecondHalf = encodeHammingCode(secondHalf);

    std::bitset<16> encodedData = (encodedFirstHalf.to_ulong() << 8) | encodedSecondHalf.to_ulong();

    return encodedData;
}
