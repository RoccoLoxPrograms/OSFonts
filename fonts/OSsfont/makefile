# Put each of your .fnt files on this next line.
# Look at the documentation for convfont for more information on font properties
temp.bin: OSSmallFont.fnt
	convfont -o fontpack -N "OS Small Font" -P "ASCII" -V "Version 1.0" -A "RoccoLox Programs" \
	-D "OS small font to be used in C programs" \
	-f OSSmallFont.fnt -a 1 -b 1 \
	temp.bin
# Don't forget to change font_pack_file_name on both these lines.
# Set PACKNAME to the on-calculator appvar name you want
font_pack_file_name.8xv: temp.bin
	convhex -a -v -n OSsfont temp.bin OSsfont.8xv
all: OSsfont.8xv