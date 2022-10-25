LIBFT_PATH = ./libft
FT_PRINTF_PATH = ./ft_printf

all:
	$(error No project specified.)

projects:
	$(info Available projects :)
	$(info libft)

rules:
	$(info libft)
	$(info libft-all)
	$(info libft-clean)
	$(info libft-fclean)
	$(info libft-re)
	$(info libft-bonus)
	$(info libft-everything)

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