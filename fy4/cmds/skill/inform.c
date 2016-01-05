// - by neon
#include <ansi.h>
inherit F_CLEAN_UP;
void move_team(object me,object ob);
int main(object me, string arg)
{
	string what, who;
	object ob, *team, beggar;
	int i, delay;
	object where = environment(me);
        if ( me->query("class")!="beggar" )
          	return notify_fail("Ö»ÓĞØ¤°ïµÜ×Ó²ÅÄÜ·É¸ë´«Êé£¡\n");

	if ( (int)me->query_skill("begging",1)<185)
	{
		return notify_fail("·É¸ë´«ÊéÖÁÉÙĞèÒª185¼¶ÆòÌÖÖ®Êõ¡£\n");
	}
	
	if( !arg ) return
		notify_fail("Ö¸Áî¸ñÊ½£ºinform <Ä³ÈË> \n");

	// Only two 
	beggar= present("beggar courier",environment(me));
//	write (sprintf("%O\n",beggar));
	if (!beggar)
		return notify_fail("ÕâÀïÃ»ÓĞØ¤°ïĞÅÊ¹£¬ÎŞ·¨·É¸ë´«Êé¡£\n");
	
	if (!beggar->query("inform_target"))	
		return notify_fail("ÕâÀïÃ»ÓĞØ¤°ïµÄĞÅÊ¹£¬ÎŞ·¨·É¸ë´«Êé¡£\n");
		
	if(me->is_busy())
		return notify_fail("ÄãÏÖÔÚÕıÔÚÃ¦£¡\n");

	if(me->query_temp("inform_in_progress") )
		return notify_fail("ÄãµÄĞÅ¸ëÕıÔÚ½ÓÒı¶ÓÓÑ£¡\n");

	
	if( !pointerp(team = me->query_team()) )  
		return notify_fail("Äã²¢Ã»ÓĞÈÎºÎ¶ÓÓÑ£¡\n");
		
	ob = find_player(arg);
	if (!ob || ob == me) return notify_fail("ÄãÒª·É¸ë´«Êé¸øË­£¿\n");
	for ( i=0; i<sizeof(team); i++) {
		if (team[i]==ob ) break;
	}
	if (i == sizeof(team)) return notify_fail("·É¸ë²»ÄÜ´«Êé¸ø¶ÓÎéÒÔÍâµÄÈË¡£\n");
// Now start to summon 
	if (environment(ob) == environment(me)) 
		return notify_fail(ob->name() + "ÒÑ¾­ÔÚÄãÉí±ßÁË£¡\n");

	if (me->query("gin")<500)
		return notify_fail("·É¸ë´«ÊéĞèÒªºÄ·Ñ500µã¾«Á¦¡£\n");
	if (userp(me))	me->receive_damage("gin",500);
        
    message_vision("$NÔÚÂúÁ³·çËªµÄÀÏÆòØ¤¶ú±ßµÍÓï¼¸¾ä¡£\n", me);
    message_vision(WHT"$NºöÈ»Ò»¾ÙÊÖ£¬Ò»Ö»°×É«µÄĞÅ¸ëÌÚ¿Õ¶øÆğ£¬ÔÚÕñÓğÉùÖĞ·ÉÏòÔ¶·½¡£\n"NOR, beggar);
    me->set_temp("inform_in_progress", 1);
	
	if (environment(ob)->query("no_fight") ||environment(ob)->query("no_magic")
		|| environment(ob)->query("no_fly") || environment(ob)->query("no_death_penalty")) {
		message_vision(WHT"\nµ«ÊÇ£¬ĞÅ¸ëÔÚÔ¶·½ÅÌĞıÁËÒ»»á¶ù£¬ÓÖ·É»Ø$NÊÖÀï¡£\n"NOR, me);	
		me->delete_temp("inform_in_progress", 1) ;
		write("ĞÅ¸ëÎŞ·¨·¢ÏÖÄãµÄ¶ÓÓÑ£¡\n");
		return 1;
	}
	
	if (ob->is_busy() || ob->is_fighting() || ob->is_ghost() ) {
		message_vision(WHT"\nµ«ÊÇ£¬ĞÅ¸ëÔÚÔ¶·½ÅÌĞıÁËÒ»»á¶ù£¬ÓÖ·É»Ø$NÊÖÀï¡£\n"NOR, me);	
		me->delete_temp("inform_in_progress", 1);
		write(ob->name()+"ËÆºõÃ»ÓĞ¿ÕÏĞÀ´½ÓÊÕĞÅ¸ë¡£\n");
		return 1;
	}
	
	message_vision(WHT"Ò»Ö»°×É«µÄĞÅ¸ëºöÈ»·ÉÀ´£¬ÔÚ$NÍ·¶¥ÉÏÏÂ·É¶¯£¬Ò»¸öÅÌĞı£¬ÏòÔ¶´¦·ÉÈ¥¡£\n$NÃæÉ«Ò»Áİ£¬Á¢¿ÌÕ¹¿ªÇá¹¦£¬×·Ëæ·É¸ë¶øÈ¥¡£\n"NOR, ob);	
    tell_object(ob, "\n ... \nÄã¼Ó¿ì½Å²½£¬ÔÚĞÅ¸ëÖ¸ÒıÏÂÏòÇ°¼±±¼¡£\n");    	
	ob->start_busy(2);
	me->start_busy(2);
	call_out("move_team",3, me,ob); 	
	return 1;	
}


void move_team(object me, object ob){
	
	if (!ob||!me) return;
	message_vision(WHT"ĞÅ¸ë»®¹ıÒ»µÀ°×É«µÄ»¡Ïß£¬·É»Øµ½$NÊÖÀï¡£"YEL"$nÔÚºóÃæ´Ò´Ò¸Ïµ½¡£\n"NOR, me, ob);	
	ob->move(environment(me));
	me->delete_temp("inform_in_progress", 1);
}


int help(object me)
{
write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : 	inform <ËûÈË>[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

·É¸ë´«Êé£¬ÕâÊÇÒ»¸öØ¤°ï×¨ÓÃµÄÖ¸Áî£¬¿ÉÒÔºô»½¶ÓÓÑµÄ°ïÖú¡£
·É¸ë´«ÊéĞèÒª185¼¶µÄÆòÌÖÖ®Êõ£¬±ØĞëÔÚØ¤°ïĞÅÊ¹Éí±ßÊ¹ÓÃ¡£

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   
HELP
    );
    return 1;
}
