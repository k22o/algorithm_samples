# 写像12相
n個のボールをk個の箱に分割する問題を考えよう<br>
このとき，12個に場合分けがされる．
- ボールが区別されるかされないか(2通り)
- 箱が区別されるかされないか(2通り)
- 箱に入れられる個数制限(3通り)
    - 1個以下
    - 制限なし
    - 1個以上

以上12パターンについて，以下の表のように求まる．記入済みの部分は中高数学レベルなので省略．(1)-(4)ば後述．<br>
(1)-(3)は解析的に求めることが可能．

|ボール|箱|1個以下|制限なし|1個以上|
|:--- |:---|:---|:---|:---|
|区別する|区別する|kPn|k^n|(1)|
|区別しない|区別する|kCn|n+k-1Cn|n-1Ck-1|
|区別する|区別しない|0or1|(2)|(3)|
|区別しない|区別しない|0or1|(4)-1|(4)-2|

## (1)包除原理(Inclusion-exclusion principle)の利用
- n個の区別するボールをk個の区別する箱に1個以上いれる
- 「0個以上入れる」場合から「0個の箱が存在する場合」を引く
- 「0個の箱が存在する場合」は，「(0個の箱が1個のみ)-(0個の箱が2個のみ)+(0個の箱が3個のみ)…」として求まる
- 以上をまとめて，
- \sigma_{i=0}^k (-1)^k kCi(k-i)^n (O(logn))

## (2)ベル数B(n,k)
- n個の区別するボールをk個の区別しない箱に制限なく入れる
- スターリング数を利用して，以下のように求められる
- B(n,k) = S(n,0) + S(n,1) + ... +S(n,k)
- 3つの解法が考えられる
    - スターリング数をDPで求めて足す O(nk)
    - スターリング数の解法(1)をりようして，ベル数を直接計算する O(min(n,k)logn)
    - B(n)B(n,n)に関しては以下のDPでも求まる
    - B(n+1) = sigma_{i=0}^n nCi(B(i))


## (3)スターリング数(Stirling Number)：S(n,k)
- n個の区別するボールをk個の区別しない箱に1個以上入れる
- 解法1：(1)の答えをk!で割る．O(klogn)
- 解法2：漸化式(動的計画法)
    - S(n,k) = S(n-1,k-1) + k*S(n-1,k) 
- 厳密には，第2種スターリング数

## (4)分割数(Partition Function)：P(n,k)
- n個の区別しないボールをk個の区別しない箱に制限なく入れる場合の場合の数をP(n,k)と表す．
- 1個以上入れる場合は，P(n-k,k)
- P(n,k) = P(n-k,k) + P(n,k-1)
- 分割数は以上の漸化式を解くことで求まる(=アルゴリズムてきには動的計画法)
- 計算量はO(nk)



### reference
https://qiita.com/drken/items/f2ea4b58b0d21621bd51