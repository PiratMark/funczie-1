#include <iostream>

using namespace std;


bool definitionOfLeapYear(int);
int calculateDayCount(int, int, int, int, int, int);
bool validationData(int, int, int);


int main()
{
    setlocale(LC_ALL, "ru");
    int startDay;
    int startMonth;
    int startYear;
    int finishDay;
    int finishMonth;
    int finishYear;

    cout << "Введите начальную дату ""день месяц год"" (через пробел или ввод):" << endl;
    cin >> startDay >> startMonth >> startYear;
    if (!validationData(startDay, startMonth, startYear))
    {
        cout << "Некорректные исходные данные " << endl;
        return 1;
    }

    cout << "Введите дату окончания ""день месяц год"" (через пробел или ввод).:" << endl;
    cin >> finishDay >> finishMonth >> finishYear;
    if (!validationData(finishDay, finishMonth, finishYear))
    {
        cout << "Некорректные конечные данные " << endl;
        return 1;
    }

    if (calculateDayCount(startDay, startMonth, startYear, finishDay, finishMonth, finishYear) < 0)
    {
        cout << "День окончания должен быть позже дня начала " << endl;
        return 1;
    }

    cout << "Между " << startDay << "." << startMonth << "." << startYear << " и " <<
        finishDay << "." << finishMonth << "." << finishYear << " = " <<
        calculateDayCount(startDay, startMonth, startYear, finishDay, finishMonth, finishYear) <<
        " дней " << endl;
}

bool definitionOfLeapYear(int year)
{
    if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
    {
        return true;
    }
    return false;
}

int calculateDayCount(int sDay, int sMon, int sYear, int fDay, int fMon, int fYear)
{
    int result = 0;

    if (fYear - sYear < 0)
    {
        return -1;
    }
    for (int i = sYear; i < fYear; i++)
    {
        result += (definitionOfLeapYear(i) ? 366 : 365);
    }
    for (int i = 1; i < fMon; i++)
    {
        switch (i)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            result += 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            result += 30;
            break;
        case 2:
            result += (definitionOfLeapYear(fYear) ? 29 : 28);
            break;
        default:
            break;
        }
    }
    result += fDay;
    for (int i = 1; i < sMon; i++)
    {
        switch (i)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            result -= 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            result -= 30;
            break;
        case 2:
            result -= (definitionOfLeapYear(sYear) ? 29 : 28);
            break;
        default:
            break;
        }
    }
    result -= sDay;
    return result;
}

bool validationData(int day, int month, int year)
{
    bool result = true;
    if (day < 1 || year < 1 || year > 9999)
    {
        result = false;
    }
    else
    {
        switch (month)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (day > 31)
            {
                result = false;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (day > 30)
            {
                result = false;
            }
            break;
        case 2:
            if (definitionOfLeapYear(year))
            {
                if (day > 29)
                {
                    result = false;
                }
            }
            else
            {
                if (day > 28)
                {
                    result = false;
                }
            }
            break;
        default:
            result = false;
            break;
        }
    }



    return result;
}
