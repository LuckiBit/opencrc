#ifndef FONT_ANSI_SHADOW_H
#define FONT_ANSI_SHADOW_H

#ifdef __cplusplus
extern "C" {
#endif

/* ===== Configurable Macros ===== */
#define FONT_HEIGHT     6       /* Font height (ANSI Shadow) */
#define FONT_TAB_SIZE   4       /* Tab expands to 4 spaces */
#define FONT_GAP_COUNT  0       /* Number of char_GAP between glyphs */

/* ===== API ===== */
/* Print a string in ANSI Shadow font (handles spaces, tabs, newlines). */
void font_ansi_shadow_print(const char *text);

#ifdef __cplusplus
}
#endif

#endif
