inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "���СԺ");
        set("long", @LONG
СԺ�����š�����˿�ϡ����Ե�����ϣ������͵�Ҷ����ԡ������������£�
����һ���������񾲵ĸо������������ı��ݣ������������ݶ���������Ʈ��Զ
�����ŵ����˵���ζ��Ů���˿϶�����̨��æµ�˰ɡ�
LONG
        );
        set("exits", ([ 
	"south" : __DIR__"groad3a",
	]));
        set("objects", ([
//        	__DIR__"npc/chunliu":1,
	]) );
        set("coor/x",60);
        set("coor/y",100);
        set("coor/z",0);
	set("map","eren");
	setup();
}
