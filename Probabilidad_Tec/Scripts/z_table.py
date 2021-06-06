import matplotlib.pyplot as plt
import numpy as np


def normal_distribution(z):
    return np.exp(-z**2/2)


def plot(x, y, a, b, name):
    ticks, labels = obatin_tick()
    plt.xticks(ticks, labels)
    plt.plot(x, y)
    plot_area(a, b)
    plt.ylim(0)
    plt.xlim(-3, 3)
    plt.savefig("{}{}.png".format("../Graphics/",
                                  name))
    plt.clf()


def plot_area(a, b):
    x = np.linspace(a, b, 100)
    y = normal_distribution(x)
    plt.fill_between(x, y)


def obatin_tick():
    ticks = np.arange(-3, 4)
    labels = [str(tick)+"$\\sigma$" for tick in ticks]
    return ticks, labels


z = np.linspace(-4, 4, 1000)
f = normal_distribution(z)
plot(z, f, 0, 1.2, "ejemplo_1")
plot(z, f, -0.68, 0, "ejemplo_2")
plot(z, f, -0.46, 2.21, "ejemplo_3")
plot(z, f, 0.81, 1.94, "ejemplo_4")
plot(z, f, -4, -0.6, "ejemplo_5")
plot(z, f, -0.128, 4, "ejemplo_6")
