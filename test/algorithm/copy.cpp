/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#include <boost/detail/lightweight_test.hpp>
#include <boost/fusion/container/vector/vector.hpp>
#include <boost/fusion/container/list/list.hpp>
#include <boost/fusion/sequence/comparison.hpp>
#include <boost/fusion/algorithm/auxiliary/copy.hpp>

#include "../compile_time/sfinae_friendly.hpp"

// FIXME:
//SFINAE_FRIENDLY_ASSERT((boost::fusion::result_of::copy<sfinae_friendly::v0, sfinae_friendly::v1>));
//SFINAE_FRIENDLY_ASSERT((boost::fusion::result_of::copy<sfinae_friendly::v1, sfinae_friendly::v2>));
//SFINAE_FRIENDLY_ASSERT((boost::fusion::result_of::copy<sfinae_friendly::v2, sfinae_friendly::v3>));
SFINAE_FRIENDLY_ASSERT((boost::fusion::result_of::copy<int, sfinae_friendly::v1>));
SFINAE_FRIENDLY_ASSERT((boost::fusion::result_of::copy<sfinae_friendly::v1, int>));
SFINAE_FRIENDLY_ASSERT((boost::fusion::result_of::copy<int, int>));
int
main()
{
    {
        boost::fusion::vector<int, short, double> v(1, 2, 3);
        boost::fusion::list<int, short, double> l;

        boost::fusion::copy(v, l);
        BOOST_TEST(v == l);
    }

    return boost::report_errors();
}

