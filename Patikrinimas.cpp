#include "Patikrinimas.h"

bool check_string(string& str)
{
    int sum = 0;

    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false) sum += 1;

    if (sum == str.length()) return true;
    else return false;
}

bool check_alpha(char& chr)
{
    if (chr == 't' || chr == 'T' || chr == 'n' || chr == 'N') return true;
    else return false;
}

bool check_vma(char& chr)
{
    if (chr == 'v' || chr == 'V' || chr == 'm' || chr == 'M' || chr == 'A' || chr == 'a') return true;
    else return false;

}