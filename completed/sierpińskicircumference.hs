import System.IO (isEOF)
import Text.Printf

-- perimeter = 3 + (3 / 2) ^ 1 + (3 / 2) ^ 2 + ... = 3 ^ (n + 1) / 2 ^ n
-- number of digits = ⌊(n + 1) * log10(3) + n * log10(2)⌋ + 1
digits :: Double -> Integer
digits n = floor $ ((n + 1) * (logBase 10 3) - n * (logBase 10 2)) + 1

main :: IO()
main = do
    c <- getContents
    let ts = (map read) (words c) :: [Integer]
    flip mapM_ (zip [1..] ts) $ \(i, t) -> do
        putStr $ "Case " ++ show i ++ ": "
        print $ digits $ fromIntegral t
