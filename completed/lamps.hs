light :: Integer -> Integer -> Integer -> Integer
light d h p
    | kle < ki  = d
    | otherwise = light (d + 1) h p
    where
        ni   = ceiling $ fromIntegral (d * h) / 1000
        ki   = 60 * d * h * p + ni * 500000
        kle  = 11 * d * h * p + 6000000

main :: IO()
main = do
    line <- getLine

    let numbers = map read (words line) :: [Integer]
    let h = numbers !! 0
    let p = numbers !! 1

    print $ light 0 h p