#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", HIY"̫����"NOR);
    set("long", @LONG
ͨ���Ͻ��ǵİ�����������������������Ρ�������ĺ�ΰ���ʳǾ�����
ǰ���������Ƶ���ɫ��ǽ�����������޾����������̫���ţ�����Ъɽ����������
�㺺����ʯ�����̨���ϡ���ǰ�����������ͭʨһ�������Ҵƣ������׺�����
ʨ����̤��������Ȩ�������£���ʨ���㸧��ʨ���������ò�ʢ��
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"nwind2",
	"north" : __DIR__"nwind4",
	"northeast" : __DIR__"huantian3",
	"northwest" : __DIR__"huantian1",
      ]));
    set("objects", ([
//	__DIR__"npc/patrol_soldier": 1,
      ]) );
    set("outdoors", "fengyun");
    set("coor/x",0);
    set("coor/y",160);
    set("coor/z",0);
    set("map","fynorth");
    setup();
    replace_program(ROOM);
}
