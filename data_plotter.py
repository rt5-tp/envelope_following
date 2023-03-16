import matplotlib.pyplot as plt

input = []
out = []

with open('Input.txt', 'r') as in_file:
	input = [float(val) for val in in_file]

with open('Envelope.txt', 'r') as out_file:
	out = [float(val) for val in out_file]

# print(out)

fig, axs = plt.subplots(2)
axs[0].plot(input)
axs[0].set_title("Input Audio")
axs[1].plot(out)
axs[1].set_title("Envelope")

fig.tight_layout()

plt.show()
plt.savefig("EnvelopeFollower.svg")


