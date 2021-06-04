import matplotlib.pyplot as plt
import numpy as np


def f1(x):
    return np.exp(-x ** 2)


def f2(x):
    return np.exp(-x**2-2*x)


def f3(x):
    return np.exp(-x**2+2*x)


def f4(x):
    return np.exp(x)


def f5(x):
    return np.exp(-x)


def f6(x):
    return np.exp(-x**2+2*x)+np.exp(-x**2-2*x)


def plot_each_distribution(ax, x, y, title):
    ax.set_title(title)
    ax.plot(x, y)
    ax.axis("off")


fig, axs = plt.subplots(ncols=3,
                        nrows=2,
                        figsize=(10, 10))
x = np.arange(-2, 2, 0.001)
y = f1(x)
plot_each_distribution(axs[0][0],
                       x,
                       y,
                       "Simetrica")
y = f2(x)
plot_each_distribution(axs[0][1],
                       x,
                       y,
                       "Sesgo positivo")
y = f3(x)
plot_each_distribution(axs[0][2],
                       x,
                       y,
                       "Sesgo negativo")
y = f4(x)
plot_each_distribution(axs[1][0],
                       x,
                       y,
                       "Exponencial positiva")
y = f5(x)
plot_each_distribution(axs[1][1],
                       x,
                       y,
                       "Exponencial negativa")
y = f6(x)
plot_each_distribution(axs[1][2],
                       x,
                       y,
                       "Bimodal")
plt.savefig("../Graphics/Frecuency_types.png")
