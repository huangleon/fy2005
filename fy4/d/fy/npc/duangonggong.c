// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

// 2009 FengYun
// Edit by hippo 2009.11
// Т�� ����

#include <ansi.h>
inherit NPC;
inherit F_LEVEL;
object ob;
int  do_ji(string arg);
int give_me_it(object me);


void create()
{
	set_name("�ι���", ({ "duan gonggong","duan","gonggong" }) );
	set("gender", "����" );
	set("title", HIR "���¹���"NOR);
	set("age", 52);
	set("long","�ι����ǵ��������ǰ��һ����ˣ���Ȼֻ�Ǹ�����Ʒ���Ĺ��Σ�
ȴ�ƹ��Ź������졢��̽�������Ļ�������Ż��ϵ����壬��
�����ѹ������"WHT"�����챦"NOR"��\n");

	set("inquiry",([
		"�����챦" : "�����������������һ���������Ǵ����������Ϻò��ϡ�\n",
		"����"     : "�������������Ǵ����������Ϻò��ϡ�\n",
		"��������" : "Ψ�й�����Ƹ�Ĵ�ʦ�������˲�֪��ζ��죬Ѱ�������ǲ��еģ���\n",
		"��������" : "�������˴Ӳ��������������⣬�һ���и����㡣\n",
		"�и�����" : "�����������ޣ��������˸������׳��֣�Ѱ����û���������\n",
		"����"     : "�����������ޣ��������˸������׳��֣�Ѱ����û���������\n",
		"Ѱ����"   : "action�ι������˿��㣬���Ʋ��Ʋ��˵����\n",
		"����"     : "˵��Ҳ���ѣ��������Ϲ�����������Ҫ��ôǧ���ƽ��ټ���Ϊ����Ч������task����",
		"task"     : "ÿ����һ�Σ������������ǧ������task������ʱ��Ϳ��������Ұ�æ��temper���ˡ�\n",	
		"temper"   : "���Ǵ��������ˣ��ⶼ��������������������ûѧ�á�\n",
	]) );

	set("combat_exp", 50000);
	set("str",30);
	set("attitude", "friendly");
	setup();
	carry_object("/obj/armor/cloth")->wear();
}

void init()
{       
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 2, ob);
	}
	add_action("do_ji","temper");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() || random(10) ) {
		return;
	}
	message_vision(CYN"�ι�������˹��ؿ�����һ�ۣ����ǲ�м����ɫ��\n"NOR, this_object()); 
}

int do_ji(string arg)
{
	int ji2, n;
	int gold;
	int cost =1;
	int i, j, base, current;
	string id, name, broken;  

	object me = this_player();

	if( me->is_busy() ) {
		return notify_fail("����һ��������û����ɡ�\n");
	}
	if( !arg ) {
		return notify_fail("��Ҫ����ʲ��������\n");
	}
	if( !objectp(ob = present(arg, me)) ) {
		return notify_fail("������û������������\n"); 	
	}
	if( !ob->query("weapon_prop") ) {
			return notify_fail("��ֻ�ܶ���ɵ��������Ķ�����\n");
	}
	if( ob->query("equipped") ) {
			return notify_fail("�㲻�ɶ���װ�����˵�������\n");
	}
	if( !ob->query("owner") ) {
		return notify_fail("��ֻ�ɶ����Լ������������\n");
	}
	sscanf(ob->query("name"), "%s��", broken);
	if( broken == "�ϵ�" ) {
		return notify_fail("�㲻�ɶ������˵���������ȥ�����������޺�����������\n");
	}
	base = (int)ob->query("base_damage");
	current = (int) ob->query("weapon_prop/damage");
	if( base != current ) {
		return notify_fail("�㲻�ɶ������˵���������ȥ�����������޺�����������\n"); 
	}
	if( me->query("deposit") < 10000000 ) {
		tell_object(me, CYN"�ι���Ц���е�˵�������������Ǽ����˹��Ļ��������Ҫ��ǧ����\n"NOR);
		return 1;
	}
	if( me->query("TASK") < 2000 ) {
		tell_object(me,CYN"�ι���ҡҡͷ˵����ûΪ������ʲô�¶����Ҽ��ѱ氡����������2000��ʹ����\n"NOR);
		return 1;
	}
			
	ji2 = me->query("ji2_times");
	if( ji2 >= 10 ) {
		tell_object(me,CYN"������������ƴ�ʦ˵�����Ѿ�û���ٸĽ���������ˡ�\n");
		return 1;
	}
				
	n = (ji2+1)*2000 - me->query("TASK");
	if( n > 0 ) {
		tell_object(me,CYN"��λ�������㻹ҪΪ���϶�Ч�����С������ٻ�������"+n+ "��ʹ����\n"NOR);
		return 1;
	}
	tell_object(me, HIY"��������һ�ν���ʹ��һǧ���ƽ��Ƿ�Ҫ������(continue yes/no)\n"NOR);
	add_action("do_continue", "continue");
	me->set_temp("process_ji2", ob);
	return 1;
}

int do_continue(string arg)
{
	int i, j, cost = 1;
	object me = this_player();
	object ji_person, obx;
	string broken;
	int gold, base, current;

	if( environment(me)!= environment(this_object()) || !me->query_temp("process_ji2") || !objectp(me->query_temp("process_ji2")) ) {
		return notify_fail("ʲô��\n");
	}
	if( arg != "yes" ) { 
		write ("�ι���˵��֪�Ѷ��ˣ��㻹�Ǻ�����֪֮���ġ�\n");
		me->delete_temp("process_ji2");
		remove_action("do_continue","continue");
		return 1; 
	}
	if( !objectp(ob = me->query_temp("process_ji2")) ) {
		return notify_fail("������û������������\n");
	}
	me->delete_temp("process_ji2");
	if( !ob->query("weapon_prop") ) {
		return notify_fail("��ֻ�ܶ���ɵ��������Ķ�����\n");
	}
	if( ob->query("equipped") ) {
		return notify_fail("�㲻�ɶ���װ�����˵�������\n");
	}
	if( !ob->query("owner") ) {
		return notify_fail("��ֻ�ɶ����Լ������������\n");
	}
	sscanf(ob->query("name"), "%s��", broken);
	if( broken =="�ϵ�" ) {
		return notify_fail("�㲻�ɶ������˵���������ȥ�����������޺�����������\n");
	}
	base = (int)ob->query("base_damage");
	current = (int) ob->query("weapon_prop/damage");
	if( base != current ) {
		return notify_fail("�㲻�ɼ����˵���������ȥ�����������޺�������������\n");
	}
	cost = 1000;
	gold = me->query("deposit")/10000;
	if( gold < cost) {
		tell_object(me,"�����������" + sprintf("%d",cost)+ "�����ӡ�\n");
		return 1;
	}
	me->perform_busy(1);        
	me->add("deposit", -10000000);

	// need to update 2 things: damage, base_damage is to keep track
	// damage on weapon so we can xiu weapon later on.
	seteuid(ROOT_UID);
	me->add("ji2_times",1);
	ob->unequip();
	ob->add("weapon_prop/damage", 10);
	ob->add("base_damage", 10);
	ob->add("ji2_times", 1);
	ob->save();
	ob->restore();
	me->save();
	seteuid(getuid());

	message_vision("\n$N��$n����ȡ��"+ob->name()+NOR"���빬�У�ûһ��������˳�����\n", this_object(), me); 
	message_vision("$N�Ǻ�Ц������С�Ӻø���������������������������£�˳��Ͱ�����¶�Ҳ���ˡ�\n\n", this_object());
	message_vision("$N��"+ob->name()+NOR"������$n�����ú�����ϰ��¶����������ͣ�\n\n", this_object(), me);

	remove_action("do_continue", "continue");
	return 1;
}

int accept_object(object who, object ob)
{
	object me = who;

	if( (ob->query("name") == HIG"ТŮ��"NOR) && (REWARD_D->riddle_check(me,"Т�в���") == 2) ) {
		if( ob->query("lore") ) {
			message_vision("�ι����ӹ��˵�������ϸ������$N˵��"CYN"�����°�����֪������\n"NOR, me);
			REWARD_D->riddle_set(me,"Т�в���",3);
			give_me_it(me);
			return 1;
		}
	} else if( ob->query("pfm_r1") == 1 ) {
		message_vision(WHT"$N�����к�Ȼ�ų�������Ц�Ǻǵص������ã��ã���Ȼ��ȱ��Щ��Ҳ����Ի��ϵ�һƬ���ġ���\n"NOR, this_object());
		who->add("marks/book_task", 1);
		who->add("TASK", 1);
		tell_object(who,"�����ʹ���� +1 ����\n");
		return 1;
	}
	return 0;
}

int give_me_it(object me)
{
	object x;
	x = new(__DIR__"obj/su_paper");
	if( !x->move(me) ) {
		x->move(environment(me));
		message_vision("�ι����ӻ�������һ��������ȥ�����ֵ���"CYN"��ȥ�ɣ����ûʡ��������Ӿõ��ˡ���"NOR"\n");
	} else {
		message_vision("�ι����ӻ�������һ��������$N�󣬻��ֵ���"CYN"��ȥ�ɣ����ûʡ��������Ӿõ��ˡ���"NOR"\n",me);
	}
	return 1;
}