/*=============================================================================
    Copyright (c) 2001-2011 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !defined(FUSION_FRONT_09162005_0343)
#define FUSION_FRONT_09162005_0343

#include <boost/fusion/support/config.hpp>
#include <boost/fusion/support/detail/enabler.hpp>
#include <boost/fusion/sequence/intrinsic_fwd.hpp>
#include <boost/fusion/sequence/intrinsic/begin.hpp>
#include <boost/fusion/iterator/deref.hpp>

namespace boost { namespace fusion
{
    namespace detail
    {
        template <typename Sequence, typename = void>
        struct front_impl
        {};

        template <typename Sequence>
        struct front_impl<Sequence,
            typename detail::enabler<typename result_of::begin<Sequence>::type>::type>
            : result_of::deref<typename result_of::begin<Sequence>::type>
        {};
    }

    namespace result_of
    {
        template <typename Sequence>
        struct front : detail::front_impl<Sequence> {};
    }

    template <typename Sequence>
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    inline typename result_of::front<Sequence>::type
    front(Sequence& seq)
    {
        return *fusion::begin(seq);
    }

    template <typename Sequence>
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    inline typename result_of::front<Sequence const>::type
    front(Sequence const& seq)
    {
        return *fusion::begin(seq);
    }
}}

#endif
