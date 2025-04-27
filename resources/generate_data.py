import csv
import random
import math

def generate_satellite_data(filename, num_satellites):
    with open(filename, mode='w', newline='') as file:
        writer = csv.writer(file)
        for _ in range(num_satellites):
            radius = 6371 + 500 

            theta = random.uniform(0, 2 * math.pi)
            phi = random.uniform(0, math.pi)
            
            x = radius * math.sin(phi) * math.cos(theta)
            y = radius * math.sin(phi) * math.sin(theta)
            z = radius * math.cos(phi)

            writer.writerow([f"{x:.3f}", f"{y:.3f}", f"{z:.3f}"])

generate_satellite_data('data/data.csv', 10000000)
