inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "ǡ�˲���ɽ");
        set("long", @LONG
ʯ����ԫ��ب�ڲ���������ǡ�˲���ɽ֮�䣬ɽͷ�ϲ�����¥����������Ժ��
���٣���ɽ��ԶԶ�������������������Ǹ�������ʯ�ϵľ޴�Ǳ��������������
����Ĵ�����������������ô��������ô���͡�
LONG
        );
        set("exits", ([ 
		"northeast":  __DIR__"garden",
		"south":  	__DIR__"smallroad4",
	]));
        set("objects", ([
        	
	]) );
	set("outdoors", "guanwai");
        set("coor/x",40);
        set("coor/y",-20);
        set("coor/z",10);
	setup();

}
