// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "ڤ��Т˾");
        set("long", @LONG
�����������������ŵľ�Ȼ��λ���Ӱ��Ů���������Ǻ�ʱ��ӣ��游������
��δ������Т�����½��ţ�����������Ա�ȡ����ĸ��ů�����Խ���Т�����
����һ����ң����顰Т�崫�ҡ������������������������͹��尾�������ǲ�
Т֮ͽ��
LONG
        );
        set("exits", ([
		"southwest" : __DIR__"naihe2",
        ]) );
        set("objects", ([
                __DIR__"npc/suo":1,
        ]) );
	set("coor/x",10);
	set("coor/y",20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
 
