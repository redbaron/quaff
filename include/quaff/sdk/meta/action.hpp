/******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2007 & onward IEF    UMR 8622 CNRS/Univ Paris Sud XI
 *         Copyright 2008 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef QUAFF_SDK_META_ACTION_HPP_INCLUDED
#define QUAFF_SDK_META_ACTION_HPP_INCLUDED

#include <quaff/sdk/meta/is_callable.hpp>
#include <boost/function_types/result_type.hpp>

////////////////////////////////////////////////////////////////////////////////
/// @file quaff/sdk/meta/action.hpp
////////////////////////////////////////////////////////////////////////////////
namespace quaff { namespace meta
{
  //////////////////////////////////////////////////////////////////////////////
  // action takes some Callable and adapt it to the Concretized Function Object
  // we require.
  //////////////////////////////////////////////////////////////////////////////
  template<class Callable> struct action;
  
  //////////////////////////////////////////////////////////////////////////////
  // Plain C function of the form O (*)(I)
  //////////////////////////////////////////////////////////////////////////////
  template<class Output, class Input>
  struct  action<Output (*) (Input) > : callable
  {
    typedef Output  (*function_type)(Input);

    typedef Input     input_type;
    typedef Output    output_type;

    action() {}
    action(function_type const& f) : callee(f) {}

    action& operator=(function_type const& f) { callee = f; return *this; }

    inline std::string  name()                const { return "<unamed>"; }
    inline Output       operator()(Input in)  const { return callee(in); }

    private:
    function_type callee;
  };
} }

#endif
