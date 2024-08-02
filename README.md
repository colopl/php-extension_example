# extension_example

[`zeriyoshi/pskel`](https://github.com/zeriyoshi/pskel) を用いた PHP Extension のサンプルです。

PHP 8.2 から利用できる `ext-random` ビルトイン拡張機能に [`libsodium`](https://github.com/jedisct1/libsodium) を用いた乱数生成器を追加するサンプル実装を含んでいます。

### Usage

```
$ git clone --recursive "https://github.com/colopl/php-extension_example" "extension_example"
$ cd "extension_example/ext"
$ phpize && ./configure --with-php-config="$(which php-config)"
$ make -j"$(nproc)" && make test
$ [sudo] make install
```

### Development

このプロジェクトは [`zeriyoshi/pskel`](https://github.com/zeriyoshi/pskel) をベースに作成されています。基本的な使い方は Pskel と同様です。

### LICENSE

PHP License 3.01
