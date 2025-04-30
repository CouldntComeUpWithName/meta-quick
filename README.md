# **meta-quick**

**Examines type information at compile time or runtime, enabling dynamic function dispatch where standard C++ mechanisms simply fall short.**

---

## Features

- C++ RTTI-free
- Compile-time hash computation
- No exceptions
- Minimal API, clear intent
- Header-only, zero external dependencies

> **Note:** This is not a reflection library.

---

---

## 📦 Installation

Just drop `metaq.hpp` into your project — it's fully header-only and self-contained.

## 🛡 Design Goals

- Be fast and lightweight
- Avoid RTTI and dynamic_cast
- Work in systems where exceptions and runtime reflection are undesirable
- Stable across builds if the string input is consistent
- Can be used for network messaging, serialization, etc.
---

## ❌ Not a Reflection System

While it uses type information internally, `meta-quick` doesn't provide full runtime reflection. It focuses solely on **type-based dispatch** in environments where **standard C++ techniques fall short**.