# Libft

Libft is a minimalistic subset of the standard C library. Implementation of the GNU C Library for Embedded Systems.

### Installation

Libft requires no dependencies.

```sh
$ cd Libft
$ make
```

### List of standart libc functions

| memory  | string    | ctype    | io      | math  |
| ------- | --------- | -------- | ------- | ----- |
| bzero   | strlen    | isalpha  | putchar | max   |
| calloc  | strcpy    | isdigit  | putstr  | min   |
| memcpy  | strcat    | isalnum  | putendl | isinf |
| memmove | strchr    | isascii  | getline | isnan |
| memchr  | strcmp    | isprint  |         |       |
| memcmp  | atoi      | isupper  |         |       |
| memset  | strdup    | islower  |         |       |
| memccpy | strstr    | isspaace |         |       |
| mempcpy | strrchr   | toupper  |         |       |
|         | strncpy   | tolowet  |         |       |
|         | strncat   | wctomb   |         |       |
|         | strncmp   |          |         |       |
|         | strnstr   |          |         |       |
|         | strlcat   |          |         |       |
|         | strlcpy   |          |         |       |
|         | itoa      |          |         |       |
|         | ltoa      |          |         |       |
|         | ultoa     |          |         |       |
|         | strtol    |          |         |       |
|         | strtoul   |          |         |       |
|         | strnlen   |          |         |       |
|         | strchrnul |          |         |       |

### List of nonstandart functions

| memory          | string     | ctype      | io      | math         | linked list   | doubly linked list |
| --------------- | ---------- | ---------- | ------- | ------------ | ------------- | ------------------ |
| memalloc        | strnew     | isnegative | putnbr  | num_of_digs  | lstnew        | dlstnew            |
| memdel          | strjoin    | ispositive | putlnbr | unum_of_digs | lstadd        | dlstadd            |
| repcset         | strequ     | isbeween   |         |              | lstrev        | dlstdelone         |
| optmemalign     | strsplit   |            |         |              | lstdelone     | dlstdel            |
| memaligncmp     | strsub     |            |         |              | lstdel        | dlstiter           |
| memaligncmp_bwd | strdel     |            |         |              | lstiter       | dlstmap            |
| memappend       | strclr     |            |         |              | lstmap        | dlstlength         |
|                 | strtrim    |            |         |              | lstdelcontent | dlstedge           |
|                 | striter    |            |         |              | lstlength     | dlstloop           |
|                 | striteri   |            |         |              | lstadd_front  | dlstunloop         |
|                 | strmap     |            |         |              | lstsize       |                    |
|                 | strmapi    |            |         |              | lstlast       |                    |
|                 | strappend  |            |         |              | lstadd_bask   |                    |
|                 | strnequ    |            |         |              | lstclear      |                    |
|                 | strnappend |            |         |              |               |                    |

### Todos

 - Add printf
 - Wrtite code for vectors and matrices
 - replace d/lstlength on d/lstsize