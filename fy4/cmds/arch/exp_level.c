#include <ansi.h>
inherit F_CLEAN_UP;
inherit F_LEVEL;

int main(object me, string arg)
{
	int num;
	mapping data;
	
	if (!arg)
		return notify_fail("¸ñÊ½´íÎó£ºÇë²ì¿´°ïÖúÎÄ¼ş¡£\n");

	if (sscanf(arg, "%d/%d", num) != 1)
		return notify_fail("¸ñÊ½´íÎó£ºÇë²ì¿´°ïÖúÎÄ¼ş¡£\n");

	if ( num>0 && num <= 500)
	{
		write ("µÈ¼¶£¨"+num+"£©	»»Ëã¾­ÑéÖµ£¨"+level_to_exp(num,0)+"£©\n");
		return 1;
	}
	
	if ( num > 2000 && num < 100000000)
	{
		data = exp_to_level(num);
		
		write("¾­ÑéÖµ£¨" + num + "£©»»Ëã£º\n");
		write("	µ±Ç°µÈ¼¶ = " + data["level"] + "\n");
		write("	¸ÃµÈ¼¶ÆğÊ¼¾­Ñé = " + data["level_exp"] + "\n");
		write("	ÒÑÍê³É°Ù·ÖÊı = " + data["sub"] /10 + "." + data["sub"]%10 + "%\n");
		write("	ÕâÒ»µÈ¼¶¹²ĞèÒª¾­ÑéÖµ = " + data["next_level"] + "\n");
		
		return 1;
	}	
		
	return notify_fail("¸ñÊ½´íÎó£ºÇë²ì¿´°ïÖúÎÄ¼ş¡£\n");
}
		
int help(object me)
{
write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÎ×Ê¦Ö¸Áî¸ñÊ½ : 	exp_level [Êı×Ö][0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   
 
´ËÃüÁîÈÃÎ×Ê¦¼ì²é¾­ÑéÓëµÈ¼¶µÄ»»Ëã£¬ÔÚÃüÁîºó¸úÒ»¸öÊı×Ö£¬

Èç¹ûÊı×Ö·¶Î§ÔÚ0-500Ö®¼ä£¬½«Ä¬ÈÏÎªÊÇÓÉµÈ¼¶»»Ëã¾­Ñé£¬
Èç¹ûÊı×Ö·¶Î§2000-100000000Ö®¼ä£¬½«Ä¬ÈÏÎªÊÇÓÉ¾­Ñé»»ËãµÈ¼¶¡£

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m 
HELP	);
	return 1;
}