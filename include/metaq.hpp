#pragma once
#include <string_view>
#include <cstdint>

#ifdef defined __clang__ || defined __GNUC__
# define MQ_PRETTY_FUNCTION __PRETTY_FUNCTION__
#else
# define MQ_PRETTY_FUNCTION __FUNCSIG__
#endif

namespace mq {
  
  using shash_t = uint32_t;

  namespace detail {
    
    template<typename>
    struct fnv1a;

    template<>
    struct fnv1a<std::uint32_t> {
      static constexpr auto offset = 2166136261U;
      static constexpr auto prime  = 16777619U;
    };

    template<>
    struct fnv1a<std::uint64_t> {
      static constexpr auto offset = 1099511628211ULL;
      static constexpr auto prime  = 14695981039346656037ULL;
    };
  }

  template<typename Type>
  constexpr auto nameof() noexcept
  {
    const std::string_view func_name{ MQ_PRETTY_FUNCTION };
  
  #if defined __clang__ || defined __GNUC__

    constexpr auto prefix = '=';
    constexpr auto suffix = ']';

    auto begin = func_name.find_first_not_of(' ', func_name.find_first_of(prefix) + 1);
    auto name = func_name.substr(begin, func_name.find_last_of(suffix) - begin);
    return name;

  #else // MSVC 

    constexpr auto prefix = '<';
    constexpr auto suffix = '>';

    if constexpr (!std::is_fundamental_v<Type>)
    {
      auto begin = func_name.find_first_of(prefix) + 1;

      auto space = func_name.find_first_of(' ', begin) + 1;
      auto end = func_name.find_last_of(suffix);

      if (space < end)
      {
        return func_name.substr(space, end - space);
      }

      auto name = func_name.substr(begin, end - begin);

      return name;
    }
    else
    {
      auto begin = func_name.find_first_not_of(' ', func_name.find_first_of(prefix) + 1);
      auto name = func_name.substr(begin, func_name.find_last_of(suffix) - begin);
      return name;
    }

  #endif
  }
  
  constexpr shash_t hash_code(const std::string_view name)
  {
    constexpr auto prime = detail::fnv1a<shash_t>::prime;
    
    shash_t hash = detail::fnv1a<shash_t>::offset;
    for (auto&& c : name)
      hash = (hash ^ static_cast<shash_t>(c)) * prime;

    return hash;
  }

  template<typename T>
  constexpr shash_t hash_code() noexcept
  {
    return hash_code(nameof<T>());
  }
  
  template<typename T>
  struct meta {
    using type = std::remove_cv_t<std::remove_pointer_t<std::decay_t<T>>>;
    
    static constexpr std::string_view name = nameof<type>();
    static constexpr shash_t hash = hash_code<type>();

    constexpr meta() noexcept = default;
    
    constexpr meta(T&&) noexcept
    { }
    
    constexpr operator shash_t() noexcept { return hash; } 
  };

  template<typename T> meta(T&&) -> meta<T>;

  namespace literals {
    constexpr shash_t operator""_sh(const char* str, std::size_t size)
    {
      return hash_code({str, size});
    }
  } // namespace literals

}// namespace mq



