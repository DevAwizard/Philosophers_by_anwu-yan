NAME = philo

SRC_DIR     := srcs
OBJ_DIR     := obj
INC_DIR     := includes

# Source files
SRCS        := \
			main.c \
			program/0_check_input.c \
			program/1_init_all.c \
			program/2_start_simulation.c \
			program/3_philo_routine.c \
			program/4_philo_actions.c \
			program/5_monitor.c \
			utils/time_utils.c \
			utils/error_message.c \
			utils/check_input_utils.c \
			utils/free_program.c \
			utils/print_utils.c \

# Set the source and object paths
SRCS        := $(SRCS:%=$(SRC_DIR)/%)
OBJS        := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Compiler and flags
CC          := cc
CFLAGS      := -Wall -Wextra -Werror
CPPFLAGS    := -I $(INC_DIR)

#------------------------------------------------#
#   UTENSILS                                     #
#------------------------------------------------#
RM          := rm -f
MAKEFLAGS   += --no-print-directory
DIR_DUP     = mkdir -p $(@D)

#------------------------------------------------#
#   COLORS                                       #
#------------------------------------------------#
RED			= \033[91;1m
GREEN		= \033[92;1m
YELLOW		= \033[93;1m
BLUE		= \033[94;1m
CLEAR		= \033[0m

#------------------------------------------------#
#   RECIPES                                      #
#------------------------------------------------#
all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[35;1mPhilosophers\033[0m"  # Magenta for title
	@echo "\033[96mLinking objects to create $(NAME)...\033[0m"    # Cyan for linking
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[92mCompilation successful: $(NAME) created.\033[0m"  # Green for success

# Rule for compiling source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)  # Create the directory for the object file if it doesn't exist
	@echo "\033[93mCompiling $< into $@\033[0m"  # Yellow for compiling
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	@echo "\033[92mCREATED $@\033[0m"  # Green for created

# Cleaning object files
clean:
	@echo "\033[91mCleaning compiled files.\033[0m"  # Red for cleaning
	$(RM) $(OBJS)

# Full clean, including the binary and the libraries
fclean: clean
	@echo "\033[91mCleaning binary files.\033[0m"  # Red for cleaning binaries
	$(RM) $(NAME)

# Rebuild from scratch
re: fclean all

#------------------------------------------------#
#   SPEC                                         #
#------------------------------------------------#
.PHONY: clean fclean re all
.SILENT: