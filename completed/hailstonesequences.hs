hailstone :: Integer -> [Integer]
hailstone a
    | a == 1 = a : []
    | a `mod` 2 == 0 = a : hailstone (a `div` 2)
    | otherwise = a : hailstone (3 * a + 1)

main :: IO()
main = do
    n <- readLn :: IO Integer
    print(length (hailstone n))