# Feature Vector Normalization Performance
This project aims to analyze and compare the performance of two feature vector normalization approaches, implemented using the Newton-Raphson and SSE versions. The goal is to measure execution time and memory usage when normalizing large data vectors, in order to provide insights into the efficiency of each approach across different vector sizes.

The system is modularly structured and was developed in C. Performance analysis is carried out through repeated execution of both algorithms and data collection regarding execution time and memory consumption. The results are exported to a CSV file, and comparative graphs are automatically generated through Python scripts for data visualization.

# Directory and File Description:
- **/data**: Contains data files required for processing, such as `data.csv` used in the performance tests.
- **/report**: Where the results and test graphs are stored, `performance_results.csv` and `performance_graphs`.
- **/resources**: Contains additional resources, such as the Python script for generating graphs from the test results.
- **/src**: Contains the main source code of the project, including the `main.c` file that runs the testing logic.
- **/test**: Auxiliary script to perform tasks called `run_tests.sh`, which automates the tests and collects the results.

# Compilation and Execution Instructions

## Environment Setup

In your Linux environment, execute sequentially:

`sudo apt update`

`sudo apt install build-essential`

`sudo apt install python3 python3-pip`

Confirm the success of the installation with `gcc --version` and `python3 --version`

Then, run the following command to install the Python libraries used to generate the graphs:

`pip install -r ./resources/requirements.txt`

## Compilation

If for any reason the data in data.csv is modified, shows errors, or if you wish to generate the CSV file again, simply run the command:

`python resources/generate_data.py`

A new CSV file named "data" will be generated in the corresponding folder.

To compile the main code, execute the following command:

`gcc -o ./src/main ./src/main.c ./src/read_csv.c ./src/normalize.c ./src/performance.c -lm -msse`

## Execution
To run the tests (which will generate the report file and the graphs), use the following Bash script:

`./test/run_tests.sh`

## Result
The results will be displayed in the terminal and saved in CSV files and PNG graphs (available in /report).
