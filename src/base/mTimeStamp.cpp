#include "mTimestamp.h"
#include <sys/time.h>
namespace BASE
{
    mTimestamp::mTimestamp(int64_t t):microsecond(t){}
    mTimestamp::~mTimestamp(){}
    mTimestamp mTimestamp::now(){
        struct timeval tv;
        gettimeofday(&tv,NULL);
        return mTimestamp(tv.tv_sec*microSecondPerSecond+tv.tv_usec);
    }
    mTimestamp mTimestamp::invalid(){
        return mTimestamp(0);
    }
    std::string mTimestamp::toString(){
        return std::to_string(microsecond);
    }
    std::string mTimestamp::toFormatString(){
        char buf[64]={};
        struct tm tm_time;
        int microseconds=microsecond%microSecondPerSecond;
        snprintf(buf, sizeof(buf), "%4d%02d%02d %02d:%02d:%02d.%06d",
             tm_time.tm_year + 1900, tm_time.tm_mon + 1, tm_time.tm_mday,
             tm_time.tm_hour, tm_time.tm_min, tm_time.tm_sec,
             microseconds);
        return buf;
    }
    mTimestamp mTimestamp::fromUnixTime(time_t t){
        fromUnixTime(t,0);
    }
    mTimestamp mTimestamp::fromUnixTime(time_t t,int64_t micro){
        return mTimestamp( static_cast<int64_t>(t)*microSecondPerSecond+micro);
    }
} // namespace MTM


