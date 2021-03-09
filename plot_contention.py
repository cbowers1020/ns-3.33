#!/usr/bin/env python3
from matplotlib import pyplot as plt
import seaborn as sns
import pandas as pd

# CSV file
csv_file = 'contention.csv'
# read cvs with pandas read_csv
df = pd.read_csv(csv_file)
sns.lineplot(data=df,x="tx_rate_kbps",y="mac_tx_drops", hue="node")
plt.savefig("mac_tx_drops.png")
plt.close()
sns.lineplot(data=df,x="tx_rate_kbps",y="phy_rx_drops", hue="node")
plt.savefig("phy_rx_drops.png")