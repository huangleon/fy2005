// Reference point, (-900, 2500, 0)
inherit ROOM;
#include <ansi.h>


void create()

{
        set("short", "���ع�ַ");
        set("long", @LONG
���ع�ַλ�����Ź�������������Ϊ�����ʳơ����ء�������ԭ������½·��
ͨ�ʺ�֮�أ�Ҳ�ǡ�˿��֮·����·�ؾ��Ĺذ����ųǹض���Ϊũ�Զ�����ٲ�
�Ƿ�ַ������ɳ��ɳ����������ɳãã��һ���޼ʡ�����ն�ɽ����һ�������ݣ�
�����ϱ�������������Ȫˮ�丣���Ϊ������
LONG
        );
        set("exits", ([ 
	"northwest" : __DIR__"yangguan1",
	"east" : AREA_QUICKSAND"yangguan",
	"north" : __DIR__"oasis",
	]));
        set("objects", ([

	]) );
	set("outdoors", "zangbei");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
	set("map","zbeast");
	setup();
	replace_program(ROOM);
}
