// Copyright 2013 Daniel Parker
// Distributed under Boost license

#include <boost/test/unit_test.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include "jsoncons/json.hpp"
#include "jsoncons/json_serializer.hpp"
#include "my_custom_data.hpp"
#include <sstream>
#include <vector>
#include <utility>
#include <ctime>

using jsoncons::json_serializer;
using jsoncons::output_format;
using jsoncons::json;
using jsoncons::wjson;
using jsoncons::basic_json_reader;
using std::string;
using boost::numeric::ublas::matrix;

BOOST_AUTO_TEST_CASE(test_is_type)
{
    json obj;
    BOOST_CHECK(obj.is_undefined());
    std::cout << "HERE!!!"  << ", type=" << obj.type() <<  std::endl;

    // tests for proxy is_type methods
    obj["string"] = "val1";
    std::cout << "type=" << obj.type() << std::endl;

    BOOST_CHECK(obj.is_object());



    BOOST_CHECK(obj["string"].is_string());

    obj["double"] = 10.7;
    BOOST_CHECK(obj["double"].is_double());

    obj["int"] = -10;
    BOOST_CHECK(obj["int"].is_longlong());

    obj["uint"] = 10u;
    BOOST_CHECK(obj["uint"].is_ulonglong());

    obj["long"] = static_cast<long>(10);
    BOOST_CHECK(obj["long"].is_longlong());

    obj["ulong"] = static_cast<unsigned long>(10);
    BOOST_CHECK(obj["ulong"].is_ulonglong());

    obj["longlong"] = static_cast<long long>(10);
    BOOST_CHECK(obj["longlong"].is_longlong());

    obj["ulonglong"] = static_cast<unsigned long long>(10);
    BOOST_CHECK(obj["ulonglong"].is_ulonglong());

    obj["true"] = true;
    BOOST_CHECK(obj["true"].is_bool());

    obj["false"] = false;
    BOOST_CHECK(obj["false"].is_bool());

    obj["null1"] = json::null;
    BOOST_CHECK(obj["null1"].is_null());

    obj["object"] = json();
    BOOST_CHECK(obj["object"].is_undefined());

    obj["array"] = json(json::an_array);
    BOOST_CHECK(obj["array"].is_array());

    matrix<double> A;
    obj.set_custom_data("custom",A);
    BOOST_CHECK(obj["custom"].is_custom());

    // tests for json is_type methods


    json str = obj["string"];
    BOOST_CHECK(str.is_string());
}

