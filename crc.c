#include "crc.h"
#include <stdio.h>
#include <ctype.h>

uint64_t reflect_bits(uint64_t data, int width) {
    uint64_t result = 0;
    for (int i = 0; i < width; i++) {
        if (data & (1ULL << i))
            result |= (1ULL << (width - 1 - i));
    }
    return result;
}

uint64_t crc_compute(const CRCConfig* cfg, const uint8_t* data, size_t len) {
    uint64_t crc = cfg->init;
    uint64_t topbit = 1ULL << (cfg->width - 1);
    uint64_t mask = (cfg->width < 64) ? ((1ULL << cfg->width) - 1) : 0xFFFFFFFFFFFFFFFFULL;

    for (size_t i = 0; i < len; i++) {
        uint8_t byte = cfg->reflect_in ? reflect_bits(data[i], 8) : data[i];
        crc ^= ((uint64_t)byte) << (cfg->width - 8);
        for (int j = 0; j < 8; j++) {
            crc = (crc & topbit) ? ((crc << 1) ^ cfg->poly) : (crc << 1);
        }
    }

    if (cfg->reflect_out)
        crc = reflect_bits(crc, cfg->width);

    return (crc ^ cfg->xor_out) & mask;
}

size_t parse_hex_input(const char* input, uint8_t* output) {
    size_t count = 0;

    while (*input) {
        // Skip whitespace
        while (*input && isspace((unsigned char)*input)) input++;
        if (!*input) break;

        // Skip optional 0x or 0X prefix
        if (input[0] == '0' && (input[1] == 'x' || input[1] == 'X')) {
            input += 2;
        }

        // Read 1 or 2 hex digits as a single byte
        char hex[3] = {0};
        int len = 0;
        while (len < 2 && *input && isxdigit((unsigned char)*input)) {
            hex[len++] = *input++;
        }

        if (len > 0) {
            unsigned int byte;
            sscanf(hex, "%x", &byte);
            output[count++] = (uint8_t)byte;
        } else {
            // Skip invalid characters
            input++;
        }
    }

    return count;
}

