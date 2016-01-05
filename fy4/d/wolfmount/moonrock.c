#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "������");

	set("long", @LONG
���������ɽ����߷������ң���ɽ��һ�����ϵĴ�˵��ÿ��ʮ����Բ֮�ʣ�
��ɽ֮�������������ң����������ʵ���ɫ�У������Х��ֹ����ʱɽ����ǧ��
��Ⱥ���������¸���ȺХ������֮�������Ϊ֮����ʧɫ��
LONG);

	set("type","mountain");
	set("exits",([
        "westdown":__DIR__"littlesky2",
		"northwest":__DIR__"skyladder",
	]) );
       set("outdoors", "wolfmount");
	set("item_desc", ([
                "������": "����һ����ʯ�������Ǻں�����������Ԩ�������ܿ���˿�������ȥ���ʣգͣУ���\n",
        ]) );
	set("coor/x",80);
	set("coor/y",10);
	set("coor/z",60);
	set("objects",([
     		__DIR__"npc/qidiao":1,
    	]) );
	setup();
}

void init()
{
	add_action("do_jump", "jump");
}

int valid_leave(object me, string dir)
{
    	object ob;
        if( userp(me) && dir=="westdown" && ob=present("qidiao zhan", this_object()) ) 
        {
                if( me->query("class") != "wolfmount" && !me->query_temp("marks/��ɽ�ο�") )
                {                
                        return notify_fail(ob->name()+"����һ������סȥ·�������ȵ������˴�������ɽ�صأ���أ�����\n");
		}
	}
	return 1;
}

int do_jump(string arg)
{
        object 	me;
	int	cor;
	object  room;

	if(!arg || arg != "down") 
	{
		write("��Ҫ�������\n");
		return 1;
	}
	me = this_player();
    cor = (int)me->query_cor();
	
	if(cor < 30) 
		message_vision(HIY"\n$Nսս����������ɽ�£����ò��ף��ָϽ��ջؽ�������\n"NOR, me);
	else {
		message_vision(HIY"\n$Nҧ��ҧ����˫��һ�գ�����������ȥ������������\n"NOR, me);
		message_vision(HIR"����ͨ��һ����$Nˤ���µף����ҵ���ʹ$N���˹�ȥ����\n"NOR,me);
		me->unconcious();
		room = find_object(__DIR__"wolfmud");
		if(!objectp(room)) room= load_object(__DIR__"wolfmud");
		me->move(room);
	}
	return 1;
}
