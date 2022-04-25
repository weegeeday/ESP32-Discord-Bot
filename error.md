
Unhandled Exception: System.ArgumentNullException: Value cannot be null.
Parameter name: implementationInstance
   at Microsoft.Extensions.DependencyInjection.ServiceCollectionServiceExtensions.AddSingleton[TService](IServiceCollection services, TService implementationInstance)
   at DiscordBotTemplate.Program.<StartAsync>d__5.MoveNext() in C:\Users\simon\Downloads\Discord-Bot-Template-master\Discord-Bot-Template-master\Discord-Bot-Template-master\DiscordBotTemplate\Program.cs:line 71
--- End of stack trace from previous location where exception was thrown ---
   at System.Runtime.ExceptionServices.ExceptionDispatchInfo.Throw()
   at System.Runtime.CompilerServices.TaskAwaiter.HandleNonSuccessAndDebuggerNotification(Task task)
   at System.Runtime.CompilerServices.TaskAwaiter.GetResult()
   at DiscordBotTemplate.Program.Main(String[] args) in C:\Users\simon\Downloads\Discord-Bot-Template-master\Discord-Bot-Template-master\Discord-Bot-Template-master\DiscordBotTemplate\Program.cs:line 29
