FILE=$1


clang++ \
	$FILE -o "$FILE.out" \
	-I/Library/Frameworks/SDL2.framework/Headers \
	-F/Library/Frameworks \
	-framework SDL2 \
	-framework Cocoa \
	-Wall

