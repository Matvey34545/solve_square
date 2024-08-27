#ifndef ARGC
#define ARGC

const int SIZE_KEY = 100;

enum EnumKey
{
    HELP          = 0,
    TEST          = 1,
    USER          = 2,
    ERROR_IN_FLAG = 3
};

struct Flag
{
    char short_flag[SIZE_KEY];
    char long_flag [SIZE_KEY];
};

/*!
Cравнивает аргумент командной строки с ключами
\param[out] argv Командная строка
\param[out] command_line_number Номер командной строки, которую считывает
\param[out] argc Количествл аргументов командной строки
\return Совпавший ключ
*/
EnumKey comparison_with_possible_arguments(char *argv, int command_line_number, int argc);

#endif
