# Mac

## 安装

可以[安装 GPU 加速的 Tensorflow](https://developer.apple.com/metal/tensorflow-plugin/) 了，注意里面的小字，只有 Python 3.8 才能安装成功．环境没按照教程，用的是 miniconda ，不影响，加上 `SYSTEM_VERSION_COMPAT=0` 就行．但还是有点问题的，比如下面这个不加 device environment 就会报错．

```python
with tf.device('/CPU:0'):  #  GPU 上没有这个操作，不知道为啥
    X_var = tf.Variable(X)
    X_var[1, 2].assign(9)
```

更新：我在苹果的论坛上说了这个问题，苹果的工程师回复我了，下个版本应该能修复．

<img src="/Users/yangdong/Library/CloudStorage/OneDrive-Personal/Media/Knowledge Base.media/截屏2022-02-08 09.42.43.png" alt="截屏2022-02-08 09.42.43" style="zoom:100%;" />

## 报错

第 1 次导入 `tf` 的时候报错 [Unable to revert mtime: /Library/Fonts](https://stackoverflow.com/questions/62279920/python-macos-error-unable-to-revert-mtime-library-fonts) （这 `tf` 为啥会和字体有关呢？），答案里说 restore 一下系统字体，我 restore 之后自己装的字体全没了． 😱

第 1 个答案说装 `libmigic` ，也没解释（可能这就是 magic）．但我不想随便安装东西就选了第 2 种方法，然后把自己的字体装回去之后又配置了一次环境，这回啥事没有了． 🧐

```sh
brew install libmagic
```
