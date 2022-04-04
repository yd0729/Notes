# 无法联网，无法连接 USB

> [Parallels Desktop 16 完美解决无法联网，无法连接 USB_SportHappy 的博客-CSDN 博客](https://blog.csdn.net/SportHappy/article/details/112131489)

最新的 Parallels Desktop 16 在 Big Sur 下运行会有无法联网的问题，会提示“您的虚拟机将继续正常运作 但将无法连接网络。

经过数次测试，发现是 16 的配置文件里联网的配置写反了，我们可以手动更改，更改完后，虚拟机可以完美的实现联网和 USB 功能，融合模式也是非常稳定。想用的小伙伴可以试着按照下方的教程操作

1、首先点击“前往”--“前往文件夹”，在目标路径里输入“/资源库/Preferences/Parallels/”，打开文件夹后，会看到“dispatcher.desktop.xml”和“network.desktop.xml"这两个文件。

<img src="/Users/yangdong/Library/CloudStorage/OneDrive-Personal/Media/Knowledge Base.media/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1Nwb3J0SGFwcHk=,size_16,color_FFFFFF,t_70.png" alt="watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1Nwb3J0SGFwcHk=,size_16,color_FFFFFF,t_70.png" style="zoom:67%;" />

2、因为权限问题，在当前文件夹下，是无法修改文件内容的，第一种是把这两个文件复制出来 ，修改完成后再替换回去 第二种使用 vscode 编辑

3、”dispatcher.desktop.xml“文件，找到一行”<Usb>0</Usb>“，把这项的参数修改为”<Usb>1</Usb>“，如果找不到的话，可以使用编辑器的查找功能来查找这串参数，并完成修改保存，修改完后关闭文件。

如果出现此弹窗

<img src="/Users/yangdong/Library/CloudStorage/OneDrive-Personal/Media/Knowledge Base.media/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1Nwb3J0SGFwcHk=,size_16,color_FFFFFF,t_70-20220118160709492.png" alt="watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1Nwb3J0SGFwcHk=,size_16,color_FFFFFF,t_70-20220118160709492.png" style="zoom:67%;" />

点击 Retry as Sudo... 然后输入密码即可保存成功

<img src="/Users/yangdong/Library/CloudStorage/OneDrive-Personal/Media/Knowledge Base.media/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1Nwb3J0SGFwcHk=,size_16,color_FFFFFF,t_70-20220118160715527.png" alt="watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1Nwb3J0SGFwcHk=,size_16,color_FFFFFF,t_70-20220118160715527.png" style="zoom:67%;" />

4、“network.desktop.xml"文件，找到第五行”<UseKextless>1</UseKextless>“或者”<UseKextless>-1</UseKextless>“，把这一行修改为<UseKextless>0</UseKextless>“，保存，修改完成全关闭文件。

<img src="/Users/yangdong/Library/CloudStorage/OneDrive-Personal/Media/Knowledge Base.media/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1Nwb3J0SGFwcHk=,size_16,color_FFFFFF,t_70-20220118160721534.png" alt="watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1Nwb3J0SGFwcHk=,size_16,color_FFFFFF,t_70-20220118160721534.png" style="zoom:67%;" />

5、彻底退出 PD 软件，并重新打开，可以看到网络已经完全正常了，融合模式也可以互访桌面。

6、某些情况下，似乎虚拟机里的网络会有感叹号，虽然虚拟机没有报错，可是还是打不开网络，这种情况下，就需要打开虚拟机的配置文件，找到”硬件“这一项，在”网络“这一选项中，把”共享网络（建议）“这里的值修改为”默认适配器“，返回虚拟系统后，就不会没有网络了。

<img src="/Users/yangdong/Library/CloudStorage/OneDrive-Personal/Media/Knowledge Base.media/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1Nwb3J0SGFwcHk=,size_16,color_FFFFFF,t_70-20220118160727175.png" alt="watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L1Nwb3J0SGFwcHk=,size_16,color_FFFFFF,t_70-20220118160727175.png" style="zoom:67%;" />
