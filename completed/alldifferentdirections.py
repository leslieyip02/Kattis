from math import sin, cos, radians, sqrt

def main():
    n = int(input())
    while n != 0:
        x_sum, y_sum = 0, 0
        points = []
        
        for _ in range(n):
            # store directions in a list
            dirs = input().split(" ")
            # initial values
            x, y, a = [float(dirs.pop(i)) for i in (0, 0, 1)]
            dirs.pop(0)

            for i in range(0, len(dirs), 2):
                if  dirs[i] == "turn":
                    # turn in place
                    a = a + float(dirs[i + 1])
                else:
                    # displacement
                    d = float(dirs[i + 1])
                    a_rads = radians(float(a))
                    x = x + d * cos(a_rads)
                    y = y + d * sin(a_rads)

            x_sum = x_sum + x
            y_sum = y_sum + y
            points.append((x, y))
            
        avg_x = x_sum / n
        avg_y = y_sum / n

        # find distance between points and averaged end point
        max_d = 0
        for point in points:
            x, y = point
            d = sqrt((avg_x - x) ** 2 + (avg_y - y) ** 2)
            if d > max_d:
                max_d = d

        print(avg_x, avg_y, max_d)
            
        n = int(input())

if __name__ == "__main__":
    main()