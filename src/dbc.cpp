
#include "dbc.h"
#include "log.hpp"
#include "dbcparser.h"

typedef struct _dptr {
    CANdb::DBCParser parser;
    CANdb_t db;
} _dptr_t;

CANdb::DBCSimpleParser::DBCSimpleParser()
{
    _d = new _dptr_t();
}

CANdb::DBCSimpleParser::~DBCSimpleParser()
{
    delete static_cast<_dptr*>(_d);
}

const CANdb_t * const CANdb::DBCSimpleParser::parse(const std::string &data) noexcept
{
    _dptr_t* p = reinterpret_cast<_dptr_t*>(_d);
    assert(p);

    try {
        p->db = *(p->parser.parse(data).map_error([](CANdb::ParserError t) -> CANdb::CanDbOrError {
            throw std::runtime_error(t.message());
        }));
    }
    catch(const std::exception& ex) {
        cdb_error("Something went wrong while parsing: {} ", ex.what());
    }

    return &(p->db);
}
