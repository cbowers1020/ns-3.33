import csv

lost_packets = 0

with open("traffic_study_per_flow_stats.csv", "r") as fn:
	file_read = csv.reader(fn, delimiter=',')
	line = 1
	for row in file_read:
		if(line == 1):
			line += 1
			continue
		else:
			# print(row)
			lost_packets += int(row[-1])
			line += 1

print(lost_packets)
