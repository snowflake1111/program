#pragma once

#include <stdint.h>

int32_t mymem_alloc( uint8_t **ptr, size_t size );
int32_t mymem_set( uint8_t *ptr, size_t idx, uint8_t value );
int32_t mymem_set_array( uint8_t *ptr, size_t start , uint8_t array[], size_t n );
int32_t mymem_rellocate( uint8_t **ptr, size_t new_size );
void mymem_free( uint8_t *ptr );