inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "����Ȫ");
        set("long", @LONG
�ٲ����ߣ�ȴ�����㣬��˶��������������ٲ���;��Ȼ�绨��ɢ����û��ֱ
�Ӵ���������������꣬������ˮ�ߡ�ɽ�绢�����������֣�ʱ��ɽ����������ɽ
ʪ�䣬������ɽʤ����ȴ���˲�Ը������
LONG
        );
        set("exits", ([ 
	"northwest" : __DIR__"vroad5",
	]));
        set("item_desc", ([
                "�ٲ�": "�������Ͽ���ɽ�绢�����������֣��ѱ���ʵ��\n",
                "waterfall": "�������Ͽ���ɽ�绢�����������֣��ѱ���ʵ��\n",
        ]) );
        
        set("objects", ([
	]) );
	set("outdoors", "eren");
        set("coor/x",110);
        set("coor/y",50);
        set("coor/z",0);
	set("map","eren");
	setup();
	replace_program(ROOM);
}
