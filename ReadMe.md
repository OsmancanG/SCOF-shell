# SCOF Shell
This Project is a shell program that capable to run hardly coded process in a loop.  These processes are usually used for file system and based on text or C files in a system. In these codes you can find processes from encrypting a text file to generating make files for your favorite C files.

## Getting Started
### *Installing Git Files*
First you need to download all files inside of SCOF shell file from github 
if you already have files you can skip next part (*Setting Files*) .

First you should install Github:
```shell
$ sudo apt-get install git
```
After installing github you can clone the repository like this:
```shell
$ git clone https://github.com/osmancan98/SCOF-shell.git
```
If you have output done well everything is fine.

### *Setting files*
Setting all the files in the SCOF shell project is easy:
```shell
$ cd scof_shell
$ make
```
It launches itself after make process you can use:
```shell
$ ./shell
```
Welcome to SCOF shell


## Functions
 - **MakeGen**:
 Makegen is a function that ables to generate makefile for C files and headers. To obtain a successful process, all C and Header files have to be on the same path since this function just can process on current path. Otherwise, you should change the directory.
 ```shell
$ makegen  
  ```
  - **Encryption and Decryption**:
  Security is really important for your files, so we present to you a function that encrypts and decrypts a file. Encryption is a shifting process in ASCII representation of all characters. The shifted version is a key file that is used for decryption. Therewithal, decryption is used to obtain the original file from the key file.
```shell
\\For encryption 
$ crypto -enc hello.txt encryptedfile.txt 
\\For decryption
$ crypto -dec key.txt encryptedfile.txt decrypted.txt
```
 - **File System GUI**:
	This GUI provides you basic operations for getting an information about directories and files like .txt, .c etc. Also, you can add a directory or a file. 
 ```bash
$ filesys
 ```
using this GUI is really easy. When it opens, its output will be like:
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
In this GUI you can see the size of files and directories. By typing the name of the direction, you can change the path. Likewise, you can get an information about a file with typing its name. For additional operations, you can use "fcreate" to create a file and "dcreate" to create a directory. Usage of both functions are in below:

```bash
fcreate mytextfile.txt 
dcreate mydirectory
```

- **Histed**:

Histed is a function that ables to move, copy or remove files that is older then you want. Usage of the function is easy:

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
  
