
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�ɸɾ�����ǽ�Ϲ���һ���ֻ�������д������ɽ��·��Ϊ����ѧ�����Ŀ����ۡ���
���ɷ�������壬������ׯ���������顣ǽ�Ƕ��źܶ����񽣣����ϴ�ɨ��һ��
��Ⱦ���м�΢΢��Щ���£��ƺ��Ǿ��������ڴ��������뵽����֮�ˣ��۹��޲�Ϊ
ǽ�ϵ�[33mһ��һ��[32m������ס��
LONG
        );
        set("exits", ([ 
  		"east" : __DIR__"back_yard",
		]));
		
		set("item_desc", ([
			"һ��һ��":		"��˼��	���꽣\n",
			"һ��":			"����˼��������\n",
			"һ��":			"�����꣬���޺�\n",
		]));
		
       set("objects", ([
                __DIR__"obj/bsword" : 3,
                __DIR__"obj/bblade" : 4,
        ]) );

		set("coor/x",-10);
		set("coor/y",10);
		set("coor/z",0);
		setup();
}


void init()
{
	add_action("do_gets", "get");
}

int do_gets(string arg)
{
	object me, sword, blade;
	int ability;
	
	me = this_player();
	
	if(arg == "all")	{
		write("��̫̰���ˡ�\n");
		return 1;	
	}
	
	if (arg == "��˼��") {
		if (me->query("class")!="legend") {
			tell_object(me,"�ڱ���ׯ԰�����ͣ����ǲ�Ҫ�����Ҷ��ĺá�\n");
			return 1;
		}
		if (me->query_skill("dormancy",1) < 300
			|| me->query_skill("six-sense",1)<300) {
			tell_object(me,"ѩ���˵�������ѩ�书��δ���죬ȡ֮�к����档\n");
			return 1;
		}
		if (me->query("gender")=="����") {
			tell_object(me,"ѩ���˵����˼���Ǹ�Ů��������ġ�\n");
			return 1;
		}
		seteuid(getuid());
		blade = new("/obj/specials/legend/mblade");
		if (blade->move(me)) {	
			ability = F_ABILITY->check_ability(me,"parry_add");
			blade->set("block_rate", 5 + ability/2);
			message_vision("$N����ش�ǽ��ȡ������˼����\n", me);
		} else
			destruct(blade);	
		return 1;
	}	
	
	if (arg == "���꽣") {
		if (me->query("class")!="legend") {
			tell_object(me,"�ڱ���ׯ԰�����ͣ����ǲ�Ҫ�����Ҷ��ĺá�\n");
			return 1;
		}
		if (me->query_skill("dormancy",1) < 300
			|| me->query_skill("six-sense",1)<300) {
			tell_object(me,"����˵�������ѩ�书��δ���죬ȡ֮�к����档\n");
			return 1;
		}
		if (me->query("gender")=="Ů��") {
			tell_object(me,"����˵����˼���Ǹ�Ů��������ġ�\n");
			return 1;
		}
		seteuid(getuid());
		blade = new("/obj/specials/legend/msword");
		if (blade->move(me)) {	
			ability = F_ABILITY->check_ability(me,"parry_add");
			blade->set("block_rate", 5 + ability/2);
			message_vision("$N����ش�ǽ��ȡ�������꽣��\n", me);
		} else
			destruct(blade);	
		return 1;
	}
	
	return 0;
			
}
