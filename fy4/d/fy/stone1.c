// Tie@fengyun
inherit ROOM;
void create()
{
    set("short", "����ʯ��");
    set("long", @LONG
��������ǰ��������һ��������ʯ�����ɢ����һ����ֵ�ù��ζ�����ּ�
����һ˿Ѫ�ȣ��͸ɾ����Ķ��������롣�����ֳ���С�ӹ�˳��С��໺��
���ʣ����滹Ư��Ⱦ���ź�Ѫ�ı�����������֮��Ż��
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"yulong31",
	"north" : __DIR__"stone2",
	"east" : __DIR__"cheaph",
      ]));
    set("objects", ([
	__DIR__"npc/scavenger" : 1,
      ]) );

    set("outdoors", "fengyun");
    set("coor/x",240);
    set("coor/y",60);
    set("coor/z",0);
    set("map","fyeast");
    setup();
    replace_program(ROOM);
}
