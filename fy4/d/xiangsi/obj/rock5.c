#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("����ʯ", ({ "rock","����ʯ","����"}) );
	set_weight(500);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	set("prep","behind");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ��˶��ĻҺ���ʯ������Χ�ľ�ɫ����롣\n��˵�����ʯ�������������������ҡ���������ꡣ\n");
		set("value", 1);
	}
    ::init_item();
}

int is_container() { return 1; }

int do_pick(string arg)
{
	object bamboo,me = this_player();
	object room,*inv,who;
	int i,num;
	if ( !arg && arg != "rock" && arg != "����ʯ" )
		return notify_fail("��Ҫ��ʲô��\n");
	message_vision(CYN"\n$N���һ�����������˫����������ػ��ڷ���ʯ�ϡ�\n"NOR,me);
	if (me->query_str() < 40+random(80) || me->query("timer/moon_pushstone") + 900 > time())
	{
		me->set("timer/moon_pushstone",time());
		message_vision(CYN"ֻ������ʯ����ҡ�ڣ����Ǿ�Ҫ�㷭���䣬ȴ���񲻵��̰�����������λ�ԭλ��\n"NOR,me);
		return notify_fail("�㲻��Ϊ����֮��֮�ɾ�̾��\n");
	}
	me->set("timer/moon_pushstone",time());
	message_vision(CYN"�����ѩ��$N�Ʒ缤�����ɶ���ѩԭ�ϵ�ʱһƬ��ã��\n��Լ�������һ��ټ��ĺ�Ӱһ�𣬴�ɽ���߱�ֱ���䡣\n\n"RED"ɽ�´��������ľ���۵����������������ѹ��������\n"NOR,me);
	environment()->set("no_stone",1);
	environment()->set("long", @LONG
��������˼ѩ�����ߴ���һƬ��������ѩ�س����������ǰ������ɫ
�ı�ѩѹ����ɽ������ͷ��ȥ��ɽ��Ʈ�ε������Ѿ���������¡�ѩ�صı���
��һȦǳǳ�İ��ۣ���Χ��ѩ�ɶ���һ��ʲô��������Ĺ켣��Լ�ɼ�����ɽ
�������ȥ��
LONG
        );
	if (!room=find_object("/d/xiangsi/liangjie"))
		room = load_object("/d/xiangsi/liangjie");
	tell_room(room,RED"\nһ�����֮����ɽ�ϴ��������Ȼ̧ͷ��ֻ��һ��˶�����ʯ��һ·��ϲ�ľ������ֱѹ������\n\n"NOR);
	inv = all_inventory(room);
	i = random(sizeof(inv));
	who=inv[i];
	if (userp(who))	// �����õ���ѹ����
	{
		if (random(who->query_skill("move")) < 100)	// move�͵������������ֺ���..
		{
			message_vision(CYN"$N�ŵö������ã�ֻ����ʯһ�ģ���$Nֱֱײȥ������\n"NOR,who);
			who->set_temp("last_damage_from","��������������ѹ����һ̲���ࡣ\n");
			who->add_temp("block_msg/all",1);
			message_vision(CYN"\nת˲֮��$N�ͱ�ѹ��������������һ̲��\n\n"NOR,who);
			who->delete("timer/lifesave");	// �仨��ˮһ��ȥ:p
			who->move("/obj/void");
			who->die();	
//			who->set_temp("block_msg/all",0);	// ʬ���޴森��

		if (who->query_temp("block_msg/all")>=1)
				who->add_temp("block_msg/all", -1);


			// ��������������
			// ���⣬һ�ж������Ⱑ *point norns *giggle
			if (!who->query("����B/��˼_����"))
			{
				num = 1 + random(10);
				who->set("����B/��˼_����",num);
				log_file("riddle/FATE_LOG",
				sprintf("%s(%s) �õ�����B/��˼_���� "+num+"�� %s \n",
					who->name(1), geteuid(who), ctime(time()) ));
			}
		}
		else
			message_vision(CYN"$N��֮�������������࣬���ձܹ���֮�֡�\n"NOR,who);
	}
	tell_room(room,RED"��ʯ����һ�󾢷磬������߷��Ӷ������ŵ����ľ���ս���������á�\n\n"NOR);
	destruct(this_object());
    return 1;
}

void init()
{
	add_action("do_pick","push");
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

