#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short",CYN"���Ƶ�"NOR);
    set("long", @LONG
���Ƶ������ƽ�Ϊ���ᣬ�ᴩ���������ϳǣ������ǽ����˳�ȥ�Ŀ�ջ���̼�
��ͤ�ȣ��������ǵƺ���̵��̻�֮�أ����ַǷ�����Ȼ���������ĺö඼�ǳ���
����������ŮŮ��˭��˵�����н����Ľ��������ɮ������
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"northeast" : __DIR__"huanyun8",
	"west" : __DIR__"huanyun10",
      ]));
    set("outdoors", "fengyun");
    set("objects", ([
	//        __DIR__"npc/mei": 1,
      ]) );

    set("coor/x",40);
    set("coor/y",-280);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    //	replace_program(ROOM);
}

