#include "font_ansi_shadow.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Glyph definitions (each character: 6 lines) */
static const char *char_A[FONT_HEIGHT] = {
    " █████╗ ",
    "██╔══██╗",
    "███████║",
    "██╔══██║",
    "██║  ██║",
    "╚═╝  ╚═╝"
};

static const char *char_B[FONT_HEIGHT] = {
    "██████╗ ",
    "██╔══██╗",
    "██████╔╝",
    "██╔══██╗",
    "██████╔╝",
    "╚═════╝ "
};

/* Add C-Z letters (fill with correct glyphs, using ANSI Shadow style) */
static const char *char_C[FONT_HEIGHT] = {
    " ██████╗",
    "██╔════╝",
    "██║     ",
    "██║     ",
    "╚██████╗",
    " ╚═════╝"
};

static const char *char_D[FONT_HEIGHT] = {
    "██████╗ ",
    "██╔══██╗",
    "██║  ██║",
    "██║  ██║",
    "██████╔╝",
    "╚═════╝ "
};

static const char *char_E[FONT_HEIGHT] = {
    "███████╗",
    "██╔════╝",
    "█████╗  ",
    "██╔══╝  ",
    "███████╗",
    "╚══════╝"
};

static const char *char_F[FONT_HEIGHT] = {
    "███████╗",
    "██╔════╝",
    "█████╗  ",
    "██╔══╝  ",
    "██║     ",
    "╚═╝     "
};

static const char *char_G[FONT_HEIGHT] = {
    " ██████╗ ",
    "██╔════╝ ",
    "██║  ███╗",
    "██║   ██║",
    "╚██████╔╝",
    " ╚═════╝ "
};

static const char *char_H[FONT_HEIGHT] = {
    "██╗  ██╗",
    "██║  ██║",
    "███████║",
    "██╔══██║",
    "██║  ██║",
    "╚═╝  ╚═╝"
};

static const char *char_I[FONT_HEIGHT] = {
    "██╗",
    "██║",
    "██║",
    "██║",
    "██║",
    "╚═╝"
};

static const char *char_J[FONT_HEIGHT] = {
    "     ██╗",
    "     ██║",
    "     ██║",
    "██   ██║",
    "╚█████╔╝",
    " ╚════╝ "
};

static const char *char_K[FONT_HEIGHT] = {
    "██╗  ██╗",
    "██║ ██╔╝",
    "█████╔╝ ",
    "██╔═██╗ ",
    "██║  ██╗",
    "╚═╝  ╚═╝"
};

static const char *char_L[FONT_HEIGHT] = {
    "██╗     ",
    "██║     ",
    "██║     ",
    "██║     ",
    "███████╗",
    "╚══════╝"
};

static const char *char_M[FONT_HEIGHT] = {
    "███╗   ███╗",
    "████╗ ████║",
    "██╔████╔██║",
    "██║╚██╔╝██║",
    "██║ ╚═╝ ██║",
    "╚═╝     ╚═╝"
};

static const char *char_N[FONT_HEIGHT] = {
    "███╗   ██╗",
    "████╗  ██║",
    "██╔██╗ ██║",
    "██║╚██╗██║",
    "██║ ╚████║",
    "╚═╝  ╚═══╝"
};

static const char *char_O[FONT_HEIGHT] = {
    " ██████╗ ",
    "██╔═══██╗",
    "██║   ██║",
    "██║   ██║",
    "╚██████╔╝",
    " ╚═════╝ "
};

static const char *char_P[FONT_HEIGHT] = {
    "██████╗ ",
    "██╔══██╗",
    "██████╔╝",
    "██╔═══╝ ",
    "██║     ",
    "╚═╝     "
};

static const char *char_Q[FONT_HEIGHT] = {
    " ██████╗ ",
    "██╔═══██╗",
    "██║   ██║",
    "██║▄▄ ██║",
    "╚██████╔╝",
    " ╚══▀▀═╝ "
};

static const char *char_R[FONT_HEIGHT] = {
    "██████╗ ",
    "██╔══██╗",
    "██████╔╝",
    "██╔══██╗",
    "██║  ██║",
    "╚═╝  ╚═╝"
};

static const char *char_S[FONT_HEIGHT] = {
    " ██████╗",
    "██╔════╝",
    "╚█████╗ ",
    " ╚═══██╗",
    "██████╔╝",
    "╚═════╝ "
};

static const char *char_T[FONT_HEIGHT] = {
    "████████╗",
    "╚══██╔══╝",
    "   ██║   ",
    "   ██║   ",
    "   ██║   ",
    "   ╚═╝   "
};

static const char *char_U[FONT_HEIGHT] = {
    "██╗   ██╗",
    "██║   ██║",
    "██║   ██║",
    "██║   ██║",
    "╚██████╔╝",
    " ╚═════╝ "
};

static const char *char_V[FONT_HEIGHT] = {
    "██╗   ██╗",
    "██║   ██║",
    "██║   ██║",
    "╚██╗ ██╔╝",
    " ╚████╔╝ ",
    "  ╚═══╝  "
};

static const char *char_W[FONT_HEIGHT] = {
    "██╗    ██╗",
    "██║    ██║",
    "██║ █╗ ██║",
    "██║███╗██║",
    "╚███╔███╔╝",
    " ╚══╝╚══╝ "
};

static const char *char_X[FONT_HEIGHT] = {
    "██╗  ██╗",
    "╚██╗██╔╝",
    " ╚███╔╝ ",
    " ██╔██╗ ",
    "██╔╝╚██╗",
    "╚═╝  ╚═╝"
};

static const char *char_Y[FONT_HEIGHT] = {
    "██╗   ██╗",
    "╚██╗ ██╔╝",
    " ╚████╔╝ ",
    "  ╚██╔╝  ",
    "   ██║   ",
    "   ╚═╝   "
};

static const char *char_Z[FONT_HEIGHT] = {
    "███████╗",
    "╚══███╔╝",
    "  ███╔╝ ",
    " ███╔╝  ",
    "███████╗",
    "╚══════╝"
};

/* Digits 0-9 (ANSI Shadow style, height 6) */
static const char *char_0[FONT_HEIGHT] = {
    " ██████╗ ",
    "██╔═████╗",
    "██║██╔██║",
    "████╔╝██║",
    "╚██████╔╝",
    " ╚═════╝ "
};

static const char *char_1[FONT_HEIGHT] = {
    " ██╗",
    "███║",
    "╚██║",
    " ██║",
    " ██║",
    " ╚═╝"
};

static const char *char_2[FONT_HEIGHT] = {
    "██████╗ ",
    "╚════██╗",
    " █████╔╝",
    "██╔═══╝ ",
    "███████╗",
    "╚══════╝"
};

static const char *char_3[FONT_HEIGHT] = {
    "██████╗ ",
    "╚════██╗",
    " █████╔╝",
    " ╚═══██╗",
    "██████╔╝",
    "╚═════╝ "
};

static const char *char_4[FONT_HEIGHT] = {
    "██╗  ██╗",
    "██║  ██║",
    "███████║",
    "╚════██║",
    "     ██║",
    "     ╚═╝"
};

static const char *char_5[FONT_HEIGHT] = {
    "███████╗",
    "██╔════╝",
    "███████╗",
    "╚════██║",
    "███████║",
    "╚══════╝"
};

static const char *char_6[FONT_HEIGHT] = {
    " ██████╗ ",
    "██╔════╝ ",
    "███████╗ ",
    "██╔═══██╗",
    "╚██████╔╝",
    " ╚═════╝ "
};

static const char *char_7[FONT_HEIGHT] = {
    "███████╗",
    "╚═══██╔╝",
    "   ██╔╝ ",
    "  ██╔╝  ",
    "  ██║   ",
    "  ╚═╝   "
};

static const char *char_8[FONT_HEIGHT] = {
    " █████╗ ",
    "██╔══██╗",
    "╚█████╔╝",
    "██╔══██╗",
    "╚█████╔╝",
    " ╚════╝ "
};

static const char *char_9[FONT_HEIGHT] = {
    " █████╗ ",
    "██╔══██╗",
    "╚██████║",
    " ╚═══██║",
    " █████╔╝",
    " ╚════╝ "
};

/* Common symbols */
static const char *char_PLUS[FONT_HEIGHT] = {
    "   ",
    " █ ",
    "███",
    " █ ",
    "   ",
    "   "
};

static const char *char_MINUS[FONT_HEIGHT] = {
    "      ",
    "      ",
    "█████╗",
    "╚════╝",
    "      ",
    "      "
};

static const char *char_ASTERISK[FONT_HEIGHT] = {
    "      ",
    "▄ ██╗▄",
    " ████╗",
    "▀╚██╔▀",
    "  ╚═╝ ",
    "      "
};

/* Slash (/) */
static const char *char_SLASH[FONT_HEIGHT] = {
    "    ██╗",
    "   ██╔╝",
    "  ██╔╝ ",
    " ██╔╝  ",
    "██╔╝   ",
    "╚═╝    "
};

/* Equal (=) */
static const char *char_EQUAL[FONT_HEIGHT] = {
    "        ",
    "███████╗",
    "╚══════╝",
    "███████╗",
    "╚══════╝",
    "        "
};

/* Comma (,) */
static const char *char_COMMA[FONT_HEIGHT] = {
    "   ",
    "   ",
    "   ",
    "   ",
    "▄█╗",
    "╚═╝"
};

/* Period (.) */
static const char *char_PERIOD[FONT_HEIGHT] = {
    "   ",
    "   ",
    "   ",
    "   ",
    "██╗",
    "╚═╝"
};

/* Question mark (?) */
static const char *char_QUESTION[FONT_HEIGHT] = {
    "██████╗ ",
    "╚════██╗",
    "  ▄███╔╝",
    "  ▀▀══╝ ",
    "  ██╗   ",
    "  ╚═╝   "
};

/* Colon (:) */
static const char *char_COLON[FONT_HEIGHT] = {
    "   ",
    "██╗",
    "╚═╝",
    "██╗",
    "╚═╝",
    "   "
};

/* Exclamation (!) */
static const char *char_EXCLAMATION[FONT_HEIGHT] = {
    "██╗",
    "██║",
    "██║",
    "╚═╝",
    "██╗",
    "╚═╝"
};

/* At (@) */
static const char *char_AT[FONT_HEIGHT] = {
    " ██████╗ ",
    "██╔═══██╗",
    "██║██╗██║",
    "██║██║██║",
    "╚█║████╔╝",
    " ╚╝╚═══╝ "
};

/* Hash (#) */
static const char *char_HASH[FONT_HEIGHT] = {
    " ██╗ ██╗ ",
    "████████╗",
    "╚██╔═██╔╝",
    "████████╗",
    "╚██╔═██╔╝",
    " ╚═╝ ╚═╝ "
};

/* Dollar ($) */
static const char *char_DOLLAR[FONT_HEIGHT] = {
    "▄▄███▄▄·",
    "██╔════╝",
    "███████╗",
    "╚════██║",
    "███████║",
    "╚═▀▀▀══╝"
};

/* Percent (%) */
static const char *char_PERCENT[FONT_HEIGHT] = {
    "██╗ ██╗",
    "╚═╝██╔╝",
    "  ██╔╝ ",
    " ██╔╝  ",
    "██╔╝██╗",
    "╚═╝ ╚═╝"
};

/* Caret (^) */
static const char *char_CARET[FONT_HEIGHT] = {
    " ███╗ ",
    "██╔██╗",
    "╚═╝╚═╝",
    "      ",
    "      ",
    "      "
};

/* Ampersand (&) */
static const char *char_AMPERSAND[FONT_HEIGHT] = {
    "   ██╗   ",
    "   ██║   ",
    "████████╗",
    "██╔═██╔═╝",
    "██████║  ",
    "╚═════╝  "
};

/* Left Parenthesis ( ( ) */
static const char *char_LPAREN[FONT_HEIGHT] = {
    " ██╗",
    "██╔╝",
    "██║ ",
    "██║ ",
    "╚██╗",
    " ╚═╝"
};

/* Right Parenthesis ( ) ) */
static const char *char_RPAREN[FONT_HEIGHT] = {
    "██╗ ",
    "╚██╗",
    " ██║",
    " ██║",
    "██╔╝",
    "╚═╝ "
};

/* Left curly brace ({) */
static const char *char_LCURLY[FONT_HEIGHT] = {
    "  ██╗",
    " ██╔╝",
    "██╔╝ ",
    "╚██╗ ",
    " ╚██╗",
    "  ╚═╝"
};

/* Right curly brace (}) */
static const char *char_RCURLY[FONT_HEIGHT] = {
    "██╗  ",
    "╚██╗ ",
    " ╚██╗",
    " ██╔╝",
    "██╔╝ ",
    "╚═╝  "
};

/* Left Square Bracket [ */
static const char *char_LBRACKET[FONT_HEIGHT] = {
    "███╗",
    "██╔╝",
    "██║ ",
    "██║ ",
    "███╗",
    "╚══╝"
};

/* Right Square Bracket ] */
static const char *char_RBRACKET[FONT_HEIGHT] = {
    "███╗",
    "╚██║",
    " ██║",
    " ██║",
    "███║",
    "╚══╝"
};

/* Less Than Sign < */
static const char *char_LT[FONT_HEIGHT] = {
    "  ██╗",
    " ██╔╝",
    "██╔╝ ",
    "╚██╗ ",
    " ╚██╗",
    "  ╚═╝"
};

/* Greater Than Sign > */
static const char *char_GT[FONT_HEIGHT] = {
    "██╗  ",
    "╚██╗ ",
    " ╚██╗",
    " ██╔╝",
    "██╔╝ ",
    "╚═╝  "
};

/* Backslash (\\) */
static const char *char_BACKSLASH[FONT_HEIGHT] = {
    "██╗    ",
    "╚██╗   ",
    " ╚██╗  ",
    "  ╚██╗ ",
    "   ╚██╗",
    "    ╚═╝"
};

/* Vertical bar (|) */
static const char *char_PIPE[FONT_HEIGHT] = {
    "██╗",
    "██║",
    "██║",
    "██║",
    "██║",
    "╚═╝"
};

/* Double quote (\") */
static const char *char_QUOTE_DOUBLE[FONT_HEIGHT] = {
    "██╗ ██╗",
    "██║ ██║",
    "╚═╝ ╚═╝",
    "       ",
    "       ",
    "       "
};

/* Underscore _ */
static const char *char_UNDERSCORE[FONT_HEIGHT] = {
    "        ",
    "        ",
    "        ",
    "        ",
    "███████╗",
    "╚══════╝"
};

/* Space ( ) */
static const char *char_SPACE[FONT_HEIGHT] = {
    "    ",
    "    ",
    "    ",
    "    ",
    "    ",
    "    "
};

/* Special gap glyph (for controlling spacing between chars) */
static const char *char_GAP[FONT_HEIGHT] = {
    " ",
    " ",
    " ",
    " ",
    " ",
    " "
};

/* Return the glyph for a given char (case-insensitive). */
static const char **get_glyph(char c) {
    c = (char)toupper((unsigned char)c);
    switch (c) {
        /* Letters */
        case 'A': return char_A;
        case 'B': return char_B;
        case 'C': return char_C;
        case 'D': return char_D;
        case 'E': return char_E;
        case 'F': return char_F;
        case 'G': return char_G;
        case 'H': return char_H;
        case 'I': return char_I;
        case 'J': return char_J;
        case 'K': return char_K;
        case 'L': return char_L;
        case 'M': return char_M;
        case 'N': return char_N;
        case 'O': return char_O;
        case 'P': return char_P;
        case 'Q': return char_Q;
        case 'R': return char_R;
        case 'S': return char_S;
        case 'T': return char_T;
        case 'U': return char_U;
        case 'V': return char_V;
        case 'W': return char_W;
        case 'X': return char_X;
        case 'Y': return char_Y;
        case 'Z': return char_Z;

        /* Digits */
        case '0': return char_0;
        case '1': return char_1;
        case '2': return char_2;
        case '3': return char_3;
        case '4': return char_4;
        case '5': return char_5;
        case '6': return char_6;
        case '7': return char_7;
        case '8': return char_8;
        case '9': return char_9;

        /* Symbols */
        case '+': return char_PLUS;
        case '-': return char_MINUS;
        case '*': return char_ASTERISK;        
        case '/': return char_SLASH;
        case '=': return char_EQUAL;

        case ',': return char_COMMA;
        case '.': return char_PERIOD;
        case '?': return char_QUESTION;
        case ':': return char_COLON;
        case '!': return char_EXCLAMATION;
        case '@': return char_AT;
        case '#': return char_HASH;
        case '$': return char_DOLLAR;
        case '%': return char_PERCENT;
        case '^': return char_CARET;
        case '&': return char_AMPERSAND;
        case '(': return char_LPAREN;
        case ')': return char_RPAREN;
        case '{': return char_LCURLY;
        case '}': return char_RCURLY;
        case '[': return char_LBRACKET;
        case ']': return char_RBRACKET;
        case '<': return char_LT;
        case '>': return char_GT;
        case '\\': return char_BACKSLASH;
        case '|': return char_PIPE;
        case '"': return char_QUOTE_DOUBLE;
        case '_': return char_UNDERSCORE;
        
        case ' ': return char_SPACE;
        default:  return char_SPACE;
    }
}

/* Print string using ANSI Shadow font */
void font_ansi_shadow_print(const char *text) {
    if (!text || !*text) return;

    const char *p = text;

    while (*p) {
        const char *segment = p;
        while (*p && *p != '\n') p++;  /* Split by lines */
        size_t seg_len = (size_t)(p - segment);

        /* Draw line row by row */
        for (int row = 0; row < FONT_HEIGHT; row++) {
            for (size_t i = 0; i < seg_len; i++) {
                char ch = segment[i];
                if (ch == '\t') {
                    /* Tab expands into spaces */
                    for (int t = 0; t < FONT_TAB_SIZE; t++) {
                        fputs(char_SPACE[row], stdout);
                        for (int g = 0; g < FONT_GAP_COUNT; g++) {
                            fputs(char_GAP[row], stdout);
                        }
                    }
                } else {
                    const char **glyph = get_glyph(ch);
                    fputs(glyph[row], stdout);
                    /* Add GAP after each glyph except the last */
                    if (i != seg_len - 1) {
                        for (int g = 0; g < FONT_GAP_COUNT; g++) {
                            fputs(char_GAP[row], stdout);
                        }
                    }
                }
            }
            fputc('\n', stdout);
        }

        /* Keep blank line for '\n' in input */
        if (*p == '\n') {
            p++;
            fputc('\n', stdout);
        }
    }
}
