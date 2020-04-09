package bgu.spl.net.impl.stomp;
import bgu.spl.net.api.MessageEncoderDecoder;

import java.nio.charset.StandardCharsets;
import java.util.Arrays;

public class StompMessageEncoderDecoderImpl implements MessageEncoderDecoder<StompFrame> {

    private byte[] bytes = new byte[1 << 10];
    private int len = 0;

    @Override
    public StompFrame decodeNextByte(byte nextByte) {
        if (nextByte == '\0') {
            return popStomp(bytes);
        }
        pushByte(nextByte);
        return null;
    }

    @Override
    public byte[] encode(StompFrame message) {
        String result = message.toString();
        return result.getBytes();
    }

    private void pushByte(byte nextByte) {
        if (len >= bytes.length) {
            bytes = Arrays.copyOf(bytes, len * 2);
        }
        bytes[len++] = nextByte;
    }

    public StompFrame popStomp(byte [] data) {
        String result = new String(data, 0, len, StandardCharsets.UTF_8);
        StompFrame frame = new StompFrame(result);
        len = 0;
        return frame;
    }
}
