// Copyright (c) 2020 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/taocpp/config/

#ifndef TAO_CONFIG_INTERNAL_EXTENSION_RULES_HPP
#define TAO_CONFIG_INTERNAL_EXTENSION_RULES_HPP

#include "key_rules.hpp"
#include "pegtl.hpp"

namespace tao::config::internal::rules
{
   namespace jaxn = tao::json::jaxn::internal::rules;

   // clang-format off
   struct wsp : pegtl::plus< jaxn::ws > {};

   struct extension_name : pegtl::seq< ident, pegtl::opt< pegtl::one< '?' > > > {};
   struct extension_rule : pegtl::must< extension_name, wsp > {};
   // clang-format on

}  // namespace tao::config::internal::rules

#endif
