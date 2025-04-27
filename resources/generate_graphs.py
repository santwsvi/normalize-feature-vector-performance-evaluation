import sys
import pandas as pd
import matplotlib.pyplot as plt
import os

def generate_graphs(input_csv):
    data = pd.read_csv(input_csv)
    
    data.columns = data.columns.str.strip()

    print(data.columns)
    
    plt.figure(figsize=(10, 6))
    
    plt.plot(data["Tamanho do Vetor"], data["Média Newton-Raphson"], label="Newton-Raphson", marker='o')
    
    plt.plot(data["Tamanho do Vetor"], data["Média SSE"], label="SSE", marker='x')
    
    plt.title('Desempenho de Normalização - Tempo (Newton-Raphson vs SSE)')
    plt.xlabel('Tamanho do Vetor')
    plt.ylabel('Tempo de Execução (segundos)')
    
    plt.xscale('log') 
    plt.yscale('log')  
    
    plt.legend()
    plt.grid(True)
    
    output_dir = os.path.join(os.path.dirname(__file__), '../report')

    if not os.path.exists(output_dir):
        os.makedirs(output_dir)
    
    plt.savefig(os.path.join(output_dir, 'performance_graph_time.png'))
    
    plt.show()

    plt.figure(figsize=(10, 6))
    
    plt.plot(data["Tamanho do Vetor"], data["Média Memória Newton-Raphson (KB)"], label="Newton-Raphson", marker='o')
    
    plt.plot(data["Tamanho do Vetor"], data["Média Memória SSE (KB)"], label="SSE", marker='x')
    
    plt.title('Desempenho de Normalização - Uso de Memória (Newton-Raphson vs SSE)')
    plt.xlabel('Tamanho do Vetor')
    plt.ylabel('Uso de Memória (KB)')
    
    plt.xscale('log') 
    plt.yscale('log')  
    
    plt.legend()
    plt.grid(True)
    
    plt.savefig(os.path.join(output_dir, 'performance_graph_memory.png'))
    
    plt.show()

if __name__ == '__main__':
    if len(sys.argv) != 2:
        print("Aviso: Nenhum arquivo CSV foi fornecido. Por favor, forneça o caminho para o arquivo CSV como argumento.")
        sys.exit(0) 
    else:
        input_csv = sys.argv[1]
        generate_graphs(input_csv)
