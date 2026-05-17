#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>
#include "crc.h"
#include "color.h"
#include "font_ansi_shadow.h"
#include "linenoise.h"
#include "help.h"

#define TOOL_VERSION "v1.0.0"

// === Show Banner ===
void show_banner() {
    set_fg_color(COLOR_BLUE);
    font_ansi_shadow_print("CRC");
    reset_color();
    printf("\nWelcome to the OpenCRC! ");
    set_fg_color(COLOR_GREEN);
    printf("(%s)\n", TOOL_VERSION);
    reset_color();
    printf("Author: ");
    set_fg_color(COLOR_CYAN);
    printf("LuckiBit\n\n");
    reset_color();
}

// === Show Version ===
void show_version() {
    set_fg_color(COLOR_CYAN);
    printf("CRC Calculation Tool %s\n", TOOL_VERSION);
    reset_color();
}

// Display CRC configuration parameters
void show_crc_parameters(const CRCConfig* cfg, const char* name) {
    printf("%-18s: %s\n", "Algorithm", name);
    printf("%-18s: %d\n", "Bit Width", cfg->width);
    printf("%-18s: 0x%llX\n", "Polynomial", cfg->poly);
    printf("%-18s: 0x%llX\n", "Initial Value", cfg->init);
    printf("%-18s: 0x%llX\n", "XOR Output", cfg->xor_out);
    printf("%-18s: %s\n", "Reflect Input", cfg->reflect_in ? "Yes" : "No");
    printf("%-18s: %s\n", "Reflect Output", cfg->reflect_out ? "Yes" : "No");
}

// Show entered input bytes
void print_input_bytes(const uint8_t* data, size_t len) {
    set_fg_color(COLOR_YELLOW);
    printf("Input (%zu bytes): ", len);
    reset_color();

    for (size_t i = 0; i < len; i++) {
        printf("%02X", data[i]);
        if (i != len - 1) printf(" ");
    }
    printf("\n");
}

// Print CRC result
void print_crc_result(uint64_t crc, int width) {
    set_fg_color(COLOR_GREEN);
    printf("CRC Result: 0x%0*llX\n", width / 4, crc);
    reset_color();
}

// CRC algorithm selection menu
void select_crc_mode(CRCConfig* cfg, const char** name) {
    int choice;
    while (1) {
        set_fg_color(COLOR_YELLOW);
        printf("\nSelect CRC Algorithm:\n");
        reset_color();
        printf("1. CRC8_SMBUS\n");
        printf("2. CRC16_CCITT\n");
        printf("3. CRC16_MODBUS\n");
        printf("4. CRC16_USB\n");
        printf("5. CRC32_ISO_HDLC\n");
        printf("6. CRC64_ECMA_182\n");
        printf("7. CRC64_GO_ISO\n");
        set_fg_color(COLOR_CYAN);
        printf("Enter your choice: ");
        reset_color();

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');

        switch (choice) {
        case 1: *cfg = CRC8_SMBUS; *name = "CRC8_SMBUS"; break;
        case 2: *cfg = CRC16_CCITT; *name = "CRC16_CCITT"; break;
        case 3: *cfg = CRC16_MODBUS; *name = "CRC16_MODBUS"; break;
        case 4: *cfg = CRC16_USB; *name = "CRC16_USB"; break;
        case 5: *cfg = CRC32_ISO_HDLC; *name = "CRC32_ISO_HDLC"; break;
        case 6: *cfg = CRC64_ECMA_182; *name = "CRC64_ECMA_182"; break;
        case 7: *cfg = CRC64_GO_ISO; *name = "CRC64_GO_ISO"; break;
        default: continue;
        }
        break;
    }

    show_crc_parameters(cfg, *name);
}

// Tab-completion using help module for all commands
void completion_callback(const char* prefix, linenoiseCompletions* lc) {
    // Check if input starts with "help " for subcommand completion
    if (strncmp(prefix, "help ", 5) == 0) {
        // Get the subcommand prefix after "help "
        const char* subprefix = prefix + 5;

        size_t count = 0;
        const char** subcommands = help_get_command_names(&count);
        for (size_t i = 0; i < count; i++) {
            if (strncmp(subprefix, subcommands[i], strlen(subprefix)) == 0) {
                // Complete with "help subcommand"
                char completion[256];
                snprintf(completion, sizeof(completion), "help %s", subcommands[i]);
                linenoiseAddCompletion(lc, completion);
            }
        }
    } else {
        // Top-level command completion
        size_t count = 0;
        const char** commands = help_get_command_names(&count);
        for (size_t i = 0; i < count; i++) {
            if (strncmp(prefix, commands[i], strlen(prefix)) == 0) {
                linenoiseAddCompletion(lc, commands[i]);
            }
        }
    }
}

int main() {
#ifdef _WIN32
    system("chcp 65001 > nul");
#endif

#ifdef _WIN32
    linenoiseInit();   // Initialize linenoise (Windows support)
#endif
    show_banner();

    CRCConfig current_cfg = CRC16_MODBUS;     // Default CRC algorithm
    const char* current_name = "CRC16_MODBUS";

    linenoiseSetCompletionCallback(completion_callback);
    char* line;
    uint8_t data[256];

    while ((line = linenoise("> ")) != NULL) {
        char* p = line;
        while (*p && isspace((unsigned char)*p)) p++;

        if (*p == '\0') {
            linenoiseFree(line);
            continue;
        }

        if (strcmp(p, "q") == 0 || strcmp(p, "exit") == 0) {
            linenoiseFree(line);
            break;
        } else if (strcmp(p, "help") == 0) {
            help_list_commands();  // List all help topics
        } else if (strncmp(p, "help ", 5) == 0) {
            help_show_command(p + 5);  // Show detailed help
        } else if (strcmp(p, "version") == 0) {
            show_version();
        } else if (strcmp(p, "mode") == 0) {
            select_crc_mode(&current_cfg, &current_name);
        } else if (strcmp(p, "current") == 0) {
            show_crc_parameters(&current_cfg, current_name);
        } else {
            size_t len = parse_hex_input(p, data);
            if (len == 0) {
                set_fg_color(COLOR_RED);
                printf("No valid bytes entered.\n");
                reset_color();
            } else {
                print_input_bytes(data, len);
                uint64_t crc = crc_compute(&current_cfg, data, len);
                print_crc_result(crc, current_cfg.width);
            }
        }

        linenoiseHistoryAdd(p);
        linenoiseFree(line);
    }

#ifdef _WIN32
    linenoiseCleanup();
#endif

    set_fg_color(COLOR_GREEN);
    printf("Program terminated.\n");
    reset_color();
    return 0;
}
