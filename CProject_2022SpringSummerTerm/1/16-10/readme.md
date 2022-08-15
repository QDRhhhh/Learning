**本代码来自于课本样例代码**

**根据题意修改了部分代码**

----- 

# menu

- 使用方法 | Doc
- 解题思路 | Solve

-----

# 使用方法 | Doc

1. 进入 `./src` 目录
2. 确认安装 `make` 工具
3. 在终端中运行 `make` 以编译
4. 执行 `run.exe` 以运行程序
5. 程序使用方法参考书本
6. 运行 `make clean` 以清楚编译产物

# 解题思路 | Solve

题目中所指出的问题主要来自于输入数据的不规范

代码整体原理是读入若干 `question` 然后存入以 `struct` 为载体的简陋 DB 中，尽管用这个想法实现 DB 非常的原始且不安全，但整体的实现思路并不存在致命问题。

而造成题目中的问题的主要原因是，框架设计者将 **“问题反馈”** 与 **“提问”** 这两个部分进行了 **强绑定** ，理想情况下需要对其进行解耦。即将 “反馈” 和 “提问” 分离，单独将 “反馈” 作为一条 `question` 再借由 “反馈” 跳转到 “提问”。但是这样一来，修改内容将全部在数据中完成。

所以我又想了个办法，观察数据集，发现所有的 “反馈” 都以 `Yes` 或 `No` 开头，所以只需要避免重复输出以这两个单词开头的 `question` 即可。

具体实现部分在 `teach.c` 中的 285 ~ 298 行添加：

```c
/*
 * Function: isJudge
 * Usage: isJudge(line);
 * ----------------------
 * This function judge that whether the string start with 'Yes' 
 * or 'No'. If yes, than it returns true, otherwise it returns 
 * false.
 */

static int isJudge(char * line){
    if( line[0] == 'N' && line[1] == 'o' ) return 1;
    if( line[0] == 'Y' && line[1] == 'e' && line[2] == 's' ) return 1;
    return 0;
}
```

在 310 ~ 319 行中做如下修改：

```c
static void AskQuestion(questionT q, int isFirstTime)
{
    int i;

    for (i = 0; q->qtext[i] != NULL; i++) {
        // Judge whether the first line contains judgement, and remove the certain line. 
        if(!isFirstTime && isJudge(q->qtext[i]) && i == 0 ) continue;
        else printf("%s\n", q->qtext[i]);
    }
}
```

尽管这种解决办法仍然又许多纰漏，但在最小限度下修改测试数据——即面向数据修改代码——的情况下，这是我认为最有效的办法。