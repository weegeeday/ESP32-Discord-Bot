from discord.ext import commands
import serial
ser = serial.Serial()
ser.baudrate = 9600
ser.port = 'COM4'
print(ser.name) 
lshortread = 0
mshortread = 0
hshortread = 0
llongread = 0
mlongread = 0
hlongread = 0
arg1 = 0
arg2 = 0
S1 = 0
S2 = 0
lmedread = 0
mmedread = 0
hmedread = 0
class misc(commands.Cog):
    def __init__(self, bot):
        self.bot = bot
        self._last_member = None

    @commands.command()
    async def Lshort(self, ctx, msg):
        ser.open()
        ser.write(b'lshort')
        ser.read() == lshortread
        if lshortread == 1:
            await ctx.send(f"Sent!")
        while lshortread == 1:
            ser.read() == lshortread
        await ctx.send(f"Done!")
        
    @commands.command()
    async def Mshort(self, ctx, msg):
        ser.open()
        ser.write(b'mshort')
        ser.read() == mshortread
        if mshortread == 1:
            await ctx.send(f"Sent!")
        while mshortread == 1:
            ser.read() == mshortread
        await ctx.send(f"Done!")
        
    @commands.command()
    async def Hshort(self, ctx, msg):
        ser.open()
        ser.write(b'hshort')
        ser.read() == hshortread
        if hshortread == 1:
            await ctx.send(f"Sent!")
        while hshortread == 1:
            ser.read() == hshortread
        await ctx.send(f"Done!")

    @commands.command()
    async def llong(self, ctx, msg):
        ser.open()
        ser.write(b'llong')
        ser.read() == llongread
        if llongread == 1:
            await ctx.send(f"Sent!")
        while llongread == 1:
            ser.read() == llongread
        await ctx.send(f"Done!")
        
    @commands.command()
    async def mlong(self, ctx, msg):
        ser.open()
        ser.write(b'mlong')
        ser.read() == mlongread
        if mlongread == 1:
            await ctx.send(f"Sent!")
        while mlongread == 1:
            ser.read() == mlongread
        await ctx.send(f"Done!")
        
    @commands.command()
    async def hlong(self, ctx, msg):
        ser.open()
        ser.write(b'hlong')
        ser.read() == hlongread
        if hlongread == 1:
            await ctx.send(f"Sent!")
        while hlongread == 1:
            ser.read() == hlongread
        await ctx.send(f"Done!")   
     
    @commands.command()
    async def SETVAL(self, ctx, arg1, arg2):
        ser.open()
        ser.write(b"SV")
        ser.read() == S1
        while S1 == 0:
            ser.read() == S1 
        ser.write(arg1)
        while S1 == 1:
            ser.read() == S1
        ser.write(arg2)
        while S1 == 2:
            ser.read() == S1
        ser.read() == S2
        await ctx.send(f"Sent!")
        while S2 == 4:
            ser.read() == S2
        await ctx.send(f"Done!")  
    
    @commands.command()
    async def lmedium(self, ctx):
        ser.open()
        ser.writre(b"lmed")
        ser.read() == lmedread
        if lmedread == 1:
            await ctx.send(f"Sent!")
        while lmedread == 1:
            ser.read() == lmedread
        await ctx.send(f"Done!")
            
    @commands.command()
    async def mmedium(self, ctx):
        ser.open()
        ser.writre(b"mmed")
        ser.read() == mmedread
        if mmedread == 1:
            await ctx.send(f"Sent!")
        while mmedread == 1:
            ser.read() == mmedread
        await ctx.send(f"Done!")
            
    @commands.command()
    async def hmedium(self, ctx):
        ser.open()
        ser.writre(b"hmed")
        ser.read() == hmedread
        if hmedread == 1:
            await ctx.send(f"Sent!")
        while hmedread == 1:
            ser.read() == hmedread
        await ctx.send(f"Done!")

def setup(bot):
    bot.add_cog(misc(bot))
