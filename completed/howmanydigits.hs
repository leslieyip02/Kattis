solve [] = []
solve (x:xs)
    | x == 0 || x == 1 = 1 : solve xs
    | otherwise = digits : solve xs
    where
        -- kamenetsky's formula
        digits = floor $ x * logBase 10 (x / (exp 1)) 
            + 0.5 * logBase 10 (2 * pi * x) + 1

readInput = (map read) . words
writeOutput = unlines . (map show)

main = interact (writeOutput . solve . readInput)