import pandas as pd
import matplotlib.pyplot as plt

raw=pd.read_csv("Regression_BSD_hour.csv")

#with open("Regression_BSD_Readme.txt","r") as readme:
#    print(readme.read())

#print(raw)

#print(raw.columns)

#Split the data into training and test data

all_days=len(raw)//24
print("Total observations",len(raw))
print("Total number of days",all_days)

days_for_training=int(all_days*0.7)  #70% train 30% test
hours_for_training=days_for_training*24

X_train=raw[0:hours_for_training]
X_test=raw[hours_for_training:]

y_train=X_train['cnt']
y_test=X_test['cnt']

print("Observations for training", X_train.shape)
print("Observations for testing", X_test.shape)

#Visualise the data

#first_day=3*7 ->  începe graficul de la ziua 21 (3 săptămâni).
# duration_days=3*7 -> desenăm datele pentru 3 săptămâni.

def plot_data(X,y,first_day=3*7,duration_days=3*7):
    s=first_day*24 #start hour
    e=s+duration_days*24 #end hour

#ax0 ->  variabilele de intrare
#ax1 -> numarul de biciclete inchiriate

    fig,(ax0,ax1)=plt.subplots(2,1,figsize=(18,10),sharex=True)

    # fill the background of the working days
    for x, v in X['workingday'][s:e].items():
        if v == 1:
            ax0.axvline(x, lw=3, c='lightgrey')
            ax1.axvline(x, lw=3, c='lightgrey')

    mid_day_indexes = []
    # drawing lines between the days
    for x, v in X['hr'][s:e].items():
        if v == 0:
            ax0.axvline(x, ls=':', c='grey')
            ax1.axvline(x, ls=':', c='grey')
        if v == 12:
            mid_day_indexes.append(x)

    for c in [
        'temp', 'hum', 'windspeed', 'weathersit',
        # 'atemp', 'season', 'workingday', 'instant', 'dteday', 'weekday',
        # 'yr', 'mnth', 'hr', 'holiday', 'casual', 'registered',  'cnt'
    ]: ax0.plot(X[c][s:e], label=c)

    ax0.legend(loc="upper left")
    ax0.set_ylabel('Input variables')

    ax1.plot(y[s:e], 'r:', label="ground truth")
    ax1.legend(loc="upper left")
    ax1.set_ylabel('Number of Rentals per hour')

    ax1.set_xticks(mid_day_indexes)
    ax1.xaxis.set_ticklabels([X['dteday'][i] for i in mid_day_indexes], rotation=90)

    plt.tight_layout()
    # plt.savefig('plot.pdf')
    plt.show()


plot_data(X_train, y_train)