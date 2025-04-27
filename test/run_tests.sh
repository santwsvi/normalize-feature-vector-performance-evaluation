#!/bin/bash

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

calculate_average() {
    local arr=("$@")
    local min=${arr[0]}
    local max=${arr[0]}
    local sum=0
    local count=${#arr[@]}

    for num in "${arr[@]}"; do
        if (( $(echo "$num < $min" | bc -l) )); then
            min=$num
        fi
        if (( $(echo "$num > $max" | bc -l) )); then
            max=$num
        fi
        sum=$(echo "$sum + $num" | bc -l)
    done

    sum=$(echo "$sum - $min - $max" | bc -l)
    average=$(echo "$sum / ($count - 2)" | bc -l)

    echo "$average"
}

FILE="../data/data.csv"
VECTOR_SIZES=("10000" "100000" "1000000" "10000000")
OUTPUT_CSV="../report/performance_results.csv"

echo "Tamanho do Vetor, Média Newton-Raphson, Média SSE, Média Memória Newton-Raphson (KB), Média Memória SSE (KB)" > $OUTPUT_CSV

for SIZE in "${VECTOR_SIZES[@]}"; do
    echo "Testando com vetor de tamanho $SIZE"
    
    time_newton=()
    time_sse=()
    memory_newton=()
    memory_sse=()
    
    for i in {1..5}; do
        echo "Execução #$i"

        echo "Versão Newton-Raphson"
        output=$(../src/main $FILE $SIZE "newton")  # Use SIZE em vez de VECTOR_SIZE
        time_newton_value=$(echo "$output" | grep -oP "Tempo de execução: \K[0-9.]+")
        memory_newton_value=$(echo "$output" | grep -oP "Uso de memória: \K[0-9]+")
        time_newton+=($time_newton_value)
        memory_newton+=($memory_newton_value)

        echo "Versão SSE"
        output=$(../src/main $FILE $SIZE "sse")
        time_sse_value=$(echo "$output" | grep -oP "Tempo de execução: \K[0-9.]+")
        memory_sse_value=$(echo "$output" | grep -oP "Uso de memória: \K[0-9]+")
        time_sse+=($time_sse_value)
        memory_sse+=($memory_sse_value)
    done

    avg_time_newton=$(calculate_average "${time_newton[@]}")
    avg_time_sse=$(calculate_average "${time_sse[@]}")
    avg_memory_newton=$(calculate_average "${memory_newton[@]}")
    avg_memory_sse=$(calculate_average "${memory_sse[@]}")

    avg_time_newton=$(printf "%.7f" "$avg_time_newton")
    avg_time_sse=$(printf "%.7f" "$avg_time_sse")

    echo "Média - Versão Newton-Raphson: $avg_time_newton segundos, Memória: $avg_memory_newton KB"
    echo "Média - Versão SSE: $avg_time_sse segundos, Memória: $avg_memory_sse KB"

    echo "$SIZE,$avg_time_newton,$avg_time_sse,$avg_memory_newton,$avg_memory_sse" >> $OUTPUT_CSV
done

echo "Gerando gráficos..."
python3 ../resources/generate_graphs.py $OUTPUT_CSV
