#ifndef PRINTF_COLOR
#define PRINTF_COLOR


//Regular text
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"
#define NORMAL "\x1b[0m"

//Color printf
#define printf_black(x, ...)   printf(BLK x NORMAL, __VA_ARGS__)
#define printf_red(x, ...)     printf(RED x NORMAL, __VA_ARGS__)
#define printf_green(x, ...)   printf(GRN x NORMAL, __VA_ARGS__)
#define printf_yellow(x, ...)  printf(YEL x NORMAL, __VA_ARGS__)
#define printf_blue(x, ...)    printf(BLU x NORMAL, __VA_ARGS__)
#define printf_magenta(x, ...) printf(MAG x NORMAL, __VA_ARGS__)
#define printf_cyan(x, ...)    printf(CYN x NORMAL, __VA_ARGS__)
#define printf_white(x, ...)   printf(WHT x NORMAL, __VA_ARGS__)

//Color fprintf
#define fprintf_red(std, x, ...)     fprintf(std, RED x NORMAL, __VA_ARGS__)
#define fprintf_black(std, x, ...)   fprintf(std, BLK x NORMAL, __VA_ARGS__)
#define fprintf_green(std, x, ...)   fprintf(std, GRN x NORMAL, __VA_ARGS__)
#define fprintf_yellow(std, x, ...)  fprintf(std, YEL x NORMAL, __VA_ARGS__)
#define fprintf_blue(std, x, ...)    fprintf(std, BLU x NORMAL, __VA_ARGS__)
#define fprintf_magenta(std, x, ...) fprintf(std, MAG x NORMAL, __VA_ARGS__)
#define fprintf_cyan(std, x, ...)    fprintf(std, CYN x NORMAL, __VA_ARGS__)
#define fprintf_white(std, x, ...)   fprintf(std, WHT x NORMAL, __VA_ARGS__)


#endif


