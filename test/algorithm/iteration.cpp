/*=============================================================================
    Copyright (c) 2015 Kohei Takahashi

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <boost/fusion/algorithm/iteration.hpp>
#include <boost/fusion/iterator/deref.hpp>

#include "../compile_time/sfinae_friendly.hpp"
namespace fusion = boost::fusion;

struct null
{
    template <typename> struct result;

    template <typename This, typename S, typename D>
    struct result<This(S, D)> { typedef S type; };

    template <typename This, typename T>
    struct result<This(T)> { typedef T type; };
};

// fold
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::fold<int                , int, null>));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::fold<sfinae_friendly::v0, int, int >));

// reverse_fold
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::reverse_fold<int                , int, null>));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::reverse_fold<sfinae_friendly::v0, int, int >));

// iter_fold
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::<int                , int, null>));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::<sfinae_friendly::v0, int, int >));

// reverse_iter_fold
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::<int                , int, null>));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::<sfinae_friendly::v0, int, int >));

// accumulate
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::accumulate<int                , int, null>));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::accumulate<sfinae_friendly::v0, int, int >));

// for_each
// FIXME
//SFINAE_FRIENDLY_ASSERT((boost::fusion::result_of::for_each<int                , null>));
//SFINAE_FRIENDLY_ASSERT((boost::fusion::result_of::for_each<int                , int >));
//SFINAE_FRIENDLY_ASSERT((boost::fusion::result_of::for_each<sfinae_friendly::v0, int >));
//SFINAE_FRIENDLY_ASSERT((boost::fusion::result_of::for_each<sfinae_friendly::v1, int >));
//SFINAE_FRIENDLY_ASSERT((boost::fusion::result_of::for_each<sfinae_friendly::v2, int >));
//SFINAE_FRIENDLY_ASSERT((boost::fusion::result_of::for_each<sfinae_friendly::v3, int >));

