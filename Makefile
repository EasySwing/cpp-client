
gpp-compile:
	g++ main.cpp -lcurl -o gpp-easyswing

gcc-compile:
	gcc main.cpp -lcurl -o gcc-easyswing -lstdc++

run:
	./easywing
