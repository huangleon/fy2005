inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "��կǽ");
        set("long", @LONG
կǽ���ռ�¥�ĸ�ʽ�����ģ�һ�������㶼�м��ۣ�����ֻ��һ��ǽ�ڣ�����
���Ҳ��¶��ͷ�������������������������կ�����վ��ǽ������������Ӹ���
�£�ʮ�ֵ��֡�կǽ������ï�ܵ�ɭ�֣�կǽ������Կ���һ����Ժ��Ժ�ӵ�����
�м����߷������Ű��˸ߵ��̴ѡ�
LONG
        );
        set("exits", ([ 
		"northeast" : __DIR__"w_wall2",
		
	]));
        set("item_desc", ([
        	"chimney": "���̴���Ȼ�Ѿ�������ʱ�ˣ�����ȥ��ǿ�������һ���ˣ�squeeze through����\n",
        	"�̴�":	 "���̴���Ȼ�Ѿ�������ʱ�ˣ�����ȥ��ǿ�������һ���ˣ�squeeze through����\n",
        ]));
        set("objects", ([
        	__DIR__"npc/archer":	2,
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1600);
        set("coor/y",580);
        set("coor/z",10);
	set("map","zbwest");
	setup();
}

void init() {
	add_action("do_squeeze","squeeze");
}


int do_squeeze(string arg) {
	
	object me;
	
	me=this_player();
	if (arg=="through" || arg == "�̴�" || arg== "chimney" || arg =="through chimney") {
		if (me->query_temp("zangbei/chimney_1"))
			return notify_fail("���Ѿ����̴����ˡ�\n");
		message_vision("$Nһè�������̴ѣ�С�������������ȥ��\n\n",me);
		call_out("pass_river",6,me);
		me->start_busy(3);
		me->set_temp("zangbei/chimney_1",1);
		return 1;
	}
	tell_object(me,"��Ҫ��ʲô��\n");
	return 1;
}


int pass_river(object me) {
	object room;
	if (!objectp(me) || me->is_ghost()) return 0;
	room=find_object(__DIR__"v_barn");
	if (!objectp(room)) room=load_object(__DIR__"v_barn");
	tell_object(me,"�����ɵ��µ������\n");
	message("vision",me->name()+"���ݶ��ϵ���������\n",room);
	me->move(room);
	me->delete_temp("zangbei/chimney_1");
	return 1;
}