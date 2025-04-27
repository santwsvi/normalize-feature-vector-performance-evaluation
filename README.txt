# Desempenho de Normalização de Vetores de Características
Este projeto visa analisar e comparar o desempenho de duas abordagens de normalização de vetores de características, implementadas nas versões Newton-Raphson e SSE. O objetivo é medir o tempo de execução e o uso de memória ao normalizar grandes vetores de dados, a fim de fornecer insights sobre a eficiência de cada abordagem em diferentes tamanhos de vetores.

O sistema é estruturado de forma modular e foi desenvolvido em C, a análise de desempenho é feita por meio de execução repetida de ambos os algoritmos e coleta de dados sobre o tempo de execução e consumo de memória. Os resultados são exportados para um arquivo CSV, e gráficos comparativos são gerados automaticamente através de scripts Python para visualização dos dados.

# Descrição dos Diretórios e Arquivos:
- **/data**: Contém arquivos de dados necessários para o processamento, como o `data.csv` usado nos testes de desempenho.
- **/report**: Onde são armazenados os resultados e gráficos dos testes, `performance_results.csv` e `performance_graphs`.
- **/resources**: Contém recursos adicionais, como o script Python para geração de gráficos a partir dos resultados dos testes.
- **/src**: Contém o código fonte principal do projeto, com o arquivo `main.c` que executa a lógica de teste.
- **/test**: Script auxiliar para executar tarefas denominado `run_tests.sh`, que automatiza os testes e coleta os resultados.

# Instruções de Compilação e Execução

## Preparação do ambiente

No seu ambiente Linux, execute, de forma sequencial:

`sudo apt update`

`sudo apt install build-essential`

`sudo apt install python3 python3-pip`

Confirme o sucesso da instalação com `gcc --version` e `python3 --version`

Em seguida, execute o comando a seguir para instalar as bibliotecas do Python utilizadas para gerar os gráficos.

`pip install -r ./resources/requirements.txt`

## Compilação

Caso, por algum motivo, os dados em data.csv sejam modificados, apresentem erros, ou se deseje gerar novamente o arquivo csv, basta executar o comando:

`python resources/generate_data.py`.

Um novo arquivo csv com de nome "data" será gerado na pasta homônima.

Para compilar o código principal, execute o seguinte comando:

`gcc -o ./src/main ./src/main.c ./src/read_csv.c ./src/normalize.c ./src/performance.c -lm -msse`

## Execução
Para rodar os testes (que gerarão o arquivo de report e os gráficos), utilize o seguinte script bash:

 `./test/run_tests.sh`

## Resultado
Os resultados serão exibidos no terminal e gravados em arquivos CSV e gráfico PNG (disponíveis em /report).
