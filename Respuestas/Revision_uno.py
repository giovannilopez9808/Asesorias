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
valores=np.loadtxt("Examen_Final_antuan.csv",delimiter=",",max_rows=1,skiprows=1,dtype=str)
respuestas=np.loadtxt("Respuestas.csv",dtype=str)
valores=np.delete(valores,0)
bien,mal,no=0,0,0
n=1
file=open("respuestas_antuan.csv","w")
file.write("Número,respondida,correcta")
for valor,respuesta in zip(valores,respuestas):
    valor=valor.strip('""')
    respuesta=respuesta.strip('""')
    if valor==respuesta:
        bien+=1
        print(n,valor,respuesta,"si")
    elif valor=="":
        no+=1
    else: 
        mal+=1
        print(n,valor,respuesta,"no")
    file.write(str(n)+","+valor+","+respuesta)
    n+=1
print(bien,mal,no)
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
plt.savefig("resultados.png")
file.close()