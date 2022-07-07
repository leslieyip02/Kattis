from math import pow, pi

# square the polynomial
def square(p):
    coeffs = {}

    for i in range(len(p)):
        for j in range(len(p)):
            coeffs[i + j] = coeffs.get(i + j, 0) + p[i] * p[j]

    return coeffs

# integrate the polynomial
def integrate(p):
    coeffs = {}

    for power, coeff in p.items():
        coeffs[power + 1] = coeff / (power + 1)

    return coeffs

# integrate from x1 to x2
def volume(p, x1, x2):
    v = 0
    
    for power, coeff in p.items():
        v += coeff * (pow(x2, power) - pow(x1, power))

    return pi * v

def main():
    t = 1
    while True:
        try:
            n = int(input())
            p = [float(a) for a in input().split(" ")]
            xlow, xhigh, inc = [float(x) for x in input().split(" ")]

            # volume of graph rotated about axis = ∫ π y² dx
            pp = integrate(square(p))
            v = volume(pp, xlow, xhigh)
            print(f"Case {t}: {round(v, 2):.2f}")

            if inc > v:
                print("insufficient volume")
            else:
                markings = []
                while len(markings) < 8 and (len(markings) + 1) * inc < v:
                    x1 = xlow
                    x2 = xhigh

                    while x2 - x1 > 0.000001:
                        mark = (x1 + x2) / 2
                        if volume(pp, xlow, mark) > (len(markings) + 1) * inc:
                            x2 = mark
                        else:
                            x1 = mark

                    markings.append(x1 - xlow)

                print(" ".join([f"{round(mark, 2):.2f}" for mark in markings]))

            t += 1

        except:
            quit()
            
if __name__ == "__main__":
    main()