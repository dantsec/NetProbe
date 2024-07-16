# NetProbe @ C Project 🔍

> NetProbe is a versatile network exploration tool designed to facilitate DNS lookup operations. It allows users to perform DNS queries using specified domain names and wordlists, providing detailed information such as hostnames and IP addresses associated with the queried domains. NetProbe simplifies network investigation tasks by offering clear and concise results through its intuitive interface.

- Key features:
  - Perform DNS lookups for multiple domains using a wordlist;
  - Display detailed information including hostnames and IP addresses;
  - Easy-to-use command-line interface for streamlined operations.

## Authors 👥

- For more information see my blog and my contributions to community.
  - [**@dantsec**](https://www.github.com/dantsec)

## Tech Stack 🧑‍💻

- This project was developed with the following technologies:
  - [**C**](https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html) (Main Language)
  - [**Make**](https://www.gnu.org/software/make/manual/make.html) (Utilitary)

## Documents 📂

- [**MIT License**](./LICENSE)

## Installation / Run Locally ⚙️

- **Important**: First of all, you must have [**C compiler**](https://gcc.gnu.org/) and [**Make utilitary**](https://www.gnu.org/software/make/) installed.

- Clone and enter in the project:
```bash
git clone https://github.com/dantsec/NetProbe.git && cd NetProbe/
```

- Run `Makefile`
```bash
# To compile all.
make all
# To clean all.
make clean
```

## Example of Use 🔎

```sh
# @@ Executing binary @@

# Using default wordlist.
./main google.com.br
# Using personalized wordlist.
./main google.com.br ./wordlists/YOUR_WORDLIST.txt

# @@ Expected Output @@
╔═══════════════════════[ HOST FOUND ]═══════════════════════╗
║ Host : desktop.google.com.br                             ║
║ IP   : 172.217.30.3                                      ║
╚════════════════════════════════════════════════════════════╝
[ ...OBFUSCATED... ]
```

## Contributing 🛠️

```bash
# Create a fork from the original repository and clone it.
git clone https://github.com/YOUR_USERNAME/NetProbe.git
# Enter into the project folder.
cd NetProbe/
# Create a new branch with the name feat-[BRANCH_NAME].
git checkout -b feat-[BRANCH_NAME]
# Make your changes and commit them.
git add . && git commit -m "YOUR_COMMIT_MESSAGE"
# Push your branch and open a pull request.
git push origin feat-[BRANCH_NAME]
```
