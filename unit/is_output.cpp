/******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2007 & onward IEF    UMR 8622 CNRS/Univ Paris Sud XI
 *         Copyright 2008 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#include <boost/mpl/assert.hpp>
#include <quaff/sdk/meta/is_output.hpp>

int main()
{
  using quaff::meta::is_output;

  BOOST_MPL_ASSERT_NOT((  is_output<int>        ));
  BOOST_MPL_ASSERT    ((  is_output<int&>       ));
  BOOST_MPL_ASSERT_NOT((  is_output<int const>  ));
  BOOST_MPL_ASSERT_NOT((  is_output<int const&> ));

  return 0;
}