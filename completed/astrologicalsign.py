signs = {
    "Aries": ((21, "Mar"), (20, "Apr")),
    "Taurus": ((21, "Apr"), (20, "May")),
    "Gemini": ((21, "May"), (21, "Jun")),
    "Cancer": ((22, "Jun"), (22, "Jul")),
    "Leo": ((23, "Jul"), (22, "Aug")),
    "Virgo": ((23, "Aug"), (21, "Sep")),
    "Libra": ((22, "Sep"), (22, "Oct")),
    "Scorpio": ((23, "Oct"), (22, "Nov")),
    "Sagittarius": ((23, "Nov"), (21, "Dec")),
    "Capricorn": ((22, "Dec"), (20, "Jan")),
    "Aquarius": ((21, "Jan"), (19, "Feb")),
    "Pisces": ((20, "Feb"), (20, "Mar")),
}

def get_sign(d, m):
    for sign, range in signs.items():
        start, end = range
        start_date, start_month = start
        end_date, end_month = end

        if (m == start_month and d >= start_date) or \
            (m == end_month and d <= end_date):
            return sign

t = int(input())
for _ in range(t):
    d, m = input().split(" ")
    print(get_sign(int(d), m))