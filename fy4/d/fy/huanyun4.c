#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", CYN"���Ƶ�"NOR);
    set("long", @LONG
���Ƶ������ƽ�Ϊ���ᣬ�ᴩ���������ϳǣ������ǽ����˳�ȥ�Ŀ�ջ���̼�
��ͤ�ȣ��������ǵƺ���̵��̻�֮�أ����ַǷ�����Ȼ���������ĺö඼�ǳ���
����������ŮŮ��˭��˵�����н����Ľ��������ɮ������·������[1;31m����˿�ջ[0;32m��
����С��������ƵĶ��Ǵ������̤�뽭�������಻֪��ʲôȥ����ֻ�ǳ���
��������ϲ����̻�����֮����
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"north" : __DIR__"huanyun5",
	"east" :__DIR__"fqkhotel",
	"west" :__DIR__"marry_room",
	"south" :__DIR__"huanyun8",
      ]));
    set("outdoors", "fengyun");
    set("objects", ([
	//        __DIR__"npc/mei": 1,
      ]) );

    set("coor/x",60);
    set("coor/y",-200);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    //	replace_program(ROOM);
}

