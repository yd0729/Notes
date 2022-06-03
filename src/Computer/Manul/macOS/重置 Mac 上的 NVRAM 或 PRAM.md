---
created: 2022-01-18T14:56:24 (UTC +08:00)
tags: []
source: https://support.apple.com/zh-cn/HT204063?utm_source=pocket_mylist
author:
---

# 重置 Mac 上的 NVRAM 或 PRAM - Apple 支持 (中国)

如果 Mac 出现了与 NVRAM 或 PRAM 中储存的设置有关的问题，那么进行重置可能会有帮助．

NVRAM（非易失性随机访问存储器）是一小部分内存，Mac 使用这些内存来储存某些设置并对其进行快速访问．PRAM（参数 RAM）储存着类似的信息，且 NVRAM 和 PRAM 的重置步骤相同．

可储存在 NVRAM 中的设置包括音量、显示屏分辨率、启动磁盘选择、时区，以及最近的内核崩溃信息．储存在 NVRAM 中的设置取决于您的 Mac 以及与这台 Mac 搭配使用的设备．

如果您遇到与这些设置或其他设置有关的问题，那么重置 NVRAM 可能会有帮助．例如，如果 Mac 并非从“启动磁盘”偏好设置中选定的磁盘启动，或者在 Mac 启动前短暂地显示了一个问号图标，则可能需要重置 NVRAM．

## 如何重置 NVRAM

<img src="/Users/yangdong/Library/CloudStorage/OneDrive-Personal/Media/Knowledge Base.media/macos-nvram-option-key.png" alt="Option 键" style="zoom:50%;" /><img src="/Users/yangdong/Library/CloudStorage/OneDrive-Personal/Media/Knowledge Base.media/mac-nvram-add-icon.png" alt="加" style="zoom:50%;" /><img src="/Users/yangdong/Library/CloudStorage/OneDrive-Personal/Media/Knowledge Base.media/macos-nvram-command-key.png" alt="Command 键" style="zoom:50%;" /><img src="/Users/yangdong/Library/CloudStorage/OneDrive-Personal/Media/Knowledge Base.media/mac-nvram-add-icon-20220118155105889.png" alt="加" style="zoom:50%;" /><img src="/Users/yangdong/Library/CloudStorage/OneDrive-Personal/Media/Knowledge Base.media/macos-nvram-p-key.png" alt="P 键" style="zoom:50%;" /><img src="/Users/yangdong/Library/CloudStorage/OneDrive-Personal/Media/Knowledge Base.media/mac-nvram-add-icon-20220118155109703.png" alt="加" style="zoom:50%;" /><img src="/Users/yangdong/Library/CloudStorage/OneDrive-Personal/Media/Knowledge Base.media/macos-nvram-r-key.png" alt="R 键" style="zoom:50%;" />

将 Mac 关机，然后开机并立即同时按住以下四个按键：Option、Command、P 和 R．您可以在大约 20 秒后松开这些按键，在此期间您的 Mac 可能看似在重新启动．

- 如果 Mac 电脑发出启动声，您可以在第二次启动声过后松开这些按键．
- 在[搭载 Apple T2 安全芯片的 Mac 电脑](https://support.apple.com/zh-cn/HT208862)上，您可以在 Apple 标志第二次出现并消失后松开这些按键．

如果您的 Mac 使用了[固件密码](https://support.apple.com/zh-cn/HT204455)，这个组合键将不起任何作用或导致您的 Mac 从 [macOS 恢复功能](https://support.apple.com/zh-cn/HT201314)启动．要重置 NVRAM，请先关闭固件密码．

在您的 Mac 完成启动后，您可能需要打开“系统偏好设置”并调整已重置的任何设置，例如音量、显示屏分辨率、启动磁盘选择或时区．

## 进一步了解

- 如果您使用的是 Mac 台式电脑而非笔记本电脑，并且每次关闭 Mac 并断开 Mac 电源时，音量或时区等设置均会重置，则您可能需要更换 Mac 中的电池．这个小电池位于电脑的主板上，用于在断开 Mac 电源连接时帮助 NVRAM 保存设置．您可以携 Mac 前往 Apple 服务提供商处来更换该电池．
- 如果遇到了与睡眠、唤醒、电源、为 Mac 笔记本电脑电池充电有关的问题或其他与电源相关的症状，您可能需要[重置 SMC（系统管理控制器）](http://support.apple.com/zh-cn/HT201295)．

发布日期： 2020 年 12 月 04 日
