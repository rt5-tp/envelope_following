import matplotlib.pyplot as plt

input = []
out = []

with open('Input.txt', 'r') as in_file:
	input = [float(val) for val in in_file]

with open('10HzEnvelope.txt', 'r') as out_file:
	out_10 = [float(val) for val in out_file]
	
with open('20HzEnvelope.txt', 'r') as out_file:
	out_20 = [float(val) for val in out_file]

# print(out)

fig, axs = plt.subplots(3)
axs[0].plot(input)
axs[0].set_title("Input Audio")
axs[1].plot(out_20)
axs[1].set_title("20Hz Filter")
axs[2].plot(out_10)
axs[2].set_title("10Hz Filter")

fig.tight_layout()

plt.savefig("filter_comparison.svg")


