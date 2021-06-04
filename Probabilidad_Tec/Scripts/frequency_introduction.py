import matplotlib.pyplot as plt
import pandas as pd
import numpy as np


def obtain_class(min_value, max_value, delta):
    class_values = []
    for value in range(min_value, max_value, delta):
        class_values.append(value)
    return class_values


def frecuency_values(data, class_values, delta):
    frecuency = []
    for value in class_value:
        data_copy = data.copy()
        data_copy = data_copy[data_copy >= value]
        data_copy = data_copy[data_copy <= value+delta-1]
        frecuency.append(data_copy.count()[0])
    return np.array(frecuency)


def plot_histogram(class_list, frecuency, width, path, name, format):
    fig, ax = plt.subplots()
    bars = ax.bar(class_list, frecuency,
                  width=width//2)
    autolabel(bars, format, ax)
    ax.grid(ls="--",
            axis="y",
            color="#000000")
    ax.set_xticks(class_list)
    plt.savefig("{}{}".format(path,
                              name))


def autolabel(rects, format, ax):
    """Attach a text UV_values above each bar in *rects*, displaying its height."""
    for i, rect in enumerate(rects):
        height = rect.get_height()
        ax.annotate(format.format(height),
                    xy=(rect.get_x() + rect.get_width() / 2, height),
                    xytext=(0, 3),  # 3 points vertical offset
                    textcoords="offset points",
                    ha='center',
                    va='bottom',
                    fontsize=9)


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
frecuency = frecuency_values(data, class_value, R_c)
frecuency_relative = 100*frecuency/N
class_value = [value+R_c//2 for value in class_value]
plot_histogram(class_value,
               frecuency,
               R_c,
               "../Graphics/",
               "Histogram_1",
               "{:.0f}")
plot_histogram(class_value,
               frecuency_relative,
               R_c,
               "../Graphics/",
               "Histogram_2",
               "{:.2f}")
