import Data.List

f :: Integer -> Integer -> [String]
f a n
    | a * 2 < n = show a : f (a * 2) n
    | otherwise = [show a]

main :: IO()
main = do
    n <- readLn :: IO Integer
    let s = f 1 n
    print $ length s
    putStrLn $ concat $ intersperse " " s