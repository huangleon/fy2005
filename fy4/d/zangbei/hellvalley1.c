inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "�ӹ�");
        set("long", @LONG
��Խ���ɽçç�ԲԵ�ԭʼɭ�֣�ӭ������խ�վ����������ٵĺӹȡ�һ��С
·����������������һƬԭʼɭ�֣�ǰ���Ƿ�̵伮���ᵽ�ĵ����ȣ���˵�Ǿ�ס
��ѩɽ�ϵ������ǳ��ζ�ħ�ĵط���ÿ���ºڷ��ʱ��ɱ���ߵĺ����뱻ɱ�ߵİ�
���������˺�ë������
LONG
        );
        set("exits", ([ 
		"westup" : __DIR__"echu",
		"eastdown":  __DIR__"hellvalley2",
	]));
        set("objects", ([
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-2000);
        set("coor/y",620);
        set("coor/z",10);
	set("map","zbwest");
	setup();

}
