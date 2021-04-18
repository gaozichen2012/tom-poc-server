SERVER_TARGETS = tompoc

LDFLAGS = -pthread

SERVER_SRC_FILES = server_main.c tcp_service.c state.c state_init.c \
				state_work.c state_setting.c

SERVER_COMPILER = gcc

.PHPNY: all
all: $(SERVER_TARGETS)

# 嵌入式下的client需要再交叉编译工具下编译；ubuntu系统中用gcc
$(SERVER_TARGETS): 
	$(SERVER_COMPILER) $(LDFLAGS) $(SERVER_SRC_FILES) -o $@

clean:
	rm -rf $(SERVER_TARGETS) *.o
