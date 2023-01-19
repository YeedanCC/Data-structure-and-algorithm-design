#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<math.h>
#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
class StackCalculator {

    //����ջ
    Stack<Integer> numStack = new Stack<>();

    //����ջ
    Stack<String> symbolStack = new Stack<>();

    /**
     * ���ݼ��㹫ʽ���㲢������
     * @param expression ���㹫ʽ
     */
     void calculate(String expression) {
        //���ڶ�λ��ƴ��
        String numStr = "";

        //�����ַ������ÿһ���ַ�
        for (int i = 0; i < expression.length() ; i++) {
            String ch = expression.substring(i, i + 1);
            //�����Ƿ�����
            if (ch.matches("[0-9]")) {
                //����������Ѿ������һ���ַ���ֱ�Ӵ�������ջ
                if (i == expression.length() - 1){
                    numStack.push(Integer.valueOf(ch));
                }else {
                    //��������ַ������һ���ַ�����ƴ�����ַ���
                    numStr += ch;
                }
                continue;
            }
            //����Ƿ��ţ��Ͱ�֮ǰƴ�ӵĶ�λ����������ջ
            numStack.push(Integer.valueOf(numStr));
            numStr = "";

            //����Ƿ��žͱȽϷ������ȼ������м������ջ����
            compareAndOperation(ch);
        }

        //������ջΪ��ʱ��˵��������ɣ���ʱ����ջΨһ���ּ�Ϊ���
        while (!symbolStack.empty()) {
            int result = getCalculateResult();
            numStack.push(result);
        }
        System.out.println("������������Ϊ��" + numStack.pop());
    }

    /**
     * ʹ�õݹ������˻���������
     * @param symbol
     */
    void compareAndOperation(String symbol) {
        //����Ƿ��žͱȽϷ������ȼ�
        if (isFrist(symbol)){
            //�����ǰ���������ջջջ���������Ȼ���ƽ������ջ
            symbolStack.push(symbol);
            return;
        }else {
            //����ʹ�ջ��ȡ�����ֺ�һ�������ȼ���
            int num = getCalculateResult();
            //�ٰѼ���������ջ
            numStack.push(num);

            //�ݹ飬�����Ƚ���һ���Ƿ��뵱ǰ���ŵ����ȼ�
            compareAndOperation(symbol);
        }
    }

    /**
     * �������ֺͷ������㲢���ؽ��
     * @param num1 ���ջ������
     * @param num2 �ȳ�ջ������
     * @param symbol �������
     * @return
     */
    int getCalculateResult(int num1, int num2, String symbol) {
        int result = 0;
        //���ݷ��Ž�������
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
                    throw new RuntimeException("ֻ֧�ּӼ��˳����㣡");
        }

        System.out.println(num1 + symbol + num2 + "=" + result);

        return result;
    }

    /**
     * ֱ�Ӵ���ջȡ�����֣�����ջȡһ���Ž��м���
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
     * �ȽϷ��ź͵�ǰ����ջ�����ŵ����ȼ���
     * �����ǰ�������ȼ�С�ڷ���ջջ�����ŵ����ȼ����ͷ���false�����򷵻�true
     * �����ǰ����ջΪ�գ�ֱ�ӷ���true
     * @param symbol
     * @return
     */
    boolean isFrist(String symbol) {
        //�жϵ�ǰ����ջ�Ƿ�Ϊ��
        if (symbolStack.empty()) {
            return true;
        }
        //ȡ�����Ż�ջ������
        String stackSymbol = symbolStack.pop();
        symbolStack.push(stackSymbol);

        //ջ�����ŵ����ȼ�
        int stackSymbolGrade = getSymbolGrade(stackSymbol);
        //��ǰ���ŵ����ȼ�
        int symbolgrade = getSymbolGrade(symbol);

        return symbolgrade > stackSymbolGrade;
    }

    /**
     * ���ݷ��ŷ��ط��ŵ����ȼ�
     * @param symbol
     * @return �Ӽ�����0���˳�����1
     */
    int getSymbolGrade(String symbol) {
        int grade;
        if ("+".equals(symbol) || "-".equals(symbol)) {
            grade = 0;
        } else if ("*".equals(symbol) || "/".equals(symbol)) {
            grade = 1;
        }else {
            throw new RuntimeException("��֧�ֵĲ��������ͣ�" + symbol);
        }
        return grade;
    }
}
