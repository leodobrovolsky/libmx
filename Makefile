NAME = libmx.a

CFLAG = -std=c11 -Wall -Wextra -Werror -Wpedantic

LIBS = 

INC = inc/libmx.h

INCS = libmx.h

SRC =  src/mx_atoi.c src/mx_binary_search.c src/mx_bubble_sort.c src/mx_count_substr.c src/mx_count_words.c src/mx_count_words_space.c src/mx_create_node.c src/mx_del_extra_spaces.c src/mx_del_strarr.c src/mx_file_to_str.c src/mx_foreach.c src/mx_get_char_index.c src/mx_get_substr_index.c src/mx_hex_to_nbr.c src/mx_isdigit.c src/mx_islower.c src/mx_isspace.c src/mx_isupper.c src/mx_itoa.c src/mx_linear_search.c src/mx_list_size.c src/mx_memccpy.c src/mx_memchr.c src/mx_memcmp.c src/mx_memcpy.c src/mx_memmem.c src/mx_memmove.c src/mx_memset.c src/mx_nbr_to_hex.c src/mx_pop_back.c src/mx_pop_front.c src/mx_pop_index.c src/mx_pow.c src/mx_print_error.c src/mx_print_strarr.c src/mx_printchar.c src/mx_printint.c src/mx_printstr.c src/mx_push_back.c src/mx_push_front.c src/mx_push_index.c src/mx_replace_substr.c src/mx_sort_list.c src/mx_sqrt.c src/mx_str_reverse.c src/mx_strcat.c src/mx_strchr.c src/mx_strcmp.c src/mx_strcpy.c src/mx_strdel.c src/mx_strdup.c src/mx_strjoin.c src/mx_strlen.c src/mx_strncmp.c src/mx_strncpy.c src/mx_strndup.c src/mx_strnew.c src/mx_strsplit.c src/mx_strstr.c src/mx_strtrim.c src/mx_strtrim_char.c src/mx_super_atoi.c src/mx_swap_char.c src/mx_swap_str.c src/mx_tolower.c src/mx_toupper.c

SRCS =  mx_atoi.c mx_binary_search.c mx_bubble_sort.c mx_count_substr.c mx_count_words.c mx_count_words_space.c mx_create_node.c mx_del_extra_spaces.c mx_del_strarr.c mx_file_to_str.c mx_foreach.c mx_get_char_index.c mx_get_substr_index.c mx_hex_to_nbr.c mx_isdigit.c mx_islower.c mx_isspace.c mx_isupper.c mx_itoa.c mx_linear_search.c mx_list_size.c mx_memccpy.c mx_memchr.c mx_memcmp.c mx_memcpy.c mx_memmem.c mx_memmove.c mx_memset.c mx_nbr_to_hex.c mx_pop_back.c mx_pop_front.c mx_pop_index.c mx_pow.c mx_print_error.c mx_print_strarr.c mx_printchar.c mx_printint.c mx_printstr.c mx_push_back.c mx_push_front.c mx_push_index.c mx_replace_substr.c mx_sort_list.c mx_sqrt.c mx_str_reverse.c mx_strcat.c mx_strchr.c mx_strcmp.c mx_strcpy.c mx_strdel.c mx_strdup.c mx_strjoin.c mx_strlen.c mx_strncmp.c mx_strncpy.c mx_strndup.c mx_strnew.c mx_strsplit.c mx_strstr.c mx_strtrim.c mx_strtrim_char.c mx_super_atoi.c mx_swap_char.c mx_swap_str.c mx_tolower.c mx_toupper.c

OBJ_DIR = obj

OBJ =  obj/mx_atoi.o obj/mx_binary_search.o obj/mx_bubble_sort.o obj/mx_count_substr.o obj/mx_count_words.o obj/mx_count_words_space.o obj/mx_create_node.o obj/mx_del_extra_spaces.o obj/mx_del_strarr.o obj/mx_file_to_str.o obj/mx_foreach.o obj/mx_get_char_index.o obj/mx_get_substr_index.o obj/mx_hex_to_nbr.o obj/mx_isdigit.o obj/mx_islower.o obj/mx_isspace.o obj/mx_isupper.o obj/mx_itoa.o obj/mx_linear_search.o obj/mx_list_size.o obj/mx_memccpy.o obj/mx_memchr.o obj/mx_memcmp.o obj/mx_memcpy.o obj/mx_memmem.o obj/mx_memmove.o obj/mx_memset.o obj/mx_nbr_to_hex.o obj/mx_pop_back.o obj/mx_pop_front.o obj/mx_pop_index.o obj/mx_pow.o obj/mx_print_error.o obj/mx_print_strarr.o obj/mx_printchar.o obj/mx_printint.o obj/mx_printstr.o obj/mx_push_back.o obj/mx_push_front.o obj/mx_push_index.o obj/mx_replace_substr.o obj/mx_sort_list.o obj/mx_sqrt.o obj/mx_str_reverse.o obj/mx_strcat.o obj/mx_strchr.o obj/mx_strcmp.o obj/mx_strcpy.o obj/mx_strdel.o obj/mx_strdup.o obj/mx_strjoin.o obj/mx_strlen.o obj/mx_strncmp.o obj/mx_strncpy.o obj/mx_strndup.o obj/mx_strnew.o obj/mx_strsplit.o obj/mx_strstr.o obj/mx_strtrim.o obj/mx_strtrim_char.o obj/mx_super_atoi.o obj/mx_swap_char.o obj/mx_swap_str.o obj/mx_tolower.o obj/mx_toupper.o

OBJS =  mx_atoi.o mx_binary_search.o mx_bubble_sort.o mx_count_substr.o mx_count_words.o mx_count_words_space.o mx_create_node.o mx_del_extra_spaces.o mx_del_strarr.o mx_file_to_str.o mx_foreach.o mx_get_char_index.o mx_get_substr_index.o mx_hex_to_nbr.o mx_isdigit.o mx_islower.o mx_isspace.o mx_isupper.o mx_itoa.o mx_linear_search.o mx_list_size.o mx_memccpy.o mx_memchr.o mx_memcmp.o mx_memcpy.o mx_memmem.o mx_memmove.o mx_memset.o mx_nbr_to_hex.o mx_pop_back.o mx_pop_front.o mx_pop_index.o mx_pow.o mx_print_error.o mx_print_strarr.o mx_printchar.o mx_printint.o mx_printstr.o mx_push_back.o mx_push_front.o mx_push_index.o mx_replace_substr.o mx_sort_list.o mx_sqrt.o mx_str_reverse.o mx_strcat.o mx_strchr.o mx_strcmp.o mx_strcpy.o mx_strdel.o mx_strdup.o mx_strjoin.o mx_strlen.o mx_strncmp.o mx_strncpy.o mx_strndup.o mx_strnew.o mx_strsplit.o mx_strstr.o mx_strtrim.o mx_strtrim_char.o mx_super_atoi.o mx_swap_char.o mx_swap_str.o mx_tolower.o mx_toupper.o


all: install clean
install:
	@mkdir -p $(OBJ_DIR)
	@cp $(SRC) .
	@cp $(INC) .
	@clang $(CFLAG) -c $(SRCS) -I $(INCS)
	@cp $(OBJS) $(OBJ_DIR)
	@rm -rf $(OBJS)
	@ar -cq $(NAME) $(OBJ)
uninstall: clean
	@rm -rf $(NAME)
clean:
	@rm -rf $(SRCS)
	@rm -rf $(INCS)
	@rm -rf $(OBJ_DIR)
reinstall:
	@rm -rf $(NAME)
	@rm -rf $(LIBS)
	@rm -rf $(SRCS)
	@rm -rf $(INCS)
	@rm -rf $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)
	@cp $(SRC) .
	@cp $(INC) .
	@clang $(CFLAG) -c $(SRCS) -I $(INCS)
	@cp $(OBJS) $(OBJ_DIR)
	@rm -rf $(OBJS)
	@ar -cq $(NAME) $(OBJ)
	@rm -rf $(SRCS)
	@rm -rf $(INCS)
	@rm -rf $(OBJ_DIR)
