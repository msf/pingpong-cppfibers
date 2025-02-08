// Code generated by protoc-gen-go. DO NOT EDIT.
// versions:
// 	protoc-gen-go v1.36.5
// 	protoc        v3.21.12
// source: pingpong.proto

package pingpong

import (
	protoreflect "google.golang.org/protobuf/reflect/protoreflect"
	protoimpl "google.golang.org/protobuf/runtime/protoimpl"
	reflect "reflect"
	sync "sync"
	unsafe "unsafe"
)

const (
	// Verify that this generated code is sufficiently up-to-date.
	_ = protoimpl.EnforceVersion(20 - protoimpl.MinVersion)
	// Verify that runtime/protoimpl is sufficiently up-to-date.
	_ = protoimpl.EnforceVersion(protoimpl.MaxVersion - 20)
)

type Ping struct {
	state         protoimpl.MessageState `protogen:"open.v1"`
	Sequence      uint64                 `protobuf:"varint,1,opt,name=sequence,proto3" json:"sequence,omitempty"`
	Timestamp     uint64                 `protobuf:"varint,2,opt,name=timestamp,proto3" json:"timestamp,omitempty"`
	Payload       []byte                 `protobuf:"bytes,3,opt,name=payload,proto3" json:"payload,omitempty"`
	unknownFields protoimpl.UnknownFields
	sizeCache     protoimpl.SizeCache
}

func (x *Ping) Reset() {
	*x = Ping{}
	mi := &file_pingpong_proto_msgTypes[0]
	ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
	ms.StoreMessageInfo(mi)
}

func (x *Ping) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*Ping) ProtoMessage() {}

func (x *Ping) ProtoReflect() protoreflect.Message {
	mi := &file_pingpong_proto_msgTypes[0]
	if x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use Ping.ProtoReflect.Descriptor instead.
func (*Ping) Descriptor() ([]byte, []int) {
	return file_pingpong_proto_rawDescGZIP(), []int{0}
}

func (x *Ping) GetSequence() uint64 {
	if x != nil {
		return x.Sequence
	}
	return 0
}

func (x *Ping) GetTimestamp() uint64 {
	if x != nil {
		return x.Timestamp
	}
	return 0
}

func (x *Ping) GetPayload() []byte {
	if x != nil {
		return x.Payload
	}
	return nil
}

type Pong struct {
	state           protoimpl.MessageState `protogen:"open.v1"`
	Sequence        uint64                 `protobuf:"varint,1,opt,name=sequence,proto3" json:"sequence,omitempty"`
	Timestamp       uint64                 `protobuf:"varint,2,opt,name=timestamp,proto3" json:"timestamp,omitempty"`
	ServerTimestamp uint64                 `protobuf:"varint,3,opt,name=server_timestamp,json=serverTimestamp,proto3" json:"server_timestamp,omitempty"`
	Payload         []byte                 `protobuf:"bytes,4,opt,name=payload,proto3" json:"payload,omitempty"`
	unknownFields   protoimpl.UnknownFields
	sizeCache       protoimpl.SizeCache
}

func (x *Pong) Reset() {
	*x = Pong{}
	mi := &file_pingpong_proto_msgTypes[1]
	ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
	ms.StoreMessageInfo(mi)
}

func (x *Pong) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*Pong) ProtoMessage() {}

func (x *Pong) ProtoReflect() protoreflect.Message {
	mi := &file_pingpong_proto_msgTypes[1]
	if x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use Pong.ProtoReflect.Descriptor instead.
func (*Pong) Descriptor() ([]byte, []int) {
	return file_pingpong_proto_rawDescGZIP(), []int{1}
}

func (x *Pong) GetSequence() uint64 {
	if x != nil {
		return x.Sequence
	}
	return 0
}

func (x *Pong) GetTimestamp() uint64 {
	if x != nil {
		return x.Timestamp
	}
	return 0
}

func (x *Pong) GetServerTimestamp() uint64 {
	if x != nil {
		return x.ServerTimestamp
	}
	return 0
}

func (x *Pong) GetPayload() []byte {
	if x != nil {
		return x.Payload
	}
	return nil
}

var File_pingpong_proto protoreflect.FileDescriptor

var file_pingpong_proto_rawDesc = string([]byte{
	0x0a, 0x0e, 0x70, 0x69, 0x6e, 0x67, 0x70, 0x6f, 0x6e, 0x67, 0x2e, 0x70, 0x72, 0x6f, 0x74, 0x6f,
	0x12, 0x08, 0x70, 0x69, 0x6e, 0x67, 0x70, 0x6f, 0x6e, 0x67, 0x22, 0x5a, 0x0a, 0x04, 0x50, 0x69,
	0x6e, 0x67, 0x12, 0x1a, 0x0a, 0x08, 0x73, 0x65, 0x71, 0x75, 0x65, 0x6e, 0x63, 0x65, 0x18, 0x01,
	0x20, 0x01, 0x28, 0x04, 0x52, 0x08, 0x73, 0x65, 0x71, 0x75, 0x65, 0x6e, 0x63, 0x65, 0x12, 0x1c,
	0x0a, 0x09, 0x74, 0x69, 0x6d, 0x65, 0x73, 0x74, 0x61, 0x6d, 0x70, 0x18, 0x02, 0x20, 0x01, 0x28,
	0x04, 0x52, 0x09, 0x74, 0x69, 0x6d, 0x65, 0x73, 0x74, 0x61, 0x6d, 0x70, 0x12, 0x18, 0x0a, 0x07,
	0x70, 0x61, 0x79, 0x6c, 0x6f, 0x61, 0x64, 0x18, 0x03, 0x20, 0x01, 0x28, 0x0c, 0x52, 0x07, 0x70,
	0x61, 0x79, 0x6c, 0x6f, 0x61, 0x64, 0x22, 0x85, 0x01, 0x0a, 0x04, 0x50, 0x6f, 0x6e, 0x67, 0x12,
	0x1a, 0x0a, 0x08, 0x73, 0x65, 0x71, 0x75, 0x65, 0x6e, 0x63, 0x65, 0x18, 0x01, 0x20, 0x01, 0x28,
	0x04, 0x52, 0x08, 0x73, 0x65, 0x71, 0x75, 0x65, 0x6e, 0x63, 0x65, 0x12, 0x1c, 0x0a, 0x09, 0x74,
	0x69, 0x6d, 0x65, 0x73, 0x74, 0x61, 0x6d, 0x70, 0x18, 0x02, 0x20, 0x01, 0x28, 0x04, 0x52, 0x09,
	0x74, 0x69, 0x6d, 0x65, 0x73, 0x74, 0x61, 0x6d, 0x70, 0x12, 0x29, 0x0a, 0x10, 0x73, 0x65, 0x72,
	0x76, 0x65, 0x72, 0x5f, 0x74, 0x69, 0x6d, 0x65, 0x73, 0x74, 0x61, 0x6d, 0x70, 0x18, 0x03, 0x20,
	0x01, 0x28, 0x04, 0x52, 0x0f, 0x73, 0x65, 0x72, 0x76, 0x65, 0x72, 0x54, 0x69, 0x6d, 0x65, 0x73,
	0x74, 0x61, 0x6d, 0x70, 0x12, 0x18, 0x0a, 0x07, 0x70, 0x61, 0x79, 0x6c, 0x6f, 0x61, 0x64, 0x18,
	0x04, 0x20, 0x01, 0x28, 0x0c, 0x52, 0x07, 0x70, 0x61, 0x79, 0x6c, 0x6f, 0x61, 0x64, 0x32, 0x42,
	0x0a, 0x08, 0x50, 0x69, 0x6e, 0x67, 0x50, 0x6f, 0x6e, 0x67, 0x12, 0x36, 0x0a, 0x0e, 0x53, 0x74,
	0x72, 0x65, 0x61, 0x6d, 0x50, 0x69, 0x6e, 0x67, 0x50, 0x6f, 0x6e, 0x67, 0x12, 0x0e, 0x2e, 0x70,
	0x69, 0x6e, 0x67, 0x70, 0x6f, 0x6e, 0x67, 0x2e, 0x50, 0x69, 0x6e, 0x67, 0x1a, 0x0e, 0x2e, 0x70,
	0x69, 0x6e, 0x67, 0x70, 0x6f, 0x6e, 0x67, 0x2e, 0x50, 0x6f, 0x6e, 0x67, 0x22, 0x00, 0x28, 0x01,
	0x30, 0x01, 0x42, 0x14, 0x5a, 0x12, 0x70, 0x6b, 0x67, 0x2f, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x2f,
	0x70, 0x69, 0x6e, 0x67, 0x70, 0x6f, 0x6e, 0x67, 0x62, 0x06, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x33,
})

var (
	file_pingpong_proto_rawDescOnce sync.Once
	file_pingpong_proto_rawDescData []byte
)

func file_pingpong_proto_rawDescGZIP() []byte {
	file_pingpong_proto_rawDescOnce.Do(func() {
		file_pingpong_proto_rawDescData = protoimpl.X.CompressGZIP(unsafe.Slice(unsafe.StringData(file_pingpong_proto_rawDesc), len(file_pingpong_proto_rawDesc)))
	})
	return file_pingpong_proto_rawDescData
}

var file_pingpong_proto_msgTypes = make([]protoimpl.MessageInfo, 2)
var file_pingpong_proto_goTypes = []any{
	(*Ping)(nil), // 0: pingpong.Ping
	(*Pong)(nil), // 1: pingpong.Pong
}
var file_pingpong_proto_depIdxs = []int32{
	0, // 0: pingpong.PingPong.StreamPingPong:input_type -> pingpong.Ping
	1, // 1: pingpong.PingPong.StreamPingPong:output_type -> pingpong.Pong
	1, // [1:2] is the sub-list for method output_type
	0, // [0:1] is the sub-list for method input_type
	0, // [0:0] is the sub-list for extension type_name
	0, // [0:0] is the sub-list for extension extendee
	0, // [0:0] is the sub-list for field type_name
}

func init() { file_pingpong_proto_init() }
func file_pingpong_proto_init() {
	if File_pingpong_proto != nil {
		return
	}
	type x struct{}
	out := protoimpl.TypeBuilder{
		File: protoimpl.DescBuilder{
			GoPackagePath: reflect.TypeOf(x{}).PkgPath(),
			RawDescriptor: unsafe.Slice(unsafe.StringData(file_pingpong_proto_rawDesc), len(file_pingpong_proto_rawDesc)),
			NumEnums:      0,
			NumMessages:   2,
			NumExtensions: 0,
			NumServices:   1,
		},
		GoTypes:           file_pingpong_proto_goTypes,
		DependencyIndexes: file_pingpong_proto_depIdxs,
		MessageInfos:      file_pingpong_proto_msgTypes,
	}.Build()
	File_pingpong_proto = out.File
	file_pingpong_proto_goTypes = nil
	file_pingpong_proto_depIdxs = nil
}
