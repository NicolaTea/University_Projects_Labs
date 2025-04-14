import pandas as p
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans


data = p.read_csv("faithful.csv")


data_np = data.to_numpy()


errors = []
k_values = range(1, 11)

for k in k_values:
    kmeans = KMeans(n_clusters=k, random_state=42, n_init=10)
    kmeans.fit(data_np)
    errors.append(kmeans.inertia_)


plt.figure(figsize=(8, 5))
plt.plot(k_values, errors, marker='o', linestyle='-')
plt.xlabel("Numarul de Clustere (k)")
plt.ylabel("Eroarea (Inertia)")
plt.title("Eroarea în functie de k")
plt.grid(True)
plt.show()
