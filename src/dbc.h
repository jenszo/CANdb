#ifndef __DBC_H_
#define __DBC_H_

#include "cantypes.hpp"

namespace CANdb {

struct DBCSimpleParser {

    /// Default constructor
    DBCSimpleParser();

    /// Default destructor
    virtual ~DBCSimpleParser();

    /**
     * @brief Parse a vector compatible CAN database file.
     * @param data String content of a DBC database file
     * @return nullptr if file not found or malformed; CANdb_t reference in case of success
     * @note The CANdb_t memory is mangaged by the parser object and depends on its lifetime
     */
    const CANdb_t * const parse(const std::string& data) noexcept;

protected:
    /// d-Pointer
    void * _d { nullptr };
};

} // namespace CANdb



#endif // __DBC_H_
