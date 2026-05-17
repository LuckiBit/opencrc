#ifndef CRC_H
#define CRC_H

#include <stdint.h>
#include <stddef.h>

// === CRC Configuration Structure ===
typedef struct {
    int width;
    uint64_t poly;
    uint64_t init;
    uint64_t xor_out;
    int reflect_in;
    int reflect_out;
} CRCConfig;

// === Predefined CRC Configurations ===
#define CRC8_SMBUS       (CRCConfig){8, 0x07, 0x00, 0x00, 0, 0}
#define CRC16_CCITT      (CRCConfig){16, 0x1021, 0xFFFF, 0x0000, 0, 0}
#define CRC16_MODBUS     (CRCConfig){16, 0x8005, 0xFFFF, 0x0000, 1, 1}
#define CRC16_USB        (CRCConfig){16, 0x8005, 0xFFFF, 0xFFFF, 1, 1}
#define CRC32_ISO_HDLC   (CRCConfig){32, 0x04C11DB7, 0xFFFFFFFF, 0xFFFFFFFF, 1, 1}
#define CRC64_ECMA_182   (CRCConfig){64, 0x42F0E1EBA9EA3693ULL, 0x0000000000000000ULL, 0x0000000000000000ULL, 0, 0}
#define CRC64_GO_ISO     (CRCConfig){64, 0x000000000000001BULL, 0xFFFFFFFFFFFFFFFFULL, 0xFFFFFFFFFFFFFFFFULL, 1, 1}

// === Functions ===
uint64_t reflect_bits(uint64_t data, int width);
uint64_t crc_compute(const CRCConfig* cfg, const uint8_t* data, size_t len);
size_t parse_hex_input(const char* input, uint8_t* output);

#endif // CRC_H
