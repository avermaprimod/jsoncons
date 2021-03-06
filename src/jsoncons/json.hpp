// Copyright 2013 Daniel Parker
// Distributed under the Boost license, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

// See https://sourceforge.net/projects/jsoncons/files/ for latest version
// See https://sourceforge.net/p/jsoncons/wiki/Home/ for documentation.

#ifndef JSONCONS_JSON_HPP
#define JSONCONS_JSON_HPP
 
#include "jsoncons/json1.hpp"
#include "jsoncons/json2.hpp"

namespace jsoncons {

typedef basic_json<char> json;
typedef basic_json<wchar_t> wjson;

}

#endif
