// get.c
//	fix the bug that can not get 1 piece from xxx
//		modified by justdoit at 11.1 2001
// 	added various check and 15 sec corpse-protection delay
//		by Silencer at 3/6/2003
/*
	¶«Î÷µÄMark
	(1). no_drop: Can pawn only
	(2). no_get: ´ó²¿·ÖÓÃÔÚ¾²ÎïÉÏ
	(3). no_transfer: ÔÚµÚÒ»´Î£ç£å£ôºó×Ô¶¯×ªÎªno_drop£¬²»ÄÜsell, ¿ÉÒÔpawn, redeemºó×ªÎªno_drop
	(4). no_stack: ²»ÄÜ·ÅÔÚ×Ô¼ºÎİ×ÓÀï
	(5). lore: Ö»ÄÜÓµÓĞÒ»¸ö£¬ÇÒ²»ÄÜ·ÅÔÚÈİÆ÷Àï£®

	ÀÏµÄ£í£á£ò£ë
	(1). no_give.. so you just drop it to transfer?
	(2). no_pawn... why? just set value to 1
	(3). no_sell.. why? just set value to 1


	i need revise put/give/get/drop/sell/pawn container lore etc later...

	// added modification posted by siso at JUN 6, 2005 
	-- Silencer
*/



#include <ansi.h>

inherit F_CLEAN_UP;

int do_get(object me, object ob, object env);	//modified
object present(mixed str, object env); 
void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string from, item;
	object obj, *inv, env, obj2;
	object *my_inv, my_item;
	int i, j, amount, num, freeze;
	string arg1, from1;

	if( !arg ) return notify_fail("ÄãÒª¼ñÆğÊ²÷á¶«Î÷£¿\n");
	if( me->is_busy() )
		return notify_fail("ÄãÉÏÒ»¸ö¶¯×÷»¹Ã»ÓĞÍê³É£¡\n");

	if (sizeof(all_inventory(me))>=26)
		return notify_fail("ÄãÒÑ¾­´øÖøÌ«¶à¶«Î÷ÁË£¡\n");

// prevent people using get xyz from wall 0 
// prevent people using get xyz from wall 1
	if ( sscanf(arg, "%s from %s %d", arg1, from1, num)==3) {
		if (num==0 || num ==1)
			return notify_fail("²»±Ø»ò²»ÄÜÊ¹ÓÃget xxx from xxx 0/1¡£\n");
	}

	// Check if a container is specified.
	if( sscanf(arg, "%s from %s", arg, from)==2 ) {
		env = present(from, me);
		if(!env) env = present(from, environment(me));
		if(!env) return notify_fail("ÄãÕÒ²»µ½ " + from + " ÕâÑù¶«Î÷¡£\n");
		if( !env->is_corpse() && env->is_character() && (wiz_level(me) <= wiz_level(env)))
			return notify_fail("ÄãµÄ¹ÜÀíµÈ¼¶±ØĞë±È¶Ô·½¸ß£¬²ÅÄÜËÑÉí¡£\n");
		if( !env->is_corpse() && env->is_character() && !userp(env) && wiz_level(me) <= 3 )
			return notify_fail("ÄãµÄ¹ÜÀíµÈ¼¶²»¹»¡£\n");	
	} else 
		env = environment(me);
	
	// check if this thing is locked or whatsoever any tricks invovled
	if( (int) env->is_closed())
		return notify_fail( "ÄãÒªÏÈ°Ñ" + env->name() + "´ò¿ª¡£\n");
	
	// Check if a certain amount is specified.
	if(sscanf(arg, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, env)) )
			return notify_fail("ÕâÀïÃ»ÓĞÕâÑù¶«Î÷¡£\n");
		if( !obj->query_amount() )
			return notify_fail( obj->name() + "²»ÄÜ±»·Ö¿ªÄÃ×ß¡£\n");
		if( amount < 1 )
			return notify_fail("¶«Î÷µÄ¸öÊıÖÁÉÙÊÇÒ»¸ö¡£\n");
		if( amount > obj->query_amount() ) {
			return notify_fail("ÕâÀïÃ»ÓĞÄÇ÷á¶àµÄ" + obj->name() + "¡£\n");
		} else if(amount == (int)obj->query_amount()) {
			return do_get(me, obj, env);	//modified
		} else {
			obj->set_amount( (int)obj->query_amount() - amount );
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
						obj2->set_name(obj->query("name"),obj->parse_command_id_list());
			obj2->set("long",obj->query("long"));
			obj2->set("unit",obj->query("unit"));

			obj2->move(me);		//modified
			// Counting precise amount costs more time.
			if( me->is_fighting() ) me->start_busy(3);
			return do_get(me, obj2, env);	//modified
		}
	}

	// Check if we are making a quick get.
	if(arg=="all") {
		if( me->is_fighting() )	
			return notify_fail("Äã»¹ÔÚÕ½¶·ÖĞ£¡Ö»ÄÜÒ»´ÎÄÃÒ»Ñù¡£\n");
		if( !env->query_max_encumbrance() )	return notify_fail("ÄÇ²»ÊÇÈİÆ÷¡£\n");

		inv = all_inventory(env);
		if( !sizeof(inv) )
			return notify_fail("ÄÇÀïÃæÃ»ÓĞÈÎºÎ¶«Î÷¡£\n");
		
	//	15 sec corpse loot protection. Only killer/self can loot the corpse.	
		if (env->query("allow_to_loot")) {
			if (env->query("freeze")) freeze = 180;
				else freeze = 15;
			if (env->query("death_time")+ freeze > time()) {
				if ( member_array( me,env->query("allow_to_loot")) == -1
					&& env->query("victim_name")!= me->query("name"))
						return notify_fail("ÄãÏÖÔÚ»¹²»ÄÜÄÃÆğÕâ¼ş¶«Î÷¡£\n");
			}
		}
	
		for(i=0; i<sizeof(inv); i++) {
			
			if( (inv[i]->is_character() && !inv[i]->query("yes_carry")) 
				|| inv[i]->query("no_get") || inv[i]->query("lore")) continue;
			
			if (inv[i]->query("allow_to_loot")) {
			if (inv[i]->query("death_time")+15 > time()) {
				if ( member_array( me,inv[i]->query("allow_to_loot")) == -1
					&& inv[i]->query("victim_name")!= me->query("name"))
						return notify_fail("ÄãÏÖÔÚ»¹²»ÄÜÄÃÆğÕâ¼ş¶«Î÷¡£\n");
				}
			}
			do_get(me, inv[i], env);	//modified
		}
		write("Ok¡£\n");
		return 1;
	}

	if( !objectp(obj = present(arg, env)) || (living(obj) && !(int)obj->query("yes_carry")))
		return notify_fail("Äã¸½½üÃ»ÓĞÕâÑù¶«Î÷¡£\n");

	if( obj->query("no_get") )
		return notify_fail("Õâ¸ö¶«Î÷ÄÃ²»ÆğÀ´¡£\n");

// 	lore item, you can only own one in your inventory at a time
	if ( obj->query("lore")) {
		my_inv = all_inventory(me);
		for(j=0;j<sizeof(my_inv);j++){
			my_item = my_inv[j];
			if(obj->query("name")==my_item->query("name")
				&& my_item->query("lore"))
			return notify_fail("ÕâÑù¶«Î÷Äã×î¶àÖ»ÄÜÓĞÒ»¼ş¡£\n");
			}
	}

//	15 sec corpse loot protection. Only killer/self can loot the corpse.	
	
	if (env->query("allow_to_loot")) {
		if (env->query("death_time")+15 > time()) {
			if ( member_array( me,env->query("allow_to_loot")) == -1
				&& env->query("victim_name")!= me->query("name"))
				return notify_fail("ÄãÏÖÔÚ»¹²»ÄÜÄÃÆğÕâ¼ş¶«Î÷¡£\n");
		}
	}
	if (obj->query("allow_to_loot")) {
		if (obj->query("death_time")+15 > time()) {
			if ( member_array( me,obj->query("allow_to_loot")) == -1
				&& obj->query("victim_name")!= me->query("name"))
				return notify_fail("ÄãÏÖÔÚ»¹²»ÄÜÄÃÆğÕâ¼ş¶«Î÷¡£\n");
		}
	}
	
	return do_get(me, obj, env);	//modified
}
	
int do_get(object me, object obj,object env)	//modified
{
	object old_env, *enemy;
	int equipped;
	object target;
	string	prep;

	target = me;
	if( !obj ) return 0;
	old_env = env;	//modified
	if( obj->is_character()  && !obj->is_corpse()) {
		return notify_fail("Äã²»ÄÜ±³¸º»îÎï¡£\n");
		// If we try to save someone from combat, take the risk :P
	} else {
		if( obj->query("no_get") ) return 0;
	}

	
	if (sizeof(all_inventory(me))>=26)
		return notify_fail("ÄãÒÑ¾­´øÖøÌ«¶à¶«Î÷ÁË£¡\n");

	if( obj->query("equipped") ) equipped = 1;
	if( obj->query("yes_carry")) target = environment(me);
	if( obj->move(target) ) {
		if (!obj->query("got_time"))
		{
			obj->set("got_time",time());			
		}
		
		if (obj->query("value")>= 1000
			&& !obj->query("money_id")
			&&  obj->query("material")!="herb")
				log_file("money_item", sprintf("%s worth %d.\n",base_name(obj) ,obj->query("value")));
				
		if((int)obj->query("no_transfer")){
			obj->set("no_get",1); 
			obj->set("no_drop",1);
		}
		if(me->is_fighting()) 
			me->start_busy(1);
		if( obj->is_character()  && !obj->query("yes_carry"))
			message_vision( "$N½«$n·öÁËÆğÀ´±³ÔÚ±³ÉÏ¡£\n", me, obj );
		else {
			if(old_env==environment(me)) prep =  "¼ñÆğ";
			else if(old_env->is_character()) prep =  "´Ó" + old_env->name() + "ÉíÉÏ" + (equipped? "³ıÏÂ" : "ËÑ³ö");
			else switch( old_env->query("prep") ) {
				case "on":
					prep = "´Ó" + old_env->name() + "ÉÏÄÃÆğ";
					break;
				case "under":
					prep = "´Ó" + old_env->name() + "ÏÂÄÃ³ö";
					break;
				case "behind":
					prep = "´Ó" + old_env->name() + "ºóÄÃ³ö";
					break;
				case "inside":
					prep = "´Ó" + old_env->name() + "ÖĞÄÃ³ö";
					break;
				default:
					prep = "´Ó" + old_env->name() + "ÖĞÄÃ³ö";
					break;
			};
			message_vision( sprintf("$N%sÒ»%s$n¡£\n", prep,
				obj->query("unit")), me, obj );
		}
		return 1;
	}
	else return 0;
}


// ¸²¸Çpresent()Õâ¸öefun,¼ÓÈë¶Ô"name"µÄ±È½Ï by siso_20050606 
object present(mixed str, object env) 
{ 
   object *inv; 
   int n; 

   if( !env->query_max_encumbrance() ) 
       return 0; 
   inv = all_inventory(env); 
   if( !sizeof(inv) ) 
       return 0; 
   if( str ) { 
       str = replace_string(str, "$BLK$", BLK); 
       str = replace_string(str, "$RED$", RED); 
       str = replace_string(str, "$GRN$", GRN); 
       str = replace_string(str, "$YEL$", YEL); 
       str = replace_string(str, "$BLU$", BLU); 
       str = replace_string(str, "$MAG$", MAG); 
       str = replace_string(str, "$CYN$", CYN); 
       str = replace_string(str, "$WHT$", WHT); 
       str = replace_string(str, "$HIR$", HIR); 
       str = replace_string(str, "$HIG$", HIG); 
       str = replace_string(str, "$HIY$", HIY); 
       str = replace_string(str, "$HIB$", HIB); 
       str = replace_string(str, "$HIM$", HIM); 
       str = replace_string(str, "$HIC$", HIC); 
       str = replace_string(str, "$HIW$", HIW); 
       str = replace_string(str, "$NOR$", NOR); 
   } 
   for(n=0; n<sizeof(inv); n++) { 
       if ( str ==  inv[n]->name() || str == (inv[n]->query("id")) ) 
           return  inv[n]; 
   } 
   return efun::present(str, env); 
} 


int help(object me)
{
	write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : 	get <ÎïÆ·Ãû³Æ> [from <ÈİÆ÷Ãû>][0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   
Ö¸Áî¸ñÊ½ : get <ÎïÆ·Ãû³Æ> [from <ÈİÆ÷Ãû>]

Õâ¸öÖ¸Áî¿ÉÒÔÈÃÄã¼ñÆğµØÉÏ»òÈİÆ÷ÄÚµÄÄ³ÑùÎïÆ·. 
ÎïÆ·ºÍÈİÆ÷¶¼¼È¿ÉÒÔÊ¹ÓÃÓ¢ÎÄIDÒ²¿ÉÒÔÊ¹ÓÃÖĞÎÄÃû×Ö¡£ 
Èç¹ûÎïÆ·»òÈİÆ÷ÓĞÑÕÉ«£¬Çë²ÎÕÕÒÔÏÂ¹æÔò£º 

get <ÑÕÉ«´úÂë><ÎïÆ·Ãû³Æ>$NOR$ from <ÈİÆ÷> 

<ÑÕÉ«´úÂë> 
$BLK$ - ºÚÉ«            $NOR$ - »Ö¸´Õı³£ÑÕÉ« 
$RED$ - ºìÉ«            $HIR$ - ÁÁºìÉ« 
$GRN$ - ÂÌÉ«            $HIG$ - ÁÁÂÌÉ« 
$YEL$ - ÍÁ»ÆÉ«          $HIY$ - »ÆÉ« 
$BLU$ - ÉîÀ¶É«          $HIB$ - À¶É« 
$MAG$ - Ç³×ÏÉ«          $HIM$ - ·ÛºìÉ« 
$CYN$ - À¶ÂÌÉ«          $HIC$ - ÌìÇàÉ« 
$WHT$ - Ç³»ÒÉ«          $HIW$ - °×É« 
 
Ïà¹ØÖ¸Áî£ºdrop
 
HELP
    );
    return 1;
}
 

/*

¡¡¡¡¡¡¡¡¡¡¡¡¡¡¨X¨Y
¡¡¡¡¡¡¡¡¡¡¡¡¡¡¨U¨t¨r
¡¡¡¡¡¡¡¡¡¡¡¡¡¡¨U©¦¨t¨r
¡¡¡¡¡¡¡¡¡¡¡¡¡¡¨U©¦©¦¨t¨r
¡¡¡¡¡¡¡¡¡¡¡¡¡¡¨U©¦©¦©¦©¦
¡¡¡¡¡¡¡¡¡¡¡¡¡¡¨^¨k¨k¨k¨_

¡¡¡¡¡¡¡¡¡¡¡¡¡¡- FengYun - ¡¡¡¡¡¡
¡¡¡¡¡¡¡¡¡¡¡¡annie 08.2003
¡¡¡¡¡¡dancing_faery@hotmail.com
*/

