inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "���ĸ�");
        set("long", @LONG
����¥�������ģ��ں��ġ�����µ�������һ���������˳�֮Ϊ��������ˮ
���̳�����������䣻���������������Ϣ������䲨����ӳ��¥�ϵ�����������
���ż�ֻ���ۣ�����ɴ������֧��ҹɫ������¥�ڵƹ���ҫ����Ӱ�㿡�
LONG
        );
        set("exits", ([ 
		"east" : __DIR__"temple1",
	]));
        set("objects", ([
	]) );
	set("coor/x",-1720);
        set("coor/y",650);
        set("coor/z",20);
	set("map","zbwest");
	setup();

}
