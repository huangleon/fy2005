inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "�ջ�԰��");
        set("long", @LONG
�ջ�԰�ܴ��Ա���÷��԰����ĵ����Ǿޱ����ҩ���軨������������԰��˭
Ҳ��֪������ռ�˶��ٵأ�ֻ֪��һ���˾����ߵúܿ�Ҳ����һ����������Ƭ����
һȦ��԰��������ʮ�߶����������ӣ��ϲ������㴨�������ڶ��ࡣ
LONG
        );
        set("exits", ([ 
		"east" :   	__DIR__"groom1",
		"north" : 	__DIR__"groom3",
		"southwest":	__DIR__"garden1",
	]));
        set("objects", ([
        
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1280);
        set("coor/y",970);
        set("coor/z",-50);
	set("map","zbeast");
	setup();
}

void init() {
	add_action("do_pull","pull");
	add_action("do_search","search");
}

int do_search(){
	tell_object(this_player(),"԰����ľջ����������дУ�������һ�춼�����н����\n");
	return 1;
}

int do_pull(string arg) {
	object me=this_player();
	object xiaohe;
	
	if (arg== "flower" || arg == "�ջ�") {
		tell_object(me,YEL"�����ȥ���ְ���һ��ջ����ջ�����һ�Σ�����������\n\n"NOR);
		return 1;
	}
	return notify_fail("�����/��ʲô��\n");
}