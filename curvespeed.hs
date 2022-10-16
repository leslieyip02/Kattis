v (x:y:xs) = show (round . sqrt $ ((r * (s + 0.16)) / 0.067))
    where
        r = read x :: Double
        s = (read . ('0':)) y :: Double

main = do
    d <- getContents
    putStrLn $ unlines . (map v) $ (map words) (lines d)
