inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "��Į");
        set("long", @LONG
���������أ��ֿ��µ�ɳĮ�ϣ���ʵ������Ҳ�벻���ῴ��һֻ���ġ�ֻ����
�Ҵ�����������ͷ�ʹ�β�����е�̵ü�Ϊϸ�µ�װ�Σ������Ĵ������棬������
�顣�����������������Ƕ�����˼�Ļ�����������Ӱ��ɴ��ҹ���ػ��Ƽ��Ե���ͧ��
����Ҳû�����Ҵ���˻�����
LONG
        );
        set("exits", ([ 
		"east":	__DIR__"yangguan1a",
	]));
        set("objects", ([

	]) );
	
	set("outdoors", "zangbei");
        set("coor/x",-350);
        set("coor/y",100);
        set("coor/z",0);
	set("map","zbeast");
	setup();
}

void init(){
	add_action("do_look","look");
	add_action("do_jump","jump");
}

int do_look(string arg) {
	object me, room;
	
	me = this_player();
	
	if (!arg || (arg!= "boat" && arg!="in" && arg!="����"
				&& arg!="��" && arg!="ship"))
		return 0;
		
	room = find_object(__DIR__"eagleboat");
	if (!room) room = load_object(__DIR__"eagleboat");
	
	if (room->usr_in()) {
		tell_object(me,"���Ҵ���ѩ������ƽ����ɳ���ϻ���������������Զ���������ˡ�\n");
		return 1;
	}
	
	tell_object(me,"���ϲ��ߣ�Ҳ�����������ȥ��(jump)\n");
	return 1;
}
	
		

int do_jump(string arg){
	object me, room;
	
	me = this_player();
			
	if (!arg || (arg!= "boat" && arg!="in" && arg!="����"
			&& arg!="��" && arg != "ship")){
		tell_object(me,"��Ҫ���Ķ�����\n");
		return 1;
	}
	
	if (me->is_busy()) {
		tell_object(me,"��������æ��\n");
		return 1;
	}
	
	room = find_object(__DIR__"eagleboat");
	if (!room) room = load_object(__DIR__"eagleboat");
	if (room->usr_in()) {
		tell_object(me,"��������Զ���������ˡ�\n");
		return 1;
	}
	
	tell_object(me, YEL"\n����������������Ծȥ��\n"NOR);
	
	if(!me->query_temp("zangbei/����_�����ͱ�")) {
		tell_object(me,WHT"
��Ȼһ�ɾ���ӭ������������ʺ�˫Ŀ��ǰ�ء��¸����������е�Ҫ����������
�Ʒ������С��������㱻�ƻ���ԭ�ء�\n"NOR);
		return 1;
	}
		
	tell_object(YEL"\n�����ȵ����ڴ����ϡ�\n"NOR);
	me->move(room);
	room->depart(me);
	return 1;
}


		