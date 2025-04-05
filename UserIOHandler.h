#ifndef USER_IO_HANDLER_H
#define USER_IO_HANDLER_H

#include <string>

class UserIOHandler   {
    public:
        int getNonZeroInt(const std::string& prompt);
        int getPosOneInt(const std::string& prompt);
        double getNonZeroDouble(const std::string& prompt);

};

#endif //USER_IO_HANDLER_H