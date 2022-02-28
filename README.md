# Raytracer for terminal with ASCII for terminal

## Authors

- kohkubo
- yaito

## Features

- Draws a polygon based on an obj file.
- Raytracing
- Diffuse and specular reflections by Phong`s model)
- トーマス・モイラーの三角形の交差判定アルゴリズム
- Multithread using pthreads
- Specify the ASCII characters to be drawn
- Specify the color to be drawn
    - BULE, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE
- カメラ移動, 回転
    - 上下左右、回転軸の変更、回転の停止、回転速度、回転方向の
- 高速化により、ポリゴン数数千まで対応可能

## 開発手法

- Google Test
- Google Benchmark
- CI with GitHub Actions
- 単体テスト、結合テスト
- Git Flowに準じたissue駆動開発
- カバレッジツールを使用した高速化のための開発

## Key Control

- `z` - zoom in
- `x` - zoom out
- `w` - move up
- `s` - move down
- `a` - move left
- `d` - move right
- `j` - increase the angle of the left rotation
- `l` - Increase the angle of the right rotation
- `k` - Increase the upper rotation axis
- `i` - Increase the lower rotation axis