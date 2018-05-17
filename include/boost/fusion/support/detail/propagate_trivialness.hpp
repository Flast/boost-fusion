/*=============================================================================
    Copyright (c) 2018 Kohei Takahashi

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef BOOST_FUSION_SUPPORT_DETAIL_PROPAGATE_TRIVIALNESS
#define BOOST_FUSION_SUPPORT_DETAIL_PROPAGATE_TRIVIALNESS

#include <boost/fusion/support/config.hpp>
#if !defined(BOOST_NO_CXX11_DEFAULTED_FUNCTIONS) && !defined(BOOST_NO_CXX11_DEFAULTED_MOVES)
#   define BOOST_FUSION_DETAIL_PROPAGATE_TRIVIALNESS_CONFORMING
#endif

#include <boost/fusion/support/detail/is_trivially_copyable.hpp>
#ifdef BOOST_FUSION_DETAIL_PROPAGATE_TRIVIALNESS_CONFORMING
#   include <boost/mpl/bool.hpp>
#   include <boost/mpl/if.hpp>
#   include <boost/type_traits/remove_cv.hpp>
#   include <boost/type_traits/has_trivial_assign.hpp>
#   include <boost/type_traits/has_trivial_copy.hpp>
#   include <boost/type_traits/is_copy_constructible.hpp>
#   include <boost/type_traits/is_copy_assignable.hpp>
#   include <boost/type_traits/is_class.hpp>
#   include <boost/type_traits/is_union.hpp>
#ifndef BOOST_NO_CXX11_RVALUE_REFERRENCES
#   include <boost/type_traits/has_trivial_move_assign.hpp>
#   include <boost/type_traits/has_trivial_move_constructor.hpp>
#   include <boost/type_traits/is_constructible.hpp>
#   include <boost/type_traits/is_assignable.hpp>
#endif
#endif

namespace boost { namespace fusion { namespace detail
{

template <bool> struct propagate_trivially_copyable_base{ };
template<> struct propagate_trivially_copyable_base<false>
{
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    BOOST_DEFAULTED_FUNCTION(propagate_trivially_copyable_base(), {})

    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    propagate_trivially_copyable_base(propagate_trivially_copyable_base const&) BOOST_NOEXCEPT { }
};

template <typename T>
struct propagate_trivially_copyable
  : propagate_trivially_copyable_base<is_trivially_copyable<T>::value> { };

#ifdef BOOST_FUSION_DETAIL_PROPAGATE_TRIVIALNESS_CONFORMING

template <typename T>
struct is_candidate_trivially_copy_constructible
  : mpl::bool_<has_trivial_copy<T>::value || !is_copy_constructible<T>::value> { };
template <typename T>
struct is_candidate_trivially_copy_assignable
  : mpl::bool_<has_trivial_assign<T>::value || !is_copy_assignable<T>::value> { };
#ifndef BOOST_NO_CXX11_RVALUE_REFERRENCES
template <typename T>
struct is_candidate_trivially_move_constructible
  : mpl::bool_<has_trivial_move_constructor<T>::value || !is_constructible<T, T>::value> { };
template <typename T>
struct is_candidate_trivially_move_assignable
  : mpl::bool_<has_trivial_move_assign<T>::value || !is_assignable<T, T>::value> { };
#endif


template <bool> struct copy_ctor { };
template<> struct copy_ctor<false>
{
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    copy_ctor(copy_ctor const&) BOOST_NOEXCEPT { }

    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    copy_ctor() = default;
#ifndef BOOST_NO_CXX11_RVALUE_REFERRENCES
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    copy_ctor(copy_ctor&&) = default;
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    copy_ctor& operator=(copy_ctor&&) = default;
#endif
};

template <bool> struct copy_assign { };
template<> struct copy_assign<false>
{
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    copy_assign& operator=(copy_assign const&) BOOST_NOEXCEPT { return *this; }

    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    copy_assign() = default;
#ifndef BOOST_NO_CXX11_RVALUE_REFERRENCES
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    copy_assign(copy_assign&&) = default;
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    copy_assign& operator=(copy_assign&&) = default;
#endif
};

#ifndef BOOST_NO_CXX11_RVALUE_REFERRENCES
template <bool> struct move_ctor { };
template<> struct move_ctor<false>
{
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    move_ctor(move_ctor&&) BOOST_NOEXCEPT { }

    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    move_ctor() = default;
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    move_ctor(move_ctor const&) = default;
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    move_ctor& operator=(move_ctor const&) = default;
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    move_ctor& operator=(move_ctor&&) = default;
};

template <bool> struct move_assign { };
template<> struct move_assign<false>
{
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    move_assign& operator=(move_assign&&) BOOST_NOEXCEPT { return *this; }

    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    move_assign() = default;
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    move_assign(move_assign const&) = default;
    BOOST_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    move_assign(move_assign&&) = default;
    BOOST_CXX14_CONSTEXPR BOOST_FUSION_GPU_ENABLED
    move_assign& operator=(move_assign const&) = default;
};
#endif

template <bool cc, bool ca, bool mc = true, bool ma = true>
struct propagate_class_trivialness_base
  : copy_ctor<cc>, copy_assign<ca>
#ifndef BOOST_NO_CXX11_RVALUE_REFERRENCES
  , move_ctor<mc>, move_assign<ma>
#endif
{ };

template <typename T>
struct propagate_class_trivialness
  : propagate_class_trivialness_base<
      is_candidate_trivially_copy_constructible<T>::value
    , is_candidate_trivially_copy_assignable<T>::value
#ifndef BOOST_NO_CXX11_RVALUE_REFERRENCES
    , is_candidate_trivially_move_constructible<T>::value
    , is_candidate_trivially_move_assignable<T>::value
#endif
  >
{ };

#define BOOST_FUSION_DETAIL_PROPAGATE_TRIVIALNESS_BASE(T) \
  mpl::if_c< \
      is_class<T>::value || is_union<T>::value \
    , propagate_class_trivialness<typename remove_cv<T>::type> \
    , propagate_trivially_copyable<T> \
  >::type \
// BOOST_FUSION_DETAIL_PROPAGATE_TRIVIALNESS_BASE

#else // conformance

#define BOOST_FUSION_DETAIL_PROPAGATE_TRIVIALNESS_BASE(T) \
  propagate_trivially_copyable<T> \
// BOOST_FUSION_DETAIL_PROPAGATE_TRIVIALNESS_BASE

#endif // conformance

template <typename T>
struct propagate_trivialness : BOOST_FUSION_DETAIL_PROPAGATE_TRIVIALNESS_BASE(T) { };

}}} // namespace boost::fusion::detail

#endif

