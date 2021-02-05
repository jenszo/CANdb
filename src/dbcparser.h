#ifndef __CANDB_H
#define __CANDB_H

// Note: This file should never be published for linkage
// as a public header. CanDbOrError depends on an foss implementation
// of the proposed std::expected - which is nice but forces any consuming
// code to pull in and use the very same std::except header. If not - or other
// dependencies may ship with a different variant - chances are that different versions
// will eventually break the ABI!

// This file is for internal purposes only for for compiling in!
// For the public API (which exchanges PoD only) include dbc.h

#include "parser.hpp"

namespace CANdb {

struct DBCParser : public Parser<DBCParser> {
    CanDbOrError parse(const std::string& data) noexcept;
};
} // namespace CANdb

#endif /* !__CANDB_H */
