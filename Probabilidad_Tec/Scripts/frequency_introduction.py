import matplotlib.pyplot as plt
import pandas as pd
import numpy as np


def obtain_class(min_value, max_value, delta):
    class_values = []
    for value in range(min_value, max_value, delta):
        class_values.append(value)
    return class_values


def count_values(data, class_values, delta):
    count = []
    for value in class_value:
        data_copy = data.copy()
        data_copy = data_copy[data_copy >= value]
        data_copy = data_copy[data_copy <= value+delta-1]
        count.append(data_copy.count()[0])
    return count


data = pd.DataFrame([138, 146, 168, 146, 161, 164, 158, 126, 173, 144,
                     145, 150, 140, 138, 142, 135, 132, 147, 176, 165,
                     147, 142, 144, 136, 163, 135, 150, 125, 148, 135,
                     119, 153, 156, 149, 152, 154, 140, 145, 157, 128,
                     ])
min_value = data.min()[0]
max_value = data.max()[0]
R = max_value-min_value
N = len(data)
k = int(np.sqrt(N))+1
R_c = int(R/k)+1
print(R, N, k, R_c)
class_value = obtain_class(min_value,
                           max_value,
                           R_c)
count = count_values(data, class_value, R_c)
class_value = [value+R_c//2 for value in class_value]
plt.bar(class_value, count,
        width=R_c//2)
plt.grid(ls="--",
         axis="y",
         color="#000000")
plt.xticks(class_value)
plt.yticks(np.arange(0, 13, 1))
plt.ylim(0, 12)
plt.savefig("../Graphics/Histogram_1.png")
