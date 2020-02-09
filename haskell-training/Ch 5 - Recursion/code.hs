maximum' :: (Ord a) => [a] -> a  
maximum' [] = error "maximum of empty list"  
maximum' [x] = x  
maximum' (x:xs) = max x (maximum' xs)  

replicate' :: (Num i, Ord i) => i -> a -> [a]  
replicate' n x  
    | n <= 0    = []  
    | otherwise = x:replicate' (n-1) x  


take' :: (Num i, Ord i) => i -> [a] -> [a]
take' n _
    | n <= 0 = []
take' _ []   = []
take' n (x:xs) = x : take' (n-1) xs

 
reverse' :: [a] -> [a]
reverse' [] = []
reverse' (x:xs) = reverse' xs ++ [x]


repeat' :: a -> [a]
repeat' x = x:repeat' x

zip' :: [a] -> [b] -> [(a,b)]
zip' _ [] = []
zip' [] _ = []
zip' (x:xs) (y:ys) = (x,y):zip' xs ys

elem' ::(Eq a) => a ->[a] -> Bool
elem' a [] = False
elem' a(x:xs)
    | a == x    = True
    | otherwise = a `elem'` xs

-- QuickSort!!!
    -- Uses a comprehension

quicksort :: (Ord a) => [a] -> [a] -- Takes in a list, outputs a list
quicksort [] = [] -- If empty list is passed in, resultis empty list
quicksort (x:xs) =  -- Iterate through the list, pivot element by pivot element, 
                    -- Placing pivot in a list between undorted lists with values greater than pivot, and another list with values greater than pivot
    -- Set variable values with let statement
    let smallerSorted = quicksort [a | a <- xs, a <= x] -- Recursively sort array with vals <= pivot
        biggerSorted = quicksort [a | a <- xs, a > x] -- Recursively sort array with vals > pivot
    in smallerSorted ++[x]++ biggerSorted -- Concatenate the two independently sorted lists