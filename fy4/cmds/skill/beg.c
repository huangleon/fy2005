// TIE@FY3
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	string what, who;
	object ob, victim;
	mapping myfam, vtfam;
	int sp, dp,lvl;

	object where = environment(me);
    
    
    if (userp(me) && me->query("class")!="beggar" )
       	return notify_fail("Ö»ÓÐØ¤°ïµÜ×Ó²ÅÄÜÆòÌÖ£¡\n");

	if (userp(me))
    	return notify_fail("ÄÏ¹¬ÁéÕû¶Ù°ï¼Í£¬ÔÝÊ±²»×¼Ø¤°ïµÜ×ÓºúÂÒÆòÌÖÁË£¡\n");
    
	if( environment(me)->query("no_beg")
	 || environment(me)->query("no_fight"))
	 	return notify_fail("ÕâÀï²»ÊÇÊÊºÏØ¤°ïµÜ×ÓÌÖ·¹µÄµØ·½£¡\n");

	if( me->query_temp("begging") )
		return notify_fail("ÄãÒÑ¾­ÔÚÏò±ðÈËÆòÌÖÁË£¡\n");

	if( !arg || sscanf(arg, "%s from %s", what, who)!=2 ) return
		notify_fail("Ö¸Áî¸ñÊ½£ºbeg <Ä³Îï> from <Ä³ÈË>\n");

	if ( userp(me) && ((int)me->query_skill("begging",1) < 25))
		return notify_fail("ÆòÌÖÖÁÉÙÐèÒª£²£µ¼¶ÆòÌÖÖ®Êõ¡£\n");
	
	victim = present(who, environment(me));
	if( !victim || victim == me) return notify_fail("ÄãÏëÆòÌÖµÄ¶ÔÏó²»ÔÚÕâÀï¡£\n");

	if( !living(victim) || !objectp(victim))
		return notify_fail("ÄãÒªÏòË­ÆòÌÖ£¿\n");

        if ( (vtfam = victim->query("family")) && vtfam["family_name"] == "Ø¤°ï" )
                return notify_fail("Äã²»ÄÜÏò±¾°ïµÜ×ÓÆòÌÖ£¡\n");

	if( !wizardp(me) && wizardp(victim) )
		return notify_fail("²»ÄÜÏò¹ÜÀíÈËÔ±ÆòÌÖ¡£\n");

	if (userp(me))
	if (!COMBAT_D->legitimate_kill(me, victim)) {
		if (stringp(victim->query("NO_KILL")))
			return notify_fail(victim->query("NO_KILL"));
		if (stringp(victim->query("NO_PK")))
			return notify_fail(victim->query("NO_PK"));	
		else 
			return notify_fail("ÄãÎÞ·¨Ïò´ËÈËÆòÌÖ¡£\n");
	}
	
	if( me->is_fighting() )
                return notify_fail("²»¿ÉÒÔÒ»±ß´ò¼ÜÒ»±ßÆòÌÖ£¡\n");

	if( victim->is_fighting() )
                return notify_fail(victim->name() + "ÕýÔÚ´ò¼Ü£¬Ã»¿ÕÀíÄã£¡\n");

	if( !ob = present(what, victim) ) {
		object *inv;
		inv = all_inventory(victim);
		if( !sizeof(inv) )
			return notify_fail( victim->name() + "ÉíÉÏ¿´ÆðÀ´Ã»ÓÐÊ²÷áÈÃÄã¸ÐÐËÈ¤µÄ¶«Î÷¡£\n");
		ob = inv[random(sizeof(inv))];
	}

	if (ob->query("equipped") || ob->query("no_drop") || ob->query("owner"))
		return notify_fail(victim->name()+"ºÃÏó²»»áÊ©Éá¸øÄãÈÎºÎ¶«Î÷ËÆµÄ¡£\n");
        
        if(me->query("sen") <= 100 && userp(me))
            	return notify_fail("ÆòÌÖÐèÒªºÄ·ÑÒ»¶¨µÄÐÄÉñ£¨100£©¡£\n");
        if (userp(me))
        	me->add("sen",-100);

	lvl = me->query_skill("begging",1);
	
	// 200 * 200 + 55*55*55/3 = 95450
	// 60*1000 + score + bellicosity
	// The formula doesn't really make sense... 
	// Let's just say, you can improve your chance, but whom you can beg easily is pure chance.
			
	sp = (lvl * lvl + me->query_kar()* me->query_kar()* me->query_kar()/3)/10;
        dp = victim->query_cps()*1000 
        	+ victim->query("score") + victim->query("bellicosity");
        
	tell_object(me, "ÄãÒ»Á³¿ÉÁ¯°Í°ÍµÄÑù×Ó£¬ÂýÂýµØÏò" + victim->name() + "×ß¹ýÈ¥£¬Éì³öË«ÊÖ£¬ÏëÒª"
			+ ob->query("unit") + ob->name() +"¡­¡­\n\n");
	tell_object(victim, me->name() + "Ò»Á³¿ÉÁ¯Ïà£¬ÏòÄãÂýÂý×ß¹ýÀ´£¬Éì³öÊÖ£¬ËµµÀ£º" + RANK_D->query_respect(victim) + "ÐÐÐÐºÃ£¬¸øÎÒ"
			+ ob->query("unit") + ob->name() + "°É¡­¡­£¡\n\n");
	message("vision", "Ö»¼û" + me->name() + "×°³ö¿ÉÁ¯°Í°ÍµÄÑù×Ó£¬ÂýÂýµØÏò"
		+ victim->name() + "×ß¹ýÈ¥£¬\nÉì³öË«ÊÖ£¬ËµµÀ£º"
		+ RANK_D->query_respect(victim) + "£¬ÐÐÐÐºÃ°É¡­¡­\n\n", environment(me), ({ me, victim }) );

	if (wizardp(me))
		tell_object(me, "the begging chance is " + sp + " vs " + dp + "\n");
	me->set_temp("begging", 1);
	call_out( "compelete_beg",random(3)+1, me, victim, ob, sp, dp);

	return 1;
}

private void compelete_beg(object me, object victim, object ob, int sp, int dp)
{
	int amount;
	object ob1;

	if (!me)	return;
		
	me->delete_temp("begging");
	if(!victim) {
                tell_object(me, "Ì«¿ÉÏ§ÁË£¬ÄãÒªÆòÌÖµÄÈËÒÑ¾­²»¼ûÁË¡£\n");
                return;
        }
	if( environment(victim) != environment(me) ) {
		tell_object(me, "Ì«¿ÉÏ§ÁË£¬ÄãÒªÆòÌÖµÄÈËÒÑ¾­×ßÁË¡£\n");
		return;
	}
// exp limit to stop beggar dummies
	if (userp(me) && victim->query("combat_exp")>me->query("combat_exp")*10) {
		tell_object(me,victim->name()+"²»Ð¼µØ¿´ÁËÄãÒ»ÑÛËµ£º¡°ÔÙÈ¥Á·Á·°É¡£¡°\n");
		return;
	}

	if (!ob || !present(ob, victim)) {
		tell_object(me, "ÄãÏëÒªµÄ¶«Î÷ÒÑ¾­²»ÔÚ"+victim->name()+"ÉíÉÏÁË¡£\n");
		return;
	}
	
// not a human being
	if(victim->query("race")!="ÈËÀà") {
		tell_object(me,victim->name()+"¸ù±¾¾ÍÎÞ¶¯ÓÚÖÔ£¡\n");
		return;
	}
	if( living(victim) && (random(sp+dp) > dp) && ob->move(me))
	{
		message_vision("$N¿´×Å$nµÄ¿ÉÁ¯Ñù£¬Ì¾ÁË¿ÚÆø£¬¶ª¸ø$nÒ»"
			+ ob->query("unit") + ob->name() + "¡£\n",victim,me);
		me->start_busy(3);
	}
	else
	{
		if( random(sp+dp) > dp/2 ) {
                	message_vision("$NÅ¤¹ýÍ·È¥£¬¶Ô$nÀí¶¼²»Àí¡£\n", victim,me);
                	me->start_busy(3);
			return;
		}
		
		message_vision("$NºÝºÝµØµÉÁË$nÒ»ÑÛ£¬ºÈµÀ£ºÇî½Ð»¯×Ó£¡ÕæÌÖÑá£¡²»´ò²»ÐÐÁË£¡\n", victim,me);
		if(!environment(victim)->query("no_fight"))
			victim->fight_ob(me);
		me->start_busy(3);
	}
}

int help(object me)
{
write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : 	beg <¶«Î÷> from <ËûÈË>[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

ÕâÊÇÒ»¸öØ¤°ï×¨ÓÃµÄÖ¸Áî£¬ÓÃÀ´ÏòËûÈËÆòÌÖÎïÆ·£¬ÆòÌÖµÄ³É¹¦ÂÊÓëÆòÌÖÕß
µÄÔËÆø¡¢ÆòÌÖÖ®ÊõµÄ¸ßµÍ¡¢ÒÔ¼°Ë«·½µÄ½­ºþ¾­ÑéÏà¹Ø¡£
²»¹ý£¬×ÔÄÏ¹¬Áé½ÓÕÆ°ïÖ÷Ö®Î»ºó£¬Õû¶Ù°ï¼Í£¬²»×¼Ø¤°ïµÜ×ÓºúÂÒÆòÌÖÁË¡£

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   
HELP
    );
    return 1;
}
