// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: pingpong.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_pingpong_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_pingpong_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021012 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_pingpong_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_pingpong_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_pingpong_2eproto;
namespace pingpong {
class Ping;
struct PingDefaultTypeInternal;
extern PingDefaultTypeInternal _Ping_default_instance_;
class Pong;
struct PongDefaultTypeInternal;
extern PongDefaultTypeInternal _Pong_default_instance_;
}  // namespace pingpong
PROTOBUF_NAMESPACE_OPEN
template<> ::pingpong::Ping* Arena::CreateMaybeMessage<::pingpong::Ping>(Arena*);
template<> ::pingpong::Pong* Arena::CreateMaybeMessage<::pingpong::Pong>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace pingpong {

// ===================================================================

class Ping final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:pingpong.Ping) */ {
 public:
  inline Ping() : Ping(nullptr) {}
  ~Ping() override;
  explicit PROTOBUF_CONSTEXPR Ping(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Ping(const Ping& from);
  Ping(Ping&& from) noexcept
    : Ping() {
    *this = ::std::move(from);
  }

  inline Ping& operator=(const Ping& from) {
    CopyFrom(from);
    return *this;
  }
  inline Ping& operator=(Ping&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Ping& default_instance() {
    return *internal_default_instance();
  }
  static inline const Ping* internal_default_instance() {
    return reinterpret_cast<const Ping*>(
               &_Ping_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Ping& a, Ping& b) {
    a.Swap(&b);
  }
  inline void Swap(Ping* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Ping* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Ping* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Ping>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Ping& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const Ping& from) {
    Ping::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Ping* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "pingpong.Ping";
  }
  protected:
  explicit Ping(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kPayloadFieldNumber = 3,
    kSequenceFieldNumber = 1,
    kTimestampFieldNumber = 2,
  };
  // bytes payload = 3;
  void clear_payload();
  const std::string& payload() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_payload(ArgT0&& arg0, ArgT... args);
  std::string* mutable_payload();
  PROTOBUF_NODISCARD std::string* release_payload();
  void set_allocated_payload(std::string* payload);
  private:
  const std::string& _internal_payload() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_payload(const std::string& value);
  std::string* _internal_mutable_payload();
  public:

  // uint64 sequence = 1;
  void clear_sequence();
  uint64_t sequence() const;
  void set_sequence(uint64_t value);
  private:
  uint64_t _internal_sequence() const;
  void _internal_set_sequence(uint64_t value);
  public:

  // uint64 timestamp = 2;
  void clear_timestamp();
  uint64_t timestamp() const;
  void set_timestamp(uint64_t value);
  private:
  uint64_t _internal_timestamp() const;
  void _internal_set_timestamp(uint64_t value);
  public:

  // @@protoc_insertion_point(class_scope:pingpong.Ping)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr payload_;
    uint64_t sequence_;
    uint64_t timestamp_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_pingpong_2eproto;
};
// -------------------------------------------------------------------

class Pong final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:pingpong.Pong) */ {
 public:
  inline Pong() : Pong(nullptr) {}
  ~Pong() override;
  explicit PROTOBUF_CONSTEXPR Pong(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Pong(const Pong& from);
  Pong(Pong&& from) noexcept
    : Pong() {
    *this = ::std::move(from);
  }

  inline Pong& operator=(const Pong& from) {
    CopyFrom(from);
    return *this;
  }
  inline Pong& operator=(Pong&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Pong& default_instance() {
    return *internal_default_instance();
  }
  static inline const Pong* internal_default_instance() {
    return reinterpret_cast<const Pong*>(
               &_Pong_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(Pong& a, Pong& b) {
    a.Swap(&b);
  }
  inline void Swap(Pong* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Pong* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Pong* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Pong>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Pong& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const Pong& from) {
    Pong::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Pong* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "pingpong.Pong";
  }
  protected:
  explicit Pong(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kPayloadFieldNumber = 4,
    kSequenceFieldNumber = 1,
    kTimestampFieldNumber = 2,
    kServerTimestampFieldNumber = 3,
  };
  // bytes payload = 4;
  void clear_payload();
  const std::string& payload() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_payload(ArgT0&& arg0, ArgT... args);
  std::string* mutable_payload();
  PROTOBUF_NODISCARD std::string* release_payload();
  void set_allocated_payload(std::string* payload);
  private:
  const std::string& _internal_payload() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_payload(const std::string& value);
  std::string* _internal_mutable_payload();
  public:

  // uint64 sequence = 1;
  void clear_sequence();
  uint64_t sequence() const;
  void set_sequence(uint64_t value);
  private:
  uint64_t _internal_sequence() const;
  void _internal_set_sequence(uint64_t value);
  public:

  // uint64 timestamp = 2;
  void clear_timestamp();
  uint64_t timestamp() const;
  void set_timestamp(uint64_t value);
  private:
  uint64_t _internal_timestamp() const;
  void _internal_set_timestamp(uint64_t value);
  public:

  // uint64 server_timestamp = 3;
  void clear_server_timestamp();
  uint64_t server_timestamp() const;
  void set_server_timestamp(uint64_t value);
  private:
  uint64_t _internal_server_timestamp() const;
  void _internal_set_server_timestamp(uint64_t value);
  public:

  // @@protoc_insertion_point(class_scope:pingpong.Pong)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr payload_;
    uint64_t sequence_;
    uint64_t timestamp_;
    uint64_t server_timestamp_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_pingpong_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Ping

// uint64 sequence = 1;
inline void Ping::clear_sequence() {
  _impl_.sequence_ = uint64_t{0u};
}
inline uint64_t Ping::_internal_sequence() const {
  return _impl_.sequence_;
}
inline uint64_t Ping::sequence() const {
  // @@protoc_insertion_point(field_get:pingpong.Ping.sequence)
  return _internal_sequence();
}
inline void Ping::_internal_set_sequence(uint64_t value) {
  
  _impl_.sequence_ = value;
}
inline void Ping::set_sequence(uint64_t value) {
  _internal_set_sequence(value);
  // @@protoc_insertion_point(field_set:pingpong.Ping.sequence)
}

// uint64 timestamp = 2;
inline void Ping::clear_timestamp() {
  _impl_.timestamp_ = uint64_t{0u};
}
inline uint64_t Ping::_internal_timestamp() const {
  return _impl_.timestamp_;
}
inline uint64_t Ping::timestamp() const {
  // @@protoc_insertion_point(field_get:pingpong.Ping.timestamp)
  return _internal_timestamp();
}
inline void Ping::_internal_set_timestamp(uint64_t value) {
  
  _impl_.timestamp_ = value;
}
inline void Ping::set_timestamp(uint64_t value) {
  _internal_set_timestamp(value);
  // @@protoc_insertion_point(field_set:pingpong.Ping.timestamp)
}

// bytes payload = 3;
inline void Ping::clear_payload() {
  _impl_.payload_.ClearToEmpty();
}
inline const std::string& Ping::payload() const {
  // @@protoc_insertion_point(field_get:pingpong.Ping.payload)
  return _internal_payload();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Ping::set_payload(ArgT0&& arg0, ArgT... args) {
 
 _impl_.payload_.SetBytes(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:pingpong.Ping.payload)
}
inline std::string* Ping::mutable_payload() {
  std::string* _s = _internal_mutable_payload();
  // @@protoc_insertion_point(field_mutable:pingpong.Ping.payload)
  return _s;
}
inline const std::string& Ping::_internal_payload() const {
  return _impl_.payload_.Get();
}
inline void Ping::_internal_set_payload(const std::string& value) {
  
  _impl_.payload_.Set(value, GetArenaForAllocation());
}
inline std::string* Ping::_internal_mutable_payload() {
  
  return _impl_.payload_.Mutable(GetArenaForAllocation());
}
inline std::string* Ping::release_payload() {
  // @@protoc_insertion_point(field_release:pingpong.Ping.payload)
  return _impl_.payload_.Release();
}
inline void Ping::set_allocated_payload(std::string* payload) {
  if (payload != nullptr) {
    
  } else {
    
  }
  _impl_.payload_.SetAllocated(payload, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.payload_.IsDefault()) {
    _impl_.payload_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:pingpong.Ping.payload)
}

// -------------------------------------------------------------------

// Pong

// uint64 sequence = 1;
inline void Pong::clear_sequence() {
  _impl_.sequence_ = uint64_t{0u};
}
inline uint64_t Pong::_internal_sequence() const {
  return _impl_.sequence_;
}
inline uint64_t Pong::sequence() const {
  // @@protoc_insertion_point(field_get:pingpong.Pong.sequence)
  return _internal_sequence();
}
inline void Pong::_internal_set_sequence(uint64_t value) {
  
  _impl_.sequence_ = value;
}
inline void Pong::set_sequence(uint64_t value) {
  _internal_set_sequence(value);
  // @@protoc_insertion_point(field_set:pingpong.Pong.sequence)
}

// uint64 timestamp = 2;
inline void Pong::clear_timestamp() {
  _impl_.timestamp_ = uint64_t{0u};
}
inline uint64_t Pong::_internal_timestamp() const {
  return _impl_.timestamp_;
}
inline uint64_t Pong::timestamp() const {
  // @@protoc_insertion_point(field_get:pingpong.Pong.timestamp)
  return _internal_timestamp();
}
inline void Pong::_internal_set_timestamp(uint64_t value) {
  
  _impl_.timestamp_ = value;
}
inline void Pong::set_timestamp(uint64_t value) {
  _internal_set_timestamp(value);
  // @@protoc_insertion_point(field_set:pingpong.Pong.timestamp)
}

// uint64 server_timestamp = 3;
inline void Pong::clear_server_timestamp() {
  _impl_.server_timestamp_ = uint64_t{0u};
}
inline uint64_t Pong::_internal_server_timestamp() const {
  return _impl_.server_timestamp_;
}
inline uint64_t Pong::server_timestamp() const {
  // @@protoc_insertion_point(field_get:pingpong.Pong.server_timestamp)
  return _internal_server_timestamp();
}
inline void Pong::_internal_set_server_timestamp(uint64_t value) {
  
  _impl_.server_timestamp_ = value;
}
inline void Pong::set_server_timestamp(uint64_t value) {
  _internal_set_server_timestamp(value);
  // @@protoc_insertion_point(field_set:pingpong.Pong.server_timestamp)
}

// bytes payload = 4;
inline void Pong::clear_payload() {
  _impl_.payload_.ClearToEmpty();
}
inline const std::string& Pong::payload() const {
  // @@protoc_insertion_point(field_get:pingpong.Pong.payload)
  return _internal_payload();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Pong::set_payload(ArgT0&& arg0, ArgT... args) {
 
 _impl_.payload_.SetBytes(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:pingpong.Pong.payload)
}
inline std::string* Pong::mutable_payload() {
  std::string* _s = _internal_mutable_payload();
  // @@protoc_insertion_point(field_mutable:pingpong.Pong.payload)
  return _s;
}
inline const std::string& Pong::_internal_payload() const {
  return _impl_.payload_.Get();
}
inline void Pong::_internal_set_payload(const std::string& value) {
  
  _impl_.payload_.Set(value, GetArenaForAllocation());
}
inline std::string* Pong::_internal_mutable_payload() {
  
  return _impl_.payload_.Mutable(GetArenaForAllocation());
}
inline std::string* Pong::release_payload() {
  // @@protoc_insertion_point(field_release:pingpong.Pong.payload)
  return _impl_.payload_.Release();
}
inline void Pong::set_allocated_payload(std::string* payload) {
  if (payload != nullptr) {
    
  } else {
    
  }
  _impl_.payload_.SetAllocated(payload, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.payload_.IsDefault()) {
    _impl_.payload_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:pingpong.Pong.payload)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace pingpong

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_pingpong_2eproto
