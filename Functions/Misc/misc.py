from discord.ext import commands
from http.server import BaseHTTPRequestHandler, HTTPServer
import time
import logging
import settings
import web
hostName = settings.hostname
serverPort = settings.port
ser = web.MyServer(hostName, serverPort, BaseHTTPRequestHandler)
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
        ser.write(b'lshort')
        ser.do_POST() == lshortread
        if lshortread == 1:
            await ctx.send(f"Sent!")
        while lshortread == 1:
            ser.do_POST() == lshortread
        await ctx.send(f"Done!")
        
    @commands.command()
    async def Mshort(self, ctx, msg):
        ser.write(b'mshort')
        ser.do_POST() == mshortread
        if mshortread == 1:
            await ctx.send(f"Sent!")
        while mshortread == 1:
            ser.do_POST() == mshortread
        await ctx.send(f"Done!")
        
    @commands.command()
    async def Hshort(self, ctx, msg):
        ser.write(b'hshort')
        ser.do_POST() == hshortread
        if hshortread == 1:
            await ctx.send(f"Sent!")
        while hshortread == 1:
            ser.do_POST() == hshortread
        await ctx.send(f"Done!")

    @commands.command()
    async def llong(self, ctx, msg):
        ser.write(b'llong')
        ser.do_POST() == llongread
        if llongread == 1:
            await ctx.send(f"Sent!")
        while llongread == 1:
            ser.do_POST() == llongread
        await ctx.send(f"Done!")
        
    @commands.command()
    async def mlong(self, ctx, msg):
        ser.write(b'mlong')
        ser.do_POST() == mlongread
        if mlongread == 1:
            await ctx.send(f"Sent!")
        while mlongread == 1:
            ser.do_POST() == mlongread
        await ctx.send(f"Done!")
        
    @commands.command()
    async def hlong(self, ctx, msg):
        ser.write(b'hlong')
        ser.do_POST() == hlongread
        if hlongread == 1:
            await ctx.send(f"Sent!")
        while hlongread == 1:
            ser.do_POST() == hlongread
        await ctx.send(f"Done!")   
     
    @commands.command()
    async def SETVAL(self, ctx, arg1, arg2):
        ser.write(b"SV")
        ser.do_POST() == S1
        while S1 == 0:
            ser.do_POST() == S1 
        ser.write(arg1)
        while S1 == 1:
            ser.do_POST() == S1
        ser.write(arg2)
        while S1 == 2:
            ser.do_POST() == S1
        ser.do_POST() == S2
        await ctx.send(f"Sent!")
        while S2 == 4:
            ser.do_POST() == S2
        await ctx.send(f"Done!")  
    
    @commands.command()
    async def lmedium(self, ctx):
        ser.write(b"lmed")
        ser.do_POST() == lmedread
        if lmedread == 1:
            await ctx.send(f"Sent!")
        while lmedread == 1:
            ser.do_POST() == lmedread
        await ctx.send(f"Done!")
            
    @commands.command()
    async def mmedium(self, ctx):
        ser.write(b"mmed")
        ser.do_POST() == mmedread
        if mmedread == 1:
            await ctx.send(f"Sent!")
        while mmedread == 1:
            ser.do_POST() == mmedread
        await ctx.send(f"Done!")
            
    @commands.command()
    async def hmedium(self, ctx):
        ser.write(b"hmed")
        ser.do_POST() == hmedread
        if hmedread == 1:
            await ctx.send(f"Sent!")
        while hmedread == 1:
            ser.do_POST() == hmedread
        await ctx.send(f"Done!")

def setup(bot):
    bot.add_cog(misc(bot))
