/*=============================================================================
    Copyright (c) 2018 Kohei Takahashi

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <boost/config.hpp>
#include <boost/fusion/support/detail/propagate_trivialness.hpp>
#include <boost/fusion/support/detail/is_trivially_copyable.hpp>
#include <boost/mpl/assert.hpp>
#include <boost/type_traits/is_convertible.hpp>
#include <boost/type_traits/is_default_constructible.hpp>
#include "trivial.hpp"

using namespace boost;
using namespace boost::fusion::detail;

#ifdef BOOST_FUSION_DETAIL_PROPAGATE_TRIVIALNESS_CONFORMING
#   if defined(BOOST_HAS_TRIVIAL_MOVE_CONSTRUCTOR) && defined(BOOST_HAS_TRIVIAL_MOVE_ASSIGN)
#       define BOOST_FUSION_ASSERT_MOVE_DEFAULTED BOOST_MPL_ASSERT
#   endif
#   define BOOST_FUSION_ASSERT_DEFAULTED BOOST_MPL_ASSERT
#else
#   define BOOST_FUSION_ASSERT_DEFAULTED BOOST_MPL_ASSERT_NOT
#endif
#ifndef BOOST_FUSION_ASSERT_MOVE_DEFAULTED
#   define BOOST_FUSION_ASSERT_MOVE_DEFAULTED BOOST_MPL_ASSERT_NOT
#endif


#ifndef BOOST_FUSION_DETAIL_PROPAGATE_TRIVIALNESS_CONFORMING
BOOST_MPL_ASSERT((is_default_constructible<propagate_base<true> >));
BOOST_MPL_ASSERT((is_default_constructible<propagate_base<false> >));
#else
BOOST_MPL_ASSERT((is_default_constructible<copy_ctor<true> >));
BOOST_MPL_ASSERT((is_default_constructible<copy_ctor<false> >));
BOOST_MPL_ASSERT((is_default_constructible<copy_assign<true> >));
BOOST_MPL_ASSERT((is_default_constructible<copy_assign<false> >));
#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
BOOST_MPL_ASSERT((is_default_constructible<move_ctor<true> >));
BOOST_MPL_ASSERT((is_default_constructible<move_ctor<false> >));
BOOST_MPL_ASSERT((is_default_constructible<move_assign<true> >));
BOOST_MPL_ASSERT((is_default_constructible<move_assign<false> >));
#endif
#endif

#ifndef BOOST_FUSION_DETAIL_PROPAGATE_TRIVIALNESS_CONFORMING
BOOST_FUSION_ASSERT_CWG496((is_trivially_copyable<propagate_base<true> >));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_base<false> >));
#else
BOOST_MPL_ASSERT((is_trivially_copyable<copy_ctor<true> >));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<copy_ctor<false> >));
BOOST_MPL_ASSERT((is_trivially_copyable<copy_assign<true> >));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<copy_assign<false> >));
#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
BOOST_MPL_ASSERT((is_trivially_copyable<move_ctor<true> >));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<move_ctor<false> >));
BOOST_MPL_ASSERT((is_trivially_copyable<move_assign<true> >));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<move_assign<false> >));
#endif
#endif

#ifdef BOOST_FUSION_DETAIL_PROPAGATE_TRIVIALNESS_CONFORMING
BOOST_MPL_ASSERT((is_candidate_trivially_copy_constructible<trivial>));
BOOST_MPL_ASSERT_NOT((is_candidate_trivially_copy_constructible<user_provided_copy>));
#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
BOOST_FUSION_ASSERT_DEFAULTED((is_candidate_trivially_copy_constructible<user_provided_move>));
#endif
BOOST_FUSION_ASSERT_DEFAULTED((is_candidate_trivially_copy_constructible<user_provided_dtor>));

BOOST_MPL_ASSERT((is_candidate_trivially_copy_assignable<trivial>));
BOOST_MPL_ASSERT_NOT((is_candidate_trivially_copy_assignable<user_provided_copy>));
#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
BOOST_FUSION_ASSERT_DEFAULTED((is_candidate_trivially_copy_assignable<user_provided_move>));
#endif
BOOST_FUSION_ASSERT_DEFAULTED((is_candidate_trivially_copy_assignable<user_provided_dtor>));

#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
BOOST_MPL_ASSERT((is_candidate_trivially_move_constructible<trivial>));
BOOST_FUSION_ASSERT_MOVE_DEFAULTED((is_candidate_trivially_move_constructible<user_provided_copy>));
BOOST_MPL_ASSERT_NOT((is_candidate_trivially_move_constructible<user_provided_move>));
BOOST_MPL_ASSERT_NOT((is_candidate_trivially_move_constructible<user_provided_dtor>));

BOOST_MPL_ASSERT((is_candidate_trivially_move_assignable<trivial>));
BOOST_FUSION_ASSERT_MOVE_DEFAULTED((is_candidate_trivially_move_assignable<user_provided_copy>));
BOOST_MPL_ASSERT_NOT((is_candidate_trivially_move_assignable<user_provided_move>));
BOOST_FUSION_ASSERT_MOVE_DEFAULTED((is_candidate_trivially_move_assignable<user_provided_dtor>));
#endif
#endif

BOOST_MPL_ASSERT((is_trivially_copyable<propagate_trivialness<int> >));
BOOST_MPL_ASSERT((is_trivially_copyable<propagate_trivialness<int const> >));
BOOST_FUSION_ASSERT_CWG496_SCALAR((is_trivially_copyable<propagate_trivialness<int volatile> >));
BOOST_FUSION_ASSERT_CWG496_SCALAR((is_trivially_copyable<propagate_trivialness<int const volatile> >));

BOOST_MPL_ASSERT((is_trivially_copyable<propagate_trivialness<int*> >));
BOOST_MPL_ASSERT((is_trivially_copyable<propagate_trivialness<int const*> >));
BOOST_MPL_ASSERT((is_trivially_copyable<propagate_trivialness<int volatile*> >));
BOOST_MPL_ASSERT((is_trivially_copyable<propagate_trivialness<int const volatile*> >));
BOOST_MPL_ASSERT((is_trivially_copyable<propagate_trivialness<int* const> >));
BOOST_FUSION_ASSERT_CWG496_SCALAR((is_trivially_copyable<propagate_trivialness<int* volatile> >));
BOOST_FUSION_ASSERT_CWG496_SCALAR((is_trivially_copyable<propagate_trivialness<int* const volatile> >));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<int&> >));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<int const&> >));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<int volatile&> >));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<int const volatile&> >));

#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<int&&> >));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<int const&&> >));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<int volatile&&> >));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<int const volatile&&> >));
#endif


BOOST_FUSION_ASSERT_CWG496((is_trivially_copyable<propagate_trivialness<trivial> >));
BOOST_FUSION_ASSERT_CWG496((is_trivially_copyable<propagate_trivialness<trivial const> >));
BOOST_FUSION_ASSERT_CWG2094((is_trivially_copyable<propagate_trivialness<trivial volatile> >));
BOOST_FUSION_ASSERT_CWG2094((is_trivially_copyable<propagate_trivialness<trivial const volatile> >));

BOOST_MPL_ASSERT((is_trivially_copyable<propagate_trivialness<trivial*> >));
BOOST_MPL_ASSERT((is_trivially_copyable<propagate_trivialness<trivial const*> >));
BOOST_MPL_ASSERT((is_trivially_copyable<propagate_trivialness<trivial volatile*> >));
BOOST_MPL_ASSERT((is_trivially_copyable<propagate_trivialness<trivial const volatile*> >));
BOOST_MPL_ASSERT((is_trivially_copyable<propagate_trivialness<trivial* const> >));
BOOST_FUSION_ASSERT_CWG496_SCALAR((is_trivially_copyable<propagate_trivialness<trivial* volatile> >));
BOOST_FUSION_ASSERT_CWG496_SCALAR((is_trivially_copyable<propagate_trivialness<trivial* const volatile> >));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<trivial&> >));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<trivial const&> >));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<trivial volatile&> >));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<trivial const volatile&> >));

#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<trivial&&> >));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<trivial const&&> >));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<trivial volatile&&> >));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<trivial const volatile&&> >));
#endif


BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<user_provided_copy> >));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<user_provided_copy const> >));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<user_provided_copy volatile> >));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<user_provided_copy const volatile> >));

BOOST_MPL_ASSERT((is_trivially_copyable<propagate_trivialness<user_provided_copy*> >));
BOOST_MPL_ASSERT((is_trivially_copyable<propagate_trivialness<user_provided_copy const*> >));
BOOST_MPL_ASSERT((is_trivially_copyable<propagate_trivialness<user_provided_copy volatile*> >));
BOOST_MPL_ASSERT((is_trivially_copyable<propagate_trivialness<user_provided_copy const volatile*> >));
BOOST_MPL_ASSERT((is_trivially_copyable<propagate_trivialness<user_provided_copy* const> >));
BOOST_FUSION_ASSERT_CWG496_SCALAR((is_trivially_copyable<propagate_trivialness<user_provided_copy* volatile> >));
BOOST_FUSION_ASSERT_CWG496_SCALAR((is_trivially_copyable<propagate_trivialness<user_provided_copy* const volatile> >));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<user_provided_copy&> >));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<user_provided_copy const&> >));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<user_provided_copy volatile&> >));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<user_provided_copy const volatile&> >));

#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<user_provided_copy&&> >));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<user_provided_copy const&&> >));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<user_provided_copy volatile&&> >));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<user_provided_copy const volatile&&> >));
#endif


#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<user_provided_move> >));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<user_provided_move const> >));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<user_provided_move volatile> >));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<user_provided_move const volatile> >));

BOOST_MPL_ASSERT((is_trivially_copyable<propagate_trivialness<user_provided_move*> >));
BOOST_MPL_ASSERT((is_trivially_copyable<propagate_trivialness<user_provided_move const*> >));
BOOST_MPL_ASSERT((is_trivially_copyable<propagate_trivialness<user_provided_move volatile*> >));
BOOST_MPL_ASSERT((is_trivially_copyable<propagate_trivialness<user_provided_move const volatile*> >));
BOOST_MPL_ASSERT((is_trivially_copyable<propagate_trivialness<user_provided_move* const> >));
BOOST_FUSION_ASSERT_CWG496_SCALAR((is_trivially_copyable<propagate_trivialness<user_provided_move* volatile> >));
BOOST_FUSION_ASSERT_CWG496_SCALAR((is_trivially_copyable<propagate_trivialness<user_provided_move* const volatile> >));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<user_provided_move&> >));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<user_provided_move const&> >));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<user_provided_move volatile&> >));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<user_provided_move const volatile&> >));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<user_provided_move&&> >));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<user_provided_move const&&> >));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<user_provided_move volatile&&> >));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<user_provided_move const volatile&&> >));
#endif


BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<user_provided_dtor> >));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<user_provided_dtor const> >));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<user_provided_dtor volatile> >));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<user_provided_dtor const volatile> >));

BOOST_MPL_ASSERT((is_trivially_copyable<propagate_trivialness<user_provided_dtor*> >));
BOOST_MPL_ASSERT((is_trivially_copyable<propagate_trivialness<user_provided_dtor const*> >));
BOOST_MPL_ASSERT((is_trivially_copyable<propagate_trivialness<user_provided_dtor volatile*> >));
BOOST_MPL_ASSERT((is_trivially_copyable<propagate_trivialness<user_provided_dtor const volatile*> >));
BOOST_MPL_ASSERT((is_trivially_copyable<propagate_trivialness<user_provided_dtor* const> >));
BOOST_FUSION_ASSERT_CWG496_SCALAR((is_trivially_copyable<propagate_trivialness<user_provided_dtor* volatile> >));
BOOST_FUSION_ASSERT_CWG496_SCALAR((is_trivially_copyable<propagate_trivialness<user_provided_dtor* const volatile> >));

BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<user_provided_dtor&> >));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<user_provided_dtor const&> >));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<user_provided_dtor volatile&> >));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<user_provided_dtor const volatile&> >));

#ifndef BOOST_NO_CXX11_RVALUE_REFERENCES
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<user_provided_dtor&&> >));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<user_provided_dtor const&&> >));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<user_provided_dtor volatile&&> >));
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<propagate_trivialness<user_provided_dtor const volatile&&> >));
#endif


struct S1 : private propagate_trivialness<int> { };
BOOST_MPL_ASSERT((is_trivially_copyable<S1>));

struct S2 : private propagate_trivialness<float&> { };
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<S2>));

struct S3 : private propagate_trivialness<trivial> { };
BOOST_FUSION_ASSERT_CWG496((is_trivially_copyable<S3>));

struct S4 : private propagate_trivialness<user_provided_copy> { };
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<S4>));

struct S5 : private propagate_trivialness<user_provided_move> { };
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<S5>));

struct S6 : private propagate_trivialness<user_provided_dtor> { };
BOOST_MPL_ASSERT_NOT((is_trivially_copyable<S6>));
