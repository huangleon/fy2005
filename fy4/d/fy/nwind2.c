#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIY"����"NOR);
    set("long", @LONG
�����ű��У�����Ρ����Ͻ��ʳ��ˣ��ŷ��嶴������Ϊ�������ӵ���������
��ٹ������Ž������������������Ž�����һ���Աֻ�ܾ�����Ҵ�Ž������ȼ�ɭ
�ϣ�����Υ����Ψһ�������ǣ��������Կ����¿�״Ԫ�����ۡ�̽���ߣ��ڷ��ư�
���죬�ɴ����ų���һ�Ρ����Ÿߴ�Ρ�룬Լ��ʮ������������ʿ������
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"nwind1",
	"north" : __DIR__"nwind3",
      ]));
    set("outdoors", "fengyun");
    set("coor/x",0);
    set("coor/y",120);
    set("coor/z",0);
    set("map","fynorth");
    setup();

}
