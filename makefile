# ----------------------------
# Makefile Options
# ----------------------------

NAME = OSFONTS
ICON = 
DESCRIPTION = "OS Font Test"
COMPRESSED = YES
ARCHIVED = YES

CFLAGS = -Wall -Wextra -Oz
CXXFLAGS = -Wall -Wextra -Oz

# ----------------------------

include $(shell cedev-config --makefile)
