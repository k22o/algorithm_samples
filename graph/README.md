# グラフ

## dijkstra 法
単一始点最短経路問題のアルゴリズム
- dijkstra_template.cpp
    - ダイクストラ法のテンプレ
- dijkstra_example.cpp
    - ダイクストラ法の例
- extended_dijkstra.cpp
    - 拡張ダイクストラ法．例題では，ノード(N)*所持コインの2次元配列に対してダイクストラ法を実行する(DP的な運用)

## kruskal法 
最小全域木のアルゴリズム
- kruskal_template.cpp
    - クラスカル法のテンプレ
- kruskal_example.cpp
    - クラスカル法の例．孤立した点はコスト0として帰ってくる．

## Bellman-Ford法 
重みが負でも使える単一始点最短経路問題のアルゴリズム
負の重みがない場合は，ダイクストラ法の方が高速．
- bellman_ford_template.cpp
    - ベルマン・フォード法のテンプレ
- bellman_ford_template.cpp
    - ベルマン・フォード法の例．重みに－を掛けることで，最大値問題を解決．

## Warshall-Floyd法
全頂点間最短路アルゴリズム
- warshall_floyd_templete.cpp
    - ワーシャル・フロイド法のテンプレ
- warshall_floyd_example.cpp
    - ワーシャル・フロイド法の例．特定の複数点を全て通る最短経路を計算．