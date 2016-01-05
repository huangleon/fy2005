// go.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//

#pragma optimize all
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

mapping default_dirs = ([
	"north":		"��",
	"south":		"��",
	"east":			"��",
	"west":			"��",
	"northup":		"���߸ߴ�",
	"southup":		"�ϱ߸ߴ�",
	"eastup":		"���߸ߴ�",
	"westup":		"���߸ߴ�",
	"northdown":		"���ߵʹ�",
	"southdown":		"�ϱߵʹ�",
	"eastdown":		"���ߵʹ�",
	"westdown":		"���ߵʹ�",
	"northeast":		"����",
	"northwest":		"����",
	"southeast":		"����",
	"southwest":		"����",
	"up":			"��",
	"down":			"��",
	"out":			"��",
	"enter":		"��",
]);

void create() {
	seteuid(getuid());
}

int drop_things(object me) {
	int i, result;
	object *inv;
	object env;

	env = environment(me);
	inv = all_inventory(me);
	result = 0;
	for(i=0;i<sizeof(inv);i++){
		if(inv[i]->query("no_drop") || inv[i]->query("equipped") || inv[i]->query("owner")
				|| random(me->query_max_encumbrance()) > inv[i]->weight()) {
			continue;
		}
		result = me->ccommand("drop "+inv[i]->query("id")) ? 1 : result;
	}
	if(result) {
		message_vision("���Ҷ�ȥ��", me);
		return 1;
	}
	return 0;
}


int check_flee(object me, string arg)  {
   	mapping 	my, your;
   	object 	*enemy;
   	int	num, fp, bp, i, level;
   	
   	fp = me->query_agi();
	
	enemy = me->query_enemy();
   	i = sizeof(enemy);
   	while (i--) {
		if( objectp(enemy[i]) && environment(enemy[i])== environment(me) && living(enemy[i])) 
		{
			if (enemy[i]->query("possessed"))		continue;
			if (enemy[i]->query_temp("is_unconcious"))	continue;
			// Since x5 can usually kill 1, Let it not blocking x5.
			if (enemy[i]->query("combat_exp")< me->query("combat_exp")/5) 	continue;
			bp = enemy[i]->query_agi();
			if (fp > bp*2)	continue;	
			if (enemy[i]->is_busy())
				bp = bp * 3/5;
			level = F_LEVEL->get_level(me->query("combat_exp"));
			if ( level <30) fp = fp*3;
			else if (level < 40) fp = fp*2;		
			if((random(fp + bp) < bp)
				|| enemy[i]->query_temp("block_all_escape")) 
			{
				message_vision(YEL "$N��" + arg + "��ȥ��\n" NOR, me);
				message_vision(RED "$N��Ӱһ����������$n����ǰ��\n" NOR, enemy[i], me);
				return 0;
		 	}
	  	}
   	}
   	return 1;
}


int main(object me, string arg) {
	string dest, mout, min, dir, blk;
	object env, obj, blocker;
	mapping exit;
	mapping block;
	int water_lvl;
	
	if( !arg ) return notify_fail("��Ҫ���ĸ������ߣ�\n");

	if( me->over_encumbranced() )
		return notify_fail("��ĸ��ɹ��أ��������á�\n");

	if( me->is_busy() )
		return notify_fail("������æ�úܣ������ƶ���\n");

	if (stringp(me->query_temp("no_move")))
		return notify_fail(me->query_temp("no_move"));
				
	env = environment(me);
	if(!env) return notify_fail("������Ҳȥ���ˡ�\n");
	if(env->query_temp("lock_scene"))
	{
		if(time()<env->query_temp("lock_scene")+120)//��ֹ��һû��ȥ���Ǹ�temp mark�������⡣
			return notify_fail("��о�����Χ��һ������������ס���޷�������\n");
	}
	if( !mapp(exit = env->query("exits")) || undefinedp(exit[arg]) ) {
		if( query_verb()=="go")
			return notify_fail("�������û�г�·��\n");
		else
			return 0;
	}

	
//	��fy4����δ�õ��˹��ܣ���Ҫʱ��˵��        
/*      if( mapp(block = env->query("blocks"))&& blk=block[arg]) {
		if( objectp(blocker = present(blk, env)) &&  living(blocker))
		return notify_fail("��������·��"+ blocker->name() + "��ס�� ��\n");
        }*/

	dest = exit[arg];

	if( !(obj = find_object(dest)) )
	{
		if (!load_object(dest))
		{
			tell_object(me,"�����������ʧ������У�����\n");
			if (wizardp(me) && me->query("env/yesiknow"))
				call_other(dest, "???");
			return 1;
		}
//		call_other(dest, "???");
	}
	
	if( !(obj = find_object(dest)) )
		return notify_fail("�޷��ƶ���\n");

/*	if (userp(me) && ANNIE_D->check_buff(me,"fugitive")>0
		 && (obj->query("no_fight") || obj->query("no_death_penalty")))
		return notify_fail("�����ذ�����Щ�ط�����������ѽ��\n");*/
	
	if (env)
	if (!env->valid_leave(me, arg) ) {
		return 0;
	}
	 
	if( !undefinedp(default_dirs[arg]) )
			dir = default_dirs[arg];
		else if (dest->query("short")) dir=dest->query("short");
		else dir = arg;

	if( me->is_fighting() ) {

		if (ANNIE_D->check_buff(me,"lockfield") >= 1)
		{
			tell_object(me,YEL"����ǰ�ľ��������ƻã����Ʋ���������ȷ����·�������ںη���\n"NOR);
			return 0;
		}

		if (me->query_temp("timer/no_escape") > time()) 
			return notify_fail("�����ڲ������ܣ�\n");

		// ÿ3��heart_beat��ֻ��һ�����ܵĳ��Կ��ܳɹ���
		if (me->query_temp("marks/escape") + 6 > time()) {
			return notify_fail("�㱻���˻�����\n");
		}
		if(check_flee(me, dir) == 0) {
			me->set_temp("marks/escape",time());
			return notify_fail("�㱻���˻�����\n");
		}
		if (me->query("timer/insurance") + 259200 < time())
			drop_things(me);
		
		if (me->query("fleeout_message")) {
		    mout = replace_string( me->query("fleeout_message"), "$d", dir );
		    mout = mout + "��\n";
		 }
         else 
         	mout = "��" + dir + "��Ķ����ˡ�\n";
         if (me->query("fleein_message")) 
         	min  = me->query("fleein_message") + "��\n";
         else  
         	min = "����ײײ�����˹�����ģ����Щ�Ǳ���\n";

	} else {
// Let's add this messages here to make go and come more interesting...
		if( mout = me->query("leave_msg"))
			mout = "��" + dir + mout +"��\n";
		else 
			mout = "��" + dir + "�뿪��\n";
		if( min = me->query("arrive_msg") )
			min = min + "��\n";
		else
			min = "���˹�����\n";
	}
	
	if (userp(me))
	if (obj->query("underwater") > me->query_skill("swimming",1))
		return notify_fail("�����Ӿ����̫�û����ȥѽ����Ҫ����"+obj->query("underwater")+"����\n");
		
	if (!userp(me) && obj->query("NONPC"))
		return notify_fail("�㲻��ȥ���\n");
	else if( function_exists("valid_enter", obj) && !obj->valid_enter(me))
		return notify_fail("�㲻��ȥ���˵�˽լ��\n");
		
	if(!me->is_ghost())
		if( me->query("self_go_msg") )		// this is for �Զ���Ĳ���������뿪
			message( "vision", me->query("leave_msg")+"\n", environment(me), ({me}) );
		else if (me->query("env/invisibility"))
			message("vision","�ƺ���ʲô����һ����֪��ʲô����ȥ�ˡ�\n",environment(me),({me}));
		else  message( "vision", me->name() + mout, environment(me), ({me}) );

	if( me->move(obj) ) {
		me->remove_all_enemy();
		if(!me->is_ghost())
			if( me->query("self_go_msg") )	// this is for �Զ���Ĳ�������Ľ���
				message( "vision", me->query("arrive_msg")+"\n", environment(me), ({me}) );
			else if(me->query("env/invisibility"))
				message("vision","�ƺ���ʲô�������˽�����\n",environment(me),({me}));
			else	
				message( "vision", me->name()+ min, environment(me), ({me}) );
		me->set_temp("pending", 0);
		
		if(env)
		if(environment(me) != env) {
			all_inventory(env)->follow_me(me, arg);
		}
		
		return 1;
	}

	return 0;
}


void do_flee(object me) {
	mapping exits;
	string *directions;

	if(!environment(me) || !living(me)) {
		return;
	}
	exits = environment(me)->query("exits");
	if(!mapp(exits) || !sizeof(exits)) {
		return;
	}
	directions = keys(exits);
	if (!me->query_temp("no_flee_msg"))
		tell_object(me, "�������һ���������...\n");
	main(me, directions[random(sizeof(directions))]);
}




int help(object me) {
	write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	go <����>[0m
[0;1;37m����������������������������������������������������������������[0m   

������ָ���ķ����ƶ���

�������ս�����ô�ָ������뵱ǰ���䣬
��������ļ���ֱ��ȡ����ս��˫����������ݶ�
�����ڶ���æ�ң���������ʱ������ܼ������󣴣���
����ÿ����ս���غ�ֻ����һ�����ܳ��Կ��ܳɹ�
��Ҳ����˵����ʹ��������������������100��go��ϵͳֻ���ݵ�һ�����жϣ�
�����ڵ͵ȼ�ʱ���̣���ǰ���������ܼ��ʣ�������������

��ֵ���㼰˵����a = �������ٶȣ�b = �����ٶ�
���������(a + b ) < b ʱ������ʧ��

����������˴��ڻ���״̬�����ܱ�Ȼ�ɹ�
����������˾���ֵ���������ߵģ����������ܱ�Ȼ�ɹ�
��������᣾���⣬���ܱ�Ȼ�ɹ�
����������˴���æ��״̬����*������
������������ߵȼ����ڣ�������*��
������������ߵȼ����ڣ�������*��

[0;1;37m����������������������������������������������������������������[0m   
HELP
	);
	return 1;
}