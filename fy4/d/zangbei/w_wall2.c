inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "��կǽ");
        set("long", @LONG
կǽ���ռ�¥�ĸ�ʽ�����ģ�һ�������㶼�м��ۣ�����ֻ��һ��ǽ�ڣ�����
���Ҳ��¶��ͷ�������������������������կ�����վ��ǽ������������Ӹ���
�£�ʮ�ֵ��֡�կǽ������ï�ܵ�ɭ�֣�կǽ������Կ���һ����Ժ��Ժ�ӵ�����
�м����߷���
LONG
        );
        set("exits", ([ 
		"southwest" : __DIR__"w_wall3",
		"east":	__DIR__"w_wall1",
	]));
        set("objects", ([
        	__DIR__"npc/archer":	2,
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1580);
        set("coor/y",600);
        set("coor/z",10);
	set("map","zbwest");
	setup();
}

