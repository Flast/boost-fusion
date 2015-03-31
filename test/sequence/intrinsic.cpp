/*=============================================================================
    Copyright (c) 2015 Kohei Takahashi

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <boost/fusion/container/vector.hpp>
#include <boost/fusion/sequence/intrinsic.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/integral_c.hpp>

#include "../compile_time/sfinae_friendly.hpp"
namespace fusion = boost::fusion;
namespace mpl = boost::mpl;

// begin
SFINAE_FRIENDLY_ASSERT((fusion::result_of::begin<int>));

// end
SFINAE_FRIENDLY_ASSERT((fusion::result_of::end<int>));

// empty
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::empty<int>));

// front
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::front<int>));

// back
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::back<int>));

// size
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::size<int>));

// at
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::at<int, int                      >));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::at<int, mpl::int_<0>             >));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::at<int, mpl::integral_c<long, 0> >));

// at_c
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::at_c<int, 0>));

// value_at
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::value_at<int, int                      >));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::value_at<int, mpl::int_<0>             >));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::value_at<int, mpl::integral_c<long, 0> >));

// value_at_c
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::value_at_c<int, 0>));

// at_key
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::at_key<int, int>));

// value_at_key
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::value_at_key<int, int>));

// swap
SFINAE_FRIENDLY_ASSERT((fusion::result_of::swap<fusion::vector0<>, int               >));
SFINAE_FRIENDLY_ASSERT((fusion::result_of::swap<int              , fusion::vector0<> >));
SFINAE_FRIENDLY_ASSERT((fusion::result_of::swap<int              , int               >));
