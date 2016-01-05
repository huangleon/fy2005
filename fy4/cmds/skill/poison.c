// poison ÔÚÎäÆ÷ÉÏÏÂ¶¾¡£Sillencer@fy4 

#include <ansi.h>
inherit SSERVER;

int main (object me, string arg)
{
	object ob, herb;
    	int skill;
    	string h_name, obname;
	function f;
	
    	if(me->query("class")!="knight")
    		return notify_fail("Ö»ÓÐ¿ì»îÁÖµÜ×Ó²ÅÄÜ¹»¶Ô±øÆ÷È¾¶¾¡£\n");

	skill = me->query_skill("dream-herb",1);
	if (skill < 75 || me->query_skill("herb")< 75)
		return notify_fail("¶Ô±øÆ÷È¾¶¾ÖÁÉÙÐèÒª75¼¶µÄÔÆÃÎÎå»¨½õºÍÒ©µÀ¡£\n");

	if(!arg)
		return notify_fail("ÄãÒªÍùÊ²Ã´±øÆ÷ÉÏÃæ¸½¼ÓÊ²Ã´Ò©²Ý?\n");
	
	if(sscanf(arg,"%s %s",obname,h_name)!=2)
		return notify_fail("¸ñÊ½ÊÇ poison <±øÆ÷Ãû> <Ò©²ÝÃû> \n");
		
	if(!objectp(herb = present(h_name,me)))
		return notify_fail("ÄãÉíÉÏÃ»ÓÐÕâÖÖÒ©²Ý¡£\n");
		
	if(!objectp(ob=present(obname,this_player())))
		return notify_fail("ÄãÉíÉÏÃ»ÓÐÕâ¼þÎäÆ÷¡£\n");
	
	if(!ob->query("weapon_prop"))
		return notify_fail(ob->name()+"²»ÊÇ±øÆ÷¡£\n");
	
	if (herb->query("type")!= "poison" || herb->query("material")!="herb")
		return notify_fail("ÕâÖÖÒ©²Ý²»ÄÜÔÚÎäÆ÷ÉÏÈ¾¶¾¡£\n");
	
	if (ob->query("skill_type") == "unarmed")
		return notify_fail("È¾¶¾²»ÄÜÊ¹ÓÃÔÚ²«»÷µÄÎäÆ÷ÉÏ¡£\n");
	
	if (herb->query("level")> skill)
		return notify_fail("ÄãµÄÔÆÃÎÎå»¨½õµÈ¼¶Ì«µÍ£¬»¹²»ÄÜÕÆÎÕÕâÖÖÒ©²ÝµÄÌØÐÔ¡£\n");
		
	if (ob->query_temp("hit_ob",1))
		return notify_fail(ob->name()+"ÉÏÒÑ¾­ÓÐÌØÊâÌØÐÔÁË¡£\n");
		
	if (me->query("timer/apply_poison") + 10 > time())
		return notify_fail("Ðª¿ÚÆøÔÙÈ¾¶¾°É¡£\n");
	
	if (me->is_busy())
		return notify_fail("ÄãÏÖÔÚÕýÃ¦¡£\n");
	
		
	f = (:call_other,"/obj/proc/proc_herb","hit_ob":);
	if(!functionp(f))
		return notify_fail("¸½¼ÓÊ§°Ü£¬ÇëÍ¨ÖªÎ×Ê¦¼ì²é¡£\n");
		
	ob->set_temp("hit_ob",bind(f,ob));
	ob->set_temp("herb/owner", me);
	ob->set_temp("herb/proc_rate",herb->query("proc"));
	ob->set_temp("herb/proc_amount",herb->query("effect"));
	ob->set_temp("herb/proc_type",herb->query("field"));
	
	if(ob->query_temp("hit_ob",1))
	{
		message_vision(HIB"$NÐ¡ÐÄÒíÒíµØ×¥ÆðÒ»Æ¬"+herb->name()+ HIB"Ò¶£¬ÔÚ"+ob->name()+HIB"µÄ¿ª¿Ú´¦Ä¨ÁËÒ»±é£¬\n"
				+ob->name() + HIB"µÄ·æÈÐÍ¸³ö°µÀ¶É«µÄ¹âÃ¢¡£\n"NOR, me);
	}
	else 
		tell_object(me,"¸½¼ÓÊ§°Ü£¬ÇëÍ¨ÖªÎ×Ê¦¼ì²é¡£\n");
	herb->add_amount(-1);
	call_out("remove_effect",180,ob);	// 3min duration, only owner can apply
	me->set("timer/apply_poison",time());
	me->perform_busy(1);
	return 1;
}


int remove_effect(object weapon)
{
	object holder;
	if(!weapon)	return 1;
	
	holder = environment(weapon);
	if(!holder) return 1;
	
	if(interactive(holder))	
		message_vision(CYN""+weapon->name()+CYN"µÄ·æÈÐÂýÂý»Ö¸´ÁËÕý³£µÄ¹âÔó¡£\n"NOR,holder);
	else	
		message("vision",CYN""+weapon->name()+CYN"µÄ·æÈÐÂýÂý»Ö¸´ÁËÕý³£µÄ¹âÔó¡£\n"NOR,holder);
	weapon->delete_temp("herb");
	weapon->delete_temp("hit_ob");
	return 1;
}


int help(object me)
{
	write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : 	poison <±øÆ÷Ãû> <Ò©²ÝÃû> [0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   
¿ì»îÁÖµÜ×ÓµÄ×¨³¤£¬ÀûÓÃÒ©²ÝÔÚ±øÆ÷ÉÏÏÂ¶¾¡££¨Ðè75¼¶ÔÆÃÎÎå»¨½õºÍÒ©µÀ£©¡£
ÔÚ´ò¶·ÖÐÈç¹û»÷ÖÐ¶Ô·½£¬ÔòÓÐÒ»¶¨¼¸ÂÊ£¨»ù´¡£µ£°£¥£©ÈÃ¶Ô·½ÊÜµ½¶îÍâÉËº¦¡£

££ÐÄÉñÉËº¦Ò©²Ý£º
ÎÞÐÄº£ÌÄ£¨L75¡¢-75£©µ¥ÐÄº£ÌÄ£¨L110¡¢-150£©ÈýÐÄº£ÌÄ£¨L150¡¢-200£©
ÎåÐÄº£ÌÄ£¨L180¡¢-250£©ÆßÐÄº£ÌÄ£¨L200¡¢-300£©

££ ÆøÑªÉËº¦Ò©²Ý£º
À¶»¨Éß²Ý£¨L75¡¢-75£©ÂÌ»¨Éß²Ý£¨L110¡¢-150£©°×»¨Éß²Ý£¨L150¡¢-200£©
»Æ»¨Éß²Ý£¨L180¡¢-250£©ºì»¨Éß²Ý£¨L200¡¢-300£©

££¾«Á¦ÉËº¦Ò©²Ý£º
ó¿ËÚ·Û£¨L75¡¢-75£©ó¿ËÚÒ¶£¨L110¡¢-150£©ó¿ËÚÄ©£¨L150¡¢-200£©
ó¿ËÚÝà£¨L180¡¢-250£©ó¿ËÚ¹û£¨L200¡¢-300£©

ÉÏÃæÇ°Ò»¸öÊý×ÖÊ±ËùÐèÔÆÃÎÎå»¨½õµÈ¼¶£¬ºóÒ»¸öÊÇÉËº¦ÊýÖµ¡£
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   
 
HELP
    );
    return 1;
}
 