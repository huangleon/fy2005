inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", HIC"���ű�"NOR);
    set("long", @LONG
�������У����ǳ����Ƴǵ������ˡ��������������ֵĻ��Ƶ�����˵��������
�Ĵ���һЩѪ�����գ�ĬĬ�����Ľ�����Ѫ��������˭�ܻ��ɣ�������Щ����ȥ
�ͷ��Ե�С�������Ѿͷ��û�н���߳����Ƶ�һ���콾��
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"sgate",
	"north" : __DIR__"swind5",
	"east" : __DIR__"huanyun10",
	"west" : __DIR__"huanyun23",
      ]));
    set("outdoors", "fengyun");
    set("coor/x",0);
    set("coor/y",-280);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    replace_program(ROOM);
}
