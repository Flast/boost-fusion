/*=============================================================================
    Copyright (c) 2014 Christoph Weiss

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#include <string>
#include <utility>

#include <boost/detail/lightweight_test.hpp>
#include <boost/fusion/sequence/hash.hpp>
#include <boost/functional/hash.hpp>

#ifdef BOOST_NO_CXX11_HDR_FUNCTIONAL
#   define BOOST_CXX11_FUNCTIONAL_TEST(cond)
#else
#   define BOOST_CXX11_FUNCTIONAL_TEST BOOST_TEST
template <typename Seq>
inline typename std::hash<Seq>::result_type
std_hash_value(Seq const &seq)
{
    return std::hash<Seq>()(seq);
}
#endif

void
hash_test()
{
    using namespace boost::fusion;

    const FUSION_SEQUENCE<int, char, bool, std::string> v0(42, 'x', false, "Aurea prima");
    const FUSION_SEQUENCE<int, char, bool, std::string> v1(42, 'x', false, "Aurea prima");
    BOOST_TEST(hash_value(v0) == hash_value(v1));
    BOOST_CXX11_FUNCTIONAL_TEST(std_hash_value(v0) == std_hash_value(v1));

    const FUSION_SEQUENCE<int, char, bool, std::string> w(41, 'x', false, "Aurea prima");
    BOOST_TEST(hash_value(w) != hash_value(v0));
    BOOST_CXX11_FUNCTIONAL_TEST(std_hash_value(w) != std_hash_value(v0));

    const FUSION_SEQUENCE<int, char, bool, std::string> x(42, 'y', false, "Aurea prima");
    BOOST_TEST(hash_value(x) != hash_value(v0));
    BOOST_CXX11_FUNCTIONAL_TEST(std_hash_value(x) != std_hash_value(v0));

    const FUSION_SEQUENCE<int, char, bool, std::string> y(42, 'x', true, "Aurea prima");
    BOOST_TEST(hash_value(y) != hash_value(v0));
    BOOST_CXX11_FUNCTIONAL_TEST(std_hash_value(y) != std_hash_value(v0));

    const FUSION_SEQUENCE<int, char, bool, std::string> z(42, 'x', false, "quae vindice nullo");
    BOOST_TEST(hash_value(z) != hash_value(v0));
    BOOST_CXX11_FUNCTIONAL_TEST(std_hash_value(z) != std_hash_value(v0));
}
