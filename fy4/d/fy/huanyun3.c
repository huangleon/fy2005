#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", CYN"���Ƶ�"NOR);
    set("long", @LONG
���Ƶ������ƽ�Ϊ���ᣬ�ᴩ���������ϳǣ������ǽ����˳�ȥ�Ŀ�ջ���̼�
��ͤ�ȣ��������ǵƺ���̵��̻�֮�أ����ַǷ�����Ȼ���������ĺö඼�ǳ���
����������ŮŮ��˭��˵�����н����Ľ��������ɮ�����������������������
���ϱ���[33mǧ��¥[32m�ˡ�����һ��ֵǧ�����Ƿ���ȥ����Ƭ�̣�
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"north" : __DIR__"huanyun2",
	"south" : __DIR__"huanyun21",
	"west" : __DIR__"qianjin",
	"east" : __DIR__"mudan",
      ]));
    set("outdoors", "fengyun");
    set("objects", ([
	//        __DIR__"npc/mei": 1,
      ]) );

    set("coor/x",-60);
    set("coor/y",-200);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    //	replace_program(ROOM);
}

