## Overview

The Hamming (8,4) code can detect up to two-bit errors or correct one-bit errors without detection of uncorrected errors. This implementation includes functions to encode 4 bits of data into 8 bits of Hamming (8,4) code, and decode 16 bits of encoded data back into 8 bits of original data.


## Test Descriptions

- `EncodeTest`: This test suite contains two tests for the `encode` function. The `EncodeMaxValue` test checks the encoding of the maximum value (255), and the `EncodeRandomValue` test checks the encoding of a random value (85).

- `DecodeTest`: This test suite contains a single test for the `decode` function. The `BasicDecode` test checks the decoding of three different encoded packets. It verifies that the function correctly decodes the packets, correctly corrects a single error, and correctly rejects a packet with more than one error.

