inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
һ���������ֲ�����ָ�����ȣ�͸��ɭɭ�ĺ����ɱ�������м��ߵƹ������
�������������������͸�����˵ĺ���������֬�۵�ζ����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"room1",
  "north" : __DIR__"room2",
  "south" : __DIR__"room3",
  "west" : __DIR__"zoulang2",
]));
        set("objects", ([
        __DIR__"npc/dizi": 1,
        __DIR__"npc/xunluo": 1,
                        ]) );

	set("coor/x",-20);
	set("coor/y",0);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}
