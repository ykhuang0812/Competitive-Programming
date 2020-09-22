# Competitive-Programming
* Note: Please use your Google or E3 account to use Oauth for login

## Assignment1 - Big Integer
* [Problem](https://oj.nctu.me/problems/819/)
* [Code](https://github.com/ykhuang0812/Competitive-Programming/blob/master/Spring_2019/Assignment1.cpp)

想法：因為C++不支援Big Integer所以就要用字串的方法來處理（當然也可以使用python比較輕鬆）


## Assignment2 - Expression
* [Problem](https://oj.nctu.me/problems/820/)
* [Code](https://github.com/ykhuang0812/Competitive-Programming/blob/master/Spring_2019/Assignment2.cpp)

想法：此題是給定一字串 ex.1+2*3 要輸出9，所以在每次讀到operator時將現有儲存結果與當前讀到的進行運算

## Assignment3 - Mex
* [Problem](https://oj.nctu.me/problems/822/)
* [Code](https://github.com/ykhuang0812/Competitive-Programming/blob/master/Spring_2019/Assignment3.cpp)

想法：我在hashmap中只儲存 l ~ l+n 之間的值，因為要出現最小的一定只會在個範圍之中

## Assignmet4 - Time limit exceed 
* [Problem](https://oj.nctu.me/problems/823/)
* [Code](https://github.com/ykhuang0812/Competitive-Programming/blob/master/Spring_2019/Assignment4.cpp)

```
Example:
5 10 7 8 12

他是在一個陣列中從每個數字當起點用greedy的方式找到當前的遞增序列
例如5就是
5 10 12 而並非 5 7 8 12

所以我們的output會是在
5 10 12
10 12
7 8 12
8 12
中找最長的那個，也就是5 10 12 or 7 8 12 （長度為3）
```

想法：此題是要先看懂他的code在幹嘛，我就用一個stack來記錄，從陣列的最後面開始，若比stack的top還大就一直pop直到我比top小，
然後再push進去並在此時更新最大值。


## Assignmet5 - Binary String
* [Problem](https://oj.nctu.me/problems/825/)
* [Code](https://github.com/ykhuang0812/Competitive-Programming/blob/master/Spring_2019/Assignment5.cpp)

想法：用一個tree出儲存string出現的次數，而在encode的時候只要把自己的children全部加起來再加上自己就是答案
```
Example:
Input:
00
001
010
0010
00

Tree:  往左是0，往右是1

         0 
        /   
       0     
     /   \  
    2     0 
     \   /
      1 1 
     /
    1
    
Decode:
00 = 4
001 = 2
0010 = 1
010 = 1
```
