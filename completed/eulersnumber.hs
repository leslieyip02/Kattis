-- keep dividing previous term by current value of a until a = n
euler :: Double -> Double -> Int -> [Double]
euler f0 a 0 = []
euler f0 a n = fa : euler fa (a + 1) (n - 1)
    where
        fa = f0 / a

main :: IO()
main = do
    n <- readLn :: IO Int
    print $ 1 + sum (euler 1 1 n)
