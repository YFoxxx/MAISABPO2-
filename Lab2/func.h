#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>
#include <cstdint>
#include <cstring>
#include <cstddef>
#include <cctype>

uint16_t calculateCRC16(const uint8_t* data, size_t length);
void init_crc32_table();
uint32_t calculateCRC32(const uint8_t* data, size_t length);
uint32_t reverseBits(uint32_t num);

#endif

