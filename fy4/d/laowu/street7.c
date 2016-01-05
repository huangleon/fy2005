#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "���ر���");
        set("long", @LONG
�����µı��ӣ��������Ի�׳�ۡ�����ʮ�ɣ����������������Ӱ��ܽ�������
��ɫȴ����ȱ𴦻�Ҫ�Щ��һ�ο���¶�ں����ϣ�����ǿ�ʼ�⽭��ʱ������
�ġ���֦Ҳ��֪��˭��ƽ�ˣ�����ȴ����һС��¶�ں����⡣
LONG
        );
        set("exits", ([ 
  			"northeast" : __DIR__"street3",
		]));
        set("outdoors", "laowu");

	set("coor/x",28);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

void init()
{
	add_action("do_zha", "bomb");
}

int do_zha()
{
	object me, *inv;
	int i;
	object exp;
	object con,item;
	me = this_player();
	inv = all_inventory(me);
    for(i=0; i<sizeof(inv); i++)
     {			
		if( inv[i]->query("explosive"))
			exp = inv[i];
	}
	if( !exp) 
	{
		tell_object(me,"��û�������Ķ�����\n");
		return 1;
	}

	if (exp->query("explosive")<2)
	{
		message_vision(HIR"$N��ȼ�����е�"+exp->name()+ HIR"������
�������䡱��һ����������ը����һ��ǳǳ�İ��ӡ�\n\n"NOR, me);
		tell_object(me, WHT"���ҩ��������̫�\n");
		destruct(exp);
		return 1;
	}
	
	message_vision(HIR"$N��ȼ�����е�"+exp->name()+ HIR"������
�������䡱��һ������ǧ�������ɼ����𣬼д��ſ�������Ƭ������������档\n\n"NOR, me, exp);
	destruct(exp);

	if ( (REWARD_D->riddle_check( me,"��ȡ��ɲ") != 3
			&& REWARD_D->riddle_check( me,"��ȡ��ɲ") != 4))
		return 1;
	message_vision(WHT"��һ��������Ķ���������������·���������������ľ����
һ�����¡�������һ�������ں����ϡ�\n\n"NOR, me);
	
	con = new(__DIR__"obj/seal");
	item = new(__DIR__"obj/jadepai");
	if( con && item){
		item->move(con);
		con->move(this_object());
		REWARD_D->riddle_set( me, "��ȡ��ɲ", 4);
	}
	return 1;
}
