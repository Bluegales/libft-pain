# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/05 05:19:11 by pfuchs            #+#    #+#              #
#    Updated: 2022/03/16 01:45:58 by pfuchs           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Libft location
LIBFT	= ../libft/

VPATH = $(dir $(wildcard ./*/)) $(LIBFT)
# Compiler Variables
CC		= gcc
CFLAGSS	= -Wall -Wextra -Werror
INCFLAG = $(addprefix -I ,$(VPATH))

# File Variables
CTYPE			= $(notdir $(wildcard ctype/test_ft_*.c))
STDLIB			= $(notdir $(wildcard stdlib/test_ft_*.c))
OUTPUT			= $(notdir $(wildcard output/test_ft_*.c))
STRING			= $(notdir $(wildcard string/test_ft_*.c))
STRING_ADD		= $(notdir $(wildcard string_add/test_ft_*.c))
MATH			= $(notdir $(wildcard math/test_ft_*.c))
BTEST			= $(notdir $(wildcard btest/*.c))

CTYPE_TESTS		= $(sort $(addsuffix .test,$(basename $(CTYPE))))
STDLIB_TESTS	= $(sort $(addsuffix .test,$(basename $(STDLIB))))
OUTPUT_TESTS	= $(sort $(addsuffix .test,$(basename $(OUTPUT))))
STRING_TESTS	= $(sort $(addsuffix .test,$(basename $(STRING))))
STRING_ADD_TESTS= $(sort $(addsuffix .test,$(basename $(STRING_ADD))))
MATH_TESTS		= $(sort $(addsuffix .test,$(basename $(MATH))))

all:		ctype stdlib output string string_add math extra

ctype:		$(CTYPE_TESTS)

stdlib:		$(STDLIB_TESTS)

output:		$(OUTPUT_TESTS)

string:		$(STRING_TESTS)

string_add:	$(STRING_ADD_TESTS)

math:		$(MATH_TESTS)

extra:
	@echo 'wrongly used "" / <>:'
	@echo "" | grep -r '<libft.h>' $(LIBFT) | cat
	@echo "" | grep -r '"stdlib.h"' $(LIBFT) | cat
	@echo "" | grep -r '"unistd.h"' $(LIBFT) | cat
	@echo "" | grep -r '"string.h"' $(LIBFT) | cat
	@echo "" | grep -r 'stdio' $(LIBFT) | cat
	@echo "files with non static functions:"
	@nm -o $(LIBFT)/libft.a | grep " T " | cut -d ':' -f 2 | uniq -cd

.PHONY: all ctype stdlib output string string_add

# ==============================================================================
# ==============================================================================

%.test :	_bin/%.out
	@printf "\033[1;33m$<:\n\033[0m"
	-@$(debug) $<

.PRECIOUS:	_bin/%.out
_bin/%.out:	_bin/%.o _bin/libbtest.a | _bin
	@$(CC) $(CFLAGSS) $< -L$(LIBFT) -L./_bin -lft -lbtest -o $@

_bin/%.o:	%.c libft.h btest.h | _bin
	@$(CC) -c $(CFLAGSS) $(INCFLAG) $< -o $@

_bin/libbtest.a:	$(addprefix _bin/,$(BTEST:.c=.o)) | _bin
	@ar -rcs $@ $^
	@ranlib $@

_bin:
	@mkdir _bin

clean:
	@rm -rf _bin
	@rm -f no_sources.list
	@rm -f no_test.list

.PHONY: %.test clean
