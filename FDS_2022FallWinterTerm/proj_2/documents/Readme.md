> I had already prepared files compiled for Mac. They are in `./execute_file`.

# Requirements

In order to run all the module in the project, you are supposed to have those environment.

- C & C++11 environment.
- python environment (as for packages, check `requirements.txt`).
  - Recommended reading: 
    - [Python 环境搭建 | 菜鸟教程 (runoob.com)](https://www.runoob.com/python/python-install.html)
    - [Python 中的 requirement.txt - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/69058584)

- `bash`/`sh` command line environment.
  - If you are not familiar with this and you are Windows user, just install Git Bash for windows.
    - Recommended reading: 
      - [安装Git - 廖雪峰的官方网站 (liaoxuefeng.com)](https://www.liaoxuefeng.com/wiki/896043488029600/896067074338496)

  - If you are not familiar with this and you are Linux or Mac user, just use your default terminal app.



# Instructions

## Run the codes and test them.

- After making sure you have prepared all the environments, you only need to do one thing.

1. For Windows user, open your `git bash` and `cd` to this folder (or open `git bash` in the folder) and type in `bash _auto.sh` and press enter.
2. For Linux or Mac user, open your terminal and `cd` to this folder and type in `bash _auto.sh` and press enter.

- Then you should see following logs:

```
You are supposed to run this scrips with bash!
Start compiling algorithm codes!
Done!
Start generating test data!
Done!
Start testing codes! Don't edit output.txt!
Check out the answer while N = 5!
Accept!
Check out the answer while N = 10!
Accept!
Check out the answer while N = 15!
Accept!
......
```

## Clear useless files.

- Everything is the same except run the `_clear.sh` instead of `_auto.sh`.

## Others

- If you want to try the module singly, I also provide the scripts for them. 
- Try to run them.

# File Tree

```
.
├── _auto.sh
├── _clear.sh
├── readme.md
└── src
    ├── _clear.sh
    ├── _compile.sh
    ├── _run.sh
    ├── judger
    │   ├── _clear.sh
    │   ├── _judge.sh
    │   ├── _setup.sh
    │   ├── cache
    │   ├── judger.cpp
    │   ├── painter
    │   │   ├── painter.py
    │   │   └── requirements.txt
    │   ├── section_A
    │   │   ├── Readme.md
    │   │   └── maker.cpp
    │   ├── section_B
    │   │   ├── Readme.md
    │   │   └── maker.cpp
    │   └── section_C
    │       ├── Readme.md
    │       └── maker.cpp
    ├── lib
    │   ├── meta_data.cpp
    │   └── meta_data.h
    ├── python3
    └── solver
        ├── _clear.sh
        ├── _setup.sh
        ├── main.cpp
        └── optimal_match
            ├── match_referee.cpp
            ├── match_referee.h
            ├── voting_tree.cpp
            └── voting_tree.h
```