/*=============================================================================
    Copyright (c) 2015 Kohei Takahashi

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <boost/fusion/algorithm/query.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/type_traits/is_same.hpp>

#include "../compile_time/sfinae_friendly.hpp"
namespace fusion = boost::fusion;

// any
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::all<int                , int>));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::all<sfinae_friendly::v0, int>));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::all<sfinae_friendly::v1, int>));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::all<sfinae_friendly::v2, int>));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::all<sfinae_friendly::v3, int>));

// all
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::any<int                , int>));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::any<sfinae_friendly::v0, int>));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::any<sfinae_friendly::v1, int>));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::any<sfinae_friendly::v2, int>));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::any<sfinae_friendly::v3, int>));

// none
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::none<int                , int>));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::none<sfinae_friendly::v0, int>));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::none<sfinae_friendly::v1, int>));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::none<sfinae_friendly::v2, int>));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::none<sfinae_friendly::v3, int>));

// find
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::find<int, int>));

// find_if
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::find_if<sfinae_friendly::v0, char>));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::find_if<sfinae_friendly::v1, char>));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::find_if<sfinae_friendly::v2, char>));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::find_if<sfinae_friendly::v3, char>));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::find_if<int                , char>));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::find_if<int                , is_same<_, char> >));

// count
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::count<int, int>));

// count_if
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::count_if<sfinae_friendly::v0, char>));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::count_if<sfinae_friendly::v1, char>));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::count_if<sfinae_friendly::v2, char>));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::count_if<sfinae_friendly::v3, char>));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::count_if<int                , char>));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::count_if<int                , is_same<_, char> >));
