#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����ʯ");
        set("long", @LONG
�������ۣ�������ʯ�β��ý��ڵ���������һ���ʯ����һ�����࣬����
�ɣ�������Ϊ���ϣ���ͬ��������˵�˳�����ɽ��ĸ֮����ʯ�����ͷ֮����һ��
��������һ�˷������롣
LONG
        );
    	set("exits", ([ 
        	"southup" : __DIR__"lianhua",
	]));
     	set("objects", ([
                	__DIR__"npc/hawk" : 1,
		        __DIR__"npc/hawktrainer" : 1,
       ]) );

    	set("outdoors", "huashan");
		set("release_hawk",2);
		set("coor/x",-75);
		set("coor/y",-52);
		set("coor/z",35);
		setup();

}

void init()
{
	add_action("do_chop","chop");
}

int do_chop(string arg)
{
	object me,*inv,weapon;
	object hawk,chain,hawktrainer;
	int i;
	hawk = present("big hawk",this_object());
	
	me=this_player();
	if (!me->query_temp("weapon"))
		return notify_fail("������û��������\n");
	
	if (!hawk)
	{
		return notify_fail("��Ҫ����ʲô��\n");
	}
	
	if(!arg || (arg != "chain" && arg != "����") ) 
	{
		return notify_fail("���޷�����"+arg+"��\n");
	}
	
	if (!this_object()->query("item_desc")) {
		return notify_fail("������ʲô�����������������\n");
	}
	
	
	if (hawktrainer = present("hawk trainer",this_object()))
	{

        	message_vision(RED"$N��$n���һ�����������ӥ�����⣡���ò��ͷ��ˣ� \n"NOR,
                       hawktrainer,me);
        	hawktrainer->ccommand("kick "+me->get_id());
        	me->perform_busy(1);
        	return 1;
    	}

	inv = all_inventory(me);
	for (i=0;i<sizeof(inv);i++ )
	{
		if (objectp(inv[i]) && inv[i]->query("weapon_prop") && inv[i]->query("equipped"))
		{

			weapon = inv[i];
			message_vision("$N�þ�ȫ���������е�"+weapon->name()+"������������ȥ��������\n",me);
			//weapon->set("weapon_prop",0);
			//weapon->save();
			//me->reset_action();
			hawk->set("marks/chained",0);
			this_object()->set("item_desc",0);
			message_vision("����Ӧ�����ϣ�\n",me);
			chain = new(__DIR__"npc/obj/chain");
			chain->move(this_object());
			me->perform_busy(2);
			return 1;

		}
	}
	return notify_fail("��Ҫ��ʲô�������� \n");
}
