# ----------------------------
# Makefile Options
# ----------------------------

NAME ?= OSFONTS
ICON ?= 
DESCRIPTION ?= "OS Font Test"
COMPRESSED ?= YES
ARCHIVED ?= YES

CFLAGS ?= -Wall -Wextra -Oz
CXXFLAGS ?= -Wall -Wextra -Oz

# ----------------------------

ifndef CEDEV
$(error CEDEV environment path variable is not set)
endif

include $(CEDEV)/meta/makefile.mk