NAME        = libftprintf.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
LIBFT_DIR   = ./libft
LIBFT       = $(LIBFT_DIR)/libft.a

SRCS        = ft_printf.c \
              ft_formats.c \
              ft_print_char.c \
              ft_print_str.c \
              ft_print_nbr.c \
              ft_print_hex.c \
              ft_print_ptr.c \
              ft_print_uns.c

OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	@cp $(LIBFT) $(NAME)
	@ar rcs $(NAME) $(OBJS)
	@echo "libftprintf.a oluşturuldu!"

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re