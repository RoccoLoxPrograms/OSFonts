temp.bin: OSLargeFont.fnt
	convfont -o fontpack -N "OS Large Font" -P "ASCII" -V "Version 1.1" -A "RoccoLox Programs" \
	-D "OS large font for FontLibC" \
	-f OSLargeFont.fnt -a 1 -b 1 \
	temp.bin

OSLFONT.8xv: temp.bin
	convhex -a -v -n OSLFONT temp.bin OSLFONT.8xv
all: OSLFONT.8xv