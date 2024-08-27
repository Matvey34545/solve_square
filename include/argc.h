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
C��������� �������� ��������� ������ � �������
\param[out] argv ��������� ������
\param[out] command_line_number ����� ��������� ������, ������� ���������
\param[out] argc ���������� ���������� ��������� ������
\return ��������� ����
*/
EnumKey comparison_with_possible_arguments(char *argv, int command_line_number, int argc);

#endif
