#ifndef WRAPPER_H
#define WRAPPER_H

#ifdef __cplusplus
extern "C" {
#endif

void serial_begin(int baudrate);
void serial_println(const char* message);

#ifdef __cplusplus
}
#endif

#endif /* WRAPPER_H */
