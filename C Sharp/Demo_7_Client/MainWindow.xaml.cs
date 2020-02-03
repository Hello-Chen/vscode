/*==============================================================================
* 类名称：MainWindow
* 类描述：
* 创建人：王伟生
* 创建时间：2015/9/2 14:25:17
* 修改人：
* 修改时间：
* 修改备注：
* 版本：v1.0.0.0
*==============================================================================
* Copyright ©  北京新大陆时代教育有限公司 2015 . All rights reserved.
*==============================================================================*/
using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;//引用IPAddress命名空间
using System.Net.Sockets;//引用Socket命名空间
using System.Text;
using System.Threading;//引用Thread命名空间
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Demo_7_Client
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }
        //实例化套接字
        Socket soc = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
        //实例化用于接收数据的byte数组
        byte[] buff = new byte[60000];
        /// <summary>
        /// 连接按钮点击事件
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnConnect_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                if (btnConnect.Content.ToString() == "连接")
                {
                    //连接，默认端口8081
                    soc.Connect(IPAddress.Parse(txtService.Text), 8081);
                    //绑定数据接收
                    soc.BeginReceive(buff, 0, buff.Length, SocketFlags.None, new AsyncCallback(ReceiveCB), soc);
                    ShowMsg("连接成功！");
                    btnConnect.Content = "断开";
                }
                else
                {
                    //断开连接，此套接字可重复使用
                    soc.Disconnect( true);
                    ShowMsg("断开成功！");
                    btnConnect.Content = "连接";
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "错误", MessageBoxButton.OK, MessageBoxImage.Error);
            }
        }

        private void ReceiveCB(IAsyncResult ar)
        {
            
                //获取异步信息
            Socket soc = (Socket)ar.AsyncState;
            //int i= soc.EndReceive(ar);
            Thread.Sleep(100);
            Dispatcher.Invoke(new Action(() =>
            {
                //将数据转为字符串
                string readData_str = Encoding.Default.GetString(buff);
                ShowMsg(" 发言人：客户端" + "时间：" + DateTime.Now.ToString() + "  IP:" + soc.RemoteEndPoint.ToString() + "  内容：" + readData_str.Replace("\0", ""));//发言人；时间；IP ；内容
            }));
               //清空接收数组
            buff = new byte[60000];
                //绑定数据接收
            try
            {
            soc.BeginReceive(buff, 0, buff.Length, SocketFlags.None, new AsyncCallback(ReceiveCB), soc);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message,"错误",MessageBoxButton.OK,MessageBoxImage.Error);

                soc.Disconnect(true);
                ShowMsg("断开成功！");
                Dispatcher.Invoke(new Action(() => {
                    btnConnect.Content = "连接";
                }));
            }
        }

        private void btnSend_Click(object sender, RoutedEventArgs e)
        {
            string sendData_str = txtMsg.Text;
            ShowMsg("发送数据：" + sendData_str);

            byte[] sendbyte = Encoding.Default.GetBytes(sendData_str);
            //发送数据
            soc.Send(sendbyte);
        }
        private void ShowMsg(string txt)
        {
            Dispatcher.Invoke(new Action(() =>
            {
                lstMsg.Items.Add(txt);
            }));
        }
    }
}
