inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "����");
        set("long", @LONG
�����ܴ�������Ҳ��Ũ��Ũ�ҵĲ��㣬����һ�������������������ӣ�����
����һ�㡣��������Χ����̨��æ�ò��ɿ�����ǽ���и���ˮ�ף���β����������
���ڣ����������ż������⡣
LONG
        );
        set("exits", ([ 
	"west" : __DIR__"hahalou1",
	]));
	set("resource/water", 1);
    	set("liquid/container", "ˮ��");  
        set("objects", ([
        	__DIR__"npc/cooker": 1,
        	__DIR__"obj/counter": 1,
	]) );
	set("coor/x",55);
        set("coor/y",50);
        set("coor/z",0);
	set("map","eren");
	setup();
	replace_program(ROOM);
}
