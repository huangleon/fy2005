inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "������ջ");
        set("long", @LONG
������С�������ģ�Ҳ��Ψһ��һ�ҿ͵꣬�ϰ����˵�ǵ��꽭����ʮ���
��֮һ�����������ڴ���������ĸ�����ϴ�������������������Ŀ��˴����Ľ��
Ͷ�ޣ��뿴�������������֮�����黯���ġ�ǧ��ǧ�����в�Ů��������ʲôģ
����
LONG
        );
        set("exits", ([ 
	"south" : __DIR__"vroad2",
	"up" : __DIR__"jiaojiao2",
	]));
        set("objects", ([
		__DIR__"npc/xiaojiao":1,
	]) );
	set("coor/x",50);
        set("coor/y",70);
        set("coor/z",0);
	set("map","eren");
	setup();
	replace_program(ROOM);
}
