
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ����ª��С�������ı��ѱ�����޹�ķֲ���ԭ������ɫ��ǽ�Ϲ����˷�
���˵�±�⣬����������Ȼ���ű�����ҧ���ĺۼ���
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"home",
]));
        set("objects", ([
                __DIR__"npc/rat" : 6,
        ]) );

	set("coor/x",-10);
	set("coor/y",-20);
	set("coor/z",-20);
	setup();
}

