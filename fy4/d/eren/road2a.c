inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "��ɽ��");
        set("long", @LONG
ת���䣬ɽ���������ϣ�Զɽ�ǿݻ�ɫ�ģ�����Ҳ�ǿݻ�ɫ�������ɫ�Ĳ��
�£������������ض����޵������������Ҷ���ʣ����������ʱ�Ŀ��������Ʋ�֪
�����޵İ�������Ƭ��Ҷ���ɶ��£�Զ������ԼԼ��������֮����
LONG
        );
        set("exits", ([ 
		"eastdown" : __DIR__"valleyentry",
		"northup": __DIR__"road2b",
	]));
        set("objects", ([   	
	]) );
	set("outdoors", "eren");
        set("coor/x",10);
        set("coor/y",10);
        set("coor/z",60);
	set("map","eren");
	setup();
	replace_program(ROOM);
}
