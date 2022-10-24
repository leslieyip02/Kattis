reduce :: [Integer] -> [Integer]
reduce [x] = []
reduce (x:y:xs) = (y - x) : reduce (y:xs)

same :: [Integer] -> Bool
same [x] = True
same (x:y:xs)
    | x == y = same (y:xs)
    | otherwise = False

solve :: Integer -> [Integer] -> (Integer, Integer)
solve d p
    | same r = (d, (last p) + (last r))
    | otherwise = (i, (last p) + j)
    where 
        r = reduce p
        q = solve (d + 1) r
        i = fst q
        j = snd q

main :: IO()
main = do
    line <- getLine
    let v = drop 1 $ map read (words line) :: [Integer]
    let m = solve 1 v
    putStrLn $ (show $ fst m) ++ " " ++ (show $ snd m)