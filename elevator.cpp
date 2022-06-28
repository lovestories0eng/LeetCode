#include <iostream>
#include <string>
#include <cstdio>
#include <stdlib.h>
#include "print.h"
using namespace std;

// 九层楼
int mf=9;
// 定义类
building A(mf);
void display()
{
    system("cls");
    A.dis_b();
    A.dis_vew();
}

int main()
{
    int i,j;
    // 电梯向上
    int flag1;
    // 电梯向下
    int flag2;
    // 电梯转向
    int flag = 1;
    int cnt;
    // 当前电梯所在楼层
    int cur;
    cur = 1;
    display();
    cout << "电梯停在" << cur << "层，请乘客进入电梯" << endl;
    // 电梯内输入
    A.E.inoperate(1);
    // 电梯向上走
    A.E.set_status(1);
    while(1)
    {
        display();
        if(A.E.get_status() == 0)
        {
            cout << "电梯中无人也没有请求，程序结束" << endl;
            system("pause");
            break;
        }
        // 向上
        if(A.E.get_status() == 1) {
            if(flag == 0)// 电梯从下转为上
            {
                cur = cur + 1;
                A.E.set_now(cur);
            }
            flag = 1;
            display();
            cout << "电梯向上运行，将要到达" << cur + 1 << "层！" << endl << endl;
            cur = cur + 1;
            A.E.set_now(cur);
            // 电梯外输入
            A.E.outoperate();
            while(1) {
                // 没有人需要下电梯
                if(A.E.get_floor(cur) == 0) {
                    // 有人从外部进入向上走
                    if(A.E.get_out(cur) == 1 || A.E.get_out(cur) == 3) {
                        display();
                        cout << "电梯停在" << cur << "层，请乘客进入电梯" << endl;
                        // 完成了该层向上的请求，还剩下向下的请求
                        // 如果当时电梯是向上运行的并且到达了该层，我们假设该层要向下的人不会进入电梯。
                        if(A.E.get_out(cur) == 3)
                            A.E.set_out(cur, 2);
                        // 请求完成，上电梯，销毁请求
                        else
                            A.E.set_out(cur, 0);
                        // 电梯内输入    
                        A.E.inoperate(cur);
                    }
                    // 电梯没有上到最高层
                    if(cur <= mf) {
                        display();
                        cout << "没有乘客在" << cur << "层上下，电梯继续向上运行!" << endl << endl;
                        // 电梯外输入
                        A.E.outoperate();
                        // 向上状态
                        A.E.set_status(1);
                        // 电梯向上运行
                        cur = cur + 1;
                        A.E.set_now(cur);
                    }
                }
                // 有人到达所需要的楼层，要下电梯
                else if(A.E.get_floor(cur) == 1) {
                    display();
                    cout << "电梯停在" << cur << "层，请乘客下电梯" << endl;
                    for(i=1; i <= A.E.counts; i++) {
                        if((A.E.p[i].to_floor == cur) && (A.E.p[i].in_floor == 1)) {
                            cout << "请A电梯中的第" << i << "位乘客下电梯" << endl;
                            // 下电梯
                            A.E.p[i].in_floor = 0;
                        }
                    }
                    // 到达第i层，第i层指示灯熄灭。
                    A.E.set_button(cur,0);
                    // 送达，从消息列表中移除
                    A.E.set_floor(cur,0);
                    // 电梯外输入
                    A.E.outoperate();
                    cur = cur + 1;
                    A.E.set_now(cur);
                }

                // 有人从外部进入向上走
                if(A.E.get_out(cur) == 1 || A.E.get_out(cur) == 3) {
                    display();
                    cout << "电梯停在" << cur << "层，请乘客进入电梯" << endl;
                    // 完成了向上的请求，还剩下向下的请求
                    if(A.E.get_out(cur) == 3)
                        A.E.set_out(cur, 2);
                    else
                        // 请求完成，上电梯，销毁请求
                        A.E.set_out(cur, 0);
                    // 电梯内输入
                    A.E.inoperate(cur);
                }
                flag1 = 0;
                flag2 = 0;
                for(i=cur;i<=mf;i++) {
                    // 上方有请求
                    if(A.E.get_floor(i) == 1 || A.E.get_out(i) != 0)
                    {
                        flag1=1;
                        break;
                    }
                }
                for(j=1;j<=cur;j++) {
                    // 下方有请求
                    if(A.E.get_floor(j)==1||A.E.get_out(j)!=0) {
                        flag2=1;
                        break;
                    }
                }
                // 计数器
                cnt = 0;
                for(i=1; i<=mf; i++) {
                    if(A.E.get_floor(i) == 0 && A.E.get_out(i) == 0)
                        cnt++;
                }
                if(cnt == mf)
                {
                    A.E.set_status(0);
                    break;
                }
                if(flag1 == 1)
                    A.E.set_status(1);//电梯向上
                else if(flag2 == 1)//电梯向下
                {
                    A.E.set_status(2);//电梯向下
                    if(A.E.get_out(cur-1) == 2 || A.E.get_out(cur-1) == 3)
                    {
                        display();
                        cur = cur-1;
                        cout << "电梯停在" << cur << "层，请乘客进入电梯" << endl;
                        if(A.E.get_out(cur) == 3)//完成了向上的请求，还剩下向下的请求
                            A.E.set_out(cur,1);
                        else
                            A.E.set_out(cur,0);//请求完成，上电梯，销毁请求
                        A.E.inoperate(cur);//电梯内输入
                    }
                    break;
                }
            }
        }
        else if(A.E.get_status() == 2)//向下运行
        {
            if(flag == 1)//电梯从上转为下
            {
                cur = cur-1;
                A.E.set_now(cur);
            }
            flag = 0;
            display();
            cout << "电梯向下运行，将要到达" << cur-1 << "层！" << endl << endl;
            cur = cur-1;
            A.E.set_now(cur);
            A.E.outoperate();//电梯外输入
            while(1)
            {
                if(A.E.get_floor(cur) == 0)//没有人需要下电梯
                {
                    if(A.E.get_out(cur) == 2 || A.E.get_out(cur) == 3)//有人从外部进入向下走
                    {
                        system("cls");
                        A.dis_b();
                        A.dis_vew();
                        cout << "电梯停在" << cur << "层，请乘客进入电梯" << endl;
                        if(A.E.get_out(cur) == 3)//完成了向下的请求，还剩下向上的请求
                            A.E.set_out(cur,1);
                        else
                            A.E.set_out(cur,0);//请求完成，上电梯，销毁请求
                        A.E.inoperate(cur);//电梯内输入
                    }
                    if(cur >= 1)
                    {
                        display();
                        cout << "没有乘客在" << cur << "层上下，电梯继续向下运行!" << endl << endl;
                        A.E.outoperate();//电梯外输入
                        cur = cur-1;
                        A.E.set_now(cur);
                        A.E.set_status(2);//向下状态。
                    }

                }
                else if(A.E.get_floor(cur) == 1)//有人要下楼
                {
                    display();
                    cout << "电梯停在" << cur << "层，请乘客下电梯" << endl;
                    for(i = 1; i <= A.E.counts; i++)
                    {
                        if((A.E.p[i].to_floor == cur) && (A.E.p[i].in_floor == 1))
                        {
                            cout << "请A电梯中的第" << i << "位乘客下电梯" << endl;
                            A.E.p[i].in_floor = 0;//下电梯
                        }
                    }
                    A.E.set_button(cur, 0);//到达第i层，第i层指示灯熄灭。
                    A.E.set_floor(cur, 0);
                    cur = cur - 1;
                    A.E.set_now(cur);
                    A.E.outoperate();//电梯外输入
                }
                if(A.E.get_out(cur) == 2 || A.E.get_out(cur) == 3)//有人从外部进入向下走
                {
                    display();
                    cout << "电梯停在" << cur << "层，请乘客进入电梯" << endl;
                    if(A.E.get_out(cur) == 3)//完成了向下的请求，还剩下向上的请求
                        A.E.set_out(cur, 1);
                    else
                        A.E.set_out(cur,0);//请求完成，上电梯，销毁请求
                    A.E.inoperate(cur);//电梯内输入
                }
                flag1 = 0;
                flag2 = 0;
                // 判断从当前楼层到最上方是否有请求
                for(i = cur; i <= mf; i++) {
                    if(A.E.get_floor(i) == 1 || A.E.get_out(i) != 0)
                    {
                        flag1=1;
                        break;
                    }
                }
                // 判断从一楼到当前楼层是否有请求
                for(j = 1; j <= cur; j++) {
                    // 下方有请求
                    if(A.E.get_floor(j) == 1 || A.E.get_out(j) != 0)
                    {
                        flag2=1;
                        break;
                    }
                }
                cnt = 0;//计数器
                for(i = 1; i <= mf; i++)
                    if(A.E.get_floor(i) == 0 && A.E.get_out(i) == 0)
                        cnt++;
                if(cnt == mf)
                {
                    A.E.set_status(0);
                    break;
                }
                if(flag2 == 1)
                    A.E.set_status(2);// 电梯向下
                else if(flag1 == 1)
                {
                    A.E.set_status(1);// 电梯向上
                    break;
                }
            }
        }
    }
    return 0;
}