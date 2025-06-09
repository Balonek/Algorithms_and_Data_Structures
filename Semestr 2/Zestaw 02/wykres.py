import csv
import matplotlib.pyplot as plt
import numpy as np

file = "complexity_results.csv"
data = {}

with open(file, newline='') as csvfile:
    reader = csv.reader(csvfile)
    next(reader)
    for row in reader:
        if len(row) < 3:
            continue
        op_name = row[0]
        n_val = int(row[1])
        time_val = float(row[2])

        if op_name not in data:
            data[op_name] = {"n": [], "time": []}
        data[op_name]["n"].append(n_val)
        data[op_name]["time"].append(time_val)

for op_name, values in data.items():
    pairs = sorted(zip(values["n"], values["time"]), key=lambda x: x[0])
    values["n"], values["time"] = zip(*pairs)
    plt.figure(figsize=(10, 6))
    plt.plot(values["n"], values["time"], marker='o', linestyle='-', color='darkblue', markersize=3, linewidth=1)
    plt.title(f"{op_name} – czas wykonania", fontsize=16)
    plt.xlabel("n", fontsize=14)
    plt.ylabel("czas [ns]", fontsize=14)
    plt.grid(True, linestyle='--', linewidth=0.5, alpha=0.7)
    plt.xticks(fontsize=12)
    plt.yticks(fontsize=12)
    plt.ylim()   
plt.show()
