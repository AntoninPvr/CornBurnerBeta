#ifndef COM_H
#define COM_H

#include "driver.h"

// Parameters
#define COM_BUFFER_SIZE 64

// Symbols
#define H_HEADER_SYMBOL '\x02'
#define H_SYM_BELL '\x07'

#define H_SYM_ALL '*'

#define H_SYM_TEMP 'T'
#define H_SYM_TEMP_AMBIENT 'a'
#define H_SYM_TEMP_ENGINE 'e'
#define H_SYM_TEMP_FUEL 'f'
#define H_SYM_TEMP_UC 'u'

#define H_TYPE_UINT8 'U'
#define H_TYPE_UINT16 'V'
#define H_TYPE_UINT32 'W'
#define H_TYPE_UINT64 'X'
#define H_TYPE_INT8 'I'
#define H_TYPE_INT16 'J'
#define H_TYPE_INT32 'K'
#define H_TYPE_INT64 'L'
#define H_TYPE_FLOAT 'F'
#define H_TYPE_DOUBLE 'D'
#define H_TYPE_STRING 'S'
#define H_TYPE_BOOL 'B'

// Variables
struct com_buffer {
    uint8_t size;
    uint8_t index;
    uint8_t data[COM_BUFFER_SIZE];
};

uint8_t buffer_to_transmit[COM_BUFFER_SIZE];

// Functions prototypes
void update_header_sym_buffer(struct com_buffer *buffer, char header_symbol);
void send_all_data(struct com_buffer *buffer);
void _add_bell_buffer(struct com_buffer *buffer);

void _add_data_to_buffer(struct com_buffer *buffer, uint8_t *data, uint8_t size);

void _add_uint8_buffer(struct com_buffer *buffer, uint8_t data);
void _add_uint16_buffer(struct com_buffer *buffer, uint16_t data);
void _add_uint32_buffer(struct com_buffer *buffer, uint32_t data);
void _add_uint64_buffer(struct com_buffer *buffer, uint64_t data);
void _add_int8_buffer(struct com_buffer *buffer, int8_t data);
void _add_int16_buffer(struct com_buffer *buffer, int16_t data);
void _add_int32_buffer(struct com_buffer *buffer, int32_t data);
void _add_int64_buffer(struct com_buffer *buffer, int64_t data);
void _add_float_buffer(struct com_buffer *buffer, float data);
void _add_double_buffer(struct com_buffer *buffer, double data);
void _add_bool_buffer(struct com_buffer *buffer, uint8_t data);
#endif // COM_H
