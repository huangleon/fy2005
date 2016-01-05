#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");

	set("long", @LONG
���ɾ����£���һƬ�ޱ��޼ʵ�����û����ľ��û�л��ݡ�û���������е�
ֻ��ʪ�ࡢ��ˮ�����ڸ��õĿ�ľ�ܲݺ�����������������Ũ��ճ��������ֵ�
���������Դ�������Ԩ������Ҳû����ȫ������ס�       
LONG);	
	set("no_dazuo",1);
       set("outdoors", "wolfmount");
	set("no_magic",1);
	set("type","mud");
	set("item_desc", ([
                "��ľ": "Ư���������еĿ�ľ�����վ�������ץס���ǣң��ӣУ��㶫���͵���ץסϣ����\n",
 		"tree": "Ư���������еĿ�ľ�����վ�������ץס���ǣң��ӣУ��㶫���͵���ץסϣ����\n",
 		"wood": "Ư���������еĿ�ľ�����վ�������ץס���ǣң��ӣУ��㶫���͵���ץסϣ����\n",
 		"��ľ�ܲ�": "Ư���������еĿ�ľ�����վ�������ץס���ǣң��ӣУ��㶫���͵���ץסϣ����\n",
        ]) );
	set("coor/x",80);
	set("coor/y",10);
	set("coor/z",-60);
	setup();
}

void init()
{
	add_action("do_grasp", "grasp");
	if(interactive(this_player()))
	call_out("do_moving",180,this_player());
}

void do_moving(object me)
{
	object room;

	if(!me || environment(me) != this_object())
		return;
	tell_object(me,"\n���ӻ����������ţ���֪�����У����������ӻ�����Ư���š���\n\n");
	room = find_object(__DIR__"wolfmud1");
	if(!objectp(room)) room= load_object(__DIR__"wolfmud1");
	me->move(room);
}

int do_grasp(string arg)
{
	object me, room;
	int sen;

	me = this_player();
	sen =(int) (me->query("max_sen")/3);

	if(!arg || (arg != "��ľ" && arg !="tree" && arg!= "wood" ) ) 
	{
		write("��Ҫץʲô��\n");
		return 1;
	}
	switch (random(3)) 
	{
		case 0:
			tell_object(me,"������ץ�������еĿ�ľ��������һ����û��ץס��\n");
			break;
		case 1:
			tell_object(me,RED "������Ž��������ľ��ͻȻ��о�����ʲô������������һ�ڡ�\n"NOR);
			message_vision(YEL "$NͻȻ����һ�����У���������������һЩ��\n"NOR, me);
			me->receive_damage("kee",50);
			me->set_temp("last_damage_from","����������Ϣ�����ˡ�\n");
			break;
		case 2:
			tell_object(me, RED"���þ����̵�����ץס��ľ�������ƺ����ֿ��µ�������������......\n"NOR );
			tell_object(me,YEL"����е��в�����......�㿪ʼ����һ�������......��\n"NOR);
			message("vision", "��ֻ��"+me->name()+"ץ�ſ�ľ��ʼ����һ������䡣\n" , environment(me),me);
			me->receive_damage("sen",sen);
			me->set_temp("last_damage_from","����������Ϣ�����ˡ�\n");
			break;
	}
	return 1;
}
