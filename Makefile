CC=gcc
CFLAGS=-I ./ -Wall -Werror
LDFLAGS=-static

SSD1306_OBJS=ssd1306_main.o ssd1306.o linux_i2c.o
SH1106_OBJS=sh1106_main.o sh1106.o linux_i2c.o

SSD1306_BIN=ssd1306_bin
SH1106_BIN=sh1106_bin

all: $(SSD1306_BIN) $(SH1106_BIN)

default: all

.PHONY: default clean all

# Adapted from scottmcpeak.com/autodepend/autodepend.html
-include $(SSD1306_OBJS:.o=.d) $(SH1106_OBJS:.o=.d)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $*.o
	$(CC) -MM $(CFLAGS) $< > $*.d
	@cp -f $*.d $*.d.tmp
	@sed -e 's/.*://' -e 's/\\$$//' < $*.d.tmp | fmt -1 | \
	  sed -e 's/^ *//' -e 's/$$/:/' >> $*.d
	@rm -f $*.d.tmp

$(SSD1306_BIN): $(SSD1306_OBJS)
	$(CC) $(CFLAGS) -o $@ $(SSD1306_OBJS) $(LDFLAGS)

$(SH1106_BIN): $(SH1106_OBJS)
	$(CC) $(CFLAGS) -o $@ $(SH1106_OBJS) $(LDFLAGS)

clean:
	rm -f *.o *.d $(SSD1306_BIN) $(SH1106_BIN)
