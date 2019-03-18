# othello

This is othello repository

[![Build Status](https://travis-ci.org/Kose-i/othello.svg?branch=master)](https://travis-ci.org/Kose-i/othello)

[comment]: # ()

## File constitution

| class | configure |
----|----
| Game | Othello game class |
| Hand | abstracle class -> Computer, Player |
| Computer | computer class with 強化学習|
| Player | player class |
| Point | position class for map |

[comment]: # (`csvdir`を設置後,簡易的なAIの実装に移動. -> Hyoukakansuu class del)

### Computer class

*computer* は強化学習により学習します. コンピュータ同士を学習させ, 最適な手を決定します.

[comment]:# (強化学習を理解する)

## How to Use

`config`内の`detect_hand.txt`ファイルを編集して,`Black` `White`のプレーヤーの名前を決めます.

*format*

`Black [name]`

`White [name]`

### プレーヤー名にcomputerという文字列を指定していた場合,computerが起動します.

`mkdir build`

`cd $_`

`cmake ..`

`make`

実行ファイルができたことを確認して実行します.

`./init_study [学習する数字(多いほど,時間がかかるが,学習する)]`

`./main config/csvdir/[保存したCSVファイル名]`

デフォルトでは,10で計算したファイルを使用します.
