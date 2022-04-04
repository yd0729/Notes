# Conda

## 安装

### 下载

[Anaconda 官方](https://www.anaconda.com/)

[Anaconda 阿里镜像](https://mirrors.aliyun.com/anaconda/)

[Minconda 阿里镜像](http://mirrors.aliyun.com/anaconda/miniconda/)

### [配置阿里源](https://developer.aliyun.com/mirror/anaconda)

1. 修改用户目录下的 .condarc 文件。

    Windows 需要先执行 `conda config --set show_channel_urls yes` 生成该文件后再修改。

        channels:
            - defaults
        show_channel_urls: true
        default_channels:
            - http://mirrors.aliyun.com/anaconda/pkgs/main
            - http://mirrors.aliyun.com/anaconda/pkgs/r
            - http://mirrors.aliyun.com/anaconda/pkgs/msys2
        custom_channels:
            conda-forge: http://mirrors.aliyun.com/anaconda/cloud
            msys2: http://mirrors.aliyun.com/anaconda/cloud
            bioconda: http://mirrors.aliyun.com/anaconda/cloud
            menpo: http://mirrors.aliyun.com/anaconda/cloud
            pytorch: http://mirrors.aliyun.com/anaconda/cloud
            simpleitk: http://mirrors.aliyun.com/anaconda/cloud

2. 运行 `conda clean -i` 清除索引缓存。

## 使用

### 列出安装的包

```sh
conda list
```

### 升级 Python

```sh
conda install python=3.10.0
```
