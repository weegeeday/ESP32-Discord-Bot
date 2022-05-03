""""
Copyright © Krypton 2021 - https://github.com/kkrypt0nn (https://krypt0n.co.uk)
Description:
This is a template to create your own discord bot in python.

Version: 4.1
"""

import json
import os
import platform
import random
import sys
import helpers
import aiohttp
import disnake
import serial
import Serial
from disnake import ApplicationCommandInteraction, Option, OptionType
from disnake.ext import commands
from helpers import checks
ser = serial.Serial('COM4')
print(ser.name) 
shortread = ser.read()
if not os.path.isfile("config.json"):
    sys.exit("'config.json' not found! Please add it and try again.")
else:
    with open("config.json") as file:
        config = json.load(file)


class General(commands.Cog, name="general-slash"):
    def __init__(self, bot):
        self.bot = bot

    @commands.slash_command(
        name="botinfo",
        description="Get some useful (or not) information about the bot.",
    )
    @checks.not_blacklisted()
    async def botinfo(self, interaction: ApplicationCommandInteraction) -> None:
        """
        Get some useful (or not) information about the bot.
        :param interaction: The application command interaction.
        """
        embed = disnake.Embed(
            description="h",
            color=0x9C84EF
        )
        embed.set_author(
            name="h"
        )
        embed.add_field(
            name="h:",
            value="h",
            inline=True
        )
        embed.add_field(
            name="Python Version:",
            value=f"{platform.python_version()}",
            inline=True
        )
        embed.add_field(
            name="Prefix:",
            value=f"/ (Slash Commands) or {config['prefix']} for normal commands",
            inline=False
        )
        embed.set_footer(
            text=f"Requested by {interaction.author}"
        )
        await interaction.send(embed=embed)

    @commands.slash_command(
        name="ping",
        description="Check if the bot is alive.",
    )
    @checks.not_blacklisted()
    async def ping(self, interaction: ApplicationCommandInteraction) -> None:
        """
        Check if the bot is alive.
        :param interaction: The application command interaction.
        """
        embed = disnake.Embed(
            title="🏓 Pong!",
            description=f"The bot latency is {round(self.bot.latency * 1000)}ms.",
            color=0x9C84EF
        )
        await interaction.send(embed=embed)

    @commands.slash_command(
        name="invite",
        description="Get the invite link of the bot to be able to invite it.",
    )
    @checks.not_blacklisted()
    async def invite(self, interaction: ApplicationCommandInteraction) -> None:
        """
        Get the invite link of the bot to be able to invite it.
        :param interaction: The application command interaction.
        """
        embed = disnake.Embed(
            description=f"Invite me by clicking [here](https://discordapp.com/oauth2/authorize?&client_id={config['application_id']}&scope=bot+applications.commands&permissions={config['permissions']}).",
            color=0xD75BF4
        )
        try:
            # To know what permissions to give to your bot, please see here: https://discordapi.com/permissions.html and remember to not give Administrator permissions.
            await interaction.author.send(embed=embed)
            await interaction.send("I sent you a private message!")
        except disnake.Forbidden:
            await interaction.send(embed=embed)

    @commands.slash_command(
        name="8ball",
        description="Ask any question to the bot.",
        options=[
            Option(
                name="question",
                description="The question you want to ask.",
                type=OptionType.string,
                required=True
            )
        ],
    )
    @checks.not_blacklisted()
    async def eight_ball(self, interaction: ApplicationCommandInteraction, question: str) -> None:
        """
        Ask any question to the bot.
        :param interaction: The application command interaction.
        :param question: The question that should be asked by the user.
        """
        answers = ["bruh"]
        embed = disnake.Embed(
            title="**My Answer:**",
            description=f"{random.choice(answers)}",
            color=0x9C84EF
        )
        embed.set_footer(
            text=f"The question was: {question}"
        )
        await interaction.send(embed=embed)

    @commands.slash_command(
        name="short",
        description="short",
    )
    @checks.not_blacklisted()
    async def short(self, interaction: ApplicationCommandInteraction) -> None:
        """
        short
        """
        ser.write(b'short')
        async with ser.read() as shortread:
                if shortread == 1:
                    embed = disnake.Embed(
                        title="Sent",
                        color=0x9C84EF
                    )
                else: # leave this alone
                    embed = disnake.Embed(
                        title="Error!",
                        description="There is something wrong with the API, Or i fucked up.",
                        color=0xE02B2B
                    )
                await interaction.send(embed=embed)



def setup(bot):
    bot.add_cog(General(bot))
