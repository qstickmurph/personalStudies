from matplotlib import pyplot as plt
from collections import Counter

grades = [83, 95, 91, 87, 70, 0, 85, 82, 100, 67, 73, 77, 0]

# Bucket grades by decile but include 100 with 90s
histogram = Counter(min(grade //10 * 10, 90) for grade in grades)

plt.bar([x + 5 for x in histogram.keys()], # Shift bars right by 5
        histogram.values(),              # Give each bar the correct height
        10,                              # Give each a width of 10
        edgecolor=(0,0,0))               # Black edges

plt.axis([-5,105,0,5]) # x-axis from -5 to 105, y axis from 0 to 5

plt.xticks([10*i for i in range(11)])
plt.xlabel("Decile")
plt.ylabel("# of Students")
plt.title("Distribution of Exam 1 grades")
plt.show()

