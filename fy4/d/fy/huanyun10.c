#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", "���Ƶ�");
    set("long", @LONG
���Ƶ������ƽ�Ϊ���ᣬ�ᴩ���������ϳǣ������ǽ����˳�ȥ�Ŀ�ջ���̼�
��ͤ�ȣ��������ǵƺ���̵��̻�֮�أ����ַǷ�����Ȼ���������ĺö඼�ǳ���
����������ŮŮ��˭��˵�����н����Ľ��������ɮ������
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"east" : __DIR__"huanyun9",
	"west" : __DIR__"swind4",
      ]));
    set("outdoors", "fengyun");
    set("objects", ([
	//        __DIR__"npc/mei": 1,
      ]) );

    set("coor/x",20);
    set("coor/y",-280);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    //	replace_program(ROOM);
}
