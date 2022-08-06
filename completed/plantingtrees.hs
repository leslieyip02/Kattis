import Data.List

sortDesc :: [Int] -> [Int]
sortDesc list = reverse (sort list)

growTrees :: Int -> [Int] -> [Int]
growTrees n list = zipWith (+) [1 .. n] list

main :: IO()
main = do
    n <- readLn :: IO Int
    saplings <- getContents

    let sorted = sortDesc (map read (words saplings)) :: [Int]
    let trees = growTrees n sorted

    print(maximum trees + 1)