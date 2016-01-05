// quit.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//

/*	LAST Modified
	1. can not quit during fight		--- by Silencer 5/26/2003
	2. Exp<3000 won't get saved		--- by Silencer 7/5/2004
*/

#include <ansi.h>
#include <command.h>
inherit F_CLEAN_UP;

#define GOODBYE "/adm/etc/goodbye"

int rmhirdir(string dir);

void create()  {
	seteuid(getuid());
//      set("name", "¿Îœﬂ÷∏¡Ó");
//      set("id", "quit");
}

int main(object me, string arg) {
	int i, stage;
	object *inv, link_ob;
	string name;

	
	
	if(!me->query_temp("netdead")) {
		if(me->is_busy()) {
			return notify_fail("ƒ„…œ“ª∏ˆ∂Ø◊˜ªπ√ª”–ÕÍ≥…,≤ªƒ‹ÕÀ≥ˆ°£\n");
		}
		if (me->is_fighting())		{
			return notify_fail("’Ω∂∑÷–≤ªø…“‘ÕÀ≥ˆ∑Á‘∆£°\n");		
		}
		
/*		if (ANNIE_D->check_buff(me,"fugitive"))
			return notify_fail("∑∏¡À ¬∂˘æÕœÎ¡Ô£ø√ªƒ«√¥»›“◊°£\n"); */
			
		if (stringp(me->query_temp("no_move")))
			return notify_fail(me->query_temp("no_move"));
			
		if (me->query("kee")< 0 || me->query("eff_kee")<0
			|| me->query("gin")< 0 || me->query("eff_gin") < 0
			|| me->query("sen")< 0 || me->query("eff_sen") < 0 )
			{
			return notify_fail("ƒ„µƒæ´∆¯…Ò◊¥Ã¨≤ª’˝≥££¨‘› ±≤ªƒ‹ÕÀ≥ˆ∑Á‘∆°£\n");
		}
		if(environment(me))
		if(environment(me)->query_temp("lock_scene"))
		{
			//∑¿÷πÕÚ“ª√ª”–»•µÙƒ«∏ˆtemp mark£¨≥ˆŒ Ã‚°£
			if(time() < environment(me)->query_temp("lock_scene")+120)
				return notify_fail("ƒ„∏–æıµΩ÷‹Œß±ª“ª’Û∆¯≥°ΩÙΩÙÀı◊°£¨Œﬁ∑®∂ØµØ°£\n");
		}
		if(me->query_temp("no_quit")) {
			return notify_fail("ƒ„œ÷‘⁄≤ªø…“‘ÕÀ≥ˆ∑Á‘∆£°\n");
		}
	}
	
	me->heart_beat();
	link_ob = me->query_temp("link_ob");
	
	if(!(int)me->query("kee")) {
		me->set("kee",1);
	}		

	me->save();

//	We won't save low-exp player data now.	
	if (me->query("combat_exp")< 24000 && !wizardp(me))
	{
		if (!me->query_temp("nosave_warning")) {
			write(HIW"Œ™∑¿÷π∂Ò“‚◊¢≤·£¨∑Á‘∆Ωˆ±£¥Êæ≠—Èµ»º∂¥Û”⁄£Ã£≤£®£¥£∞£•£©µƒÕÊº“ ˝æ›°£\n"NOR);
			write(HIW"»Áπ˚æˆ∂®ÕÀ≥ˆ£¨«Î‘Ÿ¥Œ ‰»Î£Ò£ı£È£Ù£¨ƒ„µƒ ˝æ›Ω´≤ª±ª±£¡Ù°£\n"NOR);
			me->set_temp("nosave_warning",1);
			return 1;
		}
	}
	
	inv= all_inventory(me);
	for (i=0;i<sizeof(inv);i++) {
		if (inv[i]->query("quest_box"))	// Adding AUTOSAVE for QUEST_BOX
			inv[i]->do_qqsave(me);
		if (!inv[i])	continue;
		if (!wizardp(me) && !inv[i]->query_autoload())
		if(!DROP_CMD->do_drop(me, inv[i])) {
			write(inv[i]->name() + "ªØ≥…“ª≈Ó∑€ƒ©œ˚ ß¡À°£\n");
			destruct(inv[i]);
		}
	}

	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++) {
		if (wizardp(me)|| inv[i]->query_autoload()) {
			write(inv[i]->name() + "ªØ≥…“ª≈Ó∑€ƒ©œ˚ ß¡À°£\n");
			destruct(inv[i]);
		}
	}

	// Remove all buffs to clean up annied
	ANNIE_D->debuff(me,"all");

	// We might be called on a link_dead player, so check this.
	if( link_ob ) {
		// Are we possessing in others body ?
		if( link_ob->is_character()) {
			write("ƒ„µƒªÍ∆«ªÿµΩ" + link_ob->name(1) + "µƒ…Ì…œ°£\n");
			exec(link_ob, me);
			link_ob->setup();
						
			// Darkfy Support
			if (me->query("dark_npc"))
				destruct(me);
			else {
				// Annie Virtual Area Support.
				// quand un joueur cesse, d®¶truire son secteur.
				link_ob->delete("NO_KILL");
				"/d/phoenix/base/alive.c"->destruct_area(link_ob->query("id"));
			}
			return 1;
		}

		link_ob->set("last_on", time());
		link_ob->set("last_from", query_ip_name(me));
		if (me->query("combat_exp")< 24000 && !wizardp(me))
		{
			name = link_ob->query("id");
			rmhirdir(DATA_DIR + "login/" + name[0..0] + "/" + name );
        		rmhirdir(DATA_DIR + "user/" + name[0..0] + "/" + name );
		}else
			link_ob->save();
		destruct(link_ob);
	}
	write("\n");
	cat(GOODBYE) ;

	if(environment(me)) {
		message("system", me->name() + "¿Îø™”Œœ∑°£\n", environment(me), me);
	}

	if (me->query("marry"))
		if (find_player(me->query("marry")))
			if (find_player(me->query("marry"))->query("jiebai"))
				tell_object(find_player(me->query("marry")),HIG"ƒ„µƒ∞À∞›÷ÆΩª"+me->query("name")+"œ¬œﬂ¡À°£\n"NOR);
			else if (find_player(me->query("marry"))->query("gender") == "ƒ––‘")
				tell_object(find_player(me->query("marry")),HIG"ƒ„µƒ∆ﬁ◊”"+me->query("name")+"œ¬œﬂ¡À°£\n"NOR);
			else
				tell_object(find_player(me->query("marry")),HIG"ƒ„µƒ∑Úæ˝"+me->query("name")+"œ¬œﬂ¡À°£\n"NOR);

	if (me)
	if (!wizardp(me))
		STATUS_D->compare_status(me);	

	CHANNEL_D->do_sys_channel("sys",sprintf(
		"%s(%s)¿Îø™”Œœ∑¡À°£", me->name() , me->query("id")));
	log_file( "USAGE", sprintf(
		"%s quits at %s with exp: %d, pot: %d, money: %d\n",
		me->query("id"), ctime(time()), me->query("combat_exp"),
		me->query("potential"), me->query("deposit")));
	log_file("STAT", sprintf(
		"OFF %s %s %d %d %d %d %d %d %s\n",
		me->query("id"),me->query("name"),me->query("combat_exp"),
		me->query("deposit"),me->query("potential"),me->query("TASK"),
		me->query("mud_age"), me->query("QUEST"), ctime(time()) ) );
	
	destruct(me);

	return 1;
}


int rmhirdir(string dirstr)
{
	string *dir;
	int i;
	dir = get_dir(dirstr+"/");
        for(i=0; i<sizeof(dir); i++) {
                if(file_size(dirstr+"/"+dir[i]) == -2 ) {
                                rmhirdir( dirstr +"/"+dir[i]);
                                rmdir(dirstr+"/"+dir[i]);
                                                }
                rm(dirstr+"/"+dir[i]);
        }
	rmdir(dirstr);
	return 1;

}


int help(object me)
{
	write(@HELP
[0;1;37m©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§[0m
[0;1;36m÷∏¡Ó∏Ò Ω : quit[0m
[0;1;37m©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§[0m

µ±ƒ„(ÕÊº“)œÎ‘› ±¿Îø™ ±, ø…¿˚”√¥À“ª÷∏¡Ó£¨

◊¢“‚”Î“‘Õ˘∞Ê±æ≤ªÕ¨µƒ «£¨‘⁄’Ω∂∑÷–≤ªƒ‹»Œ“‚ÕÀ≥ˆ”Œœ∑°£

ÕÀ≥ˆ ±≥˝◊‘‘ÏŒ‰∆˜º∞ƒ≥–©Ãÿ∂®ŒÔ∆∑Õ‚æ¯¥Û≤ø∑÷…Ì…œ∂´Œ˜∂ºª·“≈ ß£¨
«ÎΩ´–Ë“™±£¥ÊµƒŒÔ∆∑∑≈÷¡µ±∆Ã£¨Ω´«Æ≤∆¥Ê»Î“¯––°£

Œ™∑¿÷π∂Ò“‚◊¢≤·£¨∑Á‘∆Ωˆ±£¥Êæ≠—Èµ»º∂¥Û”⁄£Ã£≤£®£¥£∞£•£©µƒÕÊº“ ˝æ›°£
µÕ”⁄¥Àæ≠—È÷µÕÀ≥ˆ£¨ ˝æ›Ω´≤ª◊ˆ±£¡Ù°£

[0;1;37m©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§[0m
HELP
		);
	return 1;
}


/*

°°°°°°°°°°°°°°®X®Y
°°°°°°°°°°°°°°®U®t®r
°°°°°°°°°°°°°°®U©¶®t®r
°°°°°°°°°°°°°°®U©¶©¶®t®r
°°°°°°°°°°°°°°®U©¶©¶©¶©¶
°°°°°°°°°°°°°°®^®k®k®k®_

°°°°°°°°°°°°°°- FengYun - °°°°°°
°°°°°°°°°°°°annie 08.2003
°°°°°°dancing_faery@hotmail.com
*/

