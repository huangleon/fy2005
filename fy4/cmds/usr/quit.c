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
//      set("name", "����ָ��");
//      set("id", "quit");
}

int main(object me, string arg) {
	int i, stage;
	object *inv, link_ob;
	string name;

	
	
	if(!me->query_temp("netdead")) {
		if(me->is_busy()) {
			return notify_fail("����һ��������û�����,�����˳���\n");
		}
		if (me->is_fighting())		{
			return notify_fail("ս���в������˳����ƣ�\n");		
		}
		
/*		if (ANNIE_D->check_buff(me,"fugitive"))
			return notify_fail("�����¶������û��ô���ס�\n"); */
			
		if (stringp(me->query_temp("no_move")))
			return notify_fail(me->query_temp("no_move"));
			
		if (me->query("kee")< 0 || me->query("eff_kee")<0
			|| me->query("gin")< 0 || me->query("eff_gin") < 0
			|| me->query("sen")< 0 || me->query("eff_sen") < 0 )
			{
			return notify_fail("��ľ�����״̬����������ʱ�����˳����ơ�\n");
		}
		if(environment(me))
		if(environment(me)->query_temp("lock_scene"))
		{
			//��ֹ��һû��ȥ���Ǹ�temp mark�������⡣
			if(time() < environment(me)->query_temp("lock_scene")+120)
				return notify_fail("��о�����Χ��һ������������ס���޷�������\n");
		}
		if(me->query_temp("no_quit")) {
			return notify_fail("�����ڲ������˳����ƣ�\n");
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
			write(HIW"Ϊ��ֹ����ע�ᣬ���ƽ����澭��ȼ����ڣ̣�������������������ݡ�\n"NOR);
			write(HIW"��������˳������ٴ������������������ݽ�����������\n"NOR);
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
			write(inv[i]->name() + "����һ���ĩ��ʧ�ˡ�\n");
			destruct(inv[i]);
		}
	}

	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++) {
		if (wizardp(me)|| inv[i]->query_autoload()) {
			write(inv[i]->name() + "����һ���ĩ��ʧ�ˡ�\n");
			destruct(inv[i]);
		}
	}

	// Remove all buffs to clean up annied
	ANNIE_D->debuff(me,"all");

	// We might be called on a link_dead player, so check this.
	if( link_ob ) {
		// Are we possessing in others body ?
		if( link_ob->is_character()) {
			write("��Ļ��ǻص�" + link_ob->name(1) + "�����ϡ�\n");
			exec(link_ob, me);
			link_ob->setup();
						
			// Darkfy Support
			if (me->query("dark_npc"))
				destruct(me);
			else {
				// Annie Virtual Area Support.
				// quand un joueur cesse, d��truire son secteur.
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
		message("system", me->name() + "�뿪��Ϸ��\n", environment(me), me);
	}

	if (me->query("marry"))
		if (find_player(me->query("marry")))
			if (find_player(me->query("marry"))->query("jiebai"))
				tell_object(find_player(me->query("marry")),HIG"��İ˰�֮��"+me->query("name")+"�����ˡ�\n"NOR);
			else if (find_player(me->query("marry"))->query("gender") == "����")
				tell_object(find_player(me->query("marry")),HIG"�������"+me->query("name")+"�����ˡ�\n"NOR);
			else
				tell_object(find_player(me->query("marry")),HIG"��ķ��"+me->query("name")+"�����ˡ�\n"NOR);

	if (me)
	if (!wizardp(me))
		STATUS_D->compare_status(me);	

	CHANNEL_D->do_sys_channel("sys",sprintf(
		"%s(%s)�뿪��Ϸ�ˡ�", me->name() , me->query("id")));
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
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : quit[0m
[0;1;37m����������������������������������������������������������������[0m

����(���)����ʱ�뿪ʱ, �����ô�һָ�

ע���������汾��ͬ���ǣ���ս���в��������˳���Ϸ��

�˳�ʱ������������ĳЩ�ض���Ʒ����󲿷����϶���������ʧ��
�뽫��Ҫ�������Ʒ�������̣���Ǯ�ƴ������С�

Ϊ��ֹ����ע�ᣬ���ƽ����澭��ȼ����ڣ̣�������������������ݡ�
���ڴ˾���ֵ�˳������ݽ�����������

[0;1;37m����������������������������������������������������������������[0m
HELP
		);
	return 1;
}


/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/

