#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<math.h>
#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
class StackCalculator {

    //数字栈
    Stack<Integer> numStack = new Stack<>();

    //符号栈
    Stack<String> symbolStack = new Stack<>();

    /**
     * 根据计算公式运算并输出结果
     * @param expression 计算公式
     */
     void calculate(String expression) {
        //用于多位数拼接
        String numStr = "";

        //遍历字符串里的每一个字符
        for (int i = 0; i < expression.length() ; i++) {
            String ch = expression.substring(i, i + 1);
            //检验是否数字
            if (ch.matches("[0-9]")) {
                //如果该数字已经是最后一个字符就直接存入数字栈
                if (i == expression.length() - 1){
                    numStack.push(Integer.valueOf(ch));
                }else {
                    //如果不是字符串最后一个字符，就拼接入字符串
                    numStr += ch;
                }
                continue;
            }
            //如果是符号，就把之前拼接的多位数存入数字栈
            numStack.push(Integer.valueOf(numStr));
            numStr = "";

            //如果是符号就比较符号优先级并进行计算和入栈操作
            compareAndOperation(ch);
        }

        //当符号栈为空时，说明计算完成，此时数字栈唯一数字即为结果
        while (!symbolStack.empty()) {
            int result = getCalculateResult();
            numStack.push(result);
        }
        System.out.println("计算结束！结果为：" + numStack.pop());
    }

    /**
     * 使用递归解决连乘或连除问题
     * @param symbol
     */
    void compareAndOperation(String symbol) {
        //如果是符号就比较符号优先级
        if (isFrist(symbol)){
            //如果当前符号与符号栈栈栈顶符号优先或者平级就入栈
            symbolStack.push(symbol);
            return;
        }else {
            //否则就从栈中取两数字和一个符号先计算
            int num = getCalculateResult();
            //再把计算结果入数栈
            numStack.push(num);

            //递归，继续比较上一个是否与当前符号的优先级
            compareAndOperation(symbol);
        }
    }

    /**
     * 根据数字和符号运算并返回结果
     * @param num1 后出栈的数字
     * @param num2 先出栈的数字
     * @param symbol 运算符号
     * @return
     */
    int getCalculateResult(int num1, int num2, String symbol) {
        int result = 0;
        //根据符号进行运算
        switch (symbol){
            case "+":
                result = num1 + num2;
                break;
            case "-":
                result = num1 - num2;
                break;
            case "*":
                result = num1 * num2;
                break;
            case "/":
                result = num1 / num2;
                break;
                default:
                    throw new RuntimeException("只支持加减乘除运算！");
        }

        System.out.println(num1 + symbol + num2 + "=" + result);

        return result;
    }

    /**
     * 直接从数栈取两数字，符号栈取一符号进行计算
     * @return
     */
    int getCalculateResult() {
        int num1 = numStack.pop();
        int num2 = numStack.pop();
        String symbol = symbolStack.pop();
        int result = getCalculateResult(num2, num1, symbol);
        return result;
    }

    /**
     * 比较符号和当前符号栈顶符号的优先级。
     * 如果当前符号优先级小于符号栈栈顶符号的优先级，就返回false，否则返回true
     * 如果当前符号栈为空，直接返回true
     * @param symbol
     * @return
     */
    boolean isFrist(String symbol) {
        //判断当前符号栈是否为空
        if (symbolStack.empty()) {
            return true;
        }
        //取出并放回栈顶符号
        String stackSymbol = symbolStack.pop();
        symbolStack.push(stackSymbol);

        //栈顶符号的优先级
        int stackSymbolGrade = getSymbolGrade(stackSymbol);
        //当前符号的优先级
        int symbolgrade = getSymbolGrade(symbol);

        return symbolgrade > stackSymbolGrade;
    }

    /**
     * 根据符号返回符号的优先级
     * @param symbol
     * @return 加减返回0，乘除返回1
     */
    int getSymbolGrade(String symbol) {
        int grade;
        if ("+".equals(symbol) || "-".equals(symbol)) {
            grade = 0;
        } else if ("*".equals(symbol) || "/".equals(symbol)) {
            grade = 1;
        }else {
            throw new RuntimeException("不支持的操作符类型：" + symbol);
        }
        return grade;
    }
}
