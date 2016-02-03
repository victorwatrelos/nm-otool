CC= gcc
FLAGS= -Wall -Wextra -Werror -O3
SRC_NM= main.c \
	 puthexa.c \
	 process_file.c \
	 get_data_from_bytes_array.c \
	 load_cmd_64.c \
	 load_cmd.c \
	 util.c \
	 lstsort.c \
	 process_segment.c \
	 process_segment_64.c \
	 process_symtab.c \
	 process_symtab_util.c \
	 process_symtab_64.c \
	 process_symtab_util_64.c \
	 process_fat.c \
	 main_util.c \
	 read_magic.c \
	 process_ar.c

SRC_OTOOL = otool_main.c \
	 main_util.c \
	 otool.c \
	 otool_segment_64.c \
	 otool_segment.c \
	 puthexa.c \
	 read_magic.c \
	 get_data_from_bytes_array.c \
	 otool_load.c \
	 otool_ar.c \
	 util.c \
	 lstsort.c \
	 process_segment.c \
	 otool_fat.c \
	 otool_load_cmd_64.c

OBJ_NM= $(SRC_NM:.c=.o)
OBJ_OTOOL= $(SRC_OTOOL:.c=.o)

NAME_NM=ft_nm
NAME_OTOOL=ft_otool
LIB=-L./libft -lft_core -lft_list -lft_printf
DIR_LFT=./libft
INCLUDES=./libft/includes

.PHONY: clean fclean re all

.SILENT:

all: $(NAME_NM) $(NAME_OTOOL)

$(NAME_NM): $(OBJ_NM)
	(cd $(DIR_LFT) ; make )
	$(CC) -o $(NAME_NM) $(OBJ_NM) $(LIB) $(FLAGS)
	echo "\t\xF0\x9F\x8F\x81   Compiling \033[35m$(NAME_NM) \033[0mDONE!"

$(NAME_OTOOL): $(OBJ_OTOOL)
	(cd $(DIR_LFT) ; make)
	$(CC) -o $(NAME_OTOOL) $(OBJ_OTOOL) $(LIB) $(FLAGS)
	echo "\t\xF0\x9F\x8F\x81   Compiling \033[35m$(NAME_OTOOL) \033[0mDONE!"

%.o: %.c
	echo "\t\xF0\x9F\x94\xA7   Building \033[34m $@ \033[0m"
	$(CC) -c $(FLAGS) -o $@ $< -I $(INCLUDES)

clean:
	(cd $(DIR_LFT) ; make clean)
	echo "\t\xF0\x9F\x92\xA3   Cleaning"
	rm -rf $(OBJ_NM)
	rm -rf $(OBJ_OTOOL)

fclean: clean
	(cd $(DIR_LFT) ; make fclean)
	echo "\t\xF0\x9F\x9A\xBD   Full Clean"
	rm -rf $(NAME_NM)
	rm -rf $(NAME_OTOOL)

re: fclean all
