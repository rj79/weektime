SOURCES = $(shell find . \( -name '*.h' -o -name '*.cpp' \) | grep -v .pio)

all: test

test: $(SOURCES)
	pio test
