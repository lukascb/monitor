# Monitoramento de Processo

A aplicação consiste em dois executáveis: monitoramento e leitura.
- monitoramento: Monitora a execução do processo leitura e reinicia esse processo caso ele finalize.
- leitua: Monitora o conteúdo do arquivo: data.txt. Se data.txt indicar o conteúdo "continuar" ele mantem sua execução mas se data.txt indicar o conteúdo "finalizar" ele encerra sua execução.

## Description

A aplicação consiste em dois executáveis: monitoramento e leitura.
- monitoramento: Monitora a execução do processo leitura e reinicia esse processo caso ele finalize.
- monitoramento: A cada 7 segundos essa aplicação escreve no arquivo data.txt o conteúdo "finalizar".
- monitoramento: Assim que essa aplicação identifica que data.txt apresenta o conteúdo "finalizar", executa o processo ./leitura novamente.
- leitua: Monitora o conteúdo do arquivo: data.txt. Se data.txt indicar o conteúdo "continuar" ele mantem sua execução mas se data.txt indicar o conteúdo "finalizar" a aplicação escreve em data.txt o conteúdo "finalizado" indicando que vai encerrar sua execução.

## Getting Started

### Dependencies

* Linux (Baseados em Debian, testado na versão Debian 6.1.106-3 (2024-08-26) x86_64 GNU/Linux)
* Bibliotecas: dpkg-dev, g++, gcc, libc6-dev, libc6.1-dev, make, build-essentials


### Installing

* How/where to download your program
* Any modifications needed to be made to files/folders

### Executing program

* How to run the program
* Step-by-step bullets
```
code blocks for commands
```

## Help

Any advise for common problems or issues.
```
command to run if program contains helper info
```

## Authors

Contributors names and contact info

ex. Dominique Pizzie  
ex. [@DomPizzie](https://twitter.com/dompizzie)

## Version History

* 0.2
    * Various bug fixes and optimizations
    * See [commit change]() or See [release history]()
* 0.1
    * Initial Release

## License

This project is licensed under the [NAME HERE] License - see the LICENSE.md file for details

## Acknowledgments

Inspiration, code snippets, etc.
* [awesome-readme](https://github.com/matiassingers/awesome-readme)
* [PurpleBooth](https://gist.github.com/PurpleBooth/109311bb0361f32d87a2)
* [dbader](https://github.com/dbader/readme-template)
* [zenorocha](https://gist.github.com/zenorocha/4526327)
* [fvcproductions](https://gist.github.com/fvcproductions/1bfc2d4aecb01a834b46)
