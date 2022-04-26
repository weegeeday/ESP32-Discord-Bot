using Discord;
using Discord.Commands;
using Discord.WebSocket;
using DiscordBotTemplate.Services;
using Microsoft.Extensions.DependencyInjection;
using System;
using System.Threading.Tasks;
using System.Windows.Forms;
using Discord.Net;
using Discord.Net.Rest;
using Discord.Net.WebSockets;
namespace DiscordBotTemplate
{
    class Program
    {
        public void task()
        {
            Console.WriteLine("hi");
            System.Threading.Thread.Sleep(3500);
        }
        
        
        private CommandService _commands;
        private DiscordSocketClient _client;
        private Configuration.Configuration _config;


        public static void Main(string[] args)
            => new Program().StartAsync().GetAwaiter().GetResult(); 


        public async Task StartAsync()
        {
            IServiceCollection services;
            IServiceProvider provider;

            try
            {
                _config = Configuration.ConfigurationReader.Load();
            }
            catch
            {
                // Catch the error and show a dialog. The error will be logged when trying to load the config
                // file anyway, so all we need to do here is to ensure that the user knows why the application crashed.
                MessageBox.Show(
                    "An error occurred whilst trying to load the configuration file. Please ensure the configuration file exists and is named correctly.",
                    "Invalid Configuration File",
                    MessageBoxButtons.OK,
                    MessageBoxIcon.Error
                );
            }

            _commands = new CommandService(
                new CommandServiceConfig
                {
                    DefaultRunMode = RunMode.Async,
                    LogLevel = LogSeverity.Verbose
                }
            );

            _client = new DiscordSocketClient(
                new DiscordSocketConfig
                {
                    LogLevel = LogSeverity.Verbose,
                    MessageCacheSize = 1000
                }
            );

            // Add singletons of all the services we will need.     //Error is here. error log is in error.md
            services = new ServiceCollection();
                 ServiceCollection().ConfigureServices((_, services) => 
                      //services.AddTransient<ITransientOperation, DefaultOperation>()
                        .AddSingleton(_client)
                        .AddSingleton(_commands)
                        .AddSingleton<CommandHandler>()
                        .AddSingleton<LoggingService>()
                        .AddSingleton<StartupService>()
                        .AddSingleton(_config));
                        //.Build();
            
            

            // Create the service provider.
            provider = new DefaultServiceProviderFactory().CreateServiceProvider(services);

            // Initialize all the services.
            provider.GetRequiredService<LoggingService>();
            await provider.GetRequiredService<StartupService>().StartAsync();
            provider.GetRequiredService<CommandHandler>();

            // Prevent the application from closing.
            await Task.Delay(-1);
        }
    }
}
