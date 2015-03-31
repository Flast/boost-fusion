/*=============================================================================
    Copyright (c) 2014 Kohei Takahashi

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#include <boost/config.hpp>

#if !defined(BOOST_NO_CXX11_RVALUE_REFERENCES)

#include <boost/core/lightweight_test.hpp>
#include <boost/fusion/container/vector/vector.hpp>
#include <boost/fusion/container/list/list.hpp>
#include <boost/fusion/sequence/comparison.hpp>
#include <boost/fusion/algorithm/auxiliary/move.hpp>
#include <utility>

#include "../compile_time/sfinae_friendly.hpp"

// FIXME:
//SFINAE_FRIENDLY_ASSERT((boost::fusion::result_of::move<sfinae_friendly::v0, sfinae_friendly::v1>));
//SFINAE_FRIENDLY_ASSERT((boost::fusion::result_of::move<sfinae_friendly::v1, sfinae_friendly::v2>));
//SFINAE_FRIENDLY_ASSERT((boost::fusion::result_of::move<sfinae_friendly::v2, sfinae_friendly::v3>));
SFINAE_FRIENDLY_ASSERT((boost::fusion::result_of::move<int, sfinae_friendly::v1>));
SFINAE_FRIENDLY_ASSERT((boost::fusion::result_of::move<sfinae_friendly::v1, int>));
SFINAE_FRIENDLY_ASSERT((boost::fusion::result_of::move<int, int>));

int main()
{
    {
        boost::fusion::vector<int, short, double> v(1, 2, 3);
        boost::fusion::list<int, short, double> l1 = v;
        boost::fusion::list<int, short, double> l2;

        boost::fusion::move(std::move(v), l2);
        BOOST_TEST(l1 == l2);
    }

    return boost::report_errors();
}

#else

int main()
{
    // no thing to do
}

#endif

