// team.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
		object *t,*t1, *players;
		int i, me_exp, ob_exp, num, num1, n, max_exp, min_exp;

//		First remove those 1-man bogus team, mostly due to unclean code.
		if (sizeof(me->query_team())<2) 	me->dismiss_team();

//		¶ÓÎéÁĞ±í
	
		if( !arg ) {
			if( !pointerp(t = me->query_team()) )
				return notify_fail(WHT"ÄãÏÖÔÚ²¢Ã»ÓĞ²Î¼ÓÈÎºÎ¶ÓÎé¡£\n"NOR);
			write(WHT"ÄãµÄ¡°"+ me->query_temp("team_name") + "¡±ÖĞµÄ³ÉÔ±ÓĞ£º\n  "NOR + implode(t->name(1), "\n  ") + "¡£\n"NOR);
			return 1;
		}

//		½âÉ¢¶ÓÎé»òÍÑÀë¶ÓÎé
		if( arg=="dismiss" ) {
			if( !pointerp(t = me->query_team()) )
				return notify_fail(WHT"ÄãÏÖÔÚ²¢Ã»ÓĞ²Î¼ÓÈÎºÎ¶ÓÎé¡£\n"NOR);
			if( me->is_team_leader() ) {
				message("team", WHT""+me->name(1) + "½«¶ÓÎé½âÉ¢ÁË¡£\n"NOR, t, me);
				write(WHT"Äã½«¶ÓÎé½âÉ¢ÁË¡£\n"NOR);
			} else {
				message("team", WHT""+me->name(1) + "¾ö¶¨ÍÑÀë¶ÓÎé¡£\n"NOR, t, me);
				write(WHT"ÄãÍÑÀëÁËÄãµÄ¶ÓÎé¡£\n"NOR);
			}
			me->dismiss_team();
			return 1;
		}

//		¶ÓÎéÃüÃû¡£
		if (sscanf (arg, "name %s", arg) == 1) {
			if (!me->is_team_leader())
				return notify_fail(WHT"Ö»ÓĞÁì¶ÓÈË²ÅÄÜ¹»ÃüÃû¶ÓÎéÃû³Æ¡£\n");
			if( !pointerp(t = me->query_team()) )
				return notify_fail(WHT"ÄãÏÖÔÚ²¢Ã»ÓĞ²Î¼ÓÈÎºÎ¶ÓÎé¡£\n"NOR);
			if (sizeof(arg)>14)
				return notify_fail(WHT"ÆìºÅ×î¶àÎªÁù¸ö×Ö¡£\n"NOR);
			
			if (userp(me) && me->query_temp("timer/team_name") + 4 > time())
				return notify_fail(WHT"ÄãµÄÆìºÅ±äµÃÌ«Æµ·±ÁË£¬µÈÒ»·ÖÖÓ°É¡£\n"NOR);
			players = filter_array(livings(), (: userp($1):));
			num = sizeof(players);
			while (num--)
				if (players[num]->query_temp("team_name") == arg)
					return notify_fail("Õâ¸öÆìºÅÒÑ¾­ÓĞÈËÔÚÊ¹ÓÃÁË¡£\n");
			me->set_temp("timer/team_name",time());
			for(i=0; i<sizeof(t); i++) {
				t[i]->set_temp("team_name",arg);
				tell_object(t[i],YEL"ÄãµÄ¶ÓÎéÆìºÅ¸ÄÎª¡°"+arg+YEL"¡±¡£\n"NOR);
			}			
			return 1;
		
		}			
		


//		¿ª³ı¶ÓÎéÖĞÄ³Ò»ÈË	
		if(sscanf(arg, "dismiss %s", arg) == 1) {
			object ob;
			ob = find_player(arg);
			if(!ob || !me->visible(ob)){
				return notify_fail(WHT"Ã»ÓĞÕâ¸öÈË....¡£\n"NOR);
			}
			if( !pointerp(t = me->query_team()) )
				return notify_fail(WHT"ÄãÏÖÔÚ²¢Ã»ÓĞ²Î¼ÓÈÎºÎ¶ÓÎé¡£\n"NOR);
			if( !me->is_team_leader() ) {
				return notify_fail(WHT"Äã²»ÊÇÁì¶ÓÈË¡£\n"NOR);
			} else if ( me->is_team_leader() && me==ob) {
				return notify_fail(WHT"½âÉ¢¶ÓÎéÖ±½ÓÊ¹ÓÃteam dismiss£¬·ñÔòÇëÏÈÖ¸¶¨ÏÂÈÎÁì¶Ó£¨team promote£©\n"NOR); 
			} else { 
				for(i=0; i<sizeof(t); i++) {
					if(t[i]->name() == ob->name()){
						if (me==ob) {
							message("team", WHT""+me->name(1) + "½«¶ÓÎé½âÉ¢ÁË¡£\n"NOR, t, me);
							write(WHT"Äã½«¶ÓÎé½âÉ¢ÁË¡£\n"NOR);
						} else {
							message("team", WHT""+me->name(1) + "¾ö¶¨°Ñ" + ob->name()+ "Ìß³ö¶ÓÎé¡£\n"NOR, t, me);
							write(WHT"Äã¾ö¶¨°Ñ" + ob->name() + "Ìß³ö¶ÓÎé¡£\n"NOR);
							tell_object(ob,WHT"Äã±»ÄãµÄ¶ÓÎé¿ª³ı¡£\n"NOR);
						}
						ob->dismiss_team();
						return 1;
					}
				} 
				return notify_fail(WHT""+ob->name() + "²»ÔÚÄãµÄ¶ÓÎéÖĞ¡£\n"NOR);
			}
			return 1;
		}

//		×ªÈÃÊ×Áì

		if (sscanf(arg,"promote %s", arg) == 1) {
			object ob, bb;
			ob = find_player(arg);
			if(!ob || !me->visible(ob)){
				return notify_fail(WHT"Ã»ÓĞÕâ¸öÈË....¡£\n"NOR);
			}
			if( !pointerp(t = me->query_team()) )
				return notify_fail(WHT"ÄãÏÖÔÚ²¢Ã»ÓĞ²Î¼ÓÈÎºÎ¶ÓÎé¡£\n"NOR);
			if( !me->is_team_leader() ) {
				return notify_fail(WHT"Äã²»ÊÇÁì¶ÓÈË£¬ÎŞ·¨×ªÈÃÁì¶Ó¡£\n"NOR);
			}  else if ( me == ob) {
				return notify_fail(WHT"ÄãÒÑ¾­ÊÇÁì¶ÓÈËÁË¡£\n"NOR);
			} else if (me->team_member(ob)){ 
				me->switch_team_member(me,ob);
				me->tell_team(me,WHT""+ me->name(1) + "½«Áì¶ÓÈ¨½»¸øÁË" + ob->name(1)+"¡£\n"NOR);	
				return 1;
			}	
			return notify_fail(WHT""+ob->name() + "²»ÔÚÄãµÄ¶ÓÎéÖĞ¡£\n"NOR);
		}

//		ÑûÇëÈë¶Ó¡£

		if( sscanf(arg, "with %s", arg)==1 ) {
			object ob;
			if( !(ob = present(arg, environment(me)))
				||	!living(ob)
				||	!ob->is_character()
				||	ob==me )
					return notify_fail(WHT"ÄãÏëºÍË­³ÉÎªâ·°é£¿\n"NOR);
		
			if (sizeof(ob->query_team())<2) 	ob->dismiss_team();
		
		//	(1) ¼ì²éÊÇ·ñºÏ·¨ 	

			ob_exp = ob->query("combat_exp");
			me_exp = me->query("combat_exp");
			n = 3;
			
			// ÕâÖ»ÊÇÒ»¸ö¼òµ¥µÄ¼ì²é£¬ºóÃæ¶¼»á¸´²é
			if (pointerp(t=me->query_team())) {		// If Me is in a team
				if (!me->is_team_leader())
					return notify_fail(WHT"Ö»ÓĞ¶ÓÎéÁìĞä¿ÉÒÔÑûÇë±ğÈË¼ÓÈë¡£\n"NOR);
				else if (sizeof(me->query_team())>5)
			// else if (sizeof(me->query_team())>7)
					return notify_fail(WHT"¶ÓÎé×î¶àÊÇÁù¸öÈË¡£\n"NOR);
			} 
			
			if( !pointerp(me->query_team()) || me->is_team_leader()) {
				//	£¨1£©AÑûÇëB£¬ÕæÕıµÄ¼ì²é·¢ÉúÔÚ µ±BÔÙ´ÎÊäÈëteam with A Ê±
				if( me==(object)ob->query_temp("pending/team") ) {
					//	ÔÚ¼ÓÈëÊ±¼ì²é
					if (me->query_team())
						return notify_fail(WHT"ÄãÒÑ¾­¼ÓÈëÁËÒ»¸ö¶ÓÎéÁË¡£\n"NOR);				
					if (pointerp(t1 = ob->query_team())) {	// ¼ÓÈëÒ»¸ö¶ÓÎé
						// If Ob is in a team
						if (sizeof(t1)>=6)
			        //         	if (sizeof(t1)>=8)
							return notify_fail(WHT"¶Ô·½µÄ¶ÓÎéÒÑ¾­³¬¹ı×î´óÈËÊıÁù¸öÁË¡£\n"NOR);
						if (!ob->is_team_leader())
							return notify_fail(WHT"¶Ô·½²»ÊÇÁì¶Ó£¬ÎŞ·¨ÑûÇëÄã¼ÓÈë¡£\n"NOR);
						
						num= sizeof(t1);
						max_exp = 0;
						min_exp = 15000000;
						while(num--) {
							if (t1[num]->query("combat_exp")> max_exp)
								max_exp = t1[num]->query("combat_exp");
						//	if (t1[num]->query("combat_exp") < min_exp)
						//		min_exp = t1[num]->query("combat_exp");
						}
						num= sizeof(t1);
						while (num--) {
							if (t1[num]->query("quest") && max_exp < me->query("combat_exp"))
								return notify_fail(WHT"Äã²»ÄÜ¼ÓÈëÒ»¸öÓĞÎ´Íê³ÉÈÎÎñµÄµÍµÈ¼¶¶ÓÎé¡£\n"NOR);
							if (me->query("quest") && me->query("combat_exp") < max_exp)
								return notify_fail(WHT"Íê³É×Ô¼ºÈÎÎñÇ°£¬Äã²»ÄÜ¼ÓÈëÒ»¸öµÈ¼¶±ÈÄã¸ßµÄ¶ÓÎé¡£\n"NOR);
							if (n*t1[num]->query("combat_exp")<me_exp 
								|| t1[num]->query("combat_exp")+ 2000000< me_exp)
								return notify_fail(WHT"¶Ô·½¶ÓÎéºÍÄãµÄµÈ¼¶Ïà±ÈµÍÌ«¶àÁË¡£\n"NOR);
							if (t1[num]->query("combat_exp")>n*me_exp 
								|| t1[num]->query("combat_exp")> me_exp+ 2000000)
								return notify_fail(WHT"¶Ô·½¶ÓÎéµÄµÈ¼¶±ÈÄã¸ßµÄÌ«¶àÁË¡£\n"NOR);	
						}
						
					} else	{	// ¼ÓÈëÒ»¸ö¸öÈË 
						if (n* ob_exp <me_exp 
							|| ob_exp + 2000000< me_exp)
								return notify_fail(WHT"¶Ô·½µÄµÈ¼¶±ÈÄãµÍÌ«¶àÁË¡£\n"NOR);
						if (ob_exp > n*me_exp 
							|| ob_exp > me_exp+ 2000000)
							return notify_fail(WHT"¶Ô·½µÈ¼¶±ÈÄã¸ßµÄÌ«¶àÁË¡£\n"NOR);	
						if (ob->query("quest") && ob_exp < me_exp)
							return notify_fail("Äã²»ÄÜ¼ÓÈëÒ»¸öÓĞÎ´Íê³ÉÈÎÎñµÄµÍµÈ¼¶¶ÓÎé¡£\n");		
						if (me->query("quest") && ob_exp > me_exp)
							return notify_fail("Íê³É×Ô¼ºÈÎÎñÇ°£¬Äã²»ÄÜ¼ÓÈëÒ»¸öµÈ¼¶±ÈÄã¸ßµÄ¶ÓÎé¡£\n");
					}				
													
					if( !pointerp(me->query_team()) ) {
						ob->add_team_member(me);
						message_vision(WHT"$N¾ö¶¨¼ÓÈë$nµÄ¡°"+me->query_temp("team_name")+"¡±¡£\n"NOR, me, ob);
					} else {
						me->add_team_member(ob);
						message_vision(WHT"$N¾ö¶¨ÈÃ$n¼ÓÈë¶ÓÎé¡£\n"NOR, me, ob);
						tell_object(ob,YEL"ÄãµÄ¶ÓÎéÆìºÅÊÇ"+ me->query_temp("team_name")+"¡£\n");
					}
					ob->delete_temp("pending/team");
					return 1;
				} else {	// £¨2£©¿ªÊ¼ÑûÇë£¬ÕâÀïÃ»Ê²Ã´ĞèÒª´ó¼ì²éµÄ£¬
					if(pointerp(ob->query_team())) {	//¼ì²éBÊÇ·ñÒÑÓĞ¶ÓÎé¡£
						if (!pointerp(me->query_team()) || sizeof(me->query_team())<2)
							return notify_fail(ob->name()+"ÒÑ¾­ÊôÓÚ±ğµÄ¶ÓÎéÁË£¬ÊÔ×ÅÈÃËûÃÇÑûÇëÄã£¿\n");
						if (member_array(ob, me->query_team())== -1)
							return notify_fail(ob->name()+"ÒÑ¾­ÊôÓÚ±ğµÄ¶ÓÎéÁË£¬ÄãÁíÍâÔÙÕÒÈË°É¡£\n");
						else
							return notify_fail(ob->name()+"ÒÑ¾­ÔÚÄãµÄ¶ÓÎéÖĞÁË¡£\n");
					}
					message_vision(WHT"$NÑûÇë$n¼ÓÈë$PµÄ¶ÓÎé¡£\n"NOR, me, ob);
					tell_object(ob, YEL"Èç¹ûÄãÔ¸Òâ¼ÓÈë£¬ÇëÓÃ team with " + me->query("id") + "¡£\n" NOR);
					me->set_temp("pending/team", ob);
					return 1;
				}
			} else
				return notify_fail(WHT"Ö»ÓĞ¶ÓÎéÁìĞä¿ÉÒÔÑûÇë±ğÈË¼ÓÈë¡£\n"NOR);
		}
        
	
		if( sscanf(arg, "talk %s", arg)==1 )   {
			t= me->query_team();
	        if( !pointerp(t) )
	           	return notify_fail("ÄãÏÖÔÚ²¢Ã»ÓĞºÍ±ğÈË×é³É¶ÓÎé¡£\n");
			for(i=0; i<sizeof(t) ; i++)
				if (!objectp(t[i])) return notify_fail("ÄãĞèÒªÖØĞÂ×éºÏ¶ÓÎé¡£\n");
			t -= ({ 0 });
			if (sizeof(t)==1)
				return notify_fail("ÄãµÄ¶ÓÎéÀïÖ»ÓĞÄã×Ô¼ºÁË¡£\n");	
	        return CHANNEL_D->do_channel(me, "teamtalk", arg);
		}

	
/*	if( sscanf(arg, "form %s", arg)==1 ) {
		if( !pointerp(t=me->query_team()) || !me->is_team_leader() )
			return notify_fail("Äã±ØĞëÊÇÒ»¸ö¶ÓÎéµÄÁìĞä²ÅÄÜ×éÖ¯ÕóĞÎ¡£\n");
		if( !me->query_skill(arg, 1) )
			return notify_fail("ÕâÖÖÕóĞÎÄãÃ»Ñ§¹ı¡£\n");
		return SKILL_D(arg)->form_array(me);
	}*/
}





int help(object me)
{
	write(@HELP

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
¶ÓÎéÖ¸ÁîÊ¹ÓÃ·½·¨:

team with <Ä³ÈË> - ¸úÄ³ÈË×é³É¶ÓÎé. ±ØĞëÒªË«·½¶¼Í¬Òâ¼ÓÈë²Å»áÉúĞ§¡£
team name <Ä³Ãû> - ¶ÓÎéÁì¶Ó¿É¸ü¸Ä´Ë¶ÓÎéµÄÆìºÅ¡£
team dismiss     - Àë¿ª¶ÓÎé. ÈôÏÂ´ËÖ¸ÁîµÄÊÇÁì¶Ó, ÔòÕû¸ö¶ÓÎé»á½âÉ¢¡£
team dismiss <Ä³ÈË> - ¶ÔÎéµÄÁì¶Ó¿ÉÒÔËæÊ±¿ª³ı¶ÓÎéÖĞµÄÄ³ÈË¡£
team promote <Ä³ÈË> - ¶ÓÎéµÄÁì¶Ó¿ÉÒÔ°ÑÁì¶Ó×ªÈÃ¸ø¶ÓÎéÖĞµÄÄ³ÈË
team talk <Ñ¶Ï¢> - ¸ú¶ÓÎéÀïÆäËûµÄÈËÌ¸»°, ¿ÉÒÔÓÃ tt <Ñ¶Ï¢> Ìæ´ú¡£

Ö±½ÓÏÂ team Ö¸ÁîÊ±Ôò»áÏÔÊ¾ÄãÄ¿Ç°ÊÇ·ñÓĞ¼ÓÈë¶ÓÎé¼°¶ÓÔ±Ãûµ¥¡£

×é¶ÓÊ±µÈ¼¶²»ÄÜÏà²îÌ«´ó£¬µ±µÈ¼¶²»Í¬µÄÈË×é¶ÓÊ±£¬µÈ¼¶µÍµÄÒ»·½²»ÄÜÓĞÎ´
Íê³ÉµÄÈÎÎñ¡£
	
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m  

HELP
	);
	return 1;
}
