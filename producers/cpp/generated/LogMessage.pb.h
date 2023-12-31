// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: LogMessage.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_LogMessage_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_LogMessage_2eproto

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
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
#include <google/protobuf/timestamp.pb.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_LogMessage_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_LogMessage_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_LogMessage_2eproto;
namespace protobuf {
class LogMessage;
struct LogMessageDefaultTypeInternal;
extern LogMessageDefaultTypeInternal _LogMessage_default_instance_;
}  // namespace protobuf
PROTOBUF_NAMESPACE_OPEN
template<> ::protobuf::LogMessage* Arena::CreateMaybeMessage<::protobuf::LogMessage>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace protobuf {

enum LogLevel : int {
  DEBUG = 0,
  INFO = 1,
  WARNING = 2,
  ERROR = 3,
  FATAL = 4,
  LogLevel_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::min(),
  LogLevel_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::max()
};
bool LogLevel_IsValid(int value);
constexpr LogLevel LogLevel_MIN = DEBUG;
constexpr LogLevel LogLevel_MAX = FATAL;
constexpr int LogLevel_ARRAYSIZE = LogLevel_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* LogLevel_descriptor();
template<typename T>
inline const std::string& LogLevel_Name(T enum_t_value) {
  static_assert(::std::is_same<T, LogLevel>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function LogLevel_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    LogLevel_descriptor(), enum_t_value);
}
inline bool LogLevel_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, LogLevel* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<LogLevel>(
    LogLevel_descriptor(), name, value);
}
enum ApplicationLanguage : int {
  RUST = 0,
  JAVA = 1,
  CPP = 2,
  GO = 3,
  ApplicationLanguage_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::min(),
  ApplicationLanguage_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::max()
};
bool ApplicationLanguage_IsValid(int value);
constexpr ApplicationLanguage ApplicationLanguage_MIN = RUST;
constexpr ApplicationLanguage ApplicationLanguage_MAX = GO;
constexpr int ApplicationLanguage_ARRAYSIZE = ApplicationLanguage_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* ApplicationLanguage_descriptor();
template<typename T>
inline const std::string& ApplicationLanguage_Name(T enum_t_value) {
  static_assert(::std::is_same<T, ApplicationLanguage>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function ApplicationLanguage_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    ApplicationLanguage_descriptor(), enum_t_value);
}
inline bool ApplicationLanguage_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, ApplicationLanguage* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<ApplicationLanguage>(
    ApplicationLanguage_descriptor(), name, value);
}
// ===================================================================

class LogMessage final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:protobuf.LogMessage) */ {
 public:
  inline LogMessage() : LogMessage(nullptr) {}
  ~LogMessage() override;
  explicit PROTOBUF_CONSTEXPR LogMessage(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  LogMessage(const LogMessage& from);
  LogMessage(LogMessage&& from) noexcept
    : LogMessage() {
    *this = ::std::move(from);
  }

  inline LogMessage& operator=(const LogMessage& from) {
    CopyFrom(from);
    return *this;
  }
  inline LogMessage& operator=(LogMessage&& from) noexcept {
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
  static const LogMessage& default_instance() {
    return *internal_default_instance();
  }
  static inline const LogMessage* internal_default_instance() {
    return reinterpret_cast<const LogMessage*>(
               &_LogMessage_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(LogMessage& a, LogMessage& b) {
    a.Swap(&b);
  }
  inline void Swap(LogMessage* other) {
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
  void UnsafeArenaSwap(LogMessage* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  LogMessage* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<LogMessage>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const LogMessage& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const LogMessage& from) {
    LogMessage::MergeImpl(*this, from);
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
  void InternalSwap(LogMessage* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "protobuf.LogMessage";
  }
  protected:
  explicit LogMessage(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kMessageFieldNumber = 3,
    kUidFieldNumber = 5,
    kTimestampFieldNumber = 1,
    kLogLevelFieldNumber = 2,
    kAppLangFieldNumber = 4,
  };
  // string message = 3;
  void clear_message();
  const std::string& message() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_message(ArgT0&& arg0, ArgT... args);
  std::string* mutable_message();
  PROTOBUF_NODISCARD std::string* release_message();
  void set_allocated_message(std::string* message);
  private:
  const std::string& _internal_message() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_message(const std::string& value);
  std::string* _internal_mutable_message();
  public:

  // string uid = 5;
  void clear_uid();
  const std::string& uid() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_uid(ArgT0&& arg0, ArgT... args);
  std::string* mutable_uid();
  PROTOBUF_NODISCARD std::string* release_uid();
  void set_allocated_uid(std::string* uid);
  private:
  const std::string& _internal_uid() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_uid(const std::string& value);
  std::string* _internal_mutable_uid();
  public:

  // .google.protobuf.Timestamp timestamp = 1;
  bool has_timestamp() const;
  private:
  bool _internal_has_timestamp() const;
  public:
  void clear_timestamp();
  const ::PROTOBUF_NAMESPACE_ID::Timestamp& timestamp() const;
  PROTOBUF_NODISCARD ::PROTOBUF_NAMESPACE_ID::Timestamp* release_timestamp();
  ::PROTOBUF_NAMESPACE_ID::Timestamp* mutable_timestamp();
  void set_allocated_timestamp(::PROTOBUF_NAMESPACE_ID::Timestamp* timestamp);
  private:
  const ::PROTOBUF_NAMESPACE_ID::Timestamp& _internal_timestamp() const;
  ::PROTOBUF_NAMESPACE_ID::Timestamp* _internal_mutable_timestamp();
  public:
  void unsafe_arena_set_allocated_timestamp(
      ::PROTOBUF_NAMESPACE_ID::Timestamp* timestamp);
  ::PROTOBUF_NAMESPACE_ID::Timestamp* unsafe_arena_release_timestamp();

  // .protobuf.LogLevel log_level = 2;
  void clear_log_level();
  ::protobuf::LogLevel log_level() const;
  void set_log_level(::protobuf::LogLevel value);
  private:
  ::protobuf::LogLevel _internal_log_level() const;
  void _internal_set_log_level(::protobuf::LogLevel value);
  public:

  // .protobuf.ApplicationLanguage app_lang = 4;
  void clear_app_lang();
  ::protobuf::ApplicationLanguage app_lang() const;
  void set_app_lang(::protobuf::ApplicationLanguage value);
  private:
  ::protobuf::ApplicationLanguage _internal_app_lang() const;
  void _internal_set_app_lang(::protobuf::ApplicationLanguage value);
  public:

  // @@protoc_insertion_point(class_scope:protobuf.LogMessage)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr message_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr uid_;
    ::PROTOBUF_NAMESPACE_ID::Timestamp* timestamp_;
    int log_level_;
    int app_lang_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_LogMessage_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// LogMessage

// .google.protobuf.Timestamp timestamp = 1;
inline bool LogMessage::_internal_has_timestamp() const {
  return this != internal_default_instance() && _impl_.timestamp_ != nullptr;
}
inline bool LogMessage::has_timestamp() const {
  return _internal_has_timestamp();
}
inline const ::PROTOBUF_NAMESPACE_ID::Timestamp& LogMessage::_internal_timestamp() const {
  const ::PROTOBUF_NAMESPACE_ID::Timestamp* p = _impl_.timestamp_;
  return p != nullptr ? *p : reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Timestamp&>(
      ::PROTOBUF_NAMESPACE_ID::_Timestamp_default_instance_);
}
inline const ::PROTOBUF_NAMESPACE_ID::Timestamp& LogMessage::timestamp() const {
  // @@protoc_insertion_point(field_get:protobuf.LogMessage.timestamp)
  return _internal_timestamp();
}
inline void LogMessage::unsafe_arena_set_allocated_timestamp(
    ::PROTOBUF_NAMESPACE_ID::Timestamp* timestamp) {
  if (GetArenaForAllocation() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.timestamp_);
  }
  _impl_.timestamp_ = timestamp;
  if (timestamp) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:protobuf.LogMessage.timestamp)
}
inline ::PROTOBUF_NAMESPACE_ID::Timestamp* LogMessage::release_timestamp() {
  
  ::PROTOBUF_NAMESPACE_ID::Timestamp* temp = _impl_.timestamp_;
  _impl_.timestamp_ = nullptr;
#ifdef PROTOBUF_FORCE_COPY_IN_RELEASE
  auto* old =  reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(temp);
  temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  if (GetArenaForAllocation() == nullptr) { delete old; }
#else  // PROTOBUF_FORCE_COPY_IN_RELEASE
  if (GetArenaForAllocation() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
#endif  // !PROTOBUF_FORCE_COPY_IN_RELEASE
  return temp;
}
inline ::PROTOBUF_NAMESPACE_ID::Timestamp* LogMessage::unsafe_arena_release_timestamp() {
  // @@protoc_insertion_point(field_release:protobuf.LogMessage.timestamp)
  
  ::PROTOBUF_NAMESPACE_ID::Timestamp* temp = _impl_.timestamp_;
  _impl_.timestamp_ = nullptr;
  return temp;
}
inline ::PROTOBUF_NAMESPACE_ID::Timestamp* LogMessage::_internal_mutable_timestamp() {
  
  if (_impl_.timestamp_ == nullptr) {
    auto* p = CreateMaybeMessage<::PROTOBUF_NAMESPACE_ID::Timestamp>(GetArenaForAllocation());
    _impl_.timestamp_ = p;
  }
  return _impl_.timestamp_;
}
inline ::PROTOBUF_NAMESPACE_ID::Timestamp* LogMessage::mutable_timestamp() {
  ::PROTOBUF_NAMESPACE_ID::Timestamp* _msg = _internal_mutable_timestamp();
  // @@protoc_insertion_point(field_mutable:protobuf.LogMessage.timestamp)
  return _msg;
}
inline void LogMessage::set_allocated_timestamp(::PROTOBUF_NAMESPACE_ID::Timestamp* timestamp) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaForAllocation();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::PROTOBUF_NAMESPACE_ID::MessageLite*>(_impl_.timestamp_);
  }
  if (timestamp) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
        ::PROTOBUF_NAMESPACE_ID::Arena::InternalGetOwningArena(
                reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(timestamp));
    if (message_arena != submessage_arena) {
      timestamp = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, timestamp, submessage_arena);
    }
    
  } else {
    
  }
  _impl_.timestamp_ = timestamp;
  // @@protoc_insertion_point(field_set_allocated:protobuf.LogMessage.timestamp)
}

// .protobuf.LogLevel log_level = 2;
inline void LogMessage::clear_log_level() {
  _impl_.log_level_ = 0;
}
inline ::protobuf::LogLevel LogMessage::_internal_log_level() const {
  return static_cast< ::protobuf::LogLevel >(_impl_.log_level_);
}
inline ::protobuf::LogLevel LogMessage::log_level() const {
  // @@protoc_insertion_point(field_get:protobuf.LogMessage.log_level)
  return _internal_log_level();
}
inline void LogMessage::_internal_set_log_level(::protobuf::LogLevel value) {
  
  _impl_.log_level_ = value;
}
inline void LogMessage::set_log_level(::protobuf::LogLevel value) {
  _internal_set_log_level(value);
  // @@protoc_insertion_point(field_set:protobuf.LogMessage.log_level)
}

// string message = 3;
inline void LogMessage::clear_message() {
  _impl_.message_.ClearToEmpty();
}
inline const std::string& LogMessage::message() const {
  // @@protoc_insertion_point(field_get:protobuf.LogMessage.message)
  return _internal_message();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void LogMessage::set_message(ArgT0&& arg0, ArgT... args) {
 
 _impl_.message_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:protobuf.LogMessage.message)
}
inline std::string* LogMessage::mutable_message() {
  std::string* _s = _internal_mutable_message();
  // @@protoc_insertion_point(field_mutable:protobuf.LogMessage.message)
  return _s;
}
inline const std::string& LogMessage::_internal_message() const {
  return _impl_.message_.Get();
}
inline void LogMessage::_internal_set_message(const std::string& value) {
  
  _impl_.message_.Set(value, GetArenaForAllocation());
}
inline std::string* LogMessage::_internal_mutable_message() {
  
  return _impl_.message_.Mutable(GetArenaForAllocation());
}
inline std::string* LogMessage::release_message() {
  // @@protoc_insertion_point(field_release:protobuf.LogMessage.message)
  return _impl_.message_.Release();
}
inline void LogMessage::set_allocated_message(std::string* message) {
  if (message != nullptr) {
    
  } else {
    
  }
  _impl_.message_.SetAllocated(message, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.message_.IsDefault()) {
    _impl_.message_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:protobuf.LogMessage.message)
}

// .protobuf.ApplicationLanguage app_lang = 4;
inline void LogMessage::clear_app_lang() {
  _impl_.app_lang_ = 0;
}
inline ::protobuf::ApplicationLanguage LogMessage::_internal_app_lang() const {
  return static_cast< ::protobuf::ApplicationLanguage >(_impl_.app_lang_);
}
inline ::protobuf::ApplicationLanguage LogMessage::app_lang() const {
  // @@protoc_insertion_point(field_get:protobuf.LogMessage.app_lang)
  return _internal_app_lang();
}
inline void LogMessage::_internal_set_app_lang(::protobuf::ApplicationLanguage value) {
  
  _impl_.app_lang_ = value;
}
inline void LogMessage::set_app_lang(::protobuf::ApplicationLanguage value) {
  _internal_set_app_lang(value);
  // @@protoc_insertion_point(field_set:protobuf.LogMessage.app_lang)
}

// string uid = 5;
inline void LogMessage::clear_uid() {
  _impl_.uid_.ClearToEmpty();
}
inline const std::string& LogMessage::uid() const {
  // @@protoc_insertion_point(field_get:protobuf.LogMessage.uid)
  return _internal_uid();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void LogMessage::set_uid(ArgT0&& arg0, ArgT... args) {
 
 _impl_.uid_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:protobuf.LogMessage.uid)
}
inline std::string* LogMessage::mutable_uid() {
  std::string* _s = _internal_mutable_uid();
  // @@protoc_insertion_point(field_mutable:protobuf.LogMessage.uid)
  return _s;
}
inline const std::string& LogMessage::_internal_uid() const {
  return _impl_.uid_.Get();
}
inline void LogMessage::_internal_set_uid(const std::string& value) {
  
  _impl_.uid_.Set(value, GetArenaForAllocation());
}
inline std::string* LogMessage::_internal_mutable_uid() {
  
  return _impl_.uid_.Mutable(GetArenaForAllocation());
}
inline std::string* LogMessage::release_uid() {
  // @@protoc_insertion_point(field_release:protobuf.LogMessage.uid)
  return _impl_.uid_.Release();
}
inline void LogMessage::set_allocated_uid(std::string* uid) {
  if (uid != nullptr) {
    
  } else {
    
  }
  _impl_.uid_.SetAllocated(uid, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.uid_.IsDefault()) {
    _impl_.uid_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:protobuf.LogMessage.uid)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace protobuf

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::protobuf::LogLevel> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::protobuf::LogLevel>() {
  return ::protobuf::LogLevel_descriptor();
}
template <> struct is_proto_enum< ::protobuf::ApplicationLanguage> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::protobuf::ApplicationLanguage>() {
  return ::protobuf::ApplicationLanguage_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_LogMessage_2eproto
