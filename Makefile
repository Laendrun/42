LIBFT_PATH = ./libft
PRINTF_PATH = ./ft_printf

all:
	$(error No project specified.)

projects:
	$(info Available projects :)
	$(info libft)
	$(info ft_printf (in progress))

rules:
	$(info libft)
	$(info libft-all)
	$(info libft-clean)
	$(info libft-fclean)
	$(info libft-re)
	$(info libft-bonus)
	$(info libft-everything)
	$(info printf)
	$(info printf-all)
	$(info printf-clean)
	$(info printf-fclean)
	$(info printf-re)
	$(info printf-bonus)
	$(info printf-everything)

# LIBFT

libft: libft-all

libft-all:
	@ cd $(LIBFT_PATH) && $(MAKE);

libft-clean:
	@ cd $(LIBFT_PATH) && $(MAKE) clean;

libft-fclean:
	@ cd $(LIBFT_PATH) && $(MAKE) fclean

libft-re:
	@ cd $(LIBFT_PATH) && $(MAKE) re

libft-bonus:
	@ cd $(LIBFT_PATH) && $(MAKE) bonus

libft-everything:
	@ cd $(LIBFT_PATH) && $(MAKE) everything

# FT_PRINTF

printf: printf-all

printf-all:
	@ cd $(PRINTF_PATH) && $(MAKE);

printf-clean:
	@ cd $(PRINTF_PATH) && $(MAKE) clean;

printf-fclean:
	@ cd $(PRINTF_PATH) && $(MAKE) fclean

printf-re:
	@ cd $(PRINTF_PATH) && $(MAKE) re

printf-bonus:
	@ cd $(PRINTF_PATH) && $(MAKE) bonus

printf-everything:
	@ cd $(PRINTF_PATH) && $(MAKE) everything