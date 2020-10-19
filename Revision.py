import numpy as np
import matplotlib.pyplot as plt
def autolabel(rects):
    for rect in rects:
        height =round(rect.get_height(),2)
        plt.annotate('{}'.format(height),
                    xy=(rect.get_x() + rect.get_width() / 2, height),
                    xytext=(0,3),  # 3 points vertical offset
                    textcoords="offset points",
                    ha='center', va='bottom',)
valores=np.loadtxt("Examen_Final.csv",delimiter=",",max_rows=1,skiprows=1,dtype=str)
respuestas=np.loadtxt("Respuestas.csv",dtype=str)
valores=np.delete(valores,0)
bien,mal,no,n=0,0,0,1
for valor,respuesta in zip(valores,respuestas):
    valor=valor.strip('""')
    respuesta=respuesta.strip('""')
    if valor==respuesta:
        bien+=1
        print(n,valor,respuesta,"bien")
    elif valor=="":
        no+=1
        print(n,valor,respuesta,"no")
    else: 
        mal+=1
        print(n,valor,respuesta,"mal")
    n+=1
titles=["Bien","Mal","No contestadas"]
bar=plt.bar(titles,[bien,mal,no])
bar[0].set_color("#023e8a")
bar[1].set_color("#6a040f")
bar[2].set_color("#faa307")
autolabel(bar)
plt.xlim(-0.5,2.5)
plt.ylim(0,30)
plt.yticks(np.arange(0,33,3))
for y in range(0,33,3):
    plt.plot([-0.5,2.5],[y,y],ls="--",color="grey",alpha=0.7)
plt.ylabel("Número de preguntas")
plt.xlabel("Tipo de respuesta")
plt.show()