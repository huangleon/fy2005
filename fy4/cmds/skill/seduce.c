// silencer@fy

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string what, who;
	object ob, victim;
	mapping myfam, vtfam;
	int sp, dp;
	
	object where = environment(me);
	if ( me->query("class")!="shenshui")
	          return notify_fail("Ö»ÓĞÉñË®µÜ×Ó²ÅÄÜÊ¹ÓÃ¹´»êÊõ£¡\n");

	if (userp(me))
		return notify_fail("¹´Òı±ğÈËµÄ·½Ê½¡£¡£¡£ÕıÔÚÑĞ¾¿ÖĞ¡£\n");
		
	if( environment(me)->query("no_fight"))
		return notify_fail("ÕâÀïÊÇºÜÑÏËàµÄ³¡ºÏ£¬Äã¸ÃÖªµÀ²»ÄÜÓĞ³ö¸ñµÄ¾Ù¶¯¡£\n");

	if( me->query_temp("seducing") )
		return notify_fail("ÄãÒÑ¾­ÔÚÊ©¹´»êÊõÁË£¡\n");
	
	if( !arg || sscanf(arg, "%s from %s", what, who)!=2 ) 
		return notify_fail("Ö¸Áî¸ñÊ½£ºseduce <Ä³Îï> from <Ä³ÈË>\n");

	if ( (int)me->query_skill("nine-moon-spirit",1) < 100)
		return notify_fail("²¢²»ÊÇÃ¿¸öÅ®º¢¶¼ÄÜ³ÉÎªºüÀê¾«µÄ£¬Äã»¹ÊÇ¸ÃÇÚĞŞæ±Å®Éñ¹¦²ÅÊÇ£¨ĞèÒª100¼¶£©¡£\n");

	if( me->is_fighting() )
                return notify_fail("´ò¼ÜµÄÊ±ºò»¹¿ÉÒÔÂÒÅ×ÃÄÑÛ£¿\n");

        if(me->query("sen") <= 200)
            	return notify_fail("Äã¾«Éñ²»Õñ£¬Î¯Î¯ÃÒÃÒµÄÒ»µã²»ÎüÒıÈË¡£\n");
        if(me->query_per() < 20)
            	return notify_fail("Äã½ñÌì¿´ÆğÀ´Ò»µãÒ²²»ÎüÒıÈË£¬»¹ÊÇ»ØÈ¥ºÃºÃ´ò°çÒ»ÏÂÔÙÀ´ÊÔ°É¡£\n");

	victim = present(who, environment(me));
	if( !victim || victim == me) 
		return notify_fail("ÄãÏë¹´ÒıµÄ¶ÔÏó²»ÔÚÕâÀï¡£\n");
	
	if( !living(victim) || !objectp(victim) || victim == me)
		return notify_fail("ÄãÒª¹´ÒıË­£¿\n");

	if (userp(me))
	if (!COMBAT_D->legitimate_kill(me, victim)) {
		if (stringp(victim->query("NO_KILL")))
			return notify_fail(victim->query("NO_KILL"));
		if (stringp(victim->query("NO_PK")))
			return notify_fail(victim->query("NO_PK"));	
		else 
			return notify_fail("ÄãÎŞ·¨¹´Òı´ËÈË¡£\n");
	}
	
	if( victim->is_fighting() ) 
                return notify_fail(victim->name() + "ÕıÔÚ´ò¼Ü£¬Ã»¿ÕÀíÄã£¡\n");
	
	if( !ob = present(what, victim) ) {
		object *inv;
		inv = all_inventory(victim);
		if( !sizeof(inv) )
			return notify_fail( victim->name() + "ÉíÉÏ¿´ÆğÀ´Ã»ÓĞÊ²÷áÈÃÄã¸ĞĞËÈ¤µÄ¶«Î÷¡£\n");
		ob = inv[random(sizeof(inv))];
	}

	if (ob->query("equipped") || ob->query("no_drop") || ob->query("owner"))
		return notify_fail(victim->name()+"Ì«¿´ÖØÕâÑù¶«Î÷ÁË,ÌìÏÉÏÂ·²Ò²Ã»ÓÃ¡£\n");

        if (userp(me))	me->add("sen",-200);
        
        //	180 * 180 + 40*40*40/3 = 54000
	sp = (int)me->query_skill("nine-moon-spirit",1) * (int)me->query_skill("nine-moon-spirit",1) 
	 + (int)me->query_per()* (int)me->query_per() * me->query_per() /3;
	
	if(me->query("gender")==victim->query("gender"))
		sp = sp/3;
		
	if(victim->query("age")<12 || victim->query("age")>60)
		sp = sp/3; 
	 
	if( sp < 1 ) sp = 1;
	
	//	40* 1000 + 20000 = 60000
	dp = (int)victim->query_cps()*1000+20000;

	tell_object(me, HIG"ÄãÇáĞ¦ÁËÆğÀ´£¬ÓÃĞ¡Ã¨Ò»ÑùºÃÆæµÄÄ¿¹âî©×Å"+victim->name()+HIG"´ø×ÅµÄ"+ ob->name());
	tell_object(me, NOR MAG"\nÄã´ø×ÅÑŞÏÛµÄÉñÉ«£¬ÇáÇáÒ§ÁËÒ§ÏÂ×ì´½ ¡ª¡ª \nÄãÖªµÀ×Ô¼ºÒÑ¾­×ã¹»ÁË£¬ÈôÓĞÊ²Ã´ÈË»¹²»¶®ÄãµÄÒâË¼£¬ÄÇÈËÒ»¶¨ÊÇ°×³Õ¡£\n\n"NOR);

	tell_object(victim, HIG+ me->name() + HIG"ÒøÁå°ãµÄÇáĞ¦Éù´«ÈëÄã¶úÖĞ£¬ÄãÏòËı¿´È¥¡£\n"NOR);
	tell_object(victim,MAG"ËıµÄÑÛ¾¦»áËµ»°£¬ËıµÄÃÄĞ¦»áËµ»°£¬¾ÍËãÊÇÏ¹×Ó£¬Ò²¿ÉÒÔÎÅµÃµ½ËıÉíÉÏÉ¢·¢³öµÄ\nÄÇÒ»ÂÆÂÆÌğÏã£¬Ò²¿ÉÒÔÌıµÃµ½ËıÄÇÏú»êµ´ÆÇµÄÇ³Ğ¦¡£\n\n"NOR);
	tell_object(victim,MAG"ËıËÆºõ¶ÔÄãµÄ"+ob->name()+NOR MAG"ºÜ¸ĞĞËÈ¤¡£\n"NOR);
	
	message("vision", HIG"Ö»Ìı"+me->name()+HIG"ÇáĞ¦ÁËÆğÀ´£¬ÓÃĞ¡Ã¨Ò»ÑùºÃÆæµÄÄ¿¹âî©×Å"NOR+victim->name()+"¡£\n"NOR,environment(me), ({ me, victim }) );
	message("vision", MAG+me->name()+ MAG"µÄÑÛ¾¦»áËµ»°£¬ËıµÄÃÄĞ¦»áËµ»°£¬¾ÍËãÊÇÏ¹×Ó£¬Ò²¿ÉÒÔÎÅµÃµ½ËıÉíÉÏÉ¢·¢³öµÄ\nÄÇÒ»ÂÆÂÆÌğÏã£¬Ò²¿ÉÒÔÌıµÃµ½ËıÄÇÏú»êµ´ÆÇµÄÇ³Ğ¦¡£\n"NOR,environment(me), ({ me, victim }) );
	message("vision", YEL + me->name()+ YEL"ËÆºõºÜ¸ĞĞËÈ¤"+ victim->name()+"ÉíÉÏ´øµÄÊ²Ã´¶«Î÷¡£\n\n"NOR,environment(me), ({ me, victim }) );
	
	me->set_temp("seducing", 1);
	call_out("compelete_seduce",random(3)+1, me, victim, ob, sp, dp);

	return 1;

}




private void compelete_seduce(object me, object victim, object ob, int sp, int dp)
{
	int amount;
	object ob1;

	me->delete_temp("seducing");
	if(!objectp(victim)) { 
			tell_object(me, "°×ÀË·Ñ¸ĞÇéÁË£¬ÄãÒª¹´ÒıµÄÈËÒÑ¾­²»¼ûÁË¡£\n");
		return;
	}
	
	if( environment(victim) != environment(me) ) {
		tell_object(me, "°×ÀË·Ñ¸ĞÇéÁË£¬ÄãÒª¹´ÒıµÄÈËÒÑ¾­²»¼ûÁË¡£\n");
		return;
	}
// not a human being
	if(!victim->query("spi")) {
		tell_object(me,victim->name()+"¸ù±¾¾ÍÎŞ¶¯ÓÚÖÔ£¡\n");
		return;
	}
	
	if (!present(ob, victim)) {
		tell_object(me, "ÄãÏëÒªµÄ¶«Î÷ÒÑ¾­²»ÔÚ"+victim->name()+"ÉíÉÏÁË¡£\n");
		return;
	}
	
	// exp limit to stop beggar dummies
	if (victim->query("combat_exp")> me->query("combat_exp")* 5) {
		message_vision(NOR"\n$NÒ»¸±¿á¿áµÄÑù×Ó£¬¸ù±¾²»ÔÚºõ$n·Ñ¾¡ĞÄ»úµÄÓÕ»ó¡£\n"NOR, victim, me);
		return;
	}
	
	if( living(victim) && (random(sp+dp) > dp) && ob->move(me)) 
	{
		message_vision(YEL"$N³Õ³ÕµØÍû×Å$n£¬»ĞÈ»¼ä¾ÍÃ÷°×ÁË$nµÄÒâË¼£¬ÂíÉÏ°Ñ" 
				+ ob->query("unit") + ob->name() + YEL"½»µ½$nÊÖÀï¡£\n
\n$NÁ³ÉÏÏÖ³öÑóÑó×ÔµÃµÄÉñÆø£¬ºÃÏñÔÚËµ£ºÈç´ËÉÆ½â¼ÑÈËµÄ´óÇéÊ¥£¬ÉáÎÒÆäË­£¿\n\n"NOR,victim,me);
		me->start_busy(3);
	} 
	else 
	{
		if( random(sp+dp) > dp*3/4 && random (4)>1) {
                	message_vision(YEL"$NÍû×ÅÔ¶´¦,ËÆºõ¸ù±¾¾ÍÃ»×¢Òâµ½$n¡£\n"NOR, victim,me);
                	me->start_busy(3);
			return;
		}
		else
			message_vision(YEL"$NºİºİµØµÉÁË$nÒ»ÑÛ£¬ºÈµÀ£º´óµ¨ÑıÅ®,¾¹¸ÒÔÚ´ËÎŞÀñ£¡\n"NOR, victim,me);
		if(!environment(victim)->query("no_fight"))	
			victim->fight_ob(me);
		me->start_busy(3);
	}
}



int help(object me)
{
write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : 	seduce <¶«Î÷> from <ËûÈË>[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

ÕâÊÇÉñË®µÜ×Ó×¨ÓÃµÄÖ¸Áî£¬ÀûÓÃ×Ô¼ºµÄ÷ÈÁ¦ÈÃ±ğÈËĞÄ¸ÊÇéÔ¸µØ°Ñ¶«Î÷¸øÄã¡£
³É¹¦ÂÊÓë¶Ô·½µÄĞÔ±ğ¡¢ÄêÁä¡¢×ÔÉíµÄ÷ÈÁ¦ÒÔ¼°æ±Å®Éñ¹¦µÄ¼¶±ğÏà¹Ø¡£

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   
HELP
    );
    return 1;
}
