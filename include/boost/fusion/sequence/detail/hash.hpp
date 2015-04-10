/*=============================================================================
    Copyright (c) 2015 Kohei Takahashi

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef FUSION_HASH_28032015_1044
#define FUSION_HASH_28032015_1044

#include <boost/config.hpp>

#if defined(BOOST_NO_CXX11_HDR_FUNCTIONAL) && \
  !(defined(__WAVE__) && defined(BOOST_FUSION_CREATE_PREPROCESSED_FILES))
#define BOOST_FUSION_NO_STD_HASH_SPECIALIZATION
#define BOOST_FUSION_STD_HASH_SPECIALIZATION_N(signature, N)
#define BOOST_FUSION_STD_HASH_SPECIALIZATION_V(signature)
#else
#include <functional>
#include <boost/functional/hash.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>

#define BOOST_FUSION_STD_HASH_SPECIALIZATION_N(signature, N)                    \
    namespace std                                                               \
    {                                                                           \
        template <BOOST_PP_ENUM_PARAMS(N, typename A)>                          \
        struct hash<signature<BOOST_PP_ENUM_PARAMS(N, A)> >                     \
            : ::boost::hash<signature<BOOST_PP_ENUM_PARAMS(N, A)> > { };        \
    }                                                                           \
// BOOST_FUSION_STD_HASH_SPECIALIZATION_N

#define BOOST_FUSION_STD_HASH_SPECIALIZATION_V(signature)       \
    namespace std                                               \
    {                                                           \
        template <typename ...A>                                \
        struct hash<signature<A...> >                           \
            : ::boost::hash<signature<A...> > { };              \
    }                                                           \
// BOOST_FUSION_STD_HASH_SPECIALIZATION_V

#endif

#endif
