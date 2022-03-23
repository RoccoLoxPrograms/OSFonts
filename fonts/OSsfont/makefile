temp.bin: OSSmallFont.fnt
	convfont -o fontpack -N "OS Small Font" -P "ASCII" -V "Version 2.0" -A "RoccoLox Programs" \
	-D "OS small font for FontLibC" \
	-f OSSmallFont.fnt -a 1 -b 1 \
	temp.bin

OSsfont.8xv: temp.bin
	convhex -a -v -n OSsfont temp.bin OSsfont.8xv
all: OSsfont.8xv