# Network Flow 

### Max-Flow / Min-Cut 問題
- ford_fullkerson_template.cpp
    - フォード・ファルカーソンアルゴリズム
    - 深さ優先探索で増加経路を探索
- edmonds-karp_template.cpp
    - エドモンズ・カープアルゴリズム
    - 幅優先探索で増加経路を探索
- min_cut.cpp
    - 最小カット問題
    - 無向グラフは，双方向の有向グラフとして解釈
    - 終点が複数ある場合は，終点全てが行きつく仮ゴールを設定する

## Min-Cost-Flow(最小費用流) 問題
- successive_shortest_path_template.cpp 
    - MaxFlowの探索を，最短路探索(bellman-ford)にすることで求める
    - 「最短路にできるだけ流す」を繰り返す

## bipartite_graphとマッチング
- bipartite_graph_judement_templete.cpp
    - 二部グラフ判定のテンプレ
- bipartite_graph_evenOdd.cpp
    - 二部グラフ判定 偶数長と奇数長に関する問題
- bipartite_max_matching_template.cpp
    - 最大二部マッチング問題のテンプレ
    - Group1をすべてstart,Group2を全てtargetとして最大流問題に帰着
- bipartite_max_matching_sample.cpp
    - 最大二部マッチングの例
- bipartite_max_matching_with_weight_template.cpp
    - 重み付き最大二部マッチングの例
    - costに-1を掛けることで，最小費用流問題に帰着
- bipartite_max_matching_with_weight_sample.cpp
    - 重み付き最大二部マッチングの例
