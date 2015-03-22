NAME = libftasm

LIB = libfts.a

TEST = test_libftasm

SFILES = 	ft_isalnum.s \
			ft_isalpha.s \
			ft_isdigit.s \
			ft_isascii.s \
			ft_isprint.s \
			ft_tolower.s \
			ft_toupper.s \
			ft_bzero.s \
			ft_strcat.s \
			ft_strlen.s \
			ft_memset.s \
			ft_memcpy.s \

OBJ = $(SFILES:.s=.o)

$(NAME): $(LIB) $(OBJ) libfts.h

all: $(LIB) $(OBJ) $(NAME)

$(LIB): $(OBJ)
	ar rc $(LIB) $(OBJ)
	ranlib $(LIB)

%.o: %.s
	nasm -f macho64 $<

re: fclean all

clean:
	rm -f *.o

fclean: clean
	rm -f $(LIB)

test: main.c $(NAME)
	gcc main.c $(LIB) -o $(TEST)
