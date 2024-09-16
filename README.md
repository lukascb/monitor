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

* https://github.com/lukascb/monitor

### Executing program

* git clone https://github.com/lukascb/monitor
* gcc -g ./monitor.c -lm -o ./monitor
* gcc -g ./leitor.c -lm -o ./leitor
```
Ordem de execução
* Iniciar ./leitor
* Iniciar ./monitor
```

Falhas
```
- Após iniciar a execução das aplicações, remover as permissões de escrita e leitura dos arquivos:
 * data.txt => Torna a aplicação indisponível
 * log.txt => Torna a aplicação indisponível
```

## Authors

Contributors names

ex. Lucas Babeto  

## Version History

* 0.1
    * Initial Release

## License

This project is licensed under the GPL 3.0 License 

## Acknowledgments

Inspiration, code snippets, etc.
* [Code Vault](https://code-vault.net/)
* [Sketchbook](https://github.com/ericomeehan/sketchbook/blob/c_pipes/)
* [TutorialsPoint](https://www.tutorialspoint.com/named-pipe-or-fifo-with-example-c-program)
* [geeksforgeeks](https://www.geeksforgeeks.org/named-pipe-fifo-example-c-program/)
