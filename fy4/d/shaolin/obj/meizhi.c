#include <ansi.h>;
inherit ITEM;
void create()
{
        set_name("���ϵ�÷֦", ({ "meizhi"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        "һ�������߳���÷֦���ƺ��Ǳ�ʲô�������ϡ�Ȼ���Ͽڴ��ܳ���
������ƽ�������÷֦�������ġ�\n");
                set("value", 100);
        }
}

void init()
{
	add_action("do_look","look");
}

int do_look(string arg)
{
	object me,meizhi;
	int i;
	me = this_player();
	if (arg != "meizhi" && arg != "���ϵ�÷֦" && arg != "÷֦")
	{
		return 0;
	}
	if (!meizhi = present("meizhi",me))
	{
		return 0;
	}
/*	if (me->query_temp("lookmeizhi"))
	{
		return 0;
	}*/
	i = me->query_temp("looked");
	i = i + 1;
	me -> set_temp("looked",i);
	if ( i <=20)
	{
		return 0;
	}else 
	{
		if (random(6)&& !me->query_temp("lookmeizhi"))
		{
			tell_object(me, YEL"��۲���÷֦�ĶϿڣ���������Ͽ��ƺ���������һ��ն���ġ� \n"NOR);
		}else
		{
			tell_object(me,YEL "Ȼ��������ϸ�쿴�����ȵط�����һ��֮�ƣ�ȫ��÷֦������˿˿ 
��ۣ����������һ�㡣��һն������ƽ��δ���ľ�������㲻�� 
���ģ�Ҫ��ϸ�о� (study)\n"NOR);
			me->set_temp("lookmeizhi",1);
			add_action("do_study","study");
		}
	}
	return 1;
}


int do_study(string arg)
{
	object me,meizhi;
	int i;
	me = this_player();
	if (arg != "meizhi" && arg != "���ϵ�÷֦" && arg != "÷֦")
	{
		return 0;
	}
	if (!meizhi = present("meizhi",me))
	{
		return 0;
	}
	
	// the riddle is temperorily disabled
	me->set_temp("lookmeizhi",2);
	tell_object(me,YEL"�����о���һ��÷֦�ĶϿڣ�������һ��ʵ�ڰ����������⡣\n "NOR);
	return 1;
		
	if (me->query("marks/����_��") || (string)me->query("class") != "shaolin")
	{
		tell_object(me,"���޷���÷֦�ĶϿ��������κζ�����\n");
		return 1;
	}
	if (me->query("marks/����_��_÷֦"))
	{

		tell_object(me,"�����о���һ��÷֦�ĶϿڣ�Խ��Խ������һ��������΢��������ɡ� \n");
		return 1;
	}
	if (me->query_temp("marks/����_��_����"))
	{
		me -> set_temp("looked",0);
		tell_object(me," �����о���һ��÷֦�ĶϿڣ�������һ��ʵ�ڰ����������⡣\n ");
		return 1;
	}
	i = me->query_temp("studied");
	i = i + 1;
	me->set_temp("studied",i);
	if (i == 4)
	{
		tell_object(me,"���޷���÷֦�ĶϿ��������κζ�����Ҳ��һ����ʦ��ָ��һ���� \n");
	}else if (i == 11)
	{
			if ((string)me->query("class") == "shaolin" && me->query_skill("sword",1)>=120)
			{
				tell_object(me,"�����о���һ��÷֦�ĶϿڣ�Խ��Խ������һ��������΢��������ɡ� \n");
				me->set("marks/����_��_÷֦",1);
			}else
			{
				tell_object(me," �����о���һ��÷֦�ĶϿڣ�������һ��ʵ�ڰ����������⡣ ");
				me->set_temp("marks/����_��_����",1);
			}
			me -> set_temp("looked",0);
			me->set_temp("studied",0);

	}else
	{
		tell_object(me,"���޷���÷֦�������κζ�����\n");
	}
	return 1;
}