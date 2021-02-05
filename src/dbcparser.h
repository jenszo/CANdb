#ifndef __CANDB_H
#define __CANDB_H

// Note: This file should never be published
// as a public header. CanDbOrError depends on an foos implemnetation
// of the proposed std::expect - which is nice but forces any consuming
// code to pull in and use the very same std::except header. If not - or other
// dependencies ship with a different variant - , chances are that different versions
// will eventually break the binary ABI!

// This file is for internal purposes only! For the public API (which exchanges PoD only)
// include dbc.h

#include "parser.hpp"

namespace CANdb {

struct DBCParser : public Parser<DBCParser> {
    CanDbOrError parse(const std::string& data) noexcept;
};
} // namespace CANdb

#endif /* !__CANDB_H */
