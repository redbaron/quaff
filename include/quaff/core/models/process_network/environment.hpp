/******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2007 & onward IEF    UMR 8622 CNRS/Univ Paris Sud XI
 *         Copyright 2008 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef QUAFF_CORE_MODELS_PROCESS_NETWORK_SEMANTIC_ENVIRONMENT_HPP_INCLUDED
#define QUAFF_CORE_MODELS_PROCESS_NETWORK_SEMANTIC_ENVIRONMENT_HPP_INCLUDED

////////////////////////////////////////////////////////////////////////////////
/// @file quaff/core/models/process_network/semantic/environment.hpp
////////////////////////////////////////////////////////////////////////////////
#include <boost/proto/proto.hpp>

namespace quaff { namespace model
{
  //////////////////////////////////////////////////////////////////////////////
  // environment is used to capture required element of the IR while being built
  //////////////////////////////////////////////////////////////////////////////
  template< class Network , class PIDState >
  struct environment
  {
    typedef Network   network_type;
    typedef PIDState  pid_type;

    ////////////////////////////////////////////////////////////////////////////
    // Build an environnement from a network and a back-end
    ////////////////////////////////////////////////////////////////////////////
    environment ( network_type const& n ) : network_(n) {}

    ////////////////////////////////////////////////////////////////////////////
    // Access to environment components
    ////////////////////////////////////////////////////////////////////////////
    network_type const&   network()   const { return network_;    }
    pid_type              next_pid()  const { return pid_type();  }
    
    network_type network_;
  };
  
  //////////////////////////////////////////////////////////////////////////////
  // Build an environnement from Network and PID
  //////////////////////////////////////////////////////////////////////////////
  //template<class Number, class PID,class Network>
  template<class PID,class Network>
  inline environment<Network, PID >
  make_environment(Network const& n, PID const&)
  {
    environment<Network, PID> that(n);
    return that;
  }

  //////////////////////////////////////////////////////////////////////////////
  // proto transforms retrieving the current pid of an environment
  //////////////////////////////////////////////////////////////////////////////
  struct pid_ : boost::proto::callable
  {
    template<class Sig> struct result;

    template<class This, class Env>
    struct result<This(Env)>
    {
      typedef typename boost::proto::detail::uncvref<Env>::type base;
      typedef typename base::pid_type type;
    };

    template<class Env> inline
    typename result<pid_(Env const&)>::type
    operator()(Env const& ) const
    {
      typename result<pid_(Env const&)>::type that;
      return that;
    }
  };
} }

#endif
