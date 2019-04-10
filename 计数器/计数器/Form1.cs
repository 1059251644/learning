using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Collections;

namespace 计数器
{
    public partial class Form1 : Form
    {
        
        
        private ArrayList value_list = new ArrayList();
        
        private bool reshult_flag = false;//=按下 
        private bool add_flag = false;//+按下     
        private bool minus_flag = false;//-按下      
        private bool multi_flag = false;//×按下   
        private bool div_flag = false;//÷按下   
        private bool can_operate_flag = false;//按下=是否响应

        
        public Form1()
        {
            InitializeComponent();

        }
        private void Button14_Click(object sender, EventArgs e)
        {
            if (!div_flag)
            {
               
                div_flag = true;
                Num_down("/");
               
            }

        }

        private void Button13_Click(object sender, EventArgs e)
        {
            if (!multi_flag)
            {
                
                multi_flag = true;
                Num_down("*");
            }
        }

        private void Button12_Click(object sender, EventArgs e)
        {
            if(!minus_flag)
            {
                
                minus_flag = true;
                Num_down("-");
            }
            

        }

        private void Button10_Click(object sender, EventArgs e)
        {
            if (!add_flag)//防止用户多次输入一个符号键，符号键只允许输入一次   
            {
                add_flag = true;
                Num_down("+");
                
                
            }
        }

        private void Num_down(string num)
        {
            if (num.Equals("+")|| num.Equals("-") || num.Equals("*") || num.Equals("/") )
            {
                if(reshult_flag)
                {
                    textBox1.Text = textBox2.Text;
                }
                value_list.Add(textBox2.Text);
                value_list.Add(num);
                textBox1.Text += num;
                add_flag = false;
                minus_flag = false;
                multi_flag = false;
                div_flag = false;
                can_operate_flag = false;
                reshult_flag = false;
                
                textBox2.Clear();

               
                

            }
            else 
            { 
                textBox1.Text += num;
                textBox2.Text += num;
                can_operate_flag = true;
            }

        }



      
        private void Button15_Click(object sender, EventArgs e)//清空
        {
            value_list.Clear();
            add_flag = false;
            minus_flag = false;
            multi_flag = false;
            div_flag = false;
            can_operate_flag = false;
            textBox2.Text="";
            textBox1.Text = "";

            
        }
        
        private static  int Level(string s)
        {
            int i = 0;
            i = NewMethod(s, i);
            return i;
        }

        private static int NewMethod(string s, int i)
        {
            switch (s)
            {
                case "#": i = 1; break;
                case "+":
                case "-": i = 2; break;
                case "*":
                case "/": i = 3; break;
            }

            return i;
        }

       /* private static void Calc(Stack st,Stack sk)
        {
            

        }*/
       
        private void Button17_Click(object sender, EventArgs e)//输出结果
        {

           
           Stack sk = new Stack();//数字栈
           Stack st = new Stack();//符号栈
            value_list.Add(textBox2.Text);
           if (value_list.Count>0&& can_operate_flag==true&& !reshult_flag)
           {
                
                if (value_list.Count==1)
                {
                    sk.Push(value_list[0].ToString());
                }
                else if(value_list.Count>2)
                {

                    for (int i = 0; i < value_list.Count; i++)
                    {
                        string s = value_list[i].ToString();
                        if (s.Equals("+") || s.Equals("-") || s.Equals("*") || s.Equals("/"))
                        {

                            if (st.Count == 0)
                            {
                                st.Push(s);
                            }

                            else
                            {
                                string c = (string)st.Peek();
                                int item = Level(value_list[i].ToString()).CompareTo(Level(c));
                                if (item > 0)
                                {
                                    st.Push(s);
                                }
                                else
                                {
                                    double rightnum = Convert.ToDouble(sk.Pop());
                                    double lefttnum = Convert.ToDouble(sk.Pop());
                                    string oper = (string)st.Pop();
                                    switch (oper)
                                    {
                                        case "+":
                                            sk.Push((rightnum + lefttnum).ToString());
                                            break;
                                        case "-":
                                            sk.Push((rightnum - lefttnum).ToString());
                                            break;
                                        case "*":
                                            sk.Push((rightnum * lefttnum).ToString());
                                            break;
                                        case "/":
                                            sk.Push((rightnum / lefttnum).ToString());
                                            break;
                                    }
                                    st.Push(s);
                                }

                            }
                        }
                        else 
                        {
                            sk.Push(value_list[i].ToString());
                        } 
                    }
                   
                }
                if (sk.Count > 1 && st.Count>0) { }
                while (st.Count > 0)
                {
                    double rightnum = Convert.ToDouble(sk.Pop());
                    double lefttnum = Convert.ToDouble(sk.Pop());
                    string oper = (string)st.Pop();
                    switch (oper)
                    {
                        case "+":
                            sk.Push((rightnum + lefttnum).ToString());
                            break;
                        case "-":
                            sk.Push((lefttnum - rightnum).ToString());
                            break;
                        case "*":
                            sk.Push((rightnum * lefttnum).ToString());
                            break;
                        case "/":
                            sk.Push((lefttnum / rightnum).ToString());
                            break;
                    }
                }
                textBox2.Text = (string)sk.Pop();
                value_list.Clear();
                reshult_flag = true;



            }
           
            

        }
        private void Button16_Click(object sender, EventArgs e)//撤回
        {
            textBox1.Text = textBox1.Text.Substring(0, textBox1.Text.Length - 1);
            textBox2.Text = textBox2.Text.Substring(0, textBox2.Text.Length - 1);
        }


        private void Button1_Click_1(object sender, EventArgs e)
        {
            Num_down("1");

        }

        private void TextBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void Button2_Click(object sender, EventArgs e)
        {
            Num_down("2");

        }

        private void Button3_Click(object sender, EventArgs e)
        {
            Num_down("3");

        }

        private void Button4_Click(object sender, EventArgs e)
        {
            Num_down("4");

        }

        private void Button5_Click(object sender, EventArgs e)
        {
            Num_down("5");

        }

        private void Button6_Click(object sender, EventArgs e)
        {
            Num_down("6");

        }

        private void Button7_Click(object sender, EventArgs e)
        {
            Num_down("7");

        }

        private void Button8_Click(object sender, EventArgs e)
        {
            Num_down("8");

        }

        private void Button9_Click(object sender, EventArgs e)
        {
            Num_down("9");

        }

        private void Button11_Click(object sender, EventArgs e)
        {
            Num_down("0");

        }
        private void Button18_Click(object sender, EventArgs e)
        {
            Num_down(".");

        }

        private void Btns_Click(object sender, EventArgs e)
        {
            throw new NotImplementedException();
        }

        private void Button1_Click(object sender, EventArgs e)
        {

        }

        private void Panel1_Paint(object sender, PaintEventArgs e)
        {
             
        }

        private void Panel3_Paint(object sender, PaintEventArgs e)
        {

        }

    }
}
