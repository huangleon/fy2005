#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short",CYN"���Ƶ�"NOR);
    set("long", @LONG
���Ƶ������ƽ�Ϊ���ᣬ�ᴩ���������ϳǣ������ǽ����˳�ȥ�Ŀ�ջ���̼�
��ͤ�ȣ��������ǵƺ���̵��̻�֮�أ����ַǷ�����Ȼ���������ĺö඼�ǳ���
����������ŮŮ��˭��˵�����н����Ľ��������ɮ������������һ����ˮ�أ�
ˮɫī�̣�ɢ���ŵ��������̡���ɫ���룬һ�ж��������ƺ������ڵ����С�
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"north" : __DIR__"huanyun3",
	"southeast" : __DIR__"huanyun22",
	"west" : __DIR__"hfeng",
      ]));
    set("outdoors", "fengyun");
    set("objects", ([
	//        __DIR__"npc/mei": 1,
      ]) );

    set("coor/x",-60);
    set("coor/y",-240);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    //	replace_program(ROOM);
}

