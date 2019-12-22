shell:pathing encryption decryption makegen
	gcc -o shell Shell_loop.c
	./shell

encryption:
	gcc -o ./C_files/encryption/encryption ./C_files/encryption/Encryption.c
	
decryption:
	gcc -o ./C_files/encryption/decryption ./C_files/encryption/Decryption.c
	
makegen:
	gcc -o ./C_files/Makecreator/makegen ./C_files/Makecreator/makeFile_gen.c
	
pathing:
	 bash pathchanger.sh
	 $(eval export MYPATH=$(shell pwd))
	 @echo ${MYPATH}
	
clean:
	rm -r ./C_files/Makecreator/makegen ./C_files/encryption/decryption ./C_files/encryption/encryption ./shell
	
