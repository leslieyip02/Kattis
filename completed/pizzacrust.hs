cheese :: [Double] -> Double
cheese (r:c) = (r - last c) ^ 2 / r ^ 2 * 100

main :: IO()
main = do
    ln <- getLine
    let p = map read (words ln) :: [Double]

    print(cheese p)