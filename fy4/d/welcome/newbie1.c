
inherit ROOM;
#include <ansi.h>

void create ()
{
  	set ("short", HIC"·çÔÆÌ¨"NOR);
  	set ("long", @LONG
ÃÔã¯Ö®ÖÐ£¬ÄãÀ´µ½ÕâÆ¬ÄªÃûµÄ´óÂ½£¬ÓÄ³¤¹ÅÀÏµÄÊ¯Ì¨ËÄ±ÚÉÏËÆºõ¿ÌÂúÁËÒ»Ð©Éú
ÊèÍáÐ±µÄÎÄ×Ö£º¼×ÐçÄêÈýÔÂ³õÈý£¬Ð¡ÀîÑ°»¶Ï§±ð°®ÂÂÊ«Òô£¬Ô¶¸°¾©³ÇÓ¦ÊÔ£¬Ìâ¼ÇÓÚ
´Ë¡£¡££»ÐÁÎ´ÄêÀ°ÔÂÊ®Èý£¬ÍçÍ¯ÁôÏã£¬Ìú»¨£¬±ùÑàÔÚ´Ë½á°Ý½ðÀ¼£¬Í¬´³½­ºþ£¡£¬¸ý
ÎçÄêÆßÔÂ³õÆß£¬ÏôÊ¯ÒÝ×Ô´ËÒþÃûÏôÊ®Ò»ÀÉ£¬´óµÁÏôÊ®Ò»ÀÉ£¡¡£¡£¶øÔÚ²»ÆðÑÛµÄÇ½±Ú
Ò»Óç£¬¿Ì×ÅÒ»ÐÐ½ð×Ö£º	[41;1m·çÔÆôß³ö£¬Ë­ÓëÕù·æ[2;37;0m
			
LONG);

 	set("no_magic",1);
	set("no_fight",1);
  	set("exits", ([ /* sizeof() == 1 */
  		"down" : __DIR__"newbie2",
  		
	]));
  
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",950);
  	
  	setup();
  
}
