苹果系统有一个 GateKeeper 保护机制（自 OSX 10.5 加入）。从互联网上下载来的文件，会被自动打上 com.apple.quarantine 标志，翻译过来就是免疫隔离，系统根据这个附加属性对这个文件作出限制。在安装软件的时候需要移除 quarantine 属性。

```shell
sudo xattr -r -d com.apple.quarantine 文件名
```

