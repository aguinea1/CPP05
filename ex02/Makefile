################################################################################
#                              CONFIGURATION                                   #
################################################################################

NAME			=  𝟮𝟴𝗕
CC				= c++
CFLAGS 			= -Wall -Wextra -Werror -Wno-shadow -std=c++98 -MMD -fsanitize=address
DEPFLAGS		= -MMD -MF $(DEPDIR)/$*.d

SRCDIR			= src
OBJDIR			= obj
DEPDIR			= deps

################################################################################
#                              SOURCE FILES                                    #
################################################################################

SRCS =	main_pardon.cpp						\
		Bureaucrat.cpp						\
		AForm.cpp							\
		ShrubberyCreationForm.cpp			\
		RobotomyRequestForm.cpp				\
		PresidentialPardonForm.cpp

HEADERS =	Bureaucrat.hpp					\
			AForm.hpp						\
			ShrubberyCreationForm.hpp		\
			RobotomyRequestForm.hpp			\
			PresidentialPardonForm.hpp


################################################################################
#                             OBJECTS & DEPS                                   #
################################################################################

OBJS			= $(SRCS:%.cpp=$(OBJDIR)/%.o)
DEPS			= $(OBJS:%.o=$(DEPDIR)/%.d)

################################################################################
#                              RULES                                           #
################################################################################

all: dir $(NAME)

$(NAME): Makefile $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $@
	@echo "\033[1;32m ➜ ➜ CPP05 EX02 [✔]\033[0m"


$(OBJDIR)/%.o: %.cpp $(HEADERS)
	@mkdir -p $(dir $@) $(dir $(DEPDIR)/$*.d)
	@$(CC) $(CFLAGS) $(DEPFLAGS) $(INCLUDE) -c $< -o $@

dir:
	@mkdir -p $(OBJDIR) $(DEPDIR)

clean:
	@rm -rf $(OBJDIR) $(DEPDIR)
	@echo "\033[1;32m ♻ CHAUUU ♻\033[0m"

fclean: clean
	@rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re dir
