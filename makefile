NAME := miniRT

# 색상 정의
ORIGIN := \033[0m
BLUE := \033[0;34m # 잘 안보이는..?
GREEN = \033[0;32m

CC := cc
CFLAGS := -Wall -Wextra -Werror -I include -I lib/minilibx-linux -MMD -MP
LIBMLX_DIR := lib/minilibx-linux
# MLX_LIB, LIBMLX_DIR 순서가 바뀌면 빌드 안된다. 특히, := 사용 때문.
# 재료(경로) 먼저 준비하고 요리(결합 변수)
MLX_LIB := $(LIBMLX_DIR)/libmlx_Linux.a
LIBS := -L$(LIBMLX_DIR) -lmlx_Linux -lX11 -lXext -lm # lm은 가장 마지막. 
# 링커는 왼쪽에서 오른쪽 방향으로 읽어감. 이 라이브러리는 고수준->저수준 순으로 추천
# 고수준(내가 만든) -> 저수준(시스템 표준)

# TODO: VPATH 세팅         VPATH:= src:src/디렉토리명:src/ ...
# 고민: 명시적인 것이 암시적인 것보다 낫다.. 라고 해서, 조금 고민해봐야 할 듯.
# 우선은 VPATH없이 진행
# 그전에 디렉토리 분류: print,scene,trace,utils ..?

SRC_DIR := src
OBJ_DIR := obj

SRCS_NAME := main.c \
			core/init.c \
			core/events.c \
			core/clean_exit.c \
			core/render.c \
			

SRCS := $(addprefix $(SRC_DIR)/, $(SRCS_NAME))
OBJS := $(addprefix $(OBJ_DIR)/, $(SRCS_NAME:.c=.o))
DEPS := $(OBJS:.o=.d)

all: $(NAME)

# 링킹 단계에도 CFLAGS를 포함하는 게 관례라고 함. -> 그동안 여기는 안 썼어서..
$(NAME): $(MLX_LIB) $(OBJ) 
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled successfully!$(RESET)"

$(MLX_LIB):
	@printf "$(BLUE)Checking MLX library...$(ORIGIN)\n"
	@$(MAKE) -C $(LIBMLX_DIR) --no-print-directory -s
	@printf "$(BLUE)MLX ready.$(ORIGIN)\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBMLX_DIR) clean
	@echo "$(GREEN) $(NAME) executable removed.$(RESET)"

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re
