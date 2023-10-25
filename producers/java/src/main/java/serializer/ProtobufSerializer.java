package serializer;

import org.apache.kafka.common.serialization.Serializer;

public class ProtobufSerializer<T extends com.google.protobuf.Message> implements Serializer<T> {
    @Override
    public byte[] serialize(String topic, T data) {
        return data.toByteArray();
    }
}