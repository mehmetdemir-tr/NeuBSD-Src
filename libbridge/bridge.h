#pragma once
#define RAND_MAX        (((unsigned int)-1)/2)
#define EXIT_FAILURE    1
#define EXIT_SUCCESS    0

_Noreturn void __bridge_process_exit(int status);
_Noreturn void __bridge_process_abort(void);

void* __bridge_memory_allocate(unsigned long long size);
void __bridge_memory_free(void* pointer);

int __bridge_execute_command(const char* command);
char* __bridge_execute_getenv(const char* name);

int __bridge_randgen_generate(void);
void __bridge_randgen_seed(unsigned int seed);