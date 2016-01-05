// TIE@FY3 ALL RIGHTS RESERVED
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "����Ϫ");
        set("long", @LONG
��;ʢ������Ϫˮ�����ֵ״�����������������һ��СȪ��Ȫˮ���е���
�Ŀ�ɬζ��������ҩ��ڣ����������ҩ����Ʒ������֪������������Ȫˮ��Ȫˮ
���ڽⷦ�����а���������ǰ��һ���ͱڵ�ס��ȥ·��
LONG
        );
        set("exits", ([ 
  		"southup" : __DIR__"zhulin",
	]));
        set("objects", ([
                __DIR__"npc/snake" : 2,
       	]) );
        set("item_desc", ([
                "����Ϫ": "��������Ŵ�Ϫ�����飩�кȣ������룩һ�ڡ�\n",
                "kuzhuxi": "��������Ŵ�Ϫ�����飩�кȣ������룩һ�ڡ�\n",
                "�ͱ�":	 "�ͱڵ�ס��ȥ·���¶��ƺ�¶�������˼ҡ�\n",
                "�˼�":  "�ͱڵ�ס��ȥ·���¶��ƺ�¶�������˼ҡ�\n",
        ]) );
        set("outdoors", "huangshan");
	set("coor/x",-50);
	set("coor/y",45);
	set("coor/z",10);
	setup();
}

void init(){
	add_action("do_drink","drink");
	add_action("climbing", "climb");
}

int do_drink(string arg)
{
	object me;
	me=this_player();
	if(!arg || arg != "xi") return 0;
	if(me->query("water") >= me->max_water_capacity())
		return notify_fail("���ƺ������ʡ�\n");
	message_vision("$N���������ڿ���Ϫ�к���һ��ڿ�ˮ��\n",me);
	me->add("water",50);
	me->apply_condition("kuzhu",3+random(5));
	return 1;
}

int climbing(string arg)
{
	object obj, me;
 	int i;
 	
 	me = this_player();
 	i = me->query_skill("move");
    	if(!arg || arg=="") return notify_fail("��Ҫ��ʲô��\n");
    	if( arg == "valley" || arg == "up" || arg == "�ͱ�"){
		if (me->is_busy())
	       		return notify_fail("��������æ��\n");
	        if (me->query_temp("huangshan/hs_climb_down"))
	       		return notify_fail("���Ѿ����������ˡ�\n");
		message_vision("$Nץ��ͻ����ʯ�ǣ�������˳���ͱ�������ȥ��\n", me);
            	call_out("fliping",2,me);
		me->set_temp("huangshan/hs_climb_up",1);
	       	me->start_busy(2);
	       return 1;
    	} else {
        	write("�㲻������"+arg+"\n");
    	}
	return 1;
}

int fliping(object me)
{
	if( !me->is_ghost() && objectp(me) && environment(me) == this_object()) {   
    		me->move(__DIR__"huangshan");
        	me->delete_temp("huangshan/hs_climb_up");
        	message_vision("$N˳�Źȱ�����������\n", me);
        }
        return 1;
}