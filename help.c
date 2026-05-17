#include "help.h"
#include <stdio.h>
#include <string.h>

/* Command definitions */
static const HelpCommand commands[] = {
    {"help",
     "Show help information.",
     "Displays a list of all commands or detailed help for a specific command.\n"
     "Usage:\n"
     "  help            Show all commands.\n"
     "  help <command>  Show detailed help for <command>."},
    {"version",
     "Show version information.",
     "Displays the current version of this tool."},
    {"mode",
     "Switch CRC algorithm mode.",
     "Select and configure the CRC algorithm interactively."},
    {"current",
     "Show current CRC parameters.",
     "Displays current CRC configuration, including bit width, polynomial, and flags."},
    {"exit",
     "Exit the program.",
     "Terminates the program. You can also type 'q' as a shortcut."},
    {"q",
     "Exit the program (shortcut).",
     "Same as 'exit'. Type 'q' to quit the program quickly."}
};

static const size_t command_count = sizeof(commands) / sizeof(commands[0]);

/* Print all commands with short descriptions */
void help_list_commands(void) {
    printf("Available commands:\n\n");
    for (size_t i = 0; i < command_count; i++) {
        printf("  %-10s - %s\n", commands[i].name, commands[i].short_desc);
    }
}

/* Print detailed help for a specific command */
void help_show_command(const char *name) {
    for (size_t i = 0; i < command_count; i++) {
        if (strcmp(name, commands[i].name) == 0) {
            printf("\nCommand: %s\n\n%s\n", commands[i].name, commands[i].long_desc);
            return;
        }
    }
    printf("No help available for '%s'.\n", name);
}

/* Return a static list of command names (for auto-completion) */
const char **help_get_command_names(size_t *count) {
    static const char *names[16];
    for (size_t i = 0; i < command_count; i++) {
        names[i] = commands[i].name;
    }
    *count = command_count;
    return names;
}
