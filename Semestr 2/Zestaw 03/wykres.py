import csv
import matplotlib.pyplot as plt

files = ["resultsA.csv","resultsB.csv"]

data = {}

for fname in files:
    with open(fname, newline='') as csvfile:
        reader = csv.reader(csvfile)
        header = next(reader, None)  
        for row in reader:
            n_val = int(row[0])    
            op_name = row[1]
            time_val = float(row[2])  
            
            if op_name not in data:
                data[op_name] = {"n": [], "time": []}
            data[op_name]["n"].append(n_val)
            data[op_name]["time"].append(time_val)

for op_name, values in data.items():
    pairs = sorted(zip(values["n"], values["time"]), key=lambda x: x[0])
    values["n"], values["time"] = zip(*pairs)  


for op_name, values in data.items():
    plt.figure()
    plt.plot(values["n"], values["time"], marker='o')
    plt.title(op_name)     
    plt.xlabel("n")
    plt.ylabel("czas [ns]")
    plt.grid(True)

plt.show()
