#ifndef FIRMWARE_INC_BITMAPS_H_
#define FIRMWARE_INC_BITMAPS_H_

#define BLANK_CHAR  "  "
#define SOLID_CHAR  "B "

#define SMALL_DIGIT_ROWS  7
#define LARGE_DIGIT_ROWS  12

#define LARGE_NUMS_LENGTH 17
#define SMALL_NUMS_LENGTH 15
#define SMALL_SYMB_LENGTH 9

#define RADIX_INDEX         12
#define SEMICOLON_INDEX     13
#define BLANK_INDEX         14
#define PLUS_INDEX          15
#define MINUS_INDEX         16

#define D_INDEX             0
#define S_INDEX             1
#define SUN_INDEX           2
#define MOON_INDEX          3
#define A_INDEX             4
#define T_INDEX             5
#define AM_INDEX            6
#define PM_INDEX            7
#define EXCLAMATION_INDEX   8

/*
 *  All digits are bottom-right aligned
*/ 
static unsigned char large_numbers[LARGE_NUMS_LENGTH][LARGE_DIGIT_ROWS] = {
    {
        // 0
        0b00111100,
        0b01111110,
        0b11000011,
        0b11000011,
        0b11000011,
        0b11000011,
        0b11000011,
        0b11000011,
        0b11000011,
        0b11000011,
        0b01111110,
        0b00111100
    },
    {
        // 1
        0b00011000,
        0b00111000,
        0b01111000,
        0b00011000,
        0b00011000,
        0b00011000,
        0b00011000,
        0b00011000,
        0b00011000,
        0b00011000,
        0b11111111,
        0b11111111
    },
    {
        // 2
        0b00111100,
        0b01111110,
        0b11000011,
        0b00000011,
        0b00000111,
        0b00001110,
        0b00011100,
        0b00111000,
        0b01110000,
        0b11100000,
        0b11111111,
        0b11111111
    },
    {
        // 3
        0b00111100,
        0b01111110,
        0b11000011,
        0b00000011,
        0b00000011,
        0b00111110,
        0b00111110,
        0b00000011,
        0b00000011,
        0b11000011,
        0b01111110,
        0b00111100
    },
    {
        // 4
        0b00000110,
        0b00001110,
        0b00011110,
        0b00111110,
        0b01110110,
        0b11100110,
        0b11000110,
        0b11111111,
        0b11111111,
        0b00000110,
        0b00000110,
        0b00000110
    },
    {
        // 5
        0b11111111,
        0b11111111,
        0b11000000,
        0b11000000,
        0b11000000,
        0b11111100,
        0b01111110,
        0b00000011,
        0b00000011,
        0b11000011,
        0b01111110,
        0b00111100
    },
    {
        // 6
        0b00111100,
        0b01111110,
        0b11000011,
        0b11000000,
        0b11000000,
        0b11111110,
        0b11111111,
        0b11000011,
        0b11000011,
        0b11000011,
        0b01111110,
        0b00111100
    },
    {
        // 7
        0b11111111,
        0b11111111,
        0b00000011,
        0b00000011,
        0b00000110,
        0b00000110,
        0b00001100,
        0b00001100,
        0b00011000,
        0b00011000,
        0b00110000,
        0b00110000
    },
    {
        // 8
        0b00111100,
        0b01111110,
        0b11000011,
        0b11000011,
        0b11000011,
        0b01111110,
        0b01111110,
        0b11000011,
        0b11000011,
        0b11000011,
        0b01111110,
        0b00111100
    },
    {
        // 9
        0b00111100,
        0b01111110,
        0b11000011,
        0b11000011,
        0b11000011,
        0b01111111,
        0b01111111,
        0b00000011,
        0b00000011,
        0b11000011,
        0b01111110,
        0b00111100
    },
    {
        // 10
        0b11111111,
        0b11111111,
        0b00000111,
        0b00001110,
        0b00011100,
        0b00111000,
        0b01110000,
        0b11100000,
        0b11000000,
        0b11000011,
        0b01111110,
        0b00111100
    },
    {
        // 11
        0b00111100,
        0b01111110,
        0b11000011,
        0b11000000,
        0b11000000,
        0b01111100,
        0b01111100,
        0b11000000,
        0b11000000,
        0b11000011,
        0b01111110,
        0b00111100
    },
    {
        // .
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b11000000,
        0b11000000
    },
    {
        // :
        0b00000000,
        0b00000000,
        0b00000000,
        0b11000000,
        0b11000000,
        0b00000000,
        0b00000000,
        0b11000000,
        0b11000000,
        0b00000000,
        0b00000000,
        0b00000000
    },
    {
        // blank
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000
    },
    {
        // +
        0b00000000,
        0b00000000,
        0b00011000,
        0b00011000,
        0b00011000,
        0b11111111,
        0b11111111,
        0b00011000,
        0b00011000,
        0b00011000,
        0b00000000,
        0b00000000
    },
    {
        // -
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b11111111,
        0b11111111,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000
    },
};

/*
 *  All digits are bottom-right aligned
*/ 
static unsigned char small_numbers[SMALL_NUMS_LENGTH][SMALL_DIGIT_ROWS] = {
    {
        // 0
        0b01110000,
        0b10001000,
        0b10001000,
        0b10001000,
        0b10001000,
        0b10001000,
        0b01110000
    },
    {
        // 1
        0b00100000,
        0b01100000,
        0b10100000,
        0b00100000,
        0b00100000,
        0b00100000,
        0b11111000
    },
    {
        // 2
        0b01110000,
        0b10001000,
        0b00001000,
        0b00010000,
        0b00100000,
        0b01000000,
        0b11111000
    },
    {
        // 3
        0b01110000,
        0b10001000,
        0b00001000,
        0b00110000,
        0b00001000,
        0b10001000,
        0b01110000
    },
    {
        // 4
        0b00010000,
        0b00110000,
        0b01010000,
        0b10010000,
        0b11111000,
        0b00010000,
        0b00010000
    },
    {
        // 5
        0b11111000,
        0b10000000,
        0b11110000,
        0b00001000,
        0b00001000,
        0b10001000,
        0b01110000
    },
    {
        // 6
        0b01110000,
        0b10000000,
        0b10000000,
        0b11110000,
        0b10001000,
        0b10001000,
        0b01110000
    },
    {
        // 7
        0b11111000,
        0b00001000,
        0b00001000,
        0b00010000,
        0b00100000,
        0b00100000,
        0b00100000
    },
    {
        // 8
        0b01110000,
        0b10001000,
        0b10001000,
        0b01110000,
        0b10001000,
        0b10001000,
        0b01110000
    },
    {
        // 9
        0b01110000,
        0b10001000,
        0b10001000,
        0b01111000,
        0b00001000,
        0b00001000,
        0b01110000
    },
    {
        // 10
        0b11111000,
        0b00010000,
        0b00100000,
        0b01000000,
        0b10000000,
        0b10001000,
        0b01110000
    },
    {
        // 11
        0b01110000,
        0b10001000,
        0b10000000,
        0b01100000,
        0b10000000,
        0b10001000,
        0b01110000
    },
    {
        // .
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b10000000
    },
    {
        // :
        0b00000000,
        0b00000000,
        0b10000000,
        0b00000000,
        0b10000000,
        0b00000000,
        0b00000000
    },
    {
        // Blank
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000,
        0b00000000
    },
};

/*
 *  All digits are bottom-right aligned
*/ 
static unsigned char small_symbols[SMALL_SYMB_LENGTH][SMALL_DIGIT_ROWS] = {
    {
        // D
        0b00000000,
        0b00000000,
        0b11000000,
        0b10100000,
        0b10100000,
        0b10100000,
        0b11000000
    },
    {
        // S
        0b00000000,
        0b00000000,
        0b01100000,
        0b10000000,
        0b11100000,
        0b00100000,
        0b11000000
    },
    {
        // sun
        0b00100000,
        0b10101000,
        0b01110000,
        0b11011000,
        0b01110000,
        0b10101000,
        0b00100000
    },
    {
        // moon
        0b00111000,
        0b01010000,
        0b10100000,
        0b10100000,
        0b10010000,
        0b01001100,
        0b00111000
    },
    {
        // A
        0b00000000,
        0b00000000,
        0b01000000,
        0b10100000,
        0b11100000,
        0b10100000,
        0b10100000
    },
    {
        // T
        0b00000000,
        0b00000000,
        0b11100000,
        0b01000000,
        0b01000000,
        0b01000000,
        0b01000000
    },
    {
        // AM
        0b00000000,
        0b00000000,
        0b00100101,
        0b01010111,
        0b01110111,
        0b01010101,
        0b01010101
    },
    {
        // PM
        0b00000000,
        0b00000000,
        0b01110101,
        0b01010111,
        0b01110111,
        0b01000101,
        0b01000101
    },
    {
        // !
        0b00000000,
        0b00000000,
        0b10000000,
        0b10000000,
        0b10000000,
        0b00000000,
        0b10000000
    }
};

#endif  // FIRMWARE_INC_BITMAPS_H_
