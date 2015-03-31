/*=============================================================================
    Copyright (c) 2015 Kohei Takahashi

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <boost/fusion/container/vector.hpp>
#include <boost/fusion/algorithm/auxiliary.hpp>

#include "../compile_time/sfinae_friendly.hpp"
namespace fusion = boost::fusion;

// copy
SFINAE_FRIENDLY_ASSERT((fusion::result_of::copy<fusion::vector0<>, int>));
SFINAE_FRIENDLY_ASSERT((fusion::result_of::copy<int, fusion::vector0<> >));
SFINAE_FRIENDLY_ASSERT((fusion::result_of::copy<int, int>));

#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
// move
SFINAE_FRIENDLY_ASSERT((fusion::result_of::move<fusion::vector0<>, int>));
SFINAE_FRIENDLY_ASSERT((fusion::result_of::move<int, fusion::vector0<> >));
SFINAE_FRIENDLY_ASSERT((fusion::result_of::move<int, int>));
#endif
