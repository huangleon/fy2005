inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "����");
        set("long", @LONG
����ϡ���ˣ�͸��֦Ҷ����Լ����������һ�����ᣬԶԶ�������ŵ�һ������
����ζ������Ѱ��ũ�ҵ��׻򷹲˵���ζ���ű�Ҳ������ఫС��ֲ��ƺ�����
��ר�����ֵģ�������עĿ����һЩ����ɫ�Ļ�����״���أ�ÿ�仨������һֻЬ
�ӣ����㵭������֪������
LONG
        );
        set("exits", ([ 
	"north" : __DIR__"chunliuju1",
	"south" : __DIR__"groad4a",
	"west" : __DIR__"groad3c",
	]));
        set("objects", ([
	]) );
	set("outdoors", "eren");
        set("coor/x",90);
        set("coor/y",90);
        set("coor/z",0);
	set("map","eren");
	setup();
	replace_program(ROOM);
}
