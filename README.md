# Imaginate

Imaginate is a language designed for both image production and the creative process of graphic design. Through the language, you can create in a deterministic way, being able to apply operations such as filters, effects, flavours, etc. It also allows you to create images in a non-deterministic way, that is, to obtain an image as a product of a pool of filters, effects and more, where these will be applied randomly.

## Docker and Building

First, it's necessary to pull the following Docker image, courtesy of the Alejo Flores Lucey group, to whom we thank for sharing this Docker image with everything set up to compile both projects.

```bash
$ docker pull alejofl/tla-compiler
```

To fully build the project, execute the following commands at the repository's root:

```bash
$ chmod u+x --recursive script
$ docker run -v "${PWD}:/root" -ti --rm alejofl/tla-compiler
$ ./script/build.sh
```

This command will open a session in the container where you will be able to run the .sh scripts directly from there.

## Execution

To compile a program, first create an empty file named `program` (or whatever name you prefer), with the following content:
```Imaginate
Imaginate
    .addFocus("./Hola")
    .addContrast()
    .renderAll()
```

Then, run the compiler indicating the path to the start.sh script and passing as a parameter the path to the program to compile:


```bash
root@docker-session:path/ $ ./script/start.sh program
```

You should get the valid return value (0) for that program. If the program's syntax is changed to an incorrect one, the return value will be different from 0.

The result will be Python code that will be able to generate the desired image. To run this code you can do it manually:

```bash
$ python3 generator.py
```
Alternatively, when compiling the Imagine program, you can use the '-x' flag so that this Python code is run automatically:
```bash
root@docker-session:path/ $ ./script/start.sh program -x
```

## Testing

To test the correct functioning of the compiler interpreting the syntax, acceptance and rejection cases are provided in the test directory. To validate this, the chair has provided the following script `./script/test.sh` that will try to compile all acceptance and rejection cases and will show on stdout in which ones it accepted and which ones it rejected.

```bash
root@docker-session:path/ $ ./script/test.sh
```

If you want to add new use cases, you will need to create a file for each one, which contains the program to be tested within the `test/accept` or `test/reject` folders as appropriate (i.e., whether it should be accepted or rejected by the compiler).

## Use Cases

To put the compiler to the test with real use cases, the repository has a directory with basic examples in "./examples" that use images also present in the repository. An example would be:

```bash
root@docker-session:path/ $ ./script/start.sh examples/basic -x
...
root@docker-session:path/ $ ./script/start.sh examples/customMethodAndObjects -x 
...
root@docker-session:path/ $ ./script/start.sh examples/forEachFocus2objects -x
```

> Note the use of the -x flag for automatic image generation.
> Remember to run inside Docker
