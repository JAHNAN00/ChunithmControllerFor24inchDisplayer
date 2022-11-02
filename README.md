# 适配24寸显示器的中二控制器
全部是直插式元件，买来焊上就行

## 材料清单
* Arduino Pro Micro \* 1
* Mpr121模块 \* 3
* XH2.54端子若干
* 直插式三极管 \* 6
* 红外led发射器和接收器若干
* 电阻若干

## 做法
照着pcb的图焊上就行

![image](https://user-images.githubusercontent.com/87638727/199412481-572292e7-7154-469a-afcf-fb652bdcea54.png)
![image](https://user-images.githubusercontent.com/87638727/199412525-e02cff8d-eed0-4b41-9ee9-ec0c726c26dd.png)
![image](https://user-images.githubusercontent.com/87638727/199412556-088b6e28-33b0-4c6f-bcb1-6db1bacfc940.png)

然后用Arduino IDE上传一下代码，在游戏体里修改一下按键

如果觉得触摸板背后有排针，不平滑，可以找淘宝加工一块文件里的亚克力，不过有点小贵。

## 游戏按键设置
```
[slider]
cell32=0x41
cell31=0x42
cell30=0x43
cell29=0x44
cell28=0x45
cell27=0x46
cell26=0x47
cell25=0x48
cell24=0x49
cell23=0x4A
cell22=0x4B
cell21=0x4C
cell20=0x4D
cell19=0x4E
cell18=0x4F
cell17=0x50
cell16=0x51
cell15=0x52
cell14=0x53
cell13=0x54
cell12=0x55
cell11=0x56
cell10=0x57
cell9=0x58
cell8=0x59
cell7=0x5A;a-z
cell6=0x34
cell5=0x35
cell4=0x36
cell3=0x37
cell2=0x38
cell1=0x39

[ir]
ir6=0xdd
ir5=0xdb
ir1=0xbe
ir2=0xbf
ir3=0xba
ir4=0xde
```

## 实物

![d64ac3bacf77936e5221e14f8255fbc](https://user-images.githubusercontent.com/87638727/199413221-1f899a15-9137-4a5c-9256-164e16f07a36.jpg)

游玩视频：
https://www.bilibili.com/video/BV1fP4y1f7VN/?spm_id_from=333.999.0.0&vd_source=d597dceced300371fc8ce72364df3f2e
