inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "ɽ������");
        set("long", @LONG
����ǰ�������Сɽ��ļ��п��ˣ���ʯС·��ÿ�������·��û�е��̣�
ֻ���������ձ��é�������Сͤ�ӡ�ÿ������������������������Ҹ���������
����ľƣ��ֵĲˣ��׵��⵽��������ף�ż��Ҳ�����˴�ɽ�����������Щ˿��
�ӻ������ô����Сϱ�����ۺ����ȡ�
LONG
        );
        set("exits", ([ 
	"west" : __DIR__"vroad2",
	"east" : __DIR__"vroad3",
	]));
        set("objects", ([
	]) );
	set("outdoors", "eren");
        set("coor/x",60);
        set("coor/y",60);
        set("coor/z",0);
	set("map","eren");
	setup();
	replace_program(ROOM);
}
