#ifndef ARGC
#define ARGC

const int SIZE_KEY = 100;

enum EnumKey
{
    HELP       = 0,
    TEST       = 1,
    USER       = 2,
    WITHOUT_ARG = 3
};

struct Key
{
    char short_key[SIZE_KEY];
    char long_key [SIZE_KEY];
};

/*!
C��������� �������� ��������� ������ � �������
\param[out] argv ��������� ������
\return ��������� ����
*/
EnumKey comparison_with_possible_arguments(const char *argv);

#endif
