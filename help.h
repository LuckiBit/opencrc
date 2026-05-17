#ifndef HELP_H
#define HELP_H

#include <stddef.h>  /* For size_t */

#ifdef __cplusplus
extern "C" {
#endif

/* Command help structure */
typedef struct {
    const char *name;        /* Command name */
    const char *short_desc;  /* Short description */
    const char *long_desc;   /* Detailed description */
} HelpCommand;

/* List all commands with short descriptions */
void help_list_commands(void);

/* Show detailed help for a specific command */
void help_show_command(const char *name);

/* Get command names (optional, for auto-completion if needed) */
const char **help_get_command_names(size_t *count);

#ifdef __cplusplus
}
#endif

#endif /* HELP_H */
