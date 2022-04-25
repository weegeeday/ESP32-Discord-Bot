using Discord.Commands;
using System.Threading.Tasks;
using System;
using System.IO.Ports;
//write variables for if statements when we read ports, maybe? not sure if need to in .NET
namespace DiscordBotTemplate.Modules
{

    /// <summary>
    /// Defines a command module.
    /// </summary>
    [Name("CSL")]
    public class Module1 : ModuleBase<SocketCommandContext>
    {
SerialPort port = new SerialPort();


        [Command("Connect")]
        
         public async Task Connect(string[] args)
        {
            
            await ReplyAsync($"Connecting commands sent!");
            try
            {
                //connect to device
                Console.WriteLine("connecting to device");
                port = new SerialPort();
                port.BaudRate = 9600;
                port.PortName = "COM4";
                port.Open();
                Console.WriteLine("com port open");
 
            }
            catch (Exception ex)
            {
                Console.WriteLine("Encountered error while opening serial port");
                Console.WriteLine(ex.ToString());
            }
        }
    int ReadShort = 0;
    /// <summary>
        /// Gives a cookie to the current user.
        /// </summary>
        /// <returns>An awaitable task.</returns>
        [Command("Short")]
        
        public async Task Short()
        {
            
            await ReplyAsync($"Sending request to device..");
            port.Write("short");
            ReadShort = int.Parse(port.ReadLine());
            if (ReadShort is 1)
            {
                await ReplyAsync($"Request Sent!");
            } 
            else
            {
                
                await ReplyAsync($"Request failed.");
            }
            System.Threading.Thread.Sleep(1500);
            ReadShort = int.Parse(port.ReadLine());
             if (ReadShort is 2)
            {
                await ReplyAsync($"Request Done!");
            } 
            else
            {
                await ReplyAsync($"Request Didnt finish? (or timing is off).");
            }
        }

    int ReadLong = 0;
        /// <summary>
        /// Gives a cookie to the tagged user.
        /// </summary>
        /// <param name="username">The user to give a cookie to.</param>
        /// <returns>An awaitable task.</returns>
        [Command("Long")]
        
        public async Task Long()
        {
            await ReplyAsync($"Sending request to device...");
            port.Write("long");
            ReadLong = int.Parse(port.ReadLine()); 
          if (ReadLong is 3)
            {
                await ReplyAsync($"Request Sent!");
            } 
            else
            {
                await ReplyAsync($"Request failed.");
            }
            System.Threading.Thread.Sleep(2500);
            ReadLong = int.Parse(port.ReadLine());
             if (ReadLong is 4)
            {
                await ReplyAsync($"Request Done!");
            } 
            else
            {
                await ReplyAsync($"Request Didnt finish? (or timing is off).");
            }
        }

    }
}

