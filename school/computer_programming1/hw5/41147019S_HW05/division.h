#pragma once

#include <stdint.h>

 // X/Y
void division( uint8_t **ppQuotient , uint8_t *pQuotientSize , uint8_t **ppRemainder , uint8_t *pRemainderSize , uint8_t *pX, uint8_t xSize , uint8_t *pY, uint8_t ySize );
void minus(uint8_t *x, uint8_t *y, uint8_t x_len, uint8_t y_len, uint8_t *digit);
void change(uint8_t *x, uint8_t *y, uint8_t x_len, uint8_t y_len);
void memory_alloc(uint8_t **ptr, size_t s);
int32_t judge(uint8_t *x, uint8_t *y, uint8_t x_len, uint8_t y_len);