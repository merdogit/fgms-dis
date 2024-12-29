#include <fg_util.hxx>
#include <stdio.h>

//////////////////////////////////////////////////////////////////////
/**
 * @brief convert a unix timestamp to a string
 * representation of a date
 */
string
timestamp_to_datestr(
    time_t date)
{
        struct tm *tmr;
        char buf[64];
        tmr = localtime(&date);
        sprintf(buf, "%02d.%02d.%04d %02d:%02d:%02d ",
                tmr->tm_mday,
                tmr->tm_mon + 1,
                tmr->tm_year + 1900,
                tmr->tm_hour,
                tmr->tm_min,
                tmr->tm_sec);
        return (string)buf;
} // timestamp_to_datestr()
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/**
 * @brief calculate the difference of a timestamp to now and convert
 * the difference to a string representation of the form "3 days 2 hours"
 */
string
timestamp_to_days(
    time_t Date)
{
        time_t Diff = time(0) - Date;
        return diff_to_days(Diff);
} // timestamp_to_days
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/**
 * @brief convert a time duration expressed in seconds to a string
 * representation of the form "3 days 2 hours"
 */
string
diff_to_days(
    time_t Date)
{
        time_t Diff = Date;
        unsigned int temp = 0;
        string Result;

        if (Diff > 31536000) // years
        {
                temp = Diff / 31536000;
                Result += NumToStr(temp, 0) + " years";
                return Result;
        }
        if (Diff > 86400) // days
        {
                temp = Diff / 86400;
                Result += NumToStr(temp, 0) + " days";
                return Result;
        }
        if (Diff > 3600) // hours
        {
                temp = Diff / 3600;
                Result += NumToStr(temp, 0) + " hours";
                return Result;
        }
        if (Diff > 60) // minutes
        {
                temp = Diff / 60;
                Result += NumToStr(temp, 0) + " minutes";
                return Result;
        }
        temp = Diff;
        Result += NumToStr(temp, 0) + " seconds";
        return Result;

} // diff_to_days
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/**
 * Convert a byte counter to a string representation of the form
 * "3.7 Gib" (3.7 Gigibit).
 * The units conform to IEC,
 * see http://physics.nist.gov/cuu/Units/binary.html
 */
string
byte_counter(
    double bytes)
{
        double ret_val;
        string ret_str;

        if (bytes > 1099511627776.)
        {
                ret_val = (bytes / 1099511627776.);
                ret_str = NumToStr(ret_val) + " TiB";
                return ret_str;
        }
        else if (bytes > 1073741824.)
        {
                ret_val = (bytes / 1073741824.);
                ret_str = NumToStr(ret_val) + " GiB";
                return ret_str;
        }
        else if (bytes > 1048576)
        {
                ret_val = (bytes / 1048576);
                ret_str = NumToStr(ret_val) + " MiB";
                return ret_str;
        }
        else if (bytes > 1024)
        {
                ret_val = (bytes / 1024);
                ret_str = NumToStr(ret_val) + " KiB";
                return ret_str;
        }
        ret_str = NumToStr(bytes) + " b";
        return ret_str;
} // byte_counter()
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
/**
 * @brief compute milliseconds of current hour
 */
void computeMilliSecHour(unsigned int *timeMilliSec)
{
        SYSTEMTIME sysTime;
        // get system time
        GetSystemTime(&sysTime);
        // compute milliseconds of current hour
        *timeMilliSec = sysTime.wMinute * 60000 + sysTime.wSecond * 1000 + sysTime.wMilliseconds;
} 
// computeMilliSecHour
//////////////////////////////////////////////////////////////////////

// me-add-b
void GetSystemTime(SYSTEMTIME *tim)
{
        auto now = std::chrono::system_clock::now();

        auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();

        int milliseconds = millis % 1000;
        std::time_t seconds = millis / 1000;

        std::tm tm = *std::localtime(&seconds);

        tim->wYear = tm.tm_year + 1900;
        tim->wMonth = tm.tm_mon + 1;
        tim->wDayOfWeek = tm.tm_wday;
        tim->wDay = tm.tm_mday;
        tim->wHour = tm.tm_hour;
        tim->wMinute = tm.tm_min;
        tim->wSecond = tm.tm_sec;
        tim->wMilliseconds = milliseconds;
}
// me-add-e

//////////////////////////////////////////////////////////////////////
/**
 * @brief compute milliseconds of current hour
 */
void computeMilliSecDay(double *timeMilliSec)
{
        SYSTEMTIME sysTime;
        // get system time
        GetSystemTime(&sysTime);
        // compute milliseconds of current day
        *timeMilliSec = sysTime.wHour * 3600000 + sysTime.wMinute * 60000 + sysTime.wSecond * 1000 + sysTime.wMilliseconds;
} // computeMilliSecDay
//////////////////////////////////////////////////////////////////////
