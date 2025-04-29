#include <metaq.hpp>
#include "common.hpp"

using namespace mq::literals;

int main()
{
  using mq::meta;
  using mq::nameof;
  
  static_assert(meta<char>() == "char"_sh);
  static_assert(meta<float>::name == "float");
  static_assert(meta<double>() == "double"_sh);
  
  static_assert(meta<Clazz>::name == "Clazz");
  static_assert(meta<some_info>::name == "some_info");
  static_assert(meta<another_struct>::name == "another_struct");
  static_assert(meta<Enum>::name == "Enum");
  static_assert(meta<EnumClass>::name == "EnumClass");
  static_assert(meta<MyUnion>::name == "MyUnion");
  static_assert(meta<Base>::name == "Base");
  
  static_assert(meta<Derived>::name == "Derived");
  static_assert(meta<Derived>{}.hash == "Derived"_sh);
  static_assert(meta<Derived*>::name == "Derived");
  static_assert(meta<const Derived>::name == "Derived");
  static_assert(meta<const Derived&>::name == "Derived");
  static_assert(meta<Derived&&>::name == "Derived");
  static_assert(meta<const volatile Derived>::name == "Derived");
  static_assert(meta<const volatile Derived&>::name == "Derived");
}