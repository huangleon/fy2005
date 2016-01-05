#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", CYN"���Ƶ�"NOR);
    set("long", @LONG
���Ƶ������ƽ�Ϊ���ᣬ�ᴩ���������ϳǣ������ǽ����˳�ȥ�Ŀ�ջ���̼�
��ͤ�ȣ��������ǵƺ���̵��̻�֮�أ����ַǷ�����Ȼ���������ĺö඼�ǳ���
����������ŮŮ��˭��˵�����н����Ľ��������ɮ��������������ǳ������
�Ĳ��̣���ͷ����һ���޻�����
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"northwest" : __DIR__"huanyun7",
	"south" : __DIR__"huanyun4",
	"east" : __DIR__"mianhua",
	//  "east" : __DIR__"seven",
	"west" : __DIR__"bupu",
      ]));
    set("outdoors", "fengyun");
    set("objects", ([
	//        __DIR__"npc/mei": 1,
      ]) );

    set("coor/x",60);
    set("coor/y",-160);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    replace_program(ROOM);
}


