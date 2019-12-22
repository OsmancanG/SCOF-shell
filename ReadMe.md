# SCOF Shell
This Project is a shell program that capable to run hardly coded process in a loop.  These Process are usually for file system and based on text or C files in a system. In these codes you can find process that encrypt a text to generating make files for your favorite C files.

## Getting Started
### *Installing Git Files*
First you need to download all files inside of SCOF shell file from github 
if you already have files you can skip next part (*Setting Files*) .

First you should install Github:
```shell
$ sudo apt-get install git
```
After installing github you can clone repository like this:
```shell
$ git clone https://github.com/YOUR-USERNAME/YOUR-REPOSITORY
```
If you have output done well everything is done.

### *Setting files*
Setting all the files in the SCOF shell project is easy:
```shell
$ cd scof_shell
$ make
```
After some output later you can execute shell with :
```shell
$ ./scof_shell
```
after that 
Welcome to SCOF shell


## Functions
 - **MakeGen**:
 Makegen is function that able to generate makefile for C files and headers. For success process all  C and Header files should be on the same path since this function just can process on current path, you should change directory.
 ```shell
$ makegen  
  ```
  - **Encryption and Decryption**:
  Security is really import for your file so we present you a function that encrypt and decrypt a file. For encrypt we choose to shift all char numbers to space and keep the key in the another file for decryption.
```shell
\\For encryption 
$ crypto -enc hello.txt encryptedfile.txt 
\\For decryption
$ crypto -dec encryptedfile.txt key.txt decrypted.txt
```
 - **File System GUI**:
	This GUI provides you basic operations for get information about directory and files like .txt i.e. Also you can add directory and file. 
 ```bash
$ filesys
 ```
using this GUI is really easy GUI  when its open its output will be like this:
```bash
********************************
---------------------------------
|FinalProject
|		a.txt: 43 bytes
|		C_files: d* 48586 bytes
|		scripts: d* 6182 bytes
|		shell: 13400 bytes
|		shell_loop.c:4353 bytes
|Total size: 72564 bytes
----------------------------------
Type help to see functions.
```
In this GUI you can see size of files and directory and by typing name of direction or file you can change path or get information about that file. For additional operation you can use fcreate which create a file and dcreate which create a directory. Usage of both functions are in below:

```bash
fcreate mytextfile.txt 
dcreate mydirectory
```

- **Histed**:

Histed is a function that able to move, copy or remove files that older then you want. Usage of this is easy:

 ```bash 
 histed -d 10 mv
 histed -m 3 cp
 histed -y 1 rm
```
You can use 3 time options and 3 command option. For time option you can choose:
-d : for a day
-m : for a month
-y: for a year
Also you have command option:
mv for moving the files
cp for copying the files
rm for removing the files (use as of your risk)
(Our project will not take any responsibilities for removed files it works just in one direction and it doesn't remove recursively.)

- **other functions**:
For more help you can use
```
> man [function]
> help
```

  ## Collaborators
  
  * **Feyza Türker** - *Report, Encryption, Decryption* - [FeyzaTürker](https://www.linkedin.com/in/feyza-t%C3%BCrker-547a20153/):
  * **Oğuz Baykut** - *File System GUI, OldEdit , Github* - [OğuzBaykut](https://www.linkedin.com/in/o%C4%9Fuz-baykut-1746b014a/):
* **Osman Can Güdül** - *MakeFile generator, ReadMe File , Shell Loop* - [OsmanCanGüdül](https://www.linkedin.com/in/osman-can-g%C3%BCd%C3%BCl-989963169/):
  ## Others
  