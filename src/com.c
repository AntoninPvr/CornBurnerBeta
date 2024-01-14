#include "com.h"

void update_header_sym_buffer(struct com_buffer *buffer, char header_symbol) {
    if (buffer->index+2 < buffer->size) {
        buffer->data[buffer->index] = H_HEADER_SYMBOL;
        buffer->index++;
        buffer->data[buffer->index] = header_symbol;
        buffer->index++;
    }
}

void add_uint8_buffer(struct com_buffer *buffer, uint8_t data) {
    if (buffer->index+sizeof(data)+1 < buffer->size) {
        buffer->data[buffer->index] = H_TYPE_UINT8;
        buffer->index++;
        _add_data_to_buffer(buffer, (uint8_t *) &data, 1);
    }
}

void _add_uint16_buffer(struct com_buffer *buffer, uint16_t data) {
    if (buffer->index+sizeof(data)+1 < buffer->size) {
        buffer->data[buffer->index] = H_TYPE_UINT16;
        buffer->index++;
        _add_data_to_buffer(buffer, (uint8_t *) &data, sizeof(data));
    }
}

void _add_uint32_buffer(struct com_buffer *buffer, uint32_t data) {
    if (buffer->index+sizeof(data)+1 < buffer->size) {
        buffer->data[buffer->index] = H_TYPE_UINT32;
        buffer->index++;
        _add_data_to_buffer(buffer, (uint8_t *) &data, sizeof(data));
    }
}

void _add_uint64_buffer(struct com_buffer *buffer, uint64_t data) {
    if (buffer->index+sizeof(data)+1 < buffer->size) {
        buffer->data[buffer->index] = H_TYPE_UINT64;
        buffer->index++;
        _add_data_to_buffer(buffer, (uint8_t *) &data, sizeof(data));
    }
}

void _add_int8_buffer(struct com_buffer *buffer, int8_t data) {
    if (buffer->index+sizeof(data)+1 < buffer->size) {
        buffer->data[buffer->index] = H_TYPE_INT8;
        buffer->index++;
        _add_data_to_buffer(buffer, (uint8_t *) &data, sizeof(data));
    }
}

void _add_int16_buffer(struct com_buffer *buffer, int16_t data) {
    if (buffer->index+sizeof(data)+1 < buffer->size) {
        buffer->data[buffer->index] = H_TYPE_INT16;
        buffer->index++;
        _add_data_to_buffer(buffer, (uint8_t *) &data, sizeof(data));
    }
}

void _add_int32_buffer(struct com_buffer *buffer, int32_t data) {
    if (buffer->index+sizeof(data)+1 < buffer->size) {
        buffer->data[buffer->index] = H_TYPE_INT32;
        buffer->index++;
        _add_data_to_buffer(buffer, (uint8_t *) &data, sizeof(data));
    }
}

void _add_int64_buffer(struct com_buffer *buffer, int64_t data) {
    if (buffer->index+sizeof(data)+1 < buffer->size) {
        buffer->data[buffer->index] = H_TYPE_INT64;
        buffer->index++;
        _add_data_to_buffer(buffer, (uint8_t *) &data, sizeof(data));
    }
}

void _add_float_buffer(struct com_buffer *buffer, float data) {
    if (buffer->index+sizeof(data)+1 < buffer->size) {
        buffer->data[buffer->index] = H_TYPE_FLOAT;
        buffer->index++;
        _add_data_to_buffer(buffer, (uint8_t *) &data, sizeof(data));
    }
}

void _add_double_buffer(struct com_buffer *buffer, double data) {
    if (buffer->index+sizeof(data)+1 < buffer->size) {
        buffer->data[buffer->index] = H_TYPE_DOUBLE;
        buffer->index++;
        _add_data_to_buffer(buffer, (uint8_t *) &data, sizeof(data));
    }
}

void _add_bool_buffer(struct com_buffer *buffer, uint8_t data) {
    if (buffer->index+sizeof(data)+1 < buffer->size) {
        buffer->data[buffer->index] = H_TYPE_BOOL;
        buffer->index++;
        _add_data_to_buffer(buffer, (uint8_t *) &data, sizeof(data));
    }
}

void _add_data_to_buffer(struct com_buffer *buffer, uint8_t *data, uint8_t size) {
    if (buffer->index+size < buffer->size) {
        for (uint8_t i = 0; i < size; i++) {
            buffer->data[buffer->index] = data[i];
            buffer->index++;
        }
    }
}

void _add_bell_buffer(struct com_buffer *buffer) {
    if (buffer->index+1 < buffer->size) {
        buffer->data[buffer->index] = H_SYM_BELL;
        buffer->index++;
    }
}

void all_data_to_buffer(struct com_buffer *buffer) {
    update_header_sym_buffer(buffer, H_HEADER_SYMBOL);
}