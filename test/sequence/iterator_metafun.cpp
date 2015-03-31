/*=============================================================================
    Copyright (c) 2015 Kohei Takahashi

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <boost/fusion/iterator.hpp>
#include <boost/fusion/sequence/intrinsic/end.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/integral_c.hpp>

#include "../compile_time/sfinae_friendly.hpp"

namespace fusion = boost::fusion;

typedef fusion::result_of::end<sfinae_friendly::v0>::type end;

// value_of
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::value_of<int>));

// deref
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::deref<int>));

// next
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::next<int>));

// prior
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::prior<int>));

// equal_to
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::equal_to<end, int>));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::equal_to<int, end>));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::equal_to<int, int>));

// distance
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::distance<end, int>));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::distance<int, end>));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::distance<int, int>));

// advance
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::advance<int, int                      >));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::advance<int, mpl::int_<0>             >));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::advance<int, mpl::integral_c<long, 0> >));

// advance_c
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::advance_c<int, 0>));

// key_of
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::key_of<int>));

// value_of_data
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::value_of_data<int>));

// deref_data
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::deref_data<int>));
