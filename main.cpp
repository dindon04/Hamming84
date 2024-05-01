#include <gtest/gtest.h>
#include "encode.cpp"
#include "decode.cpp"

TEST(EncodeTest, EncodeMaxValue) {
std::bitset<16> encodedData = encodeData(255);
EXPECT_EQ(encodedData.to_string(), "1110101011101010");
}

TEST(EncodeTest, EncodeRandomValue) {
std::bitset<16> encodedData = encodeData(85);
EXPECT_EQ(encodedData.to_string(), "0111001101110011");
}

TEST(DecodeTest, BasicDecode) {
short encodedPacket1 = 0b1101011011101101;
int expectedDecodedData1 = -1;
EXPECT_EQ(decodePacket(encodedPacket1), expectedDecodedData1);

short encodedPacket2 = 0b1100011011101101;
int expectedDecodedData2 = 158;
EXPECT_EQ(decodePacket(encodedPacket2), expectedDecodedData2);

short encodedPacket3 = 0b001010111110110;
int expectedDecodedData3 = 13; // error in p4
EXPECT_EQ(decodePacket(encodedPacket3), expectedDecodedData3);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
