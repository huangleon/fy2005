inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "�෿");
        set("long", @LONG
���㴨�����Ӿ��¶��ɾ���ÿ��������ǡ������Ӧ���ڵĵط���������ʲô��
�����Ҳ������ҳ���������������һ�������ࡢ�򵥡����ء������񡰶��ࡱ����
����������£��Ӳ�Ҫ�����װ�Σ�Ҳ�Ӳ�˵����Ļ�����Ϊ��������˷ѡ�ֻ��
�޴����˲��˷ѡ��ƹ�������������￴������������Ĳ����Ǹ��ҡ�
LONG
        );
        set("exits", ([ 
		"south" :   	__DIR__"garden4",
		"west": 	__DIR__"kitchen",

	]));
        set("objects", ([
               	__DIR__"npc/lv":	1,
	]) );
        set("coor/x",-1280);
        set("coor/y",980);
        set("coor/z",-50);
	set("map","zbeast");
        set("home",1);
	setup();
}


int valid_leave(object me, string dir) {
	object ob;
	if (dir == "west")
	if (ob = present("lv xiangchuan",this_object()))
		tell_object(me,"���㴨˵�������Ҹ����ռ����˰ɡ�\n");
	return ::valid_leave(me,dir);
}