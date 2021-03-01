#pragma once
#include <stdint.h>
#include <string>
#include <boost/operators.hpp>
namespace TMS
{
    class mTimestamp :public boost::equality_comparable<mTimestamp>,
                      public boost::less_than_comparable<mTimestamp> 
    {     
        public:
            static const int32_t microSecondPerSecond=1000*1000;
            mTimestamp(int64_t t);
            ~mTimestamp();
            static mTimestamp now();
            static mTimestamp invalid();
            std::string toString();
            std::string toFormatString();
            int64_t getMicrosecond(){return microsecond;}
            int64_t getSecond(){return microsecond/microSecondPerSecond;}
            static mTimestamp fromUnixTime(time_t t);
            static mTimestamp fromUnixTime(time_t t,int64_t micro);

        private:
            int64_t microsecond; 
    };
    inline bool operator<(mTimestamp lhs, mTimestamp rhs)
    {
    return lhs.getMicrosecond() < rhs.getMicrosecond();
    }

    inline bool operator==(mTimestamp lhs, mTimestamp rhs)
    {
    return lhs.getMicrosecond() == rhs.getMicrosecond();
    }
    inline double timeDifference(mTimestamp high, mTimestamp low)
    {
        int64_t diff = high.getMicrosecond() - low.getMicrosecond();
        return static_cast<double>(diff) / mTimestamp::microSecondPerSecond;
    }
} // namespace TMS