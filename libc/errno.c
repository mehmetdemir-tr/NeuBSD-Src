static int __errno = 0;
int* __errno_pointer(void) {
    return &__errno;
}