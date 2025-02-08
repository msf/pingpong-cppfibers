// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: pingpong.proto

#include "pingpong.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

namespace pingpong {
PROTOBUF_CONSTEXPR Ping::Ping(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.payload_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.sequence_)*/uint64_t{0u}
  , /*decltype(_impl_.timestamp_)*/uint64_t{0u}
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct PingDefaultTypeInternal {
  PROTOBUF_CONSTEXPR PingDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~PingDefaultTypeInternal() {}
  union {
    Ping _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 PingDefaultTypeInternal _Ping_default_instance_;
PROTOBUF_CONSTEXPR Pong::Pong(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.payload_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.sequence_)*/uint64_t{0u}
  , /*decltype(_impl_.timestamp_)*/uint64_t{0u}
  , /*decltype(_impl_.server_timestamp_)*/uint64_t{0u}
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct PongDefaultTypeInternal {
  PROTOBUF_CONSTEXPR PongDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~PongDefaultTypeInternal() {}
  union {
    Pong _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 PongDefaultTypeInternal _Pong_default_instance_;
}  // namespace pingpong
static ::_pb::Metadata file_level_metadata_pingpong_2eproto[2];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_pingpong_2eproto = nullptr;
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_pingpong_2eproto = nullptr;

const uint32_t TableStruct_pingpong_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::pingpong::Ping, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::pingpong::Ping, _impl_.sequence_),
  PROTOBUF_FIELD_OFFSET(::pingpong::Ping, _impl_.timestamp_),
  PROTOBUF_FIELD_OFFSET(::pingpong::Ping, _impl_.payload_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::pingpong::Pong, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::pingpong::Pong, _impl_.sequence_),
  PROTOBUF_FIELD_OFFSET(::pingpong::Pong, _impl_.timestamp_),
  PROTOBUF_FIELD_OFFSET(::pingpong::Pong, _impl_.server_timestamp_),
  PROTOBUF_FIELD_OFFSET(::pingpong::Pong, _impl_.payload_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::pingpong::Ping)},
  { 9, -1, -1, sizeof(::pingpong::Pong)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::pingpong::_Ping_default_instance_._instance,
  &::pingpong::_Pong_default_instance_._instance,
};

const char descriptor_table_protodef_pingpong_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\016pingpong.proto\022\010pingpong\"<\n\004Ping\022\020\n\010se"
  "quence\030\001 \001(\004\022\021\n\ttimestamp\030\002 \001(\004\022\017\n\007paylo"
  "ad\030\003 \001(\014\"V\n\004Pong\022\020\n\010sequence\030\001 \001(\004\022\021\n\tti"
  "mestamp\030\002 \001(\004\022\030\n\020server_timestamp\030\003 \001(\004\022"
  "\017\n\007payload\030\004 \001(\0142B\n\010PingPong\0226\n\016StreamPi"
  "ngPong\022\016.pingpong.Ping\032\016.pingpong.Pong\"\000"
  "(\0010\001B\024Z\022pkg/proto/pingpongb\006proto3"
  ;
static ::_pbi::once_flag descriptor_table_pingpong_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_pingpong_2eproto = {
    false, false, 274, descriptor_table_protodef_pingpong_2eproto,
    "pingpong.proto",
    &descriptor_table_pingpong_2eproto_once, nullptr, 0, 2,
    schemas, file_default_instances, TableStruct_pingpong_2eproto::offsets,
    file_level_metadata_pingpong_2eproto, file_level_enum_descriptors_pingpong_2eproto,
    file_level_service_descriptors_pingpong_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_pingpong_2eproto_getter() {
  return &descriptor_table_pingpong_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_pingpong_2eproto(&descriptor_table_pingpong_2eproto);
namespace pingpong {

// ===================================================================

class Ping::_Internal {
 public:
};

Ping::Ping(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:pingpong.Ping)
}
Ping::Ping(const Ping& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  Ping* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.payload_){}
    , decltype(_impl_.sequence_){}
    , decltype(_impl_.timestamp_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _impl_.payload_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.payload_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_payload().empty()) {
    _this->_impl_.payload_.Set(from._internal_payload(), 
      _this->GetArenaForAllocation());
  }
  ::memcpy(&_impl_.sequence_, &from._impl_.sequence_,
    static_cast<size_t>(reinterpret_cast<char*>(&_impl_.timestamp_) -
    reinterpret_cast<char*>(&_impl_.sequence_)) + sizeof(_impl_.timestamp_));
  // @@protoc_insertion_point(copy_constructor:pingpong.Ping)
}

inline void Ping::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.payload_){}
    , decltype(_impl_.sequence_){uint64_t{0u}}
    , decltype(_impl_.timestamp_){uint64_t{0u}}
    , /*decltype(_impl_._cached_size_)*/{}
  };
  _impl_.payload_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.payload_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

Ping::~Ping() {
  // @@protoc_insertion_point(destructor:pingpong.Ping)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void Ping::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.payload_.Destroy();
}

void Ping::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void Ping::Clear() {
// @@protoc_insertion_point(message_clear_start:pingpong.Ping)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.payload_.ClearToEmpty();
  ::memset(&_impl_.sequence_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&_impl_.timestamp_) -
      reinterpret_cast<char*>(&_impl_.sequence_)) + sizeof(_impl_.timestamp_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Ping::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // uint64 sequence = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          _impl_.sequence_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // uint64 timestamp = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          _impl_.timestamp_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // bytes payload = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 26)) {
          auto str = _internal_mutable_payload();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* Ping::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:pingpong.Ping)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // uint64 sequence = 1;
  if (this->_internal_sequence() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt64ToArray(1, this->_internal_sequence(), target);
  }

  // uint64 timestamp = 2;
  if (this->_internal_timestamp() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt64ToArray(2, this->_internal_timestamp(), target);
  }

  // bytes payload = 3;
  if (!this->_internal_payload().empty()) {
    target = stream->WriteBytesMaybeAliased(
        3, this->_internal_payload(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:pingpong.Ping)
  return target;
}

size_t Ping::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:pingpong.Ping)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // bytes payload = 3;
  if (!this->_internal_payload().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_payload());
  }

  // uint64 sequence = 1;
  if (this->_internal_sequence() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt64SizePlusOne(this->_internal_sequence());
  }

  // uint64 timestamp = 2;
  if (this->_internal_timestamp() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt64SizePlusOne(this->_internal_timestamp());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Ping::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    Ping::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Ping::GetClassData() const { return &_class_data_; }


void Ping::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<Ping*>(&to_msg);
  auto& from = static_cast<const Ping&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:pingpong.Ping)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_payload().empty()) {
    _this->_internal_set_payload(from._internal_payload());
  }
  if (from._internal_sequence() != 0) {
    _this->_internal_set_sequence(from._internal_sequence());
  }
  if (from._internal_timestamp() != 0) {
    _this->_internal_set_timestamp(from._internal_timestamp());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Ping::CopyFrom(const Ping& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:pingpong.Ping)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Ping::IsInitialized() const {
  return true;
}

void Ping::InternalSwap(Ping* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.payload_, lhs_arena,
      &other->_impl_.payload_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Ping, _impl_.timestamp_)
      + sizeof(Ping::_impl_.timestamp_)
      - PROTOBUF_FIELD_OFFSET(Ping, _impl_.sequence_)>(
          reinterpret_cast<char*>(&_impl_.sequence_),
          reinterpret_cast<char*>(&other->_impl_.sequence_));
}

::PROTOBUF_NAMESPACE_ID::Metadata Ping::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_pingpong_2eproto_getter, &descriptor_table_pingpong_2eproto_once,
      file_level_metadata_pingpong_2eproto[0]);
}

// ===================================================================

class Pong::_Internal {
 public:
};

Pong::Pong(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:pingpong.Pong)
}
Pong::Pong(const Pong& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  Pong* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.payload_){}
    , decltype(_impl_.sequence_){}
    , decltype(_impl_.timestamp_){}
    , decltype(_impl_.server_timestamp_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _impl_.payload_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.payload_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_payload().empty()) {
    _this->_impl_.payload_.Set(from._internal_payload(), 
      _this->GetArenaForAllocation());
  }
  ::memcpy(&_impl_.sequence_, &from._impl_.sequence_,
    static_cast<size_t>(reinterpret_cast<char*>(&_impl_.server_timestamp_) -
    reinterpret_cast<char*>(&_impl_.sequence_)) + sizeof(_impl_.server_timestamp_));
  // @@protoc_insertion_point(copy_constructor:pingpong.Pong)
}

inline void Pong::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.payload_){}
    , decltype(_impl_.sequence_){uint64_t{0u}}
    , decltype(_impl_.timestamp_){uint64_t{0u}}
    , decltype(_impl_.server_timestamp_){uint64_t{0u}}
    , /*decltype(_impl_._cached_size_)*/{}
  };
  _impl_.payload_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.payload_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

Pong::~Pong() {
  // @@protoc_insertion_point(destructor:pingpong.Pong)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void Pong::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.payload_.Destroy();
}

void Pong::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void Pong::Clear() {
// @@protoc_insertion_point(message_clear_start:pingpong.Pong)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.payload_.ClearToEmpty();
  ::memset(&_impl_.sequence_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&_impl_.server_timestamp_) -
      reinterpret_cast<char*>(&_impl_.sequence_)) + sizeof(_impl_.server_timestamp_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Pong::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // uint64 sequence = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          _impl_.sequence_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // uint64 timestamp = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          _impl_.timestamp_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // uint64 server_timestamp = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 24)) {
          _impl_.server_timestamp_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // bytes payload = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 34)) {
          auto str = _internal_mutable_payload();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* Pong::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:pingpong.Pong)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // uint64 sequence = 1;
  if (this->_internal_sequence() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt64ToArray(1, this->_internal_sequence(), target);
  }

  // uint64 timestamp = 2;
  if (this->_internal_timestamp() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt64ToArray(2, this->_internal_timestamp(), target);
  }

  // uint64 server_timestamp = 3;
  if (this->_internal_server_timestamp() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt64ToArray(3, this->_internal_server_timestamp(), target);
  }

  // bytes payload = 4;
  if (!this->_internal_payload().empty()) {
    target = stream->WriteBytesMaybeAliased(
        4, this->_internal_payload(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:pingpong.Pong)
  return target;
}

size_t Pong::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:pingpong.Pong)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // bytes payload = 4;
  if (!this->_internal_payload().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::BytesSize(
        this->_internal_payload());
  }

  // uint64 sequence = 1;
  if (this->_internal_sequence() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt64SizePlusOne(this->_internal_sequence());
  }

  // uint64 timestamp = 2;
  if (this->_internal_timestamp() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt64SizePlusOne(this->_internal_timestamp());
  }

  // uint64 server_timestamp = 3;
  if (this->_internal_server_timestamp() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt64SizePlusOne(this->_internal_server_timestamp());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Pong::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    Pong::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Pong::GetClassData() const { return &_class_data_; }


void Pong::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<Pong*>(&to_msg);
  auto& from = static_cast<const Pong&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:pingpong.Pong)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_payload().empty()) {
    _this->_internal_set_payload(from._internal_payload());
  }
  if (from._internal_sequence() != 0) {
    _this->_internal_set_sequence(from._internal_sequence());
  }
  if (from._internal_timestamp() != 0) {
    _this->_internal_set_timestamp(from._internal_timestamp());
  }
  if (from._internal_server_timestamp() != 0) {
    _this->_internal_set_server_timestamp(from._internal_server_timestamp());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Pong::CopyFrom(const Pong& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:pingpong.Pong)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Pong::IsInitialized() const {
  return true;
}

void Pong::InternalSwap(Pong* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.payload_, lhs_arena,
      &other->_impl_.payload_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Pong, _impl_.server_timestamp_)
      + sizeof(Pong::_impl_.server_timestamp_)
      - PROTOBUF_FIELD_OFFSET(Pong, _impl_.sequence_)>(
          reinterpret_cast<char*>(&_impl_.sequence_),
          reinterpret_cast<char*>(&other->_impl_.sequence_));
}

::PROTOBUF_NAMESPACE_ID::Metadata Pong::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_pingpong_2eproto_getter, &descriptor_table_pingpong_2eproto_once,
      file_level_metadata_pingpong_2eproto[1]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace pingpong
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::pingpong::Ping*
Arena::CreateMaybeMessage< ::pingpong::Ping >(Arena* arena) {
  return Arena::CreateMessageInternal< ::pingpong::Ping >(arena);
}
template<> PROTOBUF_NOINLINE ::pingpong::Pong*
Arena::CreateMaybeMessage< ::pingpong::Pong >(Arena* arena) {
  return Arena::CreateMessageInternal< ::pingpong::Pong >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
