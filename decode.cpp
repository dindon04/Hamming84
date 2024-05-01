#include <iostream>
#include <bitset>

int checkAndCorrectErrors(int example)
{
    std::bitset<8> bits(example);

    bool dataBit1 = bits[0];
    bool dataBit2 = bits[1];
    bool dataBit3 = bits[2];
    bool dataBit4 = bits[3];

    bool parityBit1 = bits[4];
    bool parityBit2 = bits[5];
    bool parityBit3 = bits[6];
    bool parityBit4 = bits[7];

    bool A = (dataBit1 + dataBit2 + parityBit2 + parityBit4) % 2 == 1;
    bool B = (dataBit2 + dataBit3 + dataBit4 + parityBit4) % 2 == 1;
    bool C = (dataBit2 + dataBit4 + parityBit1 + parityBit2) % 2 == 1;
    bool D = (dataBit1 + dataBit2 + dataBit3 + dataBit4 + parityBit1 + parityBit2 + parityBit3 + parityBit4) % 2 == 1;

    if (A && B && C && D) std::cout << "accepted" << std::endl;
    else if (A && B && C && !D)
    {
        std::cout << "accepted (error in p4)" << std::endl;
        bits.flip(6);
    }
    else if ((!A || !B || !C) && !D)
    {
        std::cout << "single error" << std::endl;
        if (!A && B && C) bits.flip(0);
        if (!A && !B && !C) bits.flip(1);
        if (A && !B && C) bits.flip(2);
        if (A && !B && !C) bits.flip(3);
        if (A && B && !C) bits.flip(4);
        if (!A && B && !C) bits.flip(5);
        if (!A && !B && C) bits.flip(7);
    }
    else if (!A && !B && !C && D)
    {
        std::cout << "double error, rejecting packet" << std::endl;
        return -1;
    }
    else
    {
        std::cout << "unknown error condition" << std::endl;
        return -1;
    }

    int correctedData = 0;

    correctedData |= dataBit2;
    correctedData |= dataBit4 << 1;
    correctedData |= parityBit2 << 2;
    correctedData |= parityBit4 << 3;

    return correctedData;
}

int decodePacket(short packet)
{
    int decodedData = 0;

    int firstHalf = packet >> 8;
    int secondHalf = packet;

    int correctedFirstHalf = checkAndCorrectErrors(firstHalf);
    int correctedSecondHalf = checkAndCorrectErrors(secondHalf);

    if (correctedFirstHalf != -1 && correctedSecondHalf != -1) {
        decodedData = correctedFirstHalf * 16 + correctedSecondHalf;
    }
    else  decodedData = -1;

    return decodedData;
}
