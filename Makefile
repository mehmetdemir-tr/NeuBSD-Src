LIBC_SRCS := $(wildcard libc/*.c)
LIBC_OBJS := $(LIBC_SRCS:.c=.o)

LIBBRIDGE_SRCS := $(wildcard libbridge/*.c)
LIBBRIDGE_OBJS := $(LIBBRIDGE_SRCS:.c=.o)

all: $(LIBC_OBJS) $(LIBBRIDGE_OBJS)

%.o: %.c
	$(CC) -nostdlib -nostdinc -Werror -Wno-invalid-noreturn -Wno-return-type -Wno-incompatible-pointer-types-discards-qualifiers -Wno-incompatible-library-redeclaration -Ilibc/include $(CFLAGS) -c $< -o $@
clean:
	rm $(LIBBRIDGE_OBJS) $(LIBC_OBJS)