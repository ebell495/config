// Copyright (c) 2018-2020 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/taocpp/config/

#ifndef TAO_CONFIG_INTERNAL_STATE_HPP
#define TAO_CONFIG_INTERNAL_STATE_HPP

#include <map>
#include <string>
#include <vector>

#include "array.hpp"
#include "concat.hpp"
#include "entry.hpp"
#include "key1.hpp"
#include "object.hpp"
#include "pegtl.hpp"

namespace tao::config::internal
{
   struct state
   {
      state() = default;

      state( state&& ) = delete;
      state( const state& ) = delete;

      ~state() = default;

      void operator=( state&& ) = delete;
      void operator=( const state&& ) = delete;

      key1 prefix;
      key1 suffix;

      object root;

      std::vector< key1 > temporaries;        // Delete from final result.
      std::map< key1, std::string > schemas;  // Check against final result.
   };

}  // namespace tao::config::internal

#endif
