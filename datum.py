dates = ["Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday"]
months = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

d, m = [int(i) for i in input().strip().split(" ")]
print(dates[(sum(months[:m - 1]) + d - 1) % 7])