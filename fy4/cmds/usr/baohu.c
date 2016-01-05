// user list
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me,string arg)
{
	string id, id2;
	object obj, old_obj,*pros,*pros_real;
	int i, remove_me;
	
	if (!arg)
		return notify_fail("Ö¸Áî¸ñÊ½ : baohu <¶ÔÏó>\n");
	
	if (userp(me))
	{
		if(!stringp(id=me->query("marry")))
			return notify_fail("ÄãºÃÏó²¢Ã»ÓĞ½á»é£¡\n");
		if(me->query("jiebai"))
			return notify_fail("ÄãºÃÏó²¢Ã»ÓĞ½á»é£¡\n");
			
		if (!objectp(obj=present(arg,environment(me))))
			return notify_fail("Õâ¶ùÓĞÕâ¸öÈËÂğ£¿\n");
		if(id!= arg)
			return notify_fail(obj->name()+"ºÃÏó²¢²»ÊÇÄãµÄ"+(me->query("gender") == "Å®ĞÔ" ? "ÕÉ·ò":"ÆŞ×Ó")+"£¡\n");
		id2 = obj->query("marry");
		if( id2 != me->query("id"))
			return notify_fail(obj->name()+"ºÃÏó²¢²»ÊÇÄãµÄ"+(me->query("gender") == "Å®ĞÔ" ? "ÕÉ·ò":"ÆŞ×Ó")+"£¡\n");
		
		if (obj->query("divorced"))
			return notify_fail("ÄãĞÄÄîÒ»¶¯£¬ÏëÆğ"+obj->name(1)+"¾ÉÈÕÖ®ÇéÊÂ£¬²»ÓÉõÜõîÆğÀ´¡£\n");
			
		pros = obj->query_temp("protectors");
		remove_me =0;
		for(i=0;i<sizeof(pros);i++)
			if(pros[i] == me) 
			{
			 pros -= ({ me });
			 remove_me =1;
			}
		if (remove_me) {
			me->delete_temp("protecting");
			obj->set_temp("protectors",pros);
			return notify_fail("ÄãÍ£Ö¹±£»¤ÄãµÄ"+(me->query("gender") == "Å®ĞÔ" ? "ÕÉ·ò":"ÆŞ×Ó")+obj->name()+"ÁË£¡\n");	
		}
	
		if(sizeof(pros))
			pros += ({ me });
		else
			pros = ({ me });
		obj->set_temp("protectors",pros);
		write("Äã¿ªÊ¼±£»¤ÄãµÄ"+(me->query("gender") == "Å®ĞÔ" ? "ÕÉ·ò":"ÆŞ×Ó")+obj->name()+"¡£\n");
		me->set_temp("protecting",obj);
		return 1;
	} else
	{
		if (!objectp(obj=present(arg,environment(me))))
			return notify_fail("Õâ¶ùÓĞÕâ¸öÈËÂğ£¿\n");	
		if (!userp(obj))
			return notify_fail("ÄãÖ»ÄÜ±£»¤Íæ¼Ò¡£\n");
		if (obj == me)
			return notify_fail("±£»¤×Ô¼º£¿ºÃÖ÷Òâ£¡\n");
		
		// È¥³ı¾ÉµÄ±£»¤¶ÔÏó¡£	
		if (objectp(old_obj = me->query_temp("protecting")))
		{
			if (old_obj == obj)
				return notify_fail("ÄãÒÑ¾­ÔÚ±£»¤"+ obj->name()+ "ÁË¡£\n");
			pros = old_obj->query_temp("protectors");
			remove_me =0;
			for(i=0;i<sizeof(pros);i++)
			if(pros[i] == me) 
			{
		 		pros -= ({ me });
		 		remove_me =1;
			}	
			old_obj->set_temp("protectors",pros);
		}
		
		// Clean up a bit.lazy to count :D
		pros = obj->query_temp("protectors");
		for(i=0;i<sizeof(pros);i++)	
		{
			if(pros[i] == me) 
				pros -= ({ me });
		}
		
		if (sizeof(pros))
			pros += ({ me });
		else
			pros = ({ me });
		
		pros_real = ({});
		for(i=0;i<sizeof(pros);i++)	
		{
			if (pros[i])
				pros_real += ({ pros[i] });
		}
		
		me->set_temp("protecting", obj);
		obj->set_temp("protectors",pros_real);
	
		write("Äã¿ªÊ¼±£»¤"+obj->name()+"¡£\n");
		return 1;
	}
}

int help(object me)
{
write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : 	baohu <¶ÔÏó>[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

ÕâÊÇÒÑ»é·ò¸¾ÓÃÀ´±£»¤¶Ô·½£¨ÆŞ×Ó£¯ÕÉ·ò£©µÄÖ¸Áî
µ±Äã³ÉÎª±£»¤ÕßÊ±£¬Äã¿ÉÒÔÓÃ×Ô¼º¸ß³¬µÄ²ğÕĞ¼¼ÄÜÀ´±£»¤
×Ô¼ºµÄÍ¬°é£¬Ìæ¶Ô·½²ğ¼ÜµĞÈËµÄ¹¥»÷¡£

×¢Òâ£º
£¨£±£©±£»¤°éÂÂÊ±£¬×ÔÉíÒ²±ØĞëÔÚ±ÈÎäÕ½¶·ÖĞ¡£
£¨£²£©Àë»éÔÙ»éºóÓĞ»éÊ·µÄÒ»·½²»ÄÜÏíÊÜ´ËÓÅ»İ¡£

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m 
HELP
    );
    return 1;
}
