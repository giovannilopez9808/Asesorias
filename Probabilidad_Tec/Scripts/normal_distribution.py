import matplotlib.pyplot as plt
import numpy as np


def normal_distribution(x, mu, sigma):
    m = 1/(sigma*np.sqrt(2*np.pi))
    z = ((x-mu)/sigma)**2
    exp = -z/2
    return m*np.exp(exp)


def plot(ax, x, y1, y2, title):
    ax.axis("off")
    ax.plot(x, y1)
    ax.plot(x, y2)
    ax.set_title(title)


fig, axs = plt.subplots(ncols=2,
                        figsize=(10, 4))
x = np.linspace(-2, 2, 1000)
y1 = normal_distribution(x, -0.5, 0.2)
y2 = normal_distribution(x, 0.5, 0.2)
plot(axs[0],
     x,
     y1,
     y2,
     "$ \\mu_1 > \\mu_2 $"+"\n"+"$ \\sigma_1= \\sigma_2 $")
y1 = normal_distribution(x, 0, 0.2)
y2 = normal_distribution(x, 0, 0.4)
plot(axs[1],
     x,
     y1,
     y2,
     "$ \\mu_1 = \\mu_2 $"+"\n"+"$ \\sigma_1> \\sigma_2 $")
plt.savefig("../Graphics/Normal_distribution.png")
