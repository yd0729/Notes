# 1 Introduction

## 1.1 Structure of a Typical Game Team

### 1.1.1 Engineers

- Runtime programmers：引擎和游戏

- Tools programmers：支持工具

二者都需要很多的专业技能，但是关注点不同：

- a single engine system：渲染、AI、声音、碰撞、物理
- gameplay programming and scripting
- system level

**但也有啥都会的全能选手．**

职业路线：engineer $\to$ lead engineer $\to$ technical director (TD) $\to$ chief technical officer (CTO)

### 1.1.2 Artists

> As we say in the game industry, “Content is king.”

- Concept artists：原画
- 3D modelers：建模
  - Foreground modelers：存在于游戏世界的东西（物品、人物、载具、武器等）
  - Background modelers：作为背景（土地、建筑、桥等）
- Texture artists：贴图
- Lighting artists：光照
- Animators：给游戏中的对象添加动作，要求必须与游戏引擎相协调，所以和 CG 电影还是有点区别．
- Motion capture actors：提供原始的动作数据，然后交给 animators 处理．
- Sound designers：声效和音乐
- Voice actors：声优
- Composers：“compose an original score for the game”

职业路线：artist $\to$ art director

### 1.1.3 Game Designers

设计玩家体验中的交互部分，即 gameplay ．工作在不同的层面，从负责整体的故事和章节到决定敌人何时会出现，排放补给品等．有一些游戏设计师也会与 gameplay engineers 紧密配合，写一些脚本．一些游戏设计师是从工程师转过来的~~，可能是觉得设计师太拉了所以想亲自上~~．

game writer 的工作包括与高级游戏设计师合作构建整体的故事框架，或者编写单个角色的对话．

职业路线：game designer $\to$ game director，也可能转到 producer ．

### 1.1.4 Producers

总的来说比较杂，更取决于工作室，包括人力资源经理、高级游戏设计师、作为开发团队与商业部门之间的桥梁等．一些小型的工作室根本就没有 producers，比如说作者所在的顽皮狗，几乎所有人都有在游戏开发中的角色，团队管理和商业上的事务由高级人员分摊（听起来很理想）．

### 1.1.5 Other Staff

行政、市场、管理、IT

### 1.1.6 Publisher and Studios

publisher 是负责卖游戏的，一般是大公司，比如 EA、Sony、Nintendo 等．

1. 很多游戏工作室不从属于某一个 pubilsher ，它们会把游戏卖给出价最高的出版商．
2. 另一些游戏工作室只为某一个 publisher 开发游戏．工作室可能与出版商签订了长期合同，或者被 publisher 直接拥有，但工作室本身是独立运营的．
3. 也有一些 publisher ，比如 EA 会直接管理它的工作室．
4. First-party developers 是从属于主机制造商（Sony，Nintendo 和 Microsoft）的工作室．For example, Naughty Dog is a first-party Sony developer. 这样的工作室只会为母公司的游戏硬件开发游戏（也就是所谓的独占大作）．

## 1.2 What Is a Game?

> In academia we sometimes speak of game theory, in which multiple agents select strategies and tactics in order to maximize their gains within the framework of a well-defined set of game rules.

根据游戏理论，游戏是在一个良好定义的游戏规则的框架下，多个玩家通过策略来最大化收益的过程．

> In his excellent book, A Theory of Fun for Game Design, Raph Koster defines a game to be **an interactive experience that provides the player with an increasingly challenging sequence of patterns which he or she learns and eventually masters** [30]. Koster’s assertion is that the activities of learning and mastering are at the heart of what we call “fun,” just as a joke becomes funny at the moment we “get it” by recognizing the pattern.

游戏“乐趣”的核心是提供给玩家的一种交互性的体验，通过一系列越来越具有挑战性的任务来让玩家觉得自己学习到并最终掌握了一种模式．

（所以说喜欢玩游戏的人应该都可以喜欢学习，也都有对成功的渴望，如果沉迷了那是为了躲避主客体矛盾）．

### 1.2.1 Video Games as Soft Real-Time Simulations

video games 在计算机科学家那里被叫做 soft real-time interactive agent-based computer simulations ．

- simluation，很显然从原子或夸克开始建模是不切实际的．对于游戏开发者来说，approximation 和 simplification 很重要，只要用的好，很简单的模型也可以看起来很真实，甚至更有趣．
- agent-based，有很多相互作用的实体，比如载具、人物、火球、能量点等．所以游戏基本上都是由面向对象的编程语言实现的．
- temporal，随着游戏中的事件和故事的发展，游戏世界本身也会改变．
- interactive，实时响应玩家的输入．
- real-time，有 deadline ．
  - 屏幕至少要每秒刷新 24 次，才能提供运动的错觉（典型的频率是 30 或 60 每秒，因为 NTSC 显示器是这个刷新率）．
  - 物理仿真至少要每秒更新 120 次，才能保持稳定．
  - AI 至少要每秒“想” 1 次，才不会看起来傻傻的．
  - audio library 至少要每秒调用 60 次，才能保证缓冲不被耗尽．
- soft，错过 deadline 也不是灾难性的（也就是卡一下，玩家不会死掉）．

数学模型有两种：

1. analytic (closed-form)：通项公式
2. numerical：递推公式

很多问题在数学上就没有 analytic 的解，而且玩家的输入是不可预测的（也就是即使有通项，你也没法用），所以不可能以 analytic 的方式建模整个游戏．在 “game loop” 中，游戏的各个部分（AI、游戏逻辑、物理仿真）以 numerical 的方式更新．

## 1.3 What Is a Game Engine?

从游戏的工程实践中产生，可重用性不断提高．一开始催生了“mod community”，后来逐渐成为了游戏开发者的二级收入来源．现在大多数的游戏开发者都不会从零开始开发一款游戏了，而是使用、修改现有的游戏引擎．

<img src="/Users/yangdong/Library/CloudStorage/OneDrive-Personal/Media/Knowledge Base.media/截屏2022-01-29 17.06.52.png" alt="截屏2022-01-29 17.06.52" style="zoom:50%;" />

游戏和游戏引擎之间没有清晰的界限，它们的定义随着游戏设计的固化而改变．**数据驱动的架构（data-driven architecture）**是游戏引擎与游戏的关键区别．作者认为“game engine”这个词应该是指在多个游戏之间可重用的那部分软件，硬编码到游戏中的逻辑和规则，或者是为了渲染一个游戏中的特定类型的对象而添加的代码是不可重用的，不能算是游戏引擎．

一些视频播放器能够播放任何类型的视频文件，但像这样的完全通用的能够播放任何游戏内容的游戏引擎可能永远都不会出现，因为对游戏来说，性能很重要．在通用性和针对特定平台/特定类型的游戏的优化这对 trade-off 之间，游戏引擎首先要尽可能满足后者．虽然现在硬件和算法上的进步缓和了这对矛盾，但仍然存在．

## 1.4 Engine Differences across Genres

- massively multiplayer online game (MMOG)
- first-person shooter (FPS)
- real-time strategy (RTS)

游戏有很多不同的类型，但只要都是 3D 游戏，就会有很多共同的部分（用户输入、渲染、显示、声音等）．所以虽然 Unreal Engine 是为 FPS 设计的，它也被成功应用在了很多其它的游戏中，比如 action-adventure game、fighting game, and the first three role-playing third-person shooter games in the Mass Effect series by BioWare.

### 1.4.1 First-Person Shooter (FPS)

第一人称射击游戏旨在为玩家提供沉浸在细节丰富的超现实主义世界中的错觉，通常也是技术上最具挑战性的游戏类型，在复杂性上可能只有第三人称射击游戏（third-person shooters）、动作平台游戏（action-platformer games）和大型多人游戏（massively multiplayer games）才能与之匹敌．游戏行业的许多重大技术创新都是从这种类型的游戏中产生的．唯独对玩家角色的运动和碰撞的要求比较低，所以看起来会 fuliu fuliu 的．

### 1.4.2 Platformers and Other Third-Person Games

平台游戏（Platformers）是一种 third-person character-based action game，主要的游戏机制是在平台之间跳跃，比如超级马里奥（Super Mario）．Platformers 的技术要求和第三人称射击/动作/冒险游戏差不多．

第三人称的游戏与 FPS 有很多共同之处，但更强调主角的能力和运动．角色需要有高保真的全身动画，而典型的 FPS 游戏中的只对“浮动手臂”的动画有高要求．虽然 FPS 基本都有多人在线模式，所以也需要角色的全身动画，但保真度无法相提并论．

平台游戏的主角通常是卡通化的，而第三人称射击游戏的主角通常是高度逼真的．这两种类型的游戏都要求玩家角色有丰富的动作和动画．

（原神应该属于第三人称动作/冒险游戏）

### 1.4.3 Fighting Games
