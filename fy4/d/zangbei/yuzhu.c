inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "������");
        set("long", @LONG
���������������£��޴��ɽӰ�����ص�ѹ�ڹ����ĳ����ϡ����ں��ţ�ȴҲ
����������ɭ���Ե�����ɽ´��Ӱ�У��м�����������ЪϢ��������һ�������
�����ͨ��[33m�߳�[32m��������ͨ��[33m�����嶥[32m��ɽ·����᫶��������ϡ�
LONG
        );
        set("exits", ([ 
		"southeast" : __DIR__"kunlun3",
		"northup" :   AREA_EREN"road0",
		"west":		__DIR__"wild1",
	]));
        set("objects", ([
	]) );
	set("outdoors", "eren");
        set("coor/x",-1100);
        set("coor/y",700);
        set("coor/z",0);
	set("map","zbeast");
	setup();
	replace_program(ROOM);
}
