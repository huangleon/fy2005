#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��ɽ�ܶ�");
        set("long", @LONG
����һ������Ȼ��Ѩ�����϶�������ܶ���������ܴ�ȴ�ܸߣ�����Ŀ���Ҳ
�����ƣ��ɼ�����ͨ���ĵط������ڵ�ʯ���Ϲ��ż�յˮ���ưѶ�����ҫ����ͬ��
�磬����ʯ�ڷ��ż�����ɫ���档һ��Ķ����ƺ����Դ򿪡�
LONG
        );
    set("exits", ([ 
//  		"northdown" : __DIR__"shaluo",
	]));
	set("item_desc", ([
		"����" : "�����ƺ����Դ򿪡��������塡����룩\n",
	]));
	set("valid_startroom", 1);
	set("objects", ([
		__DIR__"npc/zhenzhen" : 1,
	]));
	set("listen", 0);
    set("indoors", "huashan");
	set("coor/x",-11);
	set("coor/y",-56);
	set("coor/z",-116);
	setup();
}

void init(){
	object me;
	
	me = this_player();
	if(!me->query("marks/��ɽ�ܶ�")) {
		tell_object(me, "����������������ǻ�ɽ�ܶ����Ǳ���ǰ����ƿ���ġ�\n");
		tell_object(me, "�´ο����ƿ�ɽ�ڣ������塡����룩�����ܽ����ˡ���\n" );
		me->set("marks/��ɽ�ܶ�", 1);
	}
	add_action("do_slide", "slide");
}

int do_slide(string arg){
	object me, room;
	
	me = this_player();

	if(!arg || arg != "rock") {
		return notify_fail("��Ҫ�ƿ�ʲô��\n");
	}
	if(me->is_busy() || me->is_fighting()) {
		return notify_fail("������æ��\n");
	}
	message_vision("$N������ʯ��������һ�£�����ת�˳�ȥ��\n", me);
	room = find_object(__DIR__"yunv");
	if(!objectp(room)) {
		room = load_object(__DIR__"yunv");
	}
	me->move(room);
	message("vision", "ʯ���Բ�֪��ʱ��Ȼ����һ����Ӱ��\n",  
			environment(me), me);
	return 1;	
}
