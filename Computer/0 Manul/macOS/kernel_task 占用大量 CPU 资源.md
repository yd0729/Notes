# kernel_task 占用大量 CPU 资源

## 官方解释：[如果 kernel_task 正在大量占用 Mac CPU 资源](https://support.apple.com/zh-cn/HT207359)

> 内核任务进程的功能之一是帮助管理 CPU 的温度。
>
> “[活动监视器](https://support.apple.com/zh-cn/HT201464)”可能会显示一个名为 kernel_task 的进程正在大量占用 CPU 资源，您可能会注意到在此期间风扇的活动量非常大。
>
> kernel_task 的功能之一是减少[正在密集使用 CPU 的进程](https://support.apple.com/zh-cn/HT203184)的可用 CPU 资源，从而帮助管理 CPU 温度。换言之，kernel_task 会对导致 CPU 过热的情况做出响应，即使您并未感觉 Mac 很热。它本身不会导致这些情况。等 CPU 温度下降后，kernel_task 会自动减少其活动。
>
> 发布日期： 2017 年 02 月 17 日

## 部分原因：[mac 中 kernel_task 占用大量内存如何解决？](https://www.zhihu.com/question/56689986)

> **Jarno Z writes:**  
> _It is with a very big surprise I read your article on that bug. I explain you why._  
> _MBP 2015 as well, since three weeks ago I had the same bug with kernel working at 80% of the computing resources. I did everything on the basis. Reinstall the OS, change user, reinstalled the latest combo, reset SMC and so on. Nothing worked out._  
> _I gave a thought about high room temperature. But was a false positive._  
> _**Then I had an idea. Maybe it is a connected peripheral. I detached everything. Symptoms away.** Long story short. Thunderbolt. When something is connected to the thunderbolt, monitor or dock, whatever I have, at some point the CPU goes in protection, idling at 0.8 GHZ, and at that point the kernel task goes up to maximum. In reality then is the cpu stuck not the kernel going up, even though this is what appears._  
> MPG: when/if this happens again, I’ll unplug the display and see if the problem goes away. I’ll also check the [Intel Power Gadget](https://link.zhihu.com/?target=https%3A//software.intel.com/en-us/articles/intel-power-gadget-20). In my case, the MBP was **very** warm to the touch everywhere, with ambient air temp of 90°F or so. Perhaps Thunderbolt is related and/or the root cause, but the issue needs reproducing to confirm Jarno’s suggestion. Thunderbolt is a relatively high power draw featur, and it could be that when things get too hot, the power management system takes the CPU down to minimal speed as a protective measure, rather than cutting off Thunderbolt.
>
> 补充: 经实际测试, 使用 HDMI 接口也存在同样的问题. **如果只用雷电口外接显示器, 情况就改善了很多(目前我只用了一端是雷电口一端是 DP 口的视频线外接了一个显示器, 飙高的问题基本没再出现过. )**. 下载一个 gfxCardStatus 可以查看目前使用的 GPU 是核显还是独显, 不过想要外接必须使用独立显卡. 不建议使用多合一的雷电转换头, 也不建议同时使用两个雷电口. 问题的关键就是尽量少的使用外设接口.

## 真正的原因 & 解决办法

## 原因

目前发现有 3 个导致此问题的原因：

1. 安装过 BootCamp
2. 使用过外接显示器
3. 使用的外接显示器的分辨率设置为中间的缩放。

## 解决办法

1. 如果以前用过外接显示器 / 安装过 BootCamp ，导致现在即使只用笔记本也有问题，解决办法是[[重置 Mac 上的 NVRAM 或 PRAM.md]]。
2. 在使用双屏时如果出现问题，尝试先把笔记本合上，等 kernel_task 降下来再打开。
3. 如果只使用外接也出问题，那么调整缩放到最左或最右。
   <img src="/Users/yangdong/Library/CloudStorage/OneDrive-Personal/Media/Knowledge Base.media/截屏2022-02-02 11.54.49.png" alt="截屏2022-02-02 11.54.49" style="zoom:100%;" />
