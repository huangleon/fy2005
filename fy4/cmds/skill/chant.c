// Silencer@fengyun	June.2005

#include <ansi.h>
inherit F_CLEAN_UP;

string *event1_msg=	({
	"ÓÐÏàÏà²»Ïà£¬ŸoÏàÒà²»Ïà£¬ëx±ËÏà²»Ïà£¬ÏàžéºÎËùÏà¡£\n",
	"´ËÉúÈôÎ´Éú£¬ÔÆºÎÄÜ×ÔÉú£¬ÈôÉúÒÑ×ÔÉú£¬ÒÑÉúºÎÓÃÉú¡£\n",
	"ŸôÖÐ×ÔŸoéœ£¬×¡ÌŽÒàŸoéœ£¬ÆÆéœÄËÃûÕÕ£¬ŸôžéºÎËùÕÕ¡£\n",
	"ÓÐŸoÒ»•rŸo£¬ëxŸoÓÐÒàŸo£¬²»ëxŸoÓÐÓÐ£¬ÓÐ„t‘ª³£Ÿo¡£\n",
	"ÈôÐÅÖT·¨¿Õ£¬ÊÇ„tí˜ì¶Àí£¬Èô²»ÐÅ·¨¿Õ£¬Ò»ÇÐ½Ôß`Ê§¡£\n",
	"ÈôÒÔŸoÊÇ¿Õ£¬ŸoËù‘ªÔì×÷£¬Î´×÷ÒÑÓÐ˜I£¬²»×÷ÓÐ×÷Õß¡£\n",
	"°ãÈô²¨Á_ÃÛ£¬Œ·¨²»îµ¹£¬ÄîÏëÓ^ÒÑ³ý£¬ÑÔÕZ·¨½Ôœç¡£\n",
	"ŸoÁ¿±Š×ï³ý£¬ÇåœQÐÄ³£Ò»£¬ÈçÊÇ×ðÃîÈË£¬„tÄÜÒŠ°ãÈô¡£\n",
});
	
int main(object me)
{
	int i, skill, amount;

	me = this_player();
	if (me->query("class")!="lama" && me->query("class")!= "shaolin"
		&& me->query("class")!= "bonze")
		return notify_fail("²»ÊÇºÍÉÐÄîÊ²Ã´¾­£¿\n");
	
	// usually it should be around 200 - 400
	amount = me->query_skill("zen",1)
			+ me->query_skill("lamaism",1)
			+ me->query_skill("buddhism",1);
		
	if (amount < 150)
		return notify_fail("Äã¶Ô¾­ÎÄµÄÁË½âÌ«Ç³±¡ÁË¡£¡£¡£¡£\n");
		
	if( !me->is_fighting() )
		return notify_fail("ËÐ¾­Ö»ÄÜÔÚÕ½¶·ÖÐÊ¹ÓÃ¡£\n");
	
	if (me->is_busy())
		return notify_fail("ÄãÏÖÔÚÕýÃ¦×ÅÄØ¡£\n");
	
/*	if( ANNIE_D->check_buff(me,"forceshield")) 
    	return notify_fail("ÄãÌá×ÅÒ»¿ÚÆø£¬ÔõÃ´Äî¾­°¡¡£\n");*/
       		
	if (me->query_temp("timer/chanting"))
		return notify_fail("ÄãÒÑ¾­ÔÚËÐ¾­ÁË¡£\n");

	if( userp(me) && me->query("sen") < 150 )
		return notify_fail("ËÐ¾­ÐèÒªºÄ·Ñ150µãÐÄÉñ¡£\n");
	if (userp(me))	me->receive_damage("sen", 150);
			
	me->start_busy(2);
	amount = amount/2;
	
	message_vision(HIR"$NÒ»ÊÖ³Ö·ðÖé£¬Ò»ÊÖÁ½Ö¸Çá´¥Èç½áÃÖÍÓÓ¡£¬µÍËÌ·ðºÅ£¡\n" NOR, me);
    me->set_temp("timer/chanting",1);
	call_out("dot",6,me,7,0,amount);  
	return 1;
}

void dot (object me, int total, int count, int amount)
{
	int num, my_exp, his_exp, i, enhance;
	object *ob;
	
	if (!me)	return;
		
	ob = me->query_enemy();
	if (!ob || sizeof(ob)<1) {
		message_vision(WHT"$NºÏÕÆËµµÀ£º¡°°¢ÃÖÍÓ·ð£¬Ê©Ö÷¿ÉÔøÎòÁË£¿¡±\n"NOR,me);
		me->delete_temp("timer/chanting");
		return;
	}

	message_vision(WHT"$NÄîµÀ£º"+event1_msg[count]+"\n"NOR,me);
	enhance = amount> 100 ? amount: 100;
	
    for(i=0; i<sizeof(ob); i++)   {
       	if (!living(ob[i])) continue;
		if (!ob[i]->is_fighting(me)) continue;
		if (environment(ob[i]) != environment(me)) continue;

		if (COMBAT_D->do_busy_attack(me, ob[i], "chant", "step", enhance, 10))
		{
			// for normal SL/DZ/XG, it's 100 + random(100);
			num = amount + random(amount);
			num = COMBAT_D->magic_modifier(me, ob[i], "sen", num);
			ob[i]->receive_wound("sen",num,me);	// Wound is not effective on NPCs
			
			// Every 3 turns 50% chance (same exp) it will add 400 + random(400) hate
			if (!userp(ob[i]))
				ob[i]->add_hate(me, num*3);		// chant will add *4 hate.
			
			tell_object(ob[i],RED"Äã¾õµÃÍ·Í´ÓûÁÑ£¬²îµã¶ùÔÎÁË¹ýÈ¥¡£\n"NOR);
			COMBAT_D->win_lose_check(me,ob[i],num);			
    		}
    	}
    	
	count++;
	if (count<= total) call_out("dot",6,me,total,count, amount);
		else 
		{
			message_vision(WHT"$NºÏÕÆËµµÀ£º¡°°¢ÃÖÍÓ·ð£¬Ê©Ö÷¿ÉÔøÎòÁË£¿¡±\n"NOR,me);
			me->delete_temp("timer/chanting");
		}
	return ;
}


int help(object me)
{
    write( @HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : chant[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
Äî¾­ÊÇ·çÔÆÖÐÉÙÁÖ¡¢ÐË¹ú¡¢´óÕÑ¶ÀÓÐµÄ¼¼ÄÜ£¬
Ê¹ÓÃµÄÌõ¼þÎªÃÜ×Ú·ð·¨¡¢´ó³Ë·ð¾­¡¢ìøµÀµÄµÈ¼¶Ö®ºÍ¸ßÓÚ£±£µ£°¡£
¶ÔÕâÈýÃÅ¾­ÎÄµÄÐÞÏ°Ô½Éî£¬Äî¾­µÄÐ§¹û¾ÍÔ½Ã÷ÏÔ¡£

Äî¾­ÔÚÕ½¶·ÖÐÓÐÁ½´ó¹¦Ð§£¬

£¨£±£©¶ÔÖÜÎ§µÐÈËµÄÐÄÉñµÄ×î´óÖµÔì³É³ÖÐøµÄÉËº¦
£¨£²£©ÎüÒýÖÜÎ§µÐÈËµÄ×¢ÒâÁ¦£¬·ðÔ»£ºÎÒ²»ÈëµØÓü£¬Ë­Èë£¿

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
HELP
        );
    return 1;
}



