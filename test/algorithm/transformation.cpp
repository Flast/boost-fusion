/*=============================================================================
    Copyright (c) 2015 Kohei Takahashi

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <boost/fusion/algorithm/transformation.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/type_traits/is_same.hpp>

#include "../compile_time/sfinae_friendly.hpp"
namespace fusion = boost::fusion;
using boost::is_same;
using boost::mpl::_;
using boost::mpl::identity;

// filter
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::filter<int, int>));

// filter_if
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::filter_if<sfinae_friendly::v0, int              >));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::filter_if<sfinae_friendly::v1, int              >));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::filter_if<sfinae_friendly::v2, int              >));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::filter_if<sfinae_friendly::v3, int              >));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::filter_if<int                , int              >));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::filter_if<int                , is_same<_, char> >));

// transform
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::transform<sfinae_friendly::v0, int         >));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::transform<sfinae_friendly::v1, int         >));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::transform<sfinae_friendly::v2, int         >));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::transform<sfinae_friendly::v3, int         >));
//SFINAE_FRIENDLY_ASSERT((fusion:;result_of::transform<int                , int         >));
//SFINAE_FRIENDLY_ASSERT((fusion:;result_of::transform<int                , identity<_> >));

//SFINAE_FRIENDLY_ASSERT((fusion::result_of::transform<sfinae_friendly::v0, int, int           >));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::transform<sfinae_friendly::v1, int, int           >));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::transform<sfinae_friendly::v2, int, int           >));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::transform<sfinae_friendly::v3, int, int           >));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::transform<int, sfinae_friendly::v0, int           >));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::transform<int, sfinae_friendly::v1, int           >));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::transform<int, sfinae_friendly::v2, int           >));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::transform<int, sfinae_friendly::v3, int           >));

//SFINAE_FRIENDLY_ASSERT((fusion::result_of::transform<sfinae_friendly::v0, int, identity<_> >));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::transform<sfinae_friendly::v1, int, identity<_> >));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::transform<sfinae_friendly::v2, int, identity<_> >));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::transform<sfinae_friendly::v3, int, identity<_> >));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::transform<int, sfinae_friendly::v0, identity<_> >));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::transform<int, sfinae_friendly::v1, identity<_> >));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::transform<int, sfinae_friendly::v2, identity<_> >));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::transform<int, sfinae_friendly::v3, identity<_> >));

//SFINAE_FRIENDLY_ASSERT((fusion:;result_of::transform<int, int, is_same<_, _> >));
//SFINAE_FRIENDLY_ASSERT((fusion:;result_of::transform<int, int, identity<_>   >));

// replace
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::replace<int, int>));

// replace_if
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::replace_if<sfinae_friendly::v0, int             , int>));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::replace_if<sfinae_friendly::v1, int             , int>));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::replace_if<sfinae_friendly::v2, int             , int>));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::replace_if<sfinae_friendly::v3, int             , int>));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::replace_if<int                , is_same<_, char>, int>));

// remove
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::remove<int, int>));

// remove_if
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::remove_if<sfinae_friendly::v0, int            >));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::remove_if<sfinae_friendly::v1, int            >));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::remove_if<sfinae_friendly::v2, int            >));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::remove_if<sfinae_friendly::v3, int            >));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::remove_if<int                , is_same<_, char>));

// reverse
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::reverse<int>));

// clear
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::clear<int>));

// erase
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::erase<int, int>));

// erase_key
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::erase_key<int                , int>));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::erase_key<sfinae_friendly::v0, int>));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::erase_key<sfinae_friendly::v1, int>));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::erase_key<sfinae_friendly::v2, int>));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::erase_key<sfinae_friendly::v3, int>));

// insert
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::insert<int, int, int>));

// insert_range
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::insert_range<int                , int, sfinae_friendly::v0>));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::insert_range<sfinae_friendly::v0, int, int                >));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::insert_range<int                , int, int                >));

// join
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::join<sfinae_friendly::v0, int                >));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::join<int                , sfinae_friendly::v0>));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::join<sfinae_friendly::a0, int                >));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::join<int                , sfinae_friendly::a0>));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::join<int                , int                >));

// zip
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::zip<sfinae_friendly::v0, int                >));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::zip<int                , sfinae_friendly::v0>));
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::zip<int                , int                >));

// pop_back
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::pop_back<int>));

// pop_front
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::pop_front<int>));

// push_back
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::push_back<int, int>));

// push_front
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::push_front<int, int>));

// flatten
// FIXME
//SFINAE_FRIENDLY_ASSERT((fusion::result_of::flatten<int>));
